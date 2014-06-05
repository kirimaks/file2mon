<img src="http://i57.tinypic.com/a1ha9v.jpg" border="0" alt="file2mon">

<h4>File2mon - monitoring cpu temperature, battery capacity and things like this in system tray.</h4>

<strong>

This program read information from given file and create the icon.
It's possible to set how many bytes to read from file and update interval.

This program is <a href="http://www.gtk.org">gtk+</a> and <a href="http://www.imagemagick.org">ImageMagic</a> based.

</strong>


<h4>Examples:</h4> 
<h5>1. CPU temperature:</h5>
<pre><code>file2mon -i -f /sys/class/hwmon/hwmon1/device/temp1_input -e C -t cputemp -u 3 -l 2 -c white -s 22</code></pre>
<img src="http://i58.tinypic.com/wvwhsi.jpg">
</br>
<ul>
<li><strong>-e C:</strong>&nbsp;Ending string append after text.</li>
<li><strong>-t cputemp:</strong>&nbsp;Icon description.</li>
<li><strong>-u 3:</strong>&nbsp;Update interval.</li>
<li><strong>-l 2:</strong>&nbsp;Number of bytes to read.</li>
<li><strong>-c white:</strong>&nbsp;Font color.</li>
<li><strong>-s 22:</strong>&nbsp;Font size.</li>
</ul>

<h5>2. Battery: </h5>
<pre><code>file2mon -i -f /sys/class/power_supply/BAT1/capacity -e % -t battery -u 5 -l 2 -c yellow -s 22</code></pre>
<img src="http://i57.tinypic.com/6dz6ms.jpg">
</br>
<ul>
<li><strong>-e %:</strong>&nbsp;Ending string append after text.</li>
<li><strong>-t battery:</strong>&nbsp;How many bytes to read.</li>
<li><strong>-u 3:</strong>&nbsp;Update interval.</li>
<li><strong>-l 2:</strong>&nbsp;Number of bytes to read.</li>
<li><strong>-c yellow:</strong>&nbsp;Font color.</li>
<li><strong>-s 22:</strong>&nbsp;Font size.</li>
<li><strong>-i:</strong>&nbsp;Show info.</li>
</ul>

<h5>3. Load average 15min:</h5>
<pre><code> file2mon -i -f /proc/loadavg -o 5 -l 4 -u 5 -c yellow -s 18 </code></pre>
<img src="http://i62.tinypic.com/2gumu7p.jpg" border="0" alt="file2mon load average">

</br>
<ul>
<li><strong>-o 5:</strong>&nbsp;Offset in the file.</li>
<li><strong>-l 4:</strong>&nbsp;How many bytes to read.</li>
<li><strong>-u 5:</strong>&nbsp;Update interval.</li>
</ul>
