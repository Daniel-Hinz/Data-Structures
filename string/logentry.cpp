//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class implementation for a log entry.
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp" 
#include "logentry.hpp"

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
LogEntry::LogEntry(String s) {
   
    std::vector<String> vec = s.split(' ');
    if (vec.size() == 10) {
      host = vec[0];
              
      std::vector<String> date_time = vec[3].split(':');       
      std::vector<String> date_string = date_time[0].split('/');       
      String sday = date_string[0].substr(1, date_string[0].getLength());
      date.setday(sday);
        
      String stringmonth = date_string[1];
      date.setmonth(stringmonth);
        
      int intyear = date_string[2].to_i();
      date.setyear(intyear);
        
      request = vec[5] + vec[6] + vec[7];
      status = vec[8];
        
      number_of_bytes = vec[9].to_i();
    } else {
      host = "";
      date.setday("");
      date.setmonth("");
      date.setyear(0);
      time.sethour(0);
      time.setminute(0);
      time.setsecond(0);
      request = "";
      status = "";
      number_of_bytes = 0;
    }
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
std::vector<LogEntry> parse(std::istream& in) {
    std::vector<LogEntry> final;
    do {
      String line = getline(in);
      LogEntry log(line);
      result.push_back(log);
    } while (!in.eof());

    return final;
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void output_all(std::ostream& out, const std::vector<LogEntry> &all) {
  for (unsigned int i = 0; i < all.size(); ++i) {
    out << all[i];
  } 
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void by_host(std::ostream& out, const std::vector<LogEntry>&log) {
  for (unsigned int i = 0; i < log.size(); ++i) {
    out << log[i].gethost() << '\n';
  }
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
int byte_count(const std::vector<LogEntry> &log) {
  int sum = 0; 
  for (unsigned int i = 0; i < log.size(); ++i) {
    sum += log[i].getbytes();
  }
  return sum;
}

