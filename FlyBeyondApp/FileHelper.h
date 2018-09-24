#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include<vector>



namespace FlyBeyondApp {
	template <typename T>
	 class FileHelper {

	public:
		static std::string WriteTextFile(std::string fileName, std::string content);
		static std::string ReadTextFile(std::string fileName);
		static std::vector<T> SplitFile(std::string fileContent, char ch);

	};
}
