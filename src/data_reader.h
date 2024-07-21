#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>


struct Person {
    std::string name;
    int age;
    std::string city;
};


void read_content() {
    std::ifstream inputFile("C:\\Users\\User\\Desktop\\cpp\\falcon_bt\\src\\sample.txt");

    // Check if the file was successfully opened
    if(!inputFile) {
        std::cerr << "Unable to open file." << std::endl;
        return; // Exit with an error code
    }

    std::string line;
    std::vector<Person> people;

    // Skip the header line
    std::getline(inputFile,line);

    // Read the file line-by-line
    while(std::getline(inputFile,line)) {
        std::istringstream lineStream(line);
        std::string field;
        Person person;

        // Parse each field
        std::getline(lineStream,person.name,',');
        std::getline(lineStream,field,',');
        person.age = std::stoi(field);
        std::getline(lineStream,person.city,',');

        people.push_back(person);
    }

    // Close the file
    inputFile.close();

    // Process the data (for example, print it to the console)
    for(const auto& person : people) {
        std::cout << "Name: " << person.name << ", Age: " << person.age << ", City: " << person.city << std::endl;
    }

    return; // Exit successfully
}