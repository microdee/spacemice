#pragma once

#include <tuple>

namespace spacemice
{
    inline std::tuple<int, int, int> version() { return {0, 1, 0}; }
}