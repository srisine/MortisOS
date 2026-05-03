# 💀 MortisOS

**MortisOS** is a minimalist, hobbyist operating system built from scratch in **C**. It is designed to explore the fundamentals of low-level hardware interaction, leveraging the **Limine** bootloader to transition from boot to kernel execution.

---

## 🚀 Features

*   **Bootloader:** Uses the [Limine](https://github.com/limine-bootloader/limine) bootloader for modern x86_64 system initialization.
*   **Interrupt Handling:** Custom implementation of GDT, IDT, and ISRs to manage hardware events.
*   **Keyboard Driver:** A functional PS/2 keyboard driver with scan-code translation.
*   **Time & Tick Management:**
    *   **RTC (Real Time Clock):** Reads from CMOS to provide real-world time.
    *   **PIT (Programmable Interval Timer):** Handles system clock ticks and precise delays.
*   **PC Speaker:** A basic driver that utilizes the PIT to generate audible beeps and frequencies.
*   **CLI:** A basic command-line interface for executing kernel-level commands.

---

## 🏗️ System Overview

MortisOS focuses on direct hardware communication through I/O ports. By utilizing Limine, the kernel bypasses the complexities of legacy BIOS booting, allowing the code to immediately begin managing the CPU and peripherals.

### 🖼️ Photos
<img width="435" height="192" alt="screenshot_1777798112" src="https://github.com/user-attachments/assets/5cf1e344-5e0b-4c99-92ea-ad6ab4cd2d55" />

---

## Command List

* **PRINT <args>** - Prints the specified text to the terminal (e.g., `PRINT HELLO WORLD`).
* **DATE** - Prints the current system date in the terminal.
* **SYSTIKS** - Prints the total number of system clock ticks elapsed since boot.
* **CLR** - Clears all text currently visible in the terminal.
* **BEEP <freq>** - Beeps for 1s at the specified frequency (e.g., `BEEP 440` for 440Hz).

---

## 🛠️ Building & Running

### Prerequisites
You will need an `x86_64-elf` cross-compiler toolchain, `make`, and `xorriso`.

1.  **Clone the Repo:**
    ```bash
    git clone [https://github.com/yourusername/MortisOS.git](https://github.com/yourusername/MortisOS.git)
    cd MortisOS
    ```

2.  **Compile to ISO:**
    ```bash
    make iso
    ```

3. **Run in QEMU:**
   ```bash
   make run
   ``` 
