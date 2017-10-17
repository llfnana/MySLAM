#include "stdafx.h"
#include "OpenGLEsTexture.h"

COpenGLESTexture::COpenGLESTexture(int iWidth, int iHeight, EFormat eFormat):ITexture(iWidth,iHeight, eFormat)
{

}


EFormat COpenGLESTexture::GetFormat()
{
	return m_TextrueFormat;
}


void COpenGLESTexture::WritToTexture(unsigned char* pdata)
{

}