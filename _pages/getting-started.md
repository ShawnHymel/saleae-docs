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

## How to Measure Analog Signals

One helpful feature of your Saleae Logic Analyzer is its ability to measure analog signals (from 0 to 5 V). 

## How to Measure Digital Logic

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