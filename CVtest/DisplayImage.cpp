#include <opencv2/calib3d/calib3d.hpp>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <float.h>
using namespace std;
using namespace cv;
//road      124 62 128
//objects   42 123 191
//sidewalk  24 0 191
//buildings 123 0 10
//pederastian 66 67 0
int main(int argc, char *argv[]) {
  //cvLoadImage(argv[1], 1);
    Mat src=imread(argv[1],1);    
    namedWindow("src",1);imshow("src",src);
 
    // Split the image into different channels
    vector<Mat> rgbChannels(3);
    split(src, rgbChannels);
 
    // Show individual channels
    Mat g, fin_img;
    g = Mat::zeros(Size(src.cols, src.rows), CV_8UC1);
     
    // Showing Red Channel
    // G and B channels are kept as zero matrix for visual perception
  {
    vector<Mat> channels;
    /*
    *
//road      124 62 128
//objects   42 123 191
//sidewalk  24 0 191
//buildings 123 0 10
//pederastian 66 67 0

    */
    //Road
    channels.push_back(
      //(rgbChannels[2]>42)&(rgbChannels[2]< 125)&
      //                (rgbChannels[1]> 122)&(rgbChannels[1]<125)&
                      (rgbChannels[0]>125)&(rgbChannels[0]<130)&
                        (rgbChannels[1]>61)&(rgbChannels[1]<65)&
                        (rgbChannels[2]>121)&(rgbChannels[2]<130  )
                      
                      );
    //channels.push_back();
    //channels.push_back();
    merge(channels, fin_img);
    namedWindow("road",1);imshow("road", fin_img);

    }
 {
    vector<Mat> channels;
    /*
    *
//road      124 62 128
//objects   42 123 191
//sidewalk  24 0 191
//buildings 123 0 10
//pederastian 66 67 0

    */
    //suv
    channels.push_back(
      //(rgbChannels[2]>42)&(rgbChannels[2]< 125)&
      //                (rgbChannels[1]> 122)&(rgbChannels[1]<125)&
                      (rgbChannels[0]>190)&(rgbChannels[0]<195)&
                        (rgbChannels[1]>120)&(rgbChannels[1]<129)&
                        (rgbChannels[2]>38)&(rgbChannels[2]<70  )
                      
                      );
    //channels.push_back();
    //channels.push_back();
    merge(channels, fin_img);
    namedWindow("suv",1);imshow("suv", fin_img);
    
    }{
    vector<Mat> channels;
    /*
    *
//road      124 62 128
//objects   42 123 191
//sidewalk  24 0 191
//buildings 123 0 10
//pederastian 66 67 0

    */
    //roadcd
    channels.push_back(
      //(rgbChannels[2]>42)&(rgbChannels[2]< 125)&
      //                (rgbChannels[1]> 122)&(rgbChannels[1]<125)&
                      (rgbChannels[0]>190)&(rgbChannels[0]<200)&
                        (rgbChannels[2]>127)&(rgbChannels[2]<129)&
                        (rgbChannels[1]>0)&(rgbChannels[1]<200)
                      
                      );
    //channels.push_back();
    //channels.push_back();
    merge(channels, fin_img);
    namedWindow("B",1);imshow("B", fin_img);
    
    }
    waitKey(0);
    return 0;
    /* Load the image and convert to Lab colour space. */
    //IplImage *image = cvLoadImage(argv[1], 1);
    //IplImage *lab_image = cvCloneImage(image);
    //cvCvtColor(image, lab_image, CV_BGR2Lab);
    /*cv::Mat bgr_image = cv::imread(argv[1]);
    cv::Mat orig_image = bgr_image.clone();
    cv::Mat out = cv::Mat::zeros(bgr_image.rows, bgr_image.cols, CV_8UC1);
    cv::Mat hsv_image;
    cv::cvtColor(bgr_image, hsv_image, cv::COLOR_BGR2HSV);
    cv::Mat lower_red_hue_range;
    cv::Mat upper_red_hue_range;
    //  cv::inRange(hsv_image, cv::Scalar(0, 100, 100), cv::Scalar(10, 255, 255), lower_red_hue_range);
    cv::Mat ch[3];
    cv::split(orig_image,ch);

    //cv::merge(ch, out);

  cv::inRange(hsv_image, cv::Scalar( 100, 0, 0), cv::Scalar( 200, 0, 0), lower_red_hue_range);
  //cv::inRange(hsv_image, cv::Scalar(0, 100, 100), cv::Scalar(10, 255, 255), lower_red_hue_range);
  cv::inRange(hsv_image, cv::Scalar(160, 100, 100), cv::Scalar(179, 255, 255), upper_red_hue_range);

  // Combine the above two images
  cv::Mat red_hue_image;
  cv::addWeighted(lower_red_hue_range, 1.0, upper_red_hue_range, 1.0, 0.0, red_hue_image);

//cv::GaussianBlur(red_hue_image, red_hue_image, cv::Size(9, 9), 2, 2);

  cv::namedWindow("Threshold upper image", cv::WINDOW_AUTOSIZE);
  cv::imshow("Threshold upper image", upper_red_hue_range);
  cv::namedWindow("Combined threshold images", cv::WINDOW_AUTOSIZE);
  cv::imshow("Combined threshold images", red_hue_image);
  cv::namedWindow("Detected red circles on the input image", cv::WINDOW_AUTOSIZE);
cv::imshow("Detected red circles on the input image", orig_image);
cv::namedWindow("Threshold lower image", cv::WINDOW_AUTOSIZE);
  cv::imshow("Threshold lower image", lower_red_hue_range);
    /* Yield the number of superpixels and weight-factors from the user. */
    //int w = image->width, h = image->height;
    //int nr_superpixels = atoi(argv[2]);
    //int nc = atoi(argv[3]);
/*
    //double step = sqrt((w * h) / (double) nr_superpixels);
    cv::Mat m = cv::cvarrToMat(lab_image);  // default additional arguments: don't copy data.

    cv::Mat hsv_image;
 	cvtColor(m, m, cv::COLOR_BGR2HSV);
 	
 	// Threshold the HSV image, keep only the red pixels
 	cv::Mat lower_red_hue_range;
 	cv::Mat upper_red_hue_range;
 	//cv::inRange(hsv_image, cv::Scalar(100, 100, 100), cv::Scalar(255, 255, 255), lower_red_hue_range);
 	//cv::inRange(hsv_image, cv::Scalar(160, 100, 100), cv::Scalar(179, 255, 255), upper_red_hue_range);
	redFilter(m);
	//cvtColor(m, m, cv::COLOR_HSV2BGR);
    cvShowImage("result", lab_image);
    //*/
    //cvSaveImage(argv[4], image);
    cvWaitKey(0);
}
