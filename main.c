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
LIABILITY, WHETHER IN AN ACTION 
*/


#include"file2mon.h"

int main(int argc, char **argv)
{
  /* Data structure and default values. */
  struct Icon_data data = { {0}, {0}, {0}, NULL, UPTIME, 0, LTR, "file2mon", {0}, FONT_COLOR, TMP_DIR, FONT_SIZE, 0 };

  /* Check given arguments and overwrite default values if need. */
  check_args(argc,argv,&data);

  /* Start gtk. */
  gtk_init(&argc,&argv);

  /* Create empty icon. */
  data.icon = gtk_status_icon_new();

  /* Set title for icon. */
  gtk_status_icon_set_tooltip_text(data.icon, (const gchar*)data.title);

  /* Configure timeout. */
  g_timeout_add_seconds(data.update_int, (GSourceFunc)update, (gpointer)&data);	/* Send structure with data.*/

  /* Start gtk loop. */
  gtk_main();

  /* Exit. */
  file2mon_exit(&data);

  return 0;
}
