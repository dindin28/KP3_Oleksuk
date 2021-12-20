// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include <KP2/wood.h>

#include <cstring>
#include <iostream>

Wood::Wood()
    : wood_moisture_(0), wood_density_(80)
{
  const char *tree_species = "Pine";
  tree_species_ = new char[strlen(tree_species) + 1];
  strcpy(tree_species_, tree_species);

  std::cout << "Wood()" << std::endl;
}

// Constructor with parameters
Wood::Wood(const char *tree_species, int wood_moisture, int wood_density)
    : wood_moisture_(wood_moisture), wood_density_(wood_density)
{
  tree_species_ = new char[strlen(tree_species) + 1];
  strcpy(tree_species_, tree_species);

  std::cout << "Wood(const char *tree_species, int wood_moisture, int wood_density)" << std::endl;
}

// Copy constructor
Wood::Wood(const Wood &copy)
    : wood_moisture_(copy.wood_moisture_), wood_density_(copy.wood_density_)
{
  tree_species_ = new char[strlen(copy.tree_species_) + 1];
  strcpy(tree_species_, copy.tree_species_);

  std::cout << "Wood(const Wood &copy)" << std::endl;
}

// operator =
Wood &Wood::operator=(const Wood &copy)
{
  if (this != &copy) // Protect from leak of memory when this == &copy
  {
    // Copy tree_species_
    if (strlen(tree_species_) != 0)
    {
      delete[] tree_species_;
    }
    tree_species_ = new char[strlen(copy.tree_species_) + 1];
    strcpy(tree_species_, copy.tree_species_);

    // Copy wood_moisture_
    wood_moisture_ = copy.wood_moisture_;

    // Copy wood_density_
    wood_density_ = copy.wood_density_;
  }

  return *this;
}

// Destructor
Wood::~Wood()
{
  if (strlen(tree_species_) != 0)
  {
    delete[] tree_species_;
  }

  std::cout << "~Wood()" << std::endl;
}

// Setters
Wood &Wood::SetTreeSpecies(const char *tree_species)
{
  if (strlen(tree_species_) != 0)
  {
    delete[] tree_species_;
  }
  tree_species_ = new char[strlen(tree_species) + 1];
  strcpy(tree_species_, tree_species);

  return *this;
}
Wood &Wood::SetWoodMoisture(int wood_moisture)
{
  wood_moisture_ = wood_moisture;
  return *this;
}
Wood &Wood::SetWoodDensity(int wood_density)
{
  wood_density_ = wood_density;
  return *this;
}

// Getters
const char *Wood::GetTreeSpecies() const { return tree_species_; }
int Wood::GetWoodMoisture() const { return wood_moisture_; }
int Wood::GetWoodDensity() const { return wood_density_; }

// Function to print class info
void Wood::Print()
{
  std::cout << tree_species_ << "(" << wood_moisture_ << ", " << wood_density_ << ")" << std::endl;
}

// Operators
bool Wood::operator==(const Wood &copy)
{
  return (strcmp(tree_species_, copy.tree_species_) == 0 &&
          wood_density_ == copy.wood_density_ &&
          wood_moisture_ == copy.wood_moisture_);
}
bool Wood::operator!=(const Wood &copy)
{
  return !operator==(copy);
}

std::ostream &operator<<(std::ostream &out, const Wood &copy)
{
  out << copy.GetTreeSpecies() << "(" << copy.GetWoodMoisture() << ", " << copy.GetWoodDensity() << ")";
  return out;
}

std::istream &operator>>(std::istream &in, Wood &copy)
{
  std::string buff_str;
  std::cout << "Enter Tree Species: ";
  in >> buff_str;
  copy.SetTreeSpecies(buff_str.c_str());

  int buff_int;
  std::cout << "Enter Wood Moisture: ";
  in >> buff_int;
  copy.SetWoodMoisture(buff_int);

  std::cout << "Enter Wood Density: ";
  in >> buff_int;
  copy.SetWoodDensity(buff_int);

  return in;
}