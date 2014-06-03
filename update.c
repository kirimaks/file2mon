/*
The MIT License (MIT)

Copyright (c) 2014 kirimaks

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include"filemon.h"

gboolean update(struct Icon_data *data)
{
  if( pread(data-> fd,data-> text_buff, data-> len_to_read, data-> offset) <= 0) /* Try to read from the file. */
  {
      /* Error enter. */
      fprintf(stderr, "*** Filemon first reading error, try to reopen ***\n");

      /* If pread return error, try to open it again(Due to suspend and so on). */
      if((data-> fd = open((const char*)data-> saved_file, O_RDONLY)) <= 0)
      {
          fprintf(stderr, "Cant reopen the file, exit.\n");
          filemon_exit(data);
      }
      else if( pread(data-> fd,data-> text_buff, data-> len_to_read, data-> offset) <= 0) /* Try to read from the file again. */
      {
          /* Second reading was fail too. */
          fprintf(stderr, "Filemon Reading error, exit.\n");
          filemon_exit(data);
      }
  }

#ifdef DEBUG
  fprintf(stdout, "TEXT: [%s]\n", data-> text_buff);	        /* Debug. */
  fprintf(stdout, "TMP: [%s]\n", data-> tmp_buff);		/* Debug. */
#endif

  /* If current buffer is the same like previous (tmp_buffer), do nothign.
   * Or if it's different, create new icon and reset the icon.
   * Also copy current text to temporary buffer for future comparisons.
   */
  if(strcmp( (const char*)data-> text_buff, (const char*)data-> tmp_buff) != 0)
  {
      create_icon(data);						/* Create new icon. 			*/
      gtk_status_icon_set_from_file(data-> icon, data-> path_to_file);	/* Reset the icon.  			*/
      strcpy( (char*)data-> tmp_buff, (const char*)data-> text_buff);	/* Copy new lalue to temporary buffer. 	*/
  }

  return TRUE;	/* Keeep running. */
}
