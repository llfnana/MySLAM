#ifndef OPENGLESTEXTURE_H
#define OPENGLESTEXTURE_H

#include "ITexture.h"

class COpenGLESTexture :public ITexture
{
	COpenGLESTexture(int iWidth, int iHeight, EFormat eFormat);
	virtual  EFormat GetFormat() ;
	virtual  void WritToTexture(unsigned char* pdata);
private:
	EFormat			m_TextrueFormat;
};

#endif