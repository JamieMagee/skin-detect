#include "YUV.h"

int main( int argc, char** argv )
{
	
	if (argc != 2) { //Check the correct syntax is used to open a file
		cout << "Usage: " << argv[0] << " Video" << endl;
		return -1;
	}

	VideoCapture cap(argv[1]); //Open Video

	if (!cap.isOpened()) { //Check if video has been opened correctly
		cout << "cannot open camera" << endl;
		return -1;
	}
	
	cap >> img; //Capture the first frame of the video
	
	if(!img.data){ //Check for invalid input
        cout <<  "Could not open video" << endl ;
        return -1;
    }
    
    cvtColor(img, imgYUV, CV_BGR2YCrCb); //Convert to YUV colorspace
    Mat Cr(imgYUV.rows, imgYUV.cols, CV_8UC1);
    Mat Cb(imgYUV.rows, imgYUV.cols, CV_8UC1);

    
    namedWindow(window1_name, CV_WINDOW_AUTOSIZE ); //Create video window
    namedWindow(window2_name, CV_WINDOW_AUTOSIZE ); //Create thresholded video window
    
    //Create YUV range trackbars
    createTrackbar("Min Y", window2_name, &min_Y, max_value, threshold);
    createTrackbar("Max Y", window2_name, &max_Y, max_value, threshold);
    createTrackbar("Min Cr", window2_name, &min_Cr, max_value, threshold);
    createTrackbar("Max Cr", window2_name, &max_Cr, max_value, threshold);
    createTrackbar("Min Cb", window2_name, &min_Cb, max_value, threshold);
    createTrackbar("Max Cb", window2_name, &max_Cb, max_value, threshold);
    //Create trackbar to select Morphology operation
	createTrackbar("Operator", window2_name, &morph_operator, max_operator, threshold);
	//Create trackbar to select kernel type
	createTrackbar("Element", window2_name, &morph_elem, max_elem, threshold);
	//Create Trackbar to choose kernel size
	createTrackbar("Kernel size", window2_name, &morph_size, max_kernel_size, threshold);
	  
	while(true) {
	    int c;
	    c = waitKey(20);
	    if((char)c == 27) break; //Exit if ESC key is hit
	    //Debug info
	    cout << "Frames in video: " << cap.get(CV_CAP_PROP_FRAME_COUNT) << "	Current Frame: " << cap.get(CV_CAP_PROP_POS_FRAMES) << endl;
		//if ((char)c == 106) {
			if (cap.get(CV_CAP_PROP_FRAME_COUNT) > cap.get(CV_CAP_PROP_POS_FRAMES)) { //If current frame is less than length of video
				imshow(window1_name,img); //Show captured frame
				//int from_to[] = {1,0, 2,1};
				//Mat out[] = {Cr, Cb};
				//mixChannels(&imgYUV, 1, out, 2, from_to, 2);
				//imshow(window3_name, Cr);
				//imshow(window4_name, Cb);
				threshold(0,0); //Threshold captured frame
				cap >> img; //Capture next frame
				cvtColor(img, imgYUV, CV_RGB2YCrCb); //Convert to YUV colourspace
			}
			else cap.set(CV_CAP_PROP_POS_FRAMES,0); //If EOF go to start (and collect £200)
		//}
	}
}

void threshold (int, void*) {
	inRange(imgYUV, Scalar(min_Y, min_Cb, min_Cr), Scalar(max_Y, max_Cb, max_Cr), imgThreshed); //Check if pixels are in range
    //imshow(window2_name, imgThreshed);
    morphology(0,0); //Perform Morphology
}

void morphology(int, void*) {
	// Since MORPH_X : 2,3,4,5 and 6
	int operation = morph_operator + 2;
	
	Mat element = getStructuringElement(morph_elem, Size(2*morph_size + 1, 2*morph_size+1), Point(morph_size, morph_size)); //Create structuring element
	
	// Apply the specified morphology operation
	morphologyEx(imgThreshed, imgMorph, operation, element);
	imshow(window2_name, imgMorph);
}
