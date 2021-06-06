// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
BST<std::string>Wood;
std::string str = "";
std::ifstream file(filename);
if (!file) {
std::cout << "File error!" << std::endl;
return Wood;
} else {
while (!file.eof()) {
int ASCII = file.get();
if ((ASCII >= 'a' && ASCII <= 'z') || (ASCII >= 'A' && ASCII <= 'Z')) {
if (ASCII >= 'A' && ASCII <= 'Z')
ASCII = tolower(ASCII);
str += ASCII;
} else if (!str.empty()) {
Wood.add(str);
str = "";
}
}
}
file.close();
return Wood;
}
