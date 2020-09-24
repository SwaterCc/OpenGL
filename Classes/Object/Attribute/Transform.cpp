#include "Transform.h"

void Transform::update()
{
	auto modelOfUpdate = glmath::mat4(1);
	modelOfUpdate = glmath::scaling(modelOfUpdate, scale);
	for (int i = 0; i < 3; i++)
	{
		glmath::vec3 rotateAxle;
		rotateAxle[i] = 1;
		modelOfUpdate = glmath::rotation(modelOfUpdate, radios(rotate[i]), rotateAxle);
	}
	modelOfUpdate = glmath::translation(modelOfUpdate, { position,0 });
	model = modelOfUpdate;
}

glmath::mat4 Transform::getModelMatrix()
{
	return model;
}

Transform::Transform():
	position(0),rotate(0),scale(1),model(1)
{
}
