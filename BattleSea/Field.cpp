#include "Field.h"


Field::Field() {
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) {
			field[i][j] = C_EMPTY;
		}
	}
}
void Field::SetShip(int x, int y, Cell cell) {
	field[x][y] = cell;
}
Cell Field::GetShip(int x, int y)
{
	return field[x][y];
}
