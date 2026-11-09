# C++ Module 05: Repetition and Exceptions

A deep dive into C++ exception handling, abstract classes, polymorphism, and design patterns within the strict constraints of C++98.

## 🗺️ Map 
## 🗺️ Module Map
| Exo | Core Concept | Key Implementation | Status |
| :---: | :--- | :--- | :---: |
| **ex00** | `std::exception` | `Bureaucrat` class with strict grade limits (1–150) and custom exceptions. | ✅ |
| **ex01** | Form Management | `Form` class with signing grades and integration into `Bureaucrat::signForm()`. | ✅ |
| **ex02** | Abstract Base Class | `AForm` interface with 3 concrete sub-forms (`Shrubbery`, `Robotomy`, `Pardon`) and execution logic. | ✅ |
| **ex03** | Factory Pattern | `Intern` class utilizing a function pointer mapping table for dynamic form creation. | ✅ |

## 📋 Exercises & Core Concepts

### 📁 Ex00: Mommy, when I grow up, I want to be a bureaucrat!
* **Core Goal**: Implement a `Bureaucrat` class with strict grade validation and custom exception handling.
* **Key Concepts**:
  * **Custom Exceptions**: Inheriting from `std::exception` and overriding `what()`.
  * **Exception Handling**: Safe throwing and catching using `try` and `catch` blocks.
  * **Orthodox Canonical Form (OCF)**: Implementing canonical forms for robust class design.
  * **Grade Boundaries**: Managing bureaucratic ranks strictly between `1` (highest) and `150` (lowest).


> 💡 **Public Inheritance**: Inheriting publicly from `std::exception` enables polymorphic interception via references (`catch (std::exception & e)`). If inheritance is private, the type conversion fails.

> 💡 **Exception Specification (`throw()`)**: Promotes that `what()` will not throw exceptions. Overriding it requires matching the exact signature from the standard library.
---

### 📁 Ex01: Form up, maggots!
* **Core Goal**: Introduce a `Form` class that a `Bureaucrat` can sign based on specific grade requirements.
* **Key Concepts**:
  * **Class Interactions**: Handling relationships and dependencies between `Bureaucrat` and `Form`.
  * **Forward Declarations**: Resolving circular dependencies cleanly in header files.
  * **Sign Validation**: Checking if a bureaucrat's grade is high enough to sign a form (`beSigned`).

> 💡 **Circular Dependencies & Forward Declarations**: When `Bureaucrat` includes `Form` and vice versa, it triggers an infinite header inclusion loop. Using `class Form;` forward declarations in headers allows pointers/references without knowing the full class size, keeping includes restricted to `.cpp` files.

> 💡 **The `const` Member Hurdle in OCF**: Because `Form` has `const` attributes (`name`, `gradeToSign`, `gradeToExecute`), the copy assignment operator (`operator=`) **cannot reassign them**. It must only copy non-const states (like `isSigned`).
---
### 📁 Ex02: No, you need form 28B, not 28C...
* **Core Goal**: Transform `Form` into an abstract class (`AForm`) and implement three concrete, functional sub-forms. `AForm` now serves as a blueprint.
* **Key Concepts**:
  * **Abstract Base Classes**: Using pure virtual functions (`= 0`) to enforce design templates.
  * **Virtual Destructors**: Ensuring proper memory cleanup in inheritance hierarchies. 
  * **Polymorphism**: Implementing `execute()` and letting `Bureaucrat::executeForm()` dispatch specific actions.
  * **Concrete Forms**:
    * `ShrubberyCreationForm`: Generates a file and writes an ASCII tree.
    * `RobotomyRequestForm`: Simulates a drilling noise with a 50% randomized success/failure check using `std::rand()`.
    * `PresidentialPardonForm`: Declares a target pardon by Zaphod Beeblebrox.

> 💡 **Polymorphism in Action**: Much like Module 04's `Animal::makeSound()`, `AForm::execute()` relies on virtual functions and dynamic dispatch. Bureaucrat interacts solely with the abstract base reference (`AForm const &`), leaving the execution details entirely to each concrete form subclass.

> 💡 **Double Guardrail Execution**: Before executing any form, classes verify two distinct conditions: (1) Is the form signed? (2) Is the executor's grade high enough (`gradeToExecute`)?

> 💡 **AForm is generic**: Execution depends entirely on the specific type of form. By making it a pure virtual function (`= 0`), I ensure that `AForm` cannot be instantiated directly, and every concrete sub-class is forced to implement its own unique execution logic. Furthermore, the `virtual` keyword enables polymorphism, allowing `Bureaucrat::executeForm` to take a generic AForm const & reference and correctly dispatch to the derived class's `execute` method at runtime.
---
### 📁 Ex03: At least this beats coffee-making
* **Core Goal**: Implement an `Intern` class capable of creating forms dynamically using a factory pattern.
* **Key Concepts**:
  * **Factory Design Pattern**: Centralizing object creation.
  * **Mapping Tables over Anti-Patterns**: Avoiding unmaintainable `if-else` ladders by using function pointer arrays.
  * **Heap Allocation & Memory Management**: Returning raw pointers (`AForm*`) and managing memory responsibly to prevent leaks.

> 💡 **Mapping Table Scalability**: Function pointer arrays map string identifiers to static creation functions. This isolates expansion—adding a new form requires touching only the mapping array, preventing branching spaghetti code. (Using a giant `if-else` is like hardcoding chapter numbers in a document—every time you add something in the middle, you have to manually rewrite and risk breaking everything. A function pointer mapping table is like Markdown headers: you just plug in a new item, and the system dynamically maps and handles it without touching the core engine.)

> 💡 **Memory Responsibility**: Because `makeForm()` allocates memory on the heap using `new`, the caller owns the returned `AForm*` pointer and must explicitly `delete` it to prevent memory leaks.

## 🛠️ Compilation & Usage

Each exercise contains its own directory (or structure) with a standard Makefile. 

Run the following commands in the target directory:

```bash
# Compile the program
make

# Clean up object files
make clean

# Clean up object files and binary
make fclean

# Rebuild everything
make re

# Run the executable
./<executable_name>
```


## 🛡️ Exception Handling & Design Philosophy

Module 05 shifts away from traditional error codes (like returning `-1` or `NULL`) toward modern C++ exception safety:

* **Polymorphic Interception**: All custom exceptions inherit publicly from `std::exception` and override the `virtual const char* what() const throw()` method. This allows uniform handling via reference:
  ```cpp
  try {
      Bureaucrat b("Boss", 0); // Triggers GradeTooHighException
  } catch (std::exception & e) {
      std::cout << e.what() << std::endl;
  }

* **Stack Unwinding**: When an exception is thrown, local objects in the call stack are automatically destroyed in reverse order of construction, ensuring zero resource leaks before the execution flow reaches the matching `catch` block.

  
* **struct FormMapping (in Intern)**: 
在 `Intern` 类的高级实现中，`struct FormMapping` 里的 `(*creator)` 是一个函数指针（**Function Pointer**）: 把某个函数的“内存地址”存起来，以便在运行时根据输入的字符串，动态去调用对应的表单创建函数。
  ``` c++
  struct FormMapping {
      std::string name;                             // 表单名字（如 "robotomy request"）
      AForm* (*creator)(const std::string& target); // 🌟 关键：函数指针
  };
  ```
  * `AForm*`：这个函数指针指向的函数，返回值是一个指向 `AForm` 的指针。

  *  `(*creator)`：这是函数指针变量的名字（名字叫 `creator`，你可以叫它任何名字）。

  *  `const std::string& target`：这个函数指针指向的函数，接收一个参数：目标的字符串引用。
