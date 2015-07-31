//Author: Richard Holgate
//Last updated: 7/31/2015

#include "Game.h"
#include "Tile.h"

class Map {
public:
	void generate_map(int width, int height);
protected:
	void create_room(int x_pos, int y_pos, int width, int height);
private:
	Tile ** map_tiles;
}
