//
//  카메라를 CAMERA_INDEX로부터 호출하고, 해당 데이터를 전송하는 코드
//

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>

// Dependencies 오류 (아직 코드 실행 불가)


#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/highgui/highgui.hpp>


using namespace cv;

int main(int argc, char** argv)
{
    ros::init(argc, argv, "image_publisher");
    ros::NodeHandle nh;

    const int CAMERA_INDEX = 0;
    cv::VideoCapture capture(CAMERA_INDEX);
    if (not capture.isOpened()) {
        ROS_INFO_STREAM("Failed to open camera Number :: [ " << CAMERA_INDEX << " ] !"); // 카메라 오픈 (CAMERA_INDEX )
        ros::shutdown();
    }
    // Set the parameters using the results of executing the following command:
    //   v4l2-ctl -d /dev/video0 --list-formats-ext
    //
    capture.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    capture.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
    capture.set(CV_CAP_PROP_FPS, 10);



    image_transport::ImageTransport it(nh);
    image_transport::Publisher pub_image = it.advertise("camera_raw", 1);

    // for debug
    cv::namedWindow("이미지 게시", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);

    cv_bridge::CvImagePtr frame = boost::make_shared< cv_bridge::CvImage >();
    frame->encoding = sensor_msgs::image_encodings::BGR8; // frame read (BGR8Format)
    while (ros::ok()) {
        // for debug
        cv::Mat image;
        capture >> image;
        cv::imshow("이미지 게시", image);
        //

        capture >> frame->image;
        if (frame->image.empty()) {
            ROS_ERROR_STREAM("Failed to capture frame!");
            ros::shutdown();
        }
        frame->header.stamp = ros::Time::now();
        pub_image.publish(frame->toImageMsg());

        if (cv::waitKey(30) >= 0) break;
        ros::spinOnce();
    }

    capture.release();
    return EXIT_SUCCESS;
}