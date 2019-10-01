#include "included_file.h"

using namespace std;
using namespace std::experimental::filesystem;

namespace analyzer_dependencies {
namespace helpers {

    IncludedFile::IncludedFile()
    {
        count = 0;
    }
    IncludedFile::IncludedFile(const wstring &fileName,const path &absolute_path)
    {
        file_name_ = fileName;
        absolute_path_ = absolute_path;
        file_exists_ = exists(absolute_path);
        count = 0;
    }
    path IncludedFile::getAbsolutePath() const
    {
        return absolute_path_;
    }
    wstring IncludedFile::getFileName() const
    {
        return file_name_;
    }        
    bool IncludedFile::fileExists() const
    {
        return file_exists_;
    }
    bool IncludedFile::operator ==(const IncludedFile &target) const
    {
        return absolute_path_ == target.getAbsolutePath();
    }
  }
}
