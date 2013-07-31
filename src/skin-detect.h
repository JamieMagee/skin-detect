#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <string>
#include <math.h>

using namespace cv;
using namespace std;

#define MINCB 77
#define MAXCB 127
#define MINCR 133
#define MAXCR 173
#define ERODE_SIZE 5
#define DILATE_SIZE 3

Mat img, imgFilter;
int c;
VideoCapture cap;

//Default Values
int cs = 1, dr = 1, lr = 1, gc = 1;
int min_Cr = 146, max_Cr = 240, min_Cb = 106, max_Cb = 173;
int erode1 = 0;
int dilate1 = 3;
int erode2 = 5;
int dilate2 = 4;
int deviation = 2;

//Window names
string window1_name = "Video";
string window2_name = "Skin";
string window3_name = "Settings";

//Prototype functions
void process_image(int, void*);
void colour_segmentation();
void density_regularisation();
void luminance_regularisation();
void geometric_correction();
