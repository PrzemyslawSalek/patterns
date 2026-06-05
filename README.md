# Design Patterns in C++

A complete implementation of all 23 classic **Gang of Four** design patterns in C++, built as part of a 23-day software engineering challenge — one pattern per day.

Each pattern directory contains:
- `main.cpp` — working C++ implementation
- `*.uml` — UML diagram source
- `*.png` — UML class diagram

## Patterns

### Creational
| Pattern | Description |
|---|---|
| [Abstract Factory](Abstract%20Factory/) | Creates families of related objects without specifying concrete classes |
| [Builder](Builder/) | Constructs complex objects step by step |
| [Factory Method](Factory%20method/) | Defines an interface for creating objects, letting subclasses decide the class |
| [Prototype](Prototype/) | Creates new objects by cloning an existing instance |
| [Singleton](Singleton/) | Ensures a class has only one instance with a global access point |

### Structural
| Pattern | Description |
|---|---|
| [Adapter](Adapter/) | Converts an interface into another interface clients expect |
| [Bridge](Bridge/) | Decouples an abstraction from its implementation |
| [Composite](Composite/) | Composes objects into tree structures to represent part-whole hierarchies |
| [Decorator](Decorator/) | Attaches additional responsibilities to an object dynamically |
| [Facade](Facade/) | Provides a simplified interface to a complex subsystem |
| [Flyweight](Flyweight/) | Uses sharing to support large numbers of fine-grained objects efficiently |
| [Proxy](Proxy/) | Provides a surrogate or placeholder for another object |

### Behavioral
| Pattern | Description |
|---|---|
| [Chain of Responsibility](Chain%20of%20responsibility/) | Passes a request along a chain of handlers |
| [Command](Command/) | Encapsulates a request as an object |
| [Interpreter](Interpreter/) | Defines a grammar and an interpreter for a language |
| [Iterator](Iterator/) | Provides a way to sequentially access elements of a collection |
| [Mediator](Mediator/) | Defines an object that encapsulates how objects interact |
| [Memento](Memento/) | Captures and restores an object's internal state |
| [Observer](Observer/) | Notifies multiple objects about state changes in another object |
| [State](State/) | Allows an object to alter its behavior when its internal state changes |
| [Strategy](Strategy/) | Defines a family of algorithms and makes them interchangeable |
| [Template Method](Template%20Method/) | Defines the skeleton of an algorithm, deferring some steps to subclasses |
| [Visitor](Visitor/) | Lets you add further operations to objects without modifying them |

## About the Challenge

This project was created during a 23-day design patterns challenge. Each day covered one pattern: studying the concept, modeling it in UML, and implementing it in C++. The goal was to gain hands-on familiarity with the full GoF catalog.

## Tech Stack

- **Language:** C++
- **Diagrams:** UML class diagrams
