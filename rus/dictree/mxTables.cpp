/******************************************************************************

    libmorphrus - dictiorary-based morphological analyser for Russian.
    Copyright (C) 1994-2018 Andrew Kovalenko aka Keva

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

    Commercial license is available upon request.

    Contacts:
      email: keva@meta.ua, keva@rambler.ru
      Skype: big_keva
      Phone: +7(495)648-4058, +7(926)513-2991

******************************************************************************/

namespace __libmorphrus__
{

  unsigned char mxTables[] =
  {
    0x69,0x6e,0x74,0x65,0x72,0x63,0x02,0x22,0xe5,0xed,0x52,0xfc,
    0xed,0x02,0x22,0xe5,0xed,0x52,0xe9,0xed,0x02,0x22,0xe5,0xed,
    0x51,0xed,0x02,0x22,0xe5,0xeb,0x51,0xeb,0x02,0x22,0xe5,0xf0,
    0x51,0xf0,0x02,0x33,0xec,0xe0,0xeb,0x45,0xec,0xe5,0xed,0xfc,
    0xf8,0x02,0x51,0xed,0x22,0xee,0xed,0x02,0x22,0xe8,0xed,0x52,
    0xe9,0xed,0x02,0x32,0xf1,0xf2,0x41,0xf9,0x02,0x31,0xe4,0x41,
    0xe6,0x02,0x31,0xf2,0x41,0xf7,0x02,0x31,0xe2,0x42,0xe2,0xeb,
    0x02,0x51,0xeb,0x22,0xee,0xeb,0x02,0x21,0xed,0x52,0xed,0xed,
    0x02,0x22,0xe5,0xea,0x52,0xe9,0xea,0x02,0x22,0xe5,0xea,0x52,
    0xfc,0xea,0x02,0x22,0xe5,0xea,0x51,0xea,0x02,0x51,0xe3,0x22,
    0xee,0xe3,0x02,0x51,0xea,0x22,0xee,0xea,0x03,0x11,0xea,0x22,
    0xee,0xea,0x41,0xf7,0x03,0x12,0xf1,0xea,0x23,0xf1,0xee,0xea,
    0x41,0xf9,0x03,0x22,0xe5,0xea,0x12,0xe9,0xea,0x42,0xe9,0xf7,
    0x03,0x40,0x22,0xe5,0xea,0x12,0xfc,0xea,0x03,0x12,0xe4,0xea,
    0x23,0xe4,0xee,0xea,0x41,0xe6,0x03,0x12,0xe4,0xea,0x23,0xe4,
    0xee,0xea,0x41,0xf9,0x03,0x11,0xe3,0x22,0xee,0xe3,0x42,0xfc,
    0xf8,0x03,0x41,0xe6,0x12,0xe7,0xea,0x23,0xe7,0xee,0xea,0x03,
    0x12,0xf2,0xea,0x23,0xf2,0xee,0xea,0x41,0xf7,0x03,0x11,0xea,
    0x22,0xee,0xea,0x42,0xfc,0xf7,0x03,0x11,0xea,0x22,0xee,0xea,
    0x42,0xfc,0xf8,0x03,0x22,0xe5,0xea,0x11,0xea,0x41,0xf7,0x02,
    0x31,0xe3,0x41,0xe6,0x02,0x31,0xea,0x41,0xf7,0x02,0x31,0xf5,
    0x41,0xf8,0x02,0x33,0xf1,0xee,0xea,0x41,0xf8,0x02,0x41,0xf0,
    0x33,0xf0,0xee,0xea,0x02,0x42,0xe1,0xe6,0x33,0xe1,0xee,0xea,
    0x02,0x33,0xeb,0xe5,0xea,0x43,0xeb,0xfc,0xf8,0x02,0x32,0xe0,
    0xeb,0x44,0xe5,0xed,0xfc,0xf8,0x02,0x34,0xef,0xeb,0xee,0xf5,
    0x43,0xf5,0xf3,0xe6,0x02,0x44,0xeb,0xf3,0xf7,0xf8,0x35,0xf5,
    0xee,0xf0,0xee,0xf8,0x02,0x52,0xe5,0xec,0x22,0xe9,0xec,0x02,
    0x52,0xe5,0xf2,0x21,0xf2,0x02,0x52,0xee,0xf0,0x21,0xf0,0x02,
    0x21,0xed,0x52,0xee,0xed,0x02,0x52,0xe5,0xed,0x21,0xed,0x02,
    0x52,0xe5,0xeb,0x21,0xeb,0x02,0x52,0xe5,0xe4,0x22,0xfc,0xe4,
    0x02,0x52,0xe5,0xe2,0x22,0xfc,0xe2,0x02,0x52,0xe5,0xed,0x22,
    0xfc,0xed,0x02,0x52,0xee,0xf2,0x21,0xf2,0x02,0x21,0xec,0x52,
    0xee,0xec,0x02,0x21,0xeb,0x52,0xee,0xeb,0x02,0x21,0xe2,0x52,
    0xee,0xe2,0x02,0x21,0xe1,0x52,0xee,0xe1,0x02,0x52,0xe5,0xf1,
    0x21,0xf1,0x02,0x52,0xe5,0xf0,0x21,0xf0,0x02,0x52,0xe0,0xed,
    0x21,0xed,0x02,0x52,0xe5,0xea,0x22,0xe9,0xea,0x02,0x21,0xea,
    0x52,0xee,0xea,0x02,0x52,0xe5,0xea,0x21,0xea,0x02,0x52,0xe5,
    0xea,0x22,0xfc,0xea,0x02,0x52,0xee,0xf5,0x21,0xf5,0x02,0x52,
    0xe5,0xf6,0x22,0xfc,0xf6,0x02,0x52,0xe5,0xf6,0x22,0xe9,0xf6,
    0x02,0x52,0xe5,0xf6,0x21,0xf6,0x02,0x22,0xe9,0xf6,0x52,0xff,
    0xf6,0x02,0x52,0xe8,0xed,0x21,0xed,0x02,0x22,0xe5,0xe1,0x52,
    0xfc,0xe1,0x02,0x22,0xe5,0xec,0x51,0xec,0x02,0x22,0xe5,0xec,
    0x52,0xfc,0xec,0x02,0x22,0xe5,0xec,0x52,0xe9,0xec,0x02,0x22,
    0xe5,0xe3,0x52,0xfc,0xe3,0x02,0x22,0xe5,0xe3,0x52,0xe9,0xe3,
    0x02,0x51,0xe3,0x22,0xe5,0xe3,0x02,0x22,0xe5,0xf6,0x52,0xfc,
    0xf6,0x02,0x22,0xe5,0xf6,0x51,0xf6,0x02,0x22,0xe8,0xf6,0x52,
    0xe9,0xf6,0x02,0x11,0xe1,0x62,0xe1,0xeb,0x02,0x11,0xe2,0x62,
    0xe2,0xeb,0x02,0x11,0xec,0x62,0xec,0xeb,0x02,0x11,0xf4,0x62,
    0xf4,0xeb,0x02,0x11,0xef,0x62,0xef,0xeb,0x02,0x51,0xec,0x22,
    0xec,0xeb,0x03,0x11,0xe4,0x21,0xe6,0x42,0xe6,0xe4,0x02,0x11,
    0xf2,0x61,0xf9,0x02,0x11,0xf1,0x61,0xf8,0x02,0x61,0xe6,0x11,
    0xe7,0x02,0x12,0xf1,0xf2,0x61,0xf9,0x02,0x11,0xf2,0x61,0xf7,
    0x02,0x11,0xe4,0x61,0xe6,0x03,0x42,0xe6,0xe4,0x12,0xe7,0xe4,
    0x22,0xe7,0xe6,0x03,0x11,0xf2,0x42,0xf2,0xed,0x21,0xf7,0x02,
    0x51,0xf1,0x21,0xf8,0x02,0x21,0xe6,0x51,0xe7,0x02,0x32,0xf1,
    0xeb,0x42,0xf8,0xeb,0x02,0x51,0xf1,0x21,0xf8,0x02,0x12,0xf2,
    0xe2,0x63,0xf9,0xe2,0xeb,0x02,0x51,0xe4,0x21,0xe6,0x02,0x52,
    0xf1,0xf2,0x21,0xf9,0x02,0x51,0xf2,0x21,0xf7,0x02,0x51,0xef,
    0x22,0xef,0xeb,0x02,0x51,0xef,0x22,0xef,0xeb,0x02,0x23,0xe3,
    0xee,0xed,0x53,0xee,0xe3,0xed,0x02,0x51,0xe1,0x22,0xe1,0xeb,
    0x02,0x51,0xea,0x21,0xf7,0x02,0x51,0xf5,0x21,0xf8,0x02,0x51,
    0xe3,0x21,0xe6,0x02,0x52,0xf1,0xea,0x21,0xf9,0x02,0x21,0xe4,
    0x51,0xf5,0x02,0x52,0xf1,0xeb,0x22,0xf8,0xeb,0x02,0x55,0xe7,
    0xee,0xf1,0xf2,0xeb,0x25,0xf1,0xf1,0xf2,0xe5,0xeb,0x02,0x54,
    0xee,0xf1,0xf2,0xeb,0x24,0xf1,0xf2,0xe5,0xeb,0x02,0x23,0xe7,
    0xee,0xe2,0x53,0xee,0xe7,0xe2,0x02,0x51,0xe2,0x22,0xee,0xe2,
    0x02,0x23,0xe1,0xe5,0xf0,0x54,0xe1,0xee,0xe1,0xf0,0x02,0x23,
    0xe1,0xe5,0xf0,0x53,0xee,0xe1,0xf0,0x02,0x23,0xe4,0xe5,0xf0,
    0x53,0xee,0xe4,0xf0,0x02,0x51,0xf2,0x21,0xf9,0x02,0x22,0xe5,
    0xf9,0x53,0xe8,0xf1,0xf2,0x02,0x22,0xee,0xe1,0x53,0xee,0xe1,
    0xee,0x02,0x52,0xe5,0xf0,0x21,0xf0,0x02,0x24,0xe1,0xee,0xef,
    0xf0,0x53,0xef,0xe5,0xf0,0x02,0x24,0xe7,0xee,0xef,0xf0,0x54,
    0xf1,0xef,0xe5,0xf0,0x02,0x24,0xe7,0xee,0xf2,0xf0,0x54,0xf1,
    0xf2,0xe5,0xf0,0x02,0x23,0xee,0xef,0xf0,0x53,0xef,0xe5,0xf0,
    0x02,0x23,0xee,0xf2,0xf0,0x53,0xf2,0xe5,0xf0,0x02,0x53,0xec,
    0xe5,0xf0,0x23,0xee,0xec,0xf0,0x02,0x22,0xe5,0xeb,0x52,0xee,
    0xeb,0x02,0x51,0xe1,0x23,0xe1,0xee,0xe1,0x02,0x23,0xe7,0xee,
    0xf8,0x52,0xf1,0xf8,0x02,0x51,0xe1,0x22,0xee,0xe1,0x02,0x22,
    0xee,0xf8,0x51,0xf8,0x02,0x23,0xe7,0xee,0xef,0x52,0xf1,0xef,
    0x02,0x23,0xe1,0xee,0xef,0x51,0xef,0x02,0x22,0xee,0xef,0x51,
    0xef,0x02,0x51,0xec,0x22,0xee,0xec,0x02,0x51,0xe6,0x22,0xee,
    0xe6,0x02,0x51,0xe7,0x22,0xee,0xe7
  };

}  // end namespace

