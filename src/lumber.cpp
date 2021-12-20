#include <KP3/lumber.h>

#include <iostream>

// Default constructor(with no parameters)
Lumber::Lumber()
    : Wood(), sawing_option_(kBeam), delivery_date_(Date()), marking_(0), amount_(5), cost_(100)
{}

// Constructor with parameters
Lumber::Lumber(Wood wood, SawingOption sawing_option, Date delivery_date,
               int marking, int amount, int cost)
    : Wood(wood), sawing_option_(sawing_option),
      delivery_date_(delivery_date), marking_(marking), amount_(amount), cost_(cost)
{}

// Copy constructor
Lumber::Lumber(const Lumber &copy)
    : Wood(copy.GetWood()), sawing_option_(copy.sawing_option_),
      delivery_date_(copy.delivery_date_), marking_(copy.marking_), amount_(copy.amount_), cost_(copy.cost_)
{}

Lumber::~Lumber()
{}

// Setters
Lumber &Lumber::SetWood(const Wood &wood)
{
  SetTreeSpecies(wood.GetTreeSpecies());
  SetWoodMoisture(wood.GetWoodMoisture());
  SetWoodDensity(wood.GetWoodDensity());
  return *this;
}
Lumber &Lumber::SetSawingOption(const SawingOption sawing_option)
{
  sawing_option_ = sawing_option;
  return *this;
}
Lumber &Lumber::SetDeliveryDate(const Date &delivery_date)
{
  delivery_date_ = delivery_date;
  return *this;
}
Lumber &Lumber::SetMarking(const int marking)
{
  marking_ = marking;
  return *this;
}
Lumber &Lumber::SetAmount(const int amount)
{
  amount_ = amount;
  return *this;
}
Lumber &Lumber::SetCost(const int cost)
{
  cost_ = cost;
  return *this;
}

// Getters
Wood Lumber::GetWood() const { return Wood(GetTreeSpecies(), GetWoodMoisture(), GetWoodDensity()); }
SawingOption Lumber::GetSawingOption() const { return sawing_option_; }
Date Lumber::GetDeliveryDate() const { return delivery_date_; }
int Lumber::GetMarking() const { return marking_; }
int Lumber::GetAmount() const { return amount_; }
int Lumber::GetCost() const { return cost_; }

// Function for printing class info
void Lumber::Print()
{
  std::cout << GetWood() << ", " << SawingOptionToString(sawing_option_)
            << "(" << delivery_date_ << "), "
            << "marking: " << marking_ << ", amount: "
            << amount_ << ", cost: " << cost_ << std::endl;
}

// Operators

Lumber Lumber::operator+(const Lumber& obj)
{
  if(this->GetWood() == obj.GetWood())
  {
    return Lumber(GetWood(),
                  sawing_option_,
                  delivery_date_ + obj.delivery_date_,
                  marking_ + obj.marking_,
                  amount_ + obj.amount_,
                  cost_ + obj.cost_);
  }
  return *this;
}

bool Lumber::operator<(const Lumber& obj)
{
  return cost_ < obj.cost_;
}
bool Lumber::operator>(const Lumber& obj)
{
  return cost_ > obj.cost_;
}

std::ostream &operator<<(std::ostream &out, const Lumber &copy)
{
  out << copy.GetWood() << ", " << SawingOptionToString(copy.GetSawingOption())
      << "(" << copy.GetDeliveryDate() << "), "
      << "marking: " << copy.GetMarking() << ", amount: "
      << copy.GetAmount() << ", cost: " << copy.GetCost();
  return out;
}

std::istream &operator>>(std::istream &in, Lumber &copy)
{
  // Set wood_
  Wood buff_wood;
  in >> buff_wood;
  copy.SetWood(buff_wood);

  // Set sawing_option_
  int buff_int;
  std::cout << "1 - Beam" << std::endl;
  std::cout << "2 - Unedged Board" << std::endl;
  std::cout << "3 - Edged Board" << std::endl;
  std::cout << "4 - Rail" << std::endl;
  std::cout << "Enter Sawing Option(int): ";
  in >> buff_int;
  copy.SetSawingOption(IntToSawingOption(buff_int));

  // Set delivery_date_
  Date buff_date;
  in >> buff_date;
  copy.SetDeliveryDate(buff_date);

  // Set marking_
  std::cout << "Enter marking: ";
  in >> buff_int;
  copy.SetMarking(buff_int);

  // Set amount_
  std::cout << "Enter amount: ";
  in >> buff_int;
  copy.SetAmount(buff_int);

  // Set cost_
  std::cout << "Enter cost: ";
  in >> buff_int;
  copy.SetCost(buff_int);

  return in;
}