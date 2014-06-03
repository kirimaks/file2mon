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

/* INCLUDES */
#include<stdio.h>
#include<stdlib.h>	/* exit()	*/
#include<errno.h>
#include<sys/stat.h>
#include<fcntl.h>	/* open(). 	*/
#include<string.h>	/* strlen()	*/
#include<gtk/gtk.h>
#include<wand/magick_wand.h>

/* DEFINES */
#define VERSION	1

/* Image size. */
#define IMG_H 20
#define IMG_W 32

/* Font config. */
#define FONT_COLOR 		"white"		/* Default font color. 	*/
#define FONT_TYPE  		"Ubuntu"	/* Default font. 	*/
#define FONT_SIZE  		18		/* Default font size.	*/
#define ENDING_FONT_SIZE 	12		/* Ending font.		*/

#define LTR 	2			/* Default length to read. 	*/
#define BUFFL 	100			/* Size of buffers. 		*/	
#define UPTIME 	3			/* Default update interval.	*/
#define TMP_DIR	"/tmp/.filemon/"	/* Temporary directory.		*/


/* MACROS */
#define INFO_S(str,arg) printf("\t"#str"%s\n", arg)
#define INFO_D(str,arg) printf("\t"#str"%d\n", arg)

#define SHOW_USAGE printf("Usage: filemon [file] [args]\n"); 	\
	printf("\t-h help.\n");					\
	printf("\t-f File to read from.\n"); 			\
	printf("\t-e Ending string.\n");			\
	printf("\t-u Update interval.\n");			\
	printf("\t-t Title label.\n");				\
	printf("\t-l Bytes to read from file.\n");		\
	printf("\t-c Font color.\n");				\
	exit(1)



/* TYPES */
struct Icon_data {
  unsigned char text_buff[BUFFL];
  unsigned char tmp_buff[BUFFL];
  unsigned char saved_file[BUFFL];	/* Place for save given file. */

  GtkStatusIcon *icon;

  int update_int;		/* Update interval. 		*/
  int fd;			/* File descriptor. 		*/
  int len_to_read;		/* Length to read from file. 	*/

  char title[BUFFL];
  char ending[BUFFL];

  char font_color[BUFFL];
  char path_to_file[BUFFL];	/* The path to output icon. 	*/	
};


/* PROTOTYPES */
int create_icon(struct Icon_data*);
gboolean update(struct Icon_data*);
void check_args(int, char**, struct Icon_data*);
void show_info(struct Icon_data*);
void filemon_exit(struct Icon_data*);
