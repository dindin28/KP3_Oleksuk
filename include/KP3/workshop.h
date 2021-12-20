#ifndef _KP2_INCLUDE_KP2_WORKSHOP_H_
#define _KP2_INCLUDE_KP2_WORKSHOP_H_

#include <KP2/lumber.h>

class Workshop
{
public:
  // Default constructor(with no parameters)
  Workshop();

  // Constructor with parameters
  Workshop(int workshop_serial_number);

  // Copy constructor
  Workshop(const Workshop &copy);

  // Destructor
  ~Workshop();

  // operator=
  Workshop &operator=(const Workshop &copy);

  // Setters
  Workshop &SetWorkshopSerialNumber(const int workshop_serial_number);
  Workshop &SetNewPointer(const Lumber *pointer, const size_t size);

  // Getters
  int GetShopsCount() const;
  int GetWorkshopSerialNumber() const;
  int GetSize() const;

  // Function for printing class info
  void Print();
  void PrintShortly();

  // Other functions
  void AddLumber(const Lumber value);
  bool RemoveWood(const Wood value); // return if there is wood in lumber

  Lumber &operator[](const int index);

private:
  static int workshops_count_;
  int workshop_serial_number_;
  Lumber *pointer_;
  size_t size_;
}; // Class (Workshop)

#endif // Header Guard