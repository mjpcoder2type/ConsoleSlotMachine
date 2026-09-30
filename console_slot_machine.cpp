// Author : mjpcoder_type@outlook.com
// 9/30/26
// Console Based Slot Machine
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <random>
#include <thread>
#include <chrono>
// four unique sequences
void sequence_one()
{
    std::cout << "----------" << "      " << "----------" << "      " << "----------" << std::endl;
    std::cout << "|        |" << "      " << "|        |" << "      " << "|        |" << std::endl;
    std::cout << "|   **   |" << "      " << "|        |" << "      " << "|   **   |" << std::endl;
    std::cout << "|        |" << "      " << "|        |" << "      " << "|        |" << std::endl;
    std::cout << "|        |" << "      " << "|        |" << "      " << "|        |" << std::endl;
    std::cout << "----------" << "      " << "----------" << "      " << "----------" << std::endl;

}

void sequence_two()
{
    std::cout << "----------" << "      " << "----------" << "      " << "----------" << std::endl;
    std::cout << "|        |" << "      " << "|        |" << "      " << "|        |" << std::endl;
    std::cout << "|        |" << "      " << "|   **   |" << "      " << "|   **   |" << std::endl;
    std::cout << "|        |" << "      " << "|        |" << "      " << "|        |" << std::endl;
    std::cout << "|        |" << "      " << "|        |" << "      " << "|        |" << std::endl;
    std::cout << "----------" << "      " << "----------" << "      " << "----------" << std::endl;

}

void sequence_three()
{
    std::cout << "----------" << "      " << "----------" << "      " << "----------" << std::endl;
    std::cout << "|        |" << "      " << "|        |" << "      " << "|        |" << std::endl;
    std::cout << "|   **   |" << "      " << "|   **   |" << "      " << "|        |" << std::endl;
    std::cout << "|        |" << "      " << "|        |" << "      " << "|        |" << std::endl;
    std::cout << "|        |" << "      " << "|        |" << "      " << "|        |" << std::endl;
    std::cout << "----------" << "      " << "----------" << "      " << "----------" << std::endl;
}

void sequence_four()
{
    std::cout << "----------" << "      " << "----------" << "      " << "----------" << std::endl;
    std::cout << "|        |" << "      " << "|        |" << "      " << "|        |" << std::endl;
    std::cout << "|   **   |" << "      " << "|   **   |" << "      " << "|   **   |" << std::endl;
    std::cout << "|        |" << "      " << "|        |" << "      " << "|        |" << std::endl;
    std::cout << "|        |" << "      " << "|        |" << "      " << "|        |" << std::endl;
    std::cout << "----------" << "      " << "----------" << "      " << "----------" << std::endl;
}

void slot_machine_generator() // uses functional,random,chrono and thread headers to randomize the sequences....pretty neat, huh?
    {
        std::vector<std::function<void()>> sequence_list = 
    {
        sequence_one,
        sequence_two,
        sequence_three,
        sequence_four
    }; // include sequence functions for randomizing

    std::random_device random_func;
    std::mt19937 engine(random_func()); // Mersenne Twister...this is (obviously) from the random header! 
    std::uniform_int_distribution<> distributor(0, sequence_list.size() - 1);

    int do_random = distributor(engine);
    sequence_list[do_random]();
    }


int main()
{
    std::cout << "Welcome to the Console-based Slot Machine!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // take time to read
    std::cout << "In 3 seconds, the lever will come down!  If you get three full slots you WIN!" << std::endl; // build a little anticipation
    std::this_thread::sleep_for(std::chrono::milliseconds(3500));

    for(int i =0;i < 10;i++)
    {
        slot_machine_generator();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }    
    
    return 0;
}