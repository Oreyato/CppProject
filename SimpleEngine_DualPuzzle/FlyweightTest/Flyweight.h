#pragma once
#include "SharedState.h"
#include "UniqueState.h"

// Because the Flyweight object can be used in different contexts, 
// we have to make sure that its state can't be modified
//      initialize its state just once
//      shouldn't expose setters or ways to modify it

class Flyweight
{
private:
    // Stores the INTRINSIC state ONLY, it just accepts the rest 
    SharedState* shared_state_;

public:
    Flyweight(const SharedState* shared_state) : shared_state_(new SharedState(*shared_state))
    {
    }
    Flyweight(const Flyweight& other) : shared_state_(new SharedState(*other.shared_state_))
    {
    }
    ~Flyweight()
    {
        delete shared_state_;
    }
    SharedState* shared_state() const
    {
        return shared_state_;
    }
    void Operation(const UniqueState& unique_state) const
    {
        std::cout << "Flyweight: Displaying shared (" << *shared_state_ << ") and unique (" << unique_state << ") state.\n";
    }
};