# ByteX-Engine
<img src="ByteX_Logo.png" alt="logo" width="400"/>


ByteX is a general purpose, lightweight, data driven, multiplatform game engine writen in C++

# Information

ByteX will initially support 3d rendering through OpenGL and Vulkan APIs.
The engine will be initially developed in OpenGL and later ported to Vulkan and DirectX

__Why OpenGL support?__\
Vulkan is the future of graphics, but right now it doesent support some older hardware. Beacuse of this the engine will
support OpenGL.

__*Graphic APIs*__
- OpenGL: 4.6 (Supported at early development state)
- Vulkan: 1.2 (Supported at early development state)
- DirectX: 11 (Supported at later development state)
- DirectX: 12 (Planned, not confirmed)
- Metal: (Support through moltenVK)


# Features
```
- Rendering 
      - Model Loading
      - Textures
      - Lightnig
          - Point Light
          - Directional Light
          - Spot Light
          - Ambient Light
      - Shadows
      - Normal Maps
      - Parallax Oculsion Mapping
      - PBR
      - Transparency
      - Camera
    
- Raytracing 
      - Raytraced Lightning
      - Raytraced Shadows
- Antialising (MSAA)
- High Dynamic Range (HDR)
- Bloom
- User Input
- Audio (OpenCL)
      - 3D audio
- Networking
      - Replication
      - RPCs
      - Message
- Scripting
      - Lua
      - C++
- Editor
      - Graphical Editor
      - Level Creator
      - Model viewer
- Exporting
      - Platforms
            - Windows
                  - Single DLL
                  - Modular DLLs
            - Linux
                  - Single so
                  - Mosular so
- Multithreading
```

 
  
