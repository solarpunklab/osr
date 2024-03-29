<a name="readme-top"></a>
<div align="center">
<!-- ## SOLARPUNKLAB - OSR -->
<img src="images/osr-logo.png" alt="Logo" width = 50%>
<!-- PROJECT LOGO -->
<img src="images/osr-banner.png" alt="Logo" width = 90%>
<br>
</div>

<br>

<div align="left" width = 90% id="contents">
<!-- TABLE OF CONTENTS -->
<details open>
  <summary style="background-color: #aaa;"><b>CONTENTS</b></summary>
  <ul>
	<li><a href="#about">ABOUT O.S.R. <br><br></a></li>
	<li> <b>LEVEL 1</b></li> <ul>
	<li><a href="#physical">Physical Computing</a></li>
	<li><a href="#mcu">MCU vs Mini-Computer</a></li>
	<li><a href="#sensors"> Sensors and Actuators</a></li>
	<li><a href="#gpio"> GPIO - General Pupose Input Output</a></li>
	<li><a href="#mq4"> MQ4 - Methane gas sensor module</a></li>
	<li><a href="#DS18D20"> DS18D20 Temperature sensor</a></li>
	<li><a href="#bme280"> BMP / BME280 I2C SENSOR</a></li>
	<li><a href="#bme680"> BMP / BME680 I2C SENSOR</a></li>

  </ul>
   <br><br>
   <li><b> GENERAL</b> </li>
   <ul>
   		<li><a href="#arduino"> ARDUINO INSTALL</a> </li>
   		<li><a href="#wifi"> ESP32 WIFI MODES</a> </li>
	   <li><a href="code/"> CODE</a> </li>
	   <li><a href="#contact"> CONTACT</a> </li>
  
  </ul>
</details>
</div>

<br><br><hr> <br><br>

<!-- >>>>>> TABLE <<<<< -->
<table width = 90%>
<tr>
<td align = "justify" width = 90% colspan=2>
<p align="justify" id="about">
<b>ABOUT O.S.R.</b>
<br><br>
Open Sensor Research is a project by 
<a href="http://solarpunklab.org">SOLARPUNK LAB</a> / 
<a href="http://hackteria.org">HACKTERIA</a> 
aimed at promoting DIY practices to use sensors and microcontrollers for eco -oriented projects. 
<br> 
The documentation offered in this repository is mainly used as support for a series of workshops to introduce newbies as well as specialists and researchers to Physical Computing and DIY environmental monitoring. <br>
<br>
<a href="#contents"><img src="images/back.png" alt="Logo" width = 100%></A>
<br>
</tr>
</table>
 
 
 

<!-- >>>>>> TABLE <<<<< -->
<table width = 90%>
<tr>
<td align = "justify" width = 90% colspan=2>
<p align="justify" id="physical">
<img src="images/osr-physical.png" alt="Logo" width = 100%>
<br>
The term <b>Physical Computing</b> defines, in a broad sense, a field of studies and practices aimed at building interactive physical systems.
<br>
To this end, technologies are adopted based on integrated software and hardware devices capable of sensing and responding to stimuli coming from the surrounding world.

<br><br>
<img src="images/osr-physical2.png" alt="Logo" width = 100%>
<br>

<a href="#contents"><img src="images/back.png" alt="Logo" width = 100%></A>
<br>

<p align="justify" id="mcu">
<b>MCU vs MiniComputer</b>
<br>
<img src="images/osr-arduino-rpi.png" alt="arduino" width = 100%>
<br>
<a href="#contents"><img src="images/back.png" alt="Logo" width = 100%></A>
<br>

</tr>
</table>

<!-- >>>>>> TABLE <<<<< -->
<table width = 90%>
<tr>
<td align="center" colspan=1 width = 20%>
<img src="images/osr-mcu-esp32.png" alt="mcu" width = 90%></td>
<td align="justify" colspan=1 >
The microcontroller (MCU) is a device generally used in integrated systems to carry out specific digital control applications.
<br>
It is a real microprocessor, that is, a small computer capable of processing information coming from both digital interfaces and analog inputs (for example sensors) and responding with output signals to analog actuators or other digital interfaces, including WiFi communications and Bluetooth.

</tr>
</table>



<!-- >>>>>> TABLE <<<<< -->
<table width = 90%>
<tr>
<td align="center" colspan=2 width = 90% >
<img src="images/osr-esp32-vs-arduino.png" alt="compare" width = 100%>
<br>
<img src="images/osr-esp32-architecture.png" alt="compare" width = 100%>
<br>
<a href="#contents"><img src="images/back.png" alt="Logo" width = 100%></A>
<br>
</tr>
</table>



<!-- >>>>>> TABLE <<<<< -->
<table width = 90%>
<tr>
<td align="center" colspan=2 width = 90% >

<p align="justify" id="sensors">
<b>SENSORS AND ACTUATORS </b>
<br><br>
A SENSOR is a device that measures changes in a certain environment and responds with a signal to another system.
 <br>
Both sensors and actuators are <b>transducers</b>, that is, devices capable of converting one physical quantity into another or one form of energy into another different form,
<br>
While sensors transform any physical quantities into electrical signals, ACTUATORS transform electrical signals into other appropriate physical quantities.
<br>
Motors, LED lights, solenoid valves are all examples of actuators that can be controlled by microcontrollers to perform actions in the real world.
<br><br>
<img src="images/osr-SENSORS-slide.png" alt="physical" width = 100%>
<br>
<p align = "center"> Examples of SENSORS
<br><br>
<img src="images/osr-sensors.png" alt="physical" width = 100%>
<br>
<br>
<a href="#contents"><img src="images/back.png" alt="Logo" width = 100%></A>
<br>

<p align = "center"> Examples of ACTUATORS
<br><br>
<img src="images/osr-act-movement.png" alt="act1" width = 100%>
<br>
<img src="images/osr-act-lightsound.png" alt="act1" width = 100%>
<br>
<a href="#contents"><img src="images/back.png" alt="Logo" width = 100%></A>
<br>

</tr>
</table>



<!-- >>>>>> TABLE <<<<< -->
<table width = 90%>
<tr>
<td align="left" colspan=2 width = 90% >
<p align="justify" id="gpio">

<b> GPIO - General Purpose Input / Output</b>
<br><br>
The GPIO is a hardware computer interface, available on microcontrollers and microcomputers, that allows you to interact with other peripherals, both analogue and digital.
<br>
A series of pins on the microcontroller board allow you to connect to the functions implemented by this interface within the chip / microprocessor.
<br>
Each microcontroller has its own specific set of GPIOs with specific functions, often called "pinout".
<br><br>
<img src="images/osr-doit-pinout2.png" alt="pinout" width = 100%>
<br>
<img src="images/osr-doit-expander.png" alt="doitexp" width =100%>
<br>
<img src="images/osr-selectboard.png" alt="doitexp" width =100%>
<br><br>
<a href="#contents"><img src="images/back.png" alt="Logo" width = 100%></A>
<br>
</tr>
</table>


<!-- >>>>>> TABLE <<<<< -->
<table width = 90%>
<tr>
<td align="center" colspan=2 width = 90% >

<img src="images/osr-connecting.png" alt="mq4" width = 100%>
<br>
<p align="center" id="mq4">
<img src="images/osr-mq4-sensor.png" alt="mq4" width = 100%>
<br>
<img src="images/osr-mq4-specs.png" alt="mq4" width = 100%>
<br>
<img src="images/osr-mq4-specs2.png" alt="mq4" width = 100%>
<br>
<img src="images/osr-mq4-pinout.png" alt="mq4" width = 100%>
<br>
<img src="images/osr-mq4-preheat.png" alt="mq4" width = 100%>
<br>
<img src="images/osr-mq4-connect.png" alt="mq4-connect" width = 100%>
<br>
<img src="images/osr-mq4-connect2.png" alt="mq4-connect" width = 100%>
<br>
<img src="images/osr-mq4-breadboard.png" alt="mq4" width = 100%>
<br>
<!-- made with https://ezgif.com/video-to-gif -->
<img src="images/osr-mq4-video.gif" alt="mq4" width = 100%>
<br><br> 

<a href="https://ohmslawcalculator.com/voltage-divider-calculator">online voltage divider calculator</a>
<br>

<img src="images/osr-voltage-divider.png" alt="mq4-connect" width = 100%>
<br>
<br>
<img src="images/code.png" alt="bmparams" width = 10%>
<a href="code/OSR_MQ_SENSOR/OSR_MQ_SENSOR.ino">OSR_MQ_SENSOR.ino</a>
<br><br>

<img src="images/osr-adc-calibration.png" alt="mq4-connect" width = 100%>
<br>
<a href="https://github.com/e-tinkers/esp32-adc-calibrate">https://github.com/e-tinkers/esp32-adc-calibrate</A>
<br>
<br>
<a href="#contents"><img src="images/back.png" alt="Logo" width = 100%></A>
<br>
</tr>
</table>

<!-- >>>>>> TABLE <<<<< -->
<table width = 90%>
<tr>
<td align="center" colspan=2 width = 90%>
<p align="center" id="DS18D20">
<img src="images/osr-DS18D20-sensor.png" alt="mq4" width = 100%>
<br>
<img src="images/osr-DS18D20-specs.png" alt="mq4" width = 100%>
<br>
<img src="images/osr-DS18D20-connect3.png" alt="mq4" width = 100%>
<br>
<br>
<img src="images/code.png" alt="bmparams" width = 10%>
<a href="code/OSR_DS18D20/OSR_DS18D20.ino">OSR_DS18D20.ino</a>
<br>
<a href="#contents"><img src="images/back.png" alt="Logo" width = 100%></A>
<br>
</tr>
</table>


<!-- >>>>>> TABLE <<<<< -->
<table width = 90%>
<tr>
<td align="justify" colspan=2 id="bme280" width = 90% >
<br>
<img src="images/osr-BME280-sensor.png" alt="bme" width = 100%>
<br>
<img src="images/osr-BME-BMP280.png" alt="bmp" width = 100%>
<br>
<br>
BOSCH's BMP280 is an absolute barometric pressure sensor especially designed for mobile applications. The sensor module is housed in an extremely compact package. Its small dimensions and its low power consumption allow for the implementation in battery powered devices such as mobile phones, GPS modules, or watches. 
<br>
<img src="images/osr-bmp280-specs.png" alt="bmp" width = 100%>
<br>
<br>
<img src="images/osr-BME280-connect.png" alt="bmeconnect" width = 100%>
<br><br>
<a href="https://montreal.weatherstats.ca/charts/pressure_sea-hourly.html" target="pressure"> <img src="images/osr-pressure-mtl.png" alt="i2c" width = 100%>Barometric pressure at sea evel / Montreal</a>



<br><br>
<img src="images/osr-i2c.png" alt="i2c" width = 100%>
<br>
<img src="images/osr-bmp280-params.png" alt="bmparams" width = 100%>
<br>
<img src="images/code.png" alt="bmparams" width = 10%>

<a href="code/OSR_BMP280/OSR_BMP280.ino">OSR_BMP280.ino</a>
<br>
<a href="#contents"><img src="images/back.png" alt="Logo" width = 100%></A>
<br>
</tr>


<tr>
<td align="justify" colspan=2 id="bme680" width = 90% >
<br>
<img src="images/osr-bme680.png" alt="bme-680" width = 100%>
<br>
The BME680 is a 4-in-1 digital sensor that measures:
<ul>
<li>Temperature
<li>Humidity</item>
<li>Barometric pressure</item>
<li>Gas: Volatile Organic Compounds (VOC) like ethanol and carbon monoxide</item>
</ul>

<br><br>
The BME680 contains a MOX (Metal-oxide) sensor that detects VOCs in the air. This sensor gives you a qualitative idea of the sum of VOCs/contaminants in the surrounding air – <b>it is not specific </b>for a specific gas molecule.
<br><br>
<a href="https://randomnerdtutorials.com/esp32-bme680-sensor-arduino/" target="new">
<img src="images/osr-bme680-voc.png" alt="bme-680-voc" width = 100%></a>
<br><br>
<img src="images/osr-bme680-accuracy.png" alt="bme-680-voc" width = 100%>
<br><br>
<img src="images/osr-bme680-operation.png" alt="bme-680-voc" width = 100%>
<br><br>
<img src="images/osr-bme680-i2c.png" alt="bme-680-voc" width = 100%>
<br>
<img src="images/osr-bme680-library.png" alt="bme-680-voc" width = 48%>
<img src="images/osr-BSEC.png" alt="bme-680-voc" width = 48%>
<br>
<img src="images/osr-ESPasync-library.png" alt="bme-680-voc" width = 48%>
<br>
<br>
<img src="images/code.png" alt="bmparams" width = 10%>
<a href="code/OSR_BME680_TEST/OSR_BME680_TEST.ino">OSR_BME680_TEST.ino</a>
<br><br>

<img src="images/code.png" alt="bme_web" width = 10%>
<a href="code/OSR_BME680_WEBSERVER/OSR_BME680_WEBSERVER.ino">OSR_BME680_WEBSERVER.ino</a>
<br><br>

<img src="images/code.png" alt="bme_web" width = 10%>
<a href="code/OSR_BME680_WEBSERVER_DYNAMIC/OSR_BME680_WEBSERVER_DYNAMIC.ino">OSR_BME680_WEBSERVER_DYNAMIC.ino</a>
<br><br>

<img src="images/code.png" alt="bme_web" width = 10%>
<a href="code/OSR-BME680-BSEC-BASIC/OSR-BME680-BSEC-BASIC.ino">OSR-BME680-BSEC-BASIC.ino</a>
<br><br>

<img src="images/code.png" alt="bme_web" width = 10%>
<a href="code/OSR_BME680_WEBSERVER_DYNAMIC/OSR_BME680_WEBSERVER_DYNAMIC.ino"> OSR_BME680_WEBSERVER_DYNAMIC.ino</a>
<br><br>



<img src="images/osr-boardnumber.png" alt="boardnum" width = 100%>
<br>
<img src="images/osr-bme680-gas.png" alt="bme680-gas" width = 100%>
<br>
<a href="https://forums.pimoroni.com/t/bme680-observed-gas-ohms-readings/6608/23"><img src="images/osr-bme60-observations.png" alt="bme680-obs" width = 100%></a>

<table>
<tr>
<td>521177 - 431331 </td> <td> good </td>
<tr>
<td>297625 - 213212 </td> <td> average </td>
<tr>
<td>148977 - 108042 </td> <td> little bad </td>
<tr>
<td>575010 - 54586 </td> <td> bad </td>
<tr>
<td>37395 - 27080 </td> <td> worse </td>
<tr>
<td>18761 - 13591 </td> <td> very bad </td>
<tr>
<td>9008 - 8371 </td> <td> can't see the exit </td>
</tr>
</table>

<a href="https://community.bosch-sensortec.com/t5/MEMS-sensors-forum/BME680-VOC-classification/td-p/26154"><img src="images/osr-indoor-air.png" alt="bme680-indoor-air" width = 100%></a>

<img src="images/osr-bsec-output.png" alt="bme680-indoor-air" width = 100%>


<a href="#contents"><img src="images/back.png" alt="Logo" width = 100%></A>
<br>
</tr>


</table>

<!-- >>>>>> TABLE <<<<< -->
<table width = 90%>
<tr>
<td align="center" colspan=2 id="arduino" width = 90% >
<br>
<img src="images/osr-arduino-install.png" alt="install" width = 100%>
<br>
<img src="images/osr-drivers.png" alt="drivers" width = 100%>
<br>
<a href="https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads">DOWNLOAD ESP32 DRIVERS</a>
<br><br>
<img src="images/osr-arduino-ide.png" alt="ide" width = 100%>
<br>
<a href="https://www.arduino.cc/en/software">ARDUINO IDE DOWNLOAD + INSTALL</a>
<br><br>

<a href="https://support.arduino.cc/hc/en-us/articles/360016495679-Fix-port-access-on-Linux"> linux problem with USB port access </a>

<br><br>
<img src="images/osr-boardpref.png" alt="manager" width = 100%>
<br><br>
in "Addtional boards manager URLs" <br>
COPY / PASTE the text below 
</tr>
</table>

<!-- >>>>>> TABLE <<<<< -->
<table width = 90%>
<tr bgcolor=#009900>
<td align="left" colspan=2 id="URLS" width = 90%>
https://dl.espressif.com/dl/package_esp32_index.json,
http://arduino.esp8266.com/stable/package_esp8266com_index.json,
https://github.com/stm32duino/BoardManagerFiles/raw/main/package_stmicroelectronics_index.json,
https://m5stack.oss-cn-shenzhen.aliyuncs.com/resource/arduino/package_m5stack_index.json,h
https://raw.githubusercontent.com/damellis/attiny/ide-1.6.x-boards-manager/package_damellis_attiny_index.json,
https://raw.githubusercontent.com/stm32duino/BoardManagerFiles/master/STM32/package_stm_index.json

</tr>
</table>


<!-- >>>>>> TABLE <<<<< -->
<table width = 90%>
<tr>
<td align="left" colspan=2 id="xxxx" width = 90% >
<br>
<a href="#contents"><img src="images/back.png" alt="Logo" width = 100%></A>
<br>
<br>
<img src="images/osr-sketches.png" alt="sketches" width = 100%>
<br><br>
<img src="images/osr-boards.png" alt="boards" width = 100%>
<br><br>
<img src="images/osr-library.png" alt="boards" width = 100%>
<br><br>
<img src="images/osr-libraryname.png" alt="boards" width = 100%>
<br><br>
<img src="images/osr-select-board.png" alt="boards" width = 100%>
<br>
<br>
<a href="#contents"><img src="images/back.png" alt="Logo" width = 100%></A>
<br>

</tr>

<tr >
<td align="justify" colspan=2 id="wifi" width = 90% bgcolor="#00cc77">
<img src="images/ESP32-WIFI.png" alt="esp32-wifi" width = 100%>
<br><br>
The ESP32 board can act as Wi-Fi Station, Access Point or both. To set the Wi-Fi mode, use WiFi.mode() and set the desired mode as argument.
<br><br>
<img src="images/ESP32-WIFI-MODES.png" alt="wifi-sta" width = 100%>
<br>
<br>
<img src="images/ESP32-WIFI-STA.png" alt="wifi-sta" width = 100%>
<br>
<hr>
<br>
<img src="images/ESP32-WIFI-AP.png" alt="wifi-AP" width = 100%>
<br>
<hr>
<br>
<img src="images/ESP32-WIFI-STATUS.png" alt="wifi-AP" width = 100%>
<br>
<img src="images/ESP32-WIFI-RSSI.png" alt="wifi-AP" width = 100%>
<br>
<br>
<hr>
<a href="https://deepbluembedded.com/esp32-hostname-change-arduino/"><img src="images/ESP32-WIFI-hostname.png" alt="wifi-AP" width = 100%></a>
<br>
<img src="images/ESP32-WIFI-hostname-code.png" alt="wifi-AP" width = 100%>
<br>
<br>
<hr>
<br>
<hr>

<img src="images/code.png" alt="bmparams" width = 10%>
<a href="code/ESP32_WIFI_SCANNER/ESP32_WIFI_SCANNER.ino">ESP32_WIFI_SCANNER.ino</a>
<br><br>

<img src="images/code.png" alt="bmparams" width = 10%>
<a href="code/ESP32_WIFI_CONNECT/ESP32_WIFI_CONNECT.ino">ESP32_WIFI_CONNECT.ino</a>
<br><br>

<img src="images/code.png" alt="bmparams" width = 10%>
<a href="code/ESP32_WIFI_AP/ESP32_WIFI_AP.ino">ESP32_WIFI_AP.ino</a>
<br><br>


<hr>

<p align = center>
<a href="https://randomnerdtutorials.com/esp32-useful-wi-fi-functions-arduino/" target="new">ESP32 WiFi Functions</a>
: : : 
<a href="https://deepbluembedded.com/esp32-wifi-library-examples-tutorial-arduino/" target="new">ESP32 WiFi Tutorial</a>
</p>

<hr>
<a href="#contents"><img src="images/back.png" alt="Logo" width = 100%></A>
<br>

</tr>


<tr>
<td align="center" colspan=2 id="contact" width = 90%>
<b>CONTACT</b>
<br>
<a href="mailto:tez@solarpunklab.org">tez@solarpunklab.org
</a>
<br>
<br>
<a href="#contents"><img src="images/back.png" alt="Logo" width = 100%></A>
<br>
</tr>


<tr>
<!--  BEGIN COMMENT
<img src="images/osr-slides-qr.png" alt="Logo" width = 50%>
<br>
<a href="https://tinyurl.com/4wwd5sww
">OSR workshop slides</a>
END COMMENT  -->


</tr>
</table>

