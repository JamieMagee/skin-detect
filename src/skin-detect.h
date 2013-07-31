#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <string>
#include <math.h>

using namespace cv;
using namespace std;

#define MINCB 77
#define MAXCB 127
#define MINCR 137
#define MAXCR 173
#define ERODE_SIZE 5
#define DILATE_SIZE 3
#define DEVIATION 2

Mat img, imgFilter;
int c;
VideoCapture cap;

//Default Values
int cs = 1, dr = 1, lr = 1, gc = 1;
int min_Cr = MINCR, max_Cr = MAXCR, min_Cb = MINCB, max_Cb = MAXCB;
int erode1 = ERODE_SIZE;
int dilate1 = DILATE_SIZE;
int erode2 = ERODE_SIZE;
int dilate2 = DILATE_SIZE;
int deviation = DEVIATION;

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
