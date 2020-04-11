#include "Block.h"
#include <assert.h>

void Block::Constructor(int _x, int _y, Block::Type _type)
{
	assert(inhibit == false); //If this assert has activated it means that somewhere someone wants to initialize this block again
	this->x = _x;
	this->y = _y;
	this->type = _type;
	inhibit = true;
}
