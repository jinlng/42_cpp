# C++ 06: Casts

## Preparation
### 🗺️ Module Map
| Exo | Core Concept | Key Implementation | Status |
| :---: | :--- | :--- | :---: |
| **ex00** | Scalar conversion | Create a class that takes a string literal representation of a scalar type. | ✅ |
| **ex01** | Serialization | Convert a pointer to a data structure into an unsigned integer and back. | ✅ |
| **ex02** | Identify real type | `Base` class and 3 derived classes, | ✅ |


### Pillars of C++ Casts
C++ named casts make the developer's intent explicit to both the compiler and other programmers, restrict operations to safe boundaries, and make code much easier to search and debug in large codebases.

#### 1. `static_cast<T>(expression)`
- What it does: Compile-time cast for related types (e.g., `int` to `float`, upcasting/downcasting in class hierarchies where types are known).

- Safety: Checked at compile time. No runtime overhead.
#### 2. `dynamic_cast<T>(expression)`
- What it does: Safe downcasting for polymorphic classes (classes with at least one virtual function).

- Safety: Checked at runtime. If the cast fails on a pointer, it returns `NULL`. If it fails on a reference, it throws a `std::bad_cast` exception.

#### 3. `const_cast<T>(expression)`
- What it does: Adds or removes the `const` or `volatile` qualifier from a variable.

- Safety: The only C++ cast that can alter constness.

#### 4. `reinterpret_cast<T>(expression)`
- What it does: Low-level bit reinterpretation. Converts a pointer to an integer, or a pointer of one type to a completely unrelated pointer type.

- Safety: Highly dangerous. Implementation-dependent and prone to undefined behavior if misused.

## 📋 Exercises & Core Concepts

### Exercise 00: Conversion of scalar types
`ScalarConverter` must be a **non-instantiable** class: all constructors and the destructor are private, and it only exposes a static `convert` method.

#### Design Choice: Non-Instantiable Utility Class
The `ScalarConverter` class is designed as a **pure utility class**. It contains no instance variables and does not manage any object state; its sole purpose is to provide a conversion algorithm via a static interface.
1. **Preventing Instantiation (Non-Instantiable):**
   * All constructors (default, copy) and the destructor are explicitly declared as `private`, along with the assignment operator.
   * If a user or another class attempts to instantiate it (e.g., `ScalarConverter c;`), the compiler will immediately throw a compilation error, enforcing its design as a pure static toolbox.

2. **Static-Only Interface:**
   * The outside world can only interact with the class through its sole public static entry point: `ScalarConverter::convert(av[1]);`
    * This guarantees that no objects are unnecessarily created on the stack/heap, keeping the class lightweight, stateless, and entirely safe from memory leaks.

#### Edge Cases: Pseudo-Literals & Non-Displayable Characters
When implementing `ScalarConverter`, handling edge cases properly is crucial to prevent undefined behavior and formatting issues.

1. Pseudo-Literals (`nan`, `inf`)

    Pseudo-literals represent mathematical extremes and special floating-point states. 
    * **The Danger:** Blindly casting special floating-point values like `nan` or `inf` to `int` or `char` using `static_cast` results in **Undefined Behavior**, ranging from unpredictable junk numbers to segmentation faults or program crashes.
    * **Supported Types:**
        * `nan` / `nanf` — Not a Number (e.g., resulting from $0.0 / 0.0$)
        * `+inf` / `+inff` — Positive Infinity (e.g., resulting from $1.0 / 0.0$)
        * `-inf` / `-inff` — Negative Infinity (e.g., resulting from $-1.0 / 0.0$)
    * **Handling Logic:**
        * `char`: `impossible`
        * `int`: `impossible`
        * `float` / `double`: Print the literal as-is (e.g., `nanf`, `+inf`)

2. Non-Displayable Characters

    Not every valid byte in the ASCII table can be safely printed to a terminal screen.
    * **Definition:** Characters that fall outside the standard printable ASCII range (`32` to `126`), which includes early control characters (`0` to `31`) and `127` (`DEL`).
    * **Handling Logic:**
        * We verify that the value lies within the valid ASCII range (`0` to `127`) and is not `NaN`.
        * We use `std::isprint()` from `<cctype>` to check if the character is renderable.
        * If it is a valid ASCII value but non-printable (e.g., ASCII `10` for newline `\n`), our program safely outputs `Non displayable` instead of disrupting terminal formatting.

💡 A **utility class** is a class in object-oriented programming that acts as a container for common, reusable functions and constants rather than representing a real-world object or entity. 

💡 A utility class is always a non-instantiable class, not the reverse.
- **Non-Instantiable Class** (The *Broad* Category): This is any class that prevents you from creating an object instance using the `new` keyword. Programmers usually enforce this by giving the class a private constructor or declaring it `abstract`.
- **Utility Class** (The *Specific* Type): This is a stateless helper class that contains only `static` methods and constants. Because it holds no instance data, creating an object of it makes no sense, so it is deliberately made non-instantiable.

💡 Use `static_cast` because it provides compile-time type checking, making our intent explicit and safer. Unlike C-style casts (e.g. `(int)d`), which blindly force a conversion anywhere, `static_cast` prevents accidental and dangerous low-level re-interpretations, aligning with modern C++ best practices.”

#### 🛠️ Technical Justification

1. **Why use `std::strtod` instead of `std::atoi` or `atof`?**

Functions like `atoi` or `atof` provide no error reporting, fail silently on invalid inputs, and don't tell you where the parsing stopped. `std::strtod` gives us an `end` pointer (`char** end`), which is crucial here. It allows us to safely check for trailing invalid characters (like `"42abc"`) and correctly handle the `'f'` suffix at the end of float literals (e.g., `"42.0f"`).

### Exercise 01: Serialization
Create a non-instantiable class called `Serializer` that converts a pointer to a data structure into an unsigned integer (`uintptr_t`) and back without losing data.


#### 🛠️ Core Concepts & Technical Justification

1. **Why `reinterpret_cast`?**

`reinterpret_cast` performs a low-level bit reinterpretation, allowing us to treat a memory address as a raw integer and vice versa.

* Unlike `static_cast` (which is restricted to types with a logical relationship, such as numeric conversions or related class hierarchies), `reinterpret_cast` has no such constraints.

* It tells the compiler: "Ignore type safety rules and treat the raw bits of this memory directly as another type!" This is the power of low-level bit reinterpretation.


2. **Why `uintptr_t`?**

We use `uintptr_t` instead of standard integer types because it is **guaranteed by the C++ standard to be large enough to hold a pointer** across different architectures (both 32-bit and 64-bit), preventing bit truncation during the round-trip.

* Architecture Discrepancy (32-bit vs. 64-bit):

    * On 32-bit systems, pointers are 4 bytes.

    * On modern 64-bit systems, pointers are 8 bytes.

* **The Risk of Standard Integers:** If you use a normal `int` (typically 4 bytes) on a 64-bit machine, converting an 8-byte pointer will cause bit truncation, discarding the upper 32 bits of the memory address. This loss of information leads directly to a segmentation fault or deserialization crash. `uintptr_t` dynamically scales to match the system's pointer size.

💡 `static_cast` can only be used for type conversions with logical relationships (such as integer-to-floating-points, or class pointer conversions with inheritance relationships).

💡 `reinterpret_cast` is inherently unsafe. While using `uintptr_t` guarantees that we won't suffer from bit truncation across 32-bit and 64-bit architectures, `reinterpret_cast` itself performs zero type or alignment safety checks. If you cast a pointer to an unrelated type with stricter memory alignment requirements, or dereference a misaligned pointer, it still results in **undefined behavior**.


### Exercise 02: Identify real type
Create a base class `Base` and three derived classes `A`, `B`, and `C`. Write a function that randomly instantiates one of them, and two identification functions (`identify(Base* p)` & `identify(Base& p)`) without using `typeid`.
#### 🛠️ Core Concepts & Technical Justification

1. **Why must `Base` have a virtual destructor?**

Crucial Rule: `Base` must have at least one virtual function (polymophic classes) for `dynamic_cast` to work at runtime.

* RTTI & vtable: `dynamic_cast` relies on RTTI (Run-Time Type Information). When a class has virtual functions, the compiler generates a virtual function table (`vtable`) and inserts a hidden pointer (`vptr`) into the object.

* This structure stores runtime type data. Without any virtual functions, the class is non-polymorphic, and the compiler will throw a compilation error when attempting a `dynamic_cast`.

💡 Bonus: A virtual destructor also ensures proper memory deallocation of derived objects when deleted via a `Base*` pointer, preventing memory leaks.

2. **Pointer vs. Reference Behavior on Failure**

When a `dynamic_cast` fails, its behavior depends entirely on whether you are casting a pointer or a reference:

* Pointer `dynamic_cast<T*>(p)`:

    - Failure Behavior: Gracefully returns `NULL`.

    - Handling: Safe to check directly using a conditional statement (`if (dynamic_cast<A*>(p))`).

* Reference `dynamic_cast<T&>(p)`:

    - **Failure Behavior:** Since C++ references cannot be null, a failed reference cast cannot return `NULL`. Instead, it throws a `std::bad_cast` exception.

    - **Handling:** Must be wrapped in a `try-catch` block to intercept the failure and attempt the next type.


