import numpy as np
import pylene as pln

def test_convert(arr):
    res = pln.morpho.dilation(arr, pln.se.disc(4))
    print(np.array_equal(res, arr), arr.dtype, res.dtype)

test_convert(np.array([[17, 8], [9, 1]]))
test_convert(np.array([[17, 8], [9, 1]]).astype(np.uint8))
test_convert(np.arange(10*10*10*10).reshape((10, 10, 10, 10)).astype(np.double))