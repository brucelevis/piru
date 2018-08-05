#ifndef _CONSTANTS_H
#define _CONSTANTS_H

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define DUNGEON_SIZE 112
#define MAX_NODES 300
#define MAX_PATH_LENGTH 25
#define MAX_DAMAGE_TEXT 50
#define TILE_WIDTH 64
#define TILE_HEIGHT 32
#define WALL_WIDTH 64
#define WALL_HEIGHT 128
#define TILE_WIDTH_HALF (TILE_WIDTH / 2)
#define TILE_HEIGHT_HALF (TILE_HEIGHT / 2)
#define WALL_WIDTH_HALF (WALL_WIDTH / 2)
#define WALL_HEIGHT_HALF (WALL_HEIGHT / 2)

#define CUTOFF_X 14
#define CUTOFF_Y 14
#define MAX_DUNGEON_ROOMS 25600
#define MAX_ROOM_SIZE 30
#define MIN_ROOM_SIZE 10
#define MAX_MONSTERS 1024

#define WALL_NORTH_WEST 1 << 0
#define WALL_NORTH_EAST 1 << 1
#define WALL_SOUTH_EAST 1 << 2
#define WALL_SOUTH_WEST 1 << 3

#endif