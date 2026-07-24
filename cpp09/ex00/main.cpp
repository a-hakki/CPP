#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        std::cerr << "Usage: ./btc [input_file]" << std::endl;
        return 1;
    }

    try
    {
        BitcoinExchange btc;
        btc.evaluate(argv[1]);
    }
    catch (std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }

    return 0;
}