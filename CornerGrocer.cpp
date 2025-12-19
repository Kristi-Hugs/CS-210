/*******************************************************
 * CornerGrocer.cpp
 * Author: Kristi Huggins SNHU
 * Date: December 2025
 *
 * Description:
 *   Item-tracking program for the Corner Grocer.
 *   - Reads daily purchase log from CS210_Project_Three_Input_File.txt
 *   - Builds frequency map of items
 *   - Writes backup file frequency.dat automatically
 *   - Provides menu with options:
 *       1. Query item frequency
 *       2. Print all item frequencies
 *       3. Print histogram
 *       4. Exit
 *
 * Styling:
 *   - Menu: Options 1–3 plain text, Exit in red
 *   - Item list: plain text
 *   - Histogram: stars colored by frequency ranges
 *******************************************************/

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <stdexcept>
#include <limits>
#define NOMINMAX 
#include <windows.h>   // For SetConsoleTextAttribute

 /*------------------------------------------------------
   Utility: setColor
   Sets console text color using Windows API.
   Common color codes:
     7  = Gray (default)
     10 = Green
     12 = Red
     14 = Yellow
     6  = Dark Yellow (approx orange)
 ------------------------------------------------------*/
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

/*------------------------------------------------------
  Class: CornerGrocer
  Responsibilities:
    - Load item frequencies from file
    - Write backup file
    - Query single item frequency
    - Print all frequencies
    - Print histogram with colored stars
    - Run interactive menu
------------------------------------------------------*/
class CornerGrocer {
private:
    std::map<std::string, int> freq_;   // Item -> frequency
    std::string inputFilePath_;         // Input file path

public:
    // Constructor: initialize with input file path
    explicit CornerGrocer(std::string inputPath)
        : inputFilePath_(std::move(inputPath)) {
    }

    /*----------------------------------------------
      Load frequencies from input file.
      Throws runtime_error if file cannot be opened.
    ----------------------------------------------*/
    void loadFromFile() {
        freq_.clear();
        std::ifstream fin(inputFilePath_);
        if (!fin) {
            throw std::runtime_error("Failed to open input file: " + inputFilePath_);
        }
        std::string item;
        while (fin >> item) {
            ++freq_[item];   // Increment count for each item
        }
    }

    /*----------------------------------------------
      Write backup file (frequency.dat).
      Contains item and frequency pairs.
    ----------------------------------------------*/
    void writeBackup(const std::string& outPath = "frequency.dat") const {
        std::ofstream fout(outPath);
        if (!fout) {
            throw std::runtime_error("Failed to write backup file: " + outPath);
        }
        for (const auto& kv : freq_) {
            fout << kv.first << " " << kv.second << "\n";
        }
    }

    /*----------------------------------------------
      Query frequency of a single item.
      Returns 0 if item not found.
    ----------------------------------------------*/
    int getFrequency(const std::string& item) const {
        auto it = freq_.find(item);
        return (it != freq_.end()) ? it->second : 0;
    }

    /*----------------------------------------------
      Print all items and their frequencies.
      Black/white text only.
    ----------------------------------------------*/
    void printAll() const {
        std::cout << "\n=== Item Frequencies ===\n";
        if (freq_.empty()) {
            std::cout << "[No items loaded]\n";
            return;
        }
        for (const auto& kv : freq_) {
            std::cout << kv.first << " " << kv.second << "\n";
        }
    }

    /*----------------------------------------------
      Print histogram with colored stars.
      Frequency determines star color:
        1-3 = Red
        4-6 = Orange (approx)
        7-9 = Yellow
        10+ = Green
    ----------------------------------------------*/
    void printHistogram() const {
        std::cout << "\n=== Purchase Histogram ===\n";
        if (freq_.empty()) {
            std::cout << "[No items loaded]\n";
            return;
        }

        for (const auto& kv : freq_) {
            std::cout << kv.first << " ";
            int count = kv.second;

            // Determine color based on frequency
            int color;
            if (count <= 3) {
                color = 12; // Red
            }
            else if (count <= 6) {
                color = 6;  // Dark Yellow (approx orange)
            }
            else if (count <= 9) {
                color = 14; // Yellow
            }
            else {
                color = 10; // Green
            }

            setColor(color);
            for (int i = 0; i < count; ++i) {
                std::cout << "*";
            }
            setColor(7); // Reset
            std::cout << "\n";
        }
    }

    /*----------------------------------------------
      Run interactive menu loop.
      Options 1-3: black/white
      Option 4: red
    ----------------------------------------------*/
    void runMenu() const {
        while (true) {
            std::cout << "\nCorner Grocer Item Tracker\n";
            std::cout << "1. Query item frequency\n";
            std::cout << "2. Print all item frequencies\n";
            std::cout << "3. Print histogram\n";

            setColor(12); // Red
            std::cout << "4. Exit\n";
            setColor(7);  // Reset

            std::cout << "Select an option (1-4): ";
            int option;
            if (!(std::cin >> option)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number from 1 to 4.\n";
                continue;
            }

            if (option == 1) {
                std::cout << "Enter item name: ";
                std::string query;
                std::cin >> query;
                int count = getFrequency(query);
                std::cout << query << " " << count << "\n";
            }
            else if (option == 2) {
                printAll();
            }
            else if (option == 3) {
                printHistogram();
            }
            else if (option == 4) {
                setColor(12);
                std::cout << "Exiting program. Goodbye!\n";
                setColor(7);
                break;
            }
            else {
                std::cout << "Invalid option. Please select 1-4.\n";
            }
        }
    }
};

/*------------------------------------------------------
  Main function:
    - Creates CornerGrocer object
    - Loads data from input file
    - Writes backup file
    - Runs interactive menu
------------------------------------------------------*/
int main() {
    const std::string inputPath = "CS210_Project_Three_Input_File.txt";
    try {
        CornerGrocer app(inputPath);
        app.loadFromFile();   // Load data
        app.writeBackup();    // Write backup file
        app.runMenu();        // Run menu loop
    }
    catch (const std::exception& ex) {
        setColor(12); // Red for error
        std::cerr << "Fatal error: " << ex.what() << "\n";
        setColor(7);
        return 1;
    }
    return 0;
}