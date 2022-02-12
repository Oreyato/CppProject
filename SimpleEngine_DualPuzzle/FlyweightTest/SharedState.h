#pragma once
#include <iostream>

// = intrinsic state
// ^ felt inversed, because it is "Shared" BUT
//      intrinsinc because it lives inside the object, it can not be altered "from the outside"
//      IMMUTABLE, repeated
//      context-free

struct SharedState
{
    // Common things between cars:
    std::string brand_;
    std::string model_;
    std::string color_;

    SharedState(const std::string& brand, const std::string& model, const std::string& color)
        : brand_(brand), model_(model), color_(color)
    {
    }

    // Custom way to display infos
    friend std::ostream& operator<<(std::ostream& os, const SharedState& ss)
    {
        return os << "[ " << ss.brand_ << " , " << ss.model_ << " , " << ss.color_ << " ]";
    }
};