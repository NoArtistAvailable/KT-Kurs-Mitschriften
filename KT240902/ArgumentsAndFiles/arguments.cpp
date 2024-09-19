#include <iostream>
#include <string>
#include <cstring>

int _main(
    int argc,           // argc = (Anzahl der Argumente)
    char* argv[],       // argv = argument values immer >= 1
                        // can also be char** argv
    char* envp[]        // enivronment pointer  (NAME=WERT)
)
{
    std::string accesPath = argv[0];    // first argument is always the path of the program
    std::cout << "Anzahl der Argumente: " << argc << std::endl;

    for (int i = 0; i < argc; i++) {
        std::cout << "[" << i << "] " << argv[i] << std::endl;
    }

    //------Adding two numbers------//

    //if (argc != 3) {
    //    std::cerr << "To add two numbers, we need two arguments" << std::endl;
    //    return -1;  // Errorcode
    //}

    //int num1, num2;
    //num1 = atoi(argv[1]);
    //num2 = atoi(argv[2]);

    //std::cout << "sum: " << num1 + num2 << std::endl;

    //for (int i = 0; envp[i] != nullptr; i++) {
    //    std::cout << envp[i] << std::endl;
    //}

    // look for environment variable
    const char* search_for = "Path";

    for (int i = 0; envp[i] != nullptr; i++) {
        if (std::strncmp(envp[i], search_for, strlen(search_for)) == 0) {
            std::cout << envp[i] << std::endl;
        }
    }


    return 0;
}

