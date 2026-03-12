#include "extras.h"
#include <boost/filesystem/path.hpp>
#include <cctype>

boost::filesystem::path CustomParsers::EliteParser::JournalPathFinder(boost::filesystem::path GamePath, char OperatingSystem_selected){
  boost::filesystem::path CompleteJournalPath = GamePath;

  if(std::toupper(OperatingSystem_selected) == 'W'){
    CompleteJournalPath = "C:\\Users\\$USER\\Saved Games\\Frontier Developments\\Elite Dangerous";
  } else {  
    CompleteJournalPath = boost::filesystem::detail::dot_dot_path();
    CompleteJournalPath = boost::filesystem::detail::dot_dot_path();
    
    CompleteJournalPath = CompleteJournalPath.append("/compatdata/359320/pfx/drive_c/users/steamuser/Saved Games/Frontier Developments/Elite Dangerous");
  }
  
  return CompleteJournalPath;
}
