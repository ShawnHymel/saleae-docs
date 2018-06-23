/**
 * Digital Example for Arduino
 * 
 * Counts up in binary on 8 pins, rolls over to 0, and continues counting.
 * 
 * To run: open in the Arduino software. Click Upload.
 * 
 * Copyright (c) 2018 Saleae, Inc.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

// Pins
const int NUM_PINS = 8;
const int OUT_PINS[] = {2, 3, 4, 5, 6, 7, 8, 9};

// Counter
uint8_t cnt = 0;

void setup() {
  
  // Set up pins
  for ( uint8_t i = 0; i < NUM_PINS; i++ ) {
    pinMode(OUT_PINS[i], OUTPUT);
  }
}

void loop() {
  uint8_t bit_val;
  
  // Set pins equal to binary value in counter
  for ( uint8_t i = 0; i < NUM_PINS; i++ ) {
    bit_val = (cnt >> i) & 1;
    digitalWrite(OUT_PINS[i], bit_val);
  }

  // Increment counter and roll over if necessary
  cnt++;
}
