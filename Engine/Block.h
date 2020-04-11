#pragma once

class Block
{
public:
	//Variables
	enum class Type
	{
		Air,
		Dirt,
		Grass,
		Stone
	};
	int x;
	int y;
	Type type;
public:
	//Functions
	void Constructor(int _x, int _y, Type _type); //I made this function instead of using a constructor becasue the constructor can't be used on a array of blocks
private:
	//Variables
	bool inhibit = false;
private:
	//Functions
};