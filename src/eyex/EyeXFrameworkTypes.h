/*********************************************************************************************************************
 * Copyright 2013-2014 Tobii Technology AB. All rights reserved.
 * EyeXFrameworkTypes.h
 *********************************************************************************************************************/

#if !defined(__TOBII_TX_FRAMEWORK_TYPES__H__)
#define __TOBII_TX_FRAMEWORK_TYPES__H__

/*********************************************************************************************************************/

#include "EyeXMacros.h"

/*********************************************************************************************************************/

/**
  TX_RESULT

  Enumeration for all result codes returned by the API functions.

  @field TX_RESULT_UNKNOWN:
    Unknown error, typically returned if something unexpected occurs in the API. Is most likely a bug in the API.

  @field TX_RESULT_OK:
    Everything went well.

  @field TX_RESULT_SYSTEMNOTINITIALIZED:
    The system is not initalized. All API functions except txInitializeSystem requires the system to be
    initialized prior to being called.

  @field TX_RESULT_SYSTEMALREADYINITIALIZED:
    The system has already been initialized. This is returned by txInitializeSystem if called twice without being
    uninitialized in between.

  @field TX_RESULT_SYSTEMSTILLINUSE:
    The system is still in use. This is returned by txUninitializeSystem if at least one context is still being used.

  @field TX_RESULT_INVALIDARGUMENT:
    An invalid argument was passed to an API function. All arguments are checked before an API function actually
    does something. There are many reasons why an argument can be considered invalid. 
    Check the log for more details if this code is returned.
    
  @field TX_RESULT_INVALIDHANDLE:
    The handle for an interaction object is not valid.
    
  @field TX_RESULT_NOTFOUND:
    Generic result code when something could not be found.
    
  @field TX_RESULT_INVALIDBUFFERSIZE:
    Some buffer; string, array, etc had an invalid size. Typically, API functions that return this result code also
    provides the required size.
    
  @field TX_RESULT_DUPLICATEPROPERTY:
    An attempt has been made to create a property that does already exist.
    
  @field TX_RESULT_DUPLICATEBOUNDS:
    An attempt has been made to create bounds that already exists.
    
  @field TX_RESULT_DUPLICATEBEHAVIOR:
    An attempt has been made to create a behavior that already exists.
    
  @field TX_RESULT_DUPLICATEINTERACTOR:
    An attempt has been made to create an interactor with the same id as another in the same snapshot.
    
  @field TX_RESULT_DUPLICATESTATEOBSERVER:
    An attempt has been made to register the same state observer twice.
	
  @field TX_RESULT_DUPLICATEMASK:
    An attempt has been made to create more than one mask on an interactor.
    
  @field TX_RESULT_INVALIDPROPERTYTYPE:
    A type specific operation has been made on a property of a different type. For example a property containing a 
    TX_INTEGER has been requested for its value as a TX_STRING.
    
  @field TX_RESULT_INVALIDPROPERTYNAME:
    The specified property name is invalid.
    
  @field TX_RESULT_PROPERTYNOTREMOVABLE:
    An attempt has been made to remove a property that is not removable. Typically such properties are the ones
    backing up data that is required on different interaction objects.
    
  @field TX_RESULT_NOTCONNECTED:
    An attempt was made to perform an operation that requires a valid connection to the server.

  @field TX_RESULT_INVALIDOBJECTCAST:
    A handle for a different type of interaction object than expected was provided.
    
  @field TX_RESULT_INVALIDTHREAD:
    An attempt was made to perform an operation on a thread that is not allowed to perform such an operation.
    For example a context can not be deleted on a callback from the API.
        
  @field TX_RESULT_INVALIDBOUNDSTYPE:
    An attempt was made to perform an operation that does not apply to the current bounds type.
    
  @field TX_RESULT_INVALIDBEHAVIORTYPE:
    An attempt was made to perform an operation that does not apply to the current behavior type.
    
  @field TX_RESULT_OBJECTLEAKAGE:
    A leakage of an interaction object has been detected. May be returned by txReleaseContext if not all objects has been released properly.
    
  @field TX_RESULT_OBJECTTRACKINGNOTENABLED:
    An attempt to retrieve tracked object has been made without tracking of objects being enabled.
	
  @field TX_RESULT_INVALIDSNAPSHOT:
    The snapshot committed to the server contained some invalid data.

  @field TX_RESULT_INVALIDCOMMAND:
    The submitted command was malformed or not recognized by the server.

  @field TX_RESULT_CANCELLED:
    An attempt has been made to perform an operation that is not supported during shutdown. 
	
  @field TX_RESULT_INVALIDSCHEDULINGMODE:
    The scheduling mode is invalid.
 */
TX_BEGIN_ENUM(ResultCode)
    TX_ENUM_VALUE(TX_RESULT_UNKNOWN,                    Unknown) = TX_ENUM_STARTVALUE,
    TX_ENUM_VALUE(TX_RESULT_OK,                         Ok),
    TX_ENUM_VALUE(TX_RESULT_SYSTEMNOTINITIALIZED,       SystemNotInitialized),
    TX_ENUM_VALUE(TX_RESULT_SYSTEMALREADYINITIALIZED,   SystemAlreadyInitialized),
    TX_ENUM_VALUE(TX_RESULT_SYSTEMSTILLINUSE,           SystemStillInUse),
    TX_ENUM_VALUE(TX_RESULT_INVALIDARGUMENT,            InvalidArgument),   
    TX_ENUM_VALUE(TX_RESULT_INVALIDHANDLE,              InvalidHandle),
    TX_ENUM_VALUE(TX_RESULT_NOTFOUND,                   NotFound),
    TX_ENUM_VALUE(TX_RESULT_INVALIDBUFFERSIZE,          InvalidBufferSize),
    TX_ENUM_VALUE(TX_RESULT_DUPLICATEPROPERTY,          DuplicateProperty),
    TX_ENUM_VALUE(TX_RESULT_DUPLICATEBOUNDS,            DuplicateBounds),
    TX_ENUM_VALUE(TX_RESULT_DUPLICATEBEHAVIOR,          DuplicateBehavior),
    TX_ENUM_VALUE(TX_RESULT_DUPLICATEINTERACTOR,        DuplicateInteractor),
    TX_ENUM_VALUE(TX_RESULT_DUPLICATESTATEOBSERVER,     DuplicateStateObserver),
	TX_ENUM_VALUE(TX_RESULT_DUPLICATEMASK,				DuplicateMask),
    TX_ENUM_VALUE(TX_RESULT_INVALIDPROPERTYTYPE,        InvalidPropertyType),
    TX_ENUM_VALUE(TX_RESULT_INVALIDPROPERTYNAME,        InvalidPropertyName),
    TX_ENUM_VALUE(TX_RESULT_PROPERTYNOTREMOVABLE,       PropertyNotRemovable),
    TX_ENUM_VALUE(TX_RESULT_NOTCONNECTED,               NotConnected),
    TX_ENUM_VALUE(TX_RESULT_INVALIDOBJECTCAST,          InvalidObjectCast),
    TX_ENUM_VALUE(TX_RESULT_INVALIDTHREAD,              InvalidThread),
    TX_ENUM_VALUE(TX_RESULT_INVALIDBOUNDSTYPE,          InvalidBoundsType),
    TX_ENUM_VALUE(TX_RESULT_INVALIDBEHAVIORTYPE,        InvalidBehaviorType),
    TX_ENUM_VALUE(TX_RESULT_OBJECTLEAKAGE,              ObjectLeakage),
    TX_ENUM_VALUE(TX_RESULT_OBJECTTRACKINGNOTENABLED,   ObjectTrackingNotEnabled),
    TX_ENUM_VALUE(TX_RESULT_INVALIDSNAPSHOT,            InvalidSnapshot),
    TX_ENUM_VALUE(TX_RESULT_INVALIDCOMMAND,             InvalidCommand),
    TX_ENUM_VALUE(TX_RESULT_CANCELLED,                  Cancelled),
    TX_ENUM_VALUE(TX_RESULT_INVALIDSCHEDULINGMODE,      InvalidSchedulingMode)
TX_END_ENUM(TX_RESULT, ResultCode)

/*********************************************************************************************************************
 * Interaction Object Types
 *********************************************************************************************************************/

/**
  Enumeration for all the types of interaction objects that can be exposed through the API.

  @field TX_INTERACTIONOBJECTTYPE_SNAPSHOT:
    The object is a snapshot.

  @field TX_INTERACTIONOBJECTTYPE_INTERACTOR:
    The object is an interactor.
    
  @field TX_INTERACTIONOBJECTTYPE_QUERY:
    The object is a query.

  @field TX_INTERACTIONOBJECTTYPE_EVENT:
    The object is an event.

  @field TX_INTERACTIONOBJECTTYPE_BEHAVIOR:
    The object is a behavior.
        
  @field TX_INTERACTIONOBJECTTYPE_BOUNDS:
    The object is a bounds structure.

  @field TX_INTERACTIONOBJECTTYPE_PROPERTYBAG:
    The object is a property bag.

  @field TX_INTERACTIONOBJECTTYPE_PROPERTY:
    The object is a property.
    
  @field TX_INTERACTIONOBJECTTYPE_COMMAND:
    The object is a command.
        
  @field TX_INTERACTIONOBJECTTYPE_STATEBAG:
    The object is a state bag.
    
  @field TX_INTERACTIONOBJECTTYPE_NOTIFICATION:
    The object is a notification.
        
  @field TX_INTERACTIONOBJECTTYPE_MASK:
    The object is a mask.
 */
TX_BEGIN_ENUM(InteractionObjectType)
    TX_ENUM_VALUE(TX_INTERACTIONOBJECTTYPE_SNAPSHOT,       Snapshot) = TX_ENUM_STARTVALUE, 
    TX_ENUM_VALUE(TX_INTERACTIONOBJECTTYPE_INTERACTOR,     Interactor),
    TX_ENUM_VALUE(TX_INTERACTIONOBJECTTYPE_QUERY,          Query),
    TX_ENUM_VALUE(TX_INTERACTIONOBJECTTYPE_EVENT,          Event),
    TX_ENUM_VALUE(TX_INTERACTIONOBJECTTYPE_BEHAVIOR,       Behavior),
    TX_ENUM_VALUE(TX_INTERACTIONOBJECTTYPE_BOUNDS,         Bounds),
    TX_ENUM_VALUE(TX_INTERACTIONOBJECTTYPE_PROPERTYBAG,    PropertyBag),
    TX_ENUM_VALUE(TX_INTERACTIONOBJECTTYPE_COMMAND,        Command),    
    TX_ENUM_VALUE(TX_INTERACTIONOBJECTTYPE_STATEBAG,       StateBag),
    TX_ENUM_VALUE(TX_INTERACTIONOBJECTTYPE_NOTIFICATION,   Notification),
    TX_ENUM_VALUE(TX_INTERACTIONOBJECTTYPE_MASK,           Mask),
    TX_ENUM_VALUE(TX_INTERACTIONOBJECTTYPE_ASYNCDATA,      AsyncData),

    /* for internal use only */
    TX_ENUM_VALUE(TX_INTERACTIONOBJECTTYPE_INTERNAL_MESSAGE,       Internal_Message) = TX_INTERNAL_ENUM_STARTVALUE,
    TX_ENUM_VALUE(TX_INTERACTIONOBJECTTYPE_INTERNAL_MESSAGEHEADER, Internal_MessageHeader)  
TX_END_ENUM(TX_INTERACTIONOBJECTTYPE, InteractionObjectType)

/*********************************************************************************************************************/

/**
  TX_MESSAGETYPE

  Enumeration for all message types.
  The messages type is metadata contained by all packets sent between the client and server. 
  Some messages should be handled by the application to do proper interaction, others are internal and should be
  ignored.
    
  @field TX_MESSAGETYPE_QUERY:
    Message contains a query.
    
  @field TX_MESSAGETYPE_EVENT:
    Message contains an event.
    
  @field TX_MESSAGETYPE_NOTIFICATION:
    Message contains a notification.
    
  @field TX_MESSAGETYPE_REQUEST:
    Message contains a request.
    
  @field TX_MESSAGETYPE_RESPONSE:
    Message contains a response.
 */
TX_BEGIN_ENUM(MessageType)
    TX_ENUM_VALUE(TX_MESSAGETYPE_QUERY,        Query) = TX_ENUM_STARTVALUE,
    TX_ENUM_VALUE(TX_MESSAGETYPE_EVENT,        Event),
    TX_ENUM_VALUE(TX_MESSAGETYPE_NOTIFICATION, Notification),
    TX_ENUM_VALUE(TX_MESSAGETYPE_REQUEST,      Request),
    TX_ENUM_VALUE(TX_MESSAGETYPE_RESPONSE,     Response)
TX_END_ENUM(TX_MESSAGETYPE, MessageType)

/*********************************************************************************************************************/

/**
  TX_NOTIFICATIONTYPE

  Enumeration for all notification types.
  The notification type is metadata contained by all notifications to specify what kind of notification it is.

  @field TX_NOTIFICATIONTYPE_STATECHANGED:
    Notifies that some states have changed.
 */
TX_BEGIN_ENUM(NotificationType)    
    TX_ENUM_VALUE(TX_NOTIFICATIONTYPE_STATECHANGED, StateChanged) = TX_ENUM_STARTVALUE
TX_END_ENUM(TX_NOTIFICATIONTYPE, NotificationType)

/*********************************************************************************************************************/

/**
  TX_INTERACTIONBEHAVIORTYPE
 
  Enumeration for all behavior types.
  The behavior type is metadata contained by all behaviors to specify what kind of behavior it is.

  @field TX_INTERACTIONBEHAVIORTYPE_GAZEPOINTDATA:
    Behavior used on interactors to receive gaze point data.

  @field TX_INTERACTIONBEHAVIORTYPE_GAZEDATADIAGNOSTICS:
    Behavior used on interactors to receive gaze data diagnostics.

  @field TX_INTERACTIONBEHAVIORTYPE_EYEPOSITIONDATA:
    Behavior used on interactors to receive eye position data.
    
  @field TX_INTERACTIONBEHAVIORTYPE_GAZEAWARE:
    Behavior used on interactors to perform gaze-aware interaction.

  @field TX_INTERACTIONBEHAVIORTYPE_ACTIVATABLE:
    Behavior used on interactors to perform activation interaction.

  @field TX_INTERACTIONBEHAVIORTYPE_PANNABLE:
    Behavior used on interactors to perform panning interaction.  

  @field TX_INTERACTIONBEHAVIORTYPE_FIXATIONDATA:
    Behavior used on interactors to receive fixation data.

  @field TX_INTERACTIONBEHAVIORTYPE_PRESENCEDATA:
    Behavior used on interactors to receive presence data.
 */
TX_BEGIN_ENUM(InteractionBehaviorType)
    TX_ENUM_VALUE(TX_INTERACTIONBEHAVIORTYPE_GAZEPOINTDATA,                         GazePointData) = TX_ENUM_STARTVALUE,
    TX_ENUM_VALUE(TX_INTERACTIONBEHAVIORTYPE_GAZEDATADIAGNOSTICS,                   GazeDataDiagnostics),    
    TX_ENUM_VALUE(TX_INTERACTIONBEHAVIORTYPE_EYEPOSITIONDATA,                       EyePositionData),
    TX_ENUM_VALUE(TX_INTERACTIONBEHAVIORTYPE_GAZEAWARE,                             GazeAware),
    TX_ENUM_VALUE(TX_INTERACTIONBEHAVIORTYPE_ACTIVATABLE,                           Activatable),
    TX_ENUM_VALUE(TX_INTERACTIONBEHAVIORTYPE_PANNABLE,                              Pannable),    
    TX_ENUM_VALUE(TX_INTERACTIONBEHAVIORTYPE_FIXATIONDATA,                          FixationData),
 /* For Internal use */
    TX_ENUM_VALUE(TX_INTERNAL_INTERACTIONBEHAVIORTYPE_RAWGAZEDATA,                  Internal_RawGazeData),
    TX_ENUM_VALUE(TX_INTERNAL_INTERACTIONBEHAVIORTYPE_ZOOMABLE,                     Internal_Zoomable)
TX_END_ENUM(TX_INTERACTIONBEHAVIORTYPE, InteractionBehaviorType)

/*********************************************************************************************************************/

/**
  TX_INTERACTIONBOUNDSTYPE

  Enumeration for all bounds types.

  @field TX_INTERACTIONBOUNDSTYPE_NONE:
    No bounds.

  @field TX_INTERACTIONBOUNDSTYPE_RECTANGULAR:    
    Rectangular bounds.
 */
TX_BEGIN_ENUM(InteractionBoundsType)
    TX_ENUM_VALUE(TX_INTERACTIONBOUNDSTYPE_NONE,         None) = TX_ENUM_STARTVALUE,
    TX_ENUM_VALUE(TX_INTERACTIONBOUNDSTYPE_RECTANGULAR, Rectangular)
TX_END_ENUM(TX_INTERACTIONBOUNDSTYPE, InteractionBoundsType)

/*********************************************************************************************************************/

/**
  TX_ACTIVATABLEEVENTTYPE

  Enumeration for all activation event types.
  Activatable event type are metadata contained by all behaviors of type TX_INTERACTIONBEHAVIORTYPE_ACTIVATABLE sent
  from the server. This event type specifies what kind of activation event actually happened.
  
  @field TX_ACTIVATABLEEVENTTYPE_ACTIVATED:
    The interactor has been activated.

  @field TX_ACTIVATABLEEVENTTYPE_ACTIVATIONFOCUSCHANGED:
    The activation focus and/or tentative activation focus has changed.
 */
TX_BEGIN_ENUM(ActivatableEventType)    
    TX_ENUM_VALUE(TX_ACTIVATABLEEVENTTYPE_ACTIVATED, Activated) = TX_ENUM_STARTVALUE,
    TX_ENUM_VALUE(TX_ACTIVATABLEEVENTTYPE_ACTIVATIONFOCUSCHANGED, ActivationFocusChanged)
TX_END_ENUM(TX_ACTIVATABLEEVENTTYPE, ActivatableEventType)

/*********************************************************************************************************************/

/**
  TX_ACTIONDATA

  Enumeration for all action data types.

  @field TX_ACTIONDATATYPE_ACTIVATIONNOHIT
    An activation action did not hit any valid interactor
  @field TX_ACTIONDATATYPE_PANNOHIT
    A pan action did not hit any valid interactor
  @field TX_ACTIONDATATYPE_ZOOMNOHIT
    A zoom action did not hit any valid interactor
 */
TX_BEGIN_ENUM(ActionDataType)    
    TX_ENUM_VALUE(TX_ACTIONDATATYPE_ACTIVATIONNOHIT, ActivationNoHit) = TX_ENUM_STARTVALUE,
    TX_ENUM_VALUE(TX_ACTIONDATATYPE_PANNOHIT, PanNoHit),
    TX_ENUM_VALUE(TX_ACTIONDATATYPE_ZOOMNOHIT, ZoomNoHit)
TX_END_ENUM(TX_ACTIONDATATYPE, ActionDataType)

/*********************************************************************************************************************/

/**
  TX_FIXATIONDATAEVENTTYPE

  Enumeration for all fixation data event types.
  Fixation event type is metadata contained by all behaviors of type TX_INTERACTIONBEHAVIORTYPE_FIXATION sent
  from the server. This event type specifies what kind of fixation event actually happened.
  
  @field TX_FIXATIONDATAEVENTTYPE_BEGIN:
    The fixation has begun. The gaze point data provided is a combination of the gaze points used to detect the 
    fixation. The timestamp will reflect when the fixation actually began.

  @field TX_FIXATIONDATAEVENTTYPE_END:
    The fixation has ended. The last valid gaze point is provided. The timestamp will reflect when the 
    fixation actually ended.
    
  @field TX_FIXATIONDATAEVENTTYPE_DATA:
    The fixation is still occuring. A new, filtered gaze point within the fixation is provided.
 */
TX_BEGIN_ENUM(FixationDataEventType)    
    TX_ENUM_VALUE(TX_FIXATIONDATAEVENTTYPE_BEGIN, Begin) = TX_ENUM_STARTVALUE,
    TX_ENUM_VALUE(TX_FIXATIONDATAEVENTTYPE_END, End),
    TX_ENUM_VALUE(TX_FIXATIONDATAEVENTTYPE_DATA, Data)
TX_END_ENUM(TX_FIXATIONDATAEVENTTYPE, FixationDataEventType)

/*********************************************************************************************************************/

/**
  TX_GAZEPOINTDATAMODE

   Enumeration for all gaze point data modes.
   The gaze point data mode is metadata contained by all behaviors of type TX_INTERACTIONBEHAVIORTYPE_GAZEPOINTDATA.
   When put on an interactor it specifies what kind of filter to use by the engine when calculating the gaze points.
   When put on an event it specifies what kind of filter that was used by the engine.

   @field TX_GAZEPOINTDATAMODE_UNFILTERED:    
    No filter will be applied to the gaze points. (note though that invalid gaze points are discarded)

   @field: TX_GAZEPOINTDATAMODE_LIGHTLYFILTERED:
    A light filter was/will be applied to the gaze point data. It is not a simple smoothing filter, it aims to be 
    smooth but responsive. This should be you default choice for gaze point data.
 */
TX_BEGIN_ENUM(GazePointDataMode)
    TX_ENUM_VALUE(TX_GAZEPOINTDATAMODE_UNFILTERED,      Unfiltered) = TX_ENUM_STARTVALUE,
    TX_ENUM_VALUE(TX_GAZEPOINTDATAMODE_LIGHTLYFILTERED, LightlyFiltered)
TX_END_ENUM(TX_GAZEPOINTDATAMODE, GazePointDataMode)


/*********************************************************************************************************************/

/**
  TX_GAZEAWAREMODE

   Enumeration for all gaze aware modes.
   The gaze point data mode is metadata contained by all behaviors of type TX_INTERACTIONBEHAVIORTYPE_GAZEAWARE.
   When put on an interactor it specifies how the user must gaze on the interactor to make it gaze aware.
   When put on an event it specifies what kind of mode that was used by the engine.
   
   @field: TX_GAZEAWAREMODE_NORMAL:
    The interactor will get a gaze aware event when the engine considers the user to intentionally look at it.
       
   @field: TX_GAZEAWAREMODE_DELAYED:
    The interactor will get a gaze aware event when the engine considers the user to have looked at it for a 
    specified amount of time. When using this mode TX_GAZEAWAREPARAMS needs have the field DelayTime set.
 */
TX_BEGIN_ENUM(GazeAwareMode)
    TX_ENUM_VALUE(TX_GAZEAWAREMODE_NORMAL,   Normal) = TX_ENUM_STARTVALUE,
    TX_ENUM_VALUE(TX_GAZEAWAREMODE_DELAYED, Delayed)    
TX_END_ENUM(TX_GAZEAWAREMODE, GazeAwareMode)

/*********************************************************************************************************************/

/**
  TX_FIXATIONDATAMODE

   Enumeration for all fixation data modes.
   The fixation data mode is metadata contained by all behaviors of type TX_INTERACTIONBEHAVIORTYPE_FIXATION.
   When put on an interactor it specifies what kind of filter to use by the engine when finding fixations.
   When put on an event it specifies what kind of filter that was used by the engine.

   @field TX_FIXATIONDATAMODE_SENSITIVE:    
    Very sensitive fixation filter, will result in many fixations, sometimes very close and in quick succession.

   @field TX_FIXATIONDATAMODE_SLOW:
    Fairly sensitive to enter fixation but can be slow to exit, as it tries merge fixations close to each other. 
    Will result in fairly stable fixations but fixation end events may be coming rather late in certain circumstances.
 */
TX_BEGIN_ENUM(FixationDataMode)
    TX_ENUM_VALUE(TX_FIXATIONDATAMODE_SENSITIVE, Sensitive) = TX_ENUM_STARTVALUE,
    TX_ENUM_VALUE(TX_FIXATIONDATAMODE_SLOW, Slow)
TX_END_ENUM(TX_FIXATIONDATAMODE, FixationDataMode)

/*********************************************************************************************************************/

/**
  TX_EYETRACKINGDEVICESTATUS

  Enumeration for all eye tracking device statuses.

  @field TX_EYETRACKINGDEVICESTATUS_INITIALIZING:
    The eye tracking device is initializing.

  @field TX_EYETRACKINGDEVICESTATUS_NOTAVAILABLE:
    There is no eye tracking device available.

  @field TX_EYETRACKINGDEVICESTATUS_INVALIDCONFIGURATION:
    The eye tracking device has an invalid configuration.

  @field TX_EYETRACKINGDEVICESTATUS_DEVICENOTCONNECTED:
    The eye tracking device is not connected.

  @field TX_EYETRACKINGDEVICESTATUS_TRACKING:
    The eye tracking device is currently tracking.

  @field TX_EYETRACKINGDEVICESTATUS_TRACKINGPAUSED:
    The eye tracking device is paused.

  @field TX_EYETRACKINGDEVICESTATUS_CONFIGURING:
    The eye tracking device is being configured.

  @field TX_EYETRACKINGDEVICESTATUS_UNKNOWNERROR:
    Unknown error.
 */
TX_BEGIN_ENUM(EyeTrackingDeviceStatus)
    TX_ENUM_VALUE(TX_EYETRACKINGDEVICESTATUS_INITIALIZING,          Initializing) = TX_ENUM_STARTVALUE,
    TX_ENUM_VALUE(TX_EYETRACKINGDEVICESTATUS_NOTAVAILABLE,          NotAvailable),
    TX_ENUM_VALUE(TX_EYETRACKINGDEVICESTATUS_INVALIDCONFIGURATION,  InvalidConfiguration),
    TX_ENUM_VALUE(TX_EYETRACKINGDEVICESTATUS_DEVICENOTCONNECTED,    DeviceNotConnected),    
    TX_ENUM_VALUE(TX_EYETRACKINGDEVICESTATUS_TRACKING,              Tracking),
    TX_ENUM_VALUE(TX_EYETRACKINGDEVICESTATUS_TRACKINGPAUSED,        TrackingPaused),
    TX_ENUM_VALUE(TX_EYETRACKINGDEVICESTATUS_CONFIGURING,           Configuring),
    TX_ENUM_VALUE(TX_EYETRACKINGDEVICESTATUS_UNKNOWNERROR,          UnknownError)
TX_END_ENUM(TX_EYETRACKINGDEVICESTATUS, EyeTrackingDeviceStatus)

/*********************************************************************************************************************/

/**
  Enumeration for all command types.
  The command type is metadata contained by all commands sent from the client to the server which describes what kind
  of command it is. Normally, clients should not send commands directly. Instead prefer higher abstractions such as 
  txGetState, txCommitSnapshot, etc. However, txCreateCommand and txExecuteCommands can be used to manually send commands.

  @field TX_INTERACTIONCOMMANDTYPE_EXECUTEACTION:
    Executes an action. Expected data payload is a property with name TX_LITERAL_ACTIONTYPE and with a value of TX_ACTIONTYPE.

  @field TX_INTERACTIONCOMMANDTYPE_SETSTATE:
    Sets a state. Expected data payload is a state bag. Use txCreateStateBag to set the property path and its value.
    Asyncrhonous result will return TX_RESULT_NOT_FOUND if path does not exist.

  @field TX_INTERACTIONCOMMANDTYPE_GETSTATE:
    Gets a state. Expected payload data is a property with name TX_LITERAL_STATEPATH and with a string value.
    Asynchronous result will return TX_RESULT_NOT_FOUND if path does not exist.

  @field TX_INTERACTIONCOMMANDTYPE_REGISTERSTATEOBSERVER:
    Registers the client as a state observer. Expected payload data is a property with name TX_LITERAL_STATEPATH and with a string value.

  @field TX_INTERACTIONCOMMANDTYPE_UNREGISTERSTATEOBSERVER:
    Unregisters the client as a state observer. Expected payload data is a property with name TX_LITERAL_STATEPATH and with a string value.

  @field TX_INTERACTIONCOMMANDTYPE_COMMITSNAPSHOT:
    Commits a snapshot to the server. Expected payload data is a a snapshot created with txCreateSnapshot.
  
  @field TX_INTERACTIONCOMMANDTYPE_GETSERVERVERSION:
    Gets the version of the running server.

  @field TX_INTERACTIONCOMMANDTYPE_ENABLEBUILTINKEYS:
    Enabled built-in interaction keys in the EyeX Engine. These are enabled by default, so this will only have effect if the client has disabled
    the keys previously with TX_INTERACTIONCOMMANDTYPE_DISABLEBUILTINKEYS.

  @field TX_INTERACTIONCOMMANDTYPE_DISABLEBUILTINKEYS:
    Disables the built-in interaction keys in the EyeX Engine. The keys will automatically be re-enabled if the client who disabled the keys
    disconnects. Keys can also be re-enabled with TX_INTERACTIONCOMMANDTYPE_ENABLEBUILTINKEYS. Note that the keys will be disabled for all applications,
    so developers should take care to re-enable the keys as soon as their application no longer has the key focus.
    
  @field TX_INTERACTIONCOMMANDTYPE_CLIENTCONNECTION:
    For internal use only.

  @field TX_INTERACTIONCOMMANDTYPE_LAUNCHEYETRACKINGCONTROLPANEL:
    For internal use only.

  @field TX_INTERACTIONCOMMANDTYPE_REGISTERQUERYHANDLER:
    For internal use only.

  @field TX_INTERACTIONCOMMANDTYPE_UNREGISTERQUERYHANDLER:
    For internal use only.  
 */
TX_BEGIN_ENUM(InteractionCommandType)
    TX_ENUM_VALUE(TX_INTERACTIONCOMMANDTYPE_EXECUTEACTION,                  ExecuteAction) = TX_ENUM_STARTVALUE,
    TX_ENUM_VALUE(TX_INTERACTIONCOMMANDTYPE_SETSTATE,                       SetState),
    TX_ENUM_VALUE(TX_INTERACTIONCOMMANDTYPE_GETSTATE,                       GetState),
    TX_ENUM_VALUE(TX_INTERACTIONCOMMANDTYPE_REGISTERSTATEOBSERVER,          RegisterStateObserver),
    TX_ENUM_VALUE(TX_INTERACTIONCOMMANDTYPE_UNREGISTERSTATEOBSERVER,        UnregisterStateObserver),    
    TX_ENUM_VALUE(TX_INTERACTIONCOMMANDTYPE_COMMITSNAPSHOT,                 CommitSnapshot),
    TX_ENUM_VALUE(TX_INTERACTIONCOMMANDTYPE_GETSERVERVERSION,               GetServerVersion),
    TX_ENUM_VALUE(TX_INTERACTIONCOMMANDTYPE_ENABLEBUILTINKEYS,              EnableBuiltinKeys),
    TX_ENUM_VALUE(TX_INTERACTIONCOMMANDTYPE_DISABLEBUILTINKEYS,             DisableBuiltinKeys),
    TX_ENUM_VALUE(TX_INTERACTIONCOMMANDTYPE_CLIENTCONNECTION,               ClientConnection) = TX_INTERNAL_ENUM_STARTVALUE,
    TX_ENUM_VALUE(TX_INTERACTIONCOMMANDTYPE_LAUNCHEYETRACKINGCONTROLPANEL,  LaunchEyeTrackingControlPanel),
    TX_ENUM_VALUE(TX_INTERACTIONCOMMANDTYPE_REGISTERQUERYHANDLER,           RegisterQueryHandler),
    TX_ENUM_VALUE(TX_INTERACTIONCOMMANDTYPE_UNREGISTERQUERYHANDLER,         UnregisterQueryHandler)
TX_END_ENUM(TX_INTERACTIONCOMMANDTYPE, InteractionCommandType)

/*********************************************************************************************************************/

/**
  Enumeration for all action types.
  An action is a way to interact with the EyeX Engine in addition or instead of the default keybindings that normally
  executes gaze actions.

  @field TX_ACTIONTYPE_ACTIVATE:
    Activates an interactor. This corresponds to a click on the activation button

  @field TX_ACTIONTYPE_ACTIVATIONMODEON:
    Turns on activation mode. This corresponds to pressing the activation button.

  @field TX_ACTIONTYPE_ACTIVATIONMODEOFF:
    Turns off activation mode. This corresponds to releasing the activation button.

  @field TX_ACTIONTYPE_PANNINGBEGIN:
    Begins a panning. This corresponds to pressing the panning button.

  @field TX_ACTIONTYPE_PANNINGEND:
    Ends a panning. This corresponds to releasing the panning button.

  @field TX_ACTIONTYPE_PANNINGSTEP:
    Performs a panning step action. This corresponds to a click on the panning button.

  @field TX_ACTIONTYPE_ZOOMIN:
    Perfomrs a zoom-in action. This corresponds to a click on the zoom-in button.

  @field TX_ACTIONTYPE_ZOOMOUT:
    Perfomrs a zoom-out action. This corresponds to a click on the zoom-out button. 

  @field TX_ACTIONTYPE_PANNINGTOGGLEHANDSFREE:
    Toggles auto-panning mode on or off.  
 */
TX_BEGIN_ENUM(ActionType)
    TX_ENUM_VALUE(TX_ACTIONTYPE_ACTIVATE,                  Activate) = TX_ENUM_STARTVALUE,
    TX_ENUM_VALUE(TX_ACTIONTYPE_ACTIVATIONMODEON,          ActivationModeOn),
    TX_ENUM_VALUE(TX_ACTIONTYPE_ACTIVATIONMODEOFF,         ActivationModeOff),
    TX_ENUM_VALUE(TX_ACTIONTYPE_PANNINGBEGIN,              PanningBegin),
    TX_ENUM_VALUE(TX_ACTIONTYPE_PANNINGEND,                PanningEnd),    
    TX_ENUM_VALUE(TX_ACTIONTYPE_PANNINGSTEP,               PanningStep),
    TX_ENUM_VALUE(TX_ACTIONTYPE_ZOOMIN,                    ZoomIn),
    TX_ENUM_VALUE(TX_ACTIONTYPE_ZOOMOUT,                   ZoomOut),
    TX_ENUM_VALUE(TX_ACTIONTYPE_PANNINGTOGGLEHANDSFREE,    PanningToggleHandsFree)
TX_END_ENUM(TX_ACTIONTYPE, ActionType)

/*********************************************************************************************************************/

/**
  TX_PANNABLEEVENTTYPE

  Enumeration for all pannable event types.
  Pannable event type are metadata contained by all behaviors of type TX_INTERACTIONBEHAVIORTYPE_PANNABLE sent
  from the server. This event type specifies what kind of pannable event actually happened.
  
  @field TX_PANNABLEEVENTTYPE_PAN:
    The interactor has been panned.

  @field TX_PANNABLEEVENTTYPE_STEP:
    The interactor has been stepped.

  @field TX_PANNABLEEVENTTYPE_HANDSFREE:
    The interactor does not need any hand user input to pan.
 */
TX_BEGIN_ENUM(PannableEventType)    
    TX_ENUM_VALUE(TX_PANNABLEEVENTTYPE_PAN, Pan) = TX_ENUM_STARTVALUE,
    TX_ENUM_VALUE(TX_PANNABLEEVENTTYPE_STEP, Step),
    TX_ENUM_VALUE(TX_PANNABLEEVENTTYPE_HANDSFREE, HandsFree)
TX_END_ENUM(TX_PANNABLEEVENTTYPE, PannableEventType)


/*********************************************************************************************************************/

/**
  TX_PANDIRECTION

  Enumeration flags for all pannable directions.
  Governs available directions to pan for a pannable interactor. 
  The directions are bitwise combinable.

  @field TX_PANDIRECTION_NONE:
    No pandirection available.

  @field TX_PANDIRECTION_LEFT:
    Panning to the left available.

  @field TX_PANDIRECTION_RIGHT:
    Panning to the right available.

  @field TX_PANDIRECTION_UP:
    Panning up available.

  @field TX_PANDIRECTION_DOWN:
    Panning down available.

  @field TX_PANDIRECTION_ALL:
    All pan directions available.
 */
TX_BEGIN_FLAGS(PanDirection)
    TX_ENUM_VALUE(TX_PANDIRECTION_NONE,  None) = TX_FLAGS_NONE_VALUE,
    TX_ENUM_VALUE(TX_PANDIRECTION_LEFT,  Left) = 1,
    TX_ENUM_VALUE(TX_PANDIRECTION_RIGHT, Right) = 1 << 1,
    TX_ENUM_VALUE(TX_PANDIRECTION_UP,    Up) = 1 << 2,
    TX_ENUM_VALUE(TX_PANDIRECTION_DOWN,  Down) = 1 << 3,
    TX_ENUM_VALUE(TX_PANDIRECTION_ALL,   All) = (1 << 4)-1
TX_END_FLAGS(TX_PANDIRECTION, PanDirection)

/*********************************************************************************************************************/

/**
  TX_PANNINGPROFILE
  
  Enumeration for all panning profiles.

  @field TX_PANNINGPROFILE_NONE:
    No panning profile.

  @field TX_PANNINGPROFILE_READING:
    Panning profile for reading, will be available in subsequent versions.

  @field TX_PANNINGPROFILE_HORIZONTAL:
    Left and right only panning profile.

  @field TX_PANNINGPROFILE_VERTICAL:
    Up and down only panning profile.

  @field TX_PANNINGPROFILE_VERTICALFIRSTTHENHORIZONTAL:
    Up, down, left and right, with emphasis on vertical panning.

  @field TX_PANNINGPROFILE_RADIAL:
    Panning in any direction.

  @field TX_PANNINGPROFILE_HORIZONTALFIRSTTHENVERTICAL:
    Up, down, left and right, with emphasis on horizontal panning.
 */
TX_BEGIN_ENUM(PanningProfile)
    TX_ENUM_VALUE(TX_PANNINGPROFILE_NONE,                        None) = TX_ENUM_STARTVALUE,
    TX_ENUM_VALUE(TX_PANNINGPROFILE_READING,                     Reading),
    TX_ENUM_VALUE(TX_PANNINGPROFILE_HORIZONTAL,                  Horizontal),
    TX_ENUM_VALUE(TX_PANNINGPROFILE_VERTICAL,                    Vertical),
    TX_ENUM_VALUE(TX_PANNINGPROFILE_VERTICALFIRSTTHENHORIZONTAL, VerticalFirstThenHorizontal),
    TX_ENUM_VALUE(TX_PANNINGPROFILE_RADIAL,                      Radial),    
    TX_ENUM_VALUE(TX_PANNINGPROFILE_HORIZONTALFIRSTTHENVERTICAL, HorizontalFirstThenVertical)
TX_END_ENUM(TX_PANNINGPROFILE, PanningProfile)

/*********************************************************************************************************************/

/**
  TX_PRESENCEDATA

  Enumeration for convery presence status.

  @field TX_PRESENCEDATA_PRESENT:
    A user is present in front of the eye tracker.
  
  @field TX_PRESENCEDATA_NOTPRESENT:
    A user is not present in front of the eye tracker.
 */
TX_BEGIN_ENUM(PresenceData)
    TX_ENUM_VALUE(TX_PRESENCEDATA_PRESENT,                  Present) = TX_ENUM_STARTVALUE,
    TX_ENUM_VALUE(TX_PRESENCEDATA_NOTPRESENT,               NotPresent)    
TX_END_ENUM(TX_PRESENCEDATA, PresenceData)

/*********************************************************************************************************************/

/**
  TX_MASKTYPE

  Enumeration for mask types.

  @field TX_MASKTYPE_DEFAULT:
	Default mask type.
 */
TX_BEGIN_ENUM(MaskType)
    TX_ENUM_VALUE(TX_MASKTYPE_DEFAULT,                  Default) = TX_ENUM_STARTVALUE
TX_END_ENUM(TX_MASKTYPE, MaskType)

/*********************************************************************************************************************/

#endif /* !defined(__TOBII_TX_FRAMEWORK_TYPES__H__) */

/*********************************************************************************************************************/
