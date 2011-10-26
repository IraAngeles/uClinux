/*
 * Copyright (C) 2003, 2004, 2005, 2006, 2007
 * Robert Lougher <rob@lougher.org.uk>.
 *
 * This file is part of JamVM.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#define HEADER_SIZE		sizeof(uintptr_t)
#define LOG_OBJECT_GRAIN	3
#define FLC_BIT			2

#define HDR_ADDRESS(obj) (uintptr_t*)(((char*)obj)-HEADER_SIZE)

#define clearFlcBit(obj) {                      \
	uintptr_t *hdr_addr = HDR_ADDRESS(obj); \
        *hdr_addr &= ~FLC_BIT;                  \
	MBARRIER();                             \
}

#define setFlcBit(obj) {                        \
	uintptr_t *hdr_addr = HDR_ADDRESS(obj); \
        *hdr_addr |= FLC_BIT;                   \
	MBARRIER();                             \
}

#define testFlcBit(obj) *HDR_ADDRESS(obj) & FLC_BIT
