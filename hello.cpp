#include <boost/variant.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>

int main(int argc, char const *argv[]) {
  typedef boost::variant<int,const char*, std::string> my_var_t;
  std::vector<my_var_t> v;
  v.push_back(10);
  v.push_back("Hello there!");
  v.push_back(std::string("Wow"));
  std::string& s = boost::get<std::string>(v.back());
  s += "That is great!\n";
  std::cout<< s;
  char* c_string = new char[s.length() + 1];
  std::strcpy(c_string, s.c_str());
  printf("%s\n", c_string);
  

  return 0;
}
