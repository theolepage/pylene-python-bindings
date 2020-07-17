from skimage import data
import pylene as pln
import numpy as np
import matplotlib.pyplot as plt

def lena_grayscale(np_type):
    image = plt.imread('lena.png') * 255
    image = image.astype(np_type)

    # Debug input
    print(image.shape, image.dtype)
    plt.imshow(image, cmap='gray')
    plt.show()

    # Process
    # image = image.reshape((512, 512, 1))
    res = pln.morpho.dilation(image, pln.se.disc(5))

    # Debug output
    print(res.shape, res.dtype)
    plt.imsave('new.png', res, cmap='gray')
    plt.imshow(res, cmap='gray')
    plt.show()

def lena_color(np_type):
    image = plt.imread('lena_color.png') * 255
    image = image.astype(np_type)

    # Debug input
    print(image.shape, image.dtype)
    plt.imshow(image)
    plt.show()

    # Process
    # image = image.reshape((512, 512, 1))
    res = pln.morpho.dilation(image, pln.se.disc(10))

    # Debug output
    print(res.shape, res.dtype)
    plt.imsave('new.png', res)
    plt.imshow(res)
    plt.show()

def camera_grayscale(np_type):
    # image = data.camera()
    image = data.retina()
    image = image.astype(np_type)

    # Debug input
    print(image.shape, image.dtype)
    plt.imshow(image)
    plt.show()

    # Process
    # image = image.reshape((512, 512, 1))
    res = pln.morpho.dilation(image, pln.se.disc(10))

    # Debug output
    print(res.shape, res.dtype)
    plt.imsave('new.png', res)
    plt.imshow(res)
    plt.show()

lena_grayscale(np.uint8)
lena_grayscale(np.double)
lena_color(np.uint8)
camera_grayscale(np.uint8)