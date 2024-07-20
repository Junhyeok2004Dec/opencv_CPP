
#include <opencv2/core.hpp> // It declararations for Mat class
#include <opencv2/highgui.hpp> // imread()
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat img;

int main()
{
    //Read image
    img = imread("./sadf.png", IMREAD_COLOR);
    //delaring mat object
    int cols = 15, rows = 20;
    //rows, cols, type, scalar()
    Mat m(rows, cols, CV_8UC3, Scalar(0, 0, 255)); //color image
    Mat m2(rows, cols, CV_8UC1, Scalar(0)); // gray scale image

    //get color channels
    vector<Mat> channels;
    split(img, channels);

    //Show img's first channel
    imshow("Blue", channels[0]);

    if (img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);
        

    namedWindow("image");
    imshow("image", img);
    while (char(waitKey(0)) != 'q');

    return 0;
}
