
#define CATCH_CONFIG_RUNNER // Configure catch to use main

#include <fstream>
#include<iostream>
#include<string>
#include<exception>
#include "catch.hpp"

using namespace std;

int main(int argc, char* argv[]) {

    //TODO: better job for parsing args
    if(argc == 1) {

        cout << "No arguments... running TESTS!!!!" << endl;
        try {
            //run catch with all tests
            auto result = Catch::Session().run(argc, argv);
            //std::cin.get(); // Immediate feedback.
            return (result < 0xFF ? result : 0xFF);
        } catch (const std::exception& ex) {
            auto pMessage = ex.what();
            if (pMessage) {
                std::cout << "An unhandled exception was thrown:\n" << pMessage;
            }
            std::cin.get(); // Immediate feedback.
            return -1;
        }
    }
    else{
        cout << "Main program logic goes here..." << endl;
        cout << "program called with args ";

        for(auto i=1; i < argc; i++){
           cout << argv[i];
           if(i+1 < argc)
              cout << ", "; 
        }
    }

    return 0;
}
