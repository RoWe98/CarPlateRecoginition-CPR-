//Code by RoWe98
//Date: 2018/12/7 

#include "OpencvCar.h"
using namespace std;
int main()
{
	IplImage *src;   //ԭʼͼƬ                        
	IplImage *pImgCanny; //��ֵ����ͼ   
	IplImage *pImgResize;  //��һ���ĳ�������Ҷ�ͼ                  
	IplImage *pImgCharOne;  //�ַ�ͼƬ             
	IplImage *pImgCharTwo;
	IplImage *pImgCharThree;
	IplImage *pImgCharFour;
	IplImage *pImgCharFive;
	IplImage *pImgCharSix;
	IplImage *pImgCharSeven;
	
	OpencvCar cvCar;
	src = NULL;
	const char *filepath;
	filepath = "C:\\Users\\RexRowe\\Desktop\\opencvCar\\opencvCar\\ͼƬ\\car1.jpg";  //�ȴ�ʶ���ͼƬλ��
	src = cvLoadImage(filepath);
	cvNamedWindow("ԭͼ��");
	cvShowImage("ԭͼ��",src);

	pImgCanny = cvCreateImage(cvSize(src->width, src->height), IPL_DEPTH_8U, 1);     //  2ֵ����ͼƬ��С��ʼ��
	cvCvtColor(src, pImgCanny, CV_RGB2GRAY);  //ת��Ϊ�Ҷ�ͼ  openCV���� Y = 0.299*R + 0.587*G + 0.114*B                                                     //  תΪ�Ҷ�ͼ	  Y=0.299*R + 0.587*G + 0.114*B
	cvSmooth(pImgCanny, pImgCanny, CV_GAUSSIAN, 3, 0, 0);   //ƽ����˹�˲�  �˲����ͼƬ������ pImgCanny

	
	//��ֵ��
	cvCar.Threshold(pImgCanny, pImgCanny);
	cvNamedWindow("��ֵ��ͼ��");
	cvShowImage("��ֵ��ͼ��", pImgCanny);


	//���ƶ�λ
	cvCar.PlateAreaSearch(pImgCanny,src);

	//�ַ��ָʶ��
	cvCar.SegmentPlate();


	return 0;
}
