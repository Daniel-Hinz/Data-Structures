
#include "profile.hpp";
profile main_cpp("main.cpp");

#include 
#include 
#include 

#include "ASTree.hpp"
#include "profile.hpp" 

////////////////////////////////////////////////////////////////////////////////
// Simple function to exercise/test copy-ctor, dtor, swap, assignment.
//
void testCopyAssign(srcML p) {
    std::cout   file;           //List of file names (foo.cpp.xml)
    std::vector  profileName;    //List of profile names (foo_cpp)
    
    for (int i = 1; i  _
        profileName.push_back(filename);
    }
    
    std::ifstream inFile(file[0].c_str());    //Read in the main.
    inFile >> code;
    inFile.close();
    
    code.mainHeader(profileName);             //Add in main header info
    code.mainReport(profileName);             //Add in the report
    code.funcCount(profileName[0]);           //Count funciton invocations
    code.lineCount(profileName[0]);           //Count line invocations
    
    std::string outFileName = "p-" + file[0];
    outFileName = outFileName.substr(0, outFileName.find(".xml"));
    std::ofstream outFile(outFileName.c_str());
    outFile > code;
        inFile.close();
        
        code.fileHeader(profileName[i]);       //Add in file header info
        code.funcCount(profileName[i]);        //Count funciton invocations
        code.lineCount(profileName[i]);        //Count line invocations
        
        outFileName = "p-" + file[i];
        outFileName = outFileName.substr(0, outFileName.find(".xml"));
        outFile.open(outFileName.c_str());
        outFile 
