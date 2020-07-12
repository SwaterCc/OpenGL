#ifndef _RenderPiplineManager_H_
#define _RenderPiplineManager_H_

#include "../Include/Include.h"

#include <map>

class ObjectBase;
class Sence;
class GLShaderProgreamCatch;
//typedef std::map<SenceType, Sence*> SenceList;
typedef std::map<int,ObjectBase*> RenderingList;

class RenderPiplineManager
{
public:
	static RenderPiplineManager* getInstance();
	void mainLoop();
	void addObjectToList(ObjectBase * object,int & tag);
	void removeObjectAtIndex(int idx);

	void createSence(SenceType type);
private:
	RenderPiplineManager();
	~RenderPiplineManager();
private:
	static RenderPiplineManager* m_pInstance;
	static int m_nListCount;

	RenderingList m_RenderingList;
	GLShaderProgreamCatch* m_pProgramCatchInstance;
	//SenceList m_SenceList;
};



#endif

