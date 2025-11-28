// Enhanced example of using SkeetSDK with optimized networking functions
// Unhide hidden checkboxes in Misc->Settings and demonstrate networking optimization
#include <Windows.h>
#include <stdio.h>
#include "Skeet.h"
#include "Networking.h"

DWORD WINAPI MainThread(LPVOID lpParam)
{
    Menu* MenuPTR = (Menu*)0x434799AC;
    while (!MenuPTR->Pos.x) Sleep(100);
    
    // Unhide hidden checkboxes in Misc->Settings (original functionality)
    for (int i = 12; i < 20; i++)
        MenuPTR->Tabs->Misc->Childs[2]->Elements[i]->header.Flags.Visible = 1;

    // Demonstrate optimized networking functionality
    printf("SkeetSDK Networking Optimization Example\n");
    printf("==========================================\n");

    // Enable optimized networking fix without tick degradation
    printf("Enabling optimized networking fix...\n");
    SkeetNetworking::FixNetworking(true);
    
    // Show current settings
    printf("Max User Cmd Process Ticks: %d\n", SkeetNetworking::GetCachedMaxUserCmdProcessTicks());
    printf("Clock Correction MS: %d\n", SkeetNetworking::GetCachedClockCorrectionMs());
    printf("Networking Fix Enabled: %s\n", SkeetNetworking::IsNetworkingFixEnabled() ? "Yes" : "No");

    // Simulate tick performance maintenance
    printf("Maintaining tick performance...\n");
    for (int i = 0; i < 10; i++) {
        SkeetNetworking::MaintainTickPerformance();
        printf("Tick %d: Performance maintained\n", i + 1);
        Sleep(50); // Simulate game loop timing
    }

    // Test individual function optimization
    printf("\nTesting individual function optimization...\n");
    SkeetNetworking::sv_maxusrcmdprocessticks2(12);
    printf("Set sv_maxusrcmdprocessticks2 to: %d\n", SkeetNetworking::GetCachedMaxUserCmdProcessTicks());
    
    SkeetNetworking::sv_clockcarrection_msecs2(20);
    printf("Set sv_clockcarrection_msecs2 to: %d\n", SkeetNetworking::GetCachedClockCorrectionMs());

    // Demonstrate performance benefits
    printf("\nPerformance optimization benefits:\n");
    printf("- Reduced tick cycle degradation\n");
    printf("- Smooth tick/ms cycles with networking fix enabled\n");
    printf("- Cached values prevent repeated processing\n");
    printf("- Minimum interval enforcement prevents overload\n");

    // Optional: Reset to defaults after testing
    printf("\nResetting networking settings to defaults...\n");
    SkeetNetworking::ResetNetworkingSettings();
    printf("Final state - Networking Fix Enabled: %s\n", SkeetNetworking::IsNetworkingFixEnabled() ? "Yes" : "No");

    return 0;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
    if (fdwReason == DLL_PROCESS_ATTACH)
        CreateThread(nullptr, 0, MainThread, nullptr, 0, nullptr);

    return TRUE;
}