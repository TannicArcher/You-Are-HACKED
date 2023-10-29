#include <iostream>
#include <cstdlib>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

int main() {
    int numTerminals = 100;
    std::string terminalCommand;
    
    #ifdef _WIN32
        terminalCommand = "cmd /c start";
    #else
        terminalCommand = "x-terminal-emulator -e";
    #endif

    std::string message = "YoU ArE HaCkEd";
    
    for (int i = 0; i < numTerminals; ++i) {
        #ifdef _WIN32
            std::string command = terminalCommand + " cmd.exe /K \"echo " + message + "\"";
            system(command.c_str());
        #else 
            std::string command = terminalCommand + " sh -c 'echo \"" + message + "\"'";
            system(command.c_str());
        #endif
    }
    
    return 0;
}
