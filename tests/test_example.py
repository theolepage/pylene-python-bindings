import numpy as np
import pylene as pln
import unittest

def test_convert(arr):
    res = pln.morpho.dilation(arr, pln.se.disc(4))
    print(np.array_equal(res, arr), arr.dtype, res.dtype)

#test_convert(np.array([[17, 8], [9, 1]]))
#test_convert(np.array([[17, 8], [9, 1]]).astype(np.uint8))
#test_convert(np.arange(10*10*10*10).reshape((10, 10, 10, 10)).astype(np.double))

class TestStringMethods(unittest.TestCase):

    def test_upper(self):
        self.assertEqual('foo'.upper(), 'FOO')

    def test_isupper(self):
        self.assertTrue('FOO'.isupper())
        self.assertFalse('Foo'.isupper())

    def test_split(self):
        s = 'hello world'
        self.assertEqual(s.split(), ['hello', 'world'])
        # check that s.split fails when the separator is not a string
        with self.assertRaises(TypeError):
            s.split(2)

if __name__ == '__main__':
    unittest.main()