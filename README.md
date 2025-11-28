# SkeetSDK

## QA & HELP in discord
[discord](https://discord.gg/KYA6NVkAHv)

## Networking Optimization

This version includes optimized networking functions that prevent tick cycle degradation:

- **`sv_maxusrcmdprocessticks2`** - Optimized user command processing
- **`sv_clockcarrection_msecs2`** - Optimized clock correction timing  
- **`FixNetworking`** - Networking fix without performance impact

See [NETWORKING_OPTIMIZATION.md](NETWORKING_OPTIMIZATION.md) for detailed documentation.

## Features

- Menu system with UI structures
- Optimized networking functions
- Performance monitoring and maintenance
- Example implementations

## Usage

```cpp
#include "Networking.h"

// Enable optimized networking fix
SkeetNetworking::FixNetworking(true);

// Maintain performance during game loop
while (running) {
    SkeetNetworking::MaintainTickPerformance();
    // Your game logic here
}
```
