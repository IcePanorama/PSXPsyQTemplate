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
#include "sfd_rndr.h"
#include "sfd_tick.h"

#include <stdio.h>

int
main (void)
{
  unsigned long ulPrev, ulCurr, ulElapsed;
  unsigned long ulNFrames = 0, ulLag = 0, ulLastTicks = 0;
  unsigned char ucFPS = 1;

  puts ("Hello World!\n");
  SFDRndrInit ();
  ulPrev = SFD_GET_TICKS ();

  while (1)
  {
    ulCurr = SFD_GET_TICKS ();
    ulElapsed = ulCurr - ulPrev;
    ulPrev = ulCurr;
    ulLag += ulElapsed;

    while (ulLag >= (SFD_TICKS_PER_UPDATE))
    {
      printf ("FPS: %d\n", ucFPS);
      ulLag -= (SFD_TICKS_PER_UPDATE);
    }

    SFDDrawFrm ();

    ulNFrames++;
    if ((ulCurr - ulLastTicks) >= (SFD_TICKS_PER_SEC))
    {
      ucFPS = ulNFrames;
      ulNFrames = 0;
      ulLastTicks = ulCurr;
    }
  }

  return 0;
}
