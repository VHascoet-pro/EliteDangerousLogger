#include <boost/filesystem.hpp>
#include <boost/filesystem/directory.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>

#include <iostream>
using std::cout, std::cin;
using namespace boost::filesystem;

#include "extras.h"

path InitLog_Archive_Directory;

/**
 Main function for copying the log files
 @param GamePath is the game path for both Windows or Linux (used only for
 Linux)
 @param host to specify the OS used for the parser
 @param LocalLogPath is the path of the Log path (./logs relatively to the main
 program)
*/
void Logger(path GamePath, char host, path LocalLogPath) {
        CustomParsers::EliteParser eP;
        const path GameLogPath = eP.JournalPathFinder(GamePath, host);
        for (directory_iterator it(GameLogPath); it != directory_iterator(); ++it) {}
}

int main(int argc, char *argv[1]) {
        path gameLoc;
        char host;

        cout << "Is your game hosted on (W)indows or (P)roton (Linux) ? ";
        cin >> host;

        while (toupper(host) != 'W' && toupper(host) != 'P') {
                cout << "\n\nThis is not a character proposed in the first dialogue, retry now (W/P) ? ";
                cin >> host;
        }
/**
@param InitLog_Archive_Directory The path where to store the logs
@function Logger The function that will to the operations on the journalfiles
(log files)
*/
        if (toupper(host) == 'W') {
                InitLog_Archive_Directory = current_path().append("\\EliteLogs");
                if (!exists(InitLog_Archive_Directory)) {
                        cout << "The initial log archive folder does not exist, creating now...";
                        create_directory(InitLog_Archive_Directory);
                }
                Logger(gameLoc, host, InitLog_Archive_Directory);
        } else if (toupper(host) == 'P') {
                InitLog_Archive_Directory = current_path().append("/EliteLogs");

                if (!exists(InitLog_Archive_Directory)) {
                        cout << "The initial log Archive folder does not exist, creating now...";
                        create_directory(InitLog_Archive_Directory);
                }

                cout << "\nWhere is the game located ? ";
                cin >> gameLoc;

                while (!exists(gameLoc)) {
                        cout << "This is not a valid path, please enter a correct Linux Path : ";
                        cin >> gameLoc;
                }

                Logger(gameLoc, host, InitLog_Archive_Directory);
        }
}
