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
    Mat output;
    cv::Point2f inputQuad[4]; 
    // Output Quadilateral or World plane coordinates
    cv::Point2f outputQuad[4];
    cv::Mat lambda( 2, 4, CV_32FC1 );
    lambda = cv::Mat::zeros( src.rows, src.cols, src.type() );
    //Mat src2=imread(argv[2],1);    
    namedWindow("src",1);imshow("src",src);

 // The 4 points that select quadilateral on the input , from top-left in clockwise order
    // These four pts are the sides of the rect box used as input 
    inputQuad[0] = cv::Point2f( 0,200 );
    inputQuad[1] = cv::Point2f( 640 ,200);
    inputQuad[2] = cv::Point2f( 640,350);
    inputQuad[3] = cv::Point2f( 0,350  );  
    // The 4 points where the mapping is to be done , from top-left in clockwise order
    outputQuad[0] = cv::Point2f( 0,0 );
    outputQuad[1] = cv::Point2f( src.cols-1,0);
    outputQuad[2] = cv::Point2f( src.cols-1,src.rows-1);
    outputQuad[3] = cv::Point2f( 0,src.rows-1  );
 
    // Get the Perspective Transform Matrix i.e. lambda 
    lambda = cv::getPerspectiveTransform( inputQuad, outputQuad );
    // Apply the Perspective Transform just found to the src image
    cv::warpPerspective(src,output,lambda,output.size() );
    
    namedWindow("src",1);imshow("src",output);
    cvWaitKey(0);
}
