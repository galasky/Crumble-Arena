#include "window.hpp"
#include "map.hpp"
#include "player.hpp"
#include "colision.hpp"

window::window()
{
  _size.x = 160;
  _size.y = 90;
  _window_name = "crumble";
}

window::~window()
{

}

void	choice(std::string &n_map)
{
  system("clear");
  std::cout << "map :" << "\n\n";
  system("ls  materials/maps");
  std::cout << "\nchoice : ";
  std::cin >> n_map;
}

void	init(sf::RenderWindow &_app, sf::Vector2f _size)
{
  _app.clear();
  _app.create(sf::VideoMode(_size.x, _size.y, 32), "crumble", sf::Style::Fullscreen | sf::Style::Titlebar | sf::Style::Close);
  _app.display();
  _app.setFramerateLimit(600);  
}

void		window::start()
{
  map		map;
  player	pl[2];
  std::string	n_map;
  
  choice(n_map);
  init(_app, _size);
  map.load_defines(n_map);
  map.load_world(n_map, pl);
  pl[0].load("1");
  pl[1].load("2");
  while (_app.isOpen())
    {
      map.refresh(_app);
      gravity(map, pl[0]);
      gravity(map, pl[1]);
      deplacement(map, pl[0]);
      deplacement(map, pl[1]);
      pl[0].refresh(_app);
      pl[1].refresh(_app);
      _app.display();
      while (_app.pollEvent(_event))
	{
	  if (_event.type == sf::Event::KeyPressed)
	    {
	      if (_event.key.code == sf::Keyboard::Escape)
		{
		  _app.close();
		}
	      else if (_event.key.code == sf::Keyboard::D)
		{
		  pl[0]._dpl[0] = 1;
		}
	      else if (_event.key.code == sf::Keyboard::Q)
		{
                  pl[0]._dpl[1] = 1;
		}
	      else if (_event.key.code == sf::Keyboard::Space)
		{
		  pl[0]._dpl[2] = 1;
		}
	      if (_event.key.code == sf::Keyboard::Up)
		{
		  pl[1]._dpl[2] = 1;
		}
	      if (_event.key.code == sf::Keyboard::Right)
		{
		  pl[1]._dpl[0] = 1;
		}
	      if (_event.key.code == sf::Keyboard::Left)
                {
                  pl[1]._dpl[1] = 1;
                }
	    }
	  else if (_event.type == sf::Event::KeyReleased)
	    {
	      if (_event.key.code == sf::Keyboard::D)
		{
		  pl[0]._dpl[0] = 0;
		}
	      if (_event.key.code == sf::Keyboard::Q)
                {
                  pl[0]._dpl[1] = 0;
                }
	      if (_event.key.code == sf::Keyboard::Space)
		{
		  pl[0]._dpl[2] = 0;
		}
	      if (_event.key.code == sf::Keyboard::Up)
		{
		  pl[1]._dpl[2] = 0;
		}
	      if (_event.key.code == sf::Keyboard::Right)
		{
		  pl[1]._dpl[0] = 0;
		}
	      if (_event.key.code == sf::Keyboard::Left)
                {
                  pl[1]._dpl[1] = 0;
                }
	    }
	}
    }
}
