# RTOS-Based Multi-Tasking System: Sensor Fusion & Sound Detection

A high-performance embedded system built on the STM32F401 (Cortex-M4) using FreeRTOS for preemptive multi-tasking. The system integrates real-time accelerometer data processing via I2C.

Features
Preemptive Multi-tasking: Managed by FreeRTOS, ensuring deterministic execution of sensor reads and UI updates.

DMA-Powered Audio: 

Motion Intelligence: Real-time magnitude calculation from MPU6050 accelerometer data.


The project is structured into independent tasks to demonstrate Task Isolation and Priority-based Scheduling:

1. Sensor Task (High Priority)Queries MPU6050 via I2C.
2. Calculates vector magnitude: $mag = \sqrt{ax^2 + ay^2 + az^2}$.
3. Applies a Low-Pass Filter (LPF) to smooth data.
4. Determines motion states: STILL, LIGHT_SHAKE, or VIOLENT_SHAKE.
