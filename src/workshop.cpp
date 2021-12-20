// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include <KP2/workshop.h>

#include <iostream>

int Workshop::workshops_count_ = 0;

// Default constructor(with no parameters)
Workshop::Workshop()
    : workshop_serial_number_(workshops_count_ + 1), size_(0), pointer_(nullptr)
{
  workshops_count_++;

  std::cout << "Workshop()" << std::endl;
}

// Constructor with parameters
Workshop::Workshop(int workshop_serial_number)
    : workshop_serial_number_(workshop_serial_number), size_(0), pointer_(nullptr)
{
  workshops_count_++;

  std::cout << "Workshop(int workshop_serial_number)" << std::endl;
}

// Copy constructor
Workshop::Workshop(const Workshop &copy)
    : size_(copy.size_), workshop_serial_number_(copy.workshop_serial_number_)
{
  pointer_ = new Lumber[size_];
  for (int i = 0; i < size_; i++)
  {
    pointer_[i] = copy.pointer_[i];
  }

  workshops_count_++;

  std::cout << "Workshop(int workshop_serial_number)" << std::endl;
}

Workshop::~Workshop()
{
  if (size_ != 0)
  {
    delete[] pointer_;
  }

  std::cout << "~Workshop()" << std::endl;
}

// operator=
Workshop &Workshop::operator=(const Workshop &copy)
{
  if (this != &copy) // Protection from leak of memory
  {
    if (size_ != 0)
    {
      delete[] pointer_;
    }

    pointer_ = new Lumber[copy.size_];
    for (int i = 0; i < copy.size_; i++)
    {
      pointer_[i] = copy.pointer_[i];
    } // For loop(i < copy.size_)

    size_ = copy.size_;
    workshop_serial_number_ = copy.workshop_serial_number_;
  } // Condition (this != &copy)

  return *this;
}

// Setters
Workshop &Workshop::SetWorkshopSerialNumber(const int workshop_serial_number)
{
  workshop_serial_number_ = workshop_serial_number;

  return *this;
}

Workshop &Workshop::SetNewPointer(const Lumber *pointer, const size_t size)
{
  if (size_ > 0)
  {
    delete[] pointer_;
  }
  pointer_ = new Lumber[size];
  for (int i = 0; i < size; i++)
  {
    pointer_[i] = pointer[i];
  }
  size_ = size;

  return *this;
}

// Getters
int Workshop::GetShopsCount() const { return workshops_count_; }
int Workshop::GetWorkshopSerialNumber() const { return workshop_serial_number_; }
int Workshop::GetSize() const { return size_; }

// Function for printing class info
void Workshop::Print()
{
  std::cout << "Workshop #" << workshop_serial_number_ << std::endl;
  if (size_ > 0)
  {
    std::cout << "Lumber:" << std::endl;
    for (int i = 0; i < size_; i++)
    {
      std::cout << i + 1 << ". ";
      pointer_[i].Print();
    }
  }
}
void Workshop::PrintShortly()
{
  std::cout << "Serial number: " << workshop_serial_number_;
  int sum = 0;
  for (int i = 0; i < size_; i++)
  {
    sum += pointer_[i].GetAmount();
  }
  std::cout << ", lumbers: " << sum << std::endl;
}

// Other functions
void Workshop::AddLumber(const Lumber value)
{
  if (size_ != 0)
  {
    Lumber *new_pointer = new Lumber[size_ + 1];
    for (int i = 0; i < size_; i++)
    {
      new_pointer[i] = pointer_[i];
    }
    new_pointer[size_] = value;
    delete[] pointer_;
    pointer_ = new_pointer;
  }
  else
  {
    pointer_ = new Lumber[1];
    pointer_[0] = value;
  }
  ++size_;
}

// return if there is toy in shop
bool Workshop::RemoveWood(const Wood value)
{
  bool is_valid_to_sell = false;
  for (int i = 0; i < size_ && is_valid_to_sell == false; i++)
  {
    if (pointer_[i].GetWood() == value)
    {
      is_valid_to_sell = true;
      if (pointer_[i].GetAmount() - 1 > 0)
      {
        pointer_[i].SetAmount(pointer_[i].GetAmount() - 1);
      }
      else
      {
        if (size_ != 1)
        {
          Lumber *new_pointer = new Lumber[size_ - 1];
          for (int j = 0, k = 0; j < size_; j++)
          {
            if (j != i)
            {
              new_pointer[k] = pointer_[j];
              k++;
            } // Condition (j != i)
          }   // for loop (j < size_)
          delete[] pointer_;
          pointer_ = new_pointer;
        }
        else
        {
          delete[] pointer_;
        }
        --size_;
      } // Condition (pointer_[i].GetCounts() - 1 > 0)
    }   // Condition (pointer_[i].GetToy() == value)
  }     // for loop (i < size_ && is_valid_to_sell == false)
  return is_valid_to_sell;
}