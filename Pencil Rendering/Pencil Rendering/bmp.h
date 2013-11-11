#ifndef __BMP_H__ 
#define __BMP_H__ 
 
#include <GL/gl.h>
#include <cstdio>

#define BITMAP_ID 0x4D42	//**< λͼ�ļ��ı�־ */

//** λͼ������ */
class CBMPLoader 
{
	public: 
		CBMPLoader(); 
		~CBMPLoader(); 

		bool LoadBMP(const char *filename); //**< װ��һ��bmp�ļ� */
		bool SaveBMP(const char *, GLint, GLint, GLint, GLubyte *);
		bool SaveBMP(const char *, GLint, GLint, GLfloat *);
		void FreeImage();                //**< �ͷ�ͼ������ */
 
		unsigned int ID;                 //**< ���������ID�� */
		int imageWidth;                  //**< ͼ���� */
		int imageHeight;                 //**< ͼ��߶� */
		unsigned char *image;            //**< ָ��ͼ�����ݵ�ָ�� */
};
 
#endif //__BMP_H__
