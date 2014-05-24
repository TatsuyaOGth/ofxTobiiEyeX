/*********************************************************************************************************************
 * Copyright 2013-2014 Tobii Technology AB. All rights reserved.
 * EyeXClientTypes.h
 *********************************************************************************************************************/

#if !defined(__TOBII_TX_TYPES__H__)
#define __TOBII_TX_TYPES__H__

/*********************************************************************************************************************
 * Common types
 *********************************************************************************************************************/

/**
  Macro that generates a type of the specified type.
 */
#if !defined(TX_DEFINE_TYPE)
#define TX_DEFINE_TYPE(type, name) typedef type name;
#endif /* !defined(TX_TRANSLATE_TYPE) */

/*********************************************************************************************************************/

TX_DEFINE_TYPE(void*,                               TX_USERPARAM);
TX_DEFINE_TYPE(struct txInteractionObject*,         TX_HANDLE);
TX_DEFINE_TYPE(const struct txInteractionObject*,   TX_CONSTHANDLE);
TX_DEFINE_TYPE(struct txProperty*,                  TX_PROPERTYHANDLE);
TX_DEFINE_TYPE(const struct txProperty*,            TX_CONSTPROPERTYHANDLE);
TX_DEFINE_TYPE(struct txInteractionContext*,        TX_CONTEXTHANDLE);
TX_DEFINE_TYPE(const struct txInteractionContext*,  TX_CONSTCONTEXTHANDLE);
TX_DEFINE_TYPE(int,                                 TX_TICKET);
TX_DEFINE_TYPE(int,                                 TX_BOOL);
TX_DEFINE_TYPE(unsigned char,                       TX_BYTE);
TX_DEFINE_TYPE(int,                                 TX_SIZE);
TX_DEFINE_TYPE(int,                                 TX_INTEGER);
TX_DEFINE_TYPE(double,                              TX_REAL);
TX_DEFINE_TYPE(char,                                TX_CHAR);
TX_DEFINE_TYPE(char*,                               TX_STRING);
TX_DEFINE_TYPE(const char*,                         TX_CONSTSTRING);
TX_DEFINE_TYPE(void*,                               TX_RAWPTR);
TX_DEFINE_TYPE(int,                                 TX_THREADID);

/*********************************************************************************************************************/

#include "EyeXInternalTypes.h"

/*********************************************************************************************************************/

#define TX_EMPTY_HANDLE 0
#define TX_INVALID_TICKET 0

#define TX_TRUE 1
#define TX_FALSE 0

#define TX_CLEANUPTIMEOUT_DEFAULT 500
#define TX_CLEANUPTIMEOUT_FORCEIMMEDIATE -1

/*********************************************************************************************************************/

/**
  TX_SYSTEMCOMPONENTOVERRIDEFLAGS    

  Enumeration for all system component override flags.
  When calling txInitializeSystem these flags must be combined to specify which system components should be overriden.

  @field TX_SYSTEMCOMPONENTOVERRIDEFLAG_NONE:
    No system component should be overriden.
    
  @field TX_SYSTEMCOMPONENTOVERRIDEFLAG_MEMORYMODEL:
    The memory model should be overriden.
    
  @field TX_SYSTEMCOMPONENTOVERRIDEFLAG_THREADINGMODEL:
    The threading model should be overriden.
    
  @field TX_SYSTEMCOMPONENTOVERRIDEFLAG_LOGGINGMODEL:
    The logging model should be overriden.
    The logging model can be overriden by just specifying some of the standard log targets (see TX_LOGTARGET) or by
    a custom user implemented log writer.
	
  @field TX_SYSTEMCOMPONENTOVERRIDEFLAG_SCHEDULINGMODEL:
    The scheduling model should be overriden.
 */ 
TX_BEGIN_FLAGS(SystemComponentOverrideFlags)
    TX_ENUM_VALUE(TX_SYSTEMCOMPONENTOVERRIDEFLAG_NONE,            None) = TX_FLAGS_NONE_VALUE,  
    TX_ENUM_VALUE(TX_SYSTEMCOMPONENTOVERRIDEFLAG_MEMORYMODEL,     MemoryModel) = 1 << 0,
    TX_ENUM_VALUE(TX_SYSTEMCOMPONENTOVERRIDEFLAG_THREADINGMODEL,  TheadingModel) = 1 << 1,
    TX_ENUM_VALUE(TX_SYSTEMCOMPONENTOVERRIDEFLAG_LOGGINGMODEL,    LoggingModel) = 1 << 2,
    TX_ENUM_VALUE(TX_SYSTEMCOMPONENTOVERRIDEFLAG_SCHEDULINGMODEL, SchedulingModel) = 1 << 3
TX_END_FLAGS(TX_SYSTEMCOMPONENTOVERRIDEFLAGS, SystemComponentOverrideFlags)

/*********************************************************************************************************************/

/**
  TX_CONNECTIONSTATE

  Enumeration for all connection states.
  These values are used to notify the application of the current connection state. 
  To recieve these notifications the client needs to subscribe using txRegisterConnectionStateChangedHandler and then 
  call txEnableConnection. 

  @field TX_CONNECTIONSTATE_CONNECTED:
    The client is now connected to the server.

  @field TX_CONNECTIONSTATE_DISCONNECTED:
    The client is now disconnected from the server. Unless this is due to txDisableConnection being called the client
    will shortly attempt to connect again.
    
  @field TX_CONNECTIONSTATE_TRYINGTOCONNECT:
    The client is now trying to connect to the server. This is the first state being sent to the application after 
    txEnableConnection has been called.
    
  @field TX_CONNECTIONSTATE_SERVERVERSIONTOOLOW:
    The server version is too low. The client is not connected and will not try to reconnect.
    
  @field TX_CONNECTIONSTATE_SERVERVERSIONTOOHIGH:
    The server version is too high. The client is not connected and will not try to reconnect.
 */ 
TX_BEGIN_ENUM(ConnectionState)
    TX_ENUM_VALUE(TX_CONNECTIONSTATE_CONNECTED,             Connected) = TX_ENUM_STARTVALUE,  
    TX_ENUM_VALUE(TX_CONNECTIONSTATE_DISCONNECTED,          Disconnected),
    TX_ENUM_VALUE(TX_CONNECTIONSTATE_TRYINGTOCONNECT,       TryingToConnect),
    TX_ENUM_VALUE(TX_CONNECTIONSTATE_SERVERVERSIONTOOLOW,   ServerVersionTooLow),
    TX_ENUM_VALUE(TX_CONNECTIONSTATE_SERVERVERSIONTOOHIGH,  ServerVersionTooHigh)
TX_END_ENUM(TX_CONNECTIONSTATE, ConnectionState)

/*********************************************************************************************************************/

/**
  TX_LOGTARGET

  Enumeration for all log targets.
  When overring the logging model these flags specify which log targets to use. The flags can be combined.

  @field TX_LOGTARGET_NONE:
    No logging should occur at all.

  @field TX_LOGTARGET_CONSOLE:
    The log message should be written to the console.
    
  @field TX_LOGTARGET_TRACE:
    The log messages should be traced. (output window i Visual Studio)
    
  @field TX_LOGTARGET_CUSTOM:
    The specified TX_LOGCALLBACK should be invoked for custom logging.
 */
TX_BEGIN_FLAGS(LogTarget)
    TX_ENUM_VALUE(TX_LOGTARGET_NONE,    None) = TX_FLAGS_NONE_VALUE,
    TX_ENUM_VALUE(TX_LOGTARGET_CONSOLE, Console) = 1 << 0,
    TX_ENUM_VALUE(TX_LOGTARGET_TRACE,   Trace) = 1 << 1,    
    TX_ENUM_VALUE(TX_LOGTARGET_CUSTOM,  Custom) = 1 << 2
TX_END_FLAGS(TX_LOGTARGET, LogTarget)

/*********************************************************************************************************************/

/**
  TX_LOGLEVEL

  Enumeration for all log levels.
  The log levels are used to indicate the severity of the message.

  @field TX_LOGLEVEL_DEBUG:
    The message is just a debug print out typically used during development.

  @field TX_LOGLEVEL_INFO:
    The message is plain info and does not indciate that something is wrong.
    
  @field TX_LOGLEVEL_WARNING:
    The message is a warning that indicates that something is not the way it should, not yet critical.
    
  @field TX_LOGLEVEL_ERROR:
    The message indicates that there is some kind of error.
 */
TX_BEGIN_ENUM(LogLevel)
    TX_ENUM_VALUE(TX_LOGLEVEL_DEBUG,   Debug)  = TX_ENUM_STARTVALUE,
    TX_ENUM_VALUE(TX_LOGLEVEL_INFO,    Info),
    TX_ENUM_VALUE(TX_LOGLEVEL_WARNING, Warning),
    TX_ENUM_VALUE(TX_LOGLEVEL_ERROR,   Error)    
TX_END_ENUM(TX_LOGLEVEL, LogLevel)

/*********************************************************************************************************************/

/**
  TX_SCHEDULINGMODE

  Enumeration for all schedulng modes.
  When overring the scheduling model the mode specifies which of the available scheduling modes to use.

  @field TX_SCHEDULINGMODE_DIRECT:
    All jobs are performed immediately on the thread that calls them.

  @field TX_SCHEDULINGMODE_USERFRAME:
	All jobs are performed when the txPerformScheduledJobs are called.
    
  @field TX_SCHEDULINGMODE_CUSTOM:
	Whenever a job is to be performed a callback function is invoked giving the client application full control.
 */
TX_BEGIN_FLAGS(SchedulingMode)
    TX_ENUM_VALUE(TX_SCHEDULINGMODE_DIRECT,    Direct) = TX_ENUM_STARTVALUE,
    TX_ENUM_VALUE(TX_SCHEDULINGMODE_USERFRAME, UserFrame),
    TX_ENUM_VALUE(TX_SCHEDULINGMODE_CUSTOM,    Custom)    
TX_END_FLAGS(TX_SCHEDULINGMODE, SchedulingMode)

/*********************************************************************************************************************/

/**
  TX_PROPERTYVALUETYPE   

  Enumeration for all property value types.

  @field TX_PROPERTYVALUETYPE_EMPTY:
    The property does not have a value.

  @field TX_PROPERTYVALUETYPE_OBJECT:
    The property currently holds an interaction object.
    
  @field TX_PROPERTYVALUETYPE_INTEGER:
    The property currently holds an integer.

  @field TX_PROPERTYVALUETYPE_REAL:
    The property currently holds a real.

  @field TX_PROPERTYVALUETYPE_STRING:
    The property currently holds a string.
        
  @field TX_PROPERTYVALUETYPE_BLOB:
    The property currently holds a blob.
 */ 
TX_BEGIN_ENUM(PropertyValueType)
    TX_ENUM_VALUE(TX_PROPERTYVALUETYPE_EMPTY,   Empty) = TX_ENUM_STARTVALUE,
    TX_ENUM_VALUE(TX_PROPERTYVALUETYPE_OBJECT,  Object),
    TX_ENUM_VALUE(TX_PROPERTYVALUETYPE_INTEGER, Integer),
    TX_ENUM_VALUE(TX_PROPERTYVALUETYPE_REAL,    Real),
    TX_ENUM_VALUE(TX_PROPERTYVALUETYPE_STRING,  String),
    TX_ENUM_VALUE(TX_PROPERTYVALUETYPE_BLOB,    Blob)
TX_END_ENUM(TX_PROPERTYVALUETYPE, PropertyValueType)

/*********************************************************************************************************************/

/**
  TX_PROPERTYBAGTYPE

  Enumeration for the all Property Bag types.
    
  @field TX_PROPERTYBAGTYPE_OBJECT:
    The property is a normal object with named properties.

  @field TX_PROPERTYBAGTYPE_ARRAY:
    The property bag is an array with sequentially named properties appearing in the order they where inserted.
 */
TX_BEGIN_ENUM(PropertyBagType)
    TX_ENUM_VALUE(TX_PROPERTYBAGTYPE_OBJECT, Object) = TX_ENUM_STARTVALUE,
    TX_ENUM_VALUE(TX_PROPERTYBAGTYPE_ARRAY,  Array)
TX_END_ENUM(TX_PROPERTYBAGTYPE, PropertyBagType)

/*********************************************************************************************************************
 * Callbacks
 *********************************************************************************************************************/

/**
  Callback for when the connection state is changed.
    See txRegisterConnectionStateChangedHandler 
  
  @param state [in]: 
    Specifies the current state of the connection.
  
  @param userParam [in]: 
    The user parameter provided to the txRegisterConnectionStateChangedHandler function.
 
  @return 
    void
 */ 
TX_DEFINE_CALLABLE(TX_CONNECTIONSTATECHANGEDCALLBACK, ConnectionStateChangedCallback, void, (
    TX_CONNECTIONSTATE state,
    TX_USERPARAM userParam
    ));

#if defined(__cplusplus)
#ifndef TOBII_TX_INTEROP
#include <functional>

    namespace Tx {
		typedef std::function<void (TX_CONNECTIONSTATE)> ConnectionStateChangedCallback;
	}

#endif
#endif
	
/*********************************************************************************************************************/

/**
  Callback for an asynchronous operations.
   
  @param hAsyncData [in]: 
    A TX_CONSTHANDLE to the async data. 
 
  @param userParam [in]: 
    The user parameter provided to the asynchronous operation.
		
  @return 
    void
 */
TX_DEFINE_CALLABLE(TX_ASYNCDATACALLBACK, AsyncDataCallback, void ,(    
    TX_CONSTHANDLE hAsyncData,
    TX_USERPARAM userParam
    ));

#if defined(__cplusplus)
#ifndef TOBII_TX_INTEROP
#include <functional>

    namespace Tx {
		typedef std::function<void (TX_CONSTHANDLE)> AsyncDataCallback;
	}

#endif
#endif

/*********************************************************************************************************************/

/**
  Function run by a thread.
    See txInitializeSystem, TX_THREADINGMODEL
 
  @param threadWorkerParam [in]: 
    The user parameter provided to the CreateThreadCallback.  
 
  @return 
    void
 */
TX_DEFINE_CALLABLE(TX_THREADWORKERFUNCTION, ThreadWorkerFunction, void, (
    TX_USERPARAM threadWorkerParam
    ));

/*********************************************************************************************************************/

/**
  Callback used to create a thread.
    See txInitializeSystem, TX_THREADINGMODEL
 
  @param worker [in]: 
   Worker function that will be run by the thread.
 
  @param threadWorkerParam [in]:
    A user parameter passed to worker function.
 
  @param userParam [in]: 
    The user parameter provided by the TX_THREADINGMODEL structure.
 
  @return 
    TX_THREADID, the id of the created thread.
 */
TX_DEFINE_CALLABLE(TX_CREATETHREADCALLBACK, CreateThreadCallback, TX_THREADID, (
    TX_THREADWORKERFUNCTION worker,
    TX_USERPARAM threadWorkerParam,
    TX_USERPARAM userParam
    ));

/*********************************************************************************************************************/

/**
  Callback used to get the current thread id.
    See txInitializeSystem, TX_THREADINGMODEL
 
  @param userParam [in]: 
    The user parameter provided by the TX_THREADINGMODEL structure.
 
  @return 
    TX_THREADID, the id of the current thread
 */
TX_DEFINE_CALLABLE(TX_GETCURRENTTHREADIDCALLBACK, GetCurrentThreadIdCallback, TX_THREADID, (
    TX_USERPARAM userParam
    ));

/*********************************************************************************************************************/

/**
  Callback used to join a thread.
    See txInitializeSystem, TX_THREADINGMODEL
 
  @param threadId [in]: 
    The id of the thread to join.
 
  @param userParam [in]: 
    The user parameter provided by the TX_THREADINGMODEL structure.
 
  @return 
    TX_TRUE if the thread was successfully joined. TX_FALSE on non existing thread.
 */
TX_DEFINE_CALLABLE(TX_JOINTHREADCALLBACK, JoinThreadCallback, TX_BOOL, (
    TX_THREADID threadId,
    TX_USERPARAM userParam
    ));

/*********************************************************************************************************************/

/**
  Callback used to delete a thread.
    See txInitializeSystem, TX_THREADINGMODEL
 
  @param threadId [in]: 
    The id of the thread to be deleted.
 
  @param userParam [in]: 
    The user parameter provided by the TX_THREADINGMODEL structure.
 
  @return 
    TX_TRUE if the thread was successfully deleted, otherwise TX_FALSE. 
 */
TX_DEFINE_CALLABLE(TX_DELETETHREADCALLBACK, DeleteThreadCallback, TX_BOOL, (
    TX_THREADID threadId,
    TX_USERPARAM userParam
    ));

/*********************************************************************************************************************/

/**
  Callback used to release a threading model or a logging model.
    See SetThreadingModel, SetLoggingModel
 
  @param userParam [in]: 
    Normally used for capture outside the scope of the callback.
 */
TX_DEFINE_CALLABLE(TX_DELETEMODELCALLBACK, ReleaseCallback, void, (
    TX_USERPARAM userParam
    ));

/*********************************************************************************************************************/

/**
  Allocator function, used to override allocation of memory
    See SetCustomAllocator
 
  @param length [in]: 
    Size in bytes of the requested memory block
 
  @return 
    void
 */
TX_DEFINE_CALLABLE(TX_ALLOCATORFUNCTION, AllocatorFunction, void, (
    TX_INTEGER length
    ));

/*********************************************************************************************************************/

/**
  Callback for logging.
    If a custom logging model is set, see TX_LOGGINGMODEL, this callback will be invoked when a log message is 
	written by the API.
 
  @param level [in]: 
    The level of log message, see TX_LOGLEVEL for levels.
 
  @param scope [in]: 
    A string token representing from which part the log message was originated.
 
  @param message [in]: 
    The message to be logged.
 
  @param userParam [in]: 
    The user parameter provided by the TX_LOGGINGMODEL structure.
  
  @return 
    void
 */
TX_DEFINE_CALLABLE(TX_LOGCALLBACK, LogCallback, void, (
    TX_LOGLEVEL level,
    TX_CONSTSTRING scope,
    TX_CONSTSTRING message,
    TX_USERPARAM userParam
    ));

/*********************************************************************************************************************

/**
  Function provided by the API when a job is scheduled.
	See TX_SCHEDULEJOBCALLBACK.

  @param jobParam [in]: 
    The user parameter provided by the API when a job is scheduled.  
 
  @return 
    void
 */
TX_DEFINE_CALLABLE(TX_PERFORMJOBFUNCTION, PerformJobFunction, void, (
    TX_USERPARAM jobParam
    ));

/*********************************************************************************************************************/

/**
  Callback for scheduling a job.
    If a custom scheduling model is set, see TX_SCHEDULINGMODEL, this callback will be invoked when a job is to be
	scheduled.
 
  @param performJob [in]: 
    The function to invoke when the job is to be performed.
 
  @param jobParam [in]: 
    A parameter used to provide a context to the job.
 
  @param userParam [in]: 
	The user parameter provided to the TX_SCHEDULINGMODEL.
   
  @return 
    void
 */
TX_DEFINE_CALLABLE(TX_SCHEDULEJOBCALLBACK, ScheduleJobCallback, void, (
    TX_PERFORMJOBFUNCTION performJob,
    TX_USERPARAM jobParam,
	TX_USERPARAM userParam
    ));

/*********************************************************************************************************************
 * Structs
 *********************************************************************************************************************/

/**
  Struct for a rectangle.
      
  @field X:
    The X coordinate for the upper left corner of the rectangle.
  
  @field Y:
    The Y coordinate for the upper left corner of the rectangle.
  
  @field Width:
    The width of the rectangle.

  @field Height:
    The height of the rectangle.
 */
TX_STRUCT_BEGIN(TX_RECT, Rect)
    TX_REAL             X;                             
    TX_REAL             Y;                             
    TX_REAL             Width;                         
    TX_REAL             Height;                        
TX_STRUCT_END(TX_RECT, Rect)

/*********************************************************************************************************************/

/**
  Struct for 2D vector.
   
  @field X:
    The X coordinate of the vector.
  
  @field Y:
    The Y coordinate of the vector.
 */
TX_STRUCT_BEGIN(TX_VEC2, Vec2)
    TX_REAL             X;                              
    TX_REAL             Y;                              
TX_STRUCT_END(TX_VEC2, Vec2)

 /*********************************************************************************************************************/

/**
  Struct for 2D size.
   
  @field Width:
    The width of the size.
  
  @field Height:
    The height of the size.
 */
TX_STRUCT_BEGIN(TX_SIZE2, Size2)
    TX_REAL             Width;                              
    TX_REAL             Height;                             
TX_STRUCT_END(TX_SIZE2, Size2)

/*********************************************************************************************************************/

/**
  Struct for pannable behavior parameters.
   
  @field IsHandsFreeEnabled:
    Specifies if a user input action is needed to initiate pan.
  
  @field Profile:
    The panning profile. See TX_PANNINGPROFILE.
    
  @field PeakVelocity:
    The maximum velocity of panning action, in millimeters per second.
  
  @field PanDirectionsAvailable:
    The available pan direction flags. See TX_PANDIRECTION.
 */
TX_STRUCT_BEGIN(TX_PANNABLEPARAMS, PannableParams)
    TX_BOOL            IsHandsFreeEnabled;             
    TX_PANNINGPROFILE  Profile;                        
    TX_REAL            PeakVelocity;                   
    TX_PANDIRECTION    PanDirectionsAvailable;         
TX_STRUCT_END(TX_PANNABLEPARAMS, PannableParams)

/*********************************************************************************************************************/

/**
  Struct for pannable pan event parameters.
   
  @field PanVelocityX:
    The X velocity for the pan. In millimeters per second.
  
  @field PanVelocityY:
    The Y velocity for the pan. In millimeters per second.
 */
TX_STRUCT_BEGIN(TX_PANNABLEPANEVENTPARAMS, PannablePanEventParams)
    TX_REAL PanVelocityX;
    TX_REAL PanVelocityY;
TX_STRUCT_END(TX_PANNABLEPANEVENTPARAMS, PannablePanEventParams)

/*********************************************************************************************************************/

/**
  Struct for pannable step event parameters.
   
  @field PanStepX:
    The step length on the X axis in millimeters.
  
  @field PanStepY:    
    The step length on the X axis in millimeters.
    
  @field PanStepDuration:    
    The amount of time in seconds during which the step should be performed.
 */
TX_STRUCT_BEGIN(TX_PANNABLESTEPEVENTPARAMS, PannableStepEventParams)
    TX_REAL PanStepX;
    TX_REAL PanStepY;
    TX_REAL PanStepDuration;
TX_STRUCT_END(TX_PANNABLESTEPEVENTPARAMS, PannableStepEventParams)

/*********************************************************************************************************************/

/**
  Struct for pannable hands free event parameters.
   
  @field HandsFreeEnabled:
    Specifies if hands free panning is enabled or not.
 */
TX_STRUCT_BEGIN(TX_PANNABLEHANDSFREEEVENTPARAMS, PannableHandsFreeEventParams)
    TX_BOOL HandsFreeEnabled;
TX_STRUCT_END(TX_PANNABLEHANDSFREEEVENTPARAMS, PannableHandsFreeEventParams)

/*********************************************************************************************************************/

/**
  Struct for activatable behavior parameters.
   
  @field EnableTentativeFocus:
    Specifies if tentative focus should be enabled.
 */
TX_STRUCT_BEGIN(TX_ACTIVATABLEPARAMS, ActivatableParams)
    TX_BOOL EnableTentativeFocus;                       
TX_STRUCT_END(TX_ACTIVATABLEPARAMS, ActivatableParams)

/*********************************************************************************************************************/

/**
  Struct for gaze aware parameters.
   
  @field GazeAwareMode:
    Specifies the gaze aware mode. See TX_GAZEAWAREMODE.

  @field DelayTime:
    Specifies the amount of time in milliseconds that the user has to look at an interactor before a gaze aware event
    is sent. This value only has an effect if the mode is set to TX_GAZEAWAREMODE_DELAYED.
 */
TX_STRUCT_BEGIN(TX_GAZEAWAREPARAMS, GazeAwareParams)
    TX_GAZEAWAREMODE GazeAwareMode;
    TX_REAL DelayTime;                  
TX_STRUCT_END(TX_GAZEAWAREPARAMS, GazeAwareParams)

/*********************************************************************************************************************/

/**
  Struct for gaze aware event parameters.
   
  @field HasGaze:
    Specifies if the interactor currently has gaze on it.
 */
TX_STRUCT_BEGIN(TX_GAZEAWAREEVENTPARAMS, GazeAwareEventParams)
    TX_BOOL HasGaze;  
TX_STRUCT_END(TX_GAZEAWAREEVENTPARAMS, GazeAwareEventParams)

/*********************************************************************************************************************/

/**
  Struct for activation focus changed Params.
   
  @field HasTentativeActivationFocus:
    Specifies if the interactor currently has tentative activation focus.
  
  @field HasActivationFocus:    
    Specifies if the interactor currently has activation focus.
 */
TX_STRUCT_BEGIN(TX_ACTIVATIONFOCUSCHANGEDEVENTPARAMS, ActivationFocusChangedEventParams)
    TX_BOOL HasTentativeActivationFocus;              
    TX_BOOL HasActivationFocus;                       
TX_STRUCT_END(TX_ACTIVATIONFOCUSCHANGEDEVENTPARAMS, ActivationFocusChangedEventParams)

/*********************************************************************************************************************/

/**
  Struct for gaze point data behavior parameters.
   
  @field GazePointDataMode:
    Specifies the gaze point data mode. See TX_GAZEPOINTDATAMODE.
 */
TX_STRUCT_BEGIN(TX_GAZEPOINTDATAPARAMS, GazePointDataParams)
    TX_GAZEPOINTDATAMODE GazePointDataMode;          
TX_STRUCT_END(TX_GAZEPOINTDATAPARAMS, GazePointDataParams)

/*********************************************************************************************************************/
    
/**
  Struct for fixation behavior parameters.
   
  @field FixationDataMode:
    Specifies the fixation data mode. See TX_FIXATIONDATAMODE.
 */
TX_STRUCT_BEGIN(TX_FIXATIONDATAPARAMS, FixationDataParams)
    TX_FIXATIONDATAMODE FixationDataMode;       
TX_STRUCT_END(TX_FIXATIONDATAPARAMS, FixationDataParams)

/*********************************************************************************************************************/

/**
  Struct for fixation behavior event parameters.
   
  @field FixationDataMode:
    The fixation data mode. See TX_FIXATIONDATAMODE.
    
  @field EventType:
    The type of fixation event. See TX_FIXATIONDATAEVENTTYPE.
    
  @field Timestamp:
    For TX_FIXATIONDATAEVENTTYPE_BEGIN, this is the time when the fixation started.
    For TX_FIXATIONDATAEVENTTYPE_END, this is the time when the fixation ended.
    For TX_FIXATIONDATAEVENTTYPE_DATA, the timestamp for the filtered gaze point provided within 
    the current fixation, when the filter was applied.
    
  @field X:
    The current X coordinate of the fixation in pixels. For begin and end events will reflect where the fixation 
    began or ended.
    
  @field Y:
    The current Y coordinate of the fixation in pixels. For begin and end events will reflect where the fixation 
    began or ended.
 */
TX_STRUCT_BEGIN(TX_FIXATIONDATAEVENTPARAMS, FixationDataEventParams)
    TX_FIXATIONDATAMODE FixationDataMode;
    TX_FIXATIONDATAEVENTTYPE EventType;
    TX_REAL Timestamp;
    TX_REAL X;       
    TX_REAL Y;
TX_STRUCT_END(TX_FIXATIONDATAEVENTPARAMS, FixationDataEventParams)

/*********************************************************************************************************************/

/**
  Struct for gaze point data behavior event parameters. 
   
  @field GazePointDataMode:
    The gaze point data mode. See TX_GAZEPOINTDATAMODE.
    
  @field Timestamp:
    For TX_GAZEPOINTDATAMODE_LIGHTLYFILTERED this is the point in time when the filter was applied.
    For TX_GAZEPOINTDATAMODE_UNFILTERED this is the point in time time when gazepoint was captured.
    
  @field X:
    The X coordinate of the gaze point in pixels.
    
  @field Y:
    The Y coordinate of the gaze point in pixels.
 */
TX_STRUCT_BEGIN(TX_GAZEPOINTDATAEVENTPARAMS, GazePointDataEventParams)
    TX_GAZEPOINTDATAMODE GazePointDataMode;
    TX_REAL Timestamp;
    TX_REAL X;       
    TX_REAL Y;
TX_STRUCT_END(TX_GAZEPOINTDATAEVENTPARAMS, GazePointDataEventParams)

/*********************************************************************************************************************/

/**
  Struct for eye position data behavior event parameters.

  The components of the eye vectors are the relative position of the eyes from the center of the screen in
  millimeters on each axis.
   
  @field Timestamp:
    The point in time when the eye position was captured.
    
  @field HasLeftEyePosition:
    Specifies if the data for the left eye is valid.
    
  @field HasRightEyePosition:
    Specifies if the data for the right eye is valid.
    
  @field LeftEyeX:
    The X coordinate of the left eye in millimiters.
    
  @field LeftEyeY:
    The Y coordinate of the left eye in millimiters.
    
  @field LeftEyeY:
    The Z coordinate of the left eye in millimiters.
    
  @field RightEyeX:
    The X coordinate of the right eye in millimiters.
    
  @field RightEyeY:
    The Y coordinate of the right eye in millimiters.
    
  @field RightEyeZ:
    The Z coordinate of the right eye in millimiters.
 */
TX_STRUCT_BEGIN(TX_EYEPOSITIONDATAEVENTPARAMS, EyePositionDataEventParams)
    TX_REAL Timestamp;
    TX_BOOL HasLeftEyePosition;
    TX_BOOL HasRightEyePosition;
    TX_REAL LeftEyeX;
    TX_REAL LeftEyeY;
    TX_REAL LeftEyeZ;
    TX_REAL RightEyeX;
    TX_REAL RightEyeY;
    TX_REAL RightEyeZ;
TX_STRUCT_END(TX_EYEPOSITIONDATAEVENTPARAMS, EyePositionDataEventParams)

/*********************************************************************************************************************/

/**
  Struct for the threading model.
   
  @field CreateThread:
    Callback function used to create a thread. See TX_CREATETHREADCALLBACK.
    
  @field GetCurrentThreadId:
     Callback function used to get the id of the current (calling) thread. See TX_GETCURRENTTHREADIDCALLBACK.
        
  @field JoinThread:
     Callback function used to join a thread. See TX_JOINTHREADCALLBACK.
    
  @field DeleteThread:
     Callback function used to delete a thread. See TX_DELETETHREADCALLBACK.
    
  @field DeleteModel:
     Callback function used to release the threading model.
    
  @field UserParam:
    User parameter which will be passed to the functions.
 */
TX_STRUCT_BEGIN(TX_THREADINGMODEL, ThreadingModel)
    TX_CREATETHREADCALLBACK       CreateThread;         
    TX_GETCURRENTTHREADIDCALLBACK GetCurrentThreadId;   
    TX_JOINTHREADCALLBACK         JoinThread;           
    TX_DELETETHREADCALLBACK       DeleteThread;         
	TX_DELETEMODELCALLBACK        DeleteModel;
    TX_USERPARAM                  UserParam;            
TX_STRUCT_END(TX_THREADINGMODEL, ThreadingModel)

/*********************************************************************************************************************/

/**
  Struct for the logging model.
   
  @field Targets:
     Specifies which log targets to use. See TX_LOGTARGET.
    
  @field Log:
     Callback function used to write a custom log message. See TX_LOGCALLBACK.
    
  @field DeleteModel:
     Callback function used to release the logging model.
    
  @field UserParam:
    User parameter which will be passed to the custom log function.
 */
TX_STRUCT_BEGIN(TX_LOGGINGMODEL, LoggingModel)
    TX_LOGTARGET Targets;
    TX_LOGCALLBACK Log;        
	TX_DELETEMODELCALLBACK DeleteModel;
    TX_USERPARAM UserParam;    
TX_STRUCT_END(TX_LOGGINGMODEL, LoggingModel)
    
/*********************************************************************************************************************/

/**
  Struct for the scheduling model.
   
  @field Mode:
     Specifies which scheduling mode to use. See TX_SCHEDULINGMODE.
    
  @field Schedule:
     Callback function schedule a work item. See TX_SCHEDULEJOBCALLBACK.
    
  @field DeleteModel:
     Callback function used to release the logging model.
    
  @field UserParam:
    User parameter which will be passed to the custom schedule function.
 */
TX_STRUCT_BEGIN(TX_SCHEDULINGMODEL, SchedulingModel)
    TX_SCHEDULINGMODE Mode;
    TX_SCHEDULEJOBCALLBACK ScheduleJob;        
	TX_DELETEMODELCALLBACK DeleteModel;
    TX_USERPARAM UserParam;    
TX_STRUCT_END(TX_SCHEDULINGMODEL, SchedulingModel)
    
/*********************************************************************************************************************/

#endif /* !defined(__TOBII_TX_TYPES__H__) */

/*********************************************************************************************************************/
