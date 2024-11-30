# HW12

## **Description**
This project implements a **physical password machine** using an Arduino Nano, two buttons, a potentiometer, and two LEDs (green for success, red for failure). The device allows users to input a specific password sequence using physical inputs. If the correct sequence is followed, the green LED lights up to indicate success. Otherwise, the red LED lights up to indicate failure.

### **Password Logic**
The correct password sequence is as follows:
1. **Step 1**: Press Button 1 (connected to D3).
2. **Step 2**: Turn the potentiometer all the way to the left (analog value near 0).
3. **Step 3**: Turn the potentiometer all the way to the right (analog value near 1023).
4. **Step 4**: Press Button 2 (connected to D4).

### **Failure Conditions**
- If Button 1 is pressed at **Step 4** instead of Button 2, the password will fail, and the red LED will light up.
- Any incorrect step in the sequence will reset the process, and the red LED will light up for 2 seconds to indicate failure.

---

## **Circuit Schematic**

Here is the schematic of the circuit, showing all components and connections:

### **Components and Connections**
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

---

### **Schematic Drawing**

Here is a textual representation of the schematic (you can replace this with a hand-drawn or software-generated image if needed):

```
      +5V                             GND
       |                               |
       |                              (GND Rail)
       |                                |
    [BUTTON 1]-----D3         [BUTTON 2]-----D4
       |                                |
    [10kΩ]                          [10kΩ]
       |                                |
      GND                             GND

    [POTENTIOMETER]
      |  |  |
     GND A0 +5V

        Arduino Nano
          |
        [D9]---(GREEN LED)---220Ω---GND
          |
        [D10]---(RED LED)----220Ω---GND
```

---

## **Finite State Machine (Optional)**

Below is the state machine representation for the password sequence logic:

1. **State 0 (Start)**:
   - Wait for Button 1 press → Go to State 1.

2. **State 1**:
   - Check if potentiometer is turned to the left (analog value < 50).
   - If true → Go to State 2.
   - If false → Reset to State 0.

3. **State 2**:
   - Check if potentiometer is turned to the right (analog value > 950).
   - If true → Go to State 3.
   - If false → Reset to State 0.

4. **State 3**:
   - Wait for Button 2 press.
   - If Button 2 is pressed → Success (Green LED).
   - If Button 1 is pressed → Failure (Red LED).

---

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

---

Let me know if you'd like a visual schematic or further edits!