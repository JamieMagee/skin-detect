#include "YUV.h"

int main(int argc, char** argv) {
	
	if (argc != 2) { //Check the correct syntax is used to open a file
		cout << "Usage: " << argv[0] << " Video" << endl;
		return -1;
	}

	VideoCapture cap(argv[1]); //Open Video

	if (!cap.isOpened()) { //Check if video has been opened correctly
		cout << "Cannot open camera" << endl;
		return -1;
	}
	
	//for (int i=0; i<3000; i++) { //Skip to interesting parts of long videos
		cap >> img; //Capture the first frame of the video
	//}
	
	if(!img.data){ //Check for invalid input
        cout <<  "Could not open video" << endl ;
        return -1;
    }
    
    cvtColor(img, imgYUV, CV_BGR2YCrCb); //Convert to YUV colorspace
    
    namedWindow(window1_name, CV_WINDOW_AUTOSIZE ); //Create video window
    namedWindow(window2_name, CV_WINDOW_AUTOSIZE ); //Create thresholded video window
    
    //Create YUV range trackbars
    createTrackbar("Min Y", window2_name, &min_Y, max_value, threshold);
    createTrackbar("Max Y", window2_name, &max_Y, max_value, threshold);
    createTrackbar("Min Cr", window2_name, &min_Cr, max_value, threshold);
    createTrackbar("Max Cr", window2_name, &max_Cr, max_value, threshold);
    createTrackbar("Min Cb", window2_name, &min_Cb, max_value, threshold);
    createTrackbar("Max Cb", window2_name, &max_Cb, max_value, threshold);
	  
	while(true) {
	    int c;
	    c = waitKey(20);
	    if((char)c == 27) break; //Exit if ESC key is hit
	    
	    //Debug info
	    cout << "Frames in video: " << cap.get(CV_CAP_PROP_FRAME_COUNT) << "	Current Frame: " << cap.get(CV_CAP_PROP_POS_FRAMES) << endl;
		
		if (cap.get(CV_CAP_PROP_FRAME_COUNT) > cap.get(CV_CAP_PROP_POS_FRAMES)) { //If current frame is less than length of video
			imshow(window1_name,img); //Show captured frame
			threshold(0,0); //Threshold captured frame
			cap >> img; //Capture next frame
			cvtColor(img, imgYUV, CV_BGR2YCrCb); //Convert to YUV colourspace
		}
		else cap.set(CV_CAP_PROP_POS_FRAMES,0); //If EOF go to start (and collect £200)
	}
}

void threshold (int, void*) {
	inRange(imgYUV, Scalar(min_Y, min_Cr, min_Cb), Scalar(max_Y, max_Cr, max_Cb), imgThreshed); //Check if pixels are in range
    morphology(0,0); //Perform Morphology
}

void morphology(int, void*) {
	// Apply the specified morphology operation
	morphologyEx(imgThreshed, imgThreshed, CV_MOP_ERODE, Mat1b(3,3,1), Point(-1, -1), 3);
	morphologyEx(imgThreshed, imgThreshed, CV_MOP_OPEN, Mat1b(7,7,1), Point(-1, -1), 1);
	morphologyEx(imgThreshed, imgMorph, CV_MOP_CLOSE, Mat1b(9,9,1), Point(-1, -1), 3);
	imshow(window2_name, imgMorph);
}
