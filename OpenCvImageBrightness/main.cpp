#include <iostream>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;

int main()
{

	cv::namedWindow("opencv");
	cv::Mat mat = cv::imread("123.jpg");

	cv::imshow("opencv", mat);



	cv::waitKey(0);
	system("pause");
	return 0;
}