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

	void createSence(SenceType type);
	void setWinSize(Size size) { m_WindowSize = size; }
	Size getWinSize() { return m_WindowSize; }
private:
	RenderPiplineManager();
	~RenderPiplineManager();
private:
	static RenderPiplineManager* m_pInstance;
	static int m_nListCount;

	Camera * m_pDefaultCamera;
	CameraList m_CameraList;

	RenderingList m_RenderingList;
	GLShaderProgreamCatch* m_pProgramCatchInstance;
	//SenceList m_SenceList;
	Size m_WindowSize;
};



#endif

