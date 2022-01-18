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
	img = imread("cat.png", IMREAD_GRAYSCALE); //파일 이름을 기바으로 파일의 포맷 결정, Mat의 형태로 변환  docs.opencv.org/4.5.1/d3/d63/classcv_1_1Mat.html

	if (img.empty()) { 
		cout << "Could not open or find the image" << endl;
		return -1; 
	}

	Canny(img, img, 50, 150);
	//namedWindow("img", WINDOW_AUTOSIZE);  //화면에 이미지 표시할 수 있는 윈도우를 열어준다. 첫번째 윈도우 이름 지정, 두번째 윈도우 사이즈 결정  www.qt.io/ko-kr/

	imshow("img", img); // Mat 구조체 상에 이미지에 대한 정보가 있다면 imgshow를 통해 화면에 출력
	waitKey(5000);  //키 입력이 있을 때까지 기다르는 함수, 밀리세컨드 단위로 대기하는 것, 0 또는 음수로 설정이 될 경우 키 입력을 무한히 기다리는 형태


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