# Real-Time Audio Processing System (DSP + DMA)

A high-performance acoustic trigger system developed for the STM32F411 (Blackpill) using the INMP441 I2S digital microphone. This project demonstrates real-time signal analysis, utilizing DMA circular buffering to detect and differentiate between single and double clap patterns for smart lighting control.

Key Features
Zero-Copy Audio Capture: Uses I2S with Circular DMA to stream audio data without CPU intervention.

Double-Buffering (Ping-Pong): Implements HAL_I2S_RxHalfCpltCallback and HAL_I2S_RxCpltCallback to process one data block while the next is being captured.

Time-Domain DSP: Implemented peak detection and signal rectification to extract amplitude envelopes from raw 24-bit PCM data.

Temporal Pattern Recognition: A state-machine-based logic to distinguish between a single "OFF" command and a double "ON" command within a 600ms window.

Tech Stack
Microcontroller: STM32F411CEU6 (ARM Cortex-M4)

Sensor: INMP441 (Omnidirectional Digital I2S Microphone)

IDE: STM32CubeIDE

Framework: STM32Cube HAL (Hardware Abstraction Layer)
