#include <opencv2/calib3d/calib3d.hpp>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <float.h>
using namespace std;
using namespace cv;
int main(int argc, char *argv[]) {
  //cvLoadImage(argv[1], 1);
    Mat src=imread(argv[1],1);    
    Mat src2=imread(argv[2],1);    
    namedWindow("src",1);imshow("src",src);
 
    // Split the image into different channels
    vector<Mat> rgbChannels(3);
    split(src, rgbChannels);
 
    // Show individual channels
    Mat  fin_img;
  {//Road
    vector<Mat> channels;
    channels.push_back(
                      (rgbChannels[0]>125)&(rgbChannels[0]<130)&
                        (rgbChannels[1]>61)&(rgbChannels[1]<65)&
                        (rgbChannels[2]>121)&(rgbChannels[2]<130  )
                      );
    merge(channels, fin_img);
    bitwise_and(src2,src2,fin_img,fin_img);
    namedWindow("road",1);imshow("road", fin_img);

    }
 {//cars &suv
    vector<Mat> channels;
    
    
    channels.push_back(//suv
                      (rgbChannels[0]>190)&(rgbChannels[0]<195)&
                        (rgbChannels[1]>120)&(rgbChannels[1]<129)&
                        (rgbChannels[2]>38)&(rgbChannels[2]<70  )|
						//cars
                        ( (rgbChannels[0]>127)&(rgbChannels[0]<129)&
                        (rgbChannels[1]<1)&
                        (rgbChannels[2]>63)&(rgbChannels[2]<65)
                      )
                      
                      );

    merge(channels, fin_img);
    bitwise_and(src2,src2,fin_img,fin_img);
    namedWindow("cars",1);imshow("cars", fin_img);
    }
    {
    //sidewalk
    vector<Mat> channels;
    channels.push_back(
                      (rgbChannels[0]>190)&(rgbChannels[0]<200)&
                        (rgbChannels[2]>127)&(rgbChannels[2]<129)&
                        (rgbChannels[1]>0)&(rgbChannels[1]<200)
                      );
    merge(channels, fin_img);
    bitwise_and(src2,src2,fin_img,fin_img);
    namedWindow("sidewalk",1);imshow("sidewalk", fin_img);

  }
  {//Tree
    vector<Mat> channels;
    channels.push_back(
                      (rgbChannels[0]<10)&
                        (rgbChannels[1]>127)&(rgbChannels[1]<129)&
                        (rgbChannels[2]>127)&(rgbChannels[2]<129)
                      );
    merge(channels, fin_img);
    bitwise_and(src2,src2,fin_img,fin_img);
    namedWindow("tree",1);imshow("tree", fin_img);
    }
    //building
    {
    vector<Mat> channels;
    channels.push_back(
                      (rgbChannels[0]>190)&
                        (rgbChannels[1]<1)&
                        (rgbChannels[2]==128)
                      );

    merge(channels, fin_img);
    bitwise_and(src2,src2,fin_img,fin_img);

    namedWindow("line",1);imshow("line", fin_img);
    
    }    
    waitKey(0);
    return 0;
}
