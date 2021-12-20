#ifndef _KP3_INCLUDE_KP3_SAWINGOPTION_H_
#define _KP3_INCLUDE_KP3_SAWINGOPTION_H_

#include <string>

enum SawingOption
{
  kBeam = 1,
  kUnedgedBoard = 2,
  kEdgedBoard = 3,
  kRail = 4,
};

std::string SawingOptionToString(SawingOption option);
SawingOption IntToSawingOption(int option);

#endif // Header Guard