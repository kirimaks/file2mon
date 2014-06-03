<!--
<a href="http://tinypic.com?ref=a1ha9v" target="_blank"><img src="http://i57.tinypic.com/a1ha9v.jpg" border="0" alt="Image and video hosting by TinyPic"></a>
-->
<img src="http://i57.tinypic.com/a1ha9v.jpg" border="0" alt="filemon">

<h4>Filemon - simple monitoring cpu temperature, battery capacity and things like this in system tray.</h4>

<strong>

This program read information from given file and create the icon.
It's possible to set how many bytes to read from file and update interval.

This program is <a href="http://www.gtk.org">gtk+</a> and <a href="http://www.imagemagick.org">ImageMagic</a> based.

</strong>


<h4>Examples:</h4> 

<h5>1. 15m load average:</h5>

<strong>
filemon -i -f /proc/loadavg -o 5 -l 4 -u 5 -c yellow -s 18
</strong>
<img src="http://i62.tinypic.com/2gumu7p.jpg" border="0" alt="filemon load average">

<strong>
-o 5: Offset in the file.
-l 4: How many bytes to read.
-u 5: Update interval.
</strong>


