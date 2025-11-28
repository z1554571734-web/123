# SkeetSDK

A refactored SDK with automatic tick cycling system and removed deprecated features.

## Features

### ✅ New Auto-Cycling Tick System
- Smooth automatic cycling through tick values (1 to N)
- Configurable maximum tick value (1-64)
- Predictable cycling patterns for stable gameplay
- Performance-optimized implementation

### ✅ Rewritten Core Functions
- `sv_maxusrcmdprocessticks2` - Integrated with auto-cycling
- `sv_clockcarrection_msecs2` - Performance optimized rewrite

### ❌ Removed Deprecated Features
- `sv_maxusrcmdprocessticks_holdaim` - Completely removed
- "Fix networking" feature - Removed due to performance issues

## Quick Start

```cpp
#include "Networking.h"

// Set up auto-cycling with max value of 9
SkeetNetworking::SetAutoCycleTicks(9);
SkeetNetworking::EnableAutoCycle(true);

// In your game loop:
while (running) {
    SkeetNetworking::UpdateTickCycle();
    // Your game logic here
}
```

## Documentation

- [Auto-Cycling System Documentation](AUTO_CYCLING_SYSTEM.md) - Complete feature overview and usage guide
- [Networking Examples](SkeetSDK/NetworkingExample.cpp) - Comprehensive code examples

## QA & HELP in discord
[discord](https://discord.gg/KYA6NVkAHv)
