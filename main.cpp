#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

int main(){
    std::cout<<"----------------------------"<<std::endl;
    std::cout<<"|        DISCLAIMER        |"<<std::endl;
    std::cout<<"| USE ABSOLUTE PATHS ONLY! |"<<std::endl;
    std::cout<<"----------------------------"<<std::endl<<std::endl;

    std::string outputName,filePath,directoryPath;
    std::vector<std::string> compile;
    // std::cout << "Enter the path of the file you want to compile: "; std::cin >> filePath;
    // // std::cout << "Enter the name of the output file: "; std::cin >> outputName;
    std::cout << "Enter the path of the directory you want to compile in: "; std::getline(std::cin,directoryPath);
    std::cout << "File(s) in the directory: " << std::endl;
    for (std::filesystem::recursive_directory_iterator i("."), end; i != end; ++i) 
        if (!std::filesystem::is_directory(i->path()))
            std::cout << i->path().filename() << "\n";
}