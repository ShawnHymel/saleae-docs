---
layout: single
title: Saleae Logic Analyzer Getting Started Guide
permalink: /getting-started/
toc: true
---

## Introduction

The Saleae Logic Analyzer is a powerful tool capable of capturing multiple signals from a digital circuit and displaying that information in the form of timing diagrams. Saleae's *Logic* software can help you decode a variety of digital protocols, including UART, SPI, I<sup>2</sup>C, 1-Wire, I<sup>2</sup>S, CAN, USB, and many more. These features can make debugging your embedded designs much simpler.

![Saleae logic analyzer with test circuit]({{ site.baseurl }}/assets/images/getting-started/saleae_example_circuit.jpg?style=center)

This tutorial will show you how to install the *Logic* software and analyze simulated digital signals. It will then cover how to analyze analog signals, digital logic, UART, SPI, and I<sup>2</sup>C in a live circuit.

### Required Materials

To follow along with this guide, you will need the following equipment:

![Required hardware for this guide]({{ site.baseurl }}/assets/images/getting-started/saleae_required_parts.jpg?style=center)

 * One of the Saleae logic analyzers:
   - [Saleae Logic 8](https://usd.saleae.com/products/saleae-logic-8)
   - [Saleae Logic Pro 8](https://usd.saleae.com/products/saleae-logic-pro-8)
   - [Saleae Logic Pro 16](https://usd.saleae.com/products/saleae-logic-pro-16)
 * [Nucleo-F446RE](https://www.digikey.com/product-detail/en/stmicroelectronics/NUCLEO-F446RE/497-15882-ND/5347712)
 * [MCP3002 10-bit analog-to-digital converter (ADC)](https://www.digikey.com/product-detail/en/microchip-technology/MCP3002-I-P/MCP3002-I-P-ND/319412)
 * [10k potentiometer](https://www.digikey.com/product-detail/en/sparkfun-electronics/COM-09806/1568-1616-ND/7319606)
 * [TMP102 temperature sensor breakout board](https://www.digikey.com/product-detail/en/sparkfun-electronics/SEN-13314/1568-1520-ND/6797646)
 * [Male 0.100 inch headers](https://www.digikey.com/product-detail/en/sullins-connector-solutions/PRPC040SAAN-RC/S1011EC-40-ND/2775214)
 * [Breadboard](https://www.digikey.com/product-detail/en/bud-industries/BB-32621/377-2094-ND/4156445)
 * [Jumper wires](https://www.digikey.com/product-detail/en/sparkfun-electronics/PRT-12795/1568-1512-ND/5993860)

## Hardware Overview

The Logic Analyzer is a small box with a lot of processing power.

![Required hardware for this guide]({{ site.baseurl }}/assets/images/getting-started/saleae_logic_analyzer.jpg?style=center)

On the front of your Logic Analyzer, you will find a set of headers used for connecting the cable harnesses, which come with your Logic Analyzer kit. You are welcome to use female jumper wires, as well, if you wish to individually connect pins.

For each header, the top row of pins are your signal pins. They are numbered 0-7 (Logic 8) or 0-15 (Logic 16). All of the pins on the bottom row are intended to be connected to ground (or common) in your test circuit.

![Annotated pins on the Saleae logic analyzer]({{ site.baseurl }}/assets/images/getting-started/saleae_annotated_pins.png?style=center)

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
    <th style="text-align:center; background-color:purple">Ch 7</th>
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

Download the Saleae Logic software by navigating to the [Saleae Downloads page](https://www.saleae.com/downloads/). Select your operating system, and click the download button.

### Windows

Find and run the .exe installer that you downloaded. Follow the on-screen prompts to install any necessary drivers.

If you run into any issues, you can try downloading the [Windows Standalone release](https://support.saleae.com/hc/en-us/articles/115005972023-saleae-logic-beta-software), which does not require running an installer. Note that you will need to [manually install the drivers](https://answers.microsoft.com/en-us/windows/forum/windows_10-hardware-winpc/how-to-install-and-update-hardware-drivers-in/a97bbbd1-9973-4d66-9a5b-291300006293) for the Logic Analyzer, which can be found in the *Drivers* folder.

### Mac

After downloading the application, double-click on its icon, and drag the Logic.app into the Applications folder.

![Installing Saleae Logic on macOS]({{ site.baseurl }}/assets/images/getting-started/mac_install.png?style=center)

### Linux

Download the .zip file and extract it. There is nothing to install, as the *Logic* application can be run directly from the extracted directory.

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

Open the Logic software with the logic analyzer plugged in. Click on the **Device Settings Button**.

In the device settings window, set the speed to **at least 50 MS/s** and the duration to **1 second**. Click both **Clear** buttons to disable all channels, leaving only the digital channel 0 enabled. Click the **analog Channel 0** to enable it, and click the **digital Channel 0** to disable it.

![Enable analog channel in Logic software]({{ site.baseurl }}/assets/images/getting-started/screen_12.png?style=center)

Click the **Device Settings Button** again to close the configuration window. Click **Start** to begin collecting data. After a moment, you should see a sinewave appear in the main window. Note that you might have to zoom out. If you hover your mouse over the sinewave, you should see the measured voltage at that time pop up.

![Measuring the analog voltage level on a sinewave with Logic]({{ site.baseurl }}/assets/images/getting-started/screen_13.png?style=center)

If you would like to measure the time between two points on the signal, you can select the A1 and A2 markers underneath the *Timing Marker Pair* tab on the right side. Click the **A1** button, which will put a marker on your cursor. Click on a peak in the waveform. Click on **A2**, which will put another marker on your cursor. Find an adjacent peak to place the second marker. You should see the time difference between those points appear next to the A1 and A2 buttons.

![Measuring the time difference between two points on a sinewave]({{ site.baseurl }}/assets/images/getting-started/screen_14.png?style=center)

As you can see, the period is measured to be about 10 ms, which is close to the 100 Hz we set in the demo programs.

## How to Analyze UART

Universal Asynchronous Receiver/Transmitter (UART) is a fairly simple protocol with two lines (transmit and receive) going between two devices. The lines are normally held high until one of the devices wish to communicate. At which point, the transmitting device pulls its transmit line low and sends out data with logic high being 1 and logic low being 0.

### Connect Hardware

Note that on the Nucleo-F446RE, the UART lines used to communicate with the host computer are connected to the programming chip next to the USB connector. Arduino pins RX/D0 and TX/D1 are disconnected from these lines by default, which means we need to use the RX and TX pins near the programming chip.

Connect the GND wire to an available ground pin on the Nucleo. Connect Channel 0 to TX and connect Channel 1 to RX.

[![Connect Saleae logic analyzer to development board to measure serial signals]({{ site.baseurl }}/assets/images/getting-started/uart_circuit_fritzing.png?style=center)]({{ site.baseurl }}/assets/images/getting-started/uart_circuit_fritzing.png?style=center)

### Run Demo Application

Download the example code for your IDE:

 * [UART Example - Arduino]({{ site.baseurl }}/assets/code/uart_example_arduino.zip)
 * [UART Example - mbed]({{ site.baseurl }}/assets/code/uart_example_mbed.zip)
 * [UART Example - SW4STM32]({{ site.baseurl }}/assets/code/uart_example_sw4stm32.zip)

Open the demo in your chosen IDE. Compile the program, and upload it to the Nucleo-F446RE development board.

Download and open a serial terminal program. Here are some suggestions:

 * Windows: [PuTTY](https://www.putty.org/), [Tera Term](https://ttssh2.osdn.jp/index.html.en)
 * Mac: [Serial](https://decisivetactics.com/products/serial/), [CoolTerm](http://freeware.the-meiers.org/)
 * Linux: [screen](https://www.gnu.org/software/screen/manual/screen.html), [Terminator](https://launchpad.net/terminator)
 
Connect to the Nucleo board over the assigned serial port with a baud rate of **115200**, 8 data bits, no parity bit, and 1 stop bit (**8-N-1**). Once you open the connection, anything you type should be echoed back to you.

![Testing the serial echo program]({{ site.baseurl }}/assets/images/getting-started/screen_15.png?style=center)

### Measure the Signal

Open the Logic software with the logic analyzer plugged in. Click on the **Device Settings Button**.

In the device settings window, set the speed to **at least 50 MS/s** and the duration to **1 second**. Click both **Clear** buttons to disable all channels, leaving only the digital channel 0 enabled. Click the **digital Channel 1** to enable it as well.

![Setting up to capture UART signals with Logic]({{ site.baseurl }}/assets/images/getting-started/screen_16.png?style=center)

Click the **Device Settings Button** again to close the configuration window. With this setup, channel 0 is configured to capture UART data going from your computer to the Nucleo board (TX on the Nucleo), and channel 1 is configured to capture data from the Nucleo to your computer (RX on the Nucleo).

By default, triggering is set to occur on the rising edge of channel 0. UART is by default high, so we want to start capturing whenever the TX line drops low (*start bit*). Click the **Trigger Button** next to *Channel 0* to bring up the *Trigger Settings* pop-up. Select the **Trigger on Falling Edge** option.

![Select falling edge option for triggering with the Saleae logic analyzer]({{ site.baseurl }}/assets/images/getting-started/screen_17.png?style=center)

Click on the **Trigger Button** again to close the pop-up. Click **Start**, and you should see the Logic software tell you that it is waiting for a trigger.

Back in your serial terminal program, type the letter 'a'. The Logic software should begin capturing data and then show you the results.

![Captured UART data]({{ site.baseurl }}/assets/images/getting-started/screen_18.png?style=center)

Click on the plus button (**+**) next to *Analyzers* on the right side of the Logic software. Select **Async Serial** to bring up the Serial settings window. Select **0 - 'Channel 0'** for *Serial*, change the bit rate to **115200**, and leave the rest alone.

![Configure the analyzer settings]({{ site.baseurl }}/assets/images/getting-started/screen_19.png?style=center)

Repeat this process to add an additional analyzer, but set the channel to **1 - 'Channel 1'**.

You should see two "Async Serial" bars appear under the *Analyzers* pane. Additionally, the captured serial data should both have the letter 'a' over them. This shows that you captured the ASCII letter 'a' going from the computer to the Nucleo and the same letter being echoed back.

![Analyzing captured serial data with the Logic software]({{ site.baseurl }}/assets/images/getting-started/screen_20.png?style=center)

Try measuring the time it takes for your Nucleo to capture and echo a letter, and see if you can type a few more letters during the capture period and decode them.

## How to Analyze SPI

Serial Peripheral Interface (SPI) is a communication protocol often used between processors and devices that require a relatively fast interface, such as shift registers, flash memory, and some sensors. It is a *synchronous* protocol, which means it requires a separate clock line so that the transmitter can tell the receiver when to sample the data line.

Interestingly, SPI connections often rely on two data lines: MISO and MOSI. Because of this, data can be sent between the master and device at the same time (known as *full duplex*).

### Connect Hardware

Even though the Nucleo-F446RE has an onboard analog-to-digital converter (ADC), the MCP3002 is an easy-to-use and inexpensive ADC that communicates over SPI, which makes it perfect for demonstrating the protocol.

Connect the Nucleo to the MCP3002 and the MCP3002 to a 10k potentiometer as shown. Note that the SPI pins are also broken out to the male pins just to the right of the female Arduino headers on the Nucleo. This allows us to attach the Saleae logic analyzer wires.

[![Connect Saleae logic analyzer to development board to measure SPI signals]({{ site.baseurl }}/assets/images/getting-started/spi_circuit_fritzing.png?style=center)]({{ site.baseurl }}/assets/images/getting-started/spi_circuit_fritzing.png?style=center)

### Run Demo Application

Download the example code for your IDE:

 * [SPI Example - Arduino]({{ site.baseurl }}/assets/code/spi_example_arduino.zip)
 * [SPI Example - mbed]({{ site.baseurl }}/assets/code/spi_example_mbed.zip)
 * [SPI Example - SW4STM32]({{ site.baseurl }}/assets/code/spi_example_sw4stm32.zip)

Open the demo in your chosen IDE. Compile the program, and upload it to the Nucleo-F446RE development board.

Open the serial terminal program that you downloaded from the UART example.
 
Connect to the Nucleo board over the assigned serial port with a baud rate of **115200**, 8 data bits, no parity bit, and 1 stop bit (**8-N-1**). Open the connection, and you should see the voltage from the MCP3002 being reported to you in regular intervals. Try turning the knob on the potentiometer to see the voltage change.

![Testing the SPI program]({{ site.baseurl }}/assets/images/getting-started/screen_21.png?style=center)

### Measure the Signal

Open the Logic software with the logic analyzer plugged in. Click on the **Device Settings Button**.

In the device settings window, set the speed to **at least 50 MS/s** and the duration to **1 second**. Click both **Clear** buttons to disable all channels, leaving only the digital Channel 0 enabled. Click **digital Channels 1-3** to enable them.

![Setting up to capture SPI signals with Logic]({{ site.baseurl }}/assets/images/getting-started/screen_22.png?style=center)

We can set up the analyzer before we capture so that we can choose the appropriate signal as the trigger. Click on the plus button (**+**) next to *Analyzers* on the right side. Select **SPI** to bring up the settings window. Leave everything as default and click **Save**.

![Setting the SPI lines in the Logic software]({{ site.baseurl }}/assets/images/getting-started/screen_23.png?style=center)

The *Enable* line (also known as *CS* or *SS*) is often the first signal to change prior to data being transmitted on a SPI bus. As a result, we'll set our trigger on that line. Click on the **Trigger Button** next to *Channel 3 (SPI - ENABLE)*, and select the **Trigger on Falling Edge** option.

![Selecting a falling edge trigger for the SPI Enable line]({{ site.baseurl }}/assets/images/getting-started/screen_24.png?style=center)

Click on the **Trigger Button** again to close the pop-up. Click **Start** to begin collecting data. Because our code is set to send SPI data every 0.2 seconds, data collection should begin almost immediately.

Zoom in around the *0 s : 0 ms : 0 μs* mark, and you should see the waveforms that traveled across the SPI bus at that moment. Click on the *gear icon* next to *SPI* under *Analyzers*. Click on **Bin** under *Display Radix* to show the interpreted data as binary.

Above Channel 0 (MOSI), you should see the data that we are transmitting out from the Nucleo board: 0b11000000 for the first byte, and all 0s for the second byte. At the same time, data comes back in from the MCP3002 on Channel 1 (MISO). In this instance, only bits 1-10 carry information about the measured voltage.

![Reading SPI data with the Logic software]({{ site.baseurl }}/assets/images/getting-started/screen_25.png?style=center)

Adjust the potentiometer and see if you get different data on the MISO line when you sample again.

## How to Analyze I<sup>2</sup>C

Inter-Integrated Circuit (I<sup>2</sup>C, I2C, or IIC) is a 2-wire communication protocol that allows multiple low-speed peripherals, such as sensors, to be attached to the same bus. Normally, a single microprocessor or microcontroller is configured as the master, which initiates all communication on the bus.

The 2 lines used in I<sup>2</sup>C are Serial Data Line (SDA) and Serial Clock Line (SCL). The lines are [open collector or open drain](https://en.wikipedia.org/wiki/Open_collector), which means the drivers on the master or devices can pull the lines low but cannot pull them high. This configuration prevents damage to the drivers when more than one device attempts to communicate on the bus at the same time.

### Connect Hardware

One of the easiest to use I<sup>2</sup>C sensors is the inexpensive TMP102 temperature sensor. The sensor can be configured to drive an alert pin when certain temperature thresholds are met. However, we only need to worry about reading from the Temperature register, as on power up, the TMP102 will simply begin sampling and storing temperature data in that register.

Connect the Nucleo to the TMP102 breakout board as shown in the following diagram. Note that GND, SDA, and SCL are broken out to the male pins to the right of the female Arduino headers on the Nucleo. This setup allows us to attach the Saleae logic analyzer wires.

[![Connect Saleae logic analyzer to development board to measure I2C signals]({{ site.baseurl }}/assets/images/getting-started/i2c_circuit_fritzing.png?style=center)]({{ site.baseurl }}/assets/images/getting-started/i2c_circuit_fritzing.png?style=center)

### Run Demo Application

Download the example code for your IDE:

 * [I2C Example - Arduino]({{ site.baseurl }}/assets/code/i2c_example_arduino.zip)
 * [I2C Example - mbed]({{ site.baseurl }}/assets/code/i2c_example_mbed.zip)
 * [I2C Example - SW4STM32]({{ site.baseurl }}/assets/code/i2c_example_sw4stm32.zip)

Open the demo in your chosen IDE. Compile the program, and upload it to the Nucleo-F446RE development board.

Open the serial terminal program that you downloaded from the UART example.
 
Connect to the Nucleo board over the assigned serial port with a baud rate of **115200**, 8 data bits, no parity bit, and 1 stop bit (**8-N-1**). Open the connection, and you should see the temperature (in Celsius) being reported to you in regular intervals. Try breathing on the TMP102 sensor to change the readings.

![Testing the I2C program]({{ site.baseurl }}/assets/images/getting-started/screen_26.png?style=center)

### Measure the Signal

Open the Logic software with the logic analyzer plugged in. Click on the **Device Settings Button**.

In the device settings window, set the speed to **at least 50 MS/s** and the duration to **1 second**. Click both **Clear** buttons to disable all channels, leaving only digital Channel 0 enabled. Click **digital Channel 1** to enable it as well.

![Setting up to capture I2C signals with Logic]({{ site.baseurl }}/assets/images/getting-started/screen_27.png?style=center)

Set the analyzer by clicking on the plus button (**+**) next to *Analyzers* on the right side. Select **I2C** to bring up the settings window. Leave everything as default and click **Save**.

![Setting the I2C lines in the Logic software]({{ site.baseurl }}/assets/images/getting-started/screen_28.png?style=center)

The data line (SDA) is normally the first signal to change during an I<sup>2</sup>C transfer. Because the lines are *open drain*, they will be nominally high, which means that we need to watch for a high-to-low transition. Click on the **Trigger Button** next to *Channel 0 (I2C - SDA)*, and select the **Trigger on Falling Edge** option.

![Selecting a falling edge trigger for I2C SDA line]({{ site.baseurl }}/assets/images/getting-started/screen_29.png?style=center)

Click on the **Trigger Button** again to close the pop-up. Click **Start** to begin collecting data. Because we told the Nucleo to read from the sensor every 0.2 seconds, we should begin collecting data right away.

Zoom in around the *0 s : 0 ms : 0 μs* mark, and you should see some I<sup>2</sup>C data. Click on the *gear icon* next to *I2C* under *Analyzers*. Click on **Hex** under *Display Radix* to show the interpreted data as hexadecimal.

You should see a write operation and a read operation. Both should begin with the address of the TMP102, which is 0x48 as a 7-bit number. If we shift it left by 1 bit, we get 0x90, and the last bit determines the type of operation (0 for read and 1 for write).

![Reading I2C data with the Logic software]({{ site.baseurl }}/assets/images/getting-started/screen_30.png?style=center)

If you look at the write operation, you should see that the address is followed by the memory location of the TMP102's *Temperature* register (0x00) and an *ACK* (line is low for 1 bit). Immediately following the write operation, you should see a read operation. Here, the microcontroller waits for 2 bytes to be sent by the TMP102. In the picture, the bytes returned are 0x017 0x30 (binary 0001 0111 0011 0000). The first byte is followed by an *ACK* (line kept low for 1 bit) and the second byte is followed by a *NACK* (line returned to high for 1 bit to indicate the end of the transmission).

## Troubleshooting

### I'm getting cross-talk from other sources

Make sure you connect a ground wire for each signal wire on the logic analyzer.

### How can you view the signals in real time?

Real-time view is currently available in the [latest beta release of the Logic software](https://support.saleae.com/hc/en-us/articles/115005972023-saleae-logic-beta-software). Please note that this is an early release of the application and may not be stable on all systems.

### While collecting data or waiting for a trigger, I get the error message: "We're sorry, but the device was not able to keep up with this sample rate"

First, check to make sure that your logic analyzer is plugged directly into a USB port on your computer. Due to the high data rates required, having the analyzer plugged into a USB hub may result in errors.

If the problem persists, try lowering the sampling rate (Settings > Speed).

### How do I protect my Saleae logic analyzer from damage?

Avoid connecting the analyzer inputs to voltages greater than ±25 V.

Common mode current can potentially damage the analyzer in the presence of a ground loop. For example, if your logic analyzer and device under test (DUT) have separate USB connections back to your computer, this can create a ground loop. If you were to accidentally brush one of the analyzer's ground probes against a power supply pin on the DUT (e.g. 5V) with a ground loop present, you risk sending large amounts of current through the analyzer and damaging it.

To learn more about ground loops and safety precautions for your logic analyzer, refer to [this article](https://support.saleae.com/hc/en-us/articles/208667786-What-Should-I-Do-to-Avoid-Accidental-Damage-to-the-Device-).

### I'm working with a protocol that isn't in the Logic software

Good news! You can create your own protocol for the Logic software using the [Saleae Analyzer SDK](https://support.saleae.com/hc/en-us/articles/115005987726-Protocol-Analyzer-SDK).

### Where can I go for help?

Take a look at the [Saleae Troubleshooting & Information page](https://support.saleae.com/hc/en-us/categories/201256726-Troubleshooting-Information) to see if your question has been asked before.

If you are still running into trouble, [contact Saleae directly](https://support.saleae.com/hc/en-us/requests/new).

## Resources

If you would like to learn more about the different protocols, check out these guides:

 * [Asynchronous Serial](https://support.saleae.com/hc/en-us/articles/115005987086-Learn-Asynchronous-Serial)
 * [SPI - Serial Peripheral Interface](https://support.saleae.com/hc/en-us/articles/115005971423-Learn-SPI-Serial-Peripheral-Interface)
 * [I2C - Inter-Integrated Circuit](https://support.saleae.com/hc/en-us/articles/115005987106-Learn-I2C-Inter-Integrated-Circuit)
 
Datasheets and the Saleae User's Guide can be found on [this page](https://support.saleae.com/hc/en-us/articles/115005971303-PDF-Users-Guide-Specifications-and-Data-Sheets)