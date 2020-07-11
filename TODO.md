#include <pybind11/pybind11.h>

class Matrix {
public:
    Matrix(ssize_t rows, ssize_t cols) : m_rows(rows), m_cols(cols) {
        print_created(this, std::to_string(m_rows) + "x" + std::to_string(m_cols) + " matrix");
        m_data = new float[(size_t) (rows*cols)];
        memset(m_data, 0, sizeof(float) * (size_t) (rows * cols));
    }

    Matrix(const Matrix &s) : m_rows(s.m_rows), m_cols(s.m_cols) {
        print_copy_created(this, std::to_string(m_rows) + "x" + std::to_string(m_cols) + " matrix");
        m_data = new float[(size_t) (m_rows * m_cols)];
        memcpy(m_data, s.m_data, sizeof(float) * (size_t) (m_rows * m_cols));
    }

    Matrix(Matrix &&s) : m_rows(s.m_rows), m_cols(s.m_cols), m_data(s.m_data) {
        print_move_created(this);
        s.m_rows = 0;
        s.m_cols = 0;
        s.m_data = nullptr;
    }

    ~Matrix() {
        print_destroyed(this, std::to_string(m_rows) + "x" + std::to_string(m_cols) + " matrix");
        delete[] m_data;
    }

    Matrix &operator=(const Matrix &s) {
        print_copy_assigned(this, std::to_string(m_rows) + "x" + std::to_string(m_cols) + " matrix");
        delete[] m_data;
        m_rows = s.m_rows;
        m_cols = s.m_cols;
        m_data = new float[(size_t) (m_rows * m_cols)];
        memcpy(m_data, s.m_data, sizeof(float) * (size_t) (m_rows * m_cols));
        return *this;
    }

    Matrix &operator=(Matrix &&s) {
        print_move_assigned(this, std::to_string(m_rows) + "x" + std::to_string(m_cols) + " matrix");
        if (&s != this) {
            delete[] m_data;
            m_rows = s.m_rows; m_cols = s.m_cols; m_data = s.m_data;
            s.m_rows = 0; s.m_cols = 0; s.m_data = nullptr;
        }
        return *this;
    }

    float operator()(ssize_t i, ssize_t j) const {
        return m_data[(size_t) (i*m_cols + j)];
    }

    float &operator()(ssize_t i, ssize_t j) {
        return m_data[(size_t) (i*m_cols + j)];
    }

    float *data() { return m_data; }

    ssize_t rows() const { return m_rows; }
    ssize_t cols() const { return m_cols; }
private:
    ssize_t m_rows;
    ssize_t m_cols;
    float *m_data;
};

py::class_<Matrix>(m, "Matrix", py::buffer_protocol())
    // Construct from a buffer, python -> c++
    .def(py::init([](py::buffer const b)
    {
        py::buffer_info info = b.request();
        if (info.format != py::format_descriptor<float>::format() || info.ndim != 2)
            throw std::runtime_error("Incompatible buffer format!");

        auto v = new Matrix(info.shape[0], info.shape[1]);
        memcpy(v->data(), info.ptr, sizeof(float) * (size_t) (v->rows() * v->cols()));
        return v;
    }))

    python3
    import pylene
    arr = [0, 1, 2]
    pylene.Matrix(arr)


    // Simple getters
    .def("rows", &Matrix::rows)
    .def("cols", &Matrix::cols)

    // Provide buffer access, c++ -> python
    .def_buffer([](Matrix &m) -> py::buffer_info
    {
        return py::buffer_info(
            // Pointer to buffer
            m.data(),

            // Buffer dimensions
            { m.rows(), m.cols() },

            // Strides (in bytes) for each index
            { sizeof(float) * size_t(m.cols()), sizeof(float) }
        );
    });


// MLN
// - number dim
// - size of each dim
// - strides
// - ptr on data (raw)        buffer() -> T

// ndbuffer_image ctor (), how to pass