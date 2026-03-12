#ifndef EXTRAS_H
#define EXTRAS_H
#include <boost/filesystem/path.hpp>

namespace CustomParsers {
  class EliteParser{
    public:
      boost::filesystem::path JournalPathFinder(boost::filesystem::path GamePath);
  };
}

#endif
