#include "map.hpp"
#include "player.hpp"

int     colision(int dx, int dy, int lx, int ly, map &map, player &pl);

int     ok(map &map, player &pl)
{
  if (pl._v.x < 0)
    {
      if (!colision(-1, 0, 0, 32, map, pl))
        return (1);
    }
  else if (pl._v.x > 0)
    {
      if (!colision(32, 0, 0, 32, map, pl))
        return (1);
    }
  else
    return (1);
  return (0);
}

void    droite(map &map, player &pl)
{
  if (ok(map, pl))
    {
      if (pl._v.x < 1)
        pl._v.x += 0.002;
    }
  else
    {
      pl._v.x = 0;
    }
}

void    gauche(map &map, player &pl)
{
  if (ok(map, pl))
    {
      if (pl._v.x > -1)
        pl._v.x -= 0.002;
    }
  else
    {
      pl._v.x = 0;
    }
}

float	get_friction(map &map, player &pl)
{
  int	cx, cy, i = 0;
  float	max;

  cx = pl._pos.x / 32;
  cy = (pl._pos.y + 32) / 32;
  max = map._case[cy][cx].f;
  while (i < 32)
    {
      cx = (pl._pos.x + i) / 32;
      if (max < map._case[cy][cx].f)
	max = map._case[cy][cx].f;
      i++;
    }
  return (max);
}

void    slow_droite(map &map, player &pl)
{
  int   friction;

  friction = get_friction(map, pl);
  if (ok(map, pl))
    {
      if (pl._v.x > 0)
        pl._v.x -= 0.001 * friction;
    }
  else
    {
      pl._v.x = 0;
    }
}

void    slow_gauche(map &map, player &pl)
{
  int   friction;
  int cx, cy;

  cx = pl._pos.x / 32;
  cy = (pl._pos.y + 32) / 32;
  friction = get_friction(map, pl);
  if (ok(map, pl))
    {
      if (pl._v.x < 0)
        pl._v.x += 0.001 * friction;
    }
  else
    {
      pl._v.x = 0;
    }
}
