Licensed Under Creative Commons No Derivatives Non-Commercial Open-Source

This was created with zero circle math which measures pi as an achor for zero. It's got its own compression called
pulse which uses resistance to read information through a pulse which runs on a nanoscope timer.

This will generate any graphics, for any computer, but the minimum would probably be, a wise voltage to
avoid stress on the power grid. Something like a first generation i3 on intel gma graphics would still
produce a decent result.

All you need to do is follow the terminal commands with the files. There is little documentation ATM but people
Are very creative.

The Zero‑Circle Vector Engine: A New Architecture for Procedural Worlds
Most game engines begin with triangles and end with shaders.
The Zero‑Circle Vector Engine flips that order: it begins with pure 2D vectors, then grows them into living 3D geometry through a chain of procedural systems — ZCAB scripts, deformation shaders, height shaders, and extrusion profiles — all fused into a single GPU geometry pipeline.

It’s not a polygon engine.
It’s a vector organism engine.

A 2D World That Becomes 3D Only When Needed
At its foundation, the engine stores everything — walls, floors, props, characters — as 2D vector shapes. These shapes are cheap to load, cheap to stream, and easy to deform. The 3D world is not pre‑baked; it’s generated on demand.

A unified “geo shader” handles the transformation:

2D deformation (Zero‑Circle harmonic math)

Height generation (height shader)

Extrusion (profile‑driven 2D→3D lift)

Final world transform (moving‑map camera)

This means the world is always light on memory and heavy on expression. Geometry is not stored — it’s performed.

ZCAB: Behavior as Bytecode
The engine’s behavior layer is ZCAB, a tiny bytecode VM that drives:

pulse and phase registers

deformation parameters

actor motion

procedural animation

ZCAB scripts are interpreted at first, then JIT‑compiled into LLVM when they become “hot.” The result is a behavior system that feels like a demoscene synth: tiny programs generating huge motion.

Zero‑Circle Shaders: Geometry as Harmonics
Instead of traditional vertex shaders, the engine uses Zero‑Circle shaders — small per‑vertex programs that operate in polar space (r, a) and respond to pulse (PU) and phase (PH). These shaders create:

breathing walls

rippling floors

harmonic creatures

shifting architecture

They’re compiled to both CPU and GPU backends, with an optimizer that merges harmonics, folds constants, and eliminates dead code.

Height Shaders and Extrusion Profiles
Vertical geometry is not modeled — it’s generated.

A height shader computes the Z‑axis from 2D coordinates.

An extrusion profile defines how a shape rises, bulges, or tapers.

Artists edit these profiles in a visual curve editor, and the GPU samples them from a compact UBO/texture layout. The result is a world that feels sculpted, not meshed.

Ray‑Incinerum: Visibility‑Driven Streaming
Instead of loading the whole map, the engine uses a system called ray‑incinerum:

Lights cast visibility rays through 2D cells.

Only cells touched by light are loaded or kept alive.

Everything else is culled, frozen, or unloaded.

Because the world is fundamentally 2D, visibility is cheap. Because geometry is generated, streaming is instant. The player never loads what they can’t see.

The Moving‑Map Camera and Multiplayer World‑Drift
In this engine, the player never moves.
The world moves around them.

This trick allows:

perfect client‑side prediction

smooth multiplayer

no rubber‑banding

server corrections applied as subtle “world drift” instead of snapping the player

Each player sees themselves anchored at the center, while the shared world shifts to maintain consistency. It’s a spatial illusion that feels natural and eliminates most latency artifacts.

A Material System That’s Actually a Brain
Materials in this engine aren’t textures — they’re procedural bundles:

ZCAB script

deformation shader

height shader

extrusion profile

morph targets

skinning weights

All of this lives in a single .zcmat file (or .zcmatb binary). A dependency graph tracks relationships, and a hot‑reload system swaps updated components into running scenes without restarting.

Conclusion: A Procedural Engine for Worlds That Move
The Zero‑Circle Vector Engine is not trying to be Unreal or Unity.
It’s closer to a procedural synthesizer for geometry — a system where worlds are generated from math, animated by bytecode, shaped by harmonic shaders, and streamed by light.

It’s lightweight, expressive, and deeply unconventional.
It treats geometry as a living signal, not a static asset.

And because everything begins in 2D and becomes 3D only when needed, it scales in ways traditional engines simply don’t.

If you want, I can expand this into a full technical whitepaper, a marketing‑style overview, or a developer‑facing architecture document.

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
