# C++ 04
## ex00: Polymorphism
```text
Animal / Dog / Cat
    ↓
inheritance
virtual function
polymorphism
virtual destructor
```
- `virtual` allows the call to be resolved according to the actual type of the object rather than only the static type of the pointer.
- `WrongAnimal` without `virtual` doesn't provide the correct animal sound accordingly.
- Since we may delete a derived object through a base-class pointer, the base destructor must be virtual.

## ex01: Brain & Deep Copy
```text
Animal / Dog / Cat
    +
  Brain
    ↓
dynamic allocation
deep copy
OCF
memory management
```
### Dynamic Ownership
Because `Dog` and `Cat` allocate `Brain` on the heap via `new`, `Dog` and `Cat` take dynamic ownership of that Brain instance. Ownership means `Dog` or `Cat` is strictly responsible for managing its lifecycle from creation to destruction.

### Destructor Cleanup
To enforce zero memory leaks, every resource allocated with `new` in the constructor must be freed in the destructor. In `~Dog()` and in `~Cat()`, executing `delete _brain` guarantees that the heap object is deallocated whenever a Dog dies.

### Explicit Resource Control
If a class manages a raw resource, relying on compiler-generated copy logic causes shallow copies, leading to shared state and double-free crashes. By adhering to the Rule of Three, we explicitly implement deep copies so that each object maintains its own independent resource.

```text
Shallow Copy (Default - DANGEROUS):
 Dog A [_brain] ────┐
                    ├───> [ Heap: Brain Object ] (Double Free on delete!)
 Dog B [_brain] ────┘

 Deep Copy (Explicit - SAFE):
 Dog A [_brain] ─────────> [ Heap: Brain A ]
 Dog B [_brain] ─────────> [ Heap: Brain B ] (Independent & safe)
```

## ex02
```text
AAnimal / Dog / Cat
    ↓
abstract class
pure virtual function
polymorphism
```


## ex03
```text
AMateria
 ├── Ice
 └── Cure

ICharacter
 └── Character

IMateriaSource
 └── MateriaSource

    ↓
interfaces
abstract classes
polymorphism
clone()
deep copy
ownership
```