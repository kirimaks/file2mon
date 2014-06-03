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

void check_args(int argc, char **argv, struct Icon_data *data)
{
  unsigned char info = 0;	/* Flag for info. */

  if(argc == 1)
  {
	printf("No arguments, exit.\n");
	SHOW_USAGE;
  }

  /* Calculate argrument list. */
  for(argv++; *argv != NULL; argv++)
  {
      if(**argv == '-')
      {
          switch(*(*argv+1))
	  {
	      case 'h':
	          SHOW_USAGE;
		  break;

	      case 'f':	/* Open file. */
	          if((data-> fd = open(*(argv+1), O_RDONLY)) <= 0)
		  {
		      fprintf(stderr, "Cant open the file, exit.\n");
		      exit(1);
		  }
		  strcpy( (char*)data-> saved_file, (const char*)*(argv+1) );	/* Save the file to read from. */
		  break;

	      case 'e':	/* Ending string. */
                  strcpy(data-> ending, *(argv+1));
	          break;

	      case 't': /* Title string. */
	          strcpy(data-> title, *(argv+1));
		  break;

	      case 'u': /* Update interval. */
	          data-> update_int = atoi(*(argv+1));
		  break;

	      case 'c':	/* Font color. */
	          strcpy(data-> font_color, *(argv+1));
		  break;

	      case 'i': /* Show info. */
	          info = 1; 	/* Show info at the end. */
	          break;

	      case 'v':
	      	  printf("Version: %d\n", VERSION);
		  exit(0);
          }
      }
  }

  /* Check if the file wasn't set. If it wasn't set, nothing to do and exit. */
  if(data-> fd <= 0)
  {
      printf("The file didn't set properly, quit\n");
      exit(1);
  }

  /* Create temporary directory if doesn't exist. */
  struct stat st;

  if(stat(TMP_DIR, &st) < 0)
  {
      printf("Try to create temporary directory.\n");

      if(mkdir(TMP_DIR, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) < 0)
      {
          perror("Cant create directory.\n");
      }
  }

  /* Generate file name. */
  srandom(getpid());
  sprintf((char*)data-> tmp_buff, "%d.png", (int)random() % 300);

  strcat(data-> path_to_file, (const char*)data-> tmp_buff);

  /* Show info if need. */
  if(info) show_info(data);
}


void show_info(struct Icon_data *data)
{
  printf("Parameters:\n");

  INFO_D(update interval:, data-> update_int);
  INFO_D(lenght to read:, data-> len_to_read); 
  INFO_S(title:, data-> title);
  INFO_S(ending:,(*data-> ending) > 0 ? data-> ending : "NONE");
  printf("\ticon size: %dx%d\n", IMG_H, IMG_W);
  INFO_S(font:, FONT_TYPE);
  INFO_S(font color:, data-> font_color);
  INFO_D(font size:, FONT_SIZE);
  INFO_S(file path:, data-> path_to_file);
}

void filemon_exit(struct Icon_data *data)
{
  gtk_main_quit();

  /* Close the file. */
  if(data-> fd) close(data-> fd);
  exit(1);
}
