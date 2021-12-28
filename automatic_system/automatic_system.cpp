#include<opencv2/imgcodecs.hpp>
#include<opencv2/video.hpp>
#include<opencv2/highgui.hpp>

#include<iostream>
#include<stdio.h>

using namespace std;

int main(int arg, char** argu) {
	cv::Mat img = cv::imread("cat.png");

	imshow("img", img);
	cv::waitKey(0);

	return 0;
}