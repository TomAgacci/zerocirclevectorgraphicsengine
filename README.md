Licensed Under Creative Commonse No Derivatives Non-Commercial Open-Source

ZeroCircleEngine/
├── core/
│   ├── zcve_core.h
│   ├── zcve_core.cpp
│   ├── zcve_scene.h
│   ├── zcve_scene.cpp
│   ├── zcve_camera.h
│   ├── zcve_camera.cpp
│   ├── zcve_profiler.h
│   ├── zcve_profiler.cpp
│   ├── zcve_build.h
│   ├── zcve_build.cpp
│   └── main.cpp
│
├── vm/
│   ├── zcab_opcodes.h
│   ├── zcab_program.h
│   ├── zcab_program.cpp
│   ├── zcve_vm.h
│   ├── zcve_vm.cpp
│   ├── zcve_jit.h
│   ├── zcve_jit.cpp
│   └── zcve_vm_debugger.cpp
│
├── shaders/
│   ├── zero_circle_geo.glsl
│   ├── zero_circle_vert.glsl
│   ├── zero_circle_frag.glsl
│   ├── builtin_deform.zcsh
│   ├── builtin_height.zchs
│   ├── builtin_extrude.zcex
│   └── shader_optimizer.cpp
│
├── materials/
│   ├── material_loader.cpp
│   ├── material_graph.cpp
│   ├── sentinel_core.zcmat
│   ├── sentinel_wall.zcex
│   ├── sentinel_rise.zchs
│   ├── breathing_flower.zcsh
│   └── zcmat_compiler.cpp
│
├── renderer/
│   ├── zcve_renderer.h
│   ├── zcve_renderer.cpp
│   ├── zcve_gpu_buffers.cpp
│   ├── zcve_visibility_buffer.cpp
│   ├── zcve_rayincinerum.cpp
│   └── zcve_draw.cpp
│
├── network/
│   ├── net_server.cpp
│   ├── net_client.cpp
│   ├── net_protocol.h
│   ├── net_sync.cpp
│   └── net_world_drift.cpp
│
├── tools/
│   ├── editor_extrusion.cpp
│   ├── editor_material.cpp
│   ├── editor_shader.cpp
│   ├── editor_zcab.cpp
│   └── editor_preview.cpp
│
├── assets/
│   ├── shapes/
│   │   ├── sentinel_shape_2d.vec
│   │   └── world_cells.vec
│   ├── materials/
│   ├── shaders/
│   ├── profiles/
│   └── scenes/
│
├── config/
│   ├── engine_config.json
│   ├── build_manifest.json
│   └── profile_layout.ubo
│
├── cache/
│   ├── jit/
│   ├── shaders/
│   └── visibility/
│
└── compressed/
    ├── zero_circle_engine.py        ← the one‑file pulse engine
    ├── pulse_terminal_commands.txt  ← all one‑liners
    └── pulse_definition.txt         ← the mathematical seed
