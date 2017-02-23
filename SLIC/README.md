# SLIC

This repository contains an implementation of the SLIC Superpixel algorithm by Achanta et al. (PAMI'12, vol. 34, num. 11, pp. 2274-2282). The C++ implementation is created to work with the strutures of OpenCV.

This repository is a modification of https://github.com/PSMM/SLIC-Superpixels

Tested in Ubuntu 14.04 with ROS indigo

	cmake .
	make
	#./SLIC num_of_superpixels weight_factor image_out
	#example
	./SLIC images/dog.png 400 40 images/out.png

<p align="center">
  <img src="https://github.com/CarlosUrteaga/SLIC/blob/master/images/dog.png?raw=true" alt="Dog"/>
  <img src="https://github.com/CarlosUrteaga/SLIC/blob/master/images/out.png?raw=true" alt="Dog Segmentation"/>
</p>
