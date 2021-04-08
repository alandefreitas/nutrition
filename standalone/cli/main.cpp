#include "run_model.h"
#include <argh.h>
#include <iostream>

int main(int, char *argv[]) {
    argh::parser cmdl(argv);

    if (cmdl[{"-h", "--help"}] || cmdl[0] == "help") {
        std::cout << "Basic usage:\n";
        std::cout << "     nutrition-cli --filename <preference_file.txt>\n";
    }

    return EXIT_SUCCESS;
}