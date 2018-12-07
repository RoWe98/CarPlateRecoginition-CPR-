//Code by RoWe98
//Date: 2018/12/7 

#include "OpencvCar.h"
using namespace std;
int main()
{
	IplImage *src;   //原始图片                        
	IplImage *pImgCanny; //二值化的图   
	IplImage *pImgResize;  //归一化的车牌区域灰度图                  
	IplImage *pImgCharOne;  //字符图片             
	IplImage *pImgCharTwo;
	IplImage *pImgCharThree;
	IplImage *pImgCharFour;
	IplImage *pImgCharFive;
	IplImage *pImgCharSix;
	IplImage *pImgCharSeven;
	
	OpencvCar cvCar;
	src = NULL;
	const char *filepath;
	filepath = "C:\\Users\\RexRowe\\Desktop\\opencvCar\\opencvCar\\图片\\car1.jpg";  //等待识别的图片位置
	src = cvLoadImage(filepath);
	cvNamedWindow("原图像");
	cvShowImage("原图像",src);

	pImgCanny = cvCreateImage(cvSize(src->width, src->height), IPL_DEPTH_8U, 1);     //  2值化后图片大小初始化
	cvCvtColor(src, pImgCanny, CV_RGB2GRAY);  //转化为灰度图  openCV函数 Y = 0.299*R + 0.587*G + 0.114*B                                                     //  转为灰度图	  Y=0.299*R + 0.587*G + 0.114*B
	cvSmooth(pImgCanny, pImgCanny, CV_GAUSSIAN, 3, 0, 0);   //平滑高斯滤波  滤波后的图片保存在 pImgCanny

	
	//二值化
	cvCar.Threshold(pImgCanny, pImgCanny);
	cvNamedWindow("二值化图像");
	cvShowImage("二值化图像", pImgCanny);


	//车牌定位
	cvCar.PlateAreaSearch(pImgCanny,src);

	//字符分割并识别
	cvCar.SegmentPlate();


	return 0;
}
