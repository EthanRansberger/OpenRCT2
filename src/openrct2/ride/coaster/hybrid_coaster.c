#pragma region Copyright (c) 2014-2017 OpenRCT2 Developers
/*****************************************************************************
 * OpenRCT2, an open source clone of Roller Coaster Tycoon 2.
 *
 * OpenRCT2 is the work of many authors, a full list can be found in contributors.md
 * For more information, visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * A full copy of the GNU General Public License can be found in licence.txt
 *****************************************************************************/
#pragma endregion

#include "../../drawing/drawing.h"
#include "../../paint/supports.h"
#include "../../interface/viewport.h"
#include "../../paint/map_element/map_element.h"
#include "../../paint/paint.h"
#include "../../sprites.h"
#include "../../world/map.h"
#include "../../world/sprite.h"
#include "../ride_data.h"
#include "../track_data.h"
#include "../track_paint.h"

//Slopes
static void hybrid_rc_track_flat(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
     if (track_element_is_lift_hill(mapElement)) {
        switch (direction) {
         case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+97), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+98), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+99), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+100), 0, 0, 32, 20, 3, height, 0, 6, height);
            break; 
        }
        if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 0, height, gTrackColours[SCHEME_SUPPORTS]);
        }
    } else {
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+93), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+94), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+95), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+96), 0, 0, 32, 20, 3, height, 0, 6, height);
            break; 
        }
        if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 0, height, gTrackColours[SCHEME_SUPPORTS]);
        }
    }
    paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 32, 0x20);
}
static void hybrid_rc_track_station(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    static const uint32 imageIds[4][3] = {
        { (SPR_G2_BEGIN+93), (SPR_G2_BEGIN+93), SPR_STATION_BASE_A_SW_NE },
        { (SPR_G2_BEGIN+94), (SPR_G2_BEGIN+94), SPR_STATION_BASE_A_NW_SE },
        { (SPR_G2_BEGIN+95), (SPR_G2_BEGIN+95), SPR_STATION_BASE_A_SW_NE },
        { (SPR_G2_BEGIN+96), (SPR_G2_BEGIN+96), SPR_STATION_BASE_A_NW_SE },
    };

    if (mapElement->properties.track.type == TRACK_ELEM_END_STATION) {
        sub_98197C_rotated(direction, imageIds[direction][1] | gTrackColours[SCHEME_TRACK], 0, 0, 32, 20, 1, height, 0, 6, height + 3);
    } else {
        sub_98197C_rotated(direction, imageIds[direction][0] | gTrackColours[SCHEME_TRACK], 0, 0, 32, 20, 1, height, 0, 6, height + 3);
    }
    sub_98196C_rotated(direction, imageIds[direction][2] | gTrackColours[SCHEME_MISC], 0, 0, 32, 32, 1, height);
    track_paint_util_draw_station_metal_supports_2(direction, height, gTrackColours[SCHEME_SUPPORTS], 0);
    track_paint_util_draw_station_2(rideIndex, trackSequence, direction, height, mapElement, 9, 11);
    paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
    paint_util_set_segment_support_height(SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(height + 32, 0x20);
}
static void hybrid_rc_track_flat_to_25_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    if (track_element_is_lift_hill(mapElement)) {
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+109), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+110), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+111), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+112), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 3, height, gTrackColours[SCHEME_SUPPORTS]);
        }
    } else {
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+105), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+106), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+107), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+108), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 3, height, gTrackColours[SCHEME_SUPPORTS]);
        }
    }
    if (direction == 0 || direction == 3) {
        paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
    } else {
        paint_util_push_tunnel_rotated(direction, height, TUNNEL_8);
    }
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 48, 0x20);
}
static void hybrid_rc_track_25_deg_up_to_flat(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    if (track_element_is_lift_hill(mapElement)) {
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+117), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+118), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+119), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+120), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 6, height, gTrackColours[SCHEME_SUPPORTS]);
        }
    } else {
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+113), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+114), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+115), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+116), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 6, height, gTrackColours[SCHEME_SUPPORTS]);
        }
    }
    if (direction == 0 || direction == 3) {
        paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_6);
    } else {
        paint_util_push_tunnel_rotated(direction, height + 8, TUNNEL_14);
    }
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 40, 0x20);
}
static void hybrid_rc_track_25_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    if (track_element_is_lift_hill(mapElement)) {
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+125), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+126), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+127), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+128), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
        }
    } else {
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+121), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+122), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+123), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+124), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
        }
    }
    if (direction == 0 || direction == 3) {
        paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_7);
    } else {
        paint_util_push_tunnel_rotated(direction, height + 8, TUNNEL_8);
    }
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 56, 0x20);
}
static void hybrid_rc_track_flat_to_25_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_25_deg_up_to_flat(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}
static void hybrid_rc_track_25_deg_down_to_flat(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_flat_to_25_deg_up(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}
static void hybrid_rc_track_25_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_25_deg_up(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}
static void hybrid_rc_track_25_deg_up_to_60_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    if (track_element_is_lift_hill(mapElement)) {
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+135), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+136), 0, 0, 32, 20, 3, height, 0, 6, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+137), 0, 0, 32, 1, 66, height, 0, 27, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+138), 0, 0, 32, 20, 3, height, 0, 6, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+139), 0, 0, 32, 1, 66, height, 0, 27, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+140), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 12, height, gTrackColours[SCHEME_SUPPORTS]);
        }
    } else {
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+129), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+130), 0, 0, 32, 20, 3, height, 0, 6, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+131), 0, 0, 32, 1, 66, height, 0, 27, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+132), 0, 0, 32, 20, 3, height, 0, 6, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+133), 0, 0, 32, 1, 66, height, 0, 27, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+134), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 12, height, gTrackColours[SCHEME_SUPPORTS]);
        }
    }
    if (direction == 0 || direction == 3) {
        paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_7);
    } else {
        paint_util_push_tunnel_rotated(direction, height + 24, TUNNEL_8);
    }
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 72, 0x20);
}
static void hybrid_rc_track_60_deg_up_to_25_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    if (track_element_is_lift_hill(mapElement)) {
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+147), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+148), 0, 0, 32, 20, 3, height, 0, 6, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+149), 0, 0, 32, 1, 66, height, 0, 27, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+150), 0, 0, 32, 20, 3, height, 0, 6, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+151), 0, 0, 32, 1, 66, height, 0, 27, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+152), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 20, height, gTrackColours[SCHEME_SUPPORTS]);
        }
    } else {
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+141), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+142), 0, 0, 32, 20, 3, height, 0, 6, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+143), 0, 0, 32, 1, 66, height, 0, 27, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+144), 0, 0, 32, 20, 3, height, 0, 6, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+145), 0, 0, 32, 1, 66, height, 0, 27, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+146), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 20, height, gTrackColours[SCHEME_SUPPORTS]);
        }
    }
    if (direction == 0 || direction == 3) {
        paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_7);
    } else {
        paint_util_push_tunnel_rotated(direction, height + 24, TUNNEL_8);
    }
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 72, 0x20);
}
static void hybrid_rc_track_60_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    if (track_element_is_lift_hill(mapElement)) {
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+157), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+158), 0, 0, 32, 1, 98, height, 0, 27, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+159), 0, 0, 32, 1, 98, height, 0, 27, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+160), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 32, height, gTrackColours[SCHEME_SUPPORTS]);
        }
    } else {
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+153), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+154), 0, 0, 32, 1, 98, height, 0, 27, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+155), 0, 0, 32, 1, 98, height, 0, 27, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+156), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 32, height, gTrackColours[SCHEME_SUPPORTS]);
        }
    }
    if (direction == 0 || direction == 3) {
        paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_7);
    } else {
        paint_util_push_tunnel_rotated(direction, height + 56, TUNNEL_8);
    }
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 104, 0x20);
}
static void hybrid_rc_track_25_deg_down_to_60_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_60_deg_up_to_25_deg_up(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}
static void hybrid_rc_track_60_deg_down_to_25_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_25_deg_up_to_60_deg_up(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}
static void hybrid_rc_track_60_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_60_deg_up(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}
static void hybrid_rc_track_60_deg_up_to_90_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
        case 0:
            switch (direction) {
                case 0:
                    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+161), 0, 0, 32, 20, 3, height, 0, 6, height);
                    break;
                case 1:
                    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+162), 0, 0, 2, 20, 55, height, 24, 6, height);
                    break;
                case 2:
                    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+163), 0, 0, 2, 20, 55, height, 24, 6, height);
                    break;
                case 3:
                    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+164), 0, 0, 32, 20, 3, height, 0, 6, height);
                    break;
            }
            if (direction == 0 || direction == 3) {
                paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_7);
            }
            paint_util_set_vertical_tunnel(height + 56);
            paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
            paint_util_set_general_support_height(height + 56, 0x20);
            break;
        case 1:
            break;
    }
}
static void hybrid_rc_track_90_deg_up_to_60_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
        case 0:
            switch (direction) {
                case 0:
                   sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+165), 0, 0, 32, 20, 3, height, 0, 6, height + 8);
                   break;
               case 1:
                   sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+166), 0, 0, 2, 20, 31, height, 24, 6, height + 8);
                   break;
               case 2:
                   sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+167), 0, 0, 2, 20, 31, height, 24, 6, height + 8);
                   break;
               case 3:
                   sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+168), 0, 0, 32, 20, 3, height, 0, 6, height + 8);
                   break;
           }
           switch (direction) {
               case 1:
                   paint_util_push_tunnel_right(height + 48, TUNNEL_8);
                   break;
               case 2:
                   paint_util_push_tunnel_left(height + 48, TUNNEL_8);
                   break;
           }
           paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
           paint_util_set_general_support_height(height + 80, 0x20);
           break;
        case 1:
            break;
    }
}
static void hybrid_rc_track_90_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
        case 0:
            switch (direction) {
                case 0:
                    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+169), 0, 0, 2, 20, 31, height, 4, 6, height + 8);
                    break;
                case 1:
                    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+170), 0, 0, 2, 20, 31, height, 24, 6, height + 8);
                    break;
                case 2:
                    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+171), 0, 0, 2, 20, 31, height, 24, 6, height + 8);
                    break;
                case 3:
                    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+172), 0, 0, 2, 20, 31, height, 4, 6, height + 8);
                    break;
            }
            paint_util_set_vertical_tunnel(height + 32);
            paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
            paint_util_set_general_support_height(height + 32, 0x20);
            break;
        case 1:
            break;
    }
}
static void hybrid_rc_track_90_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_90_deg_up(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}
static void hybrid_rc_track_90_deg_down_to_60_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_60_deg_up_to_90_deg_up(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}
static void hybrid_rc_track_60_deg_down_to_90_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_90_deg_up_to_60_deg_up(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}

//Turns
static void hybrid_rc_track_left_quarter_turn_3(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+173), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+176), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+179), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+182), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 0, height, gTrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 1:
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 2:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+174), 0, 0, 16, 16, 3, height, 16, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+177), 0, 0, 16, 16, 3, height, 0, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+180), 0, 0, 16, 16, 3, height, 0, 16, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+183), 0, 0, 16, 16, 3, height, 16, 16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+175), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+178), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+181), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+184), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 0, height, gTrackColours[SCHEME_SUPPORTS]);
        switch (direction) {
        case 2:
            paint_util_push_tunnel_right(height, TUNNEL_6);
            break;
        case 3:
            paint_util_push_tunnel_left(height, TUNNEL_6);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    }
}
static void hybrid_rc_track_right_quarter_turn_3(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    trackSequence = mapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence];
    hybrid_rc_track_left_quarter_turn_3(rideIndex, trackSequence, (direction - 1) & 3, height, mapElement);
}
static void hybrid_rc_track_left_quarter_turn_5(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+185), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+190), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+195), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+200), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 0, height, gTrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 1:
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 2:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+186), 0, 0, 32, 16, 3, height, 0, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+191), 0, 0, 32, 16, 3, height, 0, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+196), 0, 0, 32, 16, 3, height, 0, 16, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+201), 0, 0, 32, 16, 3, height, 0, 16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+187), 0, 0, 16, 16, 3, height, 0, 16, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+192), 0, 0, 16, 16, 3, height, 16, 16, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+197), 0, 0, 16, 16, 3, height, 16, 0, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+202), 0, 0, 16, 16, 3, height, 0, 0, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 4:
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 5:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+188), 0, 0, 16, 32, 3, height, 16, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+193), 0, 0, 16, 32, 3, height, 0, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+198), 0, 0, 16, 32, 3, height, 0, 0, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+203), 0, 0, 16, 32, 3, height, 16, 0, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 6:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+189), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+194), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+199), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+204), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 0, height, gTrackColours[SCHEME_SUPPORTS]);
        switch (direction) {
        case 2:
            paint_util_push_tunnel_right(height, TUNNEL_6);
            break;
        case 3:
            paint_util_push_tunnel_left(height, TUNNEL_6);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    }
}
static void hybrid_rc_track_right_quarter_turn_5(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    trackSequence = mapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence];
    hybrid_rc_track_left_quarter_turn_5(rideIndex, trackSequence, (direction - 1) & 3, height, mapElement);
}
static void hybrid_rc_track_left_eighth_to_diag(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+205), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+209), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+213), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+217), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 0, height, gTrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 1:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+206), 0, 0, 32, 16, 3, height, 0, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+210), 0, 0, 34, 16, 3, height, 0, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+214), 0, 0, 32, 16, 3, height, 0, 16, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+218), 0, 0, 32, 16, 3, height, 0, 16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 2:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+207), 0, 0, 16, 16, 3, height, 0, 16, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+211), 0, 0, 16, 16, 3, height, 16, 16, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+215), 0, 0, 16, 16, 3, height, 16, 0, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+219), 0, 0, 16, 16, 3, height, 0, 0, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 3:
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 4:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+208), 0, 0, 16, 16, 3, height, 16, 16, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+212), 0, 0, 16, 18, 3, height, 0, 16, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+216), 0, 0, 16, 16, 3, height, 0, 0, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+220), 0, 0, 16, 16, 3, height, 16, 0, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    }
}
static void hybrid_rc_track_right_eighth_to_diag(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+221), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+225), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+229), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+233), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 0, height, gTrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 1:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+222), 0, 0, 32, 16, 3, height, 0, 16, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+226), 0, 0, 32, 16, 3, height, 0, 16, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+230), 0, 0, 34, 16, 3, height, 0, 0, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+234), 0, 0, 32, 16, 3, height, 0, 0, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 2:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+223), 0, 0, 16, 16, 3, height, 0, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+227), 0, 0, 16, 16, 3, height, 16, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+231), 0, 0, 28, 28, 3, height, 4, 4, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+235), 0, 0, 16, 16, 3, height, 0, 16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 3:
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 4:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+224), 0, 0, 16, 16, 3, height, 16, 0, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+228), 0, 0, 16, 16, 3, height, 0, 0, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+232), 0, 0, 16, 18, 3, height, 0, 16, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+236), 0, 0, 16, 16, 3, height, 16, 16, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    }
}
static void hybrid_rc_track_left_eighth_to_orthogonal(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    trackSequence = mapLeftEighthTurnToOrthogonal[trackSequence];
    hybrid_rc_track_right_eighth_to_diag(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}
static void hybrid_rc_track_right_eighth_to_orthogonal(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    trackSequence = mapLeftEighthTurnToOrthogonal[trackSequence];
    hybrid_rc_track_left_eighth_to_diag(rideIndex, trackSequence, (direction + 3) & 3, height, mapElement);
}

//Diagonals
static void hybrid_rc_track_diag_flat(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        if (track_element_is_lift_hill(mapElement)) {
            switch (direction) {
            case 3:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+244), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        } else {
            switch (direction) {
            case 3:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+240), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 1:
        if (track_element_is_lift_hill(mapElement)) {
            switch (direction) {
            case 0:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+241), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        } else {
            switch (direction) {
            case 0:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+237), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 2:
        if (track_element_is_lift_hill(mapElement)) {
            switch (direction) {
            case 2:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+243), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        } else {
            switch (direction) {
            case 2:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+239), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 3:
        if (track_element_is_lift_hill(mapElement)) {
            switch (direction) {
            case 0:
                metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 0, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+242), -16, -16, 32, 32, 3, height, -16, -16, height);
                metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 0, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 0, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 0, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            }
        } else {
            switch (direction) {
            case 0:
                metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 0, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+238), -16, -16, 32, 32, 3, height, -16, -16, height);
                metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 0, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 0, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 0, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    }
}
static void hybrid_rc_track_diag_flat_to_25_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        if (track_element_is_lift_hill(mapElement)) {
            switch (direction) {
            case 3:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+252), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        } else {
            switch (direction) {
            case 3:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+248), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 48, 0x20);
        break;
    case 1:
        if (track_element_is_lift_hill(mapElement)) {
            switch (direction) {
            case 0:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+249), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        } else {
            switch (direction) {
            case 0:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+245), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 48, 0x20);
        break;
    case 2:
        if (track_element_is_lift_hill(mapElement)) {
            switch (direction) {
            case 2:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+251), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        } else {
            switch (direction) {
            case 2:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+247), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 48, 0x20);
        break;
    case 3:
        if (track_element_is_lift_hill(mapElement)) {
            switch (direction) {
            case 0:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 0, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+250), -16, -16, 32, 32, 3, height, -16, -16, height);
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 0, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 0, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 0, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            }
        } else {
            switch (direction) {
            case 0:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 0, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+246), -16, -16, 32, 32, 3, height, -16, -16, height);
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 0, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 0, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 0, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 48, 0x20);
        break;
    }
}
static void hybrid_rc_track_diag_25_deg_up_to_flat(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        if (track_element_is_lift_hill(mapElement)) {
            switch (direction) {
            case 3:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+260), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        } else {
            switch (direction) {
            case 3:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+256), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    case 1:
        if (track_element_is_lift_hill(mapElement)) {
            switch (direction) {
            case 0:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+257), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        } else {
            switch (direction) {
            case 0:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+253), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    case 2:
        if (track_element_is_lift_hill(mapElement)) {
            switch (direction) {
            case 2:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+259), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        } else {
            switch (direction) {
            case 2:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+255), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    case 3:
        if (track_element_is_lift_hill(mapElement)) {
            switch (direction) {
            case 0:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 4, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+258), -16, -16, 32, 32, 3, height, -16, -16, height);
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 4, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 4, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 4, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            }
        } else {
            switch (direction) {
            case 0:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 4, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+254), -16, -16, 32, 32, 3, height, -16, -16, height);
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 4, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 4, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 4, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    }
}
static void hybrid_rc_track_diag_25_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        if (track_element_is_lift_hill(mapElement)) {
            switch (direction) {
            case 3:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+268), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        } else {
            switch (direction) {
            case 3:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+264), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    case 1:
        if (track_element_is_lift_hill(mapElement)) {
            switch (direction) {
            case 0:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+265), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        } else {
            switch (direction) {
            case 0:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+261), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    case 2:
        if (track_element_is_lift_hill(mapElement)) {
            switch (direction) {
            case 2:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+267), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        } else {
            switch (direction) {
            case 2:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+263), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    case 3:
        if (track_element_is_lift_hill(mapElement)) {
            switch (direction) {
            case 0:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 8, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+266), -16, -16, 32, 32, 3, height, -16, -16, height);
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 8, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 8, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 8, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            }
        } else {
            switch (direction) {
            case 0:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 8, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+262), -16, -16, 32, 32, 3, height, -16, -16, height);
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 8, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 8, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 8, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    }
}
static void hybrid_rc_track_diag_flat_to_25_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        if (track_element_is_lift_hill(mapElement)) {
            switch (direction) {
            case 3:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+258), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        } else {
            switch (direction) {
            case 3:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+254), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        break;
    case 1:
        if (track_element_is_lift_hill(mapElement)) {
            switch (direction) {
            case 0:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+259), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        } else {
            switch (direction) {
            case 0:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+255), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        break;
    case 2:
        if (track_element_is_lift_hill(mapElement)) {
            switch (direction) {
            case 2:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+257), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        } else {
            switch (direction) {
            case 2:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+253), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        break;
    case 3:
        if (track_element_is_lift_hill(mapElement)) {
            switch (direction) {
            case 0:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 4, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+260), -16, -16, 32, 32, 3, height, -16, -16, height);
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 4, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 4, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 4, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            }
        } else {
            switch (direction) {
            case 0:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 4, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+256), -16, -16, 32, 32, 3, height, -16, -16, height);
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 4, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 4, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 4, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        break;
    }

    paint_util_set_general_support_height(height + 56, 0x20);
}
static void hybrid_rc_track_diag_25_deg_down_to_flat(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{

    switch (trackSequence) {
    case 0:
        if (track_element_is_lift_hill(mapElement)) {
            switch (direction) {
            case 3:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+250), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        } else {
            switch (direction) {
            case 3:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+246), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 48, 0x20);
        break;
    case 1:
        if (track_element_is_lift_hill(mapElement)) {
            switch (direction) {
            case 0:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+251), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        } else {
            switch (direction) {
            case 0:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+247), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 48, 0x20);
        break;
    case 2:
        if (track_element_is_lift_hill(mapElement)) {
            switch (direction) {
            case 2:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+249), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        } else {
            switch (direction) {
            case 2:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+245), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 48, 0x20);
        break;
    case 3:
        if (track_element_is_lift_hill(mapElement)) {
            switch (direction) {
            case 0:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 0, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+252), -16, -16, 32, 32, 3, height, -16, -16, height);
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 0, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 0, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 0, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            }
        } else {
            switch (direction) {
            case 0:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 0, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+248), -16, -16, 32, 32, 3, height, -16, -16, height);
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 0, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 0, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 0, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 48, 0x20);
        break;
    }
}
static void hybrid_rc_track_diag_25_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        if (track_element_is_lift_hill(mapElement)) {
            switch (direction) {
            case 3:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+266), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        } else {
            switch (direction) {
            case 3:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+262), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    case 1:
        if (track_element_is_lift_hill(mapElement)) {
            switch (direction) {
            case 0:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+267), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        } else {
            switch (direction) {
            case 0:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+263), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    case 2:
        if (track_element_is_lift_hill(mapElement)) {
            switch (direction) {
            case 2:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+265), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        } else {
            switch (direction) {
            case 2:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+261), -16, -16, 32, 32, 3, height, -16, -16, height);
                break;
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    case 3:
        if (track_element_is_lift_hill(mapElement)) {
            switch (direction) {
            case 0:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 8, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+268), -16, -16, 32, 32, 3, height, -16, -16, height);
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 8, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 8, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 8, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            }
        } else {
            switch (direction) {
            case 0:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 8, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+264), -16, -16, 32, 32, 3, height, -16, -16, height);
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 8, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 8, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 8, height, gTrackColours[SCHEME_SUPPORTS]);
                break;
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    }
}
static void hybrid_rc_track_diag_25_deg_up_to_60_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
	if (track_element_is_lift_hill(mapElement)) {
		switch (direction) {
		case 3:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+276), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	} else {
 		switch (direction) {
        	case 3:
            	    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+272), -16, -16, 32, 32, 3, height, -16, -16, height);
            	    break;
        	}
	}
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 1:
	if (track_element_is_lift_hill(mapElement)) {
		switch (direction) {
		case 0:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+273), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	} else {
		switch (direction) {
		case 0:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+269), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	}
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 2:
	if (track_element_is_lift_hill(mapElement)) {
		switch (direction) {
		case 2:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+275), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
        	}
	} else {
		switch (direction) {
		case 2:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+271), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	}
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 3:
	if (track_element_is_lift_hill(mapElement)) {
		switch (direction) {
		case 0:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 16, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 1:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+274), -16, -16, 32, 32, 3, height, -16, -16, height);
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 16, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 2:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 16, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 3:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 16, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		}
	} else {
		switch (direction) {
		case 0:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 16, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 1:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+270), -16, -16, 32, 32, 3, height, -16, -16, height);
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 16, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 2:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 16, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 3:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 16, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		}
	}
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    }
}
static void hybrid_rc_track_diag_60_deg_up_to_25_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
	if (track_element_is_lift_hill(mapElement)) {
		switch (direction) {
		case 3:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+284), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	} else {
		switch (direction) {
		case 3:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+280), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	}
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 1:
	if (track_element_is_lift_hill(mapElement)) {
		switch (direction) {
		case 0:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+281), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	} else {
		switch (direction) {
		case 0:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+277), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	}
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 2:
	if (track_element_is_lift_hill(mapElement)) {
		switch (direction) {
		case 2:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+283), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	} else {
		switch (direction) {
		case 2:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+279), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	}
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 3:
	if (track_element_is_lift_hill(mapElement)) {
		switch (direction) {
		case 0:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 21, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 1:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+282), -16, -16, 16, 16, 3, height, 0, 0, height);
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 21, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 2:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 21, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 3:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 21, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		}
	} else {
        switch (direction) {
		case 0:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 21, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 1:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+278), -16, -16, 16, 16, 3, height, 0, 0, height);
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 21, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 2:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 21, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 3:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 21, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		}
	}
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    }
}
static void hybrid_rc_track_diag_60_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
	if (track_element_is_lift_hill(mapElement)) {
		switch (direction) {
		case 3:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+292), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	} else {
		switch (direction) {
		case 3:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+288), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	}
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 104, 0x20);
        break;
    case 1:
	if (track_element_is_lift_hill(mapElement)) {
		switch (direction) {
		case 0:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+289), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	} else {
		switch (direction) {
		case 0:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+285), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	}
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 104, 0x20);
        break;
    case 2:
	if (track_element_is_lift_hill(mapElement)) {
		switch (direction) {
		case 2:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+291), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	} else {
		switch (direction) {
		case 2:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+287), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	}
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 104, 0x20);
        break;
    case 3:
	if (track_element_is_lift_hill(mapElement)) {
	        switch (direction) {
		case 0:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 32, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 1:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+290), -16, -16, 32, 32, 3, height, -16, -16, height);
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 36, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 2:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 32, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 3:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 36, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		}
	} else {
		switch (direction) {
		case 0:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 32, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 1:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+286), -16, -16, 32, 32, 3, height, -16, -16, height);
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 36, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 2:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 32, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 3:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 36, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		}
	}
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 104, 0x20);
        break;
    }
}
static void hybrid_rc_track_diag_25_deg_down_to_60_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
	if (track_element_is_lift_hill(mapElement)) {
		switch (direction) {
		case 3:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+282), -16, -16, 16, 16, 3, height, 0, 0, height);
		    break;
		}
	} else {
		switch (direction) {
		case 3:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+278), -16, -16, 16, 16, 3, height, 0, 0, height);
		    break;
		}
	}
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 1:
	if (track_element_is_lift_hill(mapElement)) {
		switch (direction) {
		case 0:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+283), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	} else {
		switch (direction) {
		case 0:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+279), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	}
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 2:
	if (track_element_is_lift_hill(mapElement)) {
		switch (direction) {
		case 2:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+281), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	} else {
		switch (direction) {
		case 2:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+277), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	}
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 3:
	if (track_element_is_lift_hill(mapElement)) {
		switch (direction) {
		case 0:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 17, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 1:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+284), -16, -16, 32, 32, 3, height, -16, -16, height);
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 17, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 2:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 17, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 3:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 17, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		}
	} else {
		switch (direction) {
		case 0:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 17, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 1:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+280), -16, -16, 32, 32, 3, height, -16, -16, height);
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 17, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 2:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 17, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 3:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 17, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		}
	}
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    }
}
static void hybrid_rc_track_diag_60_deg_down_to_25_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
	if (track_element_is_lift_hill(mapElement)) {
		switch (direction) {
		case 3:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+274), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	} else {
		switch (direction) {
		case 3:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+270), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	}
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 1:
	if (track_element_is_lift_hill(mapElement)) {
		switch (direction) {
		case 0:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+275), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	} else {
		switch (direction) {
		case 0:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+271), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	}
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 2:
	if (track_element_is_lift_hill(mapElement)) {
		switch (direction) {
		case 2:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+273), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	} else {
		switch (direction) {
		case 2:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+269), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	}
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 3:
	if (track_element_is_lift_hill(mapElement)) {
		switch (direction) {
		case 0:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 8, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 1:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+276), -16, -16, 32, 32, 3, height, -16, -16, height);
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 8, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 2:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 8, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 3:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 8, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		}
	} else {
		switch (direction) {
		case 0:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 8, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 1:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+272), -16, -16, 32, 32, 3, height, -16, -16, height);
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 8, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 2:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 8, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 3:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 8, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		}
	}
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    }
}
static void hybrid_rc_track_diag_60_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
	if (track_element_is_lift_hill(mapElement)) {
		switch (direction) {
		case 3:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+290), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	} else {
		switch (direction) {
		case 3:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+286), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	}
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 104, 0x20);
        break;
    case 1:
	if (track_element_is_lift_hill(mapElement)) {
		switch (direction) {
		case 0:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+291), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	} else {
		switch (direction) {
		case 0:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+287), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	}
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 104, 0x20);
        break;
    case 2:
	if (track_element_is_lift_hill(mapElement)) {
		switch (direction) {
		case 2:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+289), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	} else {
		switch (direction) {
		case 2:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+285), -16, -16, 32, 32, 3, height, -16, -16, height);
		    break;
		}
	}
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 104, 0x20);
        break;
    case 3:
	if (track_element_is_lift_hill(mapElement)) {
		switch (direction) {
		case 0:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 24, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 1:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+292), -16, -16, 32, 32, 3, height, -16, -16, height);
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 28, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 2:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 24, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 3:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 28, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		}
	} else {
		switch (direction) {
		case 0:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 24, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 1:
		    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+288), -16, -16, 32, 32, 3, height, -16, -16, height);
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 28, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 2:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 24, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		case 3:
		    metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 28, height, gTrackColours[SCHEME_SUPPORTS]);
		    break;
		}
	}
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 104, 0x20);
        break;
    }
}

//Banked turns
static void hybrid_rc_track_flat_to_left_bank(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (direction) {
    case 0:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+293), 0, 0, 32, 20, 3, height, 0, 6, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+294), 0, 0, 32, 1, 26, height, 0, 27, height);
        break;
    case 1:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+295), 0, 0, 32, 20, 3, height, 0, 6, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+296), 0, 0, 32, 1, 26, height, 0, 27, height);
        break;
    case 2:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+297), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 3:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+298), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    }
    if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 0, height, gTrackColours[SCHEME_SUPPORTS]);
    }
    paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 32, 0x20);
}
static void hybrid_rc_track_flat_to_right_bank(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (direction) {
    case 0:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+299), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 1:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+300), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 2:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+301), 0, 0, 32, 20, 3, height, 0, 6, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+302), 0, 0, 32, 1, 26, height, 0, 27, height);
        break;
    case 3:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+303), 0, 0, 32, 20, 3, height, 0, 6, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+304), 0, 0, 32, 1, 26, height, 0, 27, height);
        break;
    }
    if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 0, height, gTrackColours[SCHEME_SUPPORTS]);
    }
    paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 32, 0x20);
}
static void hybrid_rc_track_left_bank_to_flat(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (direction) {
    case 0:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+301), 0, 0, 32, 20, 3, height, 0, 6, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+302), 0, 0, 32, 1, 26, height, 0, 27, height);
        break;
    case 1:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+303), 0, 0, 32, 20, 3, height, 0, 6, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+304), 0, 0, 32, 1, 26, height, 0, 27, height);
        break;
    case 2:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+299), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 3:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+300), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    }
    if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 0, height, gTrackColours[SCHEME_SUPPORTS]);
    }
    paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 32, 0x20);
}
static void hybrid_rc_track_right_bank_to_flat(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (direction) {
    case 0:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+297), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 1:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+298), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 2:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+293), 0, 0, 32, 20, 3, height, 0, 6, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+294), 0, 0, 32, 1, 26, height, 0, 27, height);
        break;
    case 3:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+295), 0, 0, 32, 20, 3, height, 0, 6, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+296), 0, 0, 32, 1, 26, height, 0, 27, height);
        break;
    }
    if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 0, height, gTrackColours[SCHEME_SUPPORTS]);
    }
    paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 32, 0x20);
}
static void hybrid_rc_track_left_bank_to_25_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (direction) {
    case 0:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+305), 0, 0, 32, 20, 3, height, 0, 6, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+306), 0, 0, 32, 1, 34, height, 0, 27, height);
        break;
    case 1:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+307), 0, 0, 32, 20, 3, height, 0, 6, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+308), 0, 0, 32, 1, 34, height, 0, 27, height);
        break;
    case 2:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+309), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 3:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+310), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    }
    if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 3, height, gTrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3) {
        paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
    } else {
        paint_util_push_tunnel_rotated(direction, height, TUNNEL_8);
    }
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 48, 0x20);
}
static void hybrid_rc_track_right_bank_to_25_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (direction) {
    case 0:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+311), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 1:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+312), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 2:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+313), 0, 0, 32, 20, 3, height, 0, 6, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+314), 0, 0, 32, 1, 34, height, 0, 27, height);
        break;
    case 3:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+315), 0, 0, 32, 20, 3, height, 0, 6, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+316), 0, 0, 32, 1, 34, height, 0, 27, height);
        break;
    }
    if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 3, height, gTrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3) {
        paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
    } else {
        paint_util_push_tunnel_rotated(direction, height, TUNNEL_8);
    }
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 48, 0x20);
}
static void hybrid_rc_track_25_deg_up_to_left_bank(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (direction) {
    case 0:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+317), 0, 0, 32, 20, 3, height, 0, 6, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+318), 0, 0, 32, 1, 34, height, 0, 27, height);
        break;
    case 1:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+319), 0, 0, 32, 20, 3, height, 0, 6, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+320), 0, 0, 32, 1, 34, height, 0, 27, height);
        break;
    case 2:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+321), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 3:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+322), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    }
    if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 6, height, gTrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3) {
        paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_6);
    } else {
        paint_util_push_tunnel_rotated(direction, height + 8, TUNNEL_14);
    }
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 40, 0x20);
}
static void hybrid_rc_track_25_deg_up_to_right_bank(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (direction) {
    case 0:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+323), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 1:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+324), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 2:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+325), 0, 0, 32, 20, 3, height, 0, 6, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+326), 0, 0, 32, 1, 34, height, 0, 27, height);
        break;
    case 3:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+327), 0, 0, 32, 20, 3, height, 0, 6, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+328), 0, 0, 32, 1, 34, height, 0, 27, height);
        break;
    }
    if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 6, height, gTrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3) {
        paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_6);
    } else {
        paint_util_push_tunnel_rotated(direction, height + 8, TUNNEL_14);
    }
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 40, 0x20);
}
static void hybrid_rc_track_left_bank_to_25_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_25_deg_up_to_right_bank(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}
static void hybrid_rc_track_right_bank_to_25_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_25_deg_up_to_left_bank(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}
static void hybrid_rc_track_25_deg_down_to_left_bank(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_right_bank_to_25_deg_up(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}
static void hybrid_rc_track_25_deg_down_to_right_bank(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_left_bank_to_25_deg_up(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}
static void hybrid_rc_track_left_bank(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (direction) {
    case 0:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+329), 0, 0, 32, 1, 26, height, 0, 27, height);
        break;
    case 1:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+330), 0, 0, 32, 1, 26, height, 0, 27, height);
        break;
    case 2:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+331), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 3:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+332), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    }
    if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 0, height, gTrackColours[SCHEME_SUPPORTS]);
    }
    paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 32, 0x20);
}
static void hybrid_rc_track_right_bank(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_left_bank(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}
static void hybrid_rc_track_diag_flat_to_left_bank(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+337), -16, -16, 32, 32, 3, height, -16, -16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 1:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+333), -16, -16, 32, 32, 3, height, -16, -16, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+334), -16, -16, 32, 32, 0, height, -16, -16, height + 27);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 2:
        switch (direction) {
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+336), -16, -16, 32, 32, 3, height, -16, -16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+335), -16, -16, 32, 32, 3, height, -16, -16, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    }
}
static void hybrid_rc_track_diag_flat_to_right_bank(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+342), -16, -16, 32, 32, 3, height, -16, -16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 1:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+338), -16, -16, 32, 32, 3, height, -16, -16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 2:
        switch (direction) {
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+340), -16, -16, 32, 32, 3, height, -16, -16, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+341), -16, -16, 32, 32, 0, height, -16, -16, height + 27);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+339), -16, -16, 32, 32, 3, height, -16, -16, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    }
}
static void hybrid_rc_track_diag_left_bank_to_flat(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+339), -16, -16, 32, 32, 3, height, -16, -16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 1:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+340), -16, -16, 32, 32, 3, height, -16, -16, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+341), -16, -16, 32, 32, 0, height, -16, -16, height + 27);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 2:
        switch (direction) {
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+338), -16, -16, 32, 32, 3, height, -16, -16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+342), -16, -16, 32, 32, 3, height, -16, -16, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    }
}
static void hybrid_rc_track_diag_right_bank_to_flat(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+335), -16, -16, 32, 32, 3, height, -16, -16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 1:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+336), -16, -16, 32, 32, 3, height, -16, -16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 2:
        switch (direction) {
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+333), -16, -16, 32, 32, 3, height, -16, -16, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+334), -16, -16, 32, 32, 0, height, -16, -16, height + 27);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+337), -16, -16, 32, 32, 3, height, -16, -16, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    }
}
static void hybrid_rc_track_diag_left_bank_to_25_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+347), -16, -16, 32, 32, 3, height, -16, -16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 48, 0x20);
        break;
    case 1:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+343), -16, -16, 32, 32, 3, height, -16, -16, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+344), -16, -16, 32, 32, 0, height, -16, -16, height + 35);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 48, 0x20);
        break;
    case 2:
        switch (direction) {
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+346), -16, -16, 32, 32, 3, height, -16, -16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 48, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+345), -16, -16, 32, 32, 3, height, -16, -16, height);
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 48, 0x20);
        break;
    }
}
static void hybrid_rc_track_diag_right_bank_to_25_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+352), -16, -16, 32, 32, 3, height, -16, -16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 48, 0x20);
        break;
    case 1:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+348), -16, -16, 32, 32, 3, height, -16, -16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 48, 0x20);
        break;
    case 2:
        switch (direction) {
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+350), -16, -16, 32, 32, 3, height, -16, -16, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+351), -16, -16, 32, 32, 0, height, -16, -16, height + 35);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 48, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+349), -16, -16, 32, 32, 3, height, -16, -16, height);
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 48, 0x20);
        break;
    }
}
static void hybrid_rc_track_diag_25_deg_up_to_left_bank(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+357), -16, -16, 32, 32, 3, height, -16, -16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    case 1:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+353), -16, -16, 32, 32, 3, height, -16, -16, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+354), -16, -16, 32, 32, 0, height, -16, -16, height + 35);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    case 2:
        switch (direction) {
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+356), -16, -16, 32, 32, 3, height, -16, -16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 4, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+355), -16, -16, 32, 32, 3, height, -16, -16, height);
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 4, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 4, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 4, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    }
}
static void hybrid_rc_track_diag_25_deg_up_to_right_bank(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+362), -16, -16, 32, 32, 3, height, -16, -16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    case 1:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+358), -16, -16, 32, 32, 3, height, -16, -16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    case 2:
        switch (direction) {
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+360), -16, -16, 32, 32, 3, height, -16, -16, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+361), -16, -16, 32, 32, 0, height, -16, -16, height + 35);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 4, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+359), -16, -16, 32, 32, 3, height, -16, -16, height);
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 4, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 4, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 4, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    }
}
static void hybrid_rc_track_diag_left_bank_to_25_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+359), -16, -16, 32, 32, 3, height, -16, -16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        break;
    case 1:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+360), -16, -16, 32, 32, 3, height, -16, -16, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+361), -16, -16, 32, 32, 0, height, -16, -16, height + 35);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        break;
    case 2:
        switch (direction) {
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+358), -16, -16, 32, 32, 3, height, -16, -16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        break;
    case 3:
        switch (direction) {
        case 0:
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 4, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+362), -16, -16, 32, 32, 3, height, -16, -16, height);
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 4, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 4, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 4, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        break;
    }

    paint_util_set_general_support_height(height + 56, 0x20);
}
static void hybrid_rc_track_diag_right_bank_to_25_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+355), -16, -16, 32, 32, 3, height, -16, -16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        break;
    case 1:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+356), -16, -16, 32, 32, 3, height, -16, -16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        break;
    case 2:
        switch (direction) {
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+353), -16, -16, 32, 32, 3, height, -16, -16, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+354), -16, -16, 32, 32, 0, height, -16, -16, height + 35);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        break;
    case 3:
        switch (direction) {
        case 0:
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 4, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+357), -16, -16, 32, 32, 3, height, -16, -16, height);
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 4, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 4, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 4, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        break;
    }

    paint_util_set_general_support_height(height + 56, 0x20);
}
static void hybrid_rc_track_diag_25_deg_down_to_left_bank(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+349), -16, -16, 32, 32, 3, height, -16, -16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 48, 0x20);
        break;
    case 1:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+350), -16, -16, 32, 32, 3, height, -16, -16, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+351), -16, -16, 32, 32, 0, height, -16, -16, height + 35);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 48, 0x20);
        break;
    case 2:
        switch (direction) {
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+348), -16, -16, 32, 32, 3, height, -16, -16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 48, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+352), -16, -16, 32, 32, 3, height, -16, -16, height);
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 48, 0x20);
        break;
    }
}
static void hybrid_rc_track_diag_25_deg_down_to_right_bank(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+345), -16, -16, 32, 32, 3, height, -16, -16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 48, 0x20);
        break;
    case 1:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+346), -16, -16, 32, 32, 3, height, -16, -16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 48, 0x20);
        break;
    case 2:
        switch (direction) {
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+343), -16, -16, 32, 32, 3, height, -16, -16, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+344), -16, -16, 32, 32, 0, height, -16, -16, height + 35);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 48, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+347), -16, -16, 32, 32, 3, height, -16, -16, height);
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            metal_b_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 48, 0x20);
        break;
    }
}
static void hybrid_rc_track_diag_left_bank(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+366), -16, -16, 32, 32, 3, height, -16, -16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 1:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+363), -16, -16, 32, 32, 0, height, -16, -16, height + 27);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 2:
        switch (direction) {
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+365), -16, -16, 32, 32, 3, height, -16, -16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+364), -16, -16, 32, 32, 3, height, -16, -16, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    }
}
static void hybrid_rc_track_diag_right_bank(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+364), -16, -16, 32, 32, 3, height, -16, -16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 1:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+365), -16, -16, 32, 32, 3, height, -16, -16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 2:
        switch (direction) {
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+363), -16, -16, 32, 32, 0, height, -16, -16, height + 27);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+366), -16, -16, 32, 32, 3, height, -16, -16, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    }
}
static void hybrid_rc_track_left_quarter_turn_3_bank(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+367), 0, 0, 32, 20, 3, height, 0, 6, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+368), 0, 0, 32, 1, 26, height, 0, 27, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+371), 0, 0, 32, 1, 26, height, 0, 27, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+374), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+378), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 0, height, gTrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 1:
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 2:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+369), 0, 0, 16, 16, 3, height, 16, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+372), 0, 0, 16, 16, 1, height, 0, 0, height + 27);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+375), 0, 0, 16, 16, 3, height, 0, 16, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+379), 0, 0, 16, 16, 3, height, 16, 16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+370), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+373), 0, 0, 1, 32, 26, height, 27, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+376), 0, 0, 20, 32, 3, height, 6, 0, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+377), 0, 0, 1, 32, 26, height, 27, 0, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+380), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 0, height, gTrackColours[SCHEME_SUPPORTS]);
        switch (direction) {
        case 2:
            paint_util_push_tunnel_right(height, TUNNEL_6);
            break;
        case 3:
            paint_util_push_tunnel_left(height, TUNNEL_6);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    }
}
static void hybrid_rc_track_right_quarter_turn_3_bank(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    trackSequence = mapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence];
    hybrid_rc_track_left_quarter_turn_3_bank(rideIndex, trackSequence, (direction - 1) & 3, height, mapElement);
}
static void hybrid_rc_track_banked_left_quarter_turn_5(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+381), 0, 0, 32, 20, 3, height, 0, 6, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+382), 0, 0, 32, 1, 26, height, 0, 27, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+387), 0, 0, 32, 1, 26, height, 0, 27, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+392), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+398), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 0, height, gTrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 1:
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 2:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+383), 0, 0, 32, 16, 3, height, 0, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+388), 0, 0, 32, 16, 1, height, 0, 0, height + 27);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+393), 0, 0, 32, 16, 3, height, 0, 16, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+399), 0, 0, 32, 16, 3, height, 0, 16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+384), 0, 0, 16, 16, 3, height, 0, 16, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+389), 0, 0, 16, 16, 1, height, 16, 16, height + 27);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+394), 0, 0, 16, 16, 3, height, 16, 0, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+400), 0, 0, 16, 16, 3, height, 0, 0, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 4:
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 5:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+385), 0, 0, 16, 32, 3, height, 16, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+390), 0, 0, 16, 32, 1, height, 0, 0, height + 27);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+395), 0, 0, 16, 32, 3, height, 0, 0, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+401), 0, 0, 16, 32, 3, height, 16, 0, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 6:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+386), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+391), 0, 0, 1, 32, 26, height, 27, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+396), 0, 0, 20, 32, 3, height, 6, 0, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+397), 0, 0, 1, 32, 26, height, 27, 0, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+402), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 0, height, gTrackColours[SCHEME_SUPPORTS]);
        switch (direction) {
        case 2:
            paint_util_push_tunnel_right(height, TUNNEL_6);
            break;
        case 3:
            paint_util_push_tunnel_left(height, TUNNEL_6);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    }
}
static void hybrid_rc_track_banked_right_quarter_turn_5(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    trackSequence = mapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence];
    hybrid_rc_track_banked_left_quarter_turn_5(rideIndex, trackSequence, (direction - 1) & 3, height, mapElement);
}
static void hybrid_rc_track_left_eighth_bank_to_diag(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+403), 0, 0, 32, 1, 26, height, 0, 27, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+407), 0, 0, 32, 1, 26, height, 0, 27, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+411), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+415), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 0, height, gTrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 1:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+404), 0, 0, 32, 16, 3, height, 0, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+408), 0, 0, 34, 16, 0, height, 0, 0, height + 27);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+412), 0, 0, 32, 16, 3, height, 0, 16, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+416), 0, 0, 32, 16, 3, height, 0, 16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 2:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+405), 0, 0, 16, 16, 3, height, 0, 16, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+409), 0, 0, 16, 16, 0, height, 16, 16, height + 27);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+413), 0, 0, 16, 16, 3, height, 16, 0, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+417), 0, 0, 16, 16, 3, height, 0, 0, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 3:
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 4:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+406), 0, 0, 16, 16, 3, height, 16, 16, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+410), 0, 0, 16, 18, 0, height, 0, 16, height + 27);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+414), 0, 0, 16, 16, 3, height, 0, 0, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+418), 0, 0, 16, 16, 3, height, 16, 0, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    }
}
static void hybrid_rc_track_right_eighth_bank_to_diag(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+419), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+423), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+427), 0, 0, 32, 1, 26, height, 0, 27, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+431), 0, 0, 32, 1, 26, height, 0, 27, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 0, height, gTrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 1:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+420), 0, 0, 32, 16, 3, height, 0, 16, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+424), 0, 0, 32, 16, 3, height, 0, 16, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+428), 0, 0, 34, 16, 0, height, 0, 0, height + 27);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+432), 0, 0, 32, 16, 3, height, 0, 0, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 2:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+421), 0, 0, 16, 16, 3, height, 0, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+425), 0, 0, 16, 16, 3, height, 16, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+429), 0, 0, 28, 28, 0, height, 4, 4, height + 27);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+433), 0, 0, 16, 16, 3, height, 0, 16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 3:
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 4:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+422), 0, 0, 16, 16, 3, height, 16, 0, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 1, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+426), 0, 0, 16, 16, 3, height, 0, 0, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 0, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+430), 0, 0, 16, 18, 0, height, 0, 16, height + 27);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 2, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+434), 0, 0, 16, 16, 3, height, 16, 16, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 3, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    }
}
static void hybrid_rc_track_left_eighth_bank_to_orthogonal(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    trackSequence = mapLeftEighthTurnToOrthogonal[trackSequence];
    hybrid_rc_track_right_eighth_bank_to_diag(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}
static void hybrid_rc_track_right_eighth_bank_to_orthogonal(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    trackSequence = mapLeftEighthTurnToOrthogonal[trackSequence];
    hybrid_rc_track_left_eighth_bank_to_diag(rideIndex, trackSequence, (direction + 3) & 3, height, mapElement);
}
//Sloped turns
static void hybrid_rc_track_left_quarter_turn_3_25_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 0:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+435), 0, 6, 32, 20, 3, height);
            break;
        case 1:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+437), 0, 6, 32, 20, 3, height);
            break;
        case 2:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+439), 0, 6, 32, 20, 3, height);
            break;
        case 3:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+441), 0, 6, 32, 20, 3, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_7);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 1:
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    case 2:
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+436), 6, 0, 20, 32, 3, height);
            break;
        case 1:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+438), 6, 0, 20, 32, 3, height);
            break;
        case 2:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+440), 6, 0, 20, 32, 3, height);
            break;
        case 3:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+442), 6, 0, 20, 32, 3, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
        switch (direction) {
        case 2:
            paint_util_push_tunnel_right(height + 8, TUNNEL_8);
            break;
        case 3:
            paint_util_push_tunnel_left(height + 8, TUNNEL_8);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    }
}
static void hybrid_rc_track_right_quarter_turn_3_25_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 0:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+443), 0, 6, 32, 20, 3, height);
            break;
        case 1:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+445), 0, 6, 32, 20, 3, height);
            break;
        case 2:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+447), 0, 6, 32, 20, 3, height);
            break;
        case 3:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+449), 0, 6, 32, 20, 3, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_7);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 1:
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    case 2:
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+444), 6, 0, 20, 32, 3, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+446), 6, 0, 20, 32, 3, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+448), 6, 0, 20, 32, 3, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 10, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+450), 6, 0, 20, 32, 3, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        }
        switch (direction) {
        case 0:
            paint_util_push_tunnel_right(height + 8, TUNNEL_8);
            break;
        case 1:
            paint_util_push_tunnel_left(height + 8, TUNNEL_8);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    }
}
static void hybrid_rc_track_left_quarter_turn_3_25_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    trackSequence = mapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence];
    hybrid_rc_track_right_quarter_turn_3_25_deg_up(rideIndex, trackSequence, (direction + 1) & 3, height, mapElement);
}
static void hybrid_rc_track_right_quarter_turn_3_25_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    trackSequence = mapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence];
    hybrid_rc_track_left_quarter_turn_3_25_deg_up(rideIndex, trackSequence, (direction - 1) & 3, height, mapElement);
}
static void hybrid_rc_track_left_quarter_turn_5_25_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+451), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+456), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+461), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+466), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_7);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 1:
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 2:
        switch (direction) {
        case 0:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+452), 0, 0, 32, 16, 3, height);
            break;
        case 1:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+457), 0, 0, 32, 16, 3, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+462), 0, 0, 32, 16, 3, height, 0, 16, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+467), 0, 0, 32, 16, 3, height, 0, 16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+453), 0, 0, 16, 16, 3, height, 0, 16, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+458), 0, 0, 16, 16, 3, height, 16, 16, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+463), 0, 0, 16, 16, 3, height, 16, 0, height);
            break;
        case 3:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+468), 0, 0, 16, 16, 3, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 64, 0x20);
        break;
    case 4:
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 5:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+454), 0, 0, 16, 32, 3, height, 16, 0, height);
            break;
        case 1:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+459), 0, 0, 16, 32, 3, height);
            break;
        case 2:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+464), 0, 0, 16, 32, 3, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+469), 0, 0, 16, 32, 3, height, 16, 0, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 6:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+455), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+460), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+465), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+470), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
        switch (direction) {
        case 2:
            paint_util_push_tunnel_right(height + 8, TUNNEL_8);
            break;
        case 3:
            paint_util_push_tunnel_left(height + 8, TUNNEL_8);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    }
}
static void hybrid_rc_track_right_quarter_turn_5_25_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+471), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+476), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+481), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+486), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_7);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 1:
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 2:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+472), 0, 0, 32, 16, 3, height, 0, 16, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+477), 0, 0, 32, 16, 3, height, 0, 16, height);
            break;
        case 2:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+482), 0, 0, 32, 16, 3, height);
            break;
        case 3:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+487), 0, 0, 32, 16, 3, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+473), 0, 0, 16, 16, 3, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+478), 0, 0, 16, 16, 3, height, 16, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+483), 0, 0, 16, 16, 3, height, 16, 16, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+488), 0, 0, 16, 16, 3, height, 0, 16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 64, 0x20);
        break;
    case 4:
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 5:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+474), 0, 0, 16, 32, 3, height, 16, 0, height);
            break;
        case 1:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+479), 0, 0, 16, 32, 3, height);
            break;
        case 2:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+484), 0, 0, 16, 32, 3, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+489), 0, 0, 16, 32, 3, height, 16, 0, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 6:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+475), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+480), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+485), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+490), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
        switch (direction) {
        case 0:
            paint_util_push_tunnel_right(height + 8, TUNNEL_8);
            break;
        case 1:
            paint_util_push_tunnel_left(height + 8, TUNNEL_8);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    }
}
static void hybrid_rc_track_left_quarter_turn_5_25_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    trackSequence = mapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence];
    hybrid_rc_track_right_quarter_turn_5_25_deg_up(rideIndex, trackSequence, (direction + 1) & 3, height, mapElement);
}
static void hybrid_rc_track_right_quarter_turn_5_25_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    trackSequence = mapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence];
    hybrid_rc_track_left_quarter_turn_5_25_deg_up(rideIndex, trackSequence, (direction - 1) & 3, height, mapElement);
}
static void hybrid_rc_track_left_quarter_turn_1_60_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (direction) {
    case 0:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+491), 0, 0, 28, 28, 3, height, 2, 2, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+492), 0, 0, 28, 28, 1, height, 2, 2, height + 99);
        break;
    case 1:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+493), 0, 0, 28, 28, 3, height, 2, 2, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+494), 0, 0, 28, 28, 1, height, 2, 2, height + 99);
        break;
    case 2:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+495), 0, 0, 28, 28, 3, height, 2, 2, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+496), 0, 0, 28, 28, 1, height, 2, 2, height + 99);
        break;
    case 3:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+497), 0, 0, 28, 28, 3, height, 2, 2, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+498), 0, 0, 28, 28, 1, height, 2, 2, height + 99);
        break;
    }
    track_paint_util_left_quarter_turn_1_tile_tunnel(direction, height, -8, TUNNEL_7, +56, TUNNEL_8);
    paint_util_set_segment_support_height(SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(height + 104, 0x20);
}
static void hybrid_rc_track_right_quarter_turn_1_60_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (direction) {
    case 0:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+499), 0, 0, 28, 28, 3, height, 2, 2, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+500), 0, 0, 28, 28, 1, height, 2, 2, height + 99);
        break;
    case 1:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+501), 0, 0, 28, 28, 3, height, 2, 2, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+502), 0, 0, 28, 28, 1, height, 2, 2, height + 99);
        break;
    case 2:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+503), 0, 0, 28, 28, 3, height, 2, 2, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+504), 0, 0, 28, 28, 1, height, 2, 2, height + 99);
        break;
    case 3:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+505), 0, 0, 28, 28, 3, height, 2, 2, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+506), 0, 0, 28, 28, 1, height, 2, 2, height + 99);
        break;
    }
    track_paint_util_right_quarter_turn_1_tile_tunnel(direction, height, -8, TUNNEL_7, +56, TUNNEL_8);
    paint_util_set_segment_support_height(SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(height + 104, 0x20);
}
static void hybrid_rc_track_left_quarter_turn_1_60_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_right_quarter_turn_1_60_deg_up(rideIndex, trackSequence, (direction + 1) & 3, height, mapElement);
}
static void hybrid_rc_track_right_quarter_turn_1_60_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_left_quarter_turn_1_60_deg_up(rideIndex, trackSequence, (direction - 1) & 3, height, mapElement);
}
static void hybrid_rc_track_left_quarter_turn_1_90_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
        case 0:
            switch (direction) {
                case 0:
                    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+507), 0, 0, 2, 20, 63, height, 4, 6, height + 8);
                    break;
                case 1:
                    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+508), 0, 0, 2, 20, 63, height, 4, 6, height + 8);
                    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+509), 0, 0, 2, 20, 63, height, 24, 6, height + 8);
                    break;
                case 2:
                    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+510), 0, 0, 2, 20, 63, height, 24, 6, height + 8);
                    break;
                case 3:
                    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+511), 0, 0, 2, 20, 63, height, 4, 6, height + 8);
                    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+512), 0, 0, 2, 20, 63, height, 24, 6, height + 8);
                    break;
            }
            paint_util_set_vertical_tunnel(height + 96);
            paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
            paint_util_set_general_support_height(height + 96, 0x20);
            break;
        case 1:
            break;
    }
}
static void hybrid_rc_track_right_quarter_turn_1_90_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
        case 0:
            switch (direction) {
                case 0:
                    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+513), 0, 0, 2, 20, 63, height, 4, 6, height + 8);
                    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+514), 0, 0, 2, 20, 63, height, 24, 6, height + 8);
                    break;
                case 1:
                    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+515), 0, 0, 2, 20, 63, height, 24, 6, height + 8);
                    break;
                case 2:
                    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+516), 0, 0, 2, 20, 63, height, 4, 6, height + 8);
                    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+517), 0, 0, 2, 20, 63, height, 24, 6, height + 8);
                    break;
                case 3:
                    sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+518), 0, 0, 2, 20, 63, height, 4, 6, height + 8);
                    break;
            }
            paint_util_set_vertical_tunnel(height + 96);
            paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
            paint_util_set_general_support_height(height + 96, 0x20);
            break;
        case 1:
            break;
    }
}
static void hybrid_rc_track_left_quarter_turn_1_90_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_right_quarter_turn_1_90_deg_up(rideIndex, trackSequence, (direction + 1) & 3, height, mapElement);
}
static void hybrid_rc_track_right_quarter_turn_1_90_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_left_quarter_turn_1_90_deg_up(rideIndex, trackSequence, (direction - 1) & 3, height, mapElement);
}
//Sloped banked turns
static void hybrid_rc_track_25_deg_up_to_left_banked_25_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (direction) {
    case 0:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+519), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 1:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+520), 0, 0, 32, 20, 3, height, 0, 6, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+521), 0, 0, 32, 1, 34, height, 0, 27, height);
        break;
    case 2:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+522), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 3:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+523), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    }
    if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3) {
        paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_7);
    } else {
        paint_util_push_tunnel_rotated(direction, height + 8, TUNNEL_8);
    }
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 56, 0x20);
}
static void hybrid_rc_track_25_deg_up_to_right_banked_25_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (direction) {
    case 0:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+524), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 1:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+525), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 2:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+526), 0, 0, 32, 20, 3, height, 0, 6, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+527), 0, 0, 32, 1, 34, height, 0, 27, height);
        break;
    case 3:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+528), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    }
    if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3) {
        paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_7);
    } else {
        paint_util_push_tunnel_rotated(direction, height + 8, TUNNEL_8);
    }
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 56, 0x20);
}
static void hybrid_rc_track_left_banked_25_deg_up_to_25_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (direction) {
    case 0:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+529), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 1:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+530), 0, 0, 32, 20, 3, height, 0, 6, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+531), 0, 0, 32, 1, 34, height, 0, 27, height);
        break;
    case 2:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+532), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 3:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+533), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    }
    if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3) {
        paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_7);
    } else {
        paint_util_push_tunnel_rotated(direction, height + 8, TUNNEL_8);
    }
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 56, 0x20);
}
static void hybrid_rc_track_right_banked_25_deg_up_to_25_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (direction) {
    case 0:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+534), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 1:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+535), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 2:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+536), 0, 0, 32, 20, 3, height, 0, 6, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+537), 0, 0, 32, 1, 34, height, 0, 27, height);
        break;
    case 3:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+538), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    }
    if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3) {
        paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_7);
    } else {
        paint_util_push_tunnel_rotated(direction, height + 8, TUNNEL_8);
    }
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 56, 0x20);
}
static void hybrid_rc_track_25_deg_down_to_left_banked_25_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_right_banked_25_deg_up_to_25_deg_up(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}
static void hybrid_rc_track_25_deg_down_to_right_banked_25_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_left_banked_25_deg_up_to_25_deg_up(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}
static void hybrid_rc_track_left_banked_25_deg_down_to_25_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_25_deg_up_to_right_banked_25_deg_up(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}
static void hybrid_rc_track_right_banked_25_deg_down_to_25_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_25_deg_up_to_left_banked_25_deg_up(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}
static void hybrid_rc_track_left_banked_flat_to_left_banked_25_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (direction) {
    case 0:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+539), 0, 0, 32, 1, 34, height, 0, 27, height);
        break;
    case 1:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+540), 0, 0, 32, 1, 34, height, 0, 27, height);
        break;
    case 2:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+541), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 3:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+542), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    }
    if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 3, height, gTrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3) {
        paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
    } else {
        paint_util_push_tunnel_rotated(direction, height, TUNNEL_8);
    }
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 48, 0x20);
}
static void hybrid_rc_track_right_banked_flat_to_right_banked_25_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (direction) {
    case 0:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+543), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 1:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+544), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 2:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+545), 0, 0, 32, 1, 34, height, 0, 27, height);
        break;
    case 3:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+546), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    }
    if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 3, height, gTrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3) {
        paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
    } else {
        paint_util_push_tunnel_rotated(direction, height, TUNNEL_8);
    }
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 48, 0x20);
}
static void hybrid_rc_track_left_banked_25_deg_up_to_left_banked_flat(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (direction) {
    case 0:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+547), 0, 0, 32, 1, 34, height, 0, 27, height);
        break;
    case 1:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+548), 0, 0, 32, 1, 34, height, 0, 27, height);
        break;
    case 2:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+549), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 3:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+550), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    }
    if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 6, height, gTrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3) {
        paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_6);
    } else {
        paint_util_push_tunnel_rotated(direction, height + 8, TUNNEL_14);
    }
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 40, 0x20);
}
static void hybrid_rc_track_right_banked_25_deg_up_to_right_banked_flat(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (direction) {
    case 0:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+551), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 1:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+552), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 2:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+553), 0, 0, 32, 1, 34, height, 0, 27, height);
        break;
    case 3:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+554), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    }
    if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 6, height, gTrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3) {
        paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_6);
    } else {
        paint_util_push_tunnel_rotated(direction, height + 8, TUNNEL_14);
    }
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 40, 0x20);
}
static void hybrid_rc_track_left_banked_flat_to_left_banked_25_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_right_banked_25_deg_up_to_right_banked_flat(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}
static void hybrid_rc_track_right_banked_flat_to_right_banked_25_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_left_banked_25_deg_up_to_left_banked_flat(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}
static void hybrid_rc_track_left_banked_25_deg_down_to_left_banked_flat(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_right_banked_flat_to_right_banked_25_deg_up(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}
static void hybrid_rc_track_right_banked_25_deg_down_to_right_banked_flat(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_left_banked_flat_to_left_banked_25_deg_up(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}

static void hybrid_rc_track_25_deg_up_left_banked(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (direction) {
    case 0:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+555), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 1:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+556), 0, 0, 32, 1, 34, height, 0, 27, height);
        break;
    case 2:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+557), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 3:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+558), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    }
    if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3) {
        paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_7);
    } else {
        paint_util_push_tunnel_rotated(direction, height + 8, TUNNEL_8);
    }
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 56, 0x20);
}
static void hybrid_rc_track_25_deg_up_right_banked(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (direction) {
    case 0:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+559), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 1:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+560), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 2:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+561), 0, 0, 32, 1, 34, height, 0, 27, height);
        break;
    case 3:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+562), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    }
    if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3) {
        paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_7);
    } else {
        paint_util_push_tunnel_rotated(direction, height + 8, TUNNEL_8);
    }
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 56, 0x20);
}
static void hybrid_rc_track_25_deg_down_left_banked(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_25_deg_up_right_banked(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}
static void hybrid_rc_track_25_deg_down_right_banked(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_25_deg_up_left_banked(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}
static void hybrid_rc_track_flat_to_left_banked_25_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (direction) {
    case 0:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+563), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 1:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+564), 0, 0, 32, 20, 3, height, 0, 6, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+565), 0, 0, 32, 1, 34, height, 0, 27, height);
        break;
    case 2:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+566), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 3:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+567), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    }
    if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 3, height, gTrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3) {
        paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
    } else {
        paint_util_push_tunnel_rotated(direction, height, TUNNEL_8);
    }
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 48, 0x20);
}
static void hybrid_rc_track_flat_to_right_banked_25_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (direction) {
    case 0:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+568), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 1:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+569), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 2:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+570), 0, 0, 32, 20, 3, height, 0, 6, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+571), 0, 0, 32, 1, 34, height, 0, 27, height);
        break;
    case 3:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+572), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    }
    if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 3, height, gTrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3) {
        paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
    } else {
        paint_util_push_tunnel_rotated(direction, height, TUNNEL_8);
    }
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 48, 0x20);
}
static void hybrid_rc_track_left_banked_25_deg_up_to_flat(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (direction) {
    case 0:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+573), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 1:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+574), 0, 0, 32, 20, 3, height, 0, 6, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+575), 0, 0, 32, 1, 34, height, 0, 27, height);
        break;
    case 2:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+576), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 3:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+577), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    }
    if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 6, height, gTrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3) {
        paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_6);
    } else {
        paint_util_push_tunnel_rotated(direction, height + 8, TUNNEL_14);
    }
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 40, 0x20);
}
static void hybrid_rc_track_right_banked_25_deg_up_to_flat(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (direction) {
    case 0:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+578), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 1:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+579), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    case 2:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+580), 0, 0, 32, 20, 3, height, 0, 6, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+581), 0, 0, 32, 1, 34, height, 0, 27, height);
        break;
    case 3:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+582), 0, 0, 32, 20, 3, height, 0, 6, height);
        break;
    }
    if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 6, height, gTrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3) {
        paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_6);
    } else {
        paint_util_push_tunnel_rotated(direction, height + 8, TUNNEL_14);
    }
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 40, 0x20);
}
static void hybrid_rc_track_flat_to_left_banked_25_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_right_banked_25_deg_up_to_flat(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}
static void hybrid_rc_track_flat_to_right_banked_25_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_left_banked_25_deg_up_to_flat(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}
static void hybrid_rc_track_left_banked_25_deg_down_to_flat(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_flat_to_right_banked_25_deg_up(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}
static void hybrid_rc_track_right_banked_25_deg_down_to_flat(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_flat_to_left_banked_25_deg_up(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}


static void hybrid_rc_track_left_banked_quarter_turn_3_25_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 0:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+583), 0, 6, 32, 20, 3, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+585), 0, 6, 32, 1, 34, height, 0, 27, height);
            break;
        case 2:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+587), 0, 6, 32, 20, 3, height);
            break;
        case 3:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+589), 0, 6, 32, 20, 3, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_7);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 1:
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    case 2:
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+584), 6, 0, 20, 32, 3, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+586), 6, 0, 1, 32, 34, height, 27, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+588), 6, 0, 1, 32, 34, height, 27, 0, height);
            break;
        case 3:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+590), 6, 0, 20, 32, 3, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
        switch (direction) {
        case 2:
            paint_util_push_tunnel_right(height + 8, TUNNEL_8);
            break;
        case 3:
            paint_util_push_tunnel_left(height + 8, TUNNEL_8);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    }
}
static void hybrid_rc_track_right_banked_quarter_turn_3_25_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 0:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+591), 0, 6, 32, 20, 3, height);
            break;
        case 1:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+593), 0, 6, 32, 20, 3, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+595), 0, 6, 32, 1, 34, height, 0, 27, height);
            break;
        case 3:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+597), 0, 6, 32, 20, 3, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_7);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 1:
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    case 2:
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+592), 6, 0, 20, 32, 3, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+594), 6, 0, 1, 32, 34, height, 27, 0, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+596), 6, 0, 1, 32, 34, height, 27, 0, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 10, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+598), 6, 0, 20, 32, 3, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        }
        switch (direction) {
        case 0:
            paint_util_push_tunnel_right(height + 8, TUNNEL_8);
            break;
        case 1:
            paint_util_push_tunnel_left(height + 8, TUNNEL_8);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    }
}
static void hybrid_rc_track_left_banked_quarter_turn_3_25_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    trackSequence = mapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence];
    hybrid_rc_track_right_banked_quarter_turn_3_25_deg_up(rideIndex, trackSequence, (direction + 1) & 3, height, mapElement);
}
static void hybrid_rc_track_right_banked_quarter_turn_3_25_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    trackSequence = mapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence];
    hybrid_rc_track_left_banked_quarter_turn_3_25_deg_up(rideIndex, trackSequence, (direction - 1) & 3, height, mapElement);
}
static void hybrid_rc_track_left_banked_quarter_turn_5_25_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+599), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+604), 0, 0, 32, 1, 34, height, 0, 27, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+609), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+614), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_7);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 1:
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 2:
        switch (direction) {
        case 0:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+600), 0, 0, 32, 16, 3, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+605), 0, 0, 1, 1, 34, height, 30, 30, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+610), 0, 0, 32, 16, 3, height, 0, 16, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+615), 0, 0, 32, 16, 3, height, 0, 16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+601), 0, 0, 16, 16, 3, height, 0, 16, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+606), 0, 0, 1, 1, 34, height, 30, 30, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+611), 0, 0, 16, 16, 3, height, 16, 0, height);
            break;
        case 3:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+616), 0, 0, 16, 16, 3, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 64, 0x20);
        break;
    case 4:
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 5:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+602), 0, 0, 16, 32, 3, height, 16, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+607), 0, 0, 1, 1, 34, height, 30, 30, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+612), 0, 0, 1, 32, 34, height, 27, 0, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+617), 0, 0, 16, 32, 3, height, 16, 0, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 6:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+603), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+608), 0, 0, 1, 32, 34, height, 27, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+613), 0, 0, 1, 32, 34, height, 27, 0, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+618), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
        switch (direction) {
        case 2:
            paint_util_push_tunnel_right(height + 8, TUNNEL_8);
            break;
        case 3:
            paint_util_push_tunnel_left(height + 8, TUNNEL_8);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    }
}
static void hybrid_rc_track_right_banked_quarter_turn_5_25_deg_up(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+619), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+624), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+629), 0, 0, 32, 1, 34, height, 0, 27, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+634), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_7);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 1:
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 2:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+620), 0, 0, 32, 16, 3, height, 0, 16, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+625), 0, 0, 32, 16, 3, height, 0, 16, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+630), 0, 0, 1, 1, 34, height, 30, 30, height);
            break;
        case 3:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+635), 0, 0, 32, 16, 3, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+621), 0, 0, 16, 16, 3, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+626), 0, 0, 16, 16, 3, height, 16, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+631), 0, 0, 1, 1, 34, height, 30, 30, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+636), 0, 0, 16, 16, 3, height, 0, 16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 64, 0x20);
        break;
    case 4:
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 5:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] |  (SPR_G2_BEGIN+622), 0, 0, 16, 32, 3, height, 16, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] |  (SPR_G2_BEGIN+627), 0, 0, 1, 32, 34, height, 27, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+632), 0, 0, 1, 1, 34, height, 30, 30, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+637), 0, 0, 16, 32, 3, height, 16, 0, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 6:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] |  (SPR_G2_BEGIN+623), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] |  (SPR_G2_BEGIN+628), 0, 0, 1, 32, 34, height, 27, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+633), 0, 0, 1, 32, 34, height, 27, 0, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+638), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
        switch (direction) {
        case 0:
            paint_util_push_tunnel_right(height + 8, TUNNEL_8);
            break;
        case 1:
            paint_util_push_tunnel_left(height + 8, TUNNEL_8);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    }
}
static void hybrid_rc_track_left_banked_quarter_turn_5_25_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    trackSequence = mapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence];
    hybrid_rc_track_right_banked_quarter_turn_5_25_deg_up(rideIndex, trackSequence, (direction + 1) & 3, height, mapElement);
}
static void hybrid_rc_track_right_banked_quarter_turn_5_25_deg_down(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    trackSequence = mapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence];
    hybrid_rc_track_left_banked_quarter_turn_5_25_deg_up(rideIndex, trackSequence, (direction - 1) & 3, height, mapElement);
}






static void hybrid_rc_track_s_bend_left(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+639), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+643), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+642), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+646), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 0, height, gTrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 1:
        switch (direction) {
        case 0:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+640), 0, 0, 32, 26, 3, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 5, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+644), 0, 0, 32, 26, 3, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 6, 1, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+641), 0, 0, 32, 26, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+645), 0, 0, 32, 26, 3, height, 0, 6, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 2:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+641), 0, 0, 32, 26, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+645), 0, 0, 32, 26, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+640), 0, 0, 32, 26, 3, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 5, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+644), 0, 0, 32, 26, 3, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 6, 1, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+642), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+646), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+639), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+643), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 0, height, gTrackColours[SCHEME_SUPPORTS]);
        switch (direction) {
        case 1:
            paint_util_push_tunnel_right(height, TUNNEL_6);
            break;
        case 2:
            paint_util_push_tunnel_left(height, TUNNEL_6);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    }
}
static void hybrid_rc_track_s_bend_right(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+647), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+651), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+650), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+653), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 0, height, gTrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 1:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+648), 0, 0, 32, 26, 3, height, 0, 6, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 8, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+652), 0, 0, 32, 26, 3, height, 0, 6, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 7, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+649), 0, 0, 32, 26, 3, height);
            break;
        case 3:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+653), 0, 0, 32, 26, 3, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 2:
        switch (direction) {
        case 0:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+649), 0, 0, 32, 26, 3, height);
            break;
        case 1:
            sub_98196C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+653), 0, 0, 32, 26, 3, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+648), 0, 0, 32, 26, 3, height, 0, 6, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 8, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+652), 0, 0, 32, 26, 3, height, 0, 6, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 7, 0, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+650), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+654), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+647), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+651), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 0, height, gTrackColours[SCHEME_SUPPORTS]);
        switch (direction) {
        case 1:
            paint_util_push_tunnel_right(height, TUNNEL_6);
            break;
        case 2:
            paint_util_push_tunnel_left(height, TUNNEL_6);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    }
}
static void hybrid_rc_track_left_half_banked_helix_up_small(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+655), 0, 0, 32, 20, 3, height, 0, 6, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+656), 0, 0, 32, 1, 26, height, 0, 27, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+659), 0, 0, 32, 1, 26, height, 0, 27, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+662), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+666), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 2, height, gTrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 1:
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 2:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+657), 0, 0, 16, 16, 3, height, 16, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+660), 0, 0, 16, 16, 1, height, 0, 0, height + 27);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+663), 0, 0, 16, 16, 3, height, 0, 16, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+667), 0, 0, 16, 16, 3, height, 16, 16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+658), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+661), 0, 0, 1, 32, 26, height, 27, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+664), 0, 0, 20, 32, 3, height, 6, 0, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+665), 0, 0, 1, 32, 26, height, 27, 0, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+668), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 6, height, gTrackColours[SCHEME_SUPPORTS]);
        switch (direction) {
        case 2:
            paint_util_push_tunnel_right(height + 8, TUNNEL_6);
            break;
        case 3:
            paint_util_push_tunnel_left(height + 8, TUNNEL_6);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 4:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+666), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+655), 0, 0, 20, 32, 3, height, 6, 0, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+656), 0, 0, 1, 32, 26, height, 27, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+659), 0, 0, 1, 32, 26, height, 27, 0, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+662), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 2, height, gTrackColours[SCHEME_SUPPORTS]);
        switch (direction) {
        case 0:
            paint_util_push_tunnel_right(height, TUNNEL_6);
            break;
        case 1:
            paint_util_push_tunnel_left(height, TUNNEL_6);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 5:
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 6:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+667), 0, 0, 16, 16, 3, height, 16, 16, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+657), 0, 0, 16, 16, 3, height, 0, 16, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+660), 0, 0, 16, 16, 1, height, 0, 0, height + 27);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+663), 0, 0, 16, 16, 3, height, 16, 0, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 7:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+668), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+658), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+661), 0, 0, 32, 1, 26, height, 0, 27, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+664), 0, 0, 32, 20, 3, height, 0, 6, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+665), 0, 0, 32, 1, 26, height, 0, 27, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 6, height, gTrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height + 8, TUNNEL_6);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    }
}
static void hybrid_rc_track_right_half_banked_helix_up_small(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+669), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+672), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+676), 0, 0, 32, 1, 26, height, 0, 27, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+679), 0, 0, 32, 20, 3, height, 0, 6, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+680), 0, 0, 32, 1, 26, height, 0, 27, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 2, height, gTrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 1:
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 2:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+670), 0, 0, 16, 16, 3, height, 16, 16, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+673), 0, 0, 16, 16, 3, height, 0, 16, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+677), 0, 0, 16, 16, 1, height, 0, 0, height + 27);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+681), 0, 0, 16, 16, 3, height, 16, 0, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+671), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+674), 0, 0, 20, 32, 3, height, 6, 0, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+675), 0, 0, 1, 32, 26, height, 27, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+678), 0, 0, 1, 32, 26, height, 27, 0, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+682), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 6, height, gTrackColours[SCHEME_SUPPORTS]);
        switch (direction) {
        case 0:
            paint_util_push_tunnel_right(height + 8, TUNNEL_6);
            break;
        case 1:
            paint_util_push_tunnel_left(height + 8, TUNNEL_6);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 4:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+672), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+676), 0, 0, 1, 32, 26, height, 27, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+679), 0, 0, 20, 32, 3, height, 6, 0, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+680), 0, 0, 1, 32, 26, height, 27, 0, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+669), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 2, height, gTrackColours[SCHEME_SUPPORTS]);
        switch (direction) {
        case 2:
            paint_util_push_tunnel_right(height, TUNNEL_6);
            break;
        case 3:
            paint_util_push_tunnel_left(height, TUNNEL_6);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 5:
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 6:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+673), 0, 0, 16, 16, 3, height, 16, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+677), 0, 0, 16, 16, 1, height, 0, 0, height + 27);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+681), 0, 0, 16, 16, 3, height, 0, 16, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+670), 0, 0, 16, 16, 3, height, 16, 16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 7:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+674), 0, 0, 32, 20, 3, height, 0, 6, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+675), 0, 0, 32, 1, 26, height, 0, 27, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+678), 0, 0, 32, 1, 26, height, 0, 27, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+682), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+671), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 6, height, gTrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height + 8, TUNNEL_6);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    }
}
static void hybrid_rc_track_left_half_banked_helix_down_small(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    if (trackSequence >= 4) {
        trackSequence -= 4;
        direction = (direction - 1) & 3;
    }
    trackSequence = mapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence];
    hybrid_rc_track_right_half_banked_helix_up_small(rideIndex, trackSequence, (direction + 1) & 3, height, mapElement);
}
static void hybrid_rc_track_right_half_banked_helix_down_small(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    if (trackSequence >= 4) {
        trackSequence -= 4;
        direction = (direction + 1) & 3;
    }
    trackSequence = mapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence];
    hybrid_rc_track_left_half_banked_helix_up_small(rideIndex, trackSequence, (direction - 1) & 3, height, mapElement);
}
static void hybrid_rc_track_left_half_banked_helix_up_large(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+683), 0, 0, 32, 20, 3, height, 0, 6, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+684), 0, 0, 32, 1, 26, height, 0, 27, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+689), 0, 0, 32, 1, 26, height, 0, 27, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+694), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+700), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 1, height, gTrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 1:
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 2:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+685), 0, 0, 32, 16, 3, height, 0, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+690), 0, 0, 32, 16, 1, height, 0, 0, height + 27);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+695), 0, 0, 32, 16, 3, height, 0, 16, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+701), 0, 0, 32, 16, 3, height, 0, 16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+686), 0, 0, 16, 16, 3, height, 0, 16, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+691), 0, 0, 16, 16, 1, height, 16, 16, height + 27);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+696), 0, 0, 16, 16, 3, height, 16, 0, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+702), 0, 0, 16, 16, 3, height, 0, 0, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 4:
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 5:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+687), 0, 0, 16, 32, 3, height, 16, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+692), 0, 0, 16, 32, 1, height, 0, 0, height + 27);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+697), 0, 0, 16, 32, 3, height, 0, 0, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+703), 0, 0, 16, 32, 3, height, 16, 0, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 6:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+688), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+693), 0, 0, 1, 32, 26, height, 27, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+698), 0, 0, 20, 32, 3, height, 6, 0, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+699), 0, 0, 1, 32, 26, height, 27, 0, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+704), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 7, height, gTrackColours[SCHEME_SUPPORTS]);
        switch (direction) {
        case 2:
            paint_util_push_tunnel_right(height + 8, TUNNEL_6);
            break;
        case 3:
            paint_util_push_tunnel_left(height + 8, TUNNEL_6);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 7:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+700), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+683), 0, 0, 20, 32, 3, height, 6, 0, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+684), 0, 0, 1, 32, 26, height, 27, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+689), 0, 0, 1, 32, 26, height, 27, 0, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+694), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 1, height, gTrackColours[SCHEME_SUPPORTS]);
        switch (direction) {
        case 0:
            paint_util_push_tunnel_right(height, TUNNEL_6);
            break;
        case 1:
            paint_util_push_tunnel_left(height, TUNNEL_6);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 8:
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 9:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+701), 0, 0, 16, 32, 3, height, 16, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+685), 0, 0, 16, 32, 3, height, 0, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+690), 0, 0, 16, 32, 1, height, 0, 0, height + 27);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+695), 0, 0, 16, 32, 3, height, 16, 0, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 10:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+702), 0, 0, 16, 16, 3, height, 0, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+686), 0, 0, 16, 16, 3, height, 16, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+691), 0, 0, 16, 16, 1, height, 16, 16, height + 27);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+696), 0, 0, 16, 16, 3, height, 0, 16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 11:
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 12:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+703), 0, 0, 32, 16, 3, height, 0, 16, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+687), 0, 0, 32, 16, 3, height, 0, 16, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+692), 0, 0, 32, 16, 1, height, 0, 0, height + 27);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+697), 0, 0, 32, 16, 3, height, 0, 0, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 13:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+704), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+688), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+693), 0, 0, 32, 1, 26, height, 0, 27, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+698), 0, 0, 32, 20, 3, height, 0, 6, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+699), 0, 0, 32, 1, 26, height, 0, 27, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 7, height, gTrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height + 8, TUNNEL_6);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    }
}
static void hybrid_rc_track_right_half_banked_helix_up_large(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+705), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+710), 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+716), 0, 0, 32, 1, 26, height, 0, 27, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+721), 0, 0, 32, 20, 3, height, 0, 6, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+722), 0, 0, 32, 1, 26, height, 0, 27, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 1, height, gTrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 1:
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 2:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+706), 0, 0, 32, 16, 3, height, 0, 16, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+711), 0, 0, 32, 16, 3, height, 0, 16, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+717), 0, 0, 32, 16, 1, height, 0, 0, height + 27);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+723), 0, 0, 32, 16, 3, height, 0, 0, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+707), 0, 0, 16, 16, 3, height, 0, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+712), 0, 0, 16, 16, 3, height, 16, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+718), 0, 0, 16, 16, 1, height, 16, 16, height + 27);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+724), 0, 0, 16, 16, 3, height, 0, 16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 4:
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 5:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+708), 0, 0, 16, 32, 3, height, 16, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+713), 0, 0, 16, 32, 3, height, 0, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+719), 0, 0, 16, 32, 1, height, 0, 0, height + 27);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+725), 0, 0, 16, 32, 3, height, 16, 0, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 6:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+709), 0, 0, 20, 32, 3, height, 6, 0, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 7, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+714), 0, 0, 20, 32, 3, height, 6, 0, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+715), 0, 0, 1, 32, 26, height, 27, 0, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 3, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+720), 0, 0, 1, 32, 26, height, 27, 0, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 7, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+726), 0, 0, 20, 32, 3, height, 6, 0, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 7, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        }
        switch (direction) {
        case 0:
            paint_util_push_tunnel_right(height + 8, TUNNEL_6);
            break;
        case 1:
            paint_util_push_tunnel_left(height + 8, TUNNEL_6);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 7:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+710), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+716), 0, 0, 1, 32, 26, height, 27, 0, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+721), 0, 0, 20, 32, 3, height, 6, 0, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+722), 0, 0, 1, 32, 26, height, 27, 0, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+705), 0, 0, 20, 32, 3, height, 6, 0, height);
            break;
        }
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 1, height, gTrackColours[SCHEME_SUPPORTS]);
        switch (direction) {
        case 2:
            paint_util_push_tunnel_right(height, TUNNEL_6);
            break;
        case 3:
            paint_util_push_tunnel_left(height, TUNNEL_6);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 8:
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 9:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+711), 0, 0, 16, 32, 3, height, 16, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+717), 0, 0, 16, 32, 1, height, 0, 0, height + 27);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+723), 0, 0, 16, 32, 3, height, 0, 0, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+706), 0, 0, 16, 32, 3, height, 16, 0, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 10:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+712), 0, 0, 16, 16, 3, height, 0, 16, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+718), 0, 0, 16, 16, 1, height, 16, 16, height + 27);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+724), 0, 0, 16, 16, 3, height, 16, 0, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+707), 0, 0, 16, 16, 3, height, 0, 0, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 11:
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 12:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+713), 0, 0, 32, 16, 3, height, 0, 0, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+719), 0, 0, 32, 16, 1, height, 0, 0, height + 27);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+725), 0, 0, 32, 16, 3, height, 0, 16, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+708), 0, 0, 32, 16, 3, height, 0, 16, height);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    case 13:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+714), 0, 0, 32, 20, 3, height, 0, 6, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+715), 0, 0, 32, 1, 26, height, 0, 27, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 3, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+720), 0, 0, 32, 1, 26, height, 0, 27, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 7, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+726), 0, 0, 32, 20, 3, height, 0, 6, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 7, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | (SPR_G2_BEGIN+709), 0, 0, 32, 20, 3, height, 0, 6, height);
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 7, height, gTrackColours[SCHEME_SUPPORTS]);
            break;
        }
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height + 8, TUNNEL_6);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 32, 0x20);
        break;
    }
}
static void hybrid_rc_track_left_half_banked_helix_down_large(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    if (trackSequence >= 7) {
        trackSequence -= 7;
        direction = (direction - 1) & 3;
    }
    trackSequence = mapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence];
    hybrid_rc_track_right_half_banked_helix_up_large(rideIndex, trackSequence, (direction + 1) & 3, height, mapElement);
}
static void hybrid_rc_track_right_half_banked_helix_down_large(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    if (trackSequence >= 7) {
        trackSequence -= 7;
        direction = (direction + 1) & 3;
    }
    trackSequence = mapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence];
    hybrid_rc_track_left_half_banked_helix_up_large(rideIndex, trackSequence, (direction - 1) & 3, height, mapElement);
}


static void hybrid_rc_track_flat_to_60_deg_up_long_base(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        if (track_element_is_cable_lift(mapElement)) {
            switch (direction) {
            case 0:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18722, 0, 0, 32, 20, 3, height, 0, 6, height);
                break;
            case 1:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18726, 0, 0, 32, 20, 3, height, 0, 6, height);
                break;
            case 2:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18730, 0, 0, 32, 20, 3, height, 0, 6, height);
                break;
            case 3:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18734, 0, 0, 32, 20, 3, height, 0, 6, height);
                break;
            }
            if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
                metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 3, height, gTrackColours[SCHEME_SUPPORTS]);
            }
        } else {
            switch (direction) {
            case 0:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18660, 0, 0, 32, 20, 3, height, 0, 6, height);
                break;
            case 1:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18664, 0, 0, 32, 20, 3, height, 0, 6, height);
                break;
            case 2:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18668, 0, 0, 32, 20, 3, height, 0, 6, height);
                break;
            case 3:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18672, 0, 0, 32, 20, 3, height, 0, 6, height);
                break;
            }
            if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
                metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 3, height, gTrackColours[SCHEME_SUPPORTS]);
            }
        }
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 48, 0x20);
        break;
    case 1:
        if (track_element_is_cable_lift(mapElement)) {
            switch (direction) {
            case 0:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18723, 0, 0, 32, 20, 3, height, 0, 6, height);
                break;
            case 1:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18727, 0, 0, 32, 20, 3, height, 0, 6, height);
                break;
            case 2:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18731, 0, 0, 32, 20, 3, height, 0, 6, height);
                break;
            case 3:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18735, 0, 0, 32, 20, 3, height, 0, 6, height);
                break;
            }
            if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
                metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 5, height, gTrackColours[SCHEME_SUPPORTS]);
            }
        } else {
            switch (direction) {
            case 0:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18661, 0, 0, 32, 20, 3, height, 0, 6, height);
                break;
            case 1:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18665, 0, 0, 32, 20, 3, height, 0, 6, height);
                break;
            case 2:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18669, 0, 0, 32, 20, 3, height, 0, 6, height);
                break;
            case 3:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18673, 0, 0, 32, 20, 3, height, 0, 6, height);
                break;
            }
            if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
                metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 5, height, gTrackColours[SCHEME_SUPPORTS]);
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 48, 0x20);
        break;
    case 2:
        if (track_element_is_cable_lift(mapElement)) {
            switch (direction) {
            case 0:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18724, 0, 0, 32, 20, 3, height, 0, 6, height);
                break;
            case 1:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18728, 0, 0, 32, 20, 3, height, 0, 6, height);
                break;
            case 2:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18732, 0, 0, 32, 20, 3, height, 0, 6, height);
                break;
            case 3:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18736, 0, 0, 32, 20, 3, height, 0, 6, height);
                break;
            }
            if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
                metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 7, height, gTrackColours[SCHEME_SUPPORTS]);
            }
        } else {
            switch (direction) {
            case 0:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18662, 0, 0, 32, 20, 3, height, 0, 6, height);
                break;
            case 1:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18666, 0, 0, 32, 20, 3, height, 0, 6, height);
                break;
            case 2:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18670, 0, 0, 32, 20, 3, height, 0, 6, height);
                break;
            case 3:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18674, 0, 0, 32, 20, 3, height, 0, 6, height);
                break;
            }
            if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
                metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 7, height, gTrackColours[SCHEME_SUPPORTS]);
            }
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 64, 0x20);
        break;
    case 3:
        if (track_element_is_cable_lift(mapElement)) {
            switch (direction) {
            case 0:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18725, 0, 0, 32, 20, 3, height, 0, 6, height);
                break;
            case 1:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18729, 0, 0, 32, 1, 98, height, 0, 27, height);
                break;
            case 2:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18733, 0, 0, 32, 1, 98, height, 0, 27, height);
                break;
            case 3:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18737, 0, 0, 32, 20, 3, height, 0, 6, height);
                break;
            }
            if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
                metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 12, height, gTrackColours[SCHEME_SUPPORTS]);
            }
        } else {
            switch (direction) {
            case 0:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18663, 0, 0, 32, 20, 3, height, 0, 6, height);
                break;
            case 1:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18667, 0, 0, 32, 1, 98, height, 0, 27, height);
                break;
            case 2:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18671, 0, 0, 32, 1, 98, height, 0, 27, height);
                break;
            case 3:
                sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18675, 0, 0, 32, 20, 3, height, 0, 6, height);
                break;
            }
            if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
                metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 12, height, gTrackColours[SCHEME_SUPPORTS]);
            }
        }
        switch (direction) {
        case 1:
            paint_util_push_tunnel_right(height + 24, TUNNEL_8);
            break;
        case 2:
            paint_util_push_tunnel_left(height + 24, TUNNEL_8);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 80, 0x20);
        break;
    }
}
static void hybrid_rc_track_60_deg_up_to_flat_long_base(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18676, 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18680, 0, 0, 32, 1, 98, height, 0, 27, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18684, 0, 0, 32, 1, 98, height, 0, 27, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18688, 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 16, height, gTrackColours[SCHEME_SUPPORTS]);
        }
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height, TUNNEL_7);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 80, 0x20);
        break;
    case 1:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18677, 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18681, 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18685, 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18689, 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 12, height, gTrackColours[SCHEME_SUPPORTS]);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 80, 0x20);
        break;
    case 2:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18678, 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18682, 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18686, 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18690, 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 9, height, gTrackColours[SCHEME_SUPPORTS]);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 56, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18679, 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18683, 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18687, 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18691, 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 5, height, gTrackColours[SCHEME_SUPPORTS]);
        }
        switch (direction) {
        case 1:
            paint_util_push_tunnel_right(height + 8, TUNNEL_6);
            break;
        case 2:
            paint_util_push_tunnel_left(height + 8, TUNNEL_6);
            break;
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 40, 0x20);
        break;
    }
}
static void hybrid_rc_track_flat_to_60_deg_down_long_base(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_flat_to_60_deg_up_long_base(rideIndex, 3 - trackSequence, (direction + 2) & 3, height, mapElement);
}
static void hybrid_rc_track_60_deg_up_to_flat_long_base122(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    hybrid_rc_track_60_deg_up_to_flat_long_base(rideIndex, 3 - trackSequence, (direction + 2) & 3, height, mapElement);
}




/** rct2: 0x008ADA34 */
static void hybrid_rc_track_brakes(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (direction) {
    case 0:
    case 2:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18078, 0, 0, 32, 20, 3, height, 0, 6, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18082, 0, 0, 32, 1, 11, height, 0, 27, height + 5);
        break;
    case 1:
    case 3:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18079, 0, 0, 32, 20, 3, height, 0, 6, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18083, 0, 0, 32, 1, 11, height, 0, 27, height + 5);
        break;
    }
    if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 0, height, gTrackColours[SCHEME_SUPPORTS]);
    }
    paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 32, 0x20);
}

/** rct2: 0x008ADA44 */
static void hybrid_rc_track_on_ride_photo(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (direction) {
    case 0:
        sub_98196C_rotated(direction, 0x20000000 | 22432, 0, 0, 32, 32, 1, height);
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 5, 0, height, gTrackColours[SCHEME_SUPPORTS]);
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 8, 0, height, gTrackColours[SCHEME_SUPPORTS]);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18074, 0, 0, 32, 20, 0, height, 0, 6, height + 3);
        break;
    case 1:
        sub_98196C_rotated(direction, 0x20000000 | 22432, 0, 0, 32, 32, 1, height);
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 6, 0, height, gTrackColours[SCHEME_SUPPORTS]);
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 7, 0, height, gTrackColours[SCHEME_SUPPORTS]);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18075, 0, 0, 32, 20, 0, height, 0, 6, height + 3);
        break;
    case 2:
        sub_98196C_rotated(direction, 0x20000000 | 22432, 0, 0, 32, 32, 1, height);
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 5, 0, height, gTrackColours[SCHEME_SUPPORTS]);
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 8, 0, height, gTrackColours[SCHEME_SUPPORTS]);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18074, 0, 0, 32, 20, 0, height, 0, 6, height + 3);
        break;
    case 3:
        sub_98196C_rotated(direction, 0x20000000 | 22432, 0, 0, 32, 32, 1, height);
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 6, 0, height, gTrackColours[SCHEME_SUPPORTS]);
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 7, 0, height, gTrackColours[SCHEME_SUPPORTS]);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18075, 0, 0, 32, 20, 0, height, 0, 6, height + 3);
        break;
    }
    track_paint_util_onride_photo_paint(direction, height + 3, mapElement);
    paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
    paint_util_set_segment_support_height(SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(height + 48, 0x20);
}

/** rct2: 0x008ADF14 */
static void hybrid_rc_track_cable_lift_hill(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (trackSequence) {
    case 0:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18698, 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18699, 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18700, 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18701, 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 6, height, gTrackColours[SCHEME_SUPPORTS]);
        }
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_6);
        } else {
            paint_util_push_tunnel_rotated(direction, height + 8, TUNNEL_6);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 40, 0x20);
        break;
    case 1:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18700, 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18701, 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18698, 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18699, 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        }
        if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 6, height, gTrackColours[SCHEME_SUPPORTS]);
        }
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height + 8, TUNNEL_6);
        } else {
            paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_6);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 40, 0x20);
        break;
    case 2:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18714, 0, 0, 32, 20, 3, height, 0, 6, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18717, 0, 0, 32, 1, 66, height, 0, 27, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18715, 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18712, 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18713, 0, 0, 32, 20, 3, height, 0, 6, height);
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18716, 0, 0, 32, 1, 66, height, 0, 27, height);
            break;
        }
        if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 20, height, gTrackColours[SCHEME_SUPPORTS]);
        }
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height + 24, TUNNEL_8);
        } else {
            paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_7);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 72, 0x20);
        break;
    case 3:
        switch (direction) {
        case 0:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18720, 0, 0, 32, 1, 98, height, 0, 27, height);
            break;
        case 1:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18721, 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18718, 0, 0, 32, 20, 3, height, 0, 6, height);
            break;
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18719, 0, 0, 32, 1, 98, height, 0, 27, height);
            break;
        }
        if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
            metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 32, height, gTrackColours[SCHEME_SUPPORTS]);
        }
        if (direction == 0 || direction == 3) {
            paint_util_push_tunnel_rotated(direction, height + 56, TUNNEL_8);
        } else {
            paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_7);
        }
        paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        paint_util_set_general_support_height(height + 104, 0x20);
        break;
    }
}

/** rct2: 0x008ADB24 */
/** rct2: 0x008ADBC4 */
/** rct2: 0x008ADEC4 */
static void hybrid_rc_track_block_brakes(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    switch (direction) {
    case 0:
    case 2:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18076, 0, 0, 32, 20, 3, height, 0, 6, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18080, 0, 0, 32, 1, 11, height, 0, 27, height + 5);
        break;
    case 1:
    case 3:
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18077, 0, 0, 32, 20, 3, height, 0, 6, height);
        sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | 18081, 0, 0, 32, 1, 11, height, 0, 27, height + 5);
        break;
    }
    if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 0, height, gTrackColours[SCHEME_SUPPORTS]);
    }
    paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 32, 0x20);
}

static void hybrid_rc_track_booster(uint8 rideIndex, uint8 trackSequence, uint8 direction, sint32 height, rct_map_element * mapElement)
{
    // These offsets could be moved to the g2.dat file when that supports offsets.
    sint8 ne_sw_offsetX = 7;
    sint8 ne_sw_offsetY = -15;
    sint8 nw_se_offsetX = -15;
    sint8 nw_se_offsetY = 7;


    switch (direction) {
        case 0:
        case 2:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | SPR_G2_GIGA_RC_BOOSTER_NE_SW, ne_sw_offsetX, ne_sw_offsetY, 32, 20, 3, height, 0, 6, height);
            break;
        case 1:
        case 3:
            sub_98197C_rotated(direction, gTrackColours[SCHEME_TRACK] | SPR_G2_GIGA_RC_BOOSTER_NW_SE, nw_se_offsetX, nw_se_offsetY, 32, 20, 3, height, 0, 6, height);
            break;
    }
    if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
        metal_a_supports_paint_setup(METAL_SUPPORTS_TUBES, 4, 0, height, gTrackColours[SCHEME_SUPPORTS]);
    }
    paint_util_push_tunnel_rotated(direction, height, TUNNEL_6);
    paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(height + 32, 0x20);
}

TRACK_PAINT_FUNCTION get_track_paint_function_hybrid_rc(sint32 trackType, sint32 direction)
{
    switch (trackType) {
    case TRACK_ELEM_FLAT:
        return hybrid_rc_track_flat;
    case TRACK_ELEM_END_STATION:
    case TRACK_ELEM_BEGIN_STATION:
    case TRACK_ELEM_MIDDLE_STATION:
        return hybrid_rc_track_station;
    case TRACK_ELEM_25_DEG_UP:
        return hybrid_rc_track_25_deg_up;
    case TRACK_ELEM_60_DEG_UP:
        return hybrid_rc_track_60_deg_up;
    case TRACK_ELEM_FLAT_TO_25_DEG_UP:
        return hybrid_rc_track_flat_to_25_deg_up;
    case TRACK_ELEM_25_DEG_UP_TO_60_DEG_UP:
        return hybrid_rc_track_25_deg_up_to_60_deg_up;
    case TRACK_ELEM_60_DEG_UP_TO_25_DEG_UP:
        return hybrid_rc_track_60_deg_up_to_25_deg_up;
    case TRACK_ELEM_25_DEG_UP_TO_FLAT:
        return hybrid_rc_track_25_deg_up_to_flat;
    case TRACK_ELEM_25_DEG_DOWN:
        return hybrid_rc_track_25_deg_down;
    case TRACK_ELEM_60_DEG_DOWN:
        return hybrid_rc_track_60_deg_down;
    case TRACK_ELEM_FLAT_TO_25_DEG_DOWN:
        return hybrid_rc_track_flat_to_25_deg_down;
    case TRACK_ELEM_25_DEG_DOWN_TO_60_DEG_DOWN:
        return hybrid_rc_track_25_deg_down_to_60_deg_down;
    case TRACK_ELEM_60_DEG_DOWN_TO_25_DEG_DOWN:
        return hybrid_rc_track_60_deg_down_to_25_deg_down;
    case TRACK_ELEM_25_DEG_DOWN_TO_FLAT:
        return hybrid_rc_track_25_deg_down_to_flat;
    case TRACK_ELEM_LEFT_QUARTER_TURN_5_TILES:
        return hybrid_rc_track_left_quarter_turn_5;
    case TRACK_ELEM_RIGHT_QUARTER_TURN_5_TILES:
        return hybrid_rc_track_right_quarter_turn_5;
    case TRACK_ELEM_FLAT_TO_LEFT_BANK:
        return hybrid_rc_track_flat_to_left_bank;
    case TRACK_ELEM_FLAT_TO_RIGHT_BANK:
        return hybrid_rc_track_flat_to_right_bank;
    case TRACK_ELEM_LEFT_BANK_TO_FLAT:
        return hybrid_rc_track_left_bank_to_flat;
    case TRACK_ELEM_RIGHT_BANK_TO_FLAT:
        return hybrid_rc_track_right_bank_to_flat;
    case TRACK_ELEM_BANKED_LEFT_QUARTER_TURN_5_TILES:
        return hybrid_rc_track_banked_left_quarter_turn_5;
    case TRACK_ELEM_BANKED_RIGHT_QUARTER_TURN_5_TILES:
        return hybrid_rc_track_banked_right_quarter_turn_5;
    case TRACK_ELEM_LEFT_BANK_TO_25_DEG_UP:
        return hybrid_rc_track_left_bank_to_25_deg_up;
    case TRACK_ELEM_RIGHT_BANK_TO_25_DEG_UP:
        return hybrid_rc_track_right_bank_to_25_deg_up;
    case TRACK_ELEM_25_DEG_UP_TO_LEFT_BANK:
        return hybrid_rc_track_25_deg_up_to_left_bank;
    case TRACK_ELEM_25_DEG_UP_TO_RIGHT_BANK:
        return hybrid_rc_track_25_deg_up_to_right_bank;
    case TRACK_ELEM_LEFT_BANK_TO_25_DEG_DOWN:
        return hybrid_rc_track_left_bank_to_25_deg_down;
    case TRACK_ELEM_RIGHT_BANK_TO_25_DEG_DOWN:
        return hybrid_rc_track_right_bank_to_25_deg_down;
    case TRACK_ELEM_25_DEG_DOWN_TO_LEFT_BANK:
        return hybrid_rc_track_25_deg_down_to_left_bank;
    case TRACK_ELEM_25_DEG_DOWN_TO_RIGHT_BANK:
        return hybrid_rc_track_25_deg_down_to_right_bank;
    case TRACK_ELEM_LEFT_BANK:
        return hybrid_rc_track_left_bank;
    case TRACK_ELEM_RIGHT_BANK:
        return hybrid_rc_track_right_bank;
    case TRACK_ELEM_LEFT_QUARTER_TURN_5_TILES_25_DEG_UP:
        return hybrid_rc_track_left_quarter_turn_5_25_deg_up;
    case TRACK_ELEM_RIGHT_QUARTER_TURN_5_TILES_25_DEG_UP:
        return hybrid_rc_track_right_quarter_turn_5_25_deg_up;
    case TRACK_ELEM_LEFT_QUARTER_TURN_5_TILES_25_DEG_DOWN:
        return hybrid_rc_track_left_quarter_turn_5_25_deg_down;
    case TRACK_ELEM_RIGHT_QUARTER_TURN_5_TILES_25_DEG_DOWN:
        return hybrid_rc_track_right_quarter_turn_5_25_deg_down;
    case TRACK_ELEM_S_BEND_LEFT:
        return hybrid_rc_track_s_bend_left;
    case TRACK_ELEM_S_BEND_RIGHT:
        return hybrid_rc_track_s_bend_right;
    case TRACK_ELEM_LEFT_QUARTER_TURN_3_TILES:
        return hybrid_rc_track_left_quarter_turn_3;
    case TRACK_ELEM_RIGHT_QUARTER_TURN_3_TILES:
        return hybrid_rc_track_right_quarter_turn_3;
    case TRACK_ELEM_LEFT_QUARTER_TURN_3_TILES_BANK:
        return hybrid_rc_track_left_quarter_turn_3_bank;
    case TRACK_ELEM_RIGHT_QUARTER_TURN_3_TILES_BANK:
        return hybrid_rc_track_right_quarter_turn_3_bank;
    case TRACK_ELEM_LEFT_QUARTER_TURN_3_TILES_25_DEG_UP:
        return hybrid_rc_track_left_quarter_turn_3_25_deg_up;
    case TRACK_ELEM_RIGHT_QUARTER_TURN_3_TILES_25_DEG_UP:
        return hybrid_rc_track_right_quarter_turn_3_25_deg_up;
    case TRACK_ELEM_LEFT_QUARTER_TURN_3_TILES_25_DEG_DOWN:
        return hybrid_rc_track_left_quarter_turn_3_25_deg_down;
    case TRACK_ELEM_RIGHT_QUARTER_TURN_3_TILES_25_DEG_DOWN:
        return hybrid_rc_track_right_quarter_turn_3_25_deg_down;
    case TRACK_ELEM_LEFT_HALF_BANKED_HELIX_UP_SMALL:
        return hybrid_rc_track_left_half_banked_helix_up_small;
    case TRACK_ELEM_RIGHT_HALF_BANKED_HELIX_UP_SMALL:
        return hybrid_rc_track_right_half_banked_helix_up_small;
    case TRACK_ELEM_LEFT_HALF_BANKED_HELIX_DOWN_SMALL:
        return hybrid_rc_track_left_half_banked_helix_down_small;
    case TRACK_ELEM_RIGHT_HALF_BANKED_HELIX_DOWN_SMALL:
        return hybrid_rc_track_right_half_banked_helix_down_small;
    case TRACK_ELEM_LEFT_HALF_BANKED_HELIX_UP_LARGE:
        return hybrid_rc_track_left_half_banked_helix_up_large;
    case TRACK_ELEM_RIGHT_HALF_BANKED_HELIX_UP_LARGE:
        return hybrid_rc_track_right_half_banked_helix_up_large;
    case TRACK_ELEM_LEFT_HALF_BANKED_HELIX_DOWN_LARGE:
        return hybrid_rc_track_left_half_banked_helix_down_large;
    case TRACK_ELEM_RIGHT_HALF_BANKED_HELIX_DOWN_LARGE:
        return hybrid_rc_track_right_half_banked_helix_down_large;
    case TRACK_ELEM_LEFT_QUARTER_TURN_1_TILE_60_DEG_UP:
        return hybrid_rc_track_left_quarter_turn_1_60_deg_up;
    case TRACK_ELEM_RIGHT_QUARTER_TURN_1_TILE_60_DEG_UP:
        return hybrid_rc_track_right_quarter_turn_1_60_deg_up;
    case TRACK_ELEM_LEFT_QUARTER_TURN_1_TILE_60_DEG_DOWN:
        return hybrid_rc_track_left_quarter_turn_1_60_deg_down;
    case TRACK_ELEM_RIGHT_QUARTER_TURN_1_TILE_60_DEG_DOWN:
        return hybrid_rc_track_right_quarter_turn_1_60_deg_down;
    case TRACK_ELEM_BRAKES:
        return hybrid_rc_track_brakes;
    case TRACK_ELEM_25_DEG_UP_LEFT_BANKED:
        return hybrid_rc_track_25_deg_up_left_banked;
    case TRACK_ELEM_25_DEG_UP_RIGHT_BANKED:
        return hybrid_rc_track_25_deg_up_right_banked;
    case TRACK_ELEM_ON_RIDE_PHOTO:
        return hybrid_rc_track_on_ride_photo;
    case TRACK_ELEM_25_DEG_DOWN_LEFT_BANKED:
        return hybrid_rc_track_25_deg_down_left_banked;
    case TRACK_ELEM_25_DEG_DOWN_RIGHT_BANKED:
        return hybrid_rc_track_25_deg_down_right_banked;
    case TRACK_ELEM_90_DEG_UP:
        return hybrid_rc_track_90_deg_up;
    case TRACK_ELEM_90_DEG_DOWN:
        return hybrid_rc_track_90_deg_down;
    case TRACK_ELEM_60_DEG_UP_TO_90_DEG_UP:
        return hybrid_rc_track_60_deg_up_to_90_deg_up;
    case TRACK_ELEM_90_DEG_DOWN_TO_60_DEG_DOWN:
        return hybrid_rc_track_90_deg_down_to_60_deg_down;
    case TRACK_ELEM_90_DEG_UP_TO_60_DEG_UP:
        return hybrid_rc_track_90_deg_up_to_60_deg_up;
    case TRACK_ELEM_60_DEG_DOWN_TO_90_DEG_DOWN:
        return hybrid_rc_track_60_deg_down_to_90_deg_down;
    case TRACK_ELEM_FLAT_TO_60_DEG_UP_LONG_BASE:
        return hybrid_rc_track_flat_to_60_deg_up_long_base;
    case TRACK_ELEM_60_DEG_UP_TO_FLAT_LONG_BASE:
        return hybrid_rc_track_60_deg_up_to_flat_long_base;
    case TRACK_ELEM_FLAT_TO_60_DEG_DOWN_LONG_BASE:
        return hybrid_rc_track_flat_to_60_deg_down_long_base;
    case TRACK_ELEM_60_DEG_UP_TO_FLAT_LONG_BASE_122:
        return hybrid_rc_track_60_deg_up_to_flat_long_base122;
    case TRACK_ELEM_CABLE_LIFT_HILL:
        return hybrid_rc_track_cable_lift_hill;
    case TRACK_ELEM_LEFT_EIGHTH_TO_DIAG:
        return hybrid_rc_track_left_eighth_to_diag;
    case TRACK_ELEM_RIGHT_EIGHTH_TO_DIAG:
        return hybrid_rc_track_right_eighth_to_diag;
    case TRACK_ELEM_LEFT_EIGHTH_TO_ORTHOGONAL:
        return hybrid_rc_track_left_eighth_to_orthogonal;
    case TRACK_ELEM_RIGHT_EIGHTH_TO_ORTHOGONAL:
        return hybrid_rc_track_right_eighth_to_orthogonal;
    case TRACK_ELEM_LEFT_EIGHTH_BANK_TO_DIAG:
        return hybrid_rc_track_left_eighth_bank_to_diag;
    case TRACK_ELEM_RIGHT_EIGHTH_BANK_TO_DIAG:
        return hybrid_rc_track_right_eighth_bank_to_diag;
    case TRACK_ELEM_LEFT_EIGHTH_BANK_TO_ORTHOGONAL:
        return hybrid_rc_track_left_eighth_bank_to_orthogonal;
    case TRACK_ELEM_RIGHT_EIGHTH_BANK_TO_ORTHOGONAL:
        return hybrid_rc_track_right_eighth_bank_to_orthogonal;
    case TRACK_ELEM_DIAG_FLAT:
        return hybrid_rc_track_diag_flat;
    case TRACK_ELEM_DIAG_25_DEG_UP:
        return hybrid_rc_track_diag_25_deg_up;
    case TRACK_ELEM_DIAG_60_DEG_UP:
        return hybrid_rc_track_diag_60_deg_up;
    case TRACK_ELEM_DIAG_FLAT_TO_25_DEG_UP:
        return hybrid_rc_track_diag_flat_to_25_deg_up;
    case TRACK_ELEM_DIAG_25_DEG_UP_TO_60_DEG_UP:
        return hybrid_rc_track_diag_25_deg_up_to_60_deg_up;
    case TRACK_ELEM_DIAG_60_DEG_UP_TO_25_DEG_UP:
        return hybrid_rc_track_diag_60_deg_up_to_25_deg_up;
    case TRACK_ELEM_DIAG_25_DEG_UP_TO_FLAT:
        return hybrid_rc_track_diag_25_deg_up_to_flat;
    case TRACK_ELEM_DIAG_25_DEG_DOWN:
        return hybrid_rc_track_diag_25_deg_down;
    case TRACK_ELEM_DIAG_60_DEG_DOWN:
        return hybrid_rc_track_diag_60_deg_down;
    case TRACK_ELEM_DIAG_FLAT_TO_25_DEG_DOWN:
        return hybrid_rc_track_diag_flat_to_25_deg_down;
    case TRACK_ELEM_DIAG_25_DEG_DOWN_TO_60_DEG_DOWN:
        return hybrid_rc_track_diag_25_deg_down_to_60_deg_down;
    case TRACK_ELEM_DIAG_60_DEG_DOWN_TO_25_DEG_DOWN:
        return hybrid_rc_track_diag_60_deg_down_to_25_deg_down;
    case TRACK_ELEM_DIAG_25_DEG_DOWN_TO_FLAT:
        return hybrid_rc_track_diag_25_deg_down_to_flat;
    case TRACK_ELEM_DIAG_FLAT_TO_LEFT_BANK:
        return hybrid_rc_track_diag_flat_to_left_bank;
    case TRACK_ELEM_DIAG_FLAT_TO_RIGHT_BANK:
        return hybrid_rc_track_diag_flat_to_right_bank;
    case TRACK_ELEM_DIAG_LEFT_BANK_TO_FLAT:
        return hybrid_rc_track_diag_left_bank_to_flat;
    case TRACK_ELEM_DIAG_RIGHT_BANK_TO_FLAT:
        return hybrid_rc_track_diag_right_bank_to_flat;
    case TRACK_ELEM_DIAG_LEFT_BANK_TO_25_DEG_UP:
        return hybrid_rc_track_diag_left_bank_to_25_deg_up;
    case TRACK_ELEM_DIAG_RIGHT_BANK_TO_25_DEG_UP:
        return hybrid_rc_track_diag_right_bank_to_25_deg_up;
    case TRACK_ELEM_DIAG_25_DEG_UP_TO_LEFT_BANK:
        return hybrid_rc_track_diag_25_deg_up_to_left_bank;
    case TRACK_ELEM_DIAG_25_DEG_UP_TO_RIGHT_BANK:
        return hybrid_rc_track_diag_25_deg_up_to_right_bank;
    case TRACK_ELEM_DIAG_LEFT_BANK_TO_25_DEG_DOWN:
        return hybrid_rc_track_diag_left_bank_to_25_deg_down;
    case TRACK_ELEM_DIAG_RIGHT_BANK_TO_25_DEG_DOWN:
        return hybrid_rc_track_diag_right_bank_to_25_deg_down;
    case TRACK_ELEM_DIAG_25_DEG_DOWN_TO_LEFT_BANK:
        return hybrid_rc_track_diag_25_deg_down_to_left_bank;
    case TRACK_ELEM_DIAG_25_DEG_DOWN_TO_RIGHT_BANK:
        return hybrid_rc_track_diag_25_deg_down_to_right_bank;
    case TRACK_ELEM_DIAG_LEFT_BANK:
        return hybrid_rc_track_diag_left_bank;
    case TRACK_ELEM_DIAG_RIGHT_BANK:
        return hybrid_rc_track_diag_right_bank;
    case TRACK_ELEM_BLOCK_BRAKES:
        return hybrid_rc_track_block_brakes;
    case TRACK_ELEM_LEFT_BANKED_QUARTER_TURN_3_TILE_25_DEG_UP:
        return hybrid_rc_track_left_banked_quarter_turn_3_25_deg_up;
    case TRACK_ELEM_RIGHT_BANKED_QUARTER_TURN_3_TILE_25_DEG_UP:
        return hybrid_rc_track_right_banked_quarter_turn_3_25_deg_up;
    case TRACK_ELEM_LEFT_BANKED_QUARTER_TURN_3_TILE_25_DEG_DOWN:
        return hybrid_rc_track_left_banked_quarter_turn_3_25_deg_down;
    case TRACK_ELEM_RIGHT_BANKED_QUARTER_TURN_3_TILE_25_DEG_DOWN:
        return hybrid_rc_track_right_banked_quarter_turn_3_25_deg_down;
    case TRACK_ELEM_LEFT_BANKED_QUARTER_TURN_5_TILE_25_DEG_UP:
        return hybrid_rc_track_left_banked_quarter_turn_5_25_deg_up;
    case TRACK_ELEM_RIGHT_BANKED_QUARTER_TURN_5_TILE_25_DEG_UP:
        return hybrid_rc_track_right_banked_quarter_turn_5_25_deg_up;
    case TRACK_ELEM_LEFT_BANKED_QUARTER_TURN_5_TILE_25_DEG_DOWN:
        return hybrid_rc_track_left_banked_quarter_turn_5_25_deg_down;
    case TRACK_ELEM_RIGHT_BANKED_QUARTER_TURN_5_TILE_25_DEG_DOWN:
        return hybrid_rc_track_right_banked_quarter_turn_5_25_deg_down;
    case TRACK_ELEM_25_DEG_UP_TO_LEFT_BANKED_25_DEG_UP:
        return hybrid_rc_track_25_deg_up_to_left_banked_25_deg_up;
    case TRACK_ELEM_25_DEG_UP_TO_RIGHT_BANKED_25_DEG_UP:
        return hybrid_rc_track_25_deg_up_to_right_banked_25_deg_up;
    case TRACK_ELEM_LEFT_BANKED_25_DEG_UP_TO_25_DEG_UP:
        return hybrid_rc_track_left_banked_25_deg_up_to_25_deg_up;
    case TRACK_ELEM_RIGHT_BANKED_25_DEG_UP_TO_25_DEG_UP:
        return hybrid_rc_track_right_banked_25_deg_up_to_25_deg_up;
    case TRACK_ELEM_25_DEG_DOWN_TO_LEFT_BANKED_25_DEG_DOWN:
        return hybrid_rc_track_25_deg_down_to_left_banked_25_deg_down;
    case TRACK_ELEM_25_DEG_DOWN_TO_RIGHT_BANKED_25_DEG_DOWN:
        return hybrid_rc_track_25_deg_down_to_right_banked_25_deg_down;
    case TRACK_ELEM_LEFT_BANKED_25_DEG_DOWN_TO_25_DEG_DOWN:
        return hybrid_rc_track_left_banked_25_deg_down_to_25_deg_down;
    case TRACK_ELEM_RIGHT_BANKED_25_DEG_DOWN_TO_25_DEG_DOWN:
        return hybrid_rc_track_right_banked_25_deg_down_to_25_deg_down;
    case TRACK_ELEM_LEFT_BANKED_FLAT_TO_LEFT_BANKED_25_DEG_UP:
        return hybrid_rc_track_left_banked_flat_to_left_banked_25_deg_up;
    case TRACK_ELEM_RIGHT_BANKED_FLAT_TO_RIGHT_BANKED_25_DEG_UP:
        return hybrid_rc_track_right_banked_flat_to_right_banked_25_deg_up;
    case TRACK_ELEM_LEFT_BANKED_25_DEG_UP_TO_LEFT_BANKED_FLAT:
        return hybrid_rc_track_left_banked_25_deg_up_to_left_banked_flat;
    case TRACK_ELEM_RIGHT_BANKED_25_DEG_UP_TO_RIGHT_BANKED_FLAT:
        return hybrid_rc_track_right_banked_25_deg_up_to_right_banked_flat;
    case TRACK_ELEM_LEFT_BANKED_FLAT_TO_LEFT_BANKED_25_DEG_DOWN:
        return hybrid_rc_track_left_banked_flat_to_left_banked_25_deg_down;
    case TRACK_ELEM_RIGHT_BANKED_FLAT_TO_RIGHT_BANKED_25_DEG_DOWN:
        return hybrid_rc_track_right_banked_flat_to_right_banked_25_deg_down;
    case TRACK_ELEM_LEFT_BANKED_25_DEG_DOWN_TO_LEFT_BANKED_FLAT:
        return hybrid_rc_track_left_banked_25_deg_down_to_left_banked_flat;
    case TRACK_ELEM_RIGHT_BANKED_25_DEG_DOWN_TO_RIGHT_BANKED_FLAT:
        return hybrid_rc_track_right_banked_25_deg_down_to_right_banked_flat;
    case TRACK_ELEM_FLAT_TO_LEFT_BANKED_25_DEG_UP:
        return hybrid_rc_track_flat_to_left_banked_25_deg_up;
    case TRACK_ELEM_FLAT_TO_RIGHT_BANKED_25_DEG_UP:
        return hybrid_rc_track_flat_to_right_banked_25_deg_up;
    case TRACK_ELEM_LEFT_BANKED_25_DEG_UP_TO_FLAT:
        return hybrid_rc_track_left_banked_25_deg_up_to_flat;
    case TRACK_ELEM_RIGHT_BANKED_25_DEG_UP_TO_FLAT:
        return hybrid_rc_track_right_banked_25_deg_up_to_flat;
    case TRACK_ELEM_FLAT_TO_LEFT_BANKED_25_DEG_DOWN:
        return hybrid_rc_track_flat_to_left_banked_25_deg_down;
    case TRACK_ELEM_FLAT_TO_RIGHT_BANKED_25_DEG_DOWN:
        return hybrid_rc_track_flat_to_right_banked_25_deg_down;
    case TRACK_ELEM_LEFT_BANKED_25_DEG_DOWN_TO_FLAT:
        return hybrid_rc_track_left_banked_25_deg_down_to_flat;
    case TRACK_ELEM_RIGHT_BANKED_25_DEG_DOWN_TO_FLAT:
        return hybrid_rc_track_right_banked_25_deg_down_to_flat;
    case TRACK_ELEM_LEFT_QUARTER_TURN_1_TILE_90_DEG_UP:
        return hybrid_rc_track_left_quarter_turn_1_90_deg_up;
    case TRACK_ELEM_RIGHT_QUARTER_TURN_1_TILE_90_DEG_UP:
        return hybrid_rc_track_right_quarter_turn_1_90_deg_up;
    case TRACK_ELEM_LEFT_QUARTER_TURN_1_TILE_90_DEG_DOWN:
        return hybrid_rc_track_left_quarter_turn_1_90_deg_down;
    case TRACK_ELEM_RIGHT_QUARTER_TURN_1_TILE_90_DEG_DOWN:
        return hybrid_rc_track_right_quarter_turn_1_90_deg_down;
    case TRACK_ELEM_BOOSTER:
        return hybrid_rc_track_booster;
    }
    return NULL;
}
