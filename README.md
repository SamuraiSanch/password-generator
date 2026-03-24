# 🔐 Password Generator
A console-based password generator built in C++ with three complexity levels. Generate secure, random passwords instantly!

## 📋 Description
**Password Generator** lets you create random passwords tailored to your needs.
Choose a complexity level and desired length — the generator handles the rest.

- **Easy** — lowercase letters and digits
- **Medium** — lowercase + uppercase letters and digits
- **Hard** — full printable ASCII character set (letters, digits, and symbols)

Each password is randomly generated every time using a Mersenne Twister engine (`std::mt19937`).

## 🎯 Complexity Levels
| Level  | Characters Used                        |
|--------|----------------------------------------|
| Easy   | `a–z`, `0–9`                           |
| Medium | `a–z`, `A–Z`, `0–9`                    |
| Hard   | Full printable ASCII (`!`, `@`, `#`…)  |

## 🛠️ Technologies
- **C++11**
- **`<random>`:** `std::random_device` + `std::mt19937` + `std::uniform_int_distribution` for high-quality randomness
- **`enum class`:** type-safe complexity level representation
- **Input validation:** `std::cin.fail()` handling with recovery via `cin.clear()` / `cin.ignore()`
- **Exception handling:** `std::runtime_error` for invalid states

## 🚀 How to Run
### Compilation (GCC/Clang):
```bash
g++ -std=c++11 password-generator.cpp -o password-generator
./password-generator
```
### Compilation (Visual Studio):
1. Open the project in Visual Studio
2. Press `F5` (Run)

## 📂 Project Structure
```
password-generator/
└── password-generator.cpp    # Full generator logic
```

## 📋 Example Usage
```
=== Welcome to Password Generator! ===
Which complexity of password do you need?
Options:
0) Easy
1) Medium
2) Hard
Your answer: 2
Sure. Now enter length of password(1 - 999): 16
Generated password: qF3$Lp!9Wz@eR7&k
```

## 🔧 Future Improvements
- [ ] Guarantee at least one character from each required category
- [ ] Option to exclude ambiguous characters (`0`, `O`, `l`, `1`)
- [ ] Copy generated password to clipboard automatically
- [ ] Generate multiple passwords at once
- [ ] Save passwords to a file

## 👤 Author
**Oleksandr Kopii**  
GitHub: [@SamuraiSanch](https://github.com/SamuraiSanch)

---
⭐ If you found this useful, consider leaving a star!