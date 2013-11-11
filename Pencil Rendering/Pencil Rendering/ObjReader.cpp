#include "ObjReader.h"

ObjReader::ObjReader(char * FILE_NAME)
{
    //�ȶ���obj�ļ������������Ϣ���㡢��������Ϣ
    pointerdian = 1;
    pointerface = 1;
    pointerfaxiang = 1;
	NumOfFaces = 0;
    FILE * fin = fopen(FILE_NAME,"r");
    char temp[100];
	
    while(fgets(temp,99,fin) != NULL)
    {
		
		//system("pause");
        if(temp[0] == 'v')
        {
            if(temp[1] == 'n')
            {//�Ƿ�������Ϣ
                sscanf(temp,"%vn %f%f%f",&Normal[pointerfaxiang][0],
                       &Normal[pointerfaxiang][1],&Normal[pointerfaxiang][2]);
                pointerfaxiang ++;
            }
            else
            {//�ǵ���Ϣ
                sscanf(temp,"%v %f%f%f",&Point[pointerdian][0],
                       &Point[pointerdian][1],&Point[pointerdian][2]);
                pointerdian ++;
            }
        }
        if(temp[0] == 'f')
        {//�������Ϣ
            sscanf(temp,"f %d//%d %d//%d %d//%d",
                   &FacesPoint[NumOfFaces][0],&FacesNormal[NumOfFaces][0],
                   &FacesPoint[NumOfFaces][1],&FacesNormal[NumOfFaces][1],
                   &FacesPoint[NumOfFaces][2],&FacesNormal[NumOfFaces][2]);
            NumOfFaces++;
        }
    }
	fclose(fin);
    //���������ʷ���
    //�ļ�������
    char _TempFileName[100]={};
	sscanf(FILE_NAME,"%[^.]+",_TempFileName);
	strcat(_TempFileName,".txt");

	FILE * PrincipleFile = fopen(_TempFileName,"r");
	for(int ii = 1; ii<=pointerdian ;ii++)
	{
		if(fscanf(PrincipleFile,"%f%f%f",&Principle[ii][0],&Principle[ii][1],&Principle[ii][2])!=EOF)
			fscanf(PrincipleFile,"%f%f%f",&ExternPrinciple[ii][0],&ExternPrinciple[ii][1],&ExternPrinciple[ii][2]);
		else
			break;
		
	}
	fclose(PrincipleFile);
	
}

ObjReader::~ObjReader()
{
    //dtor
}
