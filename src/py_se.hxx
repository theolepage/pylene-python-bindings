#pragma once

#include "../include/pln/core/se.hpp"
#include "../include/pln/core/pln_disc.hpp"
#include "../include/pln/core/pln_rect2d.hpp"
#include "../include/pln/core/pln_mask2d.hpp"

class py_se
{
public:
    py_se(std::shared_ptr<pln::se_t> se)
        : se_(se)
    {}

    static py_se create_disc(int radius)
    {
        return py_se(std::make_shared<pln::pln_disc>(radius));
    }

    static py_se create_rect(int width, int height)
    {
        return py_se(std::make_shared<pln::pln_rect2d>(width, height));
    }

    static py_se create_mask(py::array_t<int, pyarr_params>)
    {
        // FIXME: Converting py::array_t to initializer_list seems impossible.
        std::initializer_list<std::initializer_list<int>> l = { { 0 } };
        return py_se(std::make_shared<pln::pln_mask2d>(l));
    }

    std::shared_ptr<pln::se_t> get_se()
    {
        return se_;
    }

private:
    std::shared_ptr<pln::se_t> se_;
};