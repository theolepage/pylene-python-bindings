#pragma once

#include "../include/pln/core/se.hpp"
#include "../include/pln/core/my_disc.hpp"
#include "../include/pln/core/my_rectangle.hpp"
#include "../include/pln/core/my_mask.hpp"

class py_se
{
public:
    py_se(std::shared_ptr<pln::se_t> se)
        : se_(se)
    {}

    static py_se create_disc(int radius)
    {
        return py_se(std::make_shared<pln::my_disc>(pln::my_disc(radius)));
    }

    static py_se create_rect(int width, int height)
    {
        return py_se(std::make_shared<pln::my_rectangle>(pln::my_rectangle(width, height)));
    }

    static py_se create_mask(py::array_t<int, py_array_params>)
    {
        // FIXME: Converting py::array_t to initializer_list seems impossible.
        return py_se(std::make_shared<pln::my_mask>(pln::my_mask({})));
    }

    std::shared_ptr<pln::se_t> get_se()
    {
        return se_;
    }

private:
    std::shared_ptr<pln::se_t> se_;
};