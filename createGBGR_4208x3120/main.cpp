#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


void setColorB(Mat &mat,int row,int col) {
	mat.at<unsigned char>(row, col*3) = 255;
	mat.at<unsigned char>(row, col*3 + 1) = 0;
	mat.at<unsigned char>(row, col*3 + 2) = 0;
}

void setColorG(Mat &mat, int row, int col) {
	mat.at<unsigned char>(row, col*3) = 0;
	mat.at<unsigned char>(row, col*3 + 1) = 255;
	mat.at<unsigned char>(row, col*3 + 2) = 0;
}

void setColorR(Mat &mat, int row, int col) {
	mat.at<unsigned char>(row, col*3) = 0;
	mat.at<unsigned char>(row, col*3 + 1) = 0;
	mat.at<unsigned char>(row, col*3 + 2) = 255;
}

bool firstPixel(int row,int col) {
	if (row % 2 == 0 && col % 2 == 0) {
		return true;
	}
	return false;
}

bool secondPixel(int row, int col) {
	if (row % 2 == 0 && col % 2 == 1) {
		return true;
	}
	return false;
}

bool thirdPixel(int row, int col) {

	if (row % 2 == 1 && col % 2 == 0) {
		return true;
	}
	return false;
}

bool fourthPixel(int row, int col) {
	if (row % 2 == 1 && col % 2 == 1) {
		return true;
	}
	return false;
	return true;
}

bool drawBox(Mat &image, int box_center_row, int box_center_col,int box_w,int box_h) {
	//if (box_center_col - box_w<0 || box_center_col + box_w>image.cols || box_center_row - box_h<0||box_center_row+box_h>image.rows) {
	//	return false;
	//}

	rectangle(image, Point(box_center_row - box_w / 2, box_center_col - box_h / 2), Point(box_center_row + box_w / 2, box_center_col + box_h / 2), Scalar(0, 0, 255), 3, LINE_8);
	return true;
}


int main()
{
	Mat image(Size(4208, 3120), CV_8UC3);

	for (int row = 0; row < image.rows; row++){
		for (int col = 0; col < image.cols; col++){
			if (firstPixel(row, col)|| fourthPixel(row,col)) {
				setColorG(image, row, col);
			}
			else if (secondPixel(row, col)) {
				setColorR(image, row, col);
			}
			else if(thirdPixel(row,col))
			{
				setColorB(image, row, col);
			}
			else
			{
				cout << "ERRRO___" << endl;
			}
			
		}
	}
	int x, y;
	x = 2104;
	y = 1560;
	drawBox(image, x, y, 120, 100);
	putText(image, "0", Point(x-30, y+30), FONT_HERSHEY_SIMPLEX, 3,Scalar(0, 0, 255), 2, LINE_8);

	x = 84;
	y = 62;
	drawBox(image, x, y, 120, 100);
	putText(image, "1", Point(x - 30, y + 30), FONT_HERSHEY_SIMPLEX, 3, Scalar(0, 0, 255), 2, LINE_8);

	x = 4124;
	y = 62;
	drawBox(image, x, y, 120, 100);
	putText(image, "2", Point(x - 30, y + 30), FONT_HERSHEY_SIMPLEX, 3, Scalar(0, 0, 255), 2, LINE_8);

	x = 84;
	y = 3058;
	drawBox(image, x, y, 120, 100);
	putText(image, "3", Point(x - 30, y + 30), FONT_HERSHEY_SIMPLEX, 3, Scalar(0, 0, 255), 2, LINE_8);

	x = 4124;
	y = 3058;
	drawBox(image, x, y, 120, 100);
	putText(image, "4", Point(x - 30, y + 30), FONT_HERSHEY_SIMPLEX, 3, Scalar(0, 0, 255), 2, LINE_8);

	x = 2104;
	y = 62;
	drawBox(image, x, y, 120, 100);
	putText(image, "5", Point(x - 30, y + 30), FONT_HERSHEY_SIMPLEX, 3, Scalar(0, 0, 255), 2, LINE_8);

	x = 84;
	y = 1560;
	drawBox(image, x, y, 120, 100);
	putText(image, "6", Point(x - 30, y + 30), FONT_HERSHEY_SIMPLEX, 3, Scalar(0, 0, 255), 2, LINE_8);

	x = 4124;
	y = 1560;
	drawBox(image, x, y, 120, 100);
	putText(image, "7", Point(x - 30, y + 30), FONT_HERSHEY_SIMPLEX, 3, Scalar(0, 0, 255), 2, LINE_8);

	x = 2104;
	y = 3058;
	drawBox(image, x, y, 120, 100);
	putText(image, "8", Point(x - 30, y + 30), FONT_HERSHEY_SIMPLEX, 3, Scalar(0, 0, 255), 2, LINE_8);

	x = 1094;
	y = 811;
	drawBox(image, x, y, 120, 100);
	putText(image, "9", Point(x - 30, y + 30), FONT_HERSHEY_SIMPLEX, 3, Scalar(0, 0, 255), 2, LINE_8);

	x = 3114;
	y = 811;
	drawBox(image, x, y, 120, 100);
	putText(image, "10", Point(x - 55, y + 30), FONT_HERSHEY_SIMPLEX, 3, Scalar(0, 0, 255), 2, LINE_8);

	x = 1094;
	y = 2309;
	drawBox(image, x, y, 120, 100);
	putText(image, "11", Point(x - 55, y + 30), FONT_HERSHEY_SIMPLEX, 3, Scalar(0, 0, 255), 2, LINE_8);

	x = 3114;
	y = 2309;
	drawBox(image, x, y, 120, 100);
	putText(image, "12", Point(x - 55, y + 30), FONT_HERSHEY_SIMPLEX, 3, Scalar(0, 0, 255), 2, LINE_8);

	imwrite("./image.bmp", image);
	//namedWindow("show", WINDOW_AUTOSIZE);
	//imshow("show", image);
	//waitKey(0);
	system("pause");
	return 0;
}