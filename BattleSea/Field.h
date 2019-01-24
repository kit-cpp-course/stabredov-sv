#pragma once

enum Cell {
	C_EMPTY,
	C_SHIP,
	C_DOT,
	C_BROKEN,
	C_PREVIEW
};
class Field {
	Cell field[10][10];
public:
	Field();
	void SetShip(int x, int y, Cell cell);
	Cell GetShip(int x, int y);
};