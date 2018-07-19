#ifndef TEXTABLE_H
#define TEXTABLE_H
     
#include <iostream>
#include <string>
#include <sstream>

#include "TString.h"

class TexTable{
 public:
  TexTable(const std::string placement);
       
  static std::string GetHeader(const std::string placement, const std::string tabrules);

  static std::string GetTrailer(TString caption, TString label);

  static std::string GetStartDoc();  

  static std::string GetEndDoc();  

  void AddHeader(const std::string placement, const std::string tabrules);
  
  void AddTrailer(const TString caption, const TString label);

  void AddRow(const std::string line,const std::string spacing = "");
       
  void hline(void){m_tableText << "\\hline\n";};
       
  std::string GetTableText();
       
 private:
  TexTable(){};
       
  std::stringstream m_tableText;
       
};
     
     
#endif
     

