# Alcohol Detection and Engine Locking System with GSM Alert

## Overview

This project simulates an embedded system for detecting alcohol levels and controlling engine access using an 8051 microcontroller. When the alcohol level exceeds a defined threshold, the system locks the engine, activates a buzzer, and sends an SOS SMS alert using a GSM module. An additional security feature alerts if forced ignition is attempted under intoxication.

## Features

- Alcohol sensor-based intoxication detection
- Engine locking mechanism (simulated via GPIO)
- Buzzer alert for driver feedback
- SOS SMS notification using GSM (SIM800L/SIM900)
- Ignition attempt detection under intoxication
- Retry delay before rechecking sensor status

## Files

- `main.c` – Embedded C source code for the system
- `README.md` – Project documentation
- `simulation_diagram.png` *(optional)* – Schematic for simulation (if available)
- `output.txt` *(optional)* – Sample output or simulation log

## Components Used

- 8051 Microcontroller (AT89C51/AT89S52)
- GSM Module (SIM800L/SIM900)
- Alcohol Sensor (simulated logic or MQ-3)
- Buzzer and relay simulation
- UART communication for GSM AT commands

## Tools & Tech

- **Language:** Embedded C
- **IDE:** Keil µVision
- **Simulation (optional):** Proteus
- **Microcontroller:** 8051 family

## How It Works

1. The alcohol sensor continuously monitors the driver's breath.
2. If the level crosses a defined threshold, the engine is locked and buzzer is activated.
3. An SOS message is sent to a predefined number using the GSM module.
4. If ignition is attempted while intoxicated, another critical alert SMS is sent.
5. The system rechecks after a short delay loop.

## Safety Note

This is a prototype-level simulation and should be rigorously tested before being deployed in any real vehicle. Additional safety protocols, hardware filters, and secure GSM interfacing are recommended for deployment.

