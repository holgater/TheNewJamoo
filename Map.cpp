//Author: Richard Holgate
//Last Updated: 8/17/2015 by Richard Holgate

#include "map.h"
#include <stdlib.h> //rand and srand
#include <time.h> //time

void Map::generate_map(int width, int height)
{
	//create empty map
	map_tiles = new Tile*[width];
	for (int i = 0; i < width; ++i)
	{
		map_tiles[i] = Tile[height];
	}

	//create the first room
	this.create_rooms();
}

void Map::create_rooms()
{
	//the x and y of the room being generated
	int room_x_pos = 1;
	int room_y_pos = 1;
	//height and width of basic room
	int height = 3;
	int width = 3;
	//the position of the door
	int door_x_pos;
	int door_y_pos;
	
	//which side of the room the current door is being generated on
	//(1 = left, 2 = top, 3 = right, 4 = bottom)
	int door_side;

	//generate random seed
	srand(time(NULL));

	//continue making rooms until there's no positions left and the map is full
	while(valid_pos_remain) {
		//create a room
		create_room(room_x_pos,room_y_pos,3,3);

		//choose a random tile for a door to be placed between 1 and 4
		door_side = rand() % 4 + 1;

		//if door_side = 1, door is on the left side
		if (door_side == 1) {
			door_x_pos = room_x_pos - 1;
			door_y_pos = rand() % height + room_y_pos;
		} else 
		//if door_side = 2, door is on the top side
		if (door_side == 2) {
			door_x_pos = rand() % room_x_pos + width;
			door_y_pos = room_y_pos - 1;

		} else
		//if door_side = 3, door is on the right side
		if (door_side == 3) {
			door_x_pos = room_x_pos + height;
			door_y_pos = rand() room_y_pos + height;
		} else
		//if door_side = 4, door is on the bottom side
		if (door_side == 4) {
			door_x_pos = room_x_pos + width;
			door_y_pos = room_y_pos +height;

		}

		//create the door
		create_door(door_x_pos, door_y_pos);

		//determine the coordinates of the next room to be made
		room_x_pos = gen_room_x(door_side, door_x_pos);
		room_y_pos = gen_room_y(door_side, door_y_pos);

		//see if there's still a valid position remaining
		check_valid_pos_remains();
	}
}

//create a single room on the map
void Map::create_room(int x_pos, int y_pos, int width, int height) {


}
