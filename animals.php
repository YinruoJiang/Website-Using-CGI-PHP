<!--
  FILE : animals.php
  PROJECT : assignment-WDD-A03
  PROGRAMMER : Yinruo Jiang
  FIRST VERSION : 2021-10-10
  DESCRIPTION : This source mainly receive the username and animal choice from html, and display image and text file content 
-->
<!DOCTYPE html>
  <html>
    <head>
	    <title>My PHP Zoo</title>
	    <style>
      body 
      {
        background-color: lightyellow;
      }
    </style>
	  </head>
    <body>
  		<h3>Pet Facts!</h3>
  		<hr>
  		<?php
  		  //Get username
  			$userName = $_POST["fname1"];
  			//Get Selected Animal
  			$animalSelected = $_POST["animal"];
  			echo "<p>Hello, " . $userName . "! You selected to learn more about the " . $animalSelected . "</p>";
  			echo "<p>Look how cute they can be!</p>";
  			echo "<hr>";
  			echo "<div style='overflow: hidden;'>";
  			//display image
  			echo "<img src='theZoo/{$animalSelected}.png' alt='img' style='width:300px;height:auto;float:left;'>";
  			echo "<div style='float:left;''>";
  			//open txt file
  			$myfile = fopen("theZoo/{$animalSelected}.txt", "r") or die("Unable to open file!");
				// Output one line until end-of-file
				while(!feof($myfile)) {
				  echo fgets($myfile);
				}
				fclose($myfile);
  			echo "</div>";
  			echo "</div>";
  			echo "<hr>"
  		?> 		
  	</body>
	</html>
