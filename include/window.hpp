#ifndef	__WINDOW_HPP__
#define	__WINDOW_HPP__

#include <iostream>
#include <string>
#include <fstream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class	window
{
public :

  window();
  ~window();
  void	start();

private :

  sf::Vector2f		_size;
  sf::RenderWindow	_app;
  std::string		_window_name;
  std::ifstream		_is;
  sf::Event		_event;
};

#endif
