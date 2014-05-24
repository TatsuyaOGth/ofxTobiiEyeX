/*********************************************************************************************************************
 * Copyright 2013-2014 Tobii Technology AB. All rights reserved.
 * EyeXInternalLiterals.h
 *********************************************************************************************************************/

#if !defined(__TOBII_TX_INTERNALLITERALS__H__)
#define __TOBII_TX_INTERNALLITERALS__H__


/*********************************************************************************************************************
 * Literals
 *********************************************************************************************************************/

TX_CONSTANTS_BEGIN(InternalLiterals)

    TX_LITERALS_VALUE(TX_INTERNALLITERAL_INTERACTORS,     Interactors,    "Interactors");
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_METADATA,        Metadata,       "Metadata");
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_SERIALNUMBER,    SerialNumber,   "SerialNumber");


    /**
    *   Message Type Literals
    */
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_MESSAGETYPE, MessageType, "MessageType");


    /**
    *   Snapshot internal literals
    */
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_NONAUTHORITATIVEWINDOWIDS, NonAuthoritativeWindowIds, "NonAuthoritativeWindowIds");


    /**
    *   Snapshot Literals
    */
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_WINDOWIDS,   WindowIds,    "WindowIds");


    /**
    *   Interactor Literals
    */
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_BEHAVIORS,    Behaviors,    "Behaviors");
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_BEHAVIORTYPE, BehaviorType, "BehaviorType");
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_PARENTID,     ParentId,     "ParentId");
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_INTERACTORID, InteractorId, "InteractorId");
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_ISENABLED,    IsEnabled,    "IsEnabled");
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_ISDELETED,    IsDeleted,    "IsDeleted");
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_WINDOWID,     WindowId,     "WindowId");

    /**
    *   Command Literals
    */
    TX_LITERALS_VALUE(TX_LITERAL_COMMANDTYPE, CommandType, "CommandType");


    /**
    *   Callback Response Literals
    */
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_NOTIFICATIONTYPE,   NotificationType,  "NotificationType");    
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_ISCANCELLED,        IsCancelled,       "IsCancelled");

/*********************************************************************************************************************/


    /**
    *    State literals
    */    
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_STATEPATH,  StatePath,  "StatePath");

    /**
    *  Termination Literals
    */
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_TERMINATEGXWINDOWS, TerminateGxWindows, "TerminateGxWindows");
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_GLOBALTERMINATEGXSERVER, TerminateGxServer, "Global\\TerminateGxServer");
    

   /**
    *   Internal Raw Gaze Data Literals
    **/
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_EYEPOSITIONFROMSCREENCENTERMM,   EyePositionFromScreenCenterMM,   "EyePositionFromScreenCenterMM");
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_EYEPOSITIONINTRACKBOXNORMALIZED, EyePositionInTrackBoxNormalized, "EyePositionInTrackBoxNormalized");
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_GAZEPOINTFROMSCREENCENTERMM,     GazePointFromScreenCenterMM,      "GazePointFromScreenCenterMM");
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_GAZEPOINTONDISPLAYNORMALIZED,    GazePointOnDisplayNormalized,    "GazePointOnDisplayNormalized");
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_BOTTOMLEFT,                      BottomLeft,                      "BottomLeft");
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_TOPLEFT,                         TopLeft,                         "TopLeft");
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_TOPRIGHT,                        TopRight,                        "TopRight");
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_SCREENBOUNDSMM,                  ScreenBoundsMm,                  "ScreenBoundsMm");
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_SCREENBOUNDSPIXELS,              ScreenBoundsPixels,              "ScreenBoundsPixels");
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_TRACKEDEYES,                     TrackedEyes,                     "TrackedEyes");    
    //these below could be in an enum, but wont be, since its an internal stream
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_TRACKEDEYESNONE,                 TrackedEyesNone,                 "TrackedEyesNone");
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_TRACKEDEYESBOTH,                 TrackedEyesBoth,                 "TrackedEyesBoth");
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_TRACKEDEYESLEFT,                 TrackedEyesLeft,                 "TrackedEyesLeft");
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_TRACKEDEYESRIGHT,                TrackedEyesRight,                "TrackedEyesRight");

    TX_LITERALS_VALUE(TX_INTERNALLITERAL_DETECTEDEYES,                    DetectedEyes,                    "DetectedEyes");
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_DETECTEDEYESNONE,                DetectedEyesNone,                "DetectedEyesNone");
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_DETECTEDEYESBOTH,                DetectedEyesBoth,                "DetectedEyesBoth");
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_DETECTEDEYESLEFT,                DetectedEyesLeft,                "DetectedEyesLeft");
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_DETECTEDEYESRIGHT,               DetectedEyesRight,               "DetectedEyesRight");

   /**
    *   Internal Zoom Literals
    **/
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_ZOOMDIRECTION,   ZoomDirection,    "ZoomDirection");
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_ZOOMGAZEPOINTX,  ZoomGazePointX,   "ZoomGazePointX");
    TX_LITERALS_VALUE(TX_INTERNALLITERAL_ZOOMGAZEPOINTY,  ZoomGazePointY,   "ZoomGazePointY");



TX_CONSTANTS_END
    
/*********************************************************************************************************************/

#endif /* !defined(__TOBII_TX_INTERNALLITERALS__H__) */

/*********************************************************************************************************************/
