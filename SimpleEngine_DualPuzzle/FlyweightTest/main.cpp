#include <iostream>

/**
 * Flyweight Design Pattern
 *
 * Intent: Lets you fit more objects into the available amount of RAM by sharing
 * common parts of state between multiple objects, instead of keeping all of the
 * data in each object.
 */

//#include "SharedState.h"
//#include "UniqueState.h"

/**
 * The Flyweight stores a common portion of the state (also called intrinsic
 * state) that belongs to multiple real business entities. The Flyweight accepts
 * the rest of the state (extrinsic state, unique for each entity) via its
 * method parameters.
 */

#include "Flyweight.h"

/**
 * The Flyweight Factory creates and manages the Flyweight objects. It ensures
 * that flyweights are shared correctly. When the client requests a flyweight,
 * the factory either returns an existing instance or creates a new one, if it
 * doesn't exist yet.
 */

#include "FlyweightFactory.h"

/**
 * The client code usually creates a bunch of pre-populated flyweights in the
 * initialization stage of the application.
 */

 // ...
void AddCarToPoliceDatabase(
    FlyweightFactory& ff, const std::string& plates, const std::string& owner,
    const std::string& brand, const std::string& model, const std::string& color)
{
    std::cout << "\nClient: Adding a car to database.\n";
    const Flyweight& flyweight = ff.GetFlyweight({ brand, model, color });
    // The client code either stores or calculates extrinsic state and passes it
    // to the flyweight's methods.
    flyweight.Operation({ owner, plates });
}

int main()
{
    FlyweightFactory* factory = new FlyweightFactory({ {"Chevrolet", "Camaro2018", "pink"}, {"Mercedes Benz", "C300", "black"}, {"Mercedes Benz", "C500", "red"}, {"BMW", "M5", "red"}, {"BMW", "X6", "white"} });
    factory->ListFlyweights();

    AddCarToPoliceDatabase(*factory,
        "CL234IR",
        "James Doe",
        "BMW",
        "M5",
        "red");

    AddCarToPoliceDatabase(*factory,
        "CL234IR",
        "James Doe",
        "BMW",
        "X1",
        "red");
    factory->ListFlyweights();
    delete factory;

    return 0;
}