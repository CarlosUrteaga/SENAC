/*
 * test_slic.cpp.
 *
 * Written by: Pascal Mettes.
 *
 * This file creates an over-segmentation of a provided image based on the SLIC
 * superpixel algorithm, as implemented in slic.h and slic.cpp.
 */
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <float.h>
using namespace std;
void redFilter(cv::Mat &srcBGR)
{
    assert(srcBGR.type() == CV_8UC3);

    cv::Mat redOnly;
cv::Mat imR(srcBGR.rows, srcBGR.cols, CV_8UC1);
  cv::Mat imG(srcBGR.rows, srcBGR.cols, CV_8UC1);
  cv::Mat imB(srcBGR.rows, srcBGR.cols, CV_8UC1);
  cv::Mat imRboost(srcBGR.rows, srcBGR.cols, CV_8UC1);
    //inRange(src, Scalar(0), Scalar(255), redOnly);

 cv::Mat out[] = {imR, imG, imB};
  int from_to[] = {2,0  , 1, 1,  0, 2 };
  cv::mixChannels(&srcBGR, 1, out, 3, from_to, 3);

 cv::bitwise_not(imG, imG);
  cv::bitwise_not(imB, imB);

  cv::multiply(imR, imG, imRboost, (double)1/255);
  cv::multiply(imRboost, imB, imRboost, (double)1/255);
  //  return redOnly;
}
int main(int argc, char *argv[]) {
    /* Load the image and convert to Lab colour space. */
    IplImage *image = cvLoadImage(argv[1], 1);
    IplImage *lab_image = cvCloneImage(image);
    //cvCvtColor(image, lab_image, CV_BGR2Lab);
    
    /* Yield the number of superpixels and weight-factors from the user. */
    //int w = image->width, h = image->height;
    //int nr_superpixels = atoi(argv[2]);
    //int nc = atoi(argv[3]);

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
    cvWaitKey(0);
    //*/
    cvSaveImage(argv[4], image);
}
