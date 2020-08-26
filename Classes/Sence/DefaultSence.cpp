#include "DefaultSence.h"

DefaultSence* DefaultSence::create()
{
	DefaultSence* p = new DefaultSence;
	return p;
}

void DefaultSence::init()
{
	Square* square_1 = Square::create();
	square_1->addToRenderingList();
	this->removeObjectOfTarget(square_1->getRenderTag());
	
	Triangle_Vertex vex_1;
	vex_1.p1 = { v3(0.5f,0.5f,0),c4(1,0,0,0.5) };
	vex_1.p2 = { v3(0.5f,-0.4f,0),c4(0,1,0,0.5) };
	vex_1.p3 = { v3(-0.5f,0.5f,0),c4(0,0,1,0.5) };

	Triangle_Vertex vex_2;
	vex_2.p1 = { v3(-0.5,0.4f,0),c4(1,0,0,0.5) };
	vex_2.p2 = { v3(-0.5f,-0.5f,0),c4(0,1,0,0.5) };
	vex_2.p3 = { v3(0.5f,-0.5f,0),c4(0,0,1,0.5) };
	
	auto* triangle_top = Triangle::create(vex_1);
	//triangle_top->addToRenderingList();

	auto* triangle_down = Triangle::create(vex_2);
	//triangle_down->addToRenderingList();

	auto* sprite = Sprite::create("1.jpg");
	this->addToRenderingList(sprite);
	sprite->setScale(0.5f);
	sprite->setPosition({ 540,360,0 });
	sprite->setRotate(0.3 * 3.14, { 0,0,0 });
	auto* cube = Cube::create();
	//this->addToRenderingList(cube);
}
