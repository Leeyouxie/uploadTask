#include <iostream>
//#include "cv.h"
//#include <cxcore.h>
//#include <highgui.h>
#include <opencv2/opencv.hpp>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    IplImage* pImg;
    pImg = cvLoadImage("E:\\Test\\test\\lena.jpg");

    //定义两个大小自由的窗口
    cvNamedWindow("Image-in",CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Image-out",CV_WINDOW_AUTOSIZE);
    //显示原始的lena.jpg
    cvShowImage("Image-in",pImg);
    //分配空间存储处理后的lena图像
    IplImage *out=cvCreateImage(cvGetSize(pImg),IPL_DEPTH_8U,3);
    //平滑处理函数
    cvSmooth(pImg,out,CV_GAUSSIAN,3,3,0,0);
    //显示处理后的图像
    cvShowImage("Image-out",out);

    cvWaitKey(0);

    //销毁窗口
    cvDestroyWindow("Image-in" );
    cvDestroyWindow("Image-out");

    //释放图片
    cvReleaseImage( &pImg );
    cvReleaseImage( &out );

    return 0;
}
