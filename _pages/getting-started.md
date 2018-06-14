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
 * Nucleo-F401RE
 * SparkFun BME280 (or TMP102/MCP3002)
 * Breadboard
 * Hookup wires

## Hardware Overview

The hardware component is a small box with a lot of processing power.

%%%OVERVIEW SHOT OF ANAYLZER%%%

On the front of your logic analyzer, you will find a set of headers used for connecting the cable harnesses, which come with your logic analyzer kit. You are welcome to use female jumper wires, as well, if you wish to individually connect pins.

For each header, the top row of pins are your signal pins. They are numbered 0-7 (Logic 8) or 0-15 (Logic 16). All of the pins on the bottom row are intended to be connected to ground (or common) in your test circuit.

%%%ANNOTATED FRONT OF ANALYZER--BLUR OUT PARTS%%%

<div class="notice">
    <b>Note:</b> The headers have a ground pin for each signal pin. For most low-speed or basic circuits, you can connect one ground pin as a reference for the whole circuit. If you want to measure high-speed digital signals or analog signals in a noisy environment, it's highly recommended that you connect a ground for each signal.
</div>

If you were to pry open (not recommended) your new Saleae Logic Analyzer, you would find a host of electronic components

How to plug in cables.

Label cables/ports/pins.

## Logic Software Installation

### Mac

### Windows

### Linux

## Using the Simulator

## Device Calibration

### Automatically Download Calibration File

### Manually Download Calibration File

## How to Measure Analog Signals

## How to Measure Digital Logic

## How to Analyze Communication Protocols

### UART

UART

### SPI

SPI

### I2C

I2C

## Troubleshooting

How to fix things

Ground Loops

Contact Support

## Resources

Check out these other guides.

Datasheets, User's Guide, 