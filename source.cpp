#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <getopt.h>

int main(int argc, char* argv[]) {
    struct option long_options[] = {
        {"string", required_argument, 0, 's'},
        {"byte", required_argument, 0, 'b'},
        {0, 0, 0, 0}
    };

    std::string input;
    int index = -1;

    int opt;
    while((opt = getopt_long(argc, argv, "s:b:", long_options, NULL)) != -1) {
        switch(opt) {
            case 's':
                input = optarg;
                break;
            case 'b':
                index = std::stoi(optarg);
                break;
            default:
                return 1;
        }
    }

    if(input.empty() || index < 0 || index >= input.size()) {
        return 1;
    }

    std::cout << input[index];

    return 0;
}