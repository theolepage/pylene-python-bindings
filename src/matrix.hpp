#pragma once

class Matrix {
public:
    Matrix(ssize_t rows, ssize_t cols) : m_rows(rows), m_cols(cols) {
        m_data = new float[(size_t) (rows*cols)];
        memset(m_data, 0, sizeof(float) * (size_t) (rows * cols));
    }

    ~Matrix() {
        delete[] m_data;
    }

    float *data() { return m_data; }
    ssize_t rows() const { return m_rows; }
    ssize_t cols() const { return m_cols; }
private:
    ssize_t m_rows;
    ssize_t m_cols;
    float *m_data;
};