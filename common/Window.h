#ifndef	WINDOW_H
#define WINDOW_H

//Device TYPe
typedef enum 
{
	NONE,
	OPENGLES2,
	OPENGLES3,
	METAL
}DeviceType;

class  IWindow
{
public:
	//iWidth,iHeight���ڿ�Ⱥ͸߶�
	//dt:�봴�����豸
	virtual bool			CreateWindow(int iWidth, int iHeight, DeviceType  dt)=0;
	virtual DeviceType		GetDeviceType() = 0;
	virtual void            Update() = 0;
	virtual void            Render() = 0;
};
#endif