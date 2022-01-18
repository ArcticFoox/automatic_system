#include<opencv2/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/video.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>

#include<iostream>

using namespace std;
using namespace cv;

int main() {
	Mat img;
	img = imread("cat.png", IMREAD_GRAYSCALE); //���� �̸��� ������� ������ ���� ����, Mat�� ���·� ��ȯ  docs.opencv.org/4.5.1/d3/d63/classcv_1_1Mat.html

	if (img.empty()) { 
		cout << "Could not open or find the image" << endl;
		return -1; 
	}

	Canny(img, img, 50, 150);
	//namedWindow("img", WINDOW_AUTOSIZE);  //ȭ�鿡 �̹��� ǥ���� �� �ִ� �����츦 �����ش�. ù��° ������ �̸� ����, �ι�° ������ ������ ����  www.qt.io/ko-kr/

	imshow("img", img); // Mat ����ü �� �̹����� ���� ������ �ִٸ� imgshow�� ���� ȭ�鿡 ���
	waitKey(5000);  //Ű �Է��� ���� ������ ��ٸ��� �Լ�, �и������� ������ ����ϴ� ��, 0 �Ǵ� ������ ������ �� ��� Ű �Է��� ������ ��ٸ��� ����


	//double t = (double)getTickCount();
	//// do something ...
	//t = ((double)getTickCount() - t) / getTickFrequency();
	//cout << "Times passed in seconds: " << t << endl;
	return 0;
	
}
//https://nowonbun.tistory.com/745
//https://hu-coding.tistory.com/5
//https://docs.opencv.org/4.x/d6/d6d/tutorial_mat_the_basic_image_container.html

//terminal error code is no problem to operate application