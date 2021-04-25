// Daniel Hinz
// assembler.cpp

#include "utilities.hpp"

int main(int argc, char const* argv[]){
  bool outputFile = true;

  if (argc < 2){
    std::cerr << "No input file present." << std::endl;
    return 0;
  }

  std::ifstream in(argv[1]);
  if (!in){
    std::cerr << "Could not open file, existing" << std::endl;
    return 0;
  }

  std::ofstream out(argv[2]);
  if (!out){
    outputFile = false;
    std::cerr << "Output file could not be opened" << std::endl;
  }
  std::vector<String> expressions;
  std::string temp;
  in >> temp;

  std::string exp;

  while (!in.eof()){
    while (temp != ";" && !in.eof()){
      exp += (temp + " ");
      in >> temp;
    }
    expressions.push_back(exp);
    exp = "";
    in >> temp;
  }

  std::vector<std::string> postfix;

  for(int i = 0; i < expressions.size(); ++i)
  postfix.push_back(toPostfix(expressions[i]));

  for(int i = 0; i < expressions.size(); ++i){
    if (!outputFile) {
      std::cout << "Infix: " << expressions[i] << std::endl;
      std::cout << "postfix: " << postfix[i] << std::endl;
      std::cout << '\n';
    }
  else {
    out << "Infix: " << expressions[i] << std::endl;
    out << "postfix: " << postfix[i] << std::endl;
    out << '\n';
  }
  toAssembler(postfix[i], out);

  if (!outputFile)
    std::cout << std::endl;
  else
    out << std::endl;
  }
 return 1;
}
