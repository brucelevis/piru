#include "point.h"

Point cartesian_to_isometric(const Point cartesian_point) {
  Point isometric_point;
  isometric_point.x = (cartesian_point.x - cartesian_point.y) * TILE_WIDTH_HALF;
  isometric_point.y =
      (cartesian_point.x + cartesian_point.y) * TILE_HEIGHT_HALF;
  return isometric_point;
}

Point isometric_to_cartesian(const Point isometric_point) {
  Point cartesian_point;
  double xx;
  double yy;
  xx = (((double)isometric_point.x / TILE_WIDTH_HALF) +
        ((double)isometric_point.y / TILE_HEIGHT_HALF)) /
       2.0;
  yy = (((double)isometric_point.y / TILE_HEIGHT_HALF) -
        ((double)isometric_point.x / TILE_WIDTH_HALF)) /
       2.0;
  cartesian_point.x = (int)xx;
  cartesian_point.y = (int)yy;
  return cartesian_point;
}

Point get_tile_coordinates(const Point cartesian_point) {
  Point tile_coordinates;
  tile_coordinates.x = cartesian_point.x / TILE_WIDTH;
  tile_coordinates.y = cartesian_point.y / TILE_HEIGHT;
  return tile_coordinates;
}

double get_distance(const Point a, const Point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool point_equal(const Point a, const Point b) {
  return a.x == b.x && a.y == b.y;
}

Point get_direction_from_path(enum PATH_CODE code) {
  Point point;
  point.x = 0;
  point.y = 0;
  switch (code) {
  case UP_LEFT:
    point.x--;
    point.y--;
    break;
  case UP:
    point.y--;
    break;
  case UP_RIGHT:
    point.x++;
    point.y--;
    break;
  case LEFT:
    point.x--;
    break;
  case PATH_NONE:
    break;
  case RIGHT:
    point.x++;
    break;
  case DOWN_LEFT:
    point.x--;
    point.y++;
    break;
  case DOWN:
    point.y++;
    break;
  case DOWN_RIGHT:
    point.x++;
    point.y++;
    break;
  default:
    break;
  }

  return point;
}

Point get_direction_from_player_direction(enum PLAYER_DIRECTION direction) {
  Point point;
  point.x = 0;
  point.y = 0;
  switch (direction) {
  case PLAYER_NORTH: // UP_LEFT:
    point.x--;
    point.y--;
    break;
  case PLAYER_NORTH_EAST_2: // UP:
    point.y--;
    break;
  case PLAYER_EAST:
    point.x++;
    point.y--;
    break;
  case PLAYER_NORTH_WEST_2:
    point.x--;
    break;
  case PLAYER_SOUTH_EAST_2:
    point.x++;
    break;
  case PLAYER_WEST:
    point.x--;
    point.y++;
    break;
  case PLAYER_SOUTH_WEST_2:
    point.y++;
    break;
  case PLAYER_SOUTH:
    point.x++;
    point.y++;
    break;
  default:
    break;
  }
  return point;
}

Point get_direction_to_point(const Point from, const Point to) {
  Point ret;
  ret.x = to.x - from.x;
  ret.y = to.y - from.y;

  return ret;
}

void cartesian_to_isometric_float(double cartesian_x, double cartesian_y,
                                  double *x, double *y) {
  *x = (double)(cartesian_x - cartesian_y) * TILE_WIDTH_HALF;
  *y = (double)(cartesian_x + cartesian_y) * TILE_HEIGHT_HALF;
}

void isometric_to_cartesian_float(const Point isometric_point, double *x,
                                  double *y) {
  *x = (((double)isometric_point.x / TILE_WIDTH_HALF) +
        ((double)isometric_point.y / TILE_HEIGHT_HALF)) /
       2.0;
  *y = (((double)isometric_point.y / TILE_HEIGHT_HALF) -
        ((double)isometric_point.x / TILE_WIDTH_HALF)) /
       2.0;
}

void get_normalized(const Point point, double *x, double *y) {
  if (point.x == 0 && point.y == 0) {
    *x = 0;
    *y = 0;
  }
  double length =
      sqrt((double)(point.x * point.x) + (double)(point.y * point.y));
  *x = (double)point.x / length;
  *y = (double)point.y / length;
}