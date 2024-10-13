#include "executeAll.hpp"

int main(int argc, char **argv) {
    
    if (argc != 2) {
        executeAll();
    } else 
        executeOneSeveralTimes(argv[1]);
        
    return 0;
}
