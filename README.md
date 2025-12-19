# CS-210

# Corner Grocer Frequency Tracker

## 📌 Project Summary
This project was developed for the Corner Grocer to analyze and display the frequency of items purchased. The program reads from an input file (`CS210_Project_Three_Input_File.txt`), counts how many times each item appears, and provides multiple menu options for users:
1. Look up the frequency of a specific item.
2. Print a list of all items with their purchase counts.
3. Display a text-based histogram showing item frequencies with asterisks.
4. Exit the program.

Additionally, the program creates a backup file (`frequency.dat`) at startup to ensure data persistence.

---

## ✅ What I Did Well
- Designed a **modular class (`GroceryTracker`)** with clear public and private sections, encapsulating all functionality for data loading, backup, and display.
- Used **maps** for efficient frequency counting, ensuring fast lookups and clean code.
- Implemented a **menu-driven interface** with input validation to make the program user-friendly.
- Applied **industry best practices** such as descriptive variable names, in-line comments, and consistent formatting to improve readability.

---

## 🔧 Areas for Enhancement
- **Input validation** could be expanded further to handle edge cases (e.g., empty strings, numeric input for item names).
- **Error handling** for file operations could be more robust, with custom exceptions instead of simple `cerr` messages.
- Adding **color or formatting** to the histogram output would improve user experience.
- Future improvements could include **unit tests** to validate functionality and ensure long-term maintainability.

---

## ⚡ Challenges and How I Overcame Them
- The most challenging part was **implementing the histogram output** in a way that scaled cleanly with varying item frequencies. I overcame this by iterating through the map and dynamically printing asterisks based on the count.
- Another challenge was **managing file I/O** correctly. I relied on zyBooks sections (7.1 and 7.3) and official C++ documentation to ensure proper file handling.
- To support my work, I added resources like the **C++ reference site (cppreference.com)** and GitHub documentation to my toolkit.

---

## 🎯 Transferable Skills
- **Class design and encapsulation**: Building modular, reusable components will apply directly to future projects.
- **File I/O and data persistence**: Handling input/output files is a common requirement across many applications.
- **Map usage and data structures**: Efficient data handling is critical in both academic and professional coding.
- **Problem decomposition**: Breaking down requirements into smaller, manageable functions is a skill that transfers to any programming task.

---

## 🛡️ Maintainability, Readability, and Adaptability
- The program is **maintainable** because functionality is encapsulated in a single class, making future changes localized and easy to manage.
- It is **readable** thanks to clear naming conventions, inline comments, and consistent formatting.
- It is **adaptable** because the menu system and class design allow new features (e.g., exporting to CSV, adding graphical UI) to be integrated without rewriting core logic.

---

## 📂 Files
- `CS210_Project_Three_Input_File.txt` → Input data file.
- `frequency.dat` → Backup file generated automatically.
- `main.cpp` → Source code containing the `GroceryTracker` class and menu system.

---

## 🚀 Reflection
This project strengthened my ability to design structured, maintainable programs while practicing real-world problem solving. By combining file I/O, data structures, and user interaction, I created a tool that not only solves the Corner Grocer’s problem but also demonstrates my growing proficiency in C++. The reflection process helped me identify both strengths and areas for growth, ensuring that I continue to improve as a developer.

