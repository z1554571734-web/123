#ifndef SKEET_NETWORKING_H
#define SKEET_NETWORKING_H

// Optimized networking functions for Skeet SDK
// Prevents tick cycle degradation while maintaining networking fix functionality

namespace SkeetNetworking {
    // Optimized networking functions
    void sv_maxusrcmdprocessticks2(int value);
    void sv_clockcarrection_msecs2(int value);
    void FixNetworking(bool enable);

    // Performance and utility functions
    void MaintainTickPerformance();
    bool IsNetworkingFixEnabled();
    int GetCachedMaxUserCmdProcessTicks();
    int GetCachedClockCorrectionMs();
    void ResetNetworkingSettings();
}

#endif // SKEET_NETWORKING_H