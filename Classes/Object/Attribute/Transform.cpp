#include "Transform.h"

void Transform::update()
{
	model = glmath::mat4(1);
	model = glmath::scaling(model, scale);
	for (int i = 0; i < 3; i++)
	{
		glmath::vec3 rotateAxle;
		rotateAxle[i] = 1;
		model = glmath::rotation(model, radios(rotate[i]), rotateAxle);
	}
	model = glmath::translation(model, { position,0 });
	
	mvp_mat = model;
}

glmath::mat4 & Transform::getMVPMatrix()
{
	return mvp_mat;
}

glmath::mat4 & Transform::getUpdateModelMatrix()
{
	return model;
}

Transform::Transform():
	position(0),rotate(0),scale(1), mvp_mat(1),model(1)
{

}
