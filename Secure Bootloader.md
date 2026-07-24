Secure Bootloader for STM32F411

A secure bootloader implementation for the **STM32F411** microcontroller developed using **IAR Embedded Workbench for ARM (EWARM)**. This project focuses on providing a secure firmware update mechanism with image verification and controlled application execution.

Features

- Secure boot process
- Firmware image validation
- Application integrity verification
- Vector table relocation
- Flash memory management
- Bootloader and application separation
- Safe jump to user application
- Error handling and recovery
- Modular project architecture
- Developed using IAR EWARM

Hardware

- STM32F411 (ARM Cortex-M4)
- ST-Link Debugger
- STM32F411 Discovery / Black Pill (or compatible board)

Development Environment

- IAR Embedded Workbench for ARM (EWARM)
- STM32 Standard Peripheral Library / CMSIS
- C Language

Project Structure

```
SecureBootloader/
│
├── Bootloader/
│   ├── Core
│   ├── Drivers
│   ├── Startup
│   ├── Flash
│   ├── Crypto
│   ├── Boot
│   └── Utilities
│
├── Application/
│   ├── Core
│   ├── Drivers
│   └── Startup
│
├── Docs/
├── Images/
└── README.md
```

## Boot Flow

```
Power On / Reset
        │
        ▼
 Bootloader Starts
        │
        ▼
 Initialize Hardware
        │
        ▼
 Validate Application Image
        │
   ┌────┴────┐
   │         │
 Valid    Invalid
   │         │
   ▼         ▼
Jump to   Stay in
Application Bootloader
```

Security Objectives

- Prevent execution of invalid firmware
- Verify application integrity before execution
- Ensure controlled boot sequence
- Protect firmware update process
- Separate bootloader and application memory

Memory Layout (Example)

| Region | Address |
|---------|----------|
| Bootloader | 0x08000000 |
| Application | 0x08010000 |
| SRAM | 0x20000000 |

Memory addresses can be modified according to project requirements.

Technologies Used

- Embedded C
- ARM Cortex-M4
- CMSIS
- Flash Memory Programming
- Interrupt Vector Relocation
- Linker Configuration
- Secure Boot Concepts

Future Improvements

- SHA-256 image verification
- Digital signature verification
- AES encrypted firmware
- UART firmware update
- CAN firmware update
- USB DFU support
- Rollback protection
- Anti-tamper mechanisms
- Secure key storage
- Dual-bank firmware update support

Build

1. Open the project in IAR EWARM.
2. Select the appropriate build configuration.
3. Compile the project.
4. Program the bootloader using ST-Link.
5. Flash the user application to the application region.
