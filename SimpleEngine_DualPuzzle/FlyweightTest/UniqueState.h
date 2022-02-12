#pragma once
#include <iostream>

// = extrinsic state
// MUTABLE

struct UniqueState
{
    // unique things
    std::string owner_;
    std::string plates_;

    UniqueState(const std::string& owner, const std::string& plates)
        : owner_(owner), plates_(plates)
    {
    }

    // Custom way to display infos
    friend std::ostream& operator<<(std::ostream& os, const UniqueState& us)
    {
        return os << "[ " << us.owner_ << " , " << us.plates_ << " ]";
    }
};