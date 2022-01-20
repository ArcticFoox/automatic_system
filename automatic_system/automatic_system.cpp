#include<opencv2/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/videoio.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>

#include<iostream>
#include<Windows.h>


using namespace std;
using namespace cv;

class hwnd2Mat
{
public:
    hwnd2Mat(HWND hwindow, float scale = 1);
    virtual ~hwnd2Mat();
    virtual void read();
    Mat image;

private:
    HWND hwnd;
    HDC hwindowDC, hwindowCompatibleDC;
    int height, width, srcheight, srcwidth;
    HBITMAP hbwindow;
    BITMAPINFOHEADER  bi;
};

hwnd2Mat::hwnd2Mat(HWND hwindow, float scale)
{
    hwnd = hwindow;
    hwindowDC = GetDC(hwnd);
    hwindowCompatibleDC = CreateCompatibleDC(hwindowDC);
    SetStretchBltMode(hwindowCompatibleDC, COLORONCOLOR);

    RECT windowsize;    // get the height and width of the screen
    GetClientRect(hwnd, &windowsize);

    srcheight = windowsize.bottom;
    srcwidth = windowsize.right;
    height = (int)(windowsize.bottom * scale);
    width = (int)(windowsize.right * scale);

    image.create(height, width, CV_8UC4);

    // create a bitmap
    hbwindow = CreateCompatibleBitmap(hwindowDC, width, height);
    bi.biSize = sizeof(BITMAPINFOHEADER);    //http://msdn.microsoft.com/en-us/library/windows/window/dd183402%28v=vs.85%29.aspx
    bi.biWidth = width;
    bi.biHeight = -height;  //this is the line that makes it draw upside down or not
    bi.biPlanes = 1;
    bi.biBitCount = 32;
    bi.biCompression = BI_RGB;
    bi.biSizeImage = 0;
    bi.biXPelsPerMeter = 0;
    bi.biYPelsPerMeter = 0;
    bi.biClrUsed = 0;
    bi.biClrImportant = 0;

    // use the previously created device context with the bitmap
    SelectObject(hwindowCompatibleDC, hbwindow);
    read();
};

void hwnd2Mat::read()
{
    // copy from the window device context to the bitmap device context
    StretchBlt(hwindowCompatibleDC, 0, 0, width, height, hwindowDC, 0, 0, srcwidth, srcheight, SRCCOPY); //change SRCCOPY to NOTSRCCOPY for wacky colors !
    GetDIBits(hwindowCompatibleDC, hbwindow, 0, height, image.data, (BITMAPINFO*)&bi, DIB_RGB_COLORS);  //copy from hwindowCompatibleDC to hbwindow
};

hwnd2Mat::~hwnd2Mat()
{
    // avoid memory leak
    DeleteObject(hbwindow);
    DeleteDC(hwindowCompatibleDC);
    ReleaseDC(hwnd, hwindowDC);
};

int main()
{
    Mat ui(40, 400, CV_8UC3, Scalar(0, 130, 0));
    putText(ui, "Press Esc to stop capturing", Point(30, 30), FONT_HERSHEY_COMPLEX, 0.7,
        Scalar(0, 0, 255), 1);
    Mat bgrImg;
    hwnd2Mat capDesktop(GetDesktopWindow());

    VideoWriter writer;
    int codec = VideoWriter::fourcc('X', 'V', 'I', 'D');
    double fps = 10.0;
    string filename = "./desktop_capture.avi";
    writer.open(filename, codec, fps, capDesktop.image.size(), true);
    // check if we succeeded
    if (!writer.isOpened()) {
        cerr << "Could not open the output video file for write\n";
        return -1;
    }

    while (true)
    {
        capDesktop.read();
        cvtColor(capDesktop.image, bgrImg, COLOR_BGRA2BGR);
        writer << bgrImg;
        imshow("desktop capture", ui);
        int key = waitKey(5);

        if (key == 27)
            break;
    }
}

//int main() {
//	Mat img;
//	img = imread("cat.png", IMREAD_GRAYSCALE); //파일 이름을 기바으로 파일의 포맷 결정, Mat의 형태로 변환  docs.opencv.org/4.5.1/d3/d63/classcv_1_1Mat.html
//
//	if (img.empty()) { 
//		cout << "Could not open or find the image" << endl;
//		return -1; 
//	}
//
//	Canny(img, img, 50, 150);
//	//namedWindow("img", WINDOW_AUTOSIZE);  //화면에 이미지 표시할 수 있는 윈도우를 열어준다. 첫번째 윈도우 이름 지정, 두번째 윈도우 사이즈 결정  www.qt.io/ko-kr/
//
//	imshow("img", img); // Mat 구조체 상에 이미지에 대한 정보가 있다면 imgshow를 통해 화면에 출력
//	waitKey(5000);  //키 입력이 있을 때까지 기다르는 함수, 밀리세컨드 단위로 대기하는 것, 0 또는 음수로 설정이 될 경우 키 입력을 무한히 기다리는 형태
//
//
//	//double t = (double)getTickCount();
//	//// do something ...
//	//t = ((double)getTickCount() - t) / getTickFrequency();
//	//cout << "Times passed in seconds: " << t << endl;
//	return 0;
//	
//}
//https://nowonbun.tistory.com/745
//https://hu-coding.tistory.com/5
//https://docs.opencv.org/4.x/d6/d6d/tutorial_mat_the_basic_image_container.html
//https://stackoverflow.com/questions/14148758/how-to-capture-the-desktop-in-opencv-ie-turn-a-bitmap-into-a-mat
//https://github.com/sturkmen72/opencv_samples/blob/master/Screen-Capturing.cpp

//terminal error code is no problem to operate application