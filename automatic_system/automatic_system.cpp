#include<opencv2/imgcodecs.hpp>
#include<opencv2/video.hpp>
#include<opencv2/highgui.hpp>

#include<iostream>
#include<stdio.h>

using namespace cv;

int main(int arg, char** argu) {
	Mat img = imread("cat.png"); //파일 이름을 기바으로 파일의 포맷 결정, Mat의 형태로 변환  docs.opencv.org/4.5.1/d3/d63/classcv_1_1Mat.html

	if (img.empty()) return -1;

	namedWindow("img", cv::WINDOW_AUTOSIZE);  //화면에 이미지 표시할 수 있는 윈도우를 열어준다. 첫번째 윈도우 이름 지정, 두번째 윈도우 사이즈 결정  www.qt.io/ko-kr/

	imshow("img", img); // Mat 구조체 상에 이미지에 대한 정보가 있다면 imgshow를 통해 화면에 출력
	waitKey(0);  //키 입력이 있을 때까지 기다르는 함수, 밀리세컨드 단위로 대기하는 것, 0 또는 음수로 설정이 될 경우 키 입력을 무한히 기다리는 형태

	destroyWindow("img");  //윈도우를 닫고 관련된 모든 메모리 사용에 대해 해제하는 역할을 해준다.

	return 0;
}
//https://nowonbun.tistory.com/745
//https://hu-coding.tistory.com/5