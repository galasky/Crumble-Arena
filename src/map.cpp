#include "map.hpp"

map::map()
{
  int	i = 0;

  _path = "materials/maps/";
  _case = new t_case*[34];

  while (i < 34)
    {
      _case[i] = new t_case[60];
      i++;
    }
}

map::~map()
{

}

void		map::load_defines(std::string n_map)
{
  char		str[256] = {0};
  char		nb[32] = {0};
  std::string	line = "first";
  std::string	defines;
  int		i = 0;
  int		u;
  int		v;

  defines += _path;
  defines += n_map;
  defines += "/defines";
  _is.open(defines.c_str());
  _is.getline(str, 256);
  while (str[i] != '=')
    i++;
  while (str[++i])
    _image[0].name += str[i];
  _image[0].texture.loadFromFile(_path + n_map + "/" + _image[0].name);
  _image[0].sprite.setTexture(_image[0].texture);
  _image[0].sprite.setPosition(0, 0);
  i = 1;
  while (line != "/")
    {
      _is.getline(str, 256);
      line = str;
      if (line != "/")
	{
	  u = -1;
	  while (str[++u] != '=')
	    _image[i].symbol += str[u];
	  while (str[++u] != ' ')
	    _image[i].name += str[u];
	  v = 0;
	  while (str[++u] != ' ')
	    nb[v++] = str[u];
	  nb[v] = '\0';
	  _image[i].f = atof(nb);
	  v = 0;
	  while (str[++u])
	    nb[v++] = str[u];
	  _image[i].r = atof(nb);
	  _image[i].texture.loadFromFile(_path + n_map + "/" + _image[i].name);
	  _image[i].sprite.setTexture(_image[i].texture);
	}
      i++;
    }
  _image[i].name = "NULL";
  _image[i].symbol = "NULL";
  _is.close();
}

void	map::load_world(std::string n_map, player pl[2])
{
  char          str[256];
  std::string   line = "first";
  std::string   world;
  int           i = 0;
  int           u;

  world += _path;
  world += n_map;
  world += "/world";
  _is.open(world.c_str());
  while (line != "/")
    {
      _is.getline(str, 256);
      line = str;
      if (line != "/")
        {
          u = -1;
	  while (str[++u])
	    {
	      _case[i][u].n = n_image(str[u], _image);
	      _case[i][u].f = f_image(str[u], _image);
	      _case[i][u].r = r_image(str[u], _image);
	      _case[i][u].p.x = u * 32;
	      _case[i][u].p.y = i * 32;
	      if (_case[i][u].n == -1)
		{
		  pl[0].set_pos(u * 32, i * 32);
		}
	      else if (_case[i][u].n == -2)
		{
		  pl[1].set_pos(u * 32, i * 32);
		}
	    }
        }
      i++;
    }
  _is.close();
}

void	map::refresh(sf::RenderWindow &app)
{
  int	x, y = 0;

  app.draw(_image[0].sprite);
  while (y < 34)
    {
      x = 0;
      while (x < 60)
	{
	  if (_case[y][x].n != VIDE && _case[y][x].n > 0)
	    {
	      _image[_case[y][x].n].sprite.setPosition(_case[y][x].p.x, _case[y][x].p.y);
	      app.draw(_image[_case[y][x].n].sprite);
	    }
	  x++;
	}
      y++;
    }
}
