import numpy as np
import pylene as pln
import unittest
import matplotlib.pyplot as plt
from skimage import data

def open_image(image_path):
    image = plt.imread(image_path) * 255
    return image.astype(np.uint8)

def mse(imgA, imgB):
    err = np.sum((imgA.astype("float") - imgB.astype("float")) ** 2)
    err /= float(imgA.shape[0] * imgA.shape[1])
    print(err)
    return err

def are_same(out, ref, debug=False):
    if not np.array_equal(out.shape, ref.shape):
        print("Shape Error: out image does not have the same shape as ref")
        return False
    mse_res = mse(out, ref)
    if mse_res > 0:
        print(f"MSE : {mse_res}")
        if debug:
            f = plt.figure()
            f.add_subplot(1,2, 1)
            plt.imshow(ref)
            f.add_subplot(1,2, 2)
            plt.imshow(out)
            plt.show(block=True)
        return False
    return True

lena = open_image("lena.png")
lena_gray = open_image("lena_gray.png")

class TestDilation(unittest.TestCase):

    def test_lena_disc5(self):
        ref_dilation_disc5 = open_image('lena_dilation_disc5.png')
        out_dilation_disc5 = pln.morpho.dilation(lena, pln.se.disc(5))
        self.assertTrue(are_same(out_dilation_disc5, ref_dilation_disc5))

    def test_lena_rect20(self):
        ref_dilation_rect20 = open_image('lena_dilation_rect20-20.png')
        out_dilation_rect20 = pln.morpho.dilation(lena, pln.se.rectangle(width=20, height=20))
        self.assertTrue(are_same(out_dilation_rect20, ref_dilation_rect20))

class TestErosion(unittest.TestCase):

    def test_lena_disc19(self):
        ref_erosion_disc19 = open_image('lena_erosion_disc19.png')
        out_erosion_disc19 = pln.morpho.erosion(lena, pln.se.disc(19))
        self.assertTrue(are_same(out_erosion_disc19, ref_erosion_disc19))

    def test_lena_rect1510(self):
        ref_erosion_rect1510 = open_image('lena_erosion_rect15-10.png')
        out_erosion_rect1510 = pln.morpho.erosion(lena, pln.se.rectangle(width=15, height=10))
        self.assertTrue(are_same(out_erosion_rect1510, ref_erosion_rect1510))

class TestClosing(unittest.TestCase):

    def test_lena_gray_disc2(self):
        ref_closing_disc2 = open_image('lena_gray_closing_disc2.png')
        out_closing_disc2 = pln.morpho.closing(lena, pln.se.disc(2))
        self.assertTrue(are_same(out_closing_disc2, ref_closing_disc2))

    def test_lena_gray_rect0531(self):
        ref_closing_rect0531 = open_image('lena_gray_closing_rect5-31.png')
        out_closing_rect0531 = pln.morpho.closing(lena_gray, pln.se.rectangle(width=5, height=31))
        self.assertTrue(are_same(out_closing_rect0531, ref_closing_rect0531))

class Testopening(unittest.TestCase):

    def test_lena_disc10(self):
        ref_opening_disc10 = open_image('lena_opening_disc10.png')
        out_opening_disc10 = pln.morpho.opening(lena, pln.se.disc(10))
        self.assertTrue(are_same(out_opening_disc10, ref_opening_disc10))

    def test_lena_rect0519(self):
        ref_opening_rect0519 = open_image('lena_opening_rect5-19.png')
        out_opening_rect0519 = pln.morpho.opening(lena, pln.se.rectangle(width=5, height=19))
        self.assertTrue(are_same(out_opening_rect0519, ref_opening_rect0519))

class TestMSE(unittest.TestCase):

    def test_lena_disc10vsdisc11(self):
        ref_opening_disc10 = open_image('lena_opening_disc10.png')
        out_opening_disc11 = pln.morpho.opening(lena, pln.se.disc(11))
        self.assertFalse(are_same(out_opening_disc11, ref_opening_disc10))

if __name__ == '__main__':
    unittest.main()