//Code by RoWe98
//Date: 2018/12/7 


#pragma once
#pragma comment (lib, "cxcore.lib")
#pragma comment (lib, "cv.lib")
#pragma comment (lib, "ml.lib")
#pragma comment (lib, "cvaux.lib")
#pragma comment (lib, "highgui.lib")
#pragma comment (lib, "cvcam.lib")

#include "cv.h"
#include "highgui.h"
#include "iostream"
#include "string"

using namespace std;

#define DEBUGTEST
#define POINT_X  18                                           // 水平方向不重叠点                        
#define POINT_Y  2                                            // 垂直方向不重叠点                            
#define WITH_X 0.1                                            // 水平方向车牌在图区域     
#define WITH_Y 0.2                                            // 垂直方向车牌在图区域     
#define HIGH_WITH_CAR   4.8   //(440/85)       // 小车的宽高比  440/140    
#define CHARACTER 15
#define TEMPLETENUM  43

class OpencvCar
{
public:
	OpencvCar();
	int CodeRecognize(IplImage *imgTest, int num, int char_num); //字符识别
	int SegmentPlate();								//字符分割
	int PlateAreaSearch(IplImage *pImg_Image, IplImage *src);		//车牌定位
	void Threshold(IplImage *Image, IplImage *Image_O);	//二值化
	int AdaptiveThreshold(int t, IplImage *Image);		//自适应阈值法
	void DrawPicToHDC(IplImage *img, UINT ID);			//把图像显示在 MFC图片控件里
protected:
	IplImage *src;                                // 原始图片
	IplImage *pImgCanny;                      //二值化的图
	IplImage *pImgResize;                     //归一化的车牌区域灰度图
	IplImage *pImgCharOne;                // 字符图片
	IplImage *pImgCharTwo;
	IplImage *pImgCharThree;
	IplImage *pImgCharFour;
	IplImage *pImgCharFive;
	IplImage *pImgCharSix;
	IplImage *pImgCharSeven;
};
