# Simple Water Quality Monitoring System Using ESP32

This repository contains the Arduino code and assembly instructions for a water quality monitoring system that measures **pH**, **turbidity**, and **dissolved oxygen (DO)** levels in rivers or reservoirs. Data is transmitted in real-time to platforms like Blynk for analysis <button class="citation-flag" data-index="6"><button class="citation-flag" data-index="9">. Ideal for environmental monitoring and aquaculture.

---

## Table of Contents
1. [Overview](#overview)
2. [Components Used](#components-used)
3. [System Dimensions](#system-dimensions)
4. [Assembly Instructions](#assembly-instructions)
5. [Arduino Code Explanation](#arduino-code-explanation)
6. [Contributing](#contributing)
7. [License](#license)

---

## Overview
The system uses an ESP32 to collect data from pH, turbidity, and dissolved oxygen sensors <button class="citation-flag" data-index="2"><button class="citation-flag" data-index="7"><button class="citation-flag" data-index="8">. Data is sent to a cloud platform (e.g., Blynk) for real-time monitoring <button class="citation-flag" data-index="9">. This helps assess water quality parameters critical for aquatic ecosystems and pollution detection.

---

## Components Used
- **ESP32 Development Board**
- **Analog pH Meter v2** <button class="citation-flag" data-index="2">
- **Turbidity Sensor (SEN0189)** <button class="citation-flag" data-index="7">
- **Dissolved Oxygen Sensor (SEN0321)** <button class="citation-flag" data-index="8">
- **Solar Panel + Battery Pack**
- **Waterproof Enclosure**
- **Jumper Wires**

---

## System Dimensions
- **Height**: 20–25 cm (for sensor immersion)
- **Width**: 15–20 cm (control box)
- **Length**: 15–20 cm (sensor placement)

---

## Assembly Instructions
1. Connect the pH, turbidity, and DO sensors to the ESP32 <button class="citation-flag" data-index="2"><button class="citation-flag" data-index="7"><button class="citation-flag" data-index="8">.
2. Power the system using a solar panel and battery <button class="citation-flag" data-index="8">.
3. Deploy the sensors in water and secure the ESP32 in a waterproof enclosure.

---

## Arduino Code Explanation
The code reads sensor data (pH, turbidity, DO) and transmits it via Wi-Fi to Blynk <button class="citation-flag" data-index="6"><button class="citation-flag" data-index="9">. The pH and turbidity sensors use analog inputs, while the DO sensor uses I2C communication <button class="citation-flag" data-index="8">. Calibration values (`pH_OFFSET`, `TURBIDITY_OFFSET`) must be adjusted based on sensor specifications <button class="citation-flag" data-index="2">.

---

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

By following this guide, you can deploy a water quality monitoring system for real-time analysis. Happy tinkering! 🌊🔬
