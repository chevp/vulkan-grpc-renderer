
# Vulkan gRPC Renderer

**C++ Vulkan Renderer for gRPC-Streaming**

## Overview

This project is a **Vulkan-based renderer** written in C++ designed for high-performance graphics rendering and **streaming over gRPC**. It allows for efficient transmission of rendered frames across networks using the gRPC framework, making it ideal for remote rendering applications, visualization, or cloud-based rendering services.

## Features

- **Real-time Vulkan Rendering**: Leverages Vulkan for optimized and low-level graphics rendering.
- **gRPC Integration**: Uses gRPC for streaming rendered frames to clients over the network.
- **Cross-Platform Support**: Designed to run on Linux and Windows (other platforms may require additional adjustments).
- **High Performance**: Vulkan API and gRPC provide a performant solution for remote graphics applications.

## Prerequisites

Before you begin, ensure you have the following installed:

- **C++ Compiler**: A modern C++ compiler that supports C++17 or newer.
- **Vulkan SDK**: Install the Vulkan SDK from [LunarG](https://vulkan.lunarg.com/).
- **gRPC and Protocol Buffers**: Install gRPC and Protocol Buffers libraries.
- **CMake**: Version 3.12 or higher.

## Installation

Clone the repository and its submodules (if any):

```bash
git clone https://github.com/chevp/vulkan-grpc-renderer.git
cd vulkan-grpc-renderer
```

### Build Instructions

1. **Install Dependencies** (if needed):
    - For **Ubuntu**:
      ```bash
      sudo apt update
      sudo apt install -y build-essential cmake libvulkan-dev
      ```

    - For **Windows**:
      - Install the Vulkan SDK from LunarG.
      - Use a compatible C++ compiler, such as Visual Studio 2019 or later.

2. **Build the Project**:
   - Configure and build with CMake:
     ```bash
     mkdir build
     cd build
     cmake ..
     make -j4    # Adjust `-j4` to the number of CPU cores for faster build
     ```

3. **Running the Renderer**:
   - Start the gRPC server to stream the rendered frames:
     ```bash
     ./vulkan_grpc_renderer
     ```

## Usage

### Basic Example

The server will render frames using Vulkan and stream them to connected clients via gRPC. To receive the streamed frames, connect your client application to the gRPC server's endpoint.

