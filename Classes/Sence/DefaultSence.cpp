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

}
