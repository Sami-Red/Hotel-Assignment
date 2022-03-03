#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

struct Room
{
private:
    std::string customer;
public:
    void set_customer(const std::string& customer) { this->customer = customer; }
    std::string get_customer() const { return customer; }
}rooms[10];

void clear_rooms()
{
    for (int i = 0; i < 10; i++)
        rooms[i].set_customer("e");
}

void add_customer()
{
    std::string name;
    int number;
    std::cout << "Please enter the customer's name." << std::endl;
    std::cout << " -> ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Please pick a room for customer to stay in." << std::endl;
    std::cout << " -> ";
    std::cin >> number;
    rooms[number - 1].set_customer(name);
}

void all_room()
{
    for (int i = 0; i < 10; i++)
    {
        if (rooms[i].get_customer() == "e")
            std::cout << i + 1 << ". room is empty." << std::endl;
        else
            std::cout << i + 1 << ". in room " << rooms[i].get_customer() << " is staying." << std::endl;
    }
}

void empty_rooms()
{
    for (int i = 0; i < 10; i++)
        if (rooms[i].get_customer() == "e")
            std::cout << i + 1 << ". room is empty." << std::endl;
}

void del_room()
{
    int i;
    std::cout << "Please write the room's number to empty it.";
    std::cout << " -> ";
    std::cin >> i;
    rooms[i - 1].set_customer("e");
}

void find_room_number()
{
    std::string name;
    std::cout << "Please enter customer's full name to find their room: " << std::endl;
    std::cout << " -> ";
    std::cin.ignore();
    std::getline(std::cin, name);
    for (int i = 0; i < 10; i++)
        if (rooms[i].get_customer() == name)
        {
            std::cout << rooms[i].get_customer() << " is in room " << i + 1 << ". odada kaliyor." << std::endl;
            break;
        }
}

void save_to_file()
{
    std::fstream file("Data.txt", std::ios::out);
    for (std::size_t i = 0; i < 10; i++)
        file << rooms[i].get_customer() << std::endl;

    file.close();
}

void get_from_file()
{
    std::fstream file("Data.txt", std::ios::in);
    std::string customer;
    int pos = 0;

    clear_rooms();
    for (std::size_t i = 0; i < 10; i++)
    {
        std::getline(file, customer);
        rooms[i].set_customer(customer);
    }
    file.close();
}

void sort_rooms()
{
    std::vector<std::string> rooms_vec;
    for (std::size_t i = 0; i < 10; i++)
        rooms_vec.push_back(rooms[i].get_customer());

    std::sort(rooms_vec.begin(), rooms_vec.end());
    for (const std::string& room : rooms_vec)
        std::cout << room << std::endl;
}

void choice()
{
    clear_rooms();
    while (true)
    {
        char k;
        std::cout << "Please pick an option from below." << std::endl;
        std::cout << "-------------------   -------------------" << std::endl;
        std::cout << "1-) Press the A key to add customers." << std::endl;
        std::cout << "2-) Press V key to view all rooms." << std::endl;
        std::cout << "3-) Press the E key to show the empty rooms." << std::endl;
        std::cout << "4-) Press the D key to delete the customer from the room." << std::endl;
        std::cout << "5-) Press the F key to find a room by customer name." << std::endl;
        std::cout << "6-) Press the S key to save the program data to the file." << std::endl;
        std::cout << "7-) Press the L key to load the program data from the file." << std::endl;
        std::cout << "8-) Press the O key to sort the rooms alphabetically by the customer's name." << std::endl;
        std::cout << "9-) Press any other key to exit the program." << std::endl;
        std::cout << " -> ";
        std::cin >> k;

        switch (k)
        {
        case 'A':
            add_customer();
            break;
        case 'V':
            all_room();
            break;
        case 'E':
            empty_rooms();
            break;
        case 'D':
            del_room();
            break;
        case 'F':
            find_room_number();
            break;
        case 'S':
            save_to_file();
            break;
        case 'L':
            get_from_file();
            break;
        case 'O':
            sort_rooms();
            break;
        default:
            goto end;
            break;
        }
    }

end: {}
}

void beginning()
{
    char inp;
    std::cout << "Press 'I' to start program." << std::endl;
    std::cout << " -> ";
    std::cin >> inp;
    if (inp == 'I')
        choice();
}

int main()
{
    beginning();
    return 0;
}