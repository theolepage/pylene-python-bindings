import numpy as np
import pylene as pln
import unittest
import matplotlib.pyplot as plt

ALWAYS_SHOW_IMAGES = False

def open_image(image_path):
    image = plt.imread(image_path) * 255
    return image.astype(np.uint8)

def mse(image_a, image_b):
    err = np.sum((image_a.astype("float") - image_b.astype("float")) ** 2)
    err /= float(image_a.shape[0] * image_a.shape[1])
    return err

lena = open_image("lena.png")
lena_gray = open_image("lena_gray.png")

class ImagesEqualsAssertions:
    def assertImagesEquals(self, actual, expected, negative=False):
        if not np.array_equal(actual.shape, expected.shape):
            raise AssertionError("Shape error: out image does not have the same shape as ref")

        if not actual.dtype == expected.dtype:
            raise AssertionError("Type error: out image does not have the same type as ref")

        mse_res = mse(actual, expected)

        if ALWAYS_SHOW_IMAGES or (not negative and not mse_res == 0):
            f = plt.figure()
            plt.box(False)

            # Title
            fig = plt.text(0, 0, self.id() + "\n" + 'Error: {}'.format(mse_res), fontsize=12)
            fig.axes.get_xaxis().set_visible(False)
            fig.axes.get_yaxis().set_visible(False)

            # Show output image
            actual_plot = f.add_subplot(1, 2, 1)
            plt.imshow(actual)
            actual_plot.set_xlabel('Actual')
            actual_plot.axes.xaxis.set_label_position('top')

            # Show expected image
            ref_plot = f.add_subplot(1, 2, 2)
            plt.imshow(expected)
            ref_plot.set_xlabel('Expected')
            ref_plot.axes.xaxis.set_label_position('top')

            plt.show(block=True)

        if not mse_res == 0:
            raise AssertionError("Output image is different from ref (error: {})".format(mse_res))

    def assertImagesNotEquals(self, actual, expected):
        try:
            self.assertImagesEquals(actual, expected, True)
        except AssertionError:
            pass
        else:
            raise AssertionError("Output image is equal to ref")

class TestDilation(unittest.TestCase, ImagesEqualsAssertions):

    def test_lena_disc5(self):
        ref_dilation_disc5 = open_image('lena_dilation_disc5.png')
        out_dilation_disc5 = pln.morpho.dilation(lena, pln.se.disc(5))
        self.assertImagesEquals(out_dilation_disc5, ref_dilation_disc5)

    def test_lena_rect20(self):
        ref_dilation_rect20 = open_image('lena_dilation_rect20-20.png')
        out_dilation_rect20 = pln.morpho.dilation(lena, pln.se.rectangle(width=20, height=20))
        self.assertImagesEquals(out_dilation_rect20, ref_dilation_rect20)

class TestErosion(unittest.TestCase, ImagesEqualsAssertions):

    def test_lena_disc19(self):
        ref_erosion_disc19 = open_image('lena_erosion_disc19.png')
        out_erosion_disc19 = pln.morpho.erosion(lena, pln.se.disc(19))
        self.assertImagesEquals(out_erosion_disc19, ref_erosion_disc19)

    def test_lena_rect1510(self):
        ref_erosion_rect1510 = open_image('lena_erosion_rect15-10.png')
        out_erosion_rect1510 = pln.morpho.erosion(lena, pln.se.rectangle(width=15, height=10))
        self.assertImagesEquals(out_erosion_rect1510, ref_erosion_rect1510)

class TestClosing(unittest.TestCase, ImagesEqualsAssertions):

    def test_lena_gray_disc2(self):
        ref_closing_disc2 = open_image('lena_gray_closing_disc2.png')
        out_closing_disc2 = pln.morpho.closing(lena_gray, pln.se.disc(2))
        self.assertImagesEquals(out_closing_disc2, ref_closing_disc2)

    def test_lena_gray_rect0531(self):
        ref_closing_rect0531 = open_image('lena_gray_closing_rect5-31.png')
        out_closing_rect0531 = pln.morpho.closing(lena_gray, pln.se.rectangle(width=5, height=31))
        self.assertImagesEquals(out_closing_rect0531, ref_closing_rect0531)

class TestOpening(unittest.TestCase, ImagesEqualsAssertions):

    def test_lena_disc10(self):
        ref_opening_disc10 = open_image('lena_opening_disc10.png')
        out_opening_disc10 = pln.morpho.opening(lena, pln.se.disc(10))
        self.assertImagesEquals(out_opening_disc10, ref_opening_disc10)

    def test_lena_rect0519(self):
        ref_opening_rect0519 = open_image('lena_opening_rect5-19.png')
        out_opening_rect0519 = pln.morpho.opening(lena, pln.se.rectangle(width=5, height=19))
        self.assertImagesEquals(out_opening_rect0519, ref_opening_rect0519)

class TestMSE(unittest.TestCase, ImagesEqualsAssertions):

    def test_lena_disc10vsdisc11(self):
        ref_opening_disc10 = open_image('lena_opening_disc10.png')
        out_opening_disc11 = pln.morpho.opening(lena, pln.se.disc(11))
        self.assertImagesNotEquals(out_opening_disc11, ref_opening_disc10)

if __name__ == '__main__':
    unittest.main()