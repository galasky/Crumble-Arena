#ifndef	__PLAYER_HPP__
#define	__PLAYER_HPP__

#include <string>
#include <fstream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "image.hpp"

class		player
{
public:

  player();
  ~player();
  void		load(std::string n_player);
  void		refresh(sf::RenderWindow &app);
  void		set_pos(float x, float y);
  void		set_pos(sf::Vector2f pos);
  sf::Vector2f	get_pos();
  int		_dpl[4];
  float		_fj;
  sf::Vector2f	_pos;
  int		_jumping;
  sf::Vector2f	_v;

private:

  std::ifstream	_is;
  std::string	_path;
  t_image	_image[2];
  int		_life;
};

#endif
