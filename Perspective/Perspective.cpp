/*#include <opencv2/calib3d/calib3d.hpp>
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
    inputQuad[0] = cv::Point2f( 236,257 );
    inputQuad[1] = cv::Point2f( 387 ,257);
    inputQuad[2] = cv::Point2f( 532,483);
    inputQuad[3] = cv::Point2f( 101,483  );  
    /*
    anteriormente
        inputQuad[0] = cv::Point2f( 0,200 );
    inputQuad[1] = cv::Point2f( 640 ,200);
    inputQuad[2] = cv::Point2f( 640,350);
    inputQuad[3] = cv::Point2f( 0,350  );  
    //* /
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
*/
#include <opencv2/core/core.hpp>
    #include <opencv2/opencv.hpp>
    #include <cv.h>
    #include <opencv2/highgui/highgui.hpp>
    #include <iostream>
#include "IPMapper.h"
#include "IPMapper.cpp"
    using namespace cv;
    using namespace std;

            cv::Mat OpenWarpPerspective(const cv::Mat& _image
              , const cv::Point2f& _lu
              , const cv::Point2f& _ru
              , const cv::Point2f& _rd
              , const cv::Point2f& _ld
              , const cv::Point2f& _lu_result
              , const cv::Point2f& _ru_result
              , const cv::Point2f& _rd_result
              , const cv::Point2f& _ld_result
              , cv::Mat& _transform_matrix)
            {
              // todo do some checks on input.

              cv::Point2f source_points[4];
              cv::Point2f dest_points[4];


              source_points[0] = _lu;
              source_points[1] = _ru;
              source_points[2] = _rd;
              source_points[3] = _ld;

              dest_points[0] = _lu_result;
              dest_points[1] = _ru_result;
              dest_points[2] = _rd_result;
              dest_points[3] = _ld_result;

              cv::Mat dst= _image.clone(); 
             _transform_matrix = cv::getPerspectiveTransform(source_points, dest_points);
             cv::warpPerspective(_image, dst, _transform_matrix, cv::Size(600,480));
               imshow( "Display window", dst );  
/*
 cv::Mat dst;
  _transform_matrix = cv::getPerspectiveTransform(source_points, dest_points);
  cv::warpPerspective(_image, dst, _transform_matrix, cv::Size(_width, _height));

  return dst;  
//*/
              return dst;  
            }

    int main( int argc, char** argv )
    {

        Mat image;
        Mat edited;
int ow = 640;                             //output width
    int oh = 480;                             //output height
    double f_u = 100;                         //focal lense values (mm)
    double f_v = 100;
    double c_u = 50;                          //camera optical center
    double c_v = 50;
    double deg = 45;                          //degree of camera
    //double cam_h = 10;                        //height of camera
	int cam_w =640;
    int cam_h = 480;
    int proj_y_start=115;
    int proj_image_h=40;
    int proj_image_w=80;
    //int roi_top_w=30;
    //int roi_bottom_w=20;
    int proj_image_horizontal_offset=0;
    int detector_size=16;
    int lane_width=17;
    int cam_h_half = cam_h/2;
    int proj_image_w_half = proj_image_w/2;
double cam_deg = 27;

double cam_height = 18	;
int roi_top_w = 62;
int roi_bottom_w = 30;
	IPMapper ipMapper;
	 ipMapper = IPMapper(cam_w, cam_h_half, f_u, f_v, c_u, c_v, cam_deg, cam_height);
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);   // Read the file
	Mat cut_image = image(cv::Rect(0,cam_h/2,cam_w,cam_h/2));
	 Mat remapped_image = ipMapper.remap(cut_image);

    //cv::Mat transformedImage = remapped_image(cv::Rect((cam_w/2)-proj_image_w_half+proj_image_horizontal_offset, proj_y_start,proj_image_w,proj_image_h)).clone();
     //cv::flip(transformedImage, transformedImage, 0);
	//Mat remapped_image = ipMapper.remap(cut_image);
	//ipMapper = IPMapper(cam_w, cam_h_half, f_u, f_v, c_u, c_v, cam_deg, cam_height);
    
//Mat remapped_image = ipMapper.remap(cut_image);
cv::Mat transformedImage = remapped_image.clone();
           
 imshow( "Display window", remapped_image(cv::Rect((cam_w/2)-proj_image_w_half+proj_image_horizontal_offset,proj_y_start,proj_image_w,proj_image_h)).clone());
//                         remapped_image(cv::Rect((cam_w/2)-proj_image_w_half+proj_image_horizontal_offset,proj_y_start,proj_image_w,proj_image_h));
//
 //cv::flip(transformedImage, transformedImage, 0);
 //Mat remapped_image = ipMapper.remap(cut_image);
        /*
        cv::Mat transformedImage = remapped_image	(cv::Rect((cam_w/2)-proj_image_w_half+proj_image_horizontal_offset,
proj_y_start,proj_image_w,proj_image_h)).clone();
        namedWindow( "Display window", CV_WINDOW_AUTOSIZE );// Create a window for display.

             cv::Point2f one = cv::Point2f(0,0);
            Point2f two = cv::Point2f(317, 0);
            Point2f three = cv::Point2f(317, 240);
            Point2f four =cv::Point2f (0, 240);

            Point2f five = cv::Point2f(-100, 0);
            Point2f six =cv::Point2f (617, 0);
            Point2f seven = cv::Point2f(317, 240);
            Point2f eight =cv::Point2f (0, 240);

            OpenWarpPerspective(image,one,two,three,four,five,six,seven,eight,edited);  

        //                  // Show our image inside it.

        
        //*/
    waitKey(0);                                          // Wait for a keystroke in the window
        return 0;
}