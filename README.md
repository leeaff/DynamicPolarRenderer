# POV Spin Project

This is a PlatformIO project for a spinning LED display (Persistence Of View effect). We are implementing old technology with a new spin

## Project structure

- `src/` → main code
- `include/` → headers
- `lib/` → external libraries
- `test/` → test code

## How to build and upload

1. Open PlatformIO in VS Code
2. Connect your board
3. Run **Upload** or `pio run --target upload`

# Dynamic Polar Renderer

Dynamic Polar Renderer is a PlatformIO-based ESP32 project for rendering images and patterns using **polar coordinates** on a spinning LED Persistence of Vision (POV) display. The renderer converts angular position and radius into time-synchronized LED output, enabling smooth, dynamic visuals as the display rotates.

## Features

* Polar-coordinate rendering (angle × radius)
* Designed for ESP32 (Arduino framework)
* Real-time pattern generation
* Efficient memory usage suitable for POV applications

## Hardware

* **MCU:** ESP32 (tested with ESP32 Pico Kit / `pico32`)
* **Display:** Spinning LED strip 
* **Interface:** USB for programming, motor encoder for rotation timing

## Project Structure

```
.
├── platformio.ini     # PlatformIO configuration
├── src/               # Application source (main.cpp)
├── include/           # Project headers
├── lib/               # External libraries (if any)
├── test/              # Tests
└── .gitignore         # Ignored build/editor files
```

## Build & Upload

1. Install **VS Code** and the **PlatformIO IDE** extension.
2. Open this folder (the one containing `platformio.ini`) in VS Code.
3. Connect the ESP32 via USB.
4. Click **Build** or **Upload** in the PlatformIO toolbar.

## Configuration

The default environment is defined in `platformio.ini`:

```ini
[env:pico32]
platform = espressif32
board = pico32
framework = arduino
```

Adjust the board, port, or upload settings as needed.

## Roadmap

* Add configurable rendering primitives
* Sensor-based rotation synchronization
* Animation presets and patterns
* Performance optimizations


