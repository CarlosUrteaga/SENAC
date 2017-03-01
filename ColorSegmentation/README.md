# Color Segmentation

This folder contains who to apply color segmentation using OpenCV.

	split(src, rgbChannels);
	Mat fin_img;
	vector<Mat> channels;
	//filter
	channels.push_back(
		(rgbChannels[0]>125)&(rgbChannels[0]<130)&
		(rgbChannels[1]>61)&(rgbChannels[1]<65)&
		(rgbChannels[2]>121)&(rgbChannels[2]<130  )
	);
	//Create image mask
	merge(channels, fin_img);
	// Apply Filter
	bitwise_and(src2,src2,fin_img,fin_img);

How to run it
	
	mkdir build
	cd build
	cmake ../
	make
	#./ColorSegmentation colorFilter.png Orignal.png
	#example

