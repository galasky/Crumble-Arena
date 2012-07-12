#include "map.hpp"
#include "player.hpp"
#include <math.h>

int	ok(map &map, player &pl);
void	droite(map &map, player &pl);
void	gauche(map &map, player &pl);
void	slow_droite(map &map, player &pl);
void	slow_gauche(map &map, player &pl);

int	colision(int dx, int dy, int lx, int ly, map &map, player &pl)
{
  int	x = 0, y = 0;
  int	cx, cy;

  while (x < lx)
    {
      cx = (pl._pos.x + dx + x) / 32;
      cy = (pl._pos.y + dy) / 32;
      if (map._case[cy][cx].n != VIDE && map._case[cy][cx].n > 0)
	return (1);
      x++;
    }
  while (y < ly)
    {
      cx = (pl._pos.x + dx) / 32;
      cy = (pl._pos.y + dy + y) / 32;
      if (map._case[cy][cx].n != VIDE && map._case[cy][cx].n > 0)
	return (1);
      y++;
    }
  return (0);
}

int	jump(float k, map &map, player &pl)
{
  pl._v.y -= 1 / pl._fj;
  pl._fj += 0.0001 / k;
  if (pl._v.y >= 0)
    {
      pl._v.y = 0;
      pl._fj = 1;
      pl._jumping = 2;
    }
}

void	gravity(map &map, player &pl)
{
  if (!colision(1,32,31,0, map, pl) && pl._jumping)
    {
      if (pl._v.y < 1)
        pl._v.y += 1;
    }
  else
    {
      if (!pl._dpl[2])
	pl._jumping = 0;
      pl._v.y = 0;
      pl._fj = 1;
    }
  if (colision(0,31,32,0,map,pl))
    pl._pos.y -= 1;
}

void	deplacement(map &map, player &pl)
{
  if (pl._dpl[0])
    droite(map, pl);
  else
    slow_droite(map, pl);
  if (pl._dpl[1])
    gauche(map, pl);
  else
    slow_gauche(map, pl);
  if (pl._dpl[2])
    {
      if (!pl._jumping && colision(1,32,31,0,map,pl))
	pl._jumping = 1;
    }
  if (!pl._dpl[2] && colision(1,32,31,0,map,pl))
    {
      pl._jumping = 0;
    }
  if (!pl._dpl[2] && !colision(1,32,31,0,map,pl))
    {
      pl._jumping = 2;
    }
  if (pl._jumping == 1 && !colision(0,-1,32,0,map,pl))
    jump(3, map, pl);
}
