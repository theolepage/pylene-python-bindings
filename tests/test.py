import numpy as np
import pylene as pln

def test_convert_simple():
    arr = np.array([[17, 8], [9, 1]])
    # print(arr, arr.shape, arr.dtype)
    res = pln.morpho.dilation(arr, pln.se.disc(4))
    # print(res, res.shape, res.dtype)
    print(np.array_equal(res, arr))

def test_convert_hard():
    arr = np.arange(10 * 10 * 10 * 10).reshape((10, 10, 10, 10))
    res = pln.morpho.dilation(arr, pln.se.disc(4))
    print(np.array_equal(res, arr))

test_convert_simple()
test_convert_hard()
