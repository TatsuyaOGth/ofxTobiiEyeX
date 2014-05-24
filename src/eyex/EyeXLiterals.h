/*********************************************************************************************************************
 * Copyright 2013-2014 Tobii Technology AB. All rights reserved.
 * EyeXLiterals.h
 *********************************************************************************************************************/

#if !defined(__TOBII_TX_LITERALS__H__)
#define __TOBII_TX_LITERALS__H__

/*********************************************************************************************************************
 * Literals
 *********************************************************************************************************************/

TX_CONSTANTS_BEGIN(Literals)

    /**
    *   Message Literals
    */
    TX_LITERALS_VALUE(TX_LITERAL_HEADER,          Header,         "Header");
    TX_LITERALS_VALUE(TX_LITERAL_BODY,            Body,           "Body");
    TX_LITERALS_VALUE(TX_LITERAL_ID,              Id,             "Id");
    TX_LITERALS_VALUE(TX_LITERAL_PROCESSID,       ProcessId,      "ProcessId");
    
    /**
    *    Client Literals
    */
    TX_LITERALS_VALUE(TX_LITERAL_AGENTID,         AgentId,         "AgentId");
    TX_LITERALS_VALUE(TX_LITERAL_TARGETPROCESSID, TargetProcessId, "TargetProcessId");
    
    /**
    *   Miscellaneous Literals
    */
	TX_LITERALS_VALUE(TX_LITERAL_TYPE,		Type,		"Type");
    TX_LITERALS_VALUE(TX_LITERAL_TIMESTAMP, Timestamp,	"Timestamp");
    TX_LITERALS_VALUE(TX_LITERAL_DATA,      Data,		"Data");
    TX_LITERALS_VALUE(TX_LITERAL_X,         X,			"X");
    TX_LITERALS_VALUE(TX_LITERAL_Y,         Y,			"Y");
    TX_LITERALS_VALUE(TX_LITERAL_Z,         Z,			"Z");
    
    /**
    *   Bounds Literals
    */
    TX_LITERALS_VALUE(TX_LITERAL_BOUNDS,      Bounds,      "Bounds");
    TX_LITERALS_VALUE(TX_LITERAL_BOUNDSTYPE,  BoundsType,  "BoundsType");
    TX_LITERALS_VALUE(TX_LITERAL_NONE,        None,        "None");    
    TX_LITERALS_VALUE(TX_LITERAL_RECTANGULAR, Rectangular, "Rectangular");
    TX_LITERALS_VALUE(TX_LITERAL_TOP,         Top,         "Top");
    TX_LITERALS_VALUE(TX_LITERAL_LEFT,        Left,        "Left");
    TX_LITERALS_VALUE(TX_LITERAL_RIGHT,       Right,       "Right");
    TX_LITERALS_VALUE(TX_LITERAL_BOTTOM,      Bottom,      "Bottom");
    TX_LITERALS_VALUE(TX_LITERAL_WIDTH,       Width,       "Width");
    TX_LITERALS_VALUE(TX_LITERAL_HEIGHT,      Height,      "Height");
    
    /**
    *   Interactor Literals
    */
    TX_LITERALS_VALUE(TX_LITERAL_ROOTID,       RootId,       "RootId");
    TX_LITERALS_VALUE(TX_LITERAL_GLOBALINTERACTORWINDOWID, GlobalInteractorWindowId, "GlobalInteractorWindowId");
    TX_LITERALS_VALUE(TX_LITERAL_MASK,        Mask,        "Mask");
    TX_LITERALS_VALUE(TX_LITERAL_MASKID,      MaskId,      "MaskId");
    TX_LITERALS_VALUE(TX_LITERAL_MASKBOUNDS,  MaskBounds,  "MaskBounds");
        
    /**
    *   Mask Literals
    */
    TX_LITERALS_VALUE(TX_LITERAL_MASKTYPE,    MaskType,       "MaskType");
    TX_LITERALS_VALUE(TX_LITERAL_ROWCOUNT,    RowCount,       "RowCount");
    TX_LITERALS_VALUE(TX_LITERAL_COLUMNCOUNT, ColumnCount, "ColumnCount");
    
    /**
    * Gaze Point Data Behavior Literals
    */
    TX_LITERALS_VALUE(TX_LITERAL_GAZEPOINTDATAMODE, GazePointDataMode, "GazePointDataMode");
    TX_LITERALS_VALUE(TX_LITERAL_GAZEPOINTDATAEVENTTYPE, GazePointDataEventType, "GazePointDataEventType");
    
    /**
    *    Activation Behavior Literals
    */
    TX_LITERALS_VALUE(TX_LITERAL_ACTIVATABLEEVENTTYPE,        ActivatableEventType,        "ActivatableEventType");
    TX_LITERALS_VALUE(TX_LITERAL_HASACTIVATIONFOCUS,          HasActivationFocus,          "HasActivationFocus");    
    TX_LITERALS_VALUE(TX_LITERAL_HASTENTATIVEACTIVATIONFOCUS, HasTentativeActivationFocus, "HasTentativeActivationFocus");
    TX_LITERALS_VALUE(TX_LITERAL_ISACTIVATED,                 IsActivated,                 "IsActivated");
    TX_LITERALS_VALUE(TX_LITERAL_ISTENTATIVEFOCUS,            IsTentativeFocusEnabled,     "IsTentativeFocusEnabled");

    /**
    * Fixation Data Behavior Literals
    */
    TX_LITERALS_VALUE(TX_LITERAL_FIXATIONDATAMODE, FixationDataMode, "FixationDataMode");
    TX_LITERALS_VALUE(TX_LITERAL_FIXATIONDATAEVENTTYPE, FixationDataEventType, "FixationDataEventType");

    /**
    * Action data Behavior Literals 
    */
    TX_LITERALS_VALUE(TX_LITERAL_ACTIONDATAEVENTTYPE, ActionDataEventType, "ActionDataEventType");
    TX_LITERALS_VALUE(TX_LITERAL_ACTIVATIONMISSED, ActivationMissed, "ActivationMissed");
    
    /**
    * Gaze-Aware Behavior Literals
    */
    TX_LITERALS_VALUE(TX_LITERAL_HASGAZE,        HasGaze,  "HasGaze");
    TX_LITERALS_VALUE(TX_LITERAL_GAZEAWAREMODE,  GazeAwareMode,  "GazeAwareMode");
    TX_LITERALS_VALUE(TX_LITERAL_DELAYTIME,      DelayTime,  "DelayTime");
    
    /**
    * Gaze Data Diagnostics Behavior Literals
    */
    TX_LITERALS_VALUE(TX_LITERAL_QUALITY,    Quality,    "Quality");    
    TX_LITERALS_VALUE(TX_LITERAL_NOISE,      Noise,      "Noise");
    TX_LITERALS_VALUE(TX_LITERAL_INSACCADE,  InSaccade,  "InSaccade");
    TX_LITERALS_VALUE(TX_LITERAL_INFIXATION, InFixation, "InFixation");
    
    /**
    * Eye Position Behavior Literals
    */
    TX_LITERALS_VALUE(TX_LITERAL_LEFTEYEPOSITION,     LeftEyePosition,     "LeftEyePosition");    
    TX_LITERALS_VALUE(TX_LITERAL_RIGHTEYEPOSITION,    RightEyePosition,    "RightEyePosition");
    TX_LITERALS_VALUE(TX_LITERAL_HASLEFTEYEPOSITION,  HasLeftEyePosition,  "HasLeftEyePosition");
    TX_LITERALS_VALUE(TX_LITERAL_HASRIGHTEYEPOSITION, HasRightEyePosition, "HasRightEyePosition");

    /**
    * Presence Behavior Literals
    */
    TX_LITERALS_VALUE(TX_LITERAL_PRESENCEDATA, Presence, "Presence");


    /**
    * Pannable Behavior Literals
    */
    TX_LITERALS_VALUE(TX_LITERAL_PANVELOCITYX,               PanVelocityX,            "PanVelocityX");
    TX_LITERALS_VALUE(TX_LITERAL_PANVELOCITYY,               PanVelocityY,            "PanVelocityY");
    TX_LITERALS_VALUE(TX_LITERAL_PANSTEPX,                   PanStepX,                "PanStepX");
    TX_LITERALS_VALUE(TX_LITERAL_PANSTEPY,                   PanStepY,                "PanStepY");
    TX_LITERALS_VALUE(TX_LITERAL_PANSTEPDURATION,            PanStepDuration,         "PanStepDuration");
    TX_LITERALS_VALUE(TX_LITERAL_PANHANDSFREE,               PanHandsFree,            "PanHandsFree");
    TX_LITERALS_VALUE(TX_LITERAL_PANPROFILE,                 PanningProfile,          "Profile");
    TX_LITERALS_VALUE(TX_LITERAL_PANDIRECTIONSAVAILABLE,     PanDirectionsAvailable,  "PanDirectionsAvailable");
    TX_LITERALS_VALUE(TX_LITERAL_PANPEAKVELOCITY,            PeakVelocity,            "PeakVelocity");
    TX_LITERALS_VALUE(TX_LITERAL_PANADAPTVELOCITYTOVIEWPORT, AdaptVelocityToViewport, "AdaptVelocityToViewport");
    TX_LITERALS_VALUE(TX_LITERAL_PANMAXZONERELATIVESIZE,     MaxPanZoneRelativeSize,  "MaxPanZoneRelativeSize");
    TX_LITERALS_VALUE(TX_LITERAL_PANMAXZONESIZE,             MaxPanZoneSize,          "MaxPanZoneSize");
    TX_LITERALS_VALUE(TX_LITERAL_PANZONESIZE,                PanZoneSize,             "PanZoneSize");
    TX_LITERALS_VALUE(TX_LITERAL_PANNABLEEVENTTYPE,          PannableEventType,       "PannableEventType");

    /**
    *   Callback Response Literals
    */
    TX_LITERALS_VALUE(TX_LITERAL_REQUESTID,          RequestId,         "RequestId");
    TX_LITERALS_VALUE(TX_LITERAL_ERRORMESSAGE,       ErrorMessage,      "ErrorMessage");
    TX_LITERALS_VALUE(TX_LITERAL_RESULT,             Result,            "Result");

    /**
    *   Interaction Mode Literals
    */
    TX_LITERALS_VALUE(TX_LITERAL_ACTIONTYPE,          ActionType,                    "ActionType");    

    /**
    *   State literals
    */
    TX_LITERALS_VALUE(TX_LITERAL_STATEPATH,              StatePath,           "StatePath");
    TX_LITERALS_VALUE(TX_LITERAL_STATEPATHDELIMITER,     StatePathDelimiter,  ".");

    /**
    *  Version literals
    */
    TX_LITERALS_VALUE(TX_LITERAL_VERSIONMAJOR,              VersionMajor,           "VersionMajor");
    TX_LITERALS_VALUE(TX_LITERAL_VERSIONMINOR,              VersionMinor,           "VersionMinor");
    TX_LITERALS_VALUE(TX_LITERAL_VERSIONBUILD,              VersionBuild,           "VersionBuild");


TX_CONSTANTS_END

/*********************************************************************************************************************/

/**
 * Literals for state paths.
 * 
 * @field TX_STATEPATH_EYETRACKING:
 *   The root node for all eyetracking information.
 *   GETTABLE.
 *
 * @field TX_STATEPATH_SCREENBOUNDS:
 *   Holds the virtual screen bounds in pixels. 
 *   The value can be retrieved from the state bag as a TX_RECT structure with GetStateValueAsRectangle.
 *   If the screen bounds can not be determined screen bounds (0, 0, 0, 0) will be returned.
 *   GETTABLE.
 *
 * @field TX_STATEPATH_DISPLAYSIZE:
 *   Holds the display size in millimeters as width and height. 
 *   The value can be retrieved from the state bag as a TX_SIZE2 structure with GetStateValueAsSize2.
 *   If the display size can not be determined Width and Height (0, 0) will be returned.
 *   GETTABLE.
 *
 * @field TX_STATEPATH_STATE: 
 *   Holds the eyetracking status. The value is of type TX_EYETRACKINGDEVICESTATUS.
 *   GETTABLE.
 *
 * @field TX_STATEPATH_PRESENCEDATA:
 *   Holds data about user presence. The value is of type TX_PRESENCEDATA.
 *   GETTABLE.
 *
 * @field TX_STATEPATH_ACTIONDATA:
 *   Pulses data when interactions fails. The value is of type TX_ACTIONDATA.
 *   GETTABLE.
 */
TX_CONSTANTS_BEGIN(StatePaths)    
    TX_LITERALS_VALUE(TX_STATEPATH_EYETRACKING,      EyeTracking,    "eyetracking")
    TX_LITERALS_VALUE(TX_STATEPATH_SCREENBOUNDS,     ScreenBounds,   "eyetracking.screenBounds")
    TX_LITERALS_VALUE(TX_STATEPATH_DISPLAYSIZE,      DisplaySize,    "eyetracking.displaySize")
    TX_LITERALS_VALUE(TX_STATEPATH_STATE,            State,          "eyetracking.state")
    TX_LITERALS_VALUE(TX_STATEPATH_PRESENCEDATA,     PresenceData,   "presenceData")
    TX_LITERALS_VALUE(TX_STATEPATH_ACTIONDATA,       ActionData,     "actionData")
TX_CONSTANTS_END

/*********************************************************************************************************************/

/**
 * Constants for mask weights.
 *
 * @field TX_MASKWEIGHT_NONE:
 *	Use this mask weight to indicate that a region of an interactor has no weight (not interactable).
 *
 * @field TX_MASKWEIGHT_DEFAULT:
 *  Use this mask weight to indicate that a region of an interactor has a default weight.
 
 * @field TX_MASKWEIGHT_HIGH:
 *  Use this mask weight to indicate that a region of an interactor has a high weight (more likely to be interacted with).
 */
TX_CONSTANTS_BEGIN(MaskWeights)
	TX_CONSTANT_BYTE_VALUE(TX_MASKWEIGHT_NONE, None, 0)
	TX_CONSTANT_BYTE_VALUE(TX_MASKWEIGHT_DEFAULT, Default, 1)
	TX_CONSTANT_BYTE_VALUE(TX_MASKWEIGHT_HIGH, High, 255)
TX_CONSTANTS_END
    
/*********************************************************************************************************************/

#endif /* !defined(__TOBII_TX_LITERALS__H__) */

/*********************************************************************************************************************/
