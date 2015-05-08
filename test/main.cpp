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

    //����������С���ɵĴ���
    cvNamedWindow("Image-in",CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Image-out",CV_WINDOW_AUTOSIZE);
    //��ʾԭʼ��lena.jpg
    cvShowImage("Image-in",pImg);
    //����ռ�洢������lenaͼ��
    IplImage *out=cvCreateImage(cvGetSize(pImg),IPL_DEPTH_8U,3);
    //ƽ��������
    cvSmooth(pImg,out,CV_GAUSSIAN,3,3,0,0);
    //��ʾ������ͼ��
    cvShowImage("Image-out",out);

    cvWaitKey(0);

    //���ٴ���
    cvDestroyWindow("Image-in" );
    cvDestroyWindow("Image-out");

    //�ͷ�ͼƬ
    cvReleaseImage( &pImg );
    cvReleaseImage( &out );

    return 0;
}
