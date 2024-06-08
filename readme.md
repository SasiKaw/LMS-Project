# Library Management System

This project is a console-based Library Management System developed in C++. It was my first project as a first-year undergraduate student at my university. The project was designed to help us understand the basics of C++ programming and file handling.

## Project Overview

The Library Management System is a simple console application that provides a simple yet effective way of managing a library's catalog. It allows for the addition, modification, and deletion of books. It also provides features for checking out books, returning them, and keeping track of overdue items.

This project does not establish a database connection. Instead, it uses C++ file handling functions to store library data. This was a deliberate choice to keep the project simple and focused on the core C++ programming concepts.

## Features

**Add, modify, and delete books from the catalog.
**Check out books to library patrons.
**Return books to the library.
**Track overdue items

## Code Snippet

```
// Check the username and password are both correct
if (userName == adminUserName && password == adminPassword){
    for (int i = 0; i < 40; ++i) 
    {
        std::cout << ' ';
    }
    SetConsoleTextAttribute(hConsole, 0x2F);
    cout << "\n";
    std::cout << "\t\t\t\t\tACCESS GRANTED";
    SetConsoleTextAttribute(hConsole, 7);
    Sleep(1000);
    system("cls");
    adminMenu();
    exit(0);
}
else
{   
    char option = '0';
    for (int i = 0; i < 40; ++i) 
    {
        std::cout << ' ';
    }
    SetConsoleTextAttribute(hConsole, 0x4F);
    cout << "\n";
    std::cout << "\t\t\t\t\tACCESS DENIED\n";
    SetConsoleTextAttribute(hConsole, 7); 

    SetConsoleTextAttribute(hConsole, 0x17);
    cout << "\t\t\t\t\tDo you want to try again?(y/n)";
    SetConsoleTextAttribute(hConsole, 7);
    cout << " ";
    cin >> option;
}
```
This code snippet is responsible for checking if the entered username and password match the admin credentials. If they do, the user is granted access to the admin menu. If they don't, the user is denied access and asked if they want to try again.


## How to Run

To run this project, you need a C++ compiler. You can use any IDE that supports C++ programming such as Visual Studio, Code::Blocks, or even a simple text editor and a command line compiler.

**Clone this repository to your local machine.
**Open the project in your preferred C++ IDE or text editor.
**Compile and run the project.

## Conclusion
This project was a great learning experience for me as it allowed me to apply the C++ programming concepts I learned in a practical project. I hope it will be useful to others who are learning C++ and want to understand how to create a simple console application.

## Contributing

Contributions to the Library Management System project are welcome. If you would like to contribute, please follow these guidelines:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and commit them with descriptive commit messages.
4. Push your changes to your forked repository.
5. Submit a pull request, explaining the changes you have made.

## License

This project is licensed under the [MIT License](LICENSE).

## Acknowledgements

I would like to express my gratitude to [Professor/Supervisor Name] for their guidance and support throughout the development of this project.
