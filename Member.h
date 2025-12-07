#pragma once
#include <string>
#include <stdexcept>
#include <utility>

class Member {
    std::string name;
    std::string memberId;
    int yearJoined;

public:
    Member() : name("Unknown"), memberId("NONE"), yearJoined(2000) {}

    Member(std::string n, std::string id, int y)
        : name(std::move(n)), memberId(std::move(id)), yearJoined(y)
    {
        if (memberId.empty()) throw std::invalid_argument("Empty member ID");
    }

    const std::string& getName() const { return name; }
    const std::string& getId() const { return memberId; }
    int getYearJoined() const { return yearJoined; }

    std::string to_string() const {
        return name + " (" + memberId + ", joined " + std::to_string(yearJoined) + ")";
    }
};
