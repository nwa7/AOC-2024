#pragma once
#include <iostream>
#include <string>
#include <vector>

int getColumns(const std::string &path, std::vector<int> &c1,
               std::vector<int> &c2);

int getLines(const std::string &path, std::vector<std::vector<int>> &lines);

int getStringLines(const std::string &path,
                   std::vector<std::vector<std::string>> &lines);

int getString(const std::string &path, std::string &lines);

int getPrintingInstruction(const std::string &path,
                           std::vector<std::vector<int>> &rules,
                           std::vector<std::vector<int>> &updates);