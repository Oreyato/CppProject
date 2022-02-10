#pragma once
#include <iostream>

struct UniqueState
{
    std::string owner_;
    std::string plates_;

    UniqueState(const std::string& owner, const std::string& plates)
        : owner_(owner), plates_(plates)
    {
    }

    friend std::ostream& operator<<(std::ostream& os, const UniqueState& us)
    {
        return os << "[ " << us.owner_ << " , " << us.plates_ << " ]";
    }
};