#include "Logger.h"
#include <iostream>
#include <fstream>

void Logger::log(std::string message) {
  std::ofstream logFile;
  logFile.open ("log.txt");
  logFile << message + "\n";
  logFile.close();
}
