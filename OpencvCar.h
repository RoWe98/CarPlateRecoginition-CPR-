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
#define POINT_X  18                                           // ˮƽ�����ص���                        
#define POINT_Y  2                                            // ��ֱ�����ص���                            
#define WITH_X 0.1                                            // ˮƽ��������ͼ����     
#define WITH_Y 0.2                                            // ��ֱ��������ͼ����     
#define HIGH_WITH_CAR   4.8   //(440/85)       // С���Ŀ�߱�  440/140    
#define CHARACTER 15
#define TEMPLETENUM  43

class OpencvCar
{
public:
	OpencvCar();
	int CodeRecognize(IplImage *imgTest, int num, int char_num); //�ַ�ʶ��
	int SegmentPlate();								//�ַ��ָ�
	int PlateAreaSearch(IplImage *pImg_Image, IplImage *src);		//���ƶ�λ
	void Threshold(IplImage *Image, IplImage *Image_O);	//��ֵ��
	int AdaptiveThreshold(int t, IplImage *Image);		//����Ӧ��ֵ��
	void DrawPicToHDC(IplImage *img, UINT ID);			//��ͼ����ʾ�� MFCͼƬ�ؼ���
protected:
	IplImage *src;                                // ԭʼͼƬ
	IplImage *pImgCanny;                      //��ֵ����ͼ
	IplImage *pImgResize;                     //��һ���ĳ�������Ҷ�ͼ
	IplImage *pImgCharOne;                // �ַ�ͼƬ
	IplImage *pImgCharTwo;
	IplImage *pImgCharThree;
	IplImage *pImgCharFour;
	IplImage *pImgCharFive;
	IplImage *pImgCharSix;
	IplImage *pImgCharSeven;
};
