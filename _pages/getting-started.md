---
layout: single
title: Saleae Logic Analyzer Getting Started Guide
permalink: /getting-started/
toc: true
---

## Introduction

The Saleae Logic Analyzer is a powerful tool capable of capturing multiple signals from a digital circuit and displaying that information in the form of timing diagrams. Saleae's *Logic* software can help you decode a variety of digital protocols, including UART, SPI, I<sup>2</sup>C, 1-Wire, I<sup>2</sup>S, CAN, USB, and many more. These features can make debugging your embedded designs much simpler.

%%%Anlyzer plugged into breadboard circuit%%%

This tutorial will show you how to install the *Logic* software and analyze simulated digital signals. It will then cover how to analyze digital logic, UART, SPI, and I<sup>2</sup>C in a live circuit.

### Required Materials

To follow along with this guide, you will need the following equipment:

%%%TODO: PHOTOS OF EACH%%%

 * One of Logic Analyzers
 * Nucleo-F446RE
 * SparkFun BME280 (or TMP102/MCP3002)
 * Breadboard
 * Hookup wires

## Hardware Overview

The Logic Analyzer is a small box with a lot of processing power.

%%%OVERVIEW SHOT OF ANAYLZER%%%

On the front of your Logic Analyzer, you will find a set of headers used for connecting the cable harnesses, which come with your Logic Analyzer kit. You are welcome to use female jumper wires, as well, if you wish to individually connect pins.

For each header, the top row of pins are your signal pins. They are numbered 0-7 (Logic 8) or 0-15 (Logic 16). All of the pins on the bottom row are intended to be connected to ground (or common) in your test circuit.

%%%ANNOTATED FRONT OF ANALYZER--BLUR OUT PARTS%%%

<div class="notice--info">
    <b>Note:</b> The headers have a ground pin for each signal pin. For most low-speed or basic circuits, you can connect one ground pin as a reference for the whole circuit. If you want to measure high-speed digital signals or analog signals in a noisy environment, it's highly recommended that you connect a ground for each signal.
</div>

Each cable harness has an arrow on the top of the connector. This arrow should point up (same side as the Saleae logo) and to the left (the side with the 'S' in Saleae).

%%%CLOSE UP OF ARROW GOING INTO PORT%%%

If you only need to measure 1-4 signals, you can plug in just the first set of cables on the left side (channels 0 through 3). If you need more, you can attach an additional cable harness to channels 4-7. The Logic Pro 16 has an additional 8 channels available for your use.

<div class="notice--info">
    <b>Note:</b> All channels are capable of measuring analog and digital signals between 0 and 5 V.
</div>

To help you identify the channels, the colors of the wires on the cable harness match up to the resistor code:

%%%ANNOTATED WIRES AND COLORS%%%

<table>
<tr>
    <th style="text-align:center; background-color:black">Ch 0</th>
    <th style="text-align:center; background-color:brown">Ch 1</th>
    <th style="text-align:center; background-color:red">Ch 2</th>
    <th style="text-align:center; background-color:orange">Ch 3</th>
    <th style="text-align:center; background-color:yellow">Ch 4</th>
    <th style="text-align:center; background-color:green">Ch 5</th>
    <th style="text-align:center; background-color:blue">Ch 6</th>
    <th style="text-align:center; background-color:violet">Ch 7</th>
</tr>
</table>

On the Logic Pro 16, this color code is repeated for channels 8-15.

The end of each test lead is terminated in a wrapped and crimped connector that will attach to standard 0.100-inch headers.

%%%CLOSE UP OF BARE HEADER%%%

Your kit also comes with test clips for each lead on the cable harness. Attach the crimped wire end into the back of the test clip. By pushing on the back of the test clip, you can attach the clip to wires, headers, DIP, and SOIC-type packages. If you need to measure signals from a finer-pitch part, you may want to consider soldering a small-gauge wire (e.g. 30 AWG) to an exposed pin, pad, or trace.

%%%TEST CLIP ON MCP3002 ON BREADBOARD%%%

If you were to pry open your Logic Analyzer (not recommended), you would find a Xilinx Spartan 6 FPGA and an 8-channel analog-to-digital converter (2 ADCs on the Logic Pro 16). Together, these work in tandem to sample signals and stream data back to your computer for analysis in the Logic software.

![Opened Saleae Logic 8]({{ site.baseurl }}/assets/images/getting-started/logic_8_open.png?style=center)

Depending on the model you have, the features may be different:

<table>
<tr>
    <td></td>
    <td style="text-align:center;"><a href="https://usd.saleae.com/products/saleae-logic-8">Logic 8</a></td>
    <td style="text-align:center;"><a href="https://usd.saleae.com/products/saleae-logic-pro-8">Logic Pro 8</a></td>
    <td style="text-align:center;"><a href="https://usd.saleae.com/products/saleae-logic-pro-16">Logic Pro 16</a></td>
</tr>
<tr>
    <td>Channels</td>
    <td style="text-align:center;">8</td>
    <td style="text-align:center;">8</td>
    <td style="text-align:center;">16</td>
</tr>
<tr>
    <td>Max Digital Sample Rate</td>
    <td style="text-align:center;">100 MS/s</td>
    <td style="text-align:center;">500 MS/s</td>
    <td style="text-align:center;">500 MS/s</td>
</tr>
<tr>
    <td>Max Analog Sample Rate</td>
    <td style="text-align:center;">10 MS/s</td>
    <td style="text-align:center;">50 MS/s</td>
    <td style="text-align:center;">50 MS/s</td>
</tr>
<tr>
    <td>Computer Connection</td>
    <td style="text-align:center;">USB 2.0</td>
    <td style="text-align:center;">USB 3.0</td>
    <td style="text-align:center;">USB 3.0</td>
</tr>
</table>

<div class="notice--warning">
    <b>Warning:</b> The logic analyzer needs to send a lot of data very quickly over the USB lines. As a result, it is recommended that you plug the logic analyzer directly into an available USB port on your computer (i.e. not through a USB hub). Otherwise, you might get an error such as "We're sorry, but the device was not able to keep up with this sample rate."
</div>

## Logic Software Installation

Download the Saleae Logic software by navigating to the [Salaea Downloads page](https://www.saleae.com/downloads/). Select your operating system, and click the download button.

### Windows

Find and run the .exe installer that you downloaded. Follow the on-screen prompts to install any necessary drivers.

If you run into any issues, you can try downloading the [Windows Standalone release](https://support.saleae.com/hc/en-us/articles/115005972023-saleae-logic-beta-software), which does not require running an installer. Note that you will need to [manually install the drivers](https://answers.microsoft.com/en-us/windows/forum/windows_10-hardware-winpc/how-to-install-and-update-hardware-drivers-in/a97bbbd1-9973-4d66-9a5b-291300006293) for the Logic Analyzer, which can be found in the *Drivers* folder.

### Mac

After downloading the application, double-click on its icon, and drag the Logic.app into the Applications folder.

![Installing Saleae Logic on macOS]({{ site.baseurl }}/assets/images/getting-started/mac_install.png?style=center)

### Linux

Download the .zip file and extract it. There is nothing to install, as the *Logic* application can be run directly from the extracted directory.

%%%SCREENSHOT OF LOGIC APP FILE%%%

Before running the application, you will need to give permission to the application to access the hardware device. Make sure your Logic Analyzer is unplugged, open a command prompt, and navigate to the *Drivers* directory within the Logic application directory. From there, run *install_driver.sh*.

    cd ~/"Logic 1.2.18 (64-bit)"/Drivers
    ./install_drivers.sh

Navigate back into the extracted directory and run the *Logic* application, either by double-clicking on it or entering:

    ./Logic

## Using the Simulator

If you don't have access to the Logic Analyzer hardware yet, you can still use the software in simulation mode to understand how it works. Make sure the Logic Analyzer is not plugged in to your computer, and open the Saleae Logic software. Click the **Start Simulation** button in the top left corner.

![Running a simulation in the Saleae Logic software]({{ site.baseurl }}/assets/images/getting-started/screen_01.png?style=center)

Use your mouse wheel or minus (-) key to zoom out. Click and drag on the main display to move the captured waveforms in the time domain. Hover your mouse pointer over some of the digital waveforms, Logic will give you an automatic reading of the width (w) of the high or low pulse in seconds (s), milliseconds (ms), or microseconds (μs). It will also take the measurement of the next pulse to give you an estimate of the frequency (f) and period (τ).

![Analyzing digital pulses in the Saleae Logic simulation]({{ site.baseurl }}/assets/images/getting-started/screen_02.png?style=center)

Scroll down either by holding *Shift* and using your mouse wheel or by clicking and dragging on the translucent scroll bar on the right side of the main waveforms pane. Zoom in (mouse wheel or + key) and hover your mouse over the sine wave. You should get a pop-up showing you the analog voltage at that time.

![Analyzing an analog waveform in the Saleae Logic simulation]({{ site.baseurl }}/assets/images/getting-started/screen_03.png?style=center)

## Device Calibration

Calibration information for your Logic Analyzer is generated at the factory, requiring no input from the user, and is stored on Saleae's servers. You will need to download this file for your Logic Analyzer to work properly.

Plug your Saleae Logic Analyzer into your computer. When you open the Logic software, it will identify your unique Logic Analyzer serial code. This information can be used to download the Logic Analyzer's calibration file. By default, the Logic software will attempt to automatically download the calibration file from the Internet. Without an Internet connection, you will need to manually download the file elsewhere.

### Automatically Download Calibration File

Make sure your computer is connected to the Internet. With the Logic Analyzer plugged in, open the Logic software. Click on the **Options** button in the top-right corner. Click on **Preferences** and navigate to the **Calibration Info** tab. You should see the calibration information filled out for your device.

![Automatically downloaded device calibration data]({{ site.baseurl }}/assets/images/getting-started/screen_05.png?style=center)

### Manually Download Calibration File

If your Logic software is unable to download the calibration file (e.g. you do not have Internet access on the computer running Logic), you will need to download it manually. Open the Logic software and click on the **Options** button in the top-right corner. Click on **Preferences** and navigate to the **Calibration Info** tab. You should see that no calibration data is available for your device.

![Identifying your Saleae Logic Analyzer serial ID]({{ site.baseurl }}/assets/images/getting-started/screen_04.png?style=center)

Copy or write down your *Device ID*. On a computer with Internet access, open a browser and navigate to

[https://downloads.saleae.com/calibration/{Insert Device ID here}.cal](https://downloads.saleae.com/calibration/{Insert Device ID here}.cal)

Replace {Insert Device ID here} with your actual Device ID. Note that you must convert your device ID to all lowercase (an [online tool like this](https://convertcase.net/) might help). For example: 

https://downloads.saleae.com/calibration/3b2e3a21ca4ad130.cal

Copy your .cal file and paste it into the software's calibration folder:

 * **Windows 10/8/7/Vista:** C:\Users\YourUserName\AppData\Roaming\Saleae
LLC\Logic\Calibration
 * **Windows XP:** C:\Documents and Settings\YourUserName\Application Data\Saleae
LLC\Logic\Calibration
 * **Mac:** /Users/YourUserName/Library/Preferences/Saleae/Calibration
 * **Linux:** Create a directory named *Calibration* in the same directory as the *Logic* executable. Paste the .cal file into the newly created *Calibration* directory.

Restart the Logic software and verify that the calibration file was loaded successfully (Options > Preferences, Calibration Info tab).

## How to Measure Digital Logic

The easiest way to test your logic analyzer is to use it to measure digital signals, that is, voltages that transition between two discrete values, such as 0 V and 3.3 V.

To demonstrate this, we have example code for the STM32 Nucleo-F446RE that can be uploaded via [Arduino](https://www.arduino.cc/), [mbed](https://os.mbed.com/), or as a project for the [AC6 System Workbench for STM32 (SW4STM32)](http://www.openstm32.org/) integrated development enviroment (IDE).

### Connect Hardware

To begin, plug 2 cable harnesses into your Saleae Logic. Note that the arrow on the harness connector should be facing up and toward the left (the 'S' in Saleae on your logic analyzer). While the colors of the wires do not ultimately matter, it can be helpful to have them line up with the resistor color code (from left to right): black, brown, red, orange, yellow, green, blue, violet.

%%%CLOSE UP OF PLUGGING IN HARNESSES%%%

Connect the wires to the male header pins on the Nucleo board as shown in the diagram. Note that most of the inner male pins are connected to the female pins in the Arduino UNO configuration. For a full pinout of the Nucleo-F446RE, refer to the [pinout section on the mbed page](https://os.mbed.com/platforms/ST-Nucleo-F446RE/#nucleo-pinout).

<div class="notice--info">
    Having trouble seeing the diagram? Click on the image to get a better view.
</div>

[![Connect Saleae logic analyzer to development board to measure digital signals]({{ site.baseurl }}/assets/images/getting-started/digital_circuit_fritzing.png?style=center)]({{ site.baseurl }}/assets/images/getting-started/digital_circuit_fritzing.png?style=center)

### Run Demo Application

Download the example code for your IDE:

 * [Digital Example - Arduino]({{ site.baseurl }}/assets/code/digital_example_arduino.zip)
 * [Digital Example - mbed]({{ site.baseurl }}/assets/code/digital_example_mbed.zip)
 * [Digital Example - SW4STM32]({{ site.baseurl }}/assets/code/digital_example_sw4stm32.zip)
 
<div class="notice--info">
    <b>Note:</b> If you would like to try running the code without installing any IDE, download the mbed example. Plug in your Nucleo board, and it should enumerate as a USB mass storage device on your computer. Unzip the example, and copy the .bin file to the Nucleo drive. The Nucleo board will reset, and the program will begin to run automatically.
</div>

Open the demo in your chosen IDE. Compile the program, and upload it to the Nucleo-F446RE development board. Whenever the board has power, it should begin running the digital example program, which counts in binary on pins D2-D9 (D2 is least significant bit).

### Measure Signals

Open the Logic software and make sure your logic analyzer is connected via USB (you should see "Connected" appear at the top of the window). Click on the **Device Settings Button** (the up/down arrow near *Start Simulation*). This will open the device settings window.  

Set the speed to **at least 50 MS/s** and the duration to **1 second** (length of time the analyzer will collect data). Click to enable **8 digital channels** (0 through 7 in the top row). Make sure **3.3+ Volts** is selected.

![Configuring logic analyzer to measure digital signals]({{ site.baseurl }}/assets/images/getting-started/screen_06.png?style=center)

Click the **Device Settings Button** again to close the configuration window. You should see all 8 channels appear on the left side. Click **Start**. The software should take a moment to collect data, and show you the results to the right of their respective channels.

![Capturing digital signals with the Saleae logic analyzer]({{ site.baseurl }}/assets/images/getting-started/screen_07.png?style=center)

Zoom in using your mouse wheel or the plus (+) key. Hover your mouse over a part of the waveform from Channel 0. You should see some text pop up, giving you some information about the pulses. The Logic software will automatically calculate the puslse width (w), the frequency (f), and the period (τ).

![Measuring pulse width, frequency, and period with Saleae Logic]({{ site.baseurl }}/assets/images/getting-started/screen_08.png?style=center)

### Using the Trigger

Sometimes, you need to measure a pulse or signal that happens sporadically. If you are unable to time the capture appropriately (e.g. within the 1 second capture time), you can use *triggers* to start the capture process whenever a channel changes state.

For example, we will configure the Logic software to begin capturing whenever Channel 7 (the most significant bit in our counter) switches from high to low (falling edge). This will center the capturing process around the point (t = 0) when the counter rolls over from 255 (0xFF) to 0 (0x00).

By default, the logic analyzer should be configured to trigger on a rising edge for Channel 0. Click on the **Trigger Settings Button** for Channel 0 and click on the **Rising Edge** button, which should disable all triggers for the analyzer. Verify that the trigger buttons for all channels change to the rising edge icon.

![Disable triggers in the Logic software]({{ site.baseurl }}/assets/images/getting-started/screen_09.png?style=center)

Click on the **Trigger Settings Button** for Channel 7. Select the **Trigger on Falling Edge** button.

![Enable triggering on falling edge in the Saleae Logic software]({{ site.baseurl }}/assets/images/getting-started/screen_10.png?style=center)

Press the **Start** button and wait while the logic analyzers captures and processes data. Waveforms should appear in the main window pane. Zoom in around the trigger point, which should read *0 s : 0 ms : 0μs*. You should see that the falling edge of Channel 7 lines up with this point (origin in time).

![Viewing a waveform that has been captured around a trigger]({{ site.baseurl }}/assets/images/getting-started/screen_11.png?style=center)

If you pan left on the waveforms, you should see that the logic analyzer is capable of capturing up to about 0.5 ms prior to the trigger point.

<div class="notice--info">
    <b>Note:</b> If you zoom in around the trigger point, you should see that not all pins on the microcontroller are capable of toggling at the exact same time. If you're curious about how to measure that time difference, keep reading! In the "How to Measure Analog Signals" section, we use the Timing Markers to measure differences in time. 
</div>

## How to Measure Analog Signals

One useful feature of your Saleae Logic Analyzer is its ability to measure analog signals (from 0 to 5 V).  As such, it can function as an oscilloscope with up to 8 channels (for the Logic 8 and Logic Pro 8) or 16 channels (for the Logic Pro 16).

Depending on the number of channels you use, the Logic 8 can sample up to 10 MS/s (bandwidth of 1 MHz). The Logic Pro 8 and Logic Pro 16 can sample up to 50 MS/s (bandwitch of 5 MHz).

Example code is provided below for Arduino, mbed, and AC6 System Workbench.

### Connect Hardware

For this example, you will only need 1 harness plugged into your logic analyzer. We will be using channel 0. Connect the channel 0 and GND wires to the Nucleo board as shown below. Note that pin PA_4 (A2 on the Arduino headers) is DAC_OUT1 (digital-to-analog converter output 1) on the Nucleo-F446RE.

[![Connect Saleae logic analyzer to development board to measure analog signals]({{ site.baseurl }}/assets/images/getting-started/dac_circuit_fritzing.png?style=center)]({{ site.baseurl }}/assets/images/getting-started/dac_circuit_fritzing.png?style=center)

### Run Demo Application

Download the example code for your IDE:

 * [Analog Example - Arduino]({{ site.baseurl }}/assets/code/analog_example_arduino.zip)
 * [Analog Example - mbed]({{ site.baseurl }}/assets/code/analog_example_mbed.zip)
 * [Analog Example - SW4STM32]({{ site.baseurl }}/assets/code/analog_example_sw4stm32.zip)

Open the demo in your chosen IDE. Compile the program, and upload it to the Nucleo-F446RE development board. Whenever the board has power, it should begin running the analog example program, which produces a sinewave pattern on pin PA_4 (Arduino pin A2).

### Measure the Signal



## How to Analyze Communication Protocols

### UART

UART

### SPI

SPI

### I2C

I2C

![Installing Saleae Logic on macOS]({{ site.baseurl }}/assets/images/getting-started/test_circuit_01.png?style=center)

## Troubleshooting

How to fix things

Ground Loops

Contact Support

## Resources

Check out these other guides.

Datasheets, User's Guide, 