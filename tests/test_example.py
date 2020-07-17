import numpy as np
import pylene as pln
import unittest
import matplotlib.pyplot as plt
from skimage import data

def mse(imgA, imgB):
    err = np.sum((imgA.astype("float") - imgB.astype("float")) ** 2)
    err /= float(imgA.shape[0] * imgA.shape[1])
    print(err)
    return err

lena = plt.imread('lena.png') * 255
lena = lena.astype(np.uint8)
A_dilation_disc5 = plt.imread('lena_dilation_disc5.png') * 255
A_dilation_rect20 = plt.imread('lena_dilation_rect20-20.png') * 255

B_dilation_disc5 = pln.morpho.dilation(lena, pln.se.disc(5))
B_dilation_rect20 = pln.morpho.dilation(lena, pln.se.rectangle(width=20, height=20))

print(B_dilation_disc5)
plt.imshow(A_dilation_disc5.astype(np.uint8))
plt.show()

plt.imshow(B_dilation_disc5)
plt.show()

class TestDilation(unittest.TestCase):
    # def test_lena_disc_t(test):
    #     ref = 
    #     out = 
    #     compare

    def test_shape(self):
        self.assertEqual(lena.shape, A_dilation_disc5.shape)
        self.assertEqual(A_dilation_disc5.shape, B_dilation_disc5.shape)
        self.assertEqual(A_dilation_rect20.shape, B_dilation_rect20.shape)

    def test_dtype(self):
        self.assertEqual(lena.dtype, np.uint8)

    def test_MSE(self):
        self.assertLessEqual(mse(A_dilation_disc5, B_dilation_disc5), 0)
        self.assertLessEqual(mse(A_dilation_rect20, B_dilation_rect20), 0)


if __name__ == '__main__':
    unittest.main()