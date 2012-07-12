#ifndef	__MAP_HPP__
#define	__MAP_HPP__

#include <string>
#include <iostream>
#include <fstream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "case.hpp"
#include "image.hpp"
#include "player.hpp"

int	n_image(char c, t_image[N_IMAGE]);
float	f_image(char c, t_image[N_IMAGE]);
float	r_image(char c, t_image[N_IMAGE]);

class	map
{
public:

  map();
  ~map();
  void	load_defines(std::string n_map);
  void	load_world(std::string n_map, player pl[2]);
  void	refresh(sf::RenderWindow &app);
  void	background(char str[256]);
  t_case	**_case;

private:

  std::ifstream	_is;
  std::string	_path;
  t_image	_image[N_IMAGE];
};

#endif
