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
#ifndef _SFD_GLOBAL_TICKS_H_
#define _SFD_GLOBAL_TICKS_H_

#include <sys/types.h>
#include <libetc.h>

#define SFD_GET_TICKS() (VSync (-1))

#define SFD_TICKS_PER_UPDATE  (4) // `SFD_TICKS_PER_SEC`/4 = fixed 15 fps update
#define SFD_TICKS_PER_SEC    (60)

#endif /* _SFD_GLOBAL_TICKS_H_ */
