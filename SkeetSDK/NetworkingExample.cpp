// Example of using SkeetSDK with the refactored auto-cycling tick system
// Demonstrates the new automatic tick cycling functionality
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

    // Demonstrate the new auto-cycling tick system
    printf("SkeetSDK Auto-Cycling Tick System Example\n");
    printf("==========================================\n");

    // Example 1: Set up auto-cycling with maximum value of 9
    printf("Setting up auto-cycling with max value 9...\n");
    SkeetNetworking::SetAutoCycleTicks(9);
    SkeetNetworking::EnableAutoCycle(true);
    
    printf("Auto-cycle enabled: %s\n", SkeetNetworking::IsAutoCycleEnabled() ? "Yes" : "No");
    printf("Max tick value: %d\n", SkeetNetworking::GetMaxTick());
    printf("Current tick: %d\n", SkeetNetworking::GetCurrentTick());

    // Simulate the cycling system
    printf("\nSimulating tick cycling (9 -> 1,2,3,4,5,6,7,8,9 -> repeat):\n");
    for (int i = 0; i < 15; i++) {
        SkeetNetworking::UpdateTickCycle();
        printf("Cycle %d: Current tick = %d\n", i + 1, SkeetNetworking::GetCurrentTick());
        Sleep(110); // Slightly longer than cycle interval to trigger updates
    }

    // Example 2: Change to different maximum value (16)
    printf("\nChanging max tick value to 16...\n");
    SkeetNetworking::SetAutoCycleTicks(16);
    printf("New max tick value: %d\n", SkeetNetworking::GetMaxTick());
    printf("Current tick after change: %d\n", SkeetNetworking::GetCurrentTick());

    // Simulate cycling with 16 ticks
    printf("Simulating tick cycling (16 values):\n");
    for (int i = 0; i < 20; i++) {
        SkeetNetworking::UpdateTickCycle();
        printf("Cycle %d: Current tick = %d\n", i + 1, SkeetNetworking::GetCurrentTick());
        Sleep(110);
    }

    // Example 3: Demonstrate manual control
    printf("\nDemonstrating manual control...\n");
    SkeetNetworking::EnableAutoCycle(false);
    printf("Auto-cycle disabled\n");
    
    // Manual tick setting
    SkeetNetworking::sv_maxusrcmdprocessticks2(12);
    printf("Manually set sv_maxusrcmdprocessticks2 to 12\n");
    
    SkeetNetworking::sv_clockcarrection_msecs2(25);
    printf("Manually set sv_clockcarrection_msecs2 to 25\n");

    // Re-enable auto-cycling
    printf("\nRe-enabling auto-cycling...\n");
    SkeetNetworking::EnableAutoCycle(true);
    printf("Current tick: %d\n", SkeetNetworking::GetCurrentTick());

    // Example 4: Reset functionality
    printf("\nTesting reset functionality...\n");
    printf("Before reset - Current tick: %d\n", SkeetNetworking::GetCurrentTick());
    SkeetNetworking::ResetTickCycle();
    printf("After reset - Current tick: %d\n", SkeetNetworking::GetCurrentTick());

    // Final state demonstration
    printf("\nFinal System State:\n");
    printf("- Auto-cycle enabled: %s\n", SkeetNetworking::IsAutoCycleEnabled() ? "Yes" : "No");
    printf("- Max tick value: %d\n", SkeetNetworking::GetMaxTick());
    printf("- Current tick: %d\n", SkeetNetworking::GetCurrentTick());

    printf("\nFeatures removed in this refactor:\n");
    printf("- sv_maxusrcmdprocessticks_holdaim functionality\n");
    printf("- Fix networking feature\n");
    printf("\nNew features added:\n");
    printf("- Automatic tick cycling (1 to N loop)\n");
    printf("- Smooth and continuous cycling during gameplay\n");
    printf("- Configurable maximum tick value\n");
    printf("- Performance-optimized implementation\n");

    return 0;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
    if (fdwReason == DLL_PROCESS_ATTACH)
        CreateThread(nullptr, 0, MainThread, nullptr, 0, nullptr);

    return TRUE;
}