#include "TexTable.h"


TexTable::TexTable(const std::string placement){
    m_tableText << GetStartDoc();
}

void TexTable::AddRow(const std::string line,const std::string spacing){
    m_tableText << line << " \\\\ ";
    if(spacing.size() > 0)
        m_tableText << "[" << spacing << "] ";
    m_tableText << "\n";
}

void TexTable::AddHeader(const std::string placement, const std::string tabrules){
  m_tableText << GetHeader(placement,tabrules);
}

void TexTable::AddTrailer(const TString caption, const TString label){
  m_tableText << GetTrailer(caption,label);
}

std::string TexTable::GetTableText()
{
    std::string output;
    output = m_tableText.str();
    output += GetEndDoc();
    
    return output;
}

std::string TexTable::GetHeader(const std::string placement,
                                const std::string tabrules)
{
    std::stringstream output;

    output <<" \n"; 
    output << "\\begin{table} [" << placement << "]\n";
    output << "\\setlength{\\tabcolsep}{2pt}\n";
    output << "\\footnotesize\n";
    output << "\\centering\n";
    //output << "\\noindent\\makebox[\\textwidth]{\n";
    output << "\\begin{tabular}{" << tabrules << "}\n";
    
    return output.str();
}


std::string TexTable::GetStartDoc()
{
    std::stringstream output;

    output <<"\\documentclass[10pt,twoside,a4paper]{article}\n";
    output <<"\\usepackage{color}\n";
    output <<"\\usepackage[utf8]{inputenc}\n";
    output <<"\\begin{document}\n";
    output << "\n";
    
    return output.str();
}


std::string TexTable::GetEndDoc()
{
    std::stringstream output;
    output << "\n";
    output <<"\\end{document}\n";


    return output.str();
}

std::string TexTable::GetTrailer(TString caption,
                                 TString label)
{
    std::stringstream output;
    
    output << "\\end{tabular}\n";
    output << "\\caption{" << caption << "}\n";
    output << "\\label{" << label << "}\n";
    output << "\\end{table}\n";
    output << "\n";
    
    return output.str();
}
