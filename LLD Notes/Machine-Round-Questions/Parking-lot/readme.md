## Question:

### What are Functional Requirements?

Functional requirements are specific actions or tasks that a system or product must be able to perform. They describe what the system should do and how it should behave, defining the functionalities and features that the system must have to meet the end-users needs.

#### Functional Requirements for Parking Lot

The following is a list of functional requirements for a parking lot system:

- The parking lot system should be able to park cars, bikes, and handicapped vehicles.

- The system should be able to calculate the cost of parking for each type of vehicle.

- The system should be able to keep track of the time a vehicle is parked.

- The system should be able to remove a vehicle from a parking spot.

- The system should be able to check the availability of parking spots and handicapped spots on a specific floor.

- The system should be able to calculate the number of hours a vehicle has been parked.

### What are Non-Functional Requirements?

Non-functional requirements are constraints, or quality attributes that a system must meet, such as performance, security, usability, and maintainability. They describe how well the system should perform, not what it should do. Non-functional requirements specify the system's desired performance, security, usability, and other characteristics.

#### Non-Functional Requirements for Parking Lot

The following is a list of functional requirements for a parking lot system:

- The parking lot system should handle many vehicles and parking spots.

- The system should be efficient and respond quickly to user requests.

- The system should be secure and prevent unauthorized access to the parking spots.

- The system should be user-friendly and easy to understand for the users.

- The system should have a well-designed interface to make it easy to use.

- The system should be easily extensible and maintainable for future updates and changes.

- The system should be tested and debugged thoroughly to ensure it is stable and reliable.

---

Here is a summary of where the different object-oriented principles and SOLID principles are used in the provided code:

### Object-Oriented Principles

- Inheritance: The Car, Bike, and HandicappedVehicle classes inherit from the Vehicle class.

- Polymorphism: The Vehicle class has a virtual function calculateCost(double hours) which is overridden in the derived classes CarPayment, BikePayment, and HandicappedPayment.

- Encapsulation: The member variables and functions in the classes are all marked as either private or protected so that they can only be accessed by the class itself or derived classes.

### SOLID Principles

- Single Responsibility Principle (SRP): Each class has a single responsibility; for example, the Payment class is responsible for calculating the cost of parking, the Vehicle class is responsible for storing information about the parked vehicle, and the ParkingLot class is responsible for managing the parking spots.

- Open/Closed Principle (OCP): The Payment class is open for extension but closed for modification, meaning that new payment types can be added by creating new classes that inherit from Payment, but the Payment class itself does not need to be modified.

- Liskov Substitution Principle (LSP): The derived classes CarPayment, BikePayment, and HandicappedPayment can be used interchangeably with the base class Payment without affecting the correctness of the program.

- Interface Segregation Principle (ISP): The Vehicle class only requires the methods it needs from the Payment class and does not impose unnecessary methods.

- Dependency Inversion Principle (DIP): The Vehicle class depends on the interface of the Payment class rather than the implementation, allowing for flexibility in the payment system.\

It's worth noting that this is a simplified example, and in a real-world scenario, it might be more complex to implement all of these principles.
