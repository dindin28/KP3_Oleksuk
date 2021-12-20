#include <KP3/workshop.h>
#include <iomanip>

#include <iostream>

int main()
{
  Lumber lumber1;
  Lumber lumber2;
  Lumber lumber3;
  lumber3.SetWood(Wood("Birch", 0, 0));
  lumber3.SetCost(1000);
  std::cout << "Lumber1: " << lumber1 << std::endl;
  std::cout << "Lumber2: " << lumber2 << std::endl;
  std::cout << "Lumber3: " << lumber3 << std::endl << std::endl;

  std::cout << "Lumber1 + Lumber2 = " << (lumber1 + lumber2) << std::endl;
  std::cout << "Lumber1 + Lumber3 = " << (lumber1 + lumber3) << std::endl << std::endl;

  std::cout << std::setfill('-') << std::setw(100) << '\0' << std::endl << std::endl;

  std::cout << "Lumber1 > Lumber3 : " << (lumber1 > lumber3) << std::endl;
  std::cout << "Lumber1 < Lumber3 : " << (lumber1 < lumber3) << std::endl << std::endl;

  std::cout << std::setfill('-') << std::setw(100) << '\0' << std::endl << std::endl;

  Wood wood1;
  Wood wood2;
  wood1.SetWoodDensity(15);
  std::cout << "Wood1: " << lumber1 << std::endl;
  std::cout << "Wood2: " << lumber2 << std::endl << std::endl;

  std::cout << "Wood1 == Wood2 : " << (wood1 == wood2) << std::endl;
  std::cout << "Wood1 != Wood2 : " << (wood1 != wood2) << std::endl << std::endl;

  std::cout << std::setfill('-') << std::setw(100) << '\0' << std::endl << std::endl;

  Workshop workshop;
  workshop.AddLumber(Lumber());
  workshop.AddLumber(Lumber());
  workshop.AddLumber(Lumber());

  workshop.Print();
  std::cout << std::endl << std::endl;

  workshop[1].SetCost(1000);

  std::cout << "Workshop after \"workshop[1].SetCost(1000)\"" << std::endl;
  workshop.Print();

  std::cout << std::endl << std::setfill('-') << std::setw(100) << '\0' << std::endl << std::endl;

  Wood* wood_ptr = &lumber1;
  std::cout << "Wood class is parent for Lumber class" << std::endl;
  std::cout << "We have virtual Print() function: " << std::endl;
  std::cout << "Wood a* = &(Lumber class), a->Print(): " << std::endl;
  wood_ptr->Print();
  std::cout << std::endl;
  
  return 0;
}