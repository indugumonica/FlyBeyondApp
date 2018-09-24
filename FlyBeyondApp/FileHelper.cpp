#include "pch.h"
#include<iostream>
#include "FileHelper.h"
#include<fstream>
#include<vector>
#include<sstream>

using namespace std;
namespace FlyBeyondApp {

	std::string FileHelper<string>::WriteTextFile(std::string filename, std::string content) {
		fstream openfile;
		openfile.open(filename,std::fstream::in | std::fstream::out |std::fstream::app);
		openfile << content << endl;
		openfile.close();
		return content;
	}

	std::string FileHelper<string>::ReadTextFile(std::string filename) {
		ifstream readfile;
		readfile.open(filename, ios::in);
		std::string content;
		std::string fullContent;
		while (!readfile.eof()) {
			readfile >> content;
			fullContent = fullContent.append(content).append("\n");
		}
		
		return fullContent;
	 }

	std::vector<string> FileHelper<string>::SplitFile(std::string fileContent, char ch) {
		std::string str = fileContent;
		std::stringstream ss(fileContent);
		std::string item;
		std::vector<std::string> splittedStrings;
		while (std::getline(ss, item, ch))
		{
			if(item != "")
			{
				splittedStrings.push_back(item);
			}
		}
		return splittedStrings;
	
	}
	
	
}