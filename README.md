#  Digital Clock Project - S32K144

This is a digital clock project implemented on the NXP S32K144 microcontroller. 
The clock can display time and date using a 7-segment LED (via MAX7219 over LPSPI), 
receive configuration commands over UART, and support an alarm function with LED blinking.

---

#  Features

##  Basic Features
- Display time and date on 7-segment LED display
- Toggle between time and date display using **Button 1**
- Turn on/off display using **Button 2**
- Set time, date, and alarm via **UART (Hercules software)**

##  Extra Features
- Alarm with LED blinking
- UART-based notification on successful or failed setting
- Handles leap year and date logic
- Operates with LPIT timer

---

##  Hardware 

- **S32K144 EVB**
- **MAX7219 7-segment LED display** (connected via LPSPI)
- **5V Power supply**
- **UART connection** to PC (for Hercules tool)

---

##  Software 

- Keil C
- Hercules Terminal (for UART interaction)

---

##  Peripherals Used

- **GPIO**: Button input (PC12, PC13)
- **LPUART**: Communication with Hercules
- **LPSPI**: Interface with MAX7219 LED
- **LPIT**:
  - Channel 1: Time counting
  - Channel 2: LED blinking when alarm is active

---


### UART Commands (via Hercules):
 Command Type               Format                    Example        
--------------        ------------------         -----------------
  Set Time              `hh-mm-ss`t                 `05-10-20t`    
  Set Date              `dd-mm-yyyy`d               `05-10-2024d`  
  Set Alarm             `hh-mm-ss`a                 `06-15-00a`    

> All commands end with a trailing identifier: `t` for time, `d` for date, `a` for alarm.

---

##  User Manual

- **Button 1**: Toggle between time and date display
- **Button 2**: Turn on/off LED display
- **Hercules Terminal**: Send formatted commands and view success/failure notifications

-------------------------------------------------------------------------------------------
