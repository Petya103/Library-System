#pragma once
#include <string>
#include <stdexcept>
#include <utility>
#include "Author.h"

class Book {
    std::string title;
    Author author;
    int year;
    double price;
    std::string isbn;

    static int totalBooks;

public:
    Book()
        : title("Untitled"), author(), year(1900), price(0.0), isbn("UNKNOWN")
    {
        ++totalBooks;
    }

    Book(std::string t, Author a, int y, double p, std::string i)
        : title(std::move(t)), author(std::move(a)),
          year(y), price(p), isbn(std::move(i))
    {
        if (p < 0) throw std::invalid_argument("Negative price");
        if (y < 1500 || y > 2025) throw std::invalid_argument("Invalid year");
        ++totalBooks;
    }

    
    Book(const Book&) = default;
    Book(Book&&) noexcept = default;
    Book& operator=(const Book&) = default;
    Book& operator=(Book&&) noexcept = default;
    ~Book() = default;

    const std::string& getTitle() const { return title; }
    const Author& getAuthor() const { return author; }
    const std::string& getIsbn() const { return isbn; }
    int getYear() const { return year; }
    double getPrice() const { return price; }

    void setPrice(double p) {
        if (p < 0) throw std::invalid_argument("Negative price");
        price = p;
    }

    std::string to_string() const {
        return title + " | " + author.to_string() +
               " | " + std::to_string(year) +
               " | " + std::to_string(price) +
               " | " + isbn;
    }

    static int getTotalBooks() { return totalBooks; }
};

inline int Book::totalBooks = 0;
