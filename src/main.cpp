#include <windows.h>
#include <iostream>
#include <thread>
#include "core/injection.h"
#include "core/memory.h"
#include "features/precision.h"

int main() {
    SetConsoleTitleA("Fortnite Advantage Launcher");
    
    std::cout << "Fortnite Advantage Tool v" << VERSION << std::endl;
    std::cout << "Checking game status..." << std::endl;
    
    if (!IsGameRunning("FortniteClient-Win64-Shipping.exe")) {
        std::cout << "Please launch Fortnite first!" << std::endl;
        system("pause");
        return 1;
    }
    
    std::cout << "Initializing features..." << std::endl;
    InitializeCore();
    
    std::cout << "Press INSERT in-game to open menu" << std::endl;
    
    while (true) {
        UpdateFeatures();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    
    return 0;
}