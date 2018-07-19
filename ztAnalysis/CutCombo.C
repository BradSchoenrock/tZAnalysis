#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "assert.h"

using namespace std;

/*NOTES ON HOW THIS WORKS

 the input file must be of the form 

ttbar2
NEventsbefore = 509592
weight = 25.0515
before all = 1.27661e+07
afterNLeptonReq = 4.86278e+06
afterJetReq = 763746
afterBTagReq = 346187
afterWTransverseMassReq = 286514
afterMETReq = 274540
afterTopMassReq = 66837.4
NEventsreweighted = 12250.2

ttbar5
NEventsbefore = 335246
weight = 0.0487612
before all = 16347
afterNLeptonReq = 4576.87
afterJetReq = 517.747
afterBTagReq = 295.395
afterWTransverseMassReq = 237.516
afterMETReq = 235.37
afterTopMassReq = 9.36215
NEventsreweighted = 0.0487612

...

there can not be a blank line at the begining of the file

each cut must have an equals sign before the number

after the equal sign must not contain any non-numeric characters (*:#& etc...)

each sample (ttbar, T-chan, W+jets, etc...) must have it's first two letters not equal to it's predicessor 

the first sample may not start with two spaces

the names of each cut are not importiant but they must be consistant from ht bin to ht bin

this way you can add cuts without having to rewrite this script



*/



int indexofeq(string name){
  bool foundch=false;
  bool done=false;
  char ch=' ';
  int place=0;
  while(!foundch && !done)
    {
      ch=name[place];
      if(ch=='=')
	foundch=true;
      if(ch=='\0')
	done=true;
      place++;
    }
  if(foundch)
    return place;
  else if(done)
    return -1;
  else //this should never be reached
    return -2;
}

void Print(string name, vector<string> counters, vector<double> values){
    
  ofstream myfile;
  myfile.open("yields.txt", ios::in|ios::app);
  myfile.seekp(0,ios_base::end);
	      
  myfile<<name<<'\n';

  while(values.size()>0)
    {
      //cout<<"in "<<counters.at(0)<<" = "<<values.at(0)<<'\n';
      myfile<<counters.at(0)<<" = "<<values.at(0)<<'\n';
      counters.erase(counters.begin());
      values.erase(values.begin());
    } 
  myfile<<'\n';
  myfile.close();

}

void CutCombo(string inFile){

  //cout<<"start"<<'\n';

  ifstream Input(inFile.c_str());

  vector<string> counters;
  vector<double> values;
  int linenum=0;
  string type="  ";
  bool samesample=false;

  while(!Input.eof())
    {
      linenum++;
      string line;
      getline(Input,line);
      //cout<<line<<'\n';
      if(linenum==1)
	{
  	  samesample=(type==line.substr(0,2));
	  //cout<<samesample<<'\n';
	  if(!samesample)
	    {
	      Print(type,counters,values);
	      counters.clear();
	      values.clear();
	    }
	  type=line.substr(0,2);
	}
      if(line!="\0")
	{
	  int index=indexofeq(line);
	  if(index>0)
	    {
	      stringstream ss(line.substr(index,15));
	      stringstream name(line.substr(0,index));
	      double tempnum;
	      string tempname;
	      ss>>tempnum;
	      name>>tempname;
	      //cout<<"tempname &"<<tempname<<'\n'<<"tempnum &"<<tempnum<<'\n';
	      if(!samesample)
		{
		  counters.push_back(tempname);
		  values.push_back(tempnum);
		}
	      else
		{
		  for(unsigned int i=0;i<counters.size();i++)
		    {
		      if(tempname==counters.at(i))
			{
			  values.at(i)=values.at(i)+tempnum;
			}
		    }
		}//end else
	    }//end if index>0
	}
      else
	{
	  linenum=0;
	}
    }//end while
  //cout<<"end"<<'\n';
}//end CutCombo
