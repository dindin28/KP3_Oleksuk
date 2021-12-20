#ifndef _KP2_INCLUDE_KP2_WOOD_H_
#define _KP2_INCLUDE_KP2_WOOD_H_

#include <iostream>

class Wood
{
public:
  // Default constructor(with no parameters)
  Wood();

  // Constructor with parameters
  Wood(const char *tree_species, int wood_moisture, int wood_density);

  // Copy constructor
  Wood(const Wood &copy);

  // operator =
  Wood &operator=(const Wood &copy);

  // Destructor
  ~Wood();

  // Setters
  Wood &SetTreeSpecies(const char *tree_species);
  Wood &SetWoodMoisture(int wood_moisture);
  Wood &SetWoodDensity(int wood_density);

  // Getters
  const char *GetTreeSpecies() const;
  int GetWoodMoisture() const;
  int GetWoodDensity() const;

  // Function to print class info
  void Print();

  // Operators
  bool operator==(const Wood &copy);
  bool operator!=(const Wood &copy);

  friend std::ostream &operator<<(std::ostream &out, const Wood &copy);
  friend std::istream &operator>>(std::istream &in, Wood &copy);

private:
  char *tree_species_;
  int wood_moisture_, wood_density_;
}; // Class(Wood)

#endif // Header Guard