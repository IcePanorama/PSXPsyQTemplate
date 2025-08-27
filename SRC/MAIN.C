/*  Copyright (C) 2025  SegFaultedDreams
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include "sfd_ints.h"
#include "sfd_rndr.h"
#include "sfd_tick.h"

#include <stdio.h>

int
main (void)
{
  u32_t u32Prev, u32Curr, u32Elapsed;
  u32_t u32Lag = 0;

  puts ("Hello World!\n");
  SFDRndrInit ();
  u32Prev = SFD_GET_TICKS ();
  while (1)
  {
    u32Curr = SFD_GET_TICKS ();
    u32Elapsed = u32Curr - u32Prev;
    u32Prev = u32Curr;
    u32Lag += u32Elapsed;

    while (u32Lag >= (SFD_TICKS_PER_UPDATE))
    {
      u32Lag -= (SFD_TICKS_PER_UPDATE);
    }

    SFDDrawFrm ();
  }

  return 0;
}
