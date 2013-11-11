#ifndef _MAIN_H
#define _MAIN_H

#include <windows.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glew.h>
//#include <glfw.h>
#include <GL/gl.h>
#include <fstream>
#include <vector>
#include <GL/glaux.h>
#include <crtdbg.h>
#include <string.h>
#include "ObjReader.h"

#pragma comment(lib, "glew32.lib")

using namespace std;

#define SCREEN_WIDTH 512								
#define SCREEN_HEIGHT 512								
#define SCREEN_DEPTH 16									

#define MAX_TEXTURES 100								// ����������Ŀ

// ����3D����࣬���ڱ���ģ���еĶ���
class CVector3 
{
public:
	float x, y, z;
};

// ����2D���࣬���ڱ���ģ�͵�UV��������
class CVector2 
{
public:
	float x, y;
};

//  ��Ľṹ����
struct tFace
{
	int vertIndex[3];			// ��������
	int coordIndex[3];			// ������������
};

//  ������Ϣ�ṹ��
struct tMaterialInfo
{
	char  strName[255];			// ��������
	char  strFile[255];			// �����������ӳ�䣬���ʾ�����ļ�����
	BYTE  color[3];				// �����RGB��ɫ
	int   texureId;				// ����ID
	float uTile;				// u �ظ�
	float vTile;				// v �ظ�
	float uOffset;			    // u ����ƫ��
	float vOffset;				// v ����ƫ��
} ;

//  ������Ϣ�ṹ��
struct t3DObject 
{
	int  numOfVerts;			// ģ���ж������Ŀ
	int  numOfFaces;			// ģ���������Ŀ
	int  numTexVertex;			// ģ���������������Ŀ
	int  materialID;			// ����ID
	bool bHasTexture;			// �Ƿ��������ӳ��
	char strName[255];			// ���������
	CVector3  *pVerts;			// ����Ķ���
	CVector3  *pNormals;		// ����ķ�����
	CVector2  *pTexVerts;		// ����UV����
	tFace *pFaces;				// ���������Ϣ
};

//  ģ����Ϣ�ṹ��
struct t3DModel 
{
	int numOfObjects;					// ģ���ж������Ŀ
	int numOfMaterials;					// ģ���в��ʵ���Ŀ
	vector<tMaterialInfo> pMaterials;	// ����������Ϣ
	vector<t3DObject> pObject;			// ģ���ж���������Ϣ
};


extern bool  g_bFullScreen;									
extern HWND  g_hWnd;										
extern RECT  g_rRect;										
extern HDC   g_hDC;											
extern HGLRC g_hRC;											
extern HINSTANCE g_hInstance;								

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hprev, PSTR cmdline, int ishow);
LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
WPARAM MainLoop();

// ���������������䱣��������������
void CreateTexture(UINT textureArray[], LPSTR strFileName, int textureID);

// �ı���ʾΪȫ��ģʽ
void ChangeToFullScreen();

// �����û�����
HWND CreateMyWindow(LPSTR strWindowName, int width, int height, DWORD dwStyle, bool bFullScreen, HINSTANCE hInstance);

// �������ظ�ʽ
bool bSetupPixelFormat(HDC hdc);

// ��ʼ��ͶӰ�任
void SizeOpenGLScreen(int width, int height);

// ��ʼ��OpenGL
void InitializeOpenGL(int width, int height);

// ��ʼ����������
void Init(HWND hWnd);

// ��Ⱦ����
void RenderScene();

// �ͷų���ռ�õ��ڴ�ռ�
void DeInit();

#endif