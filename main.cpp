#include <iostream>
#include "Library.h"
using namespace std;

int main() {
    Library lib;

    Author a1{"Liz Tomforde", 1990};
    Book b1{"Mile High", a1, 2023, 20.90, "ISBN-001"};
    Book b2{"The Right Move", a1, 2023, 20.90, "ISBN-002"};
    Book b3{"Caught Up", a1, 2023, 20.90, "ISBN-003"};

    lib.addBook(b1);
    lib.addBook(b2);
    lib.addBook(b3);

    Author a2{"Ana Huang", 1991};
    Book b4{"Twisted Love", a2, 2022, 22.90, "ISBN-004"};
    Book b5{"Twisted Games", a2, 2022, 22.90, "ISBN-005"};
    Book b6{"Twisted Hate", a2, 2022, 22.90, "ISBN-006"};
    Book b7{"Twisted Lies", a2, 2022, 22.90, "ISBN-007"};
    Book b8{"The Striker", a2, 2024, 21.90, "ISBN-008"};

    lib.addBook(b4);
    lib.addBook(b5);
    lib.addBook(b6);
    lib.addBook(b7);
    lib.addBook(b8);

    lib.addMember(Member{"Sisy Petkova", "M001", 2024});
    lib.addMember(Member{"Maria Tishkova", "M002", 2025}); 

    cout << lib.to_string() << "\n";

    if (lib.loanBook("ISBN-001", "M001", "2025-11-03", "2025-11-17"))
        cout << "Loan created.\n";

    cout << "Available ISBN-001? " << boolalpha << lib.isBookAvailable("ISBN-001") << "\n";
    lib.returnBook("ISBN-001", "M001");
    cout << "Available ISBN-001? " << boolalpha << lib.isBookAvailable("ISBN-001") << "\n";

    for (const auto& bk : lib.findByAuthor("Huang")) {
        cout << bk.to_string() << "\n";
    }
}

