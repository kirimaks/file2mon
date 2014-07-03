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

#include"file2mon.h"

int create_icon(struct Icon_data *data)
{
  MagickWand *mw = NULL;
  DrawingWand *dr = NULL;
  PixelWand *px = NULL;

  mw = NewMagickWand();
  dr = NewDrawingWand();
  px = NewPixelWand();

  /* Set pixel color (for background). */
  PixelSetColor(px, "none");

  /* Create a background. */
  MagickNewImage(mw, IMG_W, IMG_H, px);

  /* Configure the font. */
  PixelSetColor(px, data-> font_color);		/* Font color. 		*/
  DrawSetFillColor(dr,px);			/* Enable the font.	*/
  DrawSetFont(dr, FONT_TYPE);			/* Font type.		*/
  DrawSetFontSize(dr, data-> font_size);	/* Font size.		*/

  /* Draw the text to the background (2 and 3 parameters are position of the text) */
  DrawAnnotation(dr,0,BASELINE,data-> text_buff);

  /* SECOND TEXT (ending). Can be didn't set. */
  if(*data-> ending) {
      DrawSetFontSize(dr,ENDING_FONT_SIZE);

      size_t ending_offset = 0;	/* Offset of ending character after the text */

      ending_offset = (data-> font_size / 2) * strlen_no_n((const char*)data-> text_buff);

      DrawAnnotation(dr, ending_offset+2, BASELINE,(const unsigned char*)data-> ending);
  }

  /* Draw the image on to the magick wand. */
  MagickDrawImage(mw,dr);

  /* Write the image to the file. */
  MagickWriteImage(mw, data-> path_to_file);

  /* Clean up. */
  if(mw) mw = DestroyMagickWand(mw);
  if(dr) dr = DestroyDrawingWand(dr);
  if(px) px = DestroyPixelWand(px);

  return 0;
}
