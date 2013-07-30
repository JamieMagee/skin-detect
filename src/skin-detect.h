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

//Window names
string window1_name = "Video";
string window2_name = "Skin";

//Prototype functions
void process_image();
void colour_segmentation();
void density_regularisation();
void luminance_regularisation();
void geometric_correction();
