#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

Mat img, imgYUV, imgThreshed, imgMorph, imgHist;

//Initial values
int min_Y = 0; 
int max_Y = 255;
int min_Cr = 138;
int max_Cr = 170;
int min_Cb = 90;
int max_Cb = 130;
int weighting = 127;
int c;

//Maximum Values
int const max_operator = 4;
int const max_elem = 2;
int const max_kernel_size = 21;
int const max_value = 255;

//Window names
string window1_name = "Video";
string window2_name = "Skin";

//Prototype functions
void threshold(int, void*);
void morphology();
