/*------------------------------------------------------------------------------

    File    :   MPEG3DEC.H

    Author  :   St�phane TAVENARD

    $VER:   MPEG3DEC.H  0.1  (31/03/1997)

    (C) Copyright 1997-1997 St�phane TAVENARD
        All Rights Reserved

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
 
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
 
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

    #Rev|   Date   |                      Comment
    ----|----------|--------------------------------------------------------
    0   |15/03/1997| Initial revision                                     ST
    1   |31/03/1997| First Aminet release                                 ST

    ------------------------------------------------------------------------

    MPEG layer III decoding functions definitions

------------------------------------------------------------------------------*/

#ifndef MPEG3DEC_H
#define MPEG3DEC_H

int MPEG3_reset( MPA_STREAM *mps );
/*--------------------------------------------------------------------------
   Reset the decoder
*/

INT32 MPEG3_decode_frame( MPA_STREAM *mps );
/*--------------------------------------------------------------------------
   Decode the current frame
   Return # of decoded samples
*/

#endif /* MPEG3DEC_H */
