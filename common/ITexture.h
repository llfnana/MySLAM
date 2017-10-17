#ifndef ITEXTURE_H
#define ITEXTURE_H

typedef enum 
{
	SLAM_RGB
}EFormat;


class ITexture
{
public:
	ITexture(int iWidth, int iHeight, EFormat eFormat) {}
	virtual  EFormat GetFormat() = 0;
	virtual  void WritToTexture(unsigned char* pdata) = 0;
};

#endif