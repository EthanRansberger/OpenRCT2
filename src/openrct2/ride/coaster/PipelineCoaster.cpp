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


#include "../../drawing/Drawing.h"
#include "../../interface/Viewport.h"
#include "../../paint/Paint.h"
#include "../../paint/Supports.h"
#include "../../sprites.h"
#include "../../world/Map.h"
#include "../RideData.h"
#include "../TrackData.h"
#include "../TrackPaint.h"

namespace PipelineRC
{

static void TrackFlat(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,                               const TrackElement& trackElement)
{
    
    if (trackElement.AsTrack()->HasChain())
    {
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_FLAT+0),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_FLAT+1),{0,0,height},{32,1,26},{0,27,height});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_FLAT+2),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_FLAT+3),{0,0,height},{32,1,26},{0,27,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_FLAT+4),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_FLAT+5),{0,0,height},{32,1,26},{0,27,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_FLAT+6),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_FLAT+7),{0,0,height},{32,1,26},{0,27,height});
            break;
        }
        if (track_paint_util_should_paint_supports(session.MapPosition))
        {
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
        }
    }
    else
    {
        switch (direction)
        {
        case 0:
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT+0),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT+1),{0,0,height},{32,1,26},{0,27,height});
            break;
        case 1:
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT+2),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT+3),{0,0,height},{32,1,26},{0,27,height});
            break;
        }
        if (track_paint_util_should_paint_supports(session.MapPosition))
        {
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
        }
    }
    PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
}

static void TrackStation(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,                                  const TrackElement& trackElement)
{
    static constexpr const uint32_t imageIds[4][3] = {
        { (SPR_G2_PIPELINE_TRACK_BRAKE + 0), (SPR_G2_PIPELINE_TRACK_BLOCK_BRAKE + 0), SPR_STATION_BASE_B_SW_NE },        { (SPR_G2_PIPELINE_TRACK_BRAKE + 2), (SPR_G2_PIPELINE_TRACK_BLOCK_BRAKE + 2), SPR_STATION_BASE_B_NW_SE },        { (SPR_G2_PIPELINE_TRACK_BRAKE + 0), (SPR_G2_PIPELINE_TRACK_BLOCK_BRAKE + 0), SPR_STATION_BASE_B_SW_NE },        { (SPR_G2_PIPELINE_TRACK_BRAKE + 2), (SPR_G2_PIPELINE_TRACK_BLOCK_BRAKE + 2), SPR_STATION_BASE_B_NW_SE },    };

    if (trackElement.AsTrack()->GetTrackType() == TrackElemType::EndStation)
    {
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(imageIds[direction][1]),{0,0,height},{32,20,1},{0,6,height+3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(imageIds[direction][1]+1),{0,0,height},{32,1,26},{0,27,height+3});
    }
    else
    {
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(imageIds[direction][0]),{0,0,height},{32,20,1},{0,6,height+3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(imageIds[direction][0]+1),{0,0,height},{32,1,26},{0,27,height+3});
    }
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_MISC].WithIndex(imageIds[direction][2]),{0,0,height-2},{32,28,2},{0,2,height});
    track_paint_util_draw_station_metal_supports_2(session, direction, height, session.TrackColours[SCHEME_SUPPORTS], 0);
    //track_paint_util_draw_station_2(session, ride, direction, height, trackElement,4,7);
    PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    PaintUtilSetSegmentSupportHeight(session, SEGMENTS_ALL, 0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
}


static void TrackUp25(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                    int32_t height, const TrackElement& trackElement)
{
    if (trackElement.AsTrack()->HasChain())
    {
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE+16),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE+17),{0,0,height},{32,1,50},{0,27,height});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE+18),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE+19),{0,0,height},{32,1,50},{0,27,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE+20),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE+21),{0,0,height},{32,1,50},{0,27,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE+22),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE+23),{0,0,height},{32,1,50},{0,27,height});
            break;
        }
        if (track_paint_util_should_paint_supports(session.MapPosition))
        {
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
        }
    }
    else
    {
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE+16),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE+17),{0,0,height},{32,1,50},{0,27,height});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE+18),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE+19),{0,0,height},{32,1,50},{0,27,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE+20),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE+21),{0,0,height},{32,1,50},{0,27,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE+22),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE+23),{0,0,height},{32,1,50},{0,27,height});
            break;
        }
        if (track_paint_util_should_paint_supports(session.MapPosition))
        {
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
        }
    }
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height - 8, TUNNEL_SQUARE_7);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height + 8, TUNNEL_SQUARE_8);
    }
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
}


static void TrackUp60(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                    int32_t height, const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP+16),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP+17),{0,0,height},{32,1,50},{0,27,height});
        break;
    case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP+18),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP+19),{0,0,height},{32,1,50},{0,27,height});
        break;
    case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP+20),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP+21),{0,0,height},{32,1,50},{0,27,height});
        break;
    case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP+22),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP+23),{0,0,height},{32,1,50},{0,27,height});
        break;
    }
    if (track_paint_util_should_paint_supports(session.MapPosition))
    {
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 32, height, session.TrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height - 8, TUNNEL_SQUARE_7);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height + 56, TUNNEL_SQUARE_8);
    }
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 104, 0x20);
}

static void TrackFlatToUp25(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                            int32_t height, const TrackElement& trackElement)
{
    if (trackElement.AsTrack()->HasChain())
    {
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE+0),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE+1),{0,0,height},{32,1,42},{0,27,height});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE+2),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE+3),{0,0,height},{32,1,42},{0,27,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE+4),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE+5),{0,0,height},{32,1,42},{0,27,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE+6),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE+7),{0,0,height},{32,1,42},{0,27,height});
            break;
        }
        if (track_paint_util_should_paint_supports(session.MapPosition))
        {
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 3, height, session.TrackColours[SCHEME_SUPPORTS]);
        }
    }
    else
    {
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE+0),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE+1),{0,0,height},{32,1,42},{0,27,height});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE+2),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE+3),{0,0,height},{32,1,42},{0,27,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE+4),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE+5),{0,0,height},{32,1,42},{0,27,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE+6),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE+7),{0,0,height},{32,1,42},{0,27,height});
            break;
        }
        if (track_paint_util_should_paint_supports(session.MapPosition))
        {
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 3, height, session.TrackColours[SCHEME_SUPPORTS]);
        }
    }
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_8);
    }
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
}

static void TrackUp25ToUp60(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                                 int32_t height, const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP+0),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP+1),{0,0,height},{32,1,50},{0,27,height});
        break;
    case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP+2),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP+3),{0,0,height},{32,1,66},{0,27,height});
        break;
    case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP+4),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP+5),{0,0,height},{32,1,66},{0,27,height});
        break;
    case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP+6),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP+7),{0,0,height},{32,1,50},{0,27,height});
        break;
    }
    if (track_paint_util_should_paint_supports(session.MapPosition))
    {
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 12, height, session.TrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height - 8, TUNNEL_SQUARE_7);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height + 24, TUNNEL_SQUARE_8);
    }
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
}

static void TrackUp60ToUp25(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                                 int32_t height, const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP+8),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP+9),{0,0,height},{32,1,50},{0,27,height});
        break;
    case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP+10),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP+11),{0,0,height},{32,1,66},{0,27,height});
        break;
    case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP+12),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP+13),{0,0,height},{32,1,66},{0,27,height});
        break;
    case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP+14),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP+15),{0,0,height},{32,1,50},{0,27,height});
        break;
    }
    if (track_paint_util_should_paint_supports(session.MapPosition))
    {
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 20, height, session.TrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height - 8, TUNNEL_SQUARE_7);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height + 24, TUNNEL_SQUARE_8);
    }
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
}

static void TrackUp25ToFlat(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                            int32_t height, const TrackElement& trackElement)
{
    if (trackElement.AsTrack()->HasChain())
    {
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE+8),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE+9),{0,0,height},{32,1,42},{0,27,height});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE+10),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE+11),{0,0,height},{32,1,42},{0,27,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE+12),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE+13),{0,0,height},{32,1,42},{0,27,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE+14),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE+15),{0,0,height},{32,1,42},{0,27,height});
            break;
        }
        if (track_paint_util_should_paint_supports(session.MapPosition))
        {
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 6, height, session.TrackColours[SCHEME_SUPPORTS]);
        }
    }
    else
    {
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE+8),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE+9),{0,0,height},{32,1,42},{0,27,height});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE+10),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE+11),{0,0,height},{32,1,42},{0,27,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE+12),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE+13),{0,0,height},{32,1,42},{0,27,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE+14),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE+15),{0,0,height},{32,1,42},{0,27,height});
            break;
        }
        if (track_paint_util_should_paint_supports(session.MapPosition))
        {
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 6, height, session.TrackColours[SCHEME_SUPPORTS]);
        }
    }
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height - 8, TUNNEL_SQUARE_FLAT);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height + 8, TUNNEL_14);
    }
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 40, 0x20);
}

static void TrackDown25(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                      int32_t height, const TrackElement& trackElement)
{
    TrackUp25(session, ride, trackSequence, (direction + 2) & 3, height, trackElement);
}

static void TrackDown60(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                      int32_t height, const TrackElement& trackElement)
{
    TrackUp60(session, ride, trackSequence, (direction + 2) & 3, height, trackElement);
}

static void TrackFlatToDown25(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                              int32_t height, const TrackElement& trackElement)
{
    TrackUp25ToFlat(session, ride, trackSequence, (direction + 2) & 3, height, trackElement);
}

static void TrackDown25ToDown60(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                     uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    TrackUp60ToUp25(session, ride, trackSequence, (direction + 2) & 3, height, trackElement);
}

static void TrackDown60ToDown25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                     uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    TrackUp25ToUp60(session, ride, trackSequence, (direction + 2) & 3, height, trackElement);
}

static void TrackDown25ToFlat(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                              int32_t height, const TrackElement& trackElement)
{
    TrackFlatToUp25(session, ride, trackSequence, (direction + 2) & 3, height, trackElement);
}


static void TrackLeftQuarterTurn3(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                              int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE+0),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE+1),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE+6),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE+7),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE+12),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE+13),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE+18),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE+19),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 1:
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE+2),{0,0,height},{16,16,3},{16,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE+3),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE+8),{0,0,height},{16,16,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE+9),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE+14),{0,0,height},{16,16,3},{0,16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE+15),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE+20),{0,0,height},{16,16,3},{16,16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE+21),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 3:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE+4),{0,0,height},{20,32,3},{6,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE+5),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE+10),{0,0,height},{20,32,3},{6,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE+11),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE+16),{0,0,height},{20,32,3},{6,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE+17),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE+22),{0,0,height},{20,32,3},{6,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE+23),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
        switch (direction)
        {
        case 2:
            PaintUtilPushTunnelRight(session, height, TUNNEL_SQUARE_FLAT);
            break;
        case 3:
            PaintUtilPushTunnelLeft(session, height, TUNNEL_SQUARE_FLAT);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    }
}

static void TrackRightQuarterTurn3(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                               int32_t height, const TrackElement& trackElement)
{
    trackSequence = mapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence];
    TrackLeftQuarterTurn3(session, ride, trackSequence, (direction - 1) & 3, height, trackElement);
}

static void TrackLeftQuarterTurn5(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                              int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+0),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+1),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+10),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+11),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+20),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+21),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+30),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+31),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
        }
	PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 1:
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+2),{0,0,height},{32,16,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+3),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+12),{0,0,height},{32,16,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+13),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+22),{0,0,height},{32,16,3},{0,16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+23),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+32),{0,0,height},{32,16,3},{0,16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+33),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session,            PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 3:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+4),{0,0,height},{16,16,3},{0,16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+5),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+14),{0,0,height},{16,16,3},{16,16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+15),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+24),{0,0,height},{16,16,3},{16,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+25),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+34),{0,0,height},{16,16,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+35),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 4:
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 5:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+6),{0,0,height},{16,32,3},{16,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+7),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+16),{0,0,height},{16,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+17),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+26),{0,0,height},{16,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+27),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+36),{0,0,height},{16,32,3},{16,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+37),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session,            PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 6:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+8),{0,0,height},{20,32,3},{6,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+9),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+18),{0,0,height},{20,32,3},{6,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+19),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+28),{0,0,height},{20,32,3},{6,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+29),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+38),{0,0,height},{20,32,3},{6,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE+39),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
        switch (direction)
        {
        case 2:
            PaintUtilPushTunnelRight(session, height, TUNNEL_SQUARE_FLAT);
            break;
        case 3:
            PaintUtilPushTunnelLeft(session, height, TUNNEL_SQUARE_FLAT);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    }
}

static void TrackRightQuarterTurn5(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                               int32_t height, const TrackElement& trackElement)
{
    trackSequence = mapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence];
    TrackLeftQuarterTurn5(session, ride, trackSequence, (direction - 1) & 3, height, trackElement);
}

static void TrackLeftEighthTodiag(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                              int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+0),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+1),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+8),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+9),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+16),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+17),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+24),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+25),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 1:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+2),{0,0,height},{32,16,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+3),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+10),{0,0,height},{34,16,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+11),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+18),{0,0,height},{32,16,3},{0,16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+19),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+26),{0,0,height},{32,16,3},{0,16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+27),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session,            PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+4),{0,0,height},{16,16,3},{0,16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+5),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+12),{0,0,height},{16,16,3},{16,16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+13),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+20),{0,0,height},{16,16,3},{16,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+21),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+28),{0,0,height},{16,16,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+29),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 3:
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 4:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+6),{0,0,height},{16,16,3},{16,16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+7),{0,0,height},{32,20,0},{0,6,height+27});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+14),{0,0,height},{16,18,3},{0,16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+15),{0,0,height},{32,20,0},{0,6,height+27});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+22),{0,0,height},{16,16,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+23),{0,0,height},{32,20,0},{0,6,height+27});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+30),{0,0,height},{16,16,3},{16,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+31),{0,0,height},{32,20,0},{0,6,height+27});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session,            PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    }
}

static void TrackRightEighthTodiag(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                               int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+32),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+33),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+40),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+41),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+48),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+49),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+56),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+57),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 1:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+34),{0,0,height},{32,16,3},{0,16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+35),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+42),{0,0,height},{32,16,3},{0,16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+43),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+50),{0,0,height},{34,16,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+51),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+58),{0,0,height},{32,16,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+59),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session,            PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+36),{0,0,height},{16,16,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+37),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+44),{0,0,height},{16,16,3},{16,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+45),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+52),{0,0,height},{28,28,3},{4,4,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+53),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+60),{0,0,height},{16,16,3},{0,16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+61),{0,0,height},{32,20,0},{0,6,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 3:
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 4:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+38),{0,0,height},{16,16,3},{16,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+39),{0,0,height},{32,20,0},{0,6,height+27});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+46),{0,0,height},{16,16,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+47),{0,0,height},{32,20,0},{0,6,height+27});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+54),{0,0,height},{16,18,3},{0,16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+55),{0,0,height},{32,20,0},{0,6,height+27});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+62),{0,0,height},{16,16,3},{16,16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE+63),{0,0,height},{32,20,0},{0,6,height+27});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session,            PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    }
}

static void TrackLeftEighthToOrthogonal(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                    uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    trackSequence = mapLeftEighthTurnToOrthogonal[trackSequence];
    TrackRightEighthTodiag(session, ride, trackSequence, (direction + 2) & 3, height, trackElement);
}

static void TrackRightEighthToOrthogonal(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                     uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    trackSequence = mapLeftEighthTurnToOrthogonal[trackSequence];
    TrackLeftEighthTodiag(session, ride, trackSequence, (direction + 3) & 3, height, trackElement);
}



static void TrackDiagFlat(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                    int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        if (trackElement.AsTrack()->HasChain())
        {
            switch (direction)
            {
            case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_FLAT_DIAGONAL+5),{-16,-16,height},{32,32,3},{-16,-16,height});
                break;
            }
        }
        else
        {
            switch (direction)
            {
            case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_DIAGONAL+5),{-16,-16,height},{32,32,3},{-16,-16,height});
                break;
            }
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 1:
        if (trackElement.AsTrack()->HasChain())
        {
            switch (direction)
            {
            case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_FLAT_DIAGONAL+0),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_FLAT_DIAGONAL+1),{-16,-16,height},{32,32,0},{-16,-16,height+27});
                break;
            }
        }
        else
        {
            switch (direction)
            {
            case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_DIAGONAL+0),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_DIAGONAL+1),{-16,-16,height},{32,32,0},{-16,-16,height+27});
                break;
            }
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 2:
        if (trackElement.AsTrack()->HasChain())
        {
            switch (direction)
            {
            case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_FLAT_DIAGONAL+3),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_FLAT_DIAGONAL+4),{-16,-16,height},{32,32,0},{-16,-16,height+27});
                break;
            }
        }
        else
        {
            switch (direction)
            {
            case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_DIAGONAL+3),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_DIAGONAL+4),{-16,-16,height},{32,32,0},{-16,-16,height+27});
                break;
            }
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 3:
        if (trackElement.AsTrack()->HasChain())
        {
            switch (direction)
            {
            case 0:
                MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 0, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_FLAT_DIAGONAL+2),{-16,-16,height},{32,32,3},{-16,-16,height});
                MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 0, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 0, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 0, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            }
        }
        else
        {
            switch (direction)
            {
            case 0:
                MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 0, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_DIAGONAL+2),{-16,-16,height},{32,32,3},{-16,-16,height});
                MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 0, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 0, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 0, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            }
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    }
}

static void TrackDiagUp25(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                         int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        if (trackElement.AsTrack()->HasChain())
        {
            switch (direction)
            {
            case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+17),{-16,-16,height},{32,32,3},{-16,-16,height});
                break;
            }
        }
        else
        {
            switch (direction)
            {
            case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+17),{-16,-16,height},{32,32,3},{-16,-16,height});
                break;
            }
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    case 1:
        if (trackElement.AsTrack()->HasChain())
        {
            switch (direction)
            {
            case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+12),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+13),{-16,-16,height},{32,32,0},{-16,-16,height+40});
                break;
            }
        }
        else
        {
            switch (direction)
            {
            case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+12),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+13),{-16,-16,height},{32,32,0},{-16,-16,height+40});
                break;
            }
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    case 2:
        if (trackElement.AsTrack()->HasChain())
        {
            switch (direction)
            {
            case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+15),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+16),{-16,-16,height},{32,32,0},{-16,-16,height+40});
                break;
            }
        }
        else
        {
            switch (direction)
            {
            case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+15),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+16),{-16,-16,height},{32,32,0},{-16,-16,height+40});
                break;
            }
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    case 3:
        if (trackElement.AsTrack()->HasChain())
        {
            switch (direction)
            {
            case 0:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 8, height+1,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+14),{-16,-16,height},{32,32,3},{-16,-16,height});
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 8, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 8, height+1,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 8, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            }
        }
        else
        {
            switch (direction)
            {
            case 0:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 8, height+1,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+14),{-16,-16,height},{32,32,3},{-16,-16,height});
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 8, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 8, height+1,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 8, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            }
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    }
}

static void TrackDiagUp25ToFlat(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                                 int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        if (trackElement.AsTrack()->HasChain())
        {
            switch (direction)
            {
            case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+11),{-16,-16,height},{32,32,3},{-16,-16,height});
                break;
            }
        }
        else
        {
            switch (direction)
            {
            case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+11),{-16,-16,height},{32,32,3},{-16,-16,height});
                break;
            }
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    case 1:
        if (trackElement.AsTrack()->HasChain())
        {
            switch (direction)
            {
            case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+6),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+7),{-16,-16,height},{32,32,0},{-16,-16,height+35});
                break;
            }
        }
        else
        {
            switch (direction)
            {
            case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+6),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+7),{-16,-16,height},{32,32,0},{-16,-16,height+35});
                break;
            }
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    case 2:
        if (trackElement.AsTrack()->HasChain())
        {
            switch (direction)
            {
            case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+9),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+10),{-16,-16,height},{32,32,0},{-16,-16,height+35});
                break;
            }
        }
        else
        {
            switch (direction)
            {
            case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+9),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+10),{-16,-16,height},{32,32,0},{-16,-16,height+35});
                break;
            }
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    case 3:
        if (trackElement.AsTrack()->HasChain())
        {
            switch (direction)
            {
            case 0:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 4, height+2,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+8),{-16,-16,height},{32,32,3},{-16,-16,height});
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 4, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 4, height+2,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 4, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            }
        }
        else
        {
            switch (direction)
            {
            case 0:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 4, height+2,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+8),{-16,-16,height},{32,32,3},{-16,-16,height});
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 4, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 4, height+2,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 4, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            }
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    }
}

static void TrackDiagFlatToUp25(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                                 int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        if (trackElement.AsTrack()->HasChain())
        {
            switch (direction)
            {
            case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+5),{-16,-16,height},{32,32,3},{-16,-16,height});
                break;
            }
        }
        else
        {
            switch (direction)
            {
            case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+5),{-16,-16,height},{32,32,3},{-16,-16,height});
                break;
            }
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    case 1:
        if (trackElement.AsTrack()->HasChain())
        {
            switch (direction)
            {
            case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+0),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+1),{-16,-16,height},{32,32,0},{-16,-16,height+35});
                break;
            }
        }
        else
        {
            switch (direction)
            {
            case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+0),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+1),{-16,-16,height},{32,32,0},{-16,-16,height+35});
                break;
            }
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    case 2:
        if (trackElement.AsTrack()->HasChain())
        {
            switch (direction)
            {
            case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+3),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+4),{-16,-16,height},{32,32,0},{-16,-16,height+35});
                break;
            }
        }
        else
        {
            switch (direction)
            {
            case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+3),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+4),{-16,-16,height},{32,32,0},{-16,-16,height+35});
                break;
            }
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    case 3:
        if (trackElement.AsTrack()->HasChain())
        {
            switch (direction)
            {
            case 0:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 0, height+2,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+2),{-16,-16,height},{32,32,3},{-16,-16,height});
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 0, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 0, height+2,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 0, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            }
        }
        else
        {
            switch (direction)
            {
            case 0:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 0, height+2,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+2),{-16,-16,height},{32,32,3},{-16,-16,height});
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 0, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 0, height+2,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 0, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            }
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    }
}

static void TrackDiagDown25(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                           int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        if (trackElement.AsTrack()->HasChain())
        {
            switch (direction)
            {
            case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+14),{-16,-16,height},{32,32,3},{-16,-16,height});
                break;
            }
        }
        else
        {
            switch (direction)
            {
            case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+14),{-16,-16,height},{32,32,3},{-16,-16,height});
                break;
            }
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    case 1:
        if (trackElement.AsTrack()->HasChain())
        {
            switch (direction)
            {
            case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+15),{-16,-16,height},{32,32,3},{-16,-16,height});
                break;
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+16),{-16,-16,height},{32,32,0},{-16,-16,height+40});
            }
        }
        else
        {
            switch (direction)
            {
            case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+15),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+16),{-16,-16,height},{32,32,0},{-16,-16,height+40});
                break;
            }
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    case 2:
        if (trackElement.AsTrack()->HasChain())
        {
            switch (direction)
            {
            case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+12),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+13),{-16,-16,height},{32,32,0},{-16,-16,height+40});
                break;
            }
        }
        else
        {
            switch (direction)
            {
            case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+12),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+13),{-16,-16,height},{32,32,0},{-16,-16,height+40});
                break;
            }
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    case 3:
        if (trackElement.AsTrack()->HasChain())
        {
            switch (direction)
            {
            case 0:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 8, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+17),{-16,-16,height},{32,32,3},{-16,-16,height});
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 8, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 8, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 8, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            }
        }
        else
        {
            switch (direction)
            {
            case 0:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 8, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+17),{-16,-16,height},{32,32,3},{-16,-16,height});
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 8, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 8, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 8, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            }
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    }
}

static void TrackDiagFlatToDown25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                   uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        if (trackElement.AsTrack()->HasChain())
        {
            switch (direction)
            {
            case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+8),{-16,-16,height},{32,32,3},{-16,-16,height});
                break;
            }
        }
        else
        {
            switch (direction)
            {
            case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+8),{-16,-16,height},{32,32,3},{-16,-16,height});
                break;
            }
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        break;
    case 1:
        if (trackElement.AsTrack()->HasChain())
        {
            switch (direction)
            {
            case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+9),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+10),{-16,-16,height},{32,32,0},{-16,-16,height+35});
                break;
            }
        }
        else
        {
            switch (direction)
            {
            case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+9),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+10),{-16,-16,height},{32,32,0},{-16,-16,height+35});
                break;
            }
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        break;
    case 2:
        if (trackElement.AsTrack()->HasChain())
        {
            switch (direction)
            {
            case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+6),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+7),{-16,-16,height},{32,32,0},{-16,-16,height+35});
                break;
            }
        }
        else
        {
            switch (direction)
            {
            case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+6),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+7),{-16,-16,height},{32,32,0},{-16,-16,height+35});
                break;
            }
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        break;
    case 3:
        if (trackElement.AsTrack()->HasChain())
        {
            switch (direction)
            {
            case 0:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 4, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+11),{-16,-16,height},{32,32,3},{-16,-16,height});
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 4, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 4, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 4, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            }
        }
        else
        {
            switch (direction)
            {
            case 0:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 4, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+11),{-16,-16,height},{32,32,3},{-16,-16,height});
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 4, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 4, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 4, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            }
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        break;
    }

    PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
}

static void TrackDiagDown25ToFlat(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                   uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        if (trackElement.AsTrack()->HasChain())
        {
            switch (direction)
            {
            case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+2),{-16,-16,height},{32,32,3},{-16,-16,height});
                break;
            }
        }
        else
        {
            switch (direction)
            {
            case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+2),{-16,-16,height},{32,32,3},{-16,-16,height});
                break;
            }
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    case 1:
        if (trackElement.AsTrack()->HasChain())
        {
            switch (direction)
            {
            case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+3),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+4),{-16,-16,height},{32,32,0},{-16,-16,height+35});
                break;
            }
        }
        else
        {
            switch (direction)
            {
            case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+3),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+4),{-16,-16,height},{32,32,0},{-16,-16,height+35});
                break;
            }
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    case 2:
        if (trackElement.AsTrack()->HasChain())
        {
            switch (direction)
            {
            case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+0),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+1),{-16,-16,height},{32,32,0},{-16,-16,height+35});
                break;
            }
        }
        else
        {
            switch (direction)
            {
            case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+0),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+1),{-16,-16,height},{32,32,0},{-16,-16,height+35});
                break;
            }
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    case 3:
        if (trackElement.AsTrack()->HasChain())
        {
            switch (direction)
            {
            case 0:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 0, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_LIFT_TRACK_GENTLE_DIAGONAL+5),{-16,-16,height},{32,32,3},{-16,-16,height});
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 0, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 0, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 0, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            }
        }
        else
        {
            switch (direction)
            {
            case 0:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 0, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_DIAGONAL+5),{-16,-16,height},{32,32,3},{-16,-16,height});
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 0, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 0, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 0, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
                break;
            }
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    }
}

static void TrackDiagUp60(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                         int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
            switch (direction)
            {
            case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+17),{-16,-16,height},{32,32,3},{-16,-16,height});
                break;
            }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 104, 0x20);
        break;
    case 1:
            switch (direction)
            {
            case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+12),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+13),{-16,-16,height},{32,32,0},{-16,-16,height+95});
                break;
            }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 104, 0x20);
        break;
    case 2:
            switch (direction)
            {
            case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+15),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+16),{-16,-16,height},{32,32,0},{-16,-16,height+95});
                break;
            }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 104, 0x20);
        break;
    case 3:
            switch (direction)
            {
            case 0:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 32, height+6, session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+14),{-16,-16,height},{32,32,3},{-16,-16,height});
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 36, height, session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 32, height+6, session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 36, height, session.TrackColours[SCHEME_SUPPORTS]);
                break;
            }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 104, 0x20);
        break;
    }
}

static void TrackDiagUp25ToUp60(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                      uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
            switch (direction)
            {
            case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+5),{-16,-16,height},{32,32,3},{		-16,-16,height});
                break;
            }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 1:
            switch (direction)
            {
            case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+0),{-16,-16,height},{32,32,3},{		-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+1),{-16,-16,height},{32,32,0},{-16,-16,height+64});
                break;
            }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 2:
            switch (direction)
            {
            case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+3),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+4),{-16,-16,height},{32,32,0},{-16,-16,height+64});
                break;
            }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 3:
            switch (direction)
            {
            case 0:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 16, height, session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+2),{-16,-16,height},{32,32,3},{-16,-16,height});
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 16, height, session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 16, height, session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 16, height, session.TrackColours[SCHEME_SUPPORTS]);
                break;
            }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    }
}

static void TrackDiagUp60ToUp25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                      uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
            switch (direction)
            {
            case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+11),{-16,-16,height},{32,32,3},{-16,-16,height});
                break;
            }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 1:
            switch (direction)
            {
            case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+6),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+7),{-16,-16,height},{32,32,0},{-16,-16,height+60});
                break;
            }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 2:
            switch (direction)
            {
            case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+9),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+10),{-16,-16,height},{32,32,0},{-16,-16,height+60});
                break;
            }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 3:
            switch (direction)
            {
            case 0:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 21, height, session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+8),{-16,-16,height},{16,16,3},{0,0,height});
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 21, height, session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 21, height, session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 21, height, session.TrackColours[SCHEME_SUPPORTS]);
                break;
            }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    }
}

static void TrackDiagDown60(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                   int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
            switch (direction)
            {
            case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+14),{-16,-16,height},{32,32,3},{-16,-16,height});
                break;
            }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 104, 0x20);
        break;
    case 1:
            switch (direction)
            {
            case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+15),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+16),{-16,-16,height},{32,32,0},{-16,-16,height+95});
                break;
            }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 104, 0x20);
        break;
    case 2:
            switch (direction)
            {
            case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+12),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+13),{-16,-16,height},{32,32,0},{-16,-16,height+95});
                break;
            }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 104, 0x20);
        break;
    case 3:
            switch (direction)
            {
            case 0:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 24, height, session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+17),{-16,-16,height},{32,32,3},{-16,-16,height});
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 28, height, session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 24, height, session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 28, height, session.TrackColours[SCHEME_SUPPORTS]);
                break;
            }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 104, 0x20);
        break;
    }
}

static void TrackDiagDown25ToDown60(PaintSession& session, const Ride& ride, uint8_t trackSequence,                      uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
            switch (direction)
            {
            case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+8),{-16,-16,height},{16,16,3},{0,0,height});
                break;
            }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 1:
            switch (direction)
            {
            case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+9),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+10),{-16,-16,height},{32,32,0},{-16,-16,height+60});
                break;
            }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 2:
            switch (direction)
            {
            case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+6),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+7),{-16,-16,height},{32,32,0},{-16,-16,height+60});
                break;
            }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 3:
            switch (direction)
            {
            case 0:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 17, height, session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+11),{-16,-16,height},{32,32,3},{-16,-16,height});
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 17, height, session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 17, height, session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 17, height, session.TrackColours[SCHEME_SUPPORTS]);
                break;
            }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    }
}

static void TrackDiagDown60ToDown25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                      uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
            switch (direction)
            {
            case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+2),{-16,-16,height},{32,32,3},{-16,-16,height});
                break;
            }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 1:
            switch (direction)
            {
            case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+3),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+4),{-16,-16,height},{32,32,0},{-16,-16,height+64});
                break;
            }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 2:
            switch (direction)
            {
            case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+0),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+1),{-16,-16,height},{32,32,0},{-16,-16,height+64});
                break;
            }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 3:
            switch (direction)
            {
            case 0:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_DIAGONAL+5),{-16,-16,height},{32,32,3},{-16,-16,height});
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 2:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
                break;
            case 3:
                MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
                break;
            }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    }
}




static void TrackFlatToLeftBank(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                            int32_t height, const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+0),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+1),{0,0,height},{32,1,26},{0,27,height});
        break;
    case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+2),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+3),{0,0,height},{32,1,26},{0,27,height});
        break;
    case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+4),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+5),{0,0,height},{32,1,26},{0,27,height});
        break;
    case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+6),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+7),{0,0,height},{32,1,26},{0,27,height});
        break;
    }
    if (track_paint_util_should_paint_supports(session.MapPosition))
    {
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
    }
    PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
}

static void TrackFlatToRightBank(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                             int32_t height, const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+8),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+9),{0,0,height},{32,1,26},{0,27,height});
        break;
    case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+10),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+11),{0,0,height},{32,1,26},{0,27,height});
        break;
    case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+12),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+13),{0,0,height},{32,1,26},{0,27,height});
        break;
    case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+14),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+15),{0,0,height},{32,1,26},{0,27,height});
        break;
    }
    if (track_paint_util_should_paint_supports(session.MapPosition))
    {
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
    }
    PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
}

static void TrackLeftBankToFlat(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                            int32_t height, const TrackElement& trackElement)
{
	TrackFlatToRightBank(session, ride, trackSequence, (direction + 2) & 3, height, trackElement);
}

static void TrackRightBankToFlat(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                             int32_t height, const TrackElement& trackElement)
{
	TrackFlatToLeftBank(session, ride, trackSequence, (direction + 2) & 3, height, trackElement);
}


static void TrackLeftBankToUp25(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                                 int32_t height, const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+16),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+17),{0,0,height},{32,1,34},{0,27,height});
        break;
    case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+18),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+19),{0,0,height},{32,1,34},{0,27,height});
        break;
    case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+20),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+21),{0,0,height},{32,1,26},{0,27,height});
        break;
    case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+22),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+23),{0,0,height},{32,1,26},{0,27,height});
        break;
    }
    if (track_paint_util_should_paint_supports(session.MapPosition))
    {
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 3, height, session.TrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_8);
    }
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
}

static void TrackRightBankToUp25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                  uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+24),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+25),{0,0,height},{32,1,26},{0,27,height});
        break;
    case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+26),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+27),{0,0,height},{32,1,26},{0,27,height});
        break;
    case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+28),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+29),{0,0,height},{32,1,34},{0,27,height});
        break;
    case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+30),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+31),{0,0,height},{32,1,34},{0,27,height});
        break;
    }
    if (track_paint_util_should_paint_supports(session.MapPosition))
    {
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 3, height, session.TrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_8);
    }
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
}

static void TrackUp25ToLeftBank(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                                 int32_t height, const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+32),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+33),{0,0,height},{32,1,34},{0,27,height});
        break;
    case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+34),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+35),{0,0,height},{32,1,34},{0,27,height});
        break;
    case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+36),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+37),{0,0,height},{32,1,26},{0,27,height});
        break;
    case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+38),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+39),{0,0,height},{32,1,26},{0,27,height});
        break;
    }
    if (track_paint_util_should_paint_supports(session.MapPosition))
    {
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 6, height, session.TrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height - 8, TUNNEL_SQUARE_FLAT);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height + 8, TUNNEL_14);
    }
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 40, 0x20);
}

static void TrackUp25ToRightBank(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                  uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+40),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+41),{0,0,height},{32,1,26},{0,27,height});
        break;
    case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+42),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+43),{0,0,height},{32,1,26},{0,27,height});
        break;
    case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+44),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+45),{0,0,height},{32,1,34},{0,27,height});
        break;
    case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+46),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+47),{0,0,height},{32,1,34},{0,27,height});
        break;
    }
    if (track_paint_util_should_paint_supports(session.MapPosition))
    {
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 6, height, session.TrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height - 8, TUNNEL_SQUARE_FLAT);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height + 8, TUNNEL_14);
    }
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 40, 0x20);
}

static void TrackLeftBankToDown25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                   uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    TrackUp25ToRightBank(session, ride, trackSequence, (direction + 2) & 3, height, trackElement);
}

static void TrackRightBankToDown25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                    uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    TrackUp25ToLeftBank(session, ride, trackSequence, (direction + 2) & 3, height, trackElement);
}

static void TrackDown25ToLeftBank(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                   uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    TrackRightBankToUp25(session, ride, trackSequence, (direction + 2) & 3, height, trackElement);
}

static void TrackDown25ToRightBank(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                    uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    TrackLeftBankToUp25(session, ride, trackSequence, (direction + 2) & 3, height, trackElement);
}

static void TrackLeftBank(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                    int32_t height, const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+48),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+49),{0,0,height},{32,1,26},{0,27,height});
        break;
    case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+50),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+51),{0,0,height},{32,1,26},{0,27,height});
        break;
    case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+52),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+53),{0,0,height},{32,1,26},{0,27,height});
        break;
    case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+54),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION+55),{0,0,height},{32,1,26},{0,27,height});
        break;
    }
    if (track_paint_util_should_paint_supports(session.MapPosition))
    {
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
    }
    PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
}

static void TrackRightBank(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                     int32_t height, const TrackElement& trackElement)
{
    TrackLeftBank(session, ride, trackSequence, (direction + 2) & 3, height, trackElement);
}


static void TrackDiagFlatToLeftBank(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                                 int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+6),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+7),{-16,-16,height},{32,32,0},{-16,-16,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 1:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+0),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+1),{-16,-16,height},{32,32,0},{-16,-16,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+4),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+5),{-16,-16,height},{32,32,0},{-16,-16,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 3:
        switch (direction)
        {
        case 0:
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+2),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+3),{-16,-16,height},{32,32,0},{-16,-16,height+27});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    }
}

static void TrackDiagFlatToRightBank(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                  uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+14),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+15),{-16,-16,height},{32,32,0},{-16,-16,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 1:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+8),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+9),{-16,-16,height},{32,32,0},{-16,-16,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+12),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+13),{-16,-16,height},{32,32,0},{-16,-16,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 3:
        switch (direction)
        {
        case 0:
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+10),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+11),{-16,-16,height},{32,32,0},{-16,-16,height+27});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    }
}

static void TrackDiagLeftBankToFlat(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                                 int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+10),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+11),{-16,-16,height},{32,32,0},{-16,-16,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 1:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+12),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+13),{-16,-16,height},{32,32,0},{-16,-16,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+8),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+9),{-16,-16,height},{32,32,0},{-16,-16,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 3:
        switch (direction)
        {
        case 0:
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+14),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+15),{-16,-16,height},{32,32,0},{-16,-16,height+27});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    }
}

static void TrackDiagRightBankToFlat(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                  uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+2),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+3),{-16,-16,height},{32,32,0},{-16,-16,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 1:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+4),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+5),{-16,-16,height},{32,32,0},{-16,-16,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+0),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+1),{-16,-16,height},{32,32,0},{-16,-16,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 3:
        switch (direction)
        {
        case 0:
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+6),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+7),{-16,-16,height},{32,32,0},{-16,-16,height+27});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    }
}

static void TrackDiagLeftBankToUp25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                      uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+22),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+23),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    case 1:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+16),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+17),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+20),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+21),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    case 3:
        switch (direction)
        {
        case 0:
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+18),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+19),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    }
}

static void TrackDiagRightBankToUp25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                       uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+30),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+31),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    case 1:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+24),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+25),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+28),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+29),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    case 3:
        switch (direction)
        {
        case 0:
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+26),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+27),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    }
}

static void TrackDiagUp25ToLeftBank(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                      uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+38),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+39),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    case 1:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+32),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+33),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+36),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+37),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    case 3:
        switch (direction)
        {
        case 0:
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 4, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+34),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+35),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 4, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 4, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 4, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    }
}

static void TrackDiagUp25ToRightBank(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                       uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+46),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+47),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    case 1:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+40),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+41),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+44),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+45),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    case 3:
        switch (direction)
        {
        case 0:
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 4, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+42),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+43),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 4, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 4, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 4, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    }
}

static void TrackDiagLeftBankToDown25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                        uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+42),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+43),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        break;
    case 1:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+44),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+45),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        break;
    case 2:
        switch (direction)
        {
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+40),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+41),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        break;
    case 3:
        switch (direction)
        {
        case 0:
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 4, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+46),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+47),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 4, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 4, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 4, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        break;
    }

    PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
}

static void TrackDiagRightBankToDown25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                         uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+34),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+35),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        break;
    case 1:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+36),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+37),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        break;
    case 2:
        switch (direction)
        {
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+32),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+33),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        break;
    case 3:
        switch (direction)
        {
        case 0:
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 4, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+38),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+39),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 4, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 4, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 4, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        break;
    }

    PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
}

static void TrackDiagDown25ToLeftBank(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                        uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+26),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+27),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    case 1:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+28),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+29),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+24),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+25),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    case 3:
        switch (direction)
        {
        case 0:
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+30),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+31),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    }
}

static void TrackDiagDown25ToRightBank(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                         uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+18),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+19),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    case 1:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+20),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+21),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+16),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+17),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    case 3:
        switch (direction)
        {
        case 0:
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+22),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+23),{-16,-16,height},{32,32,0},{-16,-16,height+35});
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            MetalBSupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    }
}

static void TrackDiagLeftBank(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                         int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+54),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+55),{-16,-16,height},{32,32,0},{-16,-16,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 1:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+48),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+49),{-16,-16,height},{32,32,0},{-16,-16,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+52),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+53),{-16,-16,height},{32,32,0},{-16,-16,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 3:
        switch (direction)
        {
        case 0:
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+50),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+51),{-16,-16,height},{32,32,0},{-16,-16,height+27});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    }
}

static void TrackDiagRightBank(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                          int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+50),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+51),{-16,-16,height},{32,32,0},{-16,-16,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 1:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+52),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+53),{-16,-16,height},{32,32,0},{-16,-16,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+48),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+49),{-16,-16,height},{32,32,0},{-16,-16,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 3:
        switch (direction)
        {
        case 0:
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+54),{-16,-16,height},{32,32,3},{-16,-16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BANK_TRANSITION_DIAGONAL+55),{-16,-16,height},{32,32,0},{-16,-16,height+27});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    }
}



static void TrackLeftQuarterTurn3TilesBank(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                   uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE_BANKED+0),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE_BANKED+1),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE_BANKED+6),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE_BANKED+7),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE_BANKED+12),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE_BANKED+13),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE_BANKED+18),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE_BANKED+19),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 1:
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE_BANKED+2),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE_BANKED+3),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE_BANKED+8),{0,0,height},{32,32,3},{0,0,height+27});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE_BANKED+9),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE_BANKED+14),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE_BANKED+15),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE_BANKED+20),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE_BANKED+21),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 3:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE_BANKED+4),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE_BANKED+5),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE_BANKED+10),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE_BANKED+11),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE_BANKED+16),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE_BANKED+17),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE_BANKED+22),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_CURVE_BANKED+23),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
        switch (direction)
        {
        case 2:
            PaintUtilPushTunnelRight(session, height, TUNNEL_SQUARE_FLAT);
            break;
        case 3:
            PaintUtilPushTunnelLeft(session, height, TUNNEL_SQUARE_FLAT);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    }
}

static void TrackRightQuarterTurn3TilesBank(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                    uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    trackSequence = mapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence];
    TrackLeftQuarterTurn3TilesBank(session, ride, trackSequence, (direction - 1) & 3, height, trackElement);
}

static void TrackBankedLeftQuarterTurn5(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                     uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+0),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+1),{0,0,height},{32,32,3},{0,0,height+27});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+10),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+11),{0,0,height},{32,32,3},{0,0,height+27});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+20),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+21),{0,0,height},{32,32,3},{0,0,height+27});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+30),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+31),{0,0,height},{32,32,3},{0,0,height+27});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 1:
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+2),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+3),{0,0,height},{32,32,3},{0,0,height+27});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+12),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+13),{0,0,height},{32,32,3},{0,0,height+27});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+22),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+23),{0,0,height},{32,32,3},{0,0,height+27});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+32),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+33),{0,0,height},{32,32,3},{0,0,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session,            PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 3:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+4),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+5),{0,0,height},{32,32,3},{0,0,height+27});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+14),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+15),{0,0,height},{32,32,3},{0,0,height+27});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+24),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+25),{0,0,height},{32,32,3},{0,0,height+27});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+34),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+35),{0,0,height},{32,32,3},{0,0,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 4:
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 5:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+6),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+7),{0,0,height},{32,32,3},{0,0,height+27});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+16),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+17),{0,0,height},{32,32,3},{0,0,height+27});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+26),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+27),{0,0,height},{32,32,3},{0,0,height+27});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+36),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+37),{0,0,height},{32,32,3},{0,0,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session,            PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 6:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+8),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+9),{0,0,height},{32,32,3},{0,0,height+27});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+18),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+19),{0,0,height},{32,32,3},{0,0,height+27});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+28),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+29),{0,0,height},{32,32,3},{0,0,height+27});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+38),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_MEDIUM_CURVE_BANKED+39),{0,0,height},{32,32,3},{0,0,height+27});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
        switch (direction)
        {
        case 2:
            PaintUtilPushTunnelRight(session, height, TUNNEL_SQUARE_FLAT);
            break;
        case 3:
            PaintUtilPushTunnelLeft(session, height, TUNNEL_SQUARE_FLAT);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    }
}

static void TrackBankedRightQuarterTurn5(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                      uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    trackSequence = mapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence];
    TrackBankedLeftQuarterTurn5(session, ride, trackSequence, (direction - 1) & 3, height, trackElement);
}

static void TrackLeftEighthBankTodiag(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                   uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+0),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+1),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+8),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+9),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+16),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+17),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+24),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+25),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 1:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+2),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+3),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+10),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+11),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+18),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+19),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+26),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+27),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session,            PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+4),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+5),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+12),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+13),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+20),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+21),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+28),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+29),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 3:
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 4:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+6),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+7),{0,0,height},{32,32,0},{0,0,height+27});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+14),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+15),{0,0,height},{32,32,0},{0,0,height+27});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+22),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+23),{0,0,height},{32,32,0},{0,0,height+27});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+30),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+31),{0,0,height},{32,32,0},{0,0,height+27});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session,            PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    }
}

static void TrackRightEighthBankTodiag(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                    uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+32),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+33),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+40),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+41),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+48),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+49),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+56),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+57),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 1:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+34),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+35),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+42),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+43),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+50),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+51),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+58),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+59),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session,            PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+36),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+37),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+44),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+45),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+52),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+53),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+60),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+61),{0,0,height},{32,32,0},{0,0,height+27});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 3:
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 4:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+38),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+39),{0,0,height},{32,32,0},{0,0,height+27});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+46),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+47),{0,0,height},{32,32,0},{0,0,height+27});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+54),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+55),{0,0,height},{32,32,0},{0,0,height+27});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+62),{0,0,height},{32,32,3},{0,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_CURVE_BANKED+63),{0,0,height},{32,32,0},{0,0,height+27});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session,            PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    }
}

static void TrackLeftEighthBankToOrthogonal(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                         uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    trackSequence = mapLeftEighthTurnToOrthogonal[trackSequence];
    TrackRightEighthBankTodiag(session, ride, trackSequence, (direction + 2) & 3, height, trackElement);
}

static void TrackRightEighthBankToOrthogonal(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                          uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    trackSequence = mapLeftEighthTurnToOrthogonal[trackSequence];
    TrackLeftEighthBankTodiag(session, ride, trackSequence, (direction + 3) & 3, height, trackElement);
}





static void TrackLeftQuarterTurn3TilesUp25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                        uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+0),{0,6,height},{32,20,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+1),{0,6,height},{32,1,32},{0,28,height});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+4),{0,6,height},{32,20,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+5),{0,6,height},{32,1,32},{0,28,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+8),{0,6,height},{32,20,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+9),{0,6,height},{32,1,32},{0,28,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+12),{0,6,height},{32,20,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+13),{0,6,height},{32,1,32},{0,28,height});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height - 8, TUNNEL_SQUARE_7);
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 1:
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    case 2:
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    case 3:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+2),{6,0,height},{20,32,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+3),{6,0,height},{1,32,32},{28,0,height});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+6),{6,0,height},{20,32,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+7),{6,0,height},{1,32,32},{28,0,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+10),{6,0,height},{20,32,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+11),{6,0,height},{1,32,32},{28,0,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+14),{6,0,height},{20,32,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+15),{6,0,height},{1,32,32},{28,0,height});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
        switch (direction)
        {
        case 2:
            PaintUtilPushTunnelRight(session, height + 8, TUNNEL_SQUARE_8);
            break;
        case 3:
            PaintUtilPushTunnelLeft(session, height + 8, TUNNEL_SQUARE_8);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    }
}

static void TrackRightQuarterTurn3TilesUp25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                         uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+16),{0,6,height},{32,20,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+17),{0,6,height},{32,1,32},{0,28,height});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+20),{0,6,height},{32,20,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+21),{0,6,height},{32,1,32},{0,28,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+24),{0,6,height},{32,20,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+25),{0,6,height},{32,1,32},{0,28,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+28),{0,6,height},{32,20,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+29),{0,6,height},{32,1,32},{0,28,height});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height - 8, TUNNEL_SQUARE_7);
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 1:
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    case 2:
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    case 3:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+18),{6,0,height},{20,32,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+19),{6,0,height},{1,32,32},{28,0,height});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+22),{6,0,height},{20,32,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+23),{6,0,height},{1,32,32},{28,0,height});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+26),{6,0,height},{20,32,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+27),{6,0,height},{1,32,32},{28,0,height});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 10, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+30),{6,0,height},{20,32,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE+31),{6,0,height},{1,32,32},{28,0,height});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        }
        switch (direction)
        {
        case 0:
            PaintUtilPushTunnelRight(session, height + 8, TUNNEL_SQUARE_8);
            break;
        case 1:
            PaintUtilPushTunnelLeft(session, height + 8, TUNNEL_SQUARE_8);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    }
}

static void TrackLeftQuarterTurn3TilesDown25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                          uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    trackSequence = mapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence];
    TrackRightQuarterTurn3TilesUp25(session, ride, trackSequence, (direction + 1) & 3, height, trackElement);
}

static void TrackRightQuarterTurn3TilesDown25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                           uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    trackSequence = mapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence];
    TrackLeftQuarterTurn3TilesUp25(session, ride, trackSequence, (direction - 1) & 3, height, trackElement);
}

static void TrackLeftQuarterTurn5_Up25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                        uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+0),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+1),{0,0,height},{32,1,32},{0,28,height});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+10),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+11),{0,0,height},{32,1,32},{0,28,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+20),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+21),{0,0,height},{32,1,32},{0,28,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+30),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+31),{0,0,height},{32,1,32},{0,28,height});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height - 8, TUNNEL_SQUARE_7);
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 1:
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+2),{0,0,height},{32,16,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+3),{0,0,height},{32,1,32},{0,28,height});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+12),{0,0,height},{32,16,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+13),{0,0,height},{32,1,32},{0,28,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+22),{0,0,height},{32,16,3},{0,16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+23),{0,0,height},{28,28,1},{2,2,height+40});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+32),{0,0,height},{28,16,3},{2,16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+33),{0,0,height},{28,28,1},{2,2,height+40});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session,            PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 3:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+4),{0,0,height},{16,16,3},{0,16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+5),{0,0,height},{16,16,3},{0,16,height+40});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+14),{0,0,height},{16,16,3},{16,16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+15),{0,0,height},{16,16,3},{16,16,height+40});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+24),{0,0,height},{16,16,3},{16,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+25),{0,0,height},{16,16,3},{16,0,height+40});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+34),{0,0,height},{16,16,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+35),{0,0,height},{16,16,3},{0,0,height+40});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 64, 0x20);
        break;
    case 4:
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 5:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+6),{0,0,height},{16,32,3},{16,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+7),{0,0,height},{32,32,1},{16,0,height+40});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+16),{0,0,height},{16,32,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+17),{0,0,height},{1,32,32},{28,0,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+26),{0,0,height},{16,32,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+27),{0,0,height},{1,32,32},{28,0,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+36),{0,0,height},{16,32,3},{16,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+37),{0,0,height},{28,28,1},{2,2,height+40});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session,            PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 6:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+8),{0,0,height},{20,32,10},{6,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+9),{0,0,height},{1,32,32},{28,0,height});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+18),{0,0,height},{20,32,3},{6,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+19),{0,0,height},{1,32,32},{28,0,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+28),{0,0,height},{20,32,3},{6,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+29),{0,0,height},{1,32,32},{28,0,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+38),{0,0,height},{20,32,3},{6,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+39),{0,0,height},{1,32,32},{28,0,height});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
        switch (direction)
        {
        case 2:
            PaintUtilPushTunnelRight(session, height + 8, TUNNEL_SQUARE_8);
            break;
        case 3:
            PaintUtilPushTunnelLeft(session, height + 8, TUNNEL_SQUARE_8);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    }
}

static void TrackRightQuarterTurn5_Up25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                         uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+40),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+41),{0,0,height},{32,1,32},{0,28,height});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+50),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+51),{0,0,height},{32,1,32},{0,28,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+60),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+61),{0,0,height},{32,1,32},{0,28,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+70),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+71),{0,0,height},{32,1,32},{0,28,height});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height - 8, TUNNEL_SQUARE_7);
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 1:
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+42),{0,0,height},{28,16,3},{2,16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+43),{0,0,height},{28,28,1},{2,2,height+40});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+52),{0,0,height},{32,16,3},{0,16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+53),{0,0,height},{28,28,1},{2,2,height+40});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+62),{0,0,height},{32,16,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+63),{0,0,height},{28,28,1},{2,2,height+40});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+72),{0,0,height},{32,16,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+73),{0,0,height},{32,1,32},{0,28,height});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session,            PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 3:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+44),{0,0,height},{16,16,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+45),{0,0,height},{16,16,3},{0,0,height+40});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+54),{0,0,height},{16,16,3},{16,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+55),{0,0,height},{16,16,3},{16,0,height+40});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+64),{0,0,height},{16,16,3},{16,16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+65),{0,0,height},{16,16,3},{16,16,height+40});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+74),{0,0,height},{16,16,3},{0,16,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+75),{0,0,height},{16,16,3},{0,16,height+40});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 64, 0x20);
        break;
    case 4:
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 5:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+46),{0,0,height},{16,32,3},{16,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+47),{0,0,height},{28,28,1},{2,2,height+40});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+56),{0,0,height},{16,32,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+57),{0,0,height},{1,32,32},{28,0,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+66),{0,0,height},{16,32,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+67),{0,0,height},{1,32,32},{28,0,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+76),{0,0,height},{16,32,3},{16,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+77),{0,0,height},{28,28,1},{2,2,height+40});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session,            PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 6:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+48),{0,0,height},{20,32,3},{6,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+49),{0,0,height},{1,32,32},{28,0,height});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+58),{0,0,height},{20,32,3},{6,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+59),{0,0,height},{1,32,32},{28,0,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+68),{0,0,height},{20,32,3},{6,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+69),{0,0,height},{1,32,32},{28,0,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+78),{0,0,height},{20,32,10},{6,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE+79),{0,0,height},{1,32,32},{28,0,height});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
        switch (direction)
        {
        case 0:
            PaintUtilPushTunnelRight(session, height + 8, TUNNEL_SQUARE_8);
            break;
        case 1:
            PaintUtilPushTunnelLeft(session, height + 8, TUNNEL_SQUARE_8);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    }
}

static void TrackLeftQuarterTurn5_Down25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                          uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    trackSequence = mapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence];
    TrackRightQuarterTurn5_Up25(session, ride, trackSequence, (direction + 1) & 3, height, trackElement);
}

static void TrackRightQuarterTurn5_Down25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                           uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    trackSequence = mapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence];
    TrackLeftQuarterTurn5_Up25(session, ride, trackSequence, (direction - 1) & 3, height, trackElement);
}

static void TrackLeftQuarterTurn1TileUp60(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                        uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_SMALL_CURVE+0),{0,0,height},{28,28,3},{2,2,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_SMALL_CURVE+1),{0,0,height},{28,28,1},{2,2,height+99});
        break;
    case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_SMALL_CURVE+2),{0,0,height},{28,28,3},{2,2,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_SMALL_CURVE+3),{0,0,height},{28,28,1},{2,2,height+99});
        break;
    case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_SMALL_CURVE+4),{0,0,height},{28,28,3},{2,2,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_SMALL_CURVE+5),{0,0,height},{28,28,1},{2,2,height+99});
        break;
    case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_SMALL_CURVE+6),{0,0,height},{28,28,3},{2,2,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_SMALL_CURVE+7),{0,0,height},{28,28,1},{2,2,height+99});
        break;
    }
    track_paint_util_left_quarter_turn_1_tile_tunnel(session, direction, height, -8, TUNNEL_SQUARE_7, +56, TUNNEL_SQUARE_8);
    PaintUtilSetSegmentSupportHeight(session, SEGMENTS_ALL, 0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 104, 0x20);
}

static void TrackRightQuarterTurn1TileUp60(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                         uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_SMALL_CURVE+8),{0,0,height},{28,28,3},{2,2,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_SMALL_CURVE+9),{0,0,height},{28,28,1},{2,2,height+99});
        break;
    case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_SMALL_CURVE+10),{0,0,height},{28,28,3},{2,2,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_SMALL_CURVE+11),{0,0,height},{28,28,1},{2,2,height+99});
        break;
    case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_SMALL_CURVE+12),{0,0,height},{28,28,3},{2,2,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_SMALL_CURVE+13),{0,0,height},{28,28,1},{2,2,height+99});
        break;
    case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_SMALL_CURVE+14),{0,0,height},{28,28,3},{2,2,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_STEEP_SMALL_CURVE+15),{0,0,height},{28,28,1},{2,2,height+99});
        break;
    }
  track_paint_util_right_quarter_turn_1_tile_tunnel(session, direction, height, -8, TUNNEL_SQUARE_7, +56, TUNNEL_SQUARE_8);
    PaintUtilSetSegmentSupportHeight(session, SEGMENTS_ALL, 0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 104, 0x20);
}

static void TrackLeftQuarterTurn1TileDown60(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                          uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    TrackRightQuarterTurn1TileUp60(session, ride, trackSequence, (direction + 1) & 3, height, trackElement);
}

static void TrackRightQuarterTurn1TileDown60(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                           uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    TrackLeftQuarterTurn1TileUp60(session, ride, trackSequence, (direction - 1) & 3, height, trackElement);
}

/*
static void TrackLeftQuarterTurn1TileUp90(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                            uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_VERTICAL_TWIST+0),{0,0,height},{2,20,63},{4,6,height+8});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_VERTICAL_TWIST+1),{0,0,height},{2,20,63},{4,6,height+8});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_VERTICAL_TWIST+2),{0,0,height},{2,20,63},{24,6,height+8});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_VERTICAL_TWIST+3),{0,0,height},{2,20,63},{24,6,height+8});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_VERTICAL_TWIST+4),{0,0,height},{2,20,63},{4,6,height+8});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_VERTICAL_TWIST+5),{0,0,height},{2,20,63},{24,6,height+8});
            break;
        }
        paint_util_set_vertical_tunnel(session, height + 96);
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 96, 0x20);
        break;
    case 1:
        break;
    }
}

static void TrackRightQuarterTurn1TileUp90(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                             uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_VERTICAL_TWIST+6),{0,0,height},{2,20,63},{4,6,height+8});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_VERTICAL_TWIST+7),{0,0,height},{2,20,63},{24,6,height+8});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_VERTICAL_TWIST+8),{0,0,height},{2,20,63},{24,6,height+8});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_VERTICAL_TWIST+9),{0,0,height},{2,20,63},{4,6,height+8});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_VERTICAL_TWIST+10),{0,0,height},{2,20,63},{24,6,height+8});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_VERTICAL_TWIST+11),{0,0,height},{2,20,63},{4,6,height+8});
            break;
        }
        paint_util_set_vertical_tunnel(session, height + 96);
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 96, 0x20);
        break;
    case 1:
        break;
    }
}

static void TrackLeftQuarterTurn1TileDown90(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                              uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    TrackRightQuarterTurn1TileUp90(session, ride, trackSequence, (direction + 1) & 3, height,trackElement);
}

static void TrackRightQuarterTurn1TileDown90(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                               uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    TrackLeftQuarterTurn1TileUp90(session, ride, trackSequence, (direction - 1) & 3, height,trackElement);
}




static void TrackUp25ToLeftBankedUp25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                             uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+0),{0,0,height},{32,20,3},{0,6,height});
        break;
    case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+1),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+2),{0,0,height},{32,1,34},{0,27,height});
        break;
    case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+3),{0,0,height},{32,20,3},{0,6,height});
        break;
    case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+4),{0,0,height},{32,20,3},{0,6,height});
        break;
    }
    if (track_paint_util_should_paint_supports(session.MapPosition))
    {
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height - 8, TUNNEL_SQUARE_7);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height + 8, TUNNEL_SQUARE_8);
    }
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
}

static void TrackUp25ToRightBankedUp25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                              uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+5),{0,0,height},{32,20,3},{0,6,height});
        break;
    case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+6),{0,0,height},{32,20,3},{0,6,height});
        break;
    case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+7),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+8),{0,0,height},{32,1,34},{0,27,height});
        break;
    case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+9),{0,0,height},{32,20,3},{0,6,height});
        break;
    }
    if (track_paint_util_should_paint_supports(session.MapPosition))
    {
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height - 8, TUNNEL_SQUARE_7);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height + 8, TUNNEL_SQUARE_8);
    }
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
}

static void TrackLeftBankedUp25ToUp25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                             uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+10),{0,0,height},{32,20,3},{0,6,height});
        break;
    case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+11),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+12),{0,0,height},{32,1,34},{0,27,height});
        break;
    case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+13),{0,0,height},{32,20,3},{0,6,height});
        break;
    case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+14),{0,0,height},{32,20,3},{0,6,height});
        break;
    }
    if (track_paint_util_should_paint_supports(session.MapPosition))
    {
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height - 8, TUNNEL_SQUARE_7);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height + 8, TUNNEL_SQUARE_8);
    }
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
}

static void TrackRightBankedUp25ToUp25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                              uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+15),{0,0,height},{32,20,3},{0,6,height});
        break;
    case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+16),{0,0,height},{32,20,3},{0,6,height});
        break;
    case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+17),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+18),{0,0,height},{32,1,34},{0,27,height});
        break;
    case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+19),{0,0,height},{32,20,3},{0,6,height});
        break;
    }
    if (track_paint_util_should_paint_supports(session.MapPosition))
    {
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height - 8, TUNNEL_SQUARE_7);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height + 8, TUNNEL_SQUARE_8);
    }
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
}

static void TrackLeftBankedDown25ToDown25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                                 uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    TrackUp25ToRightBankedUp25(session, ride, trackSequence, (direction + 2) & 3, height,                                                      trackElement);
}

static void TrackRightBankedDown25ToDown25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                                  uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    TrackUp25ToLeftBankedUp25(session, ride, trackSequence, (direction + 2) & 3, height,                                                     trackElement);
}

static void TrackDown25ToLeftBankedDown25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                                 uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    TrackRightBankedUp25ToUp25(session, ride, trackSequence, (direction + 2) & 3, height,                                                      trackElement);
}

static void TrackDown25ToRightBankedDown25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                                  uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    TrackLeftBankedUp25ToUp25(session, ride, trackSequence, (direction + 2) & 3, height,                                                     trackElement);
}

static void TrackLeftBankedFlatToLeftBankedUp25(PaintSession& session, const Ride& ride,                                                                    uint8_t trackSequence, uint8_t direction, int32_t height,                                                                    const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+20),{0,0,height},{32,1,34},{0,27,height});
        break;
    case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+21),{0,0,height},{32,1,34},{0,27,height});
        break;
    case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+22),{0,0,height},{32,20,3},{0,6,height});
        break;
    case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+23),{0,0,height},{32,20,3},{0,6,height});
        break;
    }
    if (track_paint_util_should_paint_supports(session.MapPosition))
    {
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 3, height, session.TrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_8);
    }
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
}

static void TrackRightBankedFlatToRightBankedUp25(PaintSession& session, const Ride& ride,                                                                      uint8_t trackSequence, uint8_t direction, int32_t height,                                                                      const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+24),{0,0,height},{32,20,3},{0,6,height});
        break;
    case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+25),{0,0,height},{32,20,3},{0,6,height});
        break;
    case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+26),{0,0,height},{32,1,34},{0,27,height});
        break;
    case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+27),{0,0,height},{32,20,3},{0,6,height});
        break;
    }
    if (track_paint_util_should_paint_supports(session.MapPosition))
    {
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 3, height, session.TrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_8);
    }
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
}

static void TrackLeftBankedUp25ToLeftBankedFlat(PaintSession& session, const Ride& ride,                                                                    uint8_t trackSequence, uint8_t direction, int32_t height,                                                                    const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+28),{0,0,height},{32,1,34},{0,27,height});
        break;
    case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+29),{0,0,height},{32,1,34},{0,27,height});
        break;
    case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+30),{0,0,height},{32,20,3},{0,6,height});
        break;
    case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+31),{0,0,height},{32,20,3},{0,6,height});
        break;
    }
    if (track_paint_util_should_paint_supports(session.MapPosition))
    {
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 6, height, session.TrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height - 8, TUNNEL_SQUARE_FLAT);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height + 8, TUNNEL_14);
    }
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 40, 0x20);
}

static void TrackRightBankedUp25ToRightBankedFlat(PaintSession& session, const Ride& ride,                                                                      uint8_t trackSequence, uint8_t direction, int32_t height,                                                                      const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+32),{0,0,height},{32,20,3},{0,6,height});
        break;
    case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+33),{0,0,height},{32,20,3},{0,6,height});
        break;
    case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+34),{0,0,height},{32,1,34},{0,27,height});
        break;
    case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+35),{0,0,height},{32,20,3},{0,6,height});
        break;
    }
    if (track_paint_util_should_paint_supports(session.MapPosition))
    {
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 6, height, session.TrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height - 8, TUNNEL_SQUARE_FLAT);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height + 8, TUNNEL_14);
    }
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 40, 0x20);
}

static void TrackLeftBankedFlatToLeftBankedDown25(PaintSession& session, const Ride& ride,                                                                      uint8_t trackSequence, uint8_t direction, int32_t height,                                                                      const TrackElement& trackElement)
{
    TrackRightBankedUp25ToRightBankedFlat(session, ride, trackSequence, (direction + 2) & 3, height,                                                              trackElement);
}

static void TrackRightBankedFlatToRightBankedDown25(PaintSession& session, const Ride& ride,                                                                        uint8_t trackSequence, uint8_t direction, int32_t height,                                                                        const TrackElement& trackElement)
{
    TrackLeftBankedUp25ToLeftBankedFlat(session, ride, trackSequence, (direction + 2) & 3, height,                                                            trackElement);
}

static void TrackLeftBankedDown25ToLeftBankedFlat(PaintSession& session, const Ride& ride,                                                                      uint8_t trackSequence, uint8_t direction, int32_t height,                                                                      const TrackElement& trackElement)
{
    TrackRightBankedFlatToRightBankedUp25(session, ride, trackSequence, (direction + 2) & 3, height,                                                              trackElement);
}

static void TrackRightBankedDown25ToRightBankedFlat(PaintSession& session, const Ride& ride,                                                                        uint8_t trackSequence, uint8_t direction, int32_t height,                                                                        const TrackElement& trackElement)
{
    TrackLeftBankedFlatToLeftBankedUp25(session, ride, trackSequence, (direction + 2) & 3, height,                                                            trackElement);
}

static void TrackUp25LeftBanked(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                                int32_t height, const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+36),{0,0,height},{32,20,3},{0,6,height});
        break;
    case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+37),{0,0,height},{32,1,34},{0,27,height});
        break;
    case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+38),{0,0,height},{32,20,3},{0,6,height});
        break;
    case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+39),{0,0,height},{32,20,3},{0,6,height});
        break;
    }
    if (track_paint_util_should_paint_supports(session.MapPosition))
    {
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height - 8, TUNNEL_SQUARE_7);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height + 8, TUNNEL_SQUARE_8);
    }
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
}

static void TrackUp25RightBanked(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                                 int32_t height, const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+40),{0,0,height},{32,20,3},{0,6,height});
        break;
    case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+41),{0,0,height},{32,20,3},{0,6,height});
        break;
    case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+42),{0,0,height},{32,1,34},{0,27,height});
        break;
    case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+43),{0,0,height},{32,20,3},{0,6,height});
        break;
    }
    if (track_paint_util_should_paint_supports(session.MapPosition))
    {
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height - 8, TUNNEL_SQUARE_7);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height + 8, TUNNEL_SQUARE_8);
    }
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
}

static void TrackDown25LeftBanked(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                  uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    TrackUp25RightBanked(session, ride, trackSequence, (direction + 2) & 3, height, trackElement);
}

static void TrackDown25RightBanked(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                   uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    TrackUp25LeftBanked(session, ride, trackSequence, (direction + 2) & 3, height, trackElement);
}

static void TrackFlatToLeftBankedUp25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                        uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+44),{0,0,height},{32,20,3},{0,6,height});
        break;
    case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+45),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+46),{0,0,height},{32,1,34},{0,27,height});
        break;
    case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+47),{0,0,height},{32,20,3},{0,6,height});
        break;
    case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+48),{0,0,height},{32,20,3},{0,6,height});
        break;
    }
    if (track_paint_util_should_paint_supports(session.MapPosition))
    {
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 3, height, session.TrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_8);
    }
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
}

static void TrackFlatToRightBankedUp25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                         uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+49),{0,0,height},{32,20,3},{0,6,height});
        break;
    case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+50),{0,0,height},{32,20,3},{0,6,height});
        break;
    case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+51),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+52),{0,0,height},{32,1,34},{0,27,height});
        break;
    case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+53),{0,0,height},{32,20,3},{0,6,height});
        break;
    }
    if (track_paint_util_should_paint_supports(session.MapPosition))
    {
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 3, height, session.TrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_8);
    }
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
}

static void TrackLeftBankedUp25ToFlat(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                        uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+54),{0,0,height},{32,20,3},{0,6,height});
        break;
    case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+55),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+56),{0,0,height},{32,1,34},{0,27,height});
        break;
    case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+57),{0,0,height},{32,20,3},{0,6,height});
        break;
    case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+58),{0,0,height},{32,20,3},{0,6,height});
        break;
    }
    if (track_paint_util_should_paint_supports(session.MapPosition))
    {
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 6, height, session.TrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height - 8, TUNNEL_SQUARE_FLAT);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height + 8, TUNNEL_14);
    }
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 40, 0x20);
}

static void TrackRightBankedUp25ToFlat(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                         uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+59),{0,0,height},{32,20,3},{0,6,height});
        break;
    case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+60),{0,0,height},{32,20,3},{0,6,height});
        break;
    case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+61),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+62),{0,0,height},{32,1,34},{0,27,height});
        break;
    case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SLOPE_BANK_TRANSITION+63),{0,0,height},{32,20,3},{0,6,height});
        break;
    }
    if (track_paint_util_should_paint_supports(session.MapPosition))
    {
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 6, height, session.TrackColours[SCHEME_SUPPORTS]);
    }
    if (direction == 0 || direction == 3)
    {
        PaintUtilPushTunnelRotated(session, direction, height - 8, TUNNEL_SQUARE_FLAT);
    }
    else
    {
        PaintUtilPushTunnelRotated(session, direction, height + 8, TUNNEL_14);
    }
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 40, 0x20);
}

static void TrackFlatToLeftBankedDown25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                          uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    TrackRightBankedUp25ToFlat(session, ride, trackSequence, (direction + 2) & 3, height, trackElement);
}

static void TrackFlatToRightBankedDown25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                           uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    TrackLeftBankedUp25ToFlat(session, ride, trackSequence, (direction + 2) & 3, height, trackElement);
}

static void TrackLeftBankedDown25ToFlat(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                          uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    TrackFlatToRightBankedUp25(session, ride, trackSequence, (direction + 2) & 3, height, trackElement);
}

static void TrackRightBankedDown25ToFlat(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                           uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    TrackFlatToLeftBankedUp25(session, ride, trackSequence, (direction + 2) & 3, height, trackElement);
}

static void TrackLeftBankedQuarterTurn3TilesUp25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                               uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE_BANKED+0),{0,6,height},{32,20,3});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE_BANKED+2),{0,6,height},{32,1,34},{0,27,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE_BANKED+4),{0,6,height},{32,20,3});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE_BANKED+6),{0,6,height},{32,20,3});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height - 8, TUNNEL_SQUARE_7);
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 1:
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    case 2:
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    case 3:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE_BANKED+1),{6,0,height},{20,32,3});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE_BANKED+3),{6,0,height},{1,32,34},{27,0,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE_BANKED+5),{6,0,height},{1,32,34},{27,0,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE_BANKED+7),{6,0,height},{20,32,3});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
        switch (direction)
        {
        case 2:
            PaintUtilPushTunnelRight(session, height + 8, TUNNEL_SQUARE_8);
            break;
        case 3:
            PaintUtilPushTunnelLeft(session, height + 8, TUNNEL_SQUARE_8);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    }
}

static void TrackRightBankedQuarterTurn3TilesUp25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                                uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE_BANKED+8),{0,6,height},{32,20,3});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE_BANKED+10),{0,6,height},{32,20,3});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE_BANKED+12),{0,6,height},{32,1,34},{0,27,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE_BANKED+14),{0,6,height},{32,20,3});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height - 8, TUNNEL_SQUARE_7);
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 1:
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    case 2:
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    case 3:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE_BANKED+9),{6,0,height},{20,32,3});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE_BANKED+11),{6,0,height},{1,32,34},{27,0,height});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE_BANKED+13),{6,0,height},{1,32,34},{27,0,height});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 10, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_SMALL_CURVE_BANKED+15),{6,0,height},{20,32,3});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        }
        switch (direction)
        {
        case 0:
            PaintUtilPushTunnelRight(session, height + 8, TUNNEL_SQUARE_8);
            break;
        case 1:
            PaintUtilPushTunnelLeft(session, height + 8, TUNNEL_SQUARE_8);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    }
}

static void TrackLeftBankedQuarterTurn3TilesDown25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                                 uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    trackSequence = mapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence];
    TrackRightBankedQuarterTurn3TilesUp25(session, ride, trackSequence, (direction + 1) & 3, height,                                                        trackElement);
}

static void TrackRightBankedQuarterTurn3TilesDown25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                                  uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    trackSequence = mapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence];
    TrackLeftBankedQuarterTurn3TilesUp25(session, ride, trackSequence, (direction - 1) & 3, height,                                                       trackElement);
}

static void TrackLeftBankedQuarterTurn5_Up25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                               uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+0),{0,0,height},{32,20,3},{0,6,height});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+5),{0,0,height},{32,1,34},{0,27,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+10),{0,0,height},{32,20,3},{0,6,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+15),{0,0,height},{32,20,3},{0,6,height});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height - 8, TUNNEL_SQUARE_7);
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 1:
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+1),{0,0,height},{32,16,3});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+6),{0,0,height},{1,1,34},{30,30,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+11),{0,0,height},{32,16,3},{0,16,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+16),{0,0,height},{32,16,3},{0,16,height});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session,            PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 3:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+2),{0,0,height},{16,16,3},{0,16,height});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+7),{0,0,height},{1,1,34},{30,30,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+12),{0,0,height},{16,16,3},{16,0,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+17),{0,0,height},{16,16,3});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 64, 0x20);
        break;
    case 4:
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 5:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+3),{0,0,height},{16,32,3},{16,0,height});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+8),{0,0,height},{1,1,34},{30,30,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+13),{0,0,height},{1,32,34},{27,0,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+18),{0,0,height},{16,32,3},{16,0,height});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session,            PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 6:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+4),{0,0,height},{20,32,3},{6,0,height});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+9),{0,0,height},{1,32,34},{27,0,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+14),{0,0,height},{1,32,34},{27,0,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+19),{0,0,height},{20,32,3},{6,0,height});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
        switch (direction)
        {
        case 2:
            PaintUtilPushTunnelRight(session, height + 8, TUNNEL_SQUARE_8);
            break;
        case 3:
            PaintUtilPushTunnelLeft(session, height + 8, TUNNEL_SQUARE_8);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    }
}

static void TrackRightBankedQuarterTurn5_Up25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                                uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+20),{0,0,height},{32,20,3},{0,6,height});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+25),{0,0,height},{32,20,3},{0,6,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+30),{0,0,height},{32,1,34},{0,27,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+35),{0,0,height},{32,20,3},{0,6,height});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height - 8, TUNNEL_SQUARE_7);
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 1:
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+21),{0,0,height},{32,16,3},{0,16,height});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+26),{0,0,height},{32,16,3},{0,16,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+31),{0,0,height},{1,1,34},{30,30,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+36),{0,0,height},{32,16,3});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session,            PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 3:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+22),{0,0,height},{16,16,3});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+27),{0,0,height},{16,16,3},{16,0,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+32),{0,0,height},{1,1,34},{30,30,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+37),{0,0,height},{16,16,3},{0,16,height});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 64, 0x20);
        break;
    case 4:
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 5:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+23),{0,0,height},{16,32,3},{16,0,height});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+28),{0,0,height},{1,32,34},{27,0,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+33),{0,0,height},{1,1,34},{30,30,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+38),{0,0,height},{16,32,3},{16,0,height});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session,            PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    case 6:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+24),{0,0,height},{20,32,3},{6,0,height});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+29),{0,0,height},{1,32,34},{27,0,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+34),{0,0,height},{1,32,34},{27,0,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_GENTLE_MEDIUM_CURVE_BANKED+39),{0,0,height},{20,32,3},{6,0,height});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
        switch (direction)
        {
        case 0:
            PaintUtilPushTunnelRight(session, height + 8, TUNNEL_SQUARE_8);
            break;
        case 1:
            PaintUtilPushTunnelLeft(session, height + 8, TUNNEL_SQUARE_8);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D4, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
        break;
    }
}

static void TrackLeftBankedQuarterTurn5_Down25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                                 uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    trackSequence = mapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence];
    TrackRightBankedQuarterTurn5_Up25(session, ride, trackSequence, (direction + 1) & 3, height,                                                        trackElement);
}

static void TrackRightBankedQuarterTurn5_Down25(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                                  uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    trackSequence = mapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence];
    TrackLeftBankedQuarterTurn5_Up25(session, ride, trackSequence, (direction - 1) & 3, height,                                                       trackElement);
}

static void Tracks_bend_left(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                      int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+0),{0,0,height},{32,20,3},{0,6,height});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+4),{0,0,height},{32,20,3},{0,6,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+3),{0,0,height},{32,20,3},{0,6,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+7),{0,0,height},{32,20,3},{0,6,height});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 1:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+1),{0,0,height},{32,26,3});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 5, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+5),{0,0,height},{32,26,3});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 6, 1, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+2),{0,0,height},{32,26,3},{0,6,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+6),{0,0,height},{32,26,3},{0,6,height});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session,            PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+2),{0,0,height},{32,26,3},{0,6,height});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+6),{0,0,height},{32,26,3},{0,6,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+1),{0,0,height},{32,26,3});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 5, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+5),{0,0,height},{32,26,3});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 6, 1, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session,            PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 3:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+3),{0,0,height},{32,20,3},{0,6,height});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+7),{0,0,height},{32,20,3},{0,6,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+0),{0,0,height},{32,20,3},{0,6,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+4),{0,0,height},{32,20,3},{0,6,height});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
        switch (direction)
        {
        case 1:
            PaintUtilPushTunnelRight(session, height, TUNNEL_SQUARE_FLAT);
            break;
        case 2:
            PaintUtilPushTunnelLeft(session, height, TUNNEL_SQUARE_FLAT);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    }
}

static void Tracks_bend_right(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                       int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+8),{0,0,height},{32,20,3},{0,6,height});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+12),{0,0,height},{32,20,3},{0,6,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+11),{0,0,height},{32,20,3},{0,6,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+15),{0,0,height},{32,20,3},{0,6,height});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 1:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+9),{0,0,height},{32,26,3},{0,6,height});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 8, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+13),{0,0,height},{32,26,3},{0,6,height});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 7, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+10),{0,0,height},{32,26,3});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+14),{0,0,height},{32,26,3});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session,            PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+10),{0,0,height},{32,26,3});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+14),{0,0,height},{32,26,3});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+9),{0,0,height},{32,26,3},{0,6,height});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 8, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+13),{0,0,height},{32,26,3},{0,6,height});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 7, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session,            PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 3:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+11),{0,0,height},{32,20,3},{0,6,height});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+15),{0,0,height},{32,20,3},{0,6,height});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+8),{0,0,height},{32,20,3},{0,6,height});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_S_BEND+12),{0,0,height},{32,20,3},{0,6,height});
            break;
        }
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
        switch (direction)
        {
        case 1:
            PaintUtilPushTunnelRight(session, height, TUNNEL_SQUARE_FLAT);
            break;
        case 2:
            PaintUtilPushTunnelLeft(session, height, TUNNEL_SQUARE_FLAT);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    }
}

*/

static void TrackLeftHalfBankedHelixUpSmall(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                          uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 0), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 1), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 6), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 7), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 12), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 13), { 0, 0, height },
                        { 40, 32, 0 }, { 0, 0, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 18), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height + 8 });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 19), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
            }
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 2, height, session.TrackColours[SCHEME_SUPPORTS]);
            if (direction == 0 || direction == 3)
            {
                PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_0);
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 1:
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 2), { 0, 0, height },
                        { 16, 16, 2 }, { 16, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 3), { 0, 0, height },
                        { 32, 32, 0 }, { 16, 0, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 8), { 0, 0, height },
                        { 16, 16, 2 }, { 0, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 9), { 0, 0, height },
                        { 16, 16, 0 }, { 0, 0, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 14), { 0, 0, height },
                        { 24, 16, 2 }, { -8, 16, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 15), { 0, 0, height },
                        { 16, 40, 0 }, {0, 16, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 20), { 0, 0, height },
                        { 16, 16, 2 }, { 16, 16, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 21), { 0, 0, height },
                        { 16, 16, 0 }, { 16, 16, height + 40 });
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 4), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 5), { 0, 0, height },
                        { 32, 40, 0 }, { 0, 0, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 10), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 11), { 0, 0, height },
                        { 20, 32, 0 }, { 6, 0, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 16), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 17), { 0, 0, height },
                        { 20, 32, 0 }, { 6, 0, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 22), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 23), { 0, 0, height },
                        { 20, 32, 0 }, { 6, 0, height + 40 });
                    break;
            }
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 6, height, session.TrackColours[SCHEME_SUPPORTS]);
            switch (direction)
            {
                case 2:
                    PaintUtilPushTunnelRight(session, height + 8, TUNNEL_0);
                    break;
                case 3:
                    PaintUtilPushTunnelLeft(session, height + 8, TUNNEL_0);
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 4:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 18), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 19), { 0, 0, height },
                        { 20, 32, 0 }, { 6, 0, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 0), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 1), { 0, 0, height },
                        { 20, 32, 0 }, { 6, 0, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 6), { 0, 0, height },
                        { 32, 32, 2 }, { -6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 7), { 0, 0, height },
                        { 20, 32, 0 }, { 6, 0, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 12), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 13), { 0, 0, height },
                        { 32, 40, 0 }, { 0, 0, height + 40 });
                    break;
            }
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 2, height, session.TrackColours[SCHEME_SUPPORTS]);
            switch (direction)
            {
                case 0:
                    PaintUtilPushTunnelRight(session, height, TUNNEL_0);
                    break;
                case 1:
                    PaintUtilPushTunnelLeft(session, height, TUNNEL_0);
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 5:
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 6:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 20), { 0, 0, height },
                        { 16, 16, 2 }, { 16, 16, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 21), { 0, 0, height },
                        { 16, 16, 0 }, { 16, 16, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 2), { 0, 0, height },
                        { 16, 16, 2 }, { 0, 16, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 3), { 0, 0, height },
                        { 32, 32, 0 }, { 0, 16, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 8), { 0, 0, height },
                        { 16, 16, 2 }, { 0, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 9), { 0, 0, height },
                        { 16, 16, 0 }, { 0, 0, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 14), { 0, 0, height },
                        { 16, 24, 2 }, { 16, -8, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 15), { 0, 0, height },
                        { 32, 16, 0 }, { 16, 0, height + 40 });
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 7:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 22), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height + 8 });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 23), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 4), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 5), { 0, 0, height },
                        { 40, 32, 0 }, { 0, 0, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 10), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 11), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 16), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 17), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
            }
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 6, height, session.TrackColours[SCHEME_SUPPORTS]);
            if (direction == 0 || direction == 3)
            {
                PaintUtilPushTunnelRotated(session, direction, height + 8, TUNNEL_0);
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
    }
}

static void TrackRightHalfBankedHelixUpSmall(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                           uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 24), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 25), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 30), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 31), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 36), { 0, 0, height },
                        { 32, 32, 2 }, { 0, -6, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 37), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 42), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 43), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
            }
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 2, height, session.TrackColours[SCHEME_SUPPORTS]);
            if (direction == 0 || direction == 3)
            {
                PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_0);
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 1:
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 26), { 0, 0, height },
                        { 16, 16, 2 }, { 16, 16, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 27), { 0, 0, height },
                        { 16, 16, 0 }, { 16, 16, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 32), { 0, 0, height },
                        { 16, 16, 2 }, { 0, 16, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 33), { 0, 0, height },
                        { 16, 32, 0 }, { 0, 16, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 38), { 0, 0, height },
                        { 16, 16, 2 }, { 0, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 39), { 0, 0, height },
                        { 16, 16, 0 }, { 0, 0, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 44), { 0, 0, height },
                        { 16, 16, 2 }, { 16, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 45), { 0, 0, height },
                        { 32, 16, 0 }, { 16, 0, height + 40 });
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 28), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height + 8 });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 29), { 0, 0, height },
                        { 20, 32, 0 }, { 6, 0, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 34), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 35), { 0, 0, height },
                        { 20, 32, 0 }, { 6, 0, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 40), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 41), { 0, 0, height },
                        { 20, 32, 0 }, { 6, 0, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 46), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 47), { 0, 0, height },
                        { 20, 32, 0 }, { 6, 0, height + 40 });
                    break;
            }
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 6, height, session.TrackColours[SCHEME_SUPPORTS]);
            switch (direction)
            {
                case 0:
                    PaintUtilPushTunnelRight(session, height + 8, TUNNEL_0);
                    break;
                case 1:
                    PaintUtilPushTunnelLeft(session, height + 8, TUNNEL_0);
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 4:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 30), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 31), { 0, 0, height },
                        { 32, 40, 0 }, {0, 0, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 36), { 0, 0, height },
                        { 32, 32, 2 }, { -6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 37), { 0, 0, height },
                        { 20, 32, 0 }, { 6, 0, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 42), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 43), { 0, 0, height },
                        { 20, 40, 0 }, { 6, 0, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 24), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 25), { 0, 0, height },
                        { 20, 32, 0 }, { 6, 0, height + 40 });
                    break;
            }
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 2, height, session.TrackColours[SCHEME_SUPPORTS]);
            switch (direction)
            {
                case 2:
                    PaintUtilPushTunnelRight(session, height, TUNNEL_0);
                    break;
                case 3:
                    PaintUtilPushTunnelLeft(session, height, TUNNEL_0);
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 5:
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 6:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 32), { 0, 0, height },
                        { 16, 16, 2 }, { 16, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 33), { 0, 0, height },
                        { 32, 16, 0 }, { 16, 0, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 38), { 0, 0, height },
                        { 16, 16, 2 }, { 0, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 39), { 0, 0, height },
                        { 16, 16, 0 }, { 0, 0, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 44), { 0, 0, height },
                        { 24, 16, 2 }, { -8, 16, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 45), { 0, 0, height },
                        { 16, 32, 0 }, { 0, 16, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 26), { 0, 0, height },
                        { 16, 16, 2 }, { 16, 16, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 27), { 0, 0, height },
                        { 16, 16, 0 }, { 16, 16, height + 40 });
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 7:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 34), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 35), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 40), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 41), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 46), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 47), { 0, 0, height },
                        { 40, 20, 0 }, { 0, 6, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 28), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height + 8 });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_SMALL_HELIX + 29), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
            }
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 6, height, session.TrackColours[SCHEME_SUPPORTS]);
            if (direction == 0 || direction == 3)
            {
                PaintUtilPushTunnelRotated(session, direction, height + 8, TUNNEL_0);
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
    }
}

static void TrackLeftHalfBankedHelixDownSmall(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                            uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    if (trackSequence >= 4)
    {
        trackSequence -= 4;
        direction = (direction - 1) & 3;
    }
    trackSequence = mapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence];
    TrackRightHalfBankedHelixUpSmall(session, ride, trackSequence, (direction + 1) & 3, height, trackElement);
}

static void TrackRightHalfBankedHelixDownSmall(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                             uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    if (trackSequence >= 4)
    {
        trackSequence -= 4;
        direction = (direction + 1) & 3;
    }
    trackSequence = mapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence];
    TrackLeftHalfBankedHelixUpSmall(session, ride, trackSequence, (direction - 1) & 3, height, trackElement);
}


static void TrackLeftHalfBankedHelixUpLarge(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                          uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 0), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 1), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 10), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 11), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 20), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 21), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 30), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 31), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
            }
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 1, height, session.TrackColours[SCHEME_SUPPORTS]);
            if (direction == 0 || direction == 3)
            {
                PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_0);
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 1:
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 2), { 0, 0, height },
                        { 32, 16, 2 }, { 0, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 3), { 0, 0, height },
                        { 32, 16, 0 }, { 0, 0, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 12), { 0, 0, height },
                        { 32, 16, 2 }, { 0, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 13), { 0, 0, height },
                        { 32, 16, 0 }, { 0, 0, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 22), { 0, 0, height },
                        { 32, 16, 2 }, { 0, 16, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 23), { 0, 0, height },
                        { 32, 16, 0 }, { 0, 16, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 32), { 0, 0, height },
                        { 32, 16, 2 }, { 0, 16, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 33), { 0, 0, height },
                        { 32, 16, 0 }, { 0, 16, height + 40 });
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session,
                PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 4), { 0, 0, height },
                        { 16, 16, 2 }, { 0, 16, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 5), { 0, 0, height },
                        { 16, 16, 0 }, { 0, 16, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 14), { 0, 0, height },
                        { 16, 16, 2 }, { 16, 16, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 15), { 0, 0, height },
                        { 16, 16, 0 }, { 16, 16, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 24), { 0, 0, height },
                        { 16, 16, 2 }, { 16, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 25), { 0, 0, height },
                        { 16, 16, 0 }, { 16, 0, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 26), { 0, 0, height },
                        { 16, 16, 2 }, { 0, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 27), { 0, 0, height },
                        { 16, 16, 0 }, { 0, 0, height + 40 });
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 4:
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 5:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 6), { 0, 0, height },
                        { 16, 32, 2 }, { 16, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 7), { 0, 0, height },
                        { 16, 32, 0 }, { 16, 0, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 16), { 0, 0, height },
                        { 16, 32, 2 }, { 0, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 17), { 0, 0, height },
                        { 16, 32, 0 }, { 0, 0, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 26), { 0, 0, height },
                        { 16, 32, 2 }, { 0, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 27), { 0, 0, height },
                        { 16, 32, 0 }, { 0, 0, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 36), { 0, 0, height },
                        { 16, 32, 2 }, { 16, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 37), { 0, 0, height },
                        { 16, 32, 0 }, { 16, 0, height + 40 });
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session,
                PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 6:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 8), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 9), { 0, 0, height },
                        { 20, 32, 0 }, { 6, 0, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 18), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 19), { 0, 0, height },
                        { 20, 32, 0 }, { 6, 0, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 28), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 29), { 0, 0, height },
                        { 20, 32, 0 }, { 6, 0, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 38), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height + 8 });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 39), { 0, 0, height },
                        { 20, 32, 0 }, { 6, 0, height + 40 });
                    break;
            }
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 7, height, session.TrackColours[SCHEME_SUPPORTS]);
            switch (direction)
            {
                case 2:
                    PaintUtilPushTunnelRight(session, height + 8, TUNNEL_0);
                    break;
                case 3:
                    PaintUtilPushTunnelLeft(session, height + 8, TUNNEL_0);
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 7:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 30), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 31), { 0, 0, height },
                        { 20, 32, 0 }, { 6, 0, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 0), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 1), { 0, 0, height },
                        { 20, 32, 0 }, { 6, 0, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 10), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 11), { 0, 0, height },
                        { 20, 32, 0 }, { 6, 0, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 20), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 21), { 0, 0, height },
                        { 20, 32, 0 }, { 6, 0, height + 40 });
                    break;
            }
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 1, height, session.TrackColours[SCHEME_SUPPORTS]);
            switch (direction)
            {
                case 0:
                    PaintUtilPushTunnelRight(session, height, TUNNEL_0);
                    break;
                case 1:
                    PaintUtilPushTunnelLeft(session, height, TUNNEL_0);
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 8:
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 9:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 32), { 0, 0, height },
                        { 16, 32, 2 }, { 16, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 33), { 0, 0, height },
                        { 16, 32, 0 }, { 16, 0, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 2), { 0, 0, height },
                        { 16, 32, 2 }, { 0, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 3), { 0, 0, height },
                        { 16, 32, 0 }, { 0, 0, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 12), { 0, 0, height },
                        { 16, 32, 2 }, { 0, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 13), { 0, 0, height },
                        { 16, 32, 0 }, { 0, 0, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 22), { 0, 0, height },
                        { 16, 32, 2 }, { 16, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 23), { 0, 0, height },
                        { 16, 32, 0 }, { 16, 0, height + 40 });
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session,
                PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 10:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 26), { 0, 0, height },
                        { 16, 16, 2 }, { 0, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 27), { 0, 0, height },
                        { 16, 16, 0 }, { 0, 0, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 4), { 0, 0, height },
                        { 16, 16, 2 }, { 16, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 5), { 0, 0, height },
                        { 16, 16, 0 }, { 16, 0, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 14), { 0, 0, height },
                        { 16, 16, 2 }, { 16, 16, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 15), { 0, 0, height },
                        { 16, 16, 0 }, { 16, 16, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 24), { 0, 0, height },
                        { 16, 16, 2 }, { 0, 16, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 25), { 0, 0, height },
                        { 16, 16, 0 }, { 0, 16, height + 40 });
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 11:
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 12:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 36), { 0, 0, height },
                        { 32, 16, 2 }, { 0, 16, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 37), { 0, 0, height },
                        { 32, 16, 0 }, { 0, 16, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 6), { 0, 0, height },
                        { 32, 16, 2 }, { 0, 16, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 7), { 0, 0, height },
                        { 32, 16, 0 }, { 0, 16, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 16), { 0, 0, height },
                        { 32, 16, 2 }, { 0, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 17), { 0, 0, height },
                        { 32, 16, 0 }, { 0, 0, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 26), { 0, 0, height },
                        { 32, 16, 2 }, { 0, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 27), { 0, 0, height },
                        { 32, 16, 0 }, { 0, 0, height + 40 });
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session,
                PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 13:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 38), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height + 8 });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 39), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 8), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 9), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 18), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 19), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 28), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_LARGE_HELIX + 29), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
            }
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 7, height, session.TrackColours[SCHEME_SUPPORTS]);
            if (direction == 0 || direction == 3)
            {
                PaintUtilPushTunnelRotated(session, direction, height + 8, TUNNEL_0);
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
    }
}

static void TrackRightHalfBankedHelixUpLarge(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                           uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14906), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14926), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14911), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14931), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14916), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14936), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14921), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14941), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
            }
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 1, height, session.TrackColours[SCHEME_SUPPORTS]);
            if (direction == 0 || direction == 3)
            {
                PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_0);
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 1:
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14907), { 0, 0, height },
                        { 32, 16, 2 }, { 0, 16, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14927), { 0, 0, height },
                        { 32, 16, 0 }, { 0, 16, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14912), { 0, 0, height },
                        { 32, 16, 2 }, { 0, 16, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14932), { 0, 0, height },
                        { 32, 16, 0 }, { 0, 16, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14917), { 0, 0, height },
                        { 32, 16, 2 }, { 0, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14937), { 0, 0, height },
                        { 32, 16, 0 }, { 0, 0, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14922), { 0, 0, height },
                        { 32, 16, 2 }, { 0, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14942), { 0, 0, height },
                        { 32, 16, 0 }, { 0, 0, height + 40 });
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session,
                PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14908), { 0, 0, height },
                        { 16, 16, 2 }, { 0, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14928), { 0, 0, height },
                        { 16, 16, 0 }, { 0, 0, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14913), { 0, 0, height },
                        { 16, 16, 2 }, { 16, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14933), { 0, 0, height },
                        { 16, 16, 0 }, { 16, 0, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14918), { 0, 0, height },
                        { 16, 16, 2 }, { 16, 16, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14938), { 0, 0, height },
                        { 16, 16, 0 }, { 16, 16, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14923), { 0, 0, height },
                        { 16, 16, 2 }, { 0, 16, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14943), { 0, 0, height },
                        { 16, 16, 0 }, { 0, 16, height + 40 });
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 4:
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 5:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14909), { 0, 0, height },
                        { 16, 32, 2 }, { 16, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14929), { 0, 0, height },
                        { 16, 32, 0 }, { 16, 0, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14914), { 0, 0, height },
                        { 16, 32, 2 }, { 0, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14934), { 0, 0, height },
                        { 16, 32, 0 }, { 0, 0, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14919), { 0, 0, height },
                        { 16, 32, 2 }, { 0, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14939), { 0, 0, height },
                        { 16, 32, 0 }, { 0, 0, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14924), { 0, 0, height },
                        { 16, 32, 2 }, { 16, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14944), { 0, 0, height },
                        { 16, 32, 0 }, { 16, 0, height + 40 });
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session,
                PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 6:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14910), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height + 8 });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14930), { 0, 0, height },
                        { 20, 32, 0 }, { 6, 0, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14915), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14935), { 0, 0, height },
                        { 20, 32, 0 }, { 6, 0, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14920), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14940), { 0, 0, height },
                        { 20, 32, 0 }, { 6, 0, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14925), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14945), { 0, 0, height },
                        { 20, 32, 0 }, { 6, 0, height + 40 });
                    break;
            }
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 7, height, session.TrackColours[SCHEME_SUPPORTS]);
            switch (direction)
            {
                case 0:
                    PaintUtilPushTunnelRight(session, height + 8, TUNNEL_0);
                    break;
                case 1:
                    PaintUtilPushTunnelLeft(session, height + 8, TUNNEL_0);
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 7:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14911), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14931), { 0, 0, height },
                        { 20, 32, 0 }, { 6, 0, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14916), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14936), { 0, 0, height },
                        { 20, 32, 0 }, { 6, 0, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14921), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14941), { 0, 0, height },
                        { 20, 32, 0 }, { 6, 0, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14906), { 0, 0, height },
                        { 20, 32, 2 }, { 6, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14926), { 0, 0, height },
                        { 20, 32, 0 }, { 6, 0, height + 40 });
                    break;
            }
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 1, height, session.TrackColours[SCHEME_SUPPORTS]);
            switch (direction)
            {
                case 2:
                    PaintUtilPushTunnelRight(session, height, TUNNEL_0);
                    break;
                case 3:
                    PaintUtilPushTunnelLeft(session, height, TUNNEL_0);
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 8:
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 9:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14912), { 0, 0, height },
                        { 16, 32, 2 }, { 16, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14932), { 0, 0, height },
                        { 16, 32, 0 }, { 16, 0, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14917), { 0, 0, height },
                        { 16, 32, 2 }, { 0, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14937), { 0, 0, height },
                        { 16, 32, 0 }, { 0, 0, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14922), { 0, 0, height },
                        { 16, 32, 2 }, { 0, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14942), { 0, 0, height },
                        { 16, 32, 0 }, { 0, 0, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14907), { 0, 0, height },
                        { 16, 32, 2 }, { 16, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14927), { 0, 0, height },
                        { 16, 32, 0 }, { 16, 0, height + 40 });
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session,
                PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 10:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14913), { 0, 0, height },
                        { 16, 16, 2 }, { 0, 16, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14933), { 0, 0, height },
                        { 16, 16, 0 }, { 0, 16, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14918), { 0, 0, height },
                        { 16, 16, 2 }, { 16, 16, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14938), { 0, 0, height },
                        { 16, 16, 0 }, { 16, 16, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14923), { 0, 0, height },
                        { 16, 16, 2 }, { 16, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14943), { 0, 0, height },
                        { 16, 16, 0 }, { 16, 0, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14908), { 0, 0, height },
                        { 16, 16, 2 }, { 0, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14928), { 0, 0, height },
                        { 16, 16, 0 }, { 0, 0, height + 40 });
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 11:
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 12:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14914), { 0, 0, height },
                        { 32, 16, 2 }, { 0, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14934), { 0, 0, height },
                        { 32, 16, 0 }, { 0, 0, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14919), { 0, 0, height },
                        { 32, 16, 2 }, { 0, 0, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14939), { 0, 0, height },
                        { 32, 16, 0 }, { 0, 0, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14924), { 0, 0, height },
                        { 32, 16, 2 }, { 0, 16, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14944), { 0, 0, height },
                        { 32, 16, 0 }, { 0, 16, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14909), { 0, 0, height },
                        { 32, 16, 2 }, { 0, 16, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14929), { 0, 0, height },
                        { 32, 16, 0 }, { 0, 16, height + 40 });
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session,
                PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
        case 13:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14915), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14935), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14920), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14940), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14925), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14945), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14910), { 0, 0, height },
                        { 32, 20, 2 }, { 0, 6, height + 8 });
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours[SCHEME_TRACK].WithIndex(14930), { 0, 0, height },
                        { 32, 20, 0 }, { 0, 6, height + 40 });
                    break;
            }
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 7, height, session.TrackColours[SCHEME_SUPPORTS]);
            if (direction == 0 || direction == 3)
            {
                PaintUtilPushTunnelRotated(session, direction, height + 8, TUNNEL_0);
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction),
                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
            break;
    }
}

static void TrackLeftHalfBankedHelixDownLarge(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                            uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    if (trackSequence >= 7)
    {
        trackSequence -= 7;
        direction = (direction - 1) & 3;
    }
    trackSequence = mapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence];
    TrackRightHalfBankedHelixUpLarge(session, ride, trackSequence, (direction + 1) & 3, height, trackElement);
}

static void TrackRightHalfBankedHelixDownLarge(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                             uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    if (trackSequence >= 7)
    {
        trackSequence -= 7;
        direction = (direction + 1) & 3;
    }
    trackSequence = mapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence];
    TrackLeftHalfBankedHelixUpLarge(session, ride, trackSequence, (direction - 1) & 3, height, trackElement);
}

static void TrackLeftTwistDownToUp(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                          uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+0),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+1),{0,0,height},{32,20,0},{0,6,height+32});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 2, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+6),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+7),{0,0,height},{32,20,0},{0,6,height+32});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 2, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+12),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+13),{0,0,height},{32,20,0},{0,6,height+32});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 2, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+18),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+19),{0,0,height},{32,20,0},{0,6,height+32});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 2, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        }
        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 1:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+2),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+3),{0,0,height},{32,20,0},{0,6,height+32});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+8),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+9),{0,0,height},{32,20,0},{0,6,height+32});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+14),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+15),{0,0,height},{32,20,0},{0,6,height+32});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+20),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+21),{0,0,height},{32,20,0},{0,6,height+32});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session,            PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+4),{0,0,height},{32,20,3},{0,6,height-16});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+5),{0,0,height},{32,20,0},{0,6,height+16});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+10),{0,0,height},{32,20,3},{0,6,height-16});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+11),{0,0,height},{32,20,0},{0,6,height+16});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+16),{0,0,height},{32,20,3},{0,6,height-16});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+17),{0,0,height},{32,20,0},{0,6,height+16});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+22),{0,0,height},{32,20,3},{0,6,height-16});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+23),{0,0,height},{32,20,0},{0,6,height+16});
            break;
        }
        switch (direction)
        {
        case 1:
            PaintUtilPushTunnelRight(session, height, TUNNEL_SQUARE_INVERTED_9);
            break;
        case 2:
            PaintUtilPushTunnelLeft(session, height, TUNNEL_SQUARE_INVERTED_9);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    }
}

static void TrackRightTwistDownToUp(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                           uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+24),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+25),{0,0,height},{32,20,0},{0,6,height+32});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 0, 2, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+30),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+31),{0,0,height},{32,20,0},{0,6,height+32});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 2, 2, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+36),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+37),{0,0,height},{32,20,0},{0,6,height+32});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 3, 2, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+42),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+43),{0,0,height},{32,20,0},{0,6,height+32});
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 1, 2, height, session.TrackColours[SCHEME_SUPPORTS]);
            break;
        }
        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
        break;
    case 1:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+26),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+27),{0,0,height},{32,20,0},{0,6,height+32});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+32),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+33),{0,0,height},{32,20,0},{0,6,height+32});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+38),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+39),{0,0,height},{32,20,0},{0,6,height+32});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+44),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+45),{0,0,height},{32,20,0},{0,6,height+32});
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session,            PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+28),{0,0,height},{32,20,3},{0,6,height-16});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+29),{0,0,height},{32,20,0},{0,6,height+16});
            break;
        case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+34),{0,0,height},{32,20,3},{0,6,height-16});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+35),{0,0,height},{32,20,0},{0,6,height+26});
            break;
        case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+40),{0,0,height},{32,20,3},{0,6,height-16});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+41),{0,0,height},{32,20,0},{0,6,height+16});
            break;
        case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+46),{0,0,height},{32,20,3},{0,6,height-16});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_INLINE_TWIST+47),{0,0,height},{32,20,0},{0,6,height+16});
            break;
        }
        switch (direction)
        {
        case 1:
            PaintUtilPushTunnelRight(session, height, TUNNEL_SQUARE_INVERTED_9);
            break;
        case 2:
            PaintUtilPushTunnelLeft(session, height, TUNNEL_SQUARE_INVERTED_9);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction),            0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    }
}

static void TrackLeftTwistUpToDown(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                          uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    TrackLeftTwistDownToUp(session, ride, 2 - trackSequence, (direction + 2) & 3, height,                                                         trackElement);
}

static void TrackRightTwistUpToDown(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                           uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    TrackRightTwistDownToUp(session, ride, 2 - trackSequence, (direction + 2) & 3, height,                                                          trackElement);
}

static void TrackHalfLoopUp(
    PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,    const TrackElement& trackElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+0),{0,6,height},{32,20,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+1),{0,6,height},{32,1,33},{0,27,height});
                    break;
                case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+8),{0,6,height},{32,20,11});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+9),{0,6,height},{32,1,33},{0,27,height});
                    break;
                case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+16),{0,6,height},{32,20,9});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+17),{0,6,height},{32,1,33},{0,27,height});
                    break;
                case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+24),{0,6,height},{32,20,7});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+25),{0,6,height},{32,1,33},{0,27,height});
                    break;
            }
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 8, height, session.TrackColours[SCHEME_SUPPORTS]);
            if (direction == 0 || direction == 3)
            {
                PaintUtilPushTunnelRotated(session, direction, height - 8, TUNNEL_1);
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
            break;
        case 1:
            switch (direction)
            {
                case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+2),{0,0,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+3),{0,0,height},{32,1,63},{0,27,height});
                    MetalASupportsPaintSetup(
                        session, METAL_SUPPORTS_TUBES, 4, 20, height, session.TrackColours[SCHEME_SUPPORTS]);
                    break;
                case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+10),{0,14,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+11),{0,14,height},{3,1,63},{0,27,height});
                    MetalASupportsPaintSetup(
                        session, METAL_SUPPORTS_TUBES, 4, 15, height, session.TrackColours[SCHEME_SUPPORTS]);
                    break;
                case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+18),{0,6,height},{32,20,3},{0,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+19),{0,6,height},{32,1,63},{0,27,height});
                    MetalASupportsPaintSetup(
                        session, METAL_SUPPORTS_TUBES, 4, 16, height, session.TrackColours[SCHEME_SUPPORTS]);
                    break;
                case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+26),{0,6,height},{32,20,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+27),{0,6,height},{32,1,63},{0,27,height});
                    MetalASupportsPaintSetup(
                        session, METAL_SUPPORTS_TUBES, 4, 16, height, session.TrackColours[SCHEME_SUPPORTS]);
                    break;
            }
            PaintUtilSetSegmentSupportHeight(session, SEGMENTS_ALL, 0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 72, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+4),{16,0,height},{2,16,119});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+5),{16,0,height},{32,1,119},{0,27,height});
                    break;
                case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+12),{12,0,height},{3,16,119},{12,0,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+13),{12,0,height},{32,1,119},{12,0,height});
                    break;
                case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+20),{10,16,height},{4,12,119});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+21),{10,16,height},{32,1,119},{0,27,height});
                    break;
                case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+28),{16,16,height},{2,16,119},{15,6,height});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+29),{16,16,height},{32,1,119},{15,6,height});
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session,                PaintUtilRotateSegments(
                    SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),                0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 168, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+6),{0,0,height+32},{32,16,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+7),{0,0,height+32},{32,16,3});
                    break;
                case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+14),{0,0,height+32},{32,16,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+15),{0,0,height+32},{32,16,3});
                    break;
                case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+22),{0,16,height+32},{32,12,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+23),{0,16,height+32},{32,12,3});
                    break;
                case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+30),{0,16,height+32},{32,12,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_HALF_LOOP+31),{0,16,height+32},{32,12,3});
                    break;
            }
            if (direction == 0 || direction == 3)
            {
                PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_0);
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
            break;
    }
}

static void TrackHalfLoopDown(
    PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,    const TrackElement& trackElement)
{
    TrackHalfLoopUp(session, ride, 3 - trackSequence, direction, height, trackElement);
}
/*
static void Trackbrakes(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,                                 const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
    case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BRAKE+0),{0,0,height},{32,20,3},{0,6,height});
        break;
    case 1:
    case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BRAKE+1),{0,0,height},{32,20,3},{0,6,height});
        break;
    }
    if (track_paint_util_should_paint_supports(session.MapPosition))
    {
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
    }
    PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
}

static void Trackon_ride_photo(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                        int32_t height, const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
PaintAddImageAsParentRotated(session,direction,IMAGE_TYPE_REMAP|SPR_STATION_BASE_D,0,0,32,32,1,height);
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 5, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 8, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT+0),{0,0,height},{32,20,0},{0,6,height+3});
        break;
    case 1:
PaintAddImageAsParentRotated(session,direction,IMAGE_TYPE_REMAP|SPR_STATION_BASE_D,0,0,32,32,1,height);
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 6, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 7, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT+1),{0,0,height},{32,20,0},{0,6,height+3});
        break;
    case 2:
PaintAddImageAsParentRotated(session,direction,IMAGE_TYPE_REMAP|SPR_STATION_BASE_D,0,0,32,32,1,height);
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 5, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 8, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT+0),{0,0,height},{32,20,0},{0,6,height+3});
        break;
    case 3:
PaintAddImageAsParentRotated(session,direction,IMAGE_TYPE_REMAP|SPR_STATION_BASE_D,0,0,32,32,1,height);
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 6, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 7, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT+1),{0,0,height},{32,20,0},{0,6,height+3});
        break;
    }
    track_paint_util_onride_phoTopaint(session, direction, height + 3, trackElement);
    PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    PaintUtilSetSegmentSupportHeight(session, SEGMENTS_ALL, 0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
}

static void TrackFlatToUp60long_base(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                      uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
            switch (direction)
            {
            case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+0),{0,0,height},{32,20,3},{0,6,height});
                break;
            case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+4),{0,0,height},{32,20,3},{0,6,height});
                break;
            case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+8),{0,0,height},{32,20,3},{0,6,height});
                break;
            case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+12),{0,0,height},{32,20,3},{0,6,height});
                break;
            }
            if (track_paint_util_should_paint_supports(session.MapPosition))
            {
                MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 3, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
            }
        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    case 1:
            switch (direction)
            {
            case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+1),{0,0,height},{32,20,3},{0,6,height});
                break;                                                                                                    
            case 1:                                                                                                       
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+5),{0,0,height},{32,20,3},{0,6,height});
                break;                                                                                                    
            case 2:                                                                                                       
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+9),{0,0,height},{32,20,3},{0,6,height});
                break;                                                                                                    
            case 3:                                                                                                       
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+13),{0,0,height},{32,20,3},{0,6,height});
                break;
            }
            if (track_paint_util_should_paint_supports(session.MapPosition))
            {
                MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 5, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
            }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
        break;
    case 2:
            switch (direction)
            {
            case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+2),{0,0,height},{32,20,3},{0,6,height});
                break;                                                                                                    
            case 1:                                                                                                       
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+6),{0,0,height},{32,20,3},{0,6,height});
                break;                                                                                                    
            case 2:                                                                                                       
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+10),{0,0,height},{32,20,3},{0,6,height});
                break;                                                                                                    
            case 3:                                                                                                       
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+14),{0,0,height},{32,20,3},{0,6,height});
                break;
            }
            if (track_paint_util_should_paint_supports(session.MapPosition))
            {
                MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 7, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
            }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 64, 0x20);
        break;
    case 3:
            switch (direction)
            {
            case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+3),{0,0,height},{32,20,3},{0,6,height});
                break;                                                                                                    
            case 1:                                                                                                       
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+7),{0,0,height},{32,1,98},{0,27,height});
                break;                                                                                                    
            case 2:                                                                                                       
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+11),{0,0,height},{32,1,98},{0,27,height});
                break;                                                                                                    
            case 3:                                                                                                       
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+15),{0,0,height},{32,20,3},{0,6,height});
                break;
            }
            if (track_paint_util_should_paint_supports(session.MapPosition))
            {
                MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 12, height,                                             session.TrackColours[SCHEME_SUPPORTS]);
            }
        switch (direction)
        {
        case 1:
            PaintUtilPushTunnelRight(session, height + 24, TUNNEL_SQUARE_8);
            break;
        case 2:
            PaintUtilPushTunnelLeft(session, height + 24, TUNNEL_SQUARE_8);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 80, 0x20);
        break;
    }
}
static void TrackUp60ToFlat_long_base(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                      uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    switch (trackSequence)
    {
    case 0:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+16),{0,0,height},{32,20,3},{0,6,height});
            break;                                                                                                    
        case 1:                                                                                                       
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+20),{0,0,height},{32,1,98},{0,27,height});
            break;                                                                                                    
        case 2:                                                                                                       
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+24),{0,0,height},{32,1,98},{0,27,height});
            break;                                                                                                    
        case 3:                                                                                                       
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+28),{0,0,height},{32,20,3},{0,6,height});
            break;
        }
        if (track_paint_util_should_paint_supports(session.MapPosition))
        {
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 16, height, session.TrackColours[SCHEME_SUPPORTS]);
        }
        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_7);
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 80, 0x20);
        break;
    case 1:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+17),{0,0,height},{32,20,3},{0,6,height});
            break;                                                                                                    
        case 1:                                                                                                       
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+21),{0,0,height},{32,20,3},{0,6,height});
            break;                                                                                                    
        case 2:                                                                                                       
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+25),{0,0,height},{32,20,3},{0,6,height});
            break;                                                                                                    
        case 3:                                                                                                       
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+29),{0,0,height},{32,20,3},{0,6,height});
            break;
        }
        if (track_paint_util_should_paint_supports(session.MapPosition))
        {
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 12, height, session.TrackColours[SCHEME_SUPPORTS]);
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 80, 0x20);
        break;
    case 2:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+18),{0,0,height},{32,20,3},{0,6,height});
            break;                                                                                                    
        case 1:                                                                                                       
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+22),{0,0,height},{32,20,3},{0,6,height});
            break;                                                                                                    
        case 2:                                                                                                       
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+26),{0,0,height},{32,20,3},{0,6,height});
            break;                                                                                                    
        case 3:                                                                                                       
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+30),{0,0,height},{32,20,3},{0,6,height});
            break;
        }
        if (track_paint_util_should_paint_supports(session.MapPosition))
        {
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 9, height, session.TrackColours[SCHEME_SUPPORTS]);
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 56, 0x20);
        break;
    case 3:
        switch (direction)
        {
        case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+19),{0,0,height},{32,20,3},{0,6,height});
            break;                                                                                                    
        case 1:                                                                                                       
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+23),{0,0,height},{32,20,3},{0,6,height});
            break;                                                                                                    
        case 2:                                                                                                       
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+27),{0,0,height},{32,20,3},{0,6,height});
            break;                                                                                                    
        case 3:                                                                                                       
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_FLAT_TO_STEEP+31),{0,0,height},{32,20,3},{0,6,height});
            break;
        }
        if (track_paint_util_should_paint_supports(session.MapPosition))
        {
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 5, height, session.TrackColours[SCHEME_SUPPORTS]);
        }
        switch (direction)
        {
        case 1:
            PaintUtilPushTunnelRight(session, height + 8, TUNNEL_SQUARE_FLAT);
            break;
        case 2:
            PaintUtilPushTunnelLeft(session, height + 8, TUNNEL_SQUARE_FLAT);
            break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 40, 0x20);
        break;
    }
}

static void TrackFlatToDown60long_base(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                        uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    TrackUp60ToFlat_long_base(session, ride, 3 - trackSequence, (direction + 2) & 3, height, trackElement);
}

static void TrackDown60ToFlat_long_base(PaintSession& session, const Ride& ride, uint8_t trackSequence,                                                         uint8_t direction, int32_t height, const TrackElement& trackElement)
{
    TrackFlatToUp60long_base(session, ride, 3 - trackSequence, (direction + 2) & 3, height, trackElement);
}

static void Trackblock_brakes(PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction,                                       int32_t height, const TrackElement& trackElement)
{
    switch (direction)
    {
    case 0:
    case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BLOCK_BRAKE+0),{0,0,height},{32,20,3},{0,6,height});
        break;
    case 1:
    case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_BLOCK_BRAKE+1),{0,0,height},{32,20,3},{0,6,height});
        break;
    }
    if (track_paint_util_should_paint_supports(session.MapPosition))
    {
        MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
    }
    PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction),                                          0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + 32, 0x20);
}

static void TrackLeftBankToLeftQuarterTurn3TilesUp25(
    PaintSession& session, ride_id_t ride, uint8_t trackSequence, uint8_t direction, int32_t height,    const TileElement* trackElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+0),{0,6,height},{32,20,3});
                    break;
                case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+2),{0,6,height},{32,20,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+3),{0,6,height},{32,1,26},{0,27,height});
                    break;
                case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+5),{0,6,height},{32,20,3});
                    break;
                case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+7),{0,6,height},{32,20,3});
                    break;
            }
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            if (direction == 0 || direction == 3)
            {
                PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 64, 0x20);
            break;
        case 1:
            PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
            break;
        case 2:
            PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+1),{6,0,height},{20,32,3},{0,6,height-6});
                    break;
                case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+4),{6,0,height},{20,32,3},{0,6,height-6});
                    break;
                case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+6),{6,0,height},{20,32,3},{0,6,height-6});
                    break;
                case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+8),{6,0,height},{20,32,3},{0,6,height-6});
                    break;
            }
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            switch (direction)
            {
                case 2:
                    PaintUtilPushTunnelRight(session, height, TUNNEL_SQUARE_8);
                    break;
                case 3:
                    PaintUtilPushTunnelLeft(session, height, TUNNEL_SQUARE_8);
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D4, direction), 0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 64, 0x20);
            break;
    }
}

static void TrackRightBankToRightQuarterTurn3TilesUp25(
    PaintSession& session, ride_id_t ride, uint8_t trackSequence, uint8_t direction, int32_t height,    const TileElement* trackElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+9),{0,6,height},{32,20,3});
                    break;
                case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+11),{0,6,height},{32,20,3});
                    break;
                case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+13),{0,6,height},{32,20,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+14),{0,6,height},{32,1,26},{0,27,height});
                    break;
                case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+16),{0,6,height},{32,20,3});
                    break;
            }
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            if (direction == 0 || direction == 3)
            {
                PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_FLAT);
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 64, 0x20);
            break;
        case 1:
            PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
            break;
        case 2:
            PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+10),{6,0,height},{20,32,3},{0,6,height-6});
                    MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
                    break;
                case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+12),{6,0,height},{20,32,3},{0,6,height-6});
                    MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
                    break;
                case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+15),{6,0,height},{20,32,3},{0,6,height-6});
                    MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 2, height, session.TrackColours[SCHEME_SUPPORTS]);
                    break;
                case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+17),{6,0,height},{20,32,3},{0,6,height-6});
                    MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
                    break;
            }
            switch (direction)
            {
                case 0:
                    PaintUtilPushTunnelRight(session, height, TUNNEL_SQUARE_8);
                    break;
                case 1:
                    PaintUtilPushTunnelLeft(session, height, TUNNEL_SQUARE_8);
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D4, direction), 0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 64, 0x20);
            break;
    }
}

static void TrackLeftQuarterTurn3TilesDown25ToLeftBank(
    PaintSession& session, ride_id_t ride, uint8_t trackSequence, uint8_t direction, int32_t height,    const TileElement* trackElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+12),{0,6,height},{32,20,3},{0,6,height-6});
                    MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
                    break;
                case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+15),{0,6,height},{32,20,3},{0,6,height-6});
                    MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 2, height, session.TrackColours[SCHEME_SUPPORTS]);
                    break;
                case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+17),{0,6,height},{32,20,3},{0,6,height-6});
                    MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
                    break;
                case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+10),{0,6,height},{32,20,3},{0,6,height-6});
                    MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
                    break;
            }
            if (direction == 0 || direction == 3)
            {
                PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_8);
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 64, 0x20);
            break;
        case 1:
            PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
            break;
        case 2:
            PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+11),{6,0,height},{20,32,3});
                    break;
                case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+13),{6,0,height},{20,32,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+14),{6,0,height},{1,32,26},{27,0,height});
                    break;
                case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+16),{6,0,height},{20,32,3});
                    break;
                case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+9),{6,0,height},{20,32,3});
                    break;
            }
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            switch (direction)
            {
                case 2:
                    PaintUtilPushTunnelRight(session, height, TUNNEL_SQUARE_FLAT);
                    break;
                case 3:
                    PaintUtilPushTunnelLeft(session, height, TUNNEL_SQUARE_FLAT);
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D4, direction), 0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 64, 0x20);
            break;
    }
}

static void TrackRightQuarterTurn3TilesDown25ToRightBank(
    PaintSession& session, ride_id_t ride, uint8_t trackSequence, uint8_t direction, int32_t height,    const TileElement* trackElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+8),{0,6,height},{32,20,3},{0,6,height-6});
                    break;
                case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+1),{0,6,height},{32,20,3},{0,6,height-6});
                    break;
                case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+4),{0,6,height},{32,20,3},{0,6,height-6});
                    break;
                case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+6),{0,6,height},{32,20,3},{0,6,height-6});
                    break;
            }
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            if (direction == 0 || direction == 3)
            {
                PaintUtilPushTunnelRotated(session, direction, height, TUNNEL_SQUARE_8);
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0, direction), 0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 64, 0x20);
            break;
        case 1:
            PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
            break;
        case 2:
            PaintUtilSetGeneralSupportHeight(session, height + 48, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 0:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+7),{6,0,height},{20,32,3});
                    break;
                case 1:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+0),{6,0,height},{20,32,3});
                    break;
                case 2:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+2),{6,0,height},{20,32,3});
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+3),{6,0,height},{1,32,26},{27,0,height});
                    break;
                case 3:
PaintAddImageAsParentRotated(session,direction,session.TrackColours[SCHEME_TRACK].WithIndex(SPR_G2_PIPELINE_TRACK_TURN_BANK_TRANSITION+5),{6,0,height},{20,32,3});
                    break;
            }
            MetalASupportsPaintSetup(session, METAL_SUPPORTS_TUBES, 4, 0, height, session.TrackColours[SCHEME_SUPPORTS]);
            switch (direction)
            {
                case 0:
                    PaintUtilPushTunnelRight(session, height, TUNNEL_SQUARE_FLAT);
                    break;
                case 1:
                    PaintUtilPushTunnelLeft(session, height, TUNNEL_SQUARE_FLAT);
                    break;
            }
            PaintUtilSetSegmentSupportHeight(
                session, PaintUtilRotateSegments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D4, direction), 0xFFFF, 0);
            PaintUtilSetGeneralSupportHeight(session, height + 64, 0x20);
            break;
    }
}
*/

TRACK_PAINT_FUNCTION GetTrackPaintFunction(int32_t trackType)
{
    switch (trackType)
    {
    case TrackElemType::Flat:
        return TrackFlat;
    case TrackElemType::EndStation:
    case TrackElemType::BeginStation:
    case TrackElemType::MiddleStation:
        return TrackStation;
    case TrackElemType::Up25:
        return TrackUp25;
    case TrackElemType::Up60:
        return TrackUp60;
    case TrackElemType::FlatToUp25:
        return TrackFlatToUp25;
    case TrackElemType::Up25ToUp60:
        return TrackUp25ToUp60;
    case TrackElemType::Up60ToUp25:
        return TrackUp60ToUp25;
    case TrackElemType::Up25ToFlat:
        return TrackUp25ToFlat;
    case TrackElemType::Down25:
        return TrackDown25;
    case TrackElemType::Down60:
        return TrackDown60;
    case TrackElemType::FlatToDown25:
        return TrackFlatToDown25;
    case TrackElemType::Down25ToDown60:
        return TrackDown25ToDown60;
    case TrackElemType::Down60ToDown25:
        return TrackDown60ToDown25;
    case TrackElemType::Down25ToFlat:
        return TrackDown25ToFlat;
    case TrackElemType::LeftQuarterTurn5Tiles:
        return TrackLeftQuarterTurn5;
    case TrackElemType::RightQuarterTurn5Tiles:
        return TrackRightQuarterTurn5;
    case TrackElemType::FlatToLeftBank:
        return TrackFlatToLeftBank;
    case TrackElemType::FlatToRightBank:
        return TrackFlatToRightBank;
    case TrackElemType::LeftBankToFlat:
        return TrackLeftBankToFlat;
    case TrackElemType::RightBankToFlat:
        return TrackRightBankToFlat;
    case TrackElemType::BankedLeftQuarterTurn5Tiles:
        return TrackBankedLeftQuarterTurn5;
    case TrackElemType::BankedRightQuarterTurn5Tiles:
        return TrackBankedRightQuarterTurn5;
    case TrackElemType::LeftBankToUp25:
        return TrackLeftBankToUp25;
    case TrackElemType::RightBankToUp25:
        return TrackRightBankToUp25;
    case TrackElemType::Up25ToLeftBank:
        return TrackUp25ToLeftBank;
    case TrackElemType::Up25ToRightBank:
        return TrackUp25ToRightBank;
    case TrackElemType::LeftBankToDown25:
        return TrackLeftBankToDown25;
    case TrackElemType::RightBankToDown25:
        return TrackRightBankToDown25;
    case TrackElemType::Down25ToLeftBank:
        return TrackDown25ToLeftBank;
    case TrackElemType::Down25ToRightBank:
        return TrackDown25ToRightBank;
    case TrackElemType::LeftBank:
        return TrackLeftBank;
    case TrackElemType::RightBank:
        return TrackRightBank;
    case TrackElemType::LeftQuarterTurn5TilesUp25:
        return TrackLeftQuarterTurn5_Up25;
    case TrackElemType::RightQuarterTurn5TilesUp25:
        return TrackRightQuarterTurn5_Up25;
    case TrackElemType::LeftQuarterTurn5TilesDown25:
        return TrackLeftQuarterTurn5_Down25;
    case TrackElemType::RightQuarterTurn5TilesDown25:
        return TrackRightQuarterTurn5_Down25;
/*
    case TrackElemType::SBendLeft:
        return Tracks_bend_left;
    case TrackElemType::SBendRight:
        return Tracks_bend_right;
 */
    case TrackElemType::LeftQuarterTurn3Tiles:
        return TrackLeftQuarterTurn3;
    case TrackElemType::RightQuarterTurn3Tiles:
        return TrackRightQuarterTurn3;
    case TrackElemType::LeftBankedQuarterTurn3Tiles:
        return TrackLeftQuarterTurn3TilesBank;
    case TrackElemType::RightBankedQuarterTurn3Tiles:
        return TrackRightQuarterTurn3TilesBank;
    case TrackElemType::LeftQuarterTurn3TilesUp25:
        return TrackLeftQuarterTurn3TilesUp25;
    case TrackElemType::RightQuarterTurn3TilesUp25:
        return TrackRightQuarterTurn3TilesUp25;
    case TrackElemType::LeftQuarterTurn3TilesDown25:
        return TrackLeftQuarterTurn3TilesDown25;
    case TrackElemType::RightQuarterTurn3TilesDown25:
        return TrackRightQuarterTurn3TilesDown25;
    case TrackElemType::LeftHalfBankedHelixUpSmall:
        return TrackLeftHalfBankedHelixUpSmall;
    case TrackElemType::RightHalfBankedHelixUpSmall:
        return TrackRightHalfBankedHelixUpSmall;
    case TrackElemType::LeftHalfBankedHelixDownSmall:
        return TrackLeftHalfBankedHelixDownSmall;
    case TrackElemType::RightHalfBankedHelixDownSmall:
        return TrackRightHalfBankedHelixDownSmall;
    case TrackElemType::LeftHalfBankedHelixUpLarge:
        return TrackLeftHalfBankedHelixUpLarge;
    case TrackElemType::RightHalfBankedHelixUpLarge:
        return TrackRightHalfBankedHelixUpLarge;
    case TrackElemType::LeftHalfBankedHelixDownLarge:
        return TrackLeftHalfBankedHelixDownLarge;
    case TrackElemType::RightHalfBankedHelixDownLarge:
        return TrackRightHalfBankedHelixDownLarge;
    case TrackElemType::LeftQuarterTurn1TileUp60:
        return TrackLeftQuarterTurn1TileUp60;
    case TrackElemType::RightQuarterTurn1TileUp60:
        return TrackRightQuarterTurn1TileUp60;
    case TrackElemType::LeftQuarterTurn1TileDown60:
        return TrackLeftQuarterTurn1TileDown60;
    case TrackElemType::RightQuarterTurn1TileDown60:
        return TrackRightQuarterTurn1TileDown60;
/*
    case TrackElemType::Brakes:
        return Trackbrakes;
    case TrackElemType::Up25LeftBanked:
        return TrackUp25LeftBanked;
    case TrackElemType::Up25RightBanked:
        return TrackUp25RightBanked;
    case TrackElemType::OnRidePhoto:
        return Trackon_ride_photo;
    case TrackElemType::Down25LeftBanked:
        return TrackDown25LeftBanked;
    case TrackElemType::Down25RightBanked:
        return TrackDown25RightBanked;
    case TrackElemType::FlatToUp60LongBase:
        return TrackFlatToUp60long_base;
    case TrackElemType::Up60ToFlatLongBase:
        return TrackUp60ToFlat_long_base;
    case TrackElemType::FlatToDown60LongBase:
        return TrackFlatToDown60long_base;
    case TrackElemType::Down60ToFlatLongBase:
        return TrackDown60ToFlat_long_base;
*/
    case TrackElemType::LeftEighthToDiag:
        return TrackLeftEighthTodiag;
    case TrackElemType::RightEighthToDiag:
        return TrackRightEighthTodiag;
    case TrackElemType::LeftEighthToOrthogonal:
        return TrackLeftEighthToOrthogonal;
    case TrackElemType::RightEighthToOrthogonal:
        return TrackRightEighthToOrthogonal;
    case TrackElemType::LeftEighthBankToDiag:
        return TrackLeftEighthBankTodiag;
    case TrackElemType::RightEighthBankToDiag:
        return TrackRightEighthBankTodiag;
    case TrackElemType::LeftEighthBankToOrthogonal:
        return TrackLeftEighthBankToOrthogonal;
    case TrackElemType::RightEighthBankToOrthogonal:
        return TrackRightEighthBankToOrthogonal;
    case TrackElemType::DiagFlat:
        return TrackDiagFlat;
    case TrackElemType::DiagUp25:
        return TrackDiagUp25;
    case TrackElemType::DiagUp60:
        return TrackDiagUp60;
    case TrackElemType::DiagFlatToUp25:
        return TrackDiagFlatToUp25;
    case TrackElemType::DiagUp25ToUp60:
        return TrackDiagUp25ToUp60;
    case TrackElemType::DiagUp60ToUp25:
        return TrackDiagUp60ToUp25;
    case TrackElemType::DiagUp25ToFlat:
        return TrackDiagUp25ToFlat;
    case TrackElemType::DiagDown25:
        return TrackDiagDown25;
    case TrackElemType::DiagDown60:
        return TrackDiagDown60;
    case TrackElemType::DiagFlatToDown25:
        return TrackDiagFlatToDown25;
    case TrackElemType::DiagDown25ToDown60:
        return TrackDiagDown25ToDown60;
    case TrackElemType::DiagDown60ToDown25:
        return TrackDiagDown60ToDown25;
    case TrackElemType::DiagDown25ToFlat:
        return TrackDiagDown25ToFlat;
    case TrackElemType::DiagFlatToLeftBank:
        return TrackDiagFlatToLeftBank;
    case TrackElemType::DiagFlatToRightBank:
        return TrackDiagFlatToRightBank;
    case TrackElemType::DiagLeftBankToFlat:
        return TrackDiagLeftBankToFlat;
    case TrackElemType::DiagRightBankToFlat:
        return TrackDiagRightBankToFlat;
    case TrackElemType::DiagLeftBankToUp25:
        return TrackDiagLeftBankToUp25;
    case TrackElemType::DiagRightBankToUp25:
        return TrackDiagRightBankToUp25;
    case TrackElemType::DiagUp25ToLeftBank:
        return TrackDiagUp25ToLeftBank;
    case TrackElemType::DiagUp25ToRightBank:
        return TrackDiagUp25ToRightBank;
    case TrackElemType::DiagLeftBankToDown25:
        return TrackDiagLeftBankToDown25;
    case TrackElemType::DiagRightBankToDown25:
        return TrackDiagRightBankToDown25;
    case TrackElemType::DiagDown25ToLeftBank:
        return TrackDiagDown25ToLeftBank;
    case TrackElemType::DiagDown25ToRightBank:
        return TrackDiagDown25ToRightBank;
    case TrackElemType::DiagLeftBank:
        return TrackDiagLeftBank;
    case TrackElemType::DiagRightBank:
        return TrackDiagRightBank;
/*
    case TrackElemType::BlockBrakes:
        return Trackblock_brakes;
    case TrackElemType::LeftBankedQuarterTurn3TileUp25:
        return TrackLeftBankedQuarterTurn3TilesUp25;
    case TrackElemType::RightBankedQuarterTurn3TileUp25:
        return TrackRightBankedQuarterTurn3TilesUp25;
    case TrackElemType::LeftBankedQuarterTurn3TileDown25:
        return TrackLeftBankedQuarterTurn3TilesDown25;
    case TrackElemType::RightBankedQuarterTurn3TileDown25:
        return TrackRightBankedQuarterTurn3TilesDown25;
    case TrackElemType::LeftBankedQuarterTurn5TileUp25:
        return TrackLeftBankedQuarterTurn5_Up25;
    case TrackElemType::RightBankedQuarterTurn5TileUp25:
        return TrackRightBankedQuarterTurn5_Up25;
    case TrackElemType::LeftBankedQuarterTurn5TileDown25:
        return TrackLeftBankedQuarterTurn5_Down25;
    case TrackElemType::RightBankedQuarterTurn5TileDown25:
        return TrackRightBankedQuarterTurn5_Down25;
    case TrackElemType::Up25ToLeftBankedUp25:
        return TrackUp25ToLeftBankedUp25;
    case TrackElemType::Up25ToRightBankedUp25:
        return TrackUp25ToRightBankedUp25;
    case TrackElemType::LeftBankedUp25ToUp25:
        return TrackLeftBankedUp25ToUp25;
    case TrackElemType::RightBankedUp25ToUp25:
        return TrackRightBankedUp25ToUp25;
    case TrackElemType::Down25ToLeftBankedDown25:
        return TrackDown25ToLeftBankedDown25;
    case TrackElemType::Down25ToRightBankedDown25:
        return TrackDown25ToRightBankedDown25;
    case TrackElemType::LeftBankedDown25ToDown25:
        return TrackLeftBankedDown25ToDown25;
    case TrackElemType::RightBankedDown25ToDown25:
        return TrackRightBankedDown25ToDown25;
    case TrackElemType::LeftBankedFlatToLeftBankedUp25:
        return TrackLeftBankedFlatToLeftBankedUp25;
    case TrackElemType::RightBankedFlatToRightBankedUp25:
        return TrackRightBankedFlatToRightBankedUp25;
    case TrackElemType::LeftBankedUp25ToLeftBankedFlat:
        return TrackLeftBankedUp25ToLeftBankedFlat;
    case TrackElemType::RightBankedUp25ToRightBankedFlat:
        return TrackRightBankedUp25ToRightBankedFlat;
    case TrackElemType::LeftBankedFlatToLeftBankedDown25:
        return TrackLeftBankedFlatToLeftBankedDown25;
    case TrackElemType::RightBankedFlatToRightBankedDown25:
        return TrackRightBankedFlatToRightBankedDown25;
    case TrackElemType::LeftBankedDown25ToLeftBankedFlat:
        return TrackLeftBankedDown25ToLeftBankedFlat;
    case TrackElemType::RightBankedDown25ToRightBankedFlat:
        return TrackRightBankedDown25ToRightBankedFlat;
    case TrackElemType::FlatToLeftBankedUp25:
        return TrackFlatToLeftBankedUp25;
    case TrackElemType::FlatToRightBankedUp25:
        return TrackFlatToRightBankedUp25;
    case TrackElemType::LeftBankedUp25ToFlat:
        return TrackLeftBankedUp25ToFlat;
    case TrackElemType::RightBankedUp25ToFlat:
        return TrackRightBankedUp25ToFlat;
    case TrackElemType::FlatToLeftBankedDown25:
        return TrackFlatToLeftBankedDown25;
    case TrackElemType::FlatToRightBankedDown25:
        return TrackFlatToRightBankedDown25;
    case TrackElemType::LeftBankedDown25ToFlat:
        return TrackLeftBankedDown25ToFlat;
    case TrackElemType::RightBankedDown25ToFlat:
        return TrackRightBankedDown25ToFlat;
    case TrackElemType::LeftQuarterTurn1TileUp90:
        return TrackLeftQuarterTurn1TileUp90;
    case TrackElemType::RightQuarterTurn1TileUp90:
        return TrackRightQuarterTurn1TileUp90;
    case TrackElemType::LeftQuarterTurn1TileDown90:
        return TrackLeftQuarterTurn1TileDown90;
    case TrackElemType::RightQuarterTurn1TileDown90:
        return TrackRightQuarterTurn1TileDown90;
*/
    case TrackElemType::LeftTwistUpToDown:
        return TrackLeftTwistUpToDown;
    case TrackElemType::RightTwistUpToDown:
        return TrackRightTwistUpToDown;
    case TrackElemType::LeftTwistDownToUp:
        return TrackLeftTwistDownToUp;
    case TrackElemType::RightTwistDownToUp:
        return TrackRightTwistDownToUp;
    case TrackElemType::HalfLoopUp:
        return TrackHalfLoopUp;
    case TrackElemType::HalfLoopDown:
        return TrackHalfLoopDown;

/*
    case TrackElemType::LeftCorkscrewUp:
        return TrackLeftCorkscrewup;
    case TrackElemType::RightCorkscrewUp:
        return TrackRightCorkscrewup;
    case TrackElemType::LeftCorkscrewDown:
        return TrackLeftCorkscrewdown;
    case TrackElemType::RightCorkscrewDown:
        return TrackRightCorkscrewdown;
    case TrackElemType::Up90ToInvertedFlatQuarterLoop:
        return Track90DegToInvertedFlatQuarterLoopUp;
    case TrackElemType::InvertedFlatToDown90QuarterLoop:
        return TrackInvertedFlatTo90DegQuarterLoopDown;
    case TrackElemType::LeftBankToLeftQuarterTurn3TilesUp25:
        return TrackLeftBankToLeftQuarterTurn3TilesUp25;
    case TrackElemType::RightBankToRightQuarterTurn3TilesUp25:
        return TrackRightBankToRightQuarterTurn3TilesUp25;
    case TrackElemType::LeftQuarterTurn3TilesDown25ToLeftBank:
        return TrackLeftQuarterTurn3TilesDown25ToLeftBank;
    case TrackElemType::RightQuarterTurn3TilesDown25ToRightBank:
        return TrackRightQuarterTurn3TilesDown25ToRightBank;
    case TrackElemType::LeftLargeHalfLoopUp:
        return TrackLeftLargeHalfLoopUp;
    case TrackElemType::RightLargeHalfLoopUp:
        return TrackRightLargeHalfLoopUp;
    case TrackElemType::RightLargeHalfLoopDown:
        return TrackRightLargeHalfLoopDown;
    case TrackElemType::LeftLargeHalfLoopDown:
        return TrackLeftLargeHalfLoopDown;
    case TrackElemType::FlatToUp60:
        return TrackFlatToUp60;
    case TrackElemType::Up60ToFlat:
        return TrackUp60ToFlat;
    case TrackElemType::FlatToDown60:
        return TrackFlatToDown60;
    case TrackElemType::Down60ToFlat:
        return TrackDown60ToFlat;
    case TrackElemType::DiagFlatToUp60:
        return TrackDiagFlatToUp60;
    case TrackElemType::DiagUp60ToFlat:
        return TrackDiagUp60ToFlat;
    case TrackElemType::DiagFlatToDown60:
        return TrackDiagFlatToDown60;
    case TrackElemType::DiagDown60ToFlat:
        return TrackDiagDown60ToFlat;
    case TrackElemType::Booster:
        return Trackbooster;
*/
    }
    return nullptr;
}

}
