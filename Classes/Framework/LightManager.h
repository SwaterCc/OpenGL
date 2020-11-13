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
	//Ӧ�������ֹ�
	//������ƽ�й⣬ƽ�й�����Ĭ�Ϲ�
	ParallelLight* m_pl;
	//�����ĵ��Դ
	std::map<unsigned int, PointLight*> m_PointLight;
	//�����ľ۹�
	std::map<unsigned int, Spotlight*> m_Spotlight;
};



#endif // !_LightManager_h_
