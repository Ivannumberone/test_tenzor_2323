#ifndef ANALYZER_H
#define ANALYZER_H

#include <algorithm>
#include <experimental/filesystem>
#include <list>
#include <set>
#include <regex>
#include <deque>

#include "helpers/file_parser.h"

using namespace std;
using namespace experimental::filesystem;
using namespace analyzer_dependencies::helpers;

namespace analyzer_dependencies {

  class Analyzer
  {
     public:
       Analyzer();
       void Analyze(path start_folder,vector<path> lib_folders);
       void PrintCount();
       void PrintTree();
       void PrintLoop();
       vector<shared_ptr<IncludedFile>> GetAllFiles();
       vector<shared_ptr<IncludedFile>> GetLoopedFiles();
     private:       
       void AnalyzeFiles(vector<shared_ptr<IncludedFile>> &targets);
       path start_folder_;
       wregex rgx_cpp_file_ = wregex(LR"(\.h$|\.cpp$)",regex::icase);
       vector<shared_ptr<IncludedFile>> roots_files_ = vector<shared_ptr<IncludedFile>>();
       Parser parser_;
       // Нужно было сделать контейнер set, но я не уверен в корректной реализации path.compare
       vector<shared_ptr<IncludedFile>> cache_branch_files_ = vector<shared_ptr<IncludedFile>>();
       vector<shared_ptr<IncludedFile>> cache_all_files_ = vector<shared_ptr<IncludedFile>>();
       vector<shared_ptr<IncludedFile>> cache_looped_files_ = vector<shared_ptr<IncludedFile>>();
       void PrintBranch(const shared_ptr<IncludedFile> included_file,unsigned int count);
       void CheckLoop(shared_ptr<IncludedFile> targets);

  };
}


#endif // ANALYZER_H
