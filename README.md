# Arduino_Uno-Esp8266-data-transfer-to-website
This is simple project to transfer data using arduino uno and esp8266 wifi module to the website using POST method and php script

Create a esp8266.html file in the main directory of your website (you can use 000webhost.com for free hosting)
After creating esp8266.html file paste the code of esp8266.html file to yours
Create a esp8266.php file in the main directory of your website and paste he code of esp8266.php to your file
Now, Build and Upload the given arduino code to your arduino uno using arduino IDE.


# Pin Connection:

 ## ESP8266 -----------------> Arduino Uno
 
 RX --------------------------> 6
 
 TX --------------------------> 7
 
 EN --------------------------> 3.3V
 
 3V3 --------------------------> 3.3V
 
 Gnd --------------------------> Gnd

After connecing and compilling the code on arduino refresh the your_website/esp8266.html page and your will see your data there.

# By:
# Rahul Dangi (rdsquare) :)-
