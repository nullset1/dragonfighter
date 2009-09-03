/****
 * Copyright (C) Brian Moriya
 * brian.moriya@gmail.com
 * 
 * This file is part of Dragon Fighter. 
 * 
 * Dragon Fighter is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Dragon Fighter is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Dragon Fighter.  If not, see <http://www.gnu.org/licenses/>.
 ****/

#ifndef _MAPS_H
#define _MAPS_H

#define COUNTER 0
#define BRICK 1
#define STONE 2
#define GRASS 3
#define ROOF 4
#define BARRIER 5
#define WATER 6
#define STAIRSDOWNR 8
#define CHEST 9
#define DOOR 10
#define STAIRSDOWNL 11
#define STAIRSUPR 12
#define STAIRSUPL 13

/* Maps
 * format is:
 * # = door numbers of unlocked doors on map.
 * name = variable name
 * full = [name][#]...
 */
#define LTR 0
#define LTRACROSS 24
#define LTRDOWN 24
#define DR1 0
int throneroommap0[] = {
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,2,1,1,1,1,1,1,1,1,2,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,2,1,0,0,0,0,0,0,1,2,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,2,1,0,1,0,0,1,0,1,2,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,2,1,1,1,1,1,1,1,1,2,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,2,1,1,1,1,1,1,1,1,2,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,2,1,1,1,1,1,1,1,1,2,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,2,2,2,2,10,2,2,2,2,2,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,2,1,1,1,1,1,1,1,11,2,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
};

#define UTR 1
#define UTRACROSS 24
#define UTRDOWN 24
int throneroommap[] = {
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,2,1,1,1,1,1,1,1,1,2,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,2,1,0,0,0,0,0,0,1,2,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,2,1,0,1,0,0,1,0,1,2,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,2,1,1,1,1,1,1,1,1,2,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,2,1,1,1,1,1,1,1,1,2,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,2,1,1,1,1,1,1,1,1,2,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,2,2,2,2,1,2,2,2,2,2,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,2,1,1,1,1,1,1,1,11,2,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
};

#define TCY 2
#define TCYACROSS 32
#define TCYDOWN 32
#define DR2 1
#define DR3 2
int tantagelcourtyard12[] = {
  3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
  3,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,2,2,2,2,2,2,2,3,2,2,2,3,7,3,3,3,
  3,2,1,1,1,1,1,2,3,3,3,3,3,3,3,3,2,1,1,1,1,1,2,3,2,1,2,3,3,3,3,3,
  3,2,1,1,1,1,1,2,3,3,3,3,3,3,3,3,2,1,1,1,1,1,2,3,2,0,2,3,3,3,3,3,
  3,2,1,1,2,1,1,2,2,2,2,1,1,2,2,2,2,1,1,2,1,1,2,3,3,3,7,7,3,3,3,3,
  3,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,3,7,7,7,3,3,3,3,3,
  3,2,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,2,3,3,3,3,3,3,3,3,3,
  3,2,2,2,2,2,1,2,1,1,1,1,1,1,1,1,2,2,2,10,2,2,2,2,2,1,2,2,2,3,3,3,
  3,2,1,1,1,2,1,2,13,1,1,1,1,1,2,1,2,1,1,1,1,1,1,1,1,1,1,1,2,3,3,3,
  3,2,1,1,1,1,1,2,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,2,3,3,3,
  3,2,1,1,1,2,1,2,2,2,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,1,1,2,3,3,3,
  3,2,2,2,2,2,1,2,7,7,1,1,1,1,7,7,2,1,1,2,1,1,2,1,1,2,1,1,2,3,3,3,
  3,2,1,1,1,2,1,2,7,7,1,1,1,1,7,7,2,1,1,2,1,1,2,1,1,2,1,1,2,3,3,3,
  3,2,1,1,1,2,1,2,7,3,1,1,1,1,3,7,2,1,1,1,1,1,1,1,1,1,1,1,2,3,3,3,
  3,2,9,1,1,10,1,2,3,3,1,1,1,1,3,3,2,1,1,1,1,1,1,1,1,1,1,1,2,3,3,3,
  3,2,1,9,1,2,1,2,3,3,1,1,1,1,3,3,2,1,1,2,1,1,2,1,1,2,1,1,2,3,3,3,
  3,2,9,1,9,2,1,2,3,1,1,1,1,1,1,3,2,1,1,2,1,1,2,1,1,2,1,1,2,3,3,3,
  3,2,2,2,2,2,1,2,3,1,6,6,6,6,1,3,2,2,2,2,2,2,2,2,2,2,1,2,2,3,3,3,
  3,2,1,1,1,1,1,1,1,1,6,5,5,6,1,1,1,1,1,1,1,1,2,1,1,1,1,1,2,3,3,3,
  3,2,1,1,1,1,1,1,1,1,6,5,5,6,1,1,1,1,1,1,1,1,2,5,5,5,5,5,2,3,3,3,
  3,2,2,2,1,1,2,2,2,1,6,6,6,6,1,2,2,1,1,1,1,1,2,5,5,5,5,5,2,3,3,3,
  3,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,2,3,3,3,
  3,2,1,1,1,1,1,1,2,2,1,1,1,1,2,2,2,2,2,2,1,1,2,1,1,1,1,1,2,6,3,3,
  3,2,1,1,2,1,1,1,1,2,1,1,1,1,2,1,1,1,1,1,1,1,2,2,2,2,2,2,2,6,3,3,
  3,2,1,1,1,1,1,1,1,2,1,1,1,1,2,1,1,1,1,1,1,1,2,6,6,6,6,6,6,6,3,3,
  3,2,1,6,6,1,1,2,1,2,1,1,1,1,2,1,1,2,2,2,2,2,2,6,6,6,6,6,6,6,3,3,
  3,2,6,6,6,6,1,1,1,2,1,1,1,1,2,1,1,2,1,1,2,1,2,6,6,6,6,6,6,6,3,3,
  3,2,6,6,6,6,1,1,1,2,2,1,1,2,2,1,1,1,1,1,0,1,2,6,6,6,6,6,6,6,3,3,
  3,2,6,6,6,6,6,1,1,2,1,1,1,1,2,1,1,2,1,1,2,1,2,6,6,6,6,6,6,6,3,3,
  3,2,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,2,6,6,6,6,6,6,6,3,3,
  3,6,6,3,3,3,3,3,3,3,3,1,1,3,3,3,3,3,3,3,3,6,6,6,6,6,6,6,6,6,11,3,
  3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
};

#endif
