#ifndef _Transform_h_
#define _Transform_h_

#include"AttributeModule.h"
#include "../../Utility/glmath/glmathlib.h"
class Transform : public AttributeModule
{
public: 
	virtual void update() override;

	glmath::mat4 & getMVPMatrix();
	glmath::mat4 & getUpdateModelMatrix();
public:
	Transform();
public:
	glmath::vec3 position;
	glmath::vec3 scale;
	glmath::vec3 rotate;
private:
	glmath::mat4 model;
	glmath::mat4 mvp_mat;
};


#endif // !_Transform_h_

