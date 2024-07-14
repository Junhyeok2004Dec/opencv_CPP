
#include <opencv2/core.hpp> // It declararations for Mat class
#include <opencv2/highgui.hpp> // imread()
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    //Read image
    Mat img = imread("./sadf.png", IMREAD_COLOR);
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

    /*
    IMREAD_UNCHANGED If set, return the loaded image as is
    IMREAD_GRAYSCALE If set, always convert the image to the single channel grayscale image
    IMREAD_COLOR If set, always convert the image to the three channel BGR color image
    IMREAD_ANYDEPTH If set, return the 16-bit/32-bit image when the input has the
    corresponding depth, otherwise convert it to 8-bit
    IMREAD_ANYCOLOR If set, the image is read in any possible color format
    IMREAD_LOAD_GDAL If set, use the gdal driver for loading the image
    */
    if (img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    namedWindow("image");
    imshow("image", img);
    while (char(waitKey(0)) != 'q');

    return 0;
}
