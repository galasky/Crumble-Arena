#include "image.hpp"

int		n_image(char c, t_image image[N_IMAGE])
{
  int		i = 1;
  std::string	symbol;

  symbol = c;
  while (image[i].symbol != "NULL")
    {
      if (symbol == "1")
	return (-1);
      else if (symbol == "2")
	return (-2);
      else if (image[i].symbol == symbol)
	return (i);
      i++;
    }
  return (VIDE);
}

float	f_image(char c, t_image image[N_IMAGE])
{
  int		i = 1;
  std::string	symbol;

  symbol = c;
  while (image[i].name != "NULL")
    {
      if (image[i].symbol == symbol)
        return (image[i].f);
      i++;
    }
  return (0);
}

float	r_image(char c, t_image image[N_IMAGE])
{
  int		i = 1;
  std::string	symbol;

  symbol = c;
  while (image[i].name != "NULL")
    {
      if (image[i].symbol == symbol)
        return (image[i].r);
      i++;
    }
  return (0);
}
