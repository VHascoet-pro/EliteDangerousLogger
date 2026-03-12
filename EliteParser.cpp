#include "extras.h"
#include <boost/filesystem/path.hpp>

boost::filesystem::path CustomParsers::EliteParser::JournalPathFinder(boost::filesystem::path GamePath){
  boost::filesystem::path CompleteJournalPath;
  
  CompleteJournalPath = boost::filesystem::detail::dot_dot_path();
  CompleteJournalPath = boost::filesystem::detail::dot_dot_path();

  CompleteJournalPath = CompleteJournalPath.append("/compatdata/359320/pfx/drive_c/users/steamuser/Saved Games/Frontier Developments/Elite Dangerous");
  
  return CompleteJournalPath;
}
