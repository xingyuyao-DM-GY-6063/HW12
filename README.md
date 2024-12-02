# HW12

## **Description**
This project implements a **physical password machine** using an Arduino Nano, two buttons, a potentiometer, and two LEDs (green for success, red for failure). 

### **Password Logic**
The correct password sequence is as follows:
1. **Step 1**: Press Button 1 (connected to D3).
2. **Step 2**: Turn the potentiometer all the way to the left (analog value near 0).
3. **Step 3**: Turn the potentiometer all the way to the right (analog value near 1023).
4. **Step 4**: Press Button 2 (connected to D4).

### **Failure Conditions**
- If Button 1 is pressed at **Step 4** instead of Button 2, the password will fail, and the red LED will light up.
- Any incorrect step in the sequence will reset the process, and the red LED will light up for 2 seconds to indicate failure.

## **Circuit Schematic**

Here is the schematic of the circuit, showing all components and connections:

### **Components and Connections**
LINK:[Schematic Drawing](https://app.cirkitdesigner.com/project/485fc07d-0ace-4c3e-b583-2e203025ef68)  
IMAGE:[HW12circuit](https://drive.google.com/file/d/1Jayxrtx5quGxuCSnPSu12aYNG8JBSbbl/view?usp=sharing)  
- **Button 1 (D3)**:
  - One pin connected to `D3` on the Arduino.
  - The other pin connected to `5V` with a **10kΩ pull-down resistor** connected to `GND`.

- **Button 2 (D4)**:
  - One pin connected to `D4` on the Arduino.
  - The other pin connected to `5V` with a **10kΩ pull-down resistor** connected to `GND`.

- **Potentiometer (A0)**:
  - Left pin connected to `GND`.
  - Right pin connected to `5V`.
  - Middle pin connected to `A0` on the Arduino.

- **Green LED (D9)**:
  - Anode connected to `D9` through a **220Ω resistor**.
  - Cathode connected to `GND`.

- **Red LED (D10)**:
  - Anode connected to `D10` through a **220Ω resistor**.
  - Cathode connected to `GND`.

## **How to Use**
1. Connect the circuit as described in the schematic.
2. Upload the Arduino sketch to the board.
3. Follow the correct sequence:
   - Press Button 1.
   - Turn the potentiometer all the way to the left.
   - Turn the potentiometer all the way to the right.
   - Press Button 2.
4. Observe the LEDs:
   - Green LED for success.
   - Red LED for failure.

