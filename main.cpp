#include <boost/filesystem.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/directory.hpp>

#include <iostream>

void WindowsLogger(){const boost::filesystem::path WinLogPath = "C:\\Users\\%USER%\\Saved Games\\Frontier Developments\\Elite Dangerous";}

void LinuxLogger(boost::filesystem::path GamePath){
  
}

int main(int argc, char* argv[1]){
  while(!boost::filesystem::exists(boost::filesystem::current_path("/logs"))){
    std::cout<<"The initial log folder doesn't exist, creating now...";
    boost::filesystem::create_directory(boost::filesystem::current_path(),"/logs");
  }
  boost::filesystem::path initLogFolder = boost::filesystem::current_path("/logs");
  
  boost::filesystem::path gameLoc;
  char host;
  
  std::cout<<"\n\nIs your game hosted on (W)indows or (P)roton (Linux) ? ";
  std::cin>>host;
  while(toupper(host) == 'W' || toupper(host) == 'P'){
    if(toupper(host) == 'W') {
      WindowsLogger();
    } else if(toupper(host) == 'P') {
      std::cout<<"\nWhere is the game located ? ";
      std::cin>>gameLoc;
      
      while(!boost::filesystem::exists(gameLoc)){
        std::cout<<"This is not a valid path, please enter a correct Linux Path : ";
        std::cin>>gameLoc;
      }
      LinuxLogger(gameLoc);
    } else {
      std::cout<<"\n\nThis is not a character proposed in the first dialogue, retry now (W/P) ? ";
      std::cin>>host;
    }
  }
}
