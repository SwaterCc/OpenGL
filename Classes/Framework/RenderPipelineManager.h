#ifndef _RenderPiplineManager_H_
#define _RenderPiplineManager_H_

#include "../Include/Include.h"
#include "../Include/makeFileInclude.h"
#include "../Camera/Camera.h"
#include <map>


class ObjectBase;
class Sence;
class GLShaderProgreamCatch;
//typedef std::map<SenceType, Sence*> SenceList;
typedef std::map<int,ObjectBase*> RenderingList;
typedef std::map<int, Camera*> CameraList;

class RenderPiplineManager
{
public:
	static RenderPiplineManager* getInstance();
	void mainLoop();
	void addObjectToList(ObjectBase * object,int & tag);
	void removeObjectAtIndex(int idx);

	void addCameraToList(Camera* obj);
	void removeCameraAtIndex(int idx);
	void createMainCamera();

	void createSence(SenceType type);
	void setWinSize(Size size) { m_WindowSize = size; }
	Size getWinSize() { return m_WindowSize; }

	void setMainCamera(Camera* c);
private:
	RenderPiplineManager();
	~RenderPiplineManager();
private:
	static RenderPiplineManager* m_pInstance;
	static int m_nRenderListCount;
	static int m_nCameraListCount;

	Camera * m_pMainCamera;
	CameraList m_CameraList;

	RenderingList m_RenderingList;
	GLShaderProgreamCatch* m_pProgramCatchInstance;
	//SenceList m_SenceList;
	Size m_WindowSize;
};



#endif

