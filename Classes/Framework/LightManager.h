#ifndef _LightManager_h_
#define _LightManager_h_

#include "../Object/Light/Light.h"
#include "../Object/Light/ParallelLight.h"
#include "../Object/Light/PointLight.h"
#include "../Object/Light/Spotlight.h"
#include <map>

const int LIGHT_MAX = 25;

class LightManager
{
public:
	static LightManager* getInstance();

	ParallelLight* getParallelLight();
	void setParallelLight(ParallelLight* p);
	std::map<unsigned int, PointLight*>& getPointLightList();
	std::map<unsigned int, Spotlight*>& getSpotlightList();
private:
	LightManager();
	static LightManager* m_pInstance;
	//应当有三种光
	//单例的平行光，平行光属于默认光
	ParallelLight* m_pl;
	//复数的点光源
	std::map<unsigned int, PointLight*> m_PointLight;
	//复数的聚光
	std::map<unsigned int, Spotlight*> m_Spotlight;
};



#endif // !_LightManager_h_
