#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

Mat img, imgYUV, imgThreshed, imgMorph; 

//Initial values
int min_Y = 0; 
int max_Y = 255;
int min_Cr = 138;
int max_Cr = 170;
int min_Cb = 90;
int max_Cb = 130;
int morph_elem = 2;
int morph_size = 6;
int morph_operator = 1;

//Maximum Values
int const max_operator = 4;
int const max_elem = 2;
int const max_kernel_size = 21;
int const max_value = 255;

//Window names
char* window1_name = "Video";
char* window2_name = "Threshold";
char* window3_name = "Cr";
char* window4_name = "Cb";

//Prototype functions
void threshold (int, void*);
void morphology(int, void*);
