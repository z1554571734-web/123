#ifndef SKEET_NETWORKING_H
#define SKEET_NETWORKING_H

// Refactored networking functions for Skeet SDK
// Implements automatic tick cycling system with removed holdaim and networking features

namespace SkeetNetworking {
    // Rewritten core functions with auto-cycling system
    void sv_maxusrcmdprocessticks2(int maxValue);
    void sv_clockcarrection_msecs2(int value);
    
    // Auto-cycling tick system
    void SetAutoCycleTicks(int maxValue);
    void EnableAutoCycle(bool enable);
    bool IsAutoCycleEnabled();
    int GetCurrentTick();
    int GetMaxTick();
    
    // Utility functions
    void UpdateTickCycle();
    void ResetTickCycle();
}

#endif // SKEET_NETWORKING_H