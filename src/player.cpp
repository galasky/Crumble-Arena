#include "player.hpp"

player::player()
{
  _path = "materials/players/";
  _v.x = 0;
  _v.y = 0;
  _jumping = 0;
  _fj = 1;
  for (int i = 0; i < 4; i++)
    _dpl[i] = 0;
}

player::~player()
{

}

void		player::load(std::string n_player)
{
  std::string	pl;

  pl = _path;
  pl += n_player;
  pl += "_right.jpg";

  _image[0].texture.loadFromFile(pl);
  _image[0].sprite.setTexture(_image[0].texture);

  pl = _path;
  pl += n_player;
  pl += "_left.jpg";

  _image[1].texture.loadFromFile(pl);
  _image[1].sprite.setTexture(_image[0].texture);
}

void	player::refresh(sf::RenderWindow &app)
{
  if (_v.x > 0.01 || _v.x < -0.01)
    _pos.x += _v.x;
  _pos.y += _v.y;
  _image[0].sprite.setPosition(_pos.x, _pos.y);
  app.draw(_image[0].sprite);
}

void	player::set_pos(float x, float y)
{
  _pos.x = x;
  _pos.y = y;
}

void	player::set_pos(sf::Vector2f pos)
{
  _pos.x = pos.x;
  _pos.y = pos.y;
}

sf::Vector2f	player::get_pos()
{
  return (_pos);
}
