// test.cpp
#include <iostream>
#include <iomanip>
#include <string>
#include <boost/filesystem.hpp>
#include "gps.hpp"

int main()
{
    // create class instance
    const gps_position g(35, 59, 24.567f);
    std::cout << "Initial value: " << g << std::endl;
    save(g);

    // ... some time later restore the class instance to its orginal state
    gps_position newg;
    load(newg);
    std::cout << "After load: " << newg << std::endl;

    if (g != newg)
    {
        std::cerr << "ERROR: Loaded object differs from the saved one" << std::endl;
        return 1;
    }

    std::cout << "Congratulations! GPS object was successfully saved and then loaded" << std::endl;
    boost::filesystem::path tmp = "/root/test";
    boost::filesystem::path fname = "sample";
    tmp /= fname;
    std::cout << "The test for using boost::filesystem::path is " << std::endl;
    std::cout << tmp.string().c_str() << std::endl;
    return 0;
}