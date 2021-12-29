#include<opencv2/imgcodecs.hpp>
#include<opencv2/video.hpp>
#include<opencv2/highgui.hpp>

#include<iostream>
#include<stdio.h>

using namespace cv;

int main(int arg, char** argu) {
	Mat img = imread("cat.png"); //���� �̸��� ������� ������ ���� ����, Mat�� ���·� ��ȯ  docs.opencv.org/4.5.1/d3/d63/classcv_1_1Mat.html

	if (img.empty()) return -1;

	namedWindow("img", cv::WINDOW_AUTOSIZE);  //ȭ�鿡 �̹��� ǥ���� �� �ִ� �����츦 �����ش�. ù��° ������ �̸� ����, �ι�° ������ ������ ����  www.qt.io/ko-kr/

	imshow("img", img); // Mat ����ü �� �̹����� ���� ������ �ִٸ� imgshow�� ���� ȭ�鿡 ���
	waitKey(0);  //Ű �Է��� ���� ������ ��ٸ��� �Լ�, �и������� ������ ����ϴ� ��, 0 �Ǵ� ������ ������ �� ��� Ű �Է��� ������ ��ٸ��� ����

	destroyWindow("img");  //�����츦 �ݰ� ���õ� ��� �޸� ��뿡 ���� �����ϴ� ������ ���ش�.

	return 0;
}
//https://nowonbun.tistory.com/745
//https://hu-coding.tistory.com/5