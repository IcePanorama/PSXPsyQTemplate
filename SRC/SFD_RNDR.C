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

#include <sys/types.h>
#include <libgte.h>
#include <libgpu.h>
#include <libgs.h>
#include <libetc.h>

#define SCR_WIDTH   (320)
#define SCR_HEIGHT  (240)
#define OT_LEN     (4096)

struct SScrBuff
{
  DRAWENV draw;
  DISPENV disp;
  u_long ot[OT_LEN];
} rgBuffs[2];

void
SFDRndrInit (void)
{
  SetVideoMode (MODE_NTSC);
  GsInitGraph ((SCR_WIDTH), (SCR_HEIGHT), GsNONINTER | GsOFSGPU, 1, 0);
  FntLoad ((SCR_WIDTH), 256);
  SetDumpFnt (FntOpen (0, 8, (SCR_WIDTH), (SCR_HEIGHT), 0, 1024));
  SetGraphDebug (0);
  InitGeom (); // Init GTE
  SetGeomOffset ((SCR_WIDTH) >> 1, (SCR_HEIGHT) >> 1);
  SetGeomScreen ((SCR_WIDTH) >> 1);

  SetDefDrawEnv (&rgBuffs[0].draw, 0,            0, (SCR_WIDTH), (SCR_HEIGHT));
  SetDefDrawEnv (&rgBuffs[1].draw, 0, (SCR_HEIGHT), (SCR_WIDTH), (SCR_HEIGHT));
  SetDefDispEnv (&rgBuffs[0].disp, 0, (SCR_HEIGHT), (SCR_WIDTH), (SCR_HEIGHT));
  SetDefDispEnv (&rgBuffs[1].disp, 0,            0, (SCR_WIDTH), (SCR_HEIGHT));

  rgBuffs[0].draw.isbg = rgBuffs[1].draw.isbg = 1;

  setRGB0 (&rgBuffs[0].draw, 127, 127, 127);
  setRGB0 (&rgBuffs[1].draw, 127, 127, 127);

  SetDispMask (1);
}

void
SFDDrawFrm (void)
{
  static struct SScrBuff *psbCurr = rgBuffs;
  psbCurr = (psbCurr == rgBuffs) ? (rgBuffs + 1) : rgBuffs;
  ClearOTagR (psbCurr->ot, OT_LEN);

  while (DrawSync (1));
  VSync (0);
  PutDrawEnv (&psbCurr->draw);
  PutDispEnv (&psbCurr->disp);
  DrawOTag (psbCurr->ot + (OT_LEN-1));
  FntFlush (-1);
}
