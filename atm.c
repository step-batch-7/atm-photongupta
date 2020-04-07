#include "atm.h"

unsigned int get_money(unsigned short int money)
{
  if (money / 2000 > 15)
  {
    return 0;
  }
  int denominations[] = {2000, 500, 100, 50, 20, 10, 5, 1};
  int remainingAmount = money;
  int noOfNotes = 0x00000000;
  for (int i = 0; i < 8; i++)
  {
    noOfNotes = noOfNotes << sizeof(int);
    noOfNotes += remainingAmount / denominations[i];
    remainingAmount = remainingAmount % denominations[i];
  }
  return noOfNotes;
}
