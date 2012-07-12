#ifndef	__IMAGE_HPP__
#define	__IMAGE_HPP__

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#define	N_IMAGE	32
#define	VIDE	42

typedef struct	s_image
{
  float		f;
  float		r;
  sf::Sprite	sprite;
  sf::Texture	texture;
  std::string	name;
  std::string	symbol;
}		t_image;

#endif
