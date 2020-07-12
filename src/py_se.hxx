#pragma once

class se_t
{

};

class my_disc : public se_t
{
public:
    my_disc(int radius)
        : radius_(radius)
    {}
private:
    int radius_;
};

class my_rect : public se_t
{
public:
    my_rect(int width, int height)
        : width_(width), height_(height)
    {}
private:
    int width_;
    int height_;
};

class my_mask : public se_t
{
public:
    my_mask(std::initializer_list<std::initializer_list<int>> l)
        : l_(l)
    {}
private:
    std::initializer_list<std::initializer_list<int>> l_;
};

class py_se
{
public:
    py_se(se_t se)
        : se_(se)
    {}

    static py_se create_disc(int radius)
    {
        return py_se(my_disc(radius));
    }

    static py_se create_rect(int width, int height)
    {
        return py_se(my_rect(width, height));
    }

    static py_se create_mask(py::array_t<int, py_array_params>)
    {
        return py_se(my_mask({}));
    }

    se_t get_se() const
    {
        return se_;
    }

private:
    se_t se_;
};