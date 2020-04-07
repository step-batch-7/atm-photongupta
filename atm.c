#include "atm.h"
#include <stdio.h>

unsigned int get_money(unsigned short int money)
{
  int denominations[] = {2000, 500, 100, 50, 20, 10, 5, 1};
  int remaining_amount = money;
  int no_of_notes = 0x00000000;
  if (money / denominations[0] > 15)
  {
    return no_of_notes;
  }
  for (int i = 0; i < 8; i++)
  {
    no_of_notes = no_of_notes << 4;
    no_of_notes += remaining_amount / denominations[i];
    remaining_amount = remaining_amount % denominations[i];
  }
  return no_of_notes;
}

void print_notes(unsigned int no_of_notes)
{
  int denominations[] = {2000, 500, 100, 50, 20, 10, 5, 1};
  int note_count = no_of_notes;
  for (int i = 7; i >= 0; i--)
  {
    printf("%d notes of Rs %d\n", note_count & 0xf, denominations[i]);
    note_count = note_count >> 4;
  }
}