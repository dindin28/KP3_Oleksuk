// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include <KP2/sawing_option.h>

std::string SawingOptionToString(SawingOption option)
{
  std::string return_str;
  switch (option)
  {
  case (kBeam):
  {
    return_str = "Beam";
    break;
  }
  case (kUnedgedBoard):
  {
    return_str = "Unedged Board";
    break;
  }
  case (kEdgedBoard):
  {
    return_str = "Edged Board";
    break;
  }
  case (kRail):
  {
    return_str = "Rail";
    break;
  }
  }

  return return_str;
} // Function (SawingOptionToString)

SawingOption IntToSawingOption(int option)
{
  SawingOption return_option;
  switch (option)
  {
  case (kBeam):
  {
    return_option = kBeam;
    break;
  }
  case (kUnedgedBoard):
  {
    return_option = kUnedgedBoard;
    break;
  }
  case (kEdgedBoard):
  {
    return_option = kEdgedBoard;
    break;
  }
  case (kRail):
  {
    return_option = kRail;
    break;
  }
  }

  return return_option;
} // Function (IntToSawingOption)