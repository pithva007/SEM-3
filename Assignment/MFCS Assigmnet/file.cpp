#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

const int FILE_SIZE_MB = 15; // File size in MB
const int BYTE_PER_MB = 1024 * 1024;
const int TOTAL_BYTES = FILE_SIZE_MB * BYTE_PER_MB;

char getRandomChar()
{
    return ' ' + (std::rand() % 95); // Random printable ASCII characters (32-126)
}

int main()
{
    std::ofstream outFile("random_text.txt");
    if (!outFile)
    {
        std::cerr << "Error creating file!" << std::endl;
        return 1;
    }

    std::srand(static_cast<unsigned>(std::time(0))); // Seed for random number generation

    for (int i = 0; i < TOTAL_BYTES; ++i)
    {
        outFile << getRandomChar();
    }

    outFile.close();
    std::cout << "15MB file Open link which is in last submission elfuncho Error generated successfully!" << std::endl;
    return 0;
}
