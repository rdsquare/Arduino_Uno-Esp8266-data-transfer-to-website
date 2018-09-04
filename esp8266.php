<?php
	$Name=$_POST['myname'];
	$RollNo=$_POST['rollno'];
	$Write="<p>Your name: " . $Name . "</p><p>Roll No: " . $RollNo . "</p>";
	$myfile = fopen("esp8266.html", "w") or die("Unable to open file!");
	fwrite($myfile, $Write);
	fclose($fp);
?>

