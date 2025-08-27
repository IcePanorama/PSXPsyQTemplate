/**
 *  sfd_ints.h - my implementation of the stdint header for the PsyQ SDK. This
 *  header also defines shorter aliases for each of the fixed-width types, which
 *  can optionally be disabled by defining `SDF_INTS_NO_ALIASES`.
 *
 *  Copyright (C) 2025  SegFaultedDreams
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
#ifndef _SFD_INTS_H_
#define _SFD_INTS_H_

typedef char int8_t;
typedef short int16_t;
typedef int int32_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

#ifndef SDF_INTS_NO_ALIASES
typedef int8_t i8_t;
typedef int16_t i16_t;
typedef int32_t i32_t;

typedef uint8_t u8_t;
typedef uint16_t u16_t;
typedef uint32_t u32_t;
#endif /* SDF_STDINT_NO_ALIASES */


#endif /* _SFD_INTS_H_ */
