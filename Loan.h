#pragma once
#include <string>
#include <stdexcept>

class Loan {
    std::string isbn;
    std::string memberId;
    std::string startDate;
    std::string dueDate;
    bool returned;

public:
    Loan(std::string i, std::string m, std::string s, std::string d)
        : isbn(std::move(i)), memberId(std::move(m)),
          startDate(std::move(s)), dueDate(std::move(d)), returned(false)
    {
        if (dueDate < startDate)
            throw std::invalid_argument("Due date earlier than start date");
    }

    const std::string& getIsbn() const { return isbn; }
    const std::string& getMemberId() const { return memberId; }
    bool isReturned() const { return returned; }

    void markReturned() { returned = true; }

    bool isOverdue(const std::string& today) const {
        return !returned && today > dueDate;
    }

    std::string to_string() const {
        return isbn + " borrowed by " + memberId +
               " [" + startDate + " -> " + dueDate + "] " +
               (returned ? "(returned)" : "(active)");
    }
};
