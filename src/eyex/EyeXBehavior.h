/*********************************************************************************************************************
 * Copyright 2013-2014 Tobii Technology AB. All rights reserved.
 * EyeXBehavior.h
 *********************************************************************************************************************/

#if !defined(__TOBII_TX_BEHAVIOR_API__H__)
#define __TOBII_TX_BEHAVIOR_API__H__

/*********************************************************************************************************************/

/**
  txGetBehaviorType

  Gets the TX_INTERACTIONBEHAVIORTYPE of an interaction behavior.
 
  @param hBehavior [in]: 
    A TX_CONSTHANDLE to the behavior.
    Must not be TX_EMPTY_HANDLE.

  @param pBehaviorType [out]: 
    A pointer to a TX_INTERACTIONBEHAVIORTYPE which will be set to the type of the behavior
    Must not be NULL.
 
  @return 
    TX_RESULT_OK: The type of the bounds was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
 */
TX_API_FUNCTION(GetBehaviorType,(
    TX_CONSTHANDLE hBehavior,
    TX_OUT_PARAM(TX_INTERACTIONBEHAVIORTYPE) pBehaviorType
    ));

/*********************************************************************************************************************/

/**
  txSetActivatableBehaviorParams

  Sets TX_ACTIVATABLEPARAMS for an activatable Behavior.
 
  @param hBehavior [in]: 
    A TX_HANDLE to the behavior on which to set the parameters.
    Must not be TX_EMPTY_HANDLE.
 
  @param pParams [in]: 
    A pointer to a TX_ACTIVATABLEPARAMS which specifies the behaviors parameters.
	Must not be NULL.

  @return 
    TX_RESULT_OK: The option was successfully set.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.    
 */ 
TX_API_FUNCTION(SetActivatableBehaviorParams, (
    TX_HANDLE hBehavior,
    TX_IN_PARAM(TX_ACTIVATABLEPARAMS) pParams
    ));

/*********************************************************************************************************************/

/**
  txGetActivatableBehaviorParams

  Gets the TX_ACTIVATABLEPARAMS for an activatable behavior.
 
  @param hBehavior [in]: 
    A TX_CONSTHANDLE to the behavior from which the parameters should be retrieved.
    Must not be TX_EMPTY_HANDLE.
 
  @param pParams [out]: 
    A pointer to a TX_ACTIVATABLEPARAMS which will be set to the behaviors parameters.
	Must not be NULL.
 
  @return 
    TX_RESULT_OK: The parameters was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_INVALIDBEHAVIORTYPE: The behavior was not of type TX_INTERACTIONBEHAVIORTYPE_ACTIVATABLE.
 */ 
TX_API_FUNCTION(GetActivatableBehaviorParams, (
    TX_CONSTHANDLE hBehavior,
    TX_OUT_PARAM(TX_ACTIVATABLEPARAMS) pParams
    ));

/*********************************************************************************************************************/

/**
  txGetActivatableEventType

  Gets the TX_ACTIVABLEEVENTTYPE for an activatable behavior.
 
  @param hBehavior [in]: 
    A TX_CONSTHANDLE to the behavior from which the event type will be retrieved.
    Must not be TX_EMPTY_HANDLE.
 
  @param pEventType [out]: 
    A pointer to a TX_ACTIVATABLEEVENTTYPE which will be set to the event type.
	Must not be NULL.
 
  @return 
    TX_RESULT_OK: The event type was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_INVALIDBEHAVIORTYPE: The behavior was not of type TX_INTERACTIONBEHAVIORTYPE_ACTIVATABLE.
 */
TX_API_FUNCTION(GetActivatableEventType, (
    TX_CONSTHANDLE hBehavior,
    TX_OUT_PARAM(TX_ACTIVATABLEEVENTTYPE) pEventType
    ));

/*********************************************************************************************************************/

/**
  txGetActivationFocusChangedEventParams

  Gets the TX_ACTIVATIONFOCUSCHANGEDEVENTPARAMS for an activatable behavior.
 
  @param hBehavior [in]: 
    A TX_CONSTHANDLE to the behavior from which the event parameters will be retrieved.
    Must not be TX_EMPTY_HANDLE.
 
  @param pEventParams [out]: 
    A pointer to a TX_ACTIVATIONFOCUSCHANGEDEVENTPARAMS which will be set to the behaviors event parameters.
	Must not be NULL.
 
  @return 
    TX_RESULT_OK: The parameters was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_INVALIDBEHAVIORTYPE: The behavior was not of type TX_INTERACTIONBEHAVIORTYPE_ACTIVATABLE.
    TX_RESULT_NOTFOUND: The options could not be found due to invalid event type.
 */
TX_API_FUNCTION(GetActivationFocusChangedEventParams, (
    TX_CONSTHANDLE hBehavior,
    TX_OUT_PARAM(TX_ACTIVATIONFOCUSCHANGEDEVENTPARAMS) pEventParams
    ));

/*********************************************************************************************************************/

/**
  txSetPannableBehaviorParams

  Sets the TX_PANNABLEPARAMS for a pannable behavior.
 
  @param hBehavior [in]: 
    A TX_HANDLE to the behavior on which to set the parameters.
    Must not be TX_EMPTY_HANDLE.
 
  @param pParams [in]: 
    A pointer to a TX_PANNABLEPARAMS which specifies the parameters.
	Must not be NULL.

  @return 
    TX_RESULT_OK: The parameters was successfully set.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_INVALIDBEHAVIORTYPE: The behavior was not of type TX_INTERACTIONBEHAVIORTYPE_PANNABLE.
 */ 
TX_API_FUNCTION(SetPannableBehaviorParams, (
    TX_HANDLE hBehavior,
    TX_IN_PARAM(TX_PANNABLEPARAMS) pParams
    ));

/*********************************************************************************************************************/

/**
  txGetPannableBehaviorParams

  Gets the TX_PANNABLEPARAMS for a pannable behavior.
 
  @param hBehavior [in]: 
    A TX_CONSTHANDLE to the behavior from which the parameters will be retrieved.
    Must not be TX_EMPTY_HANDLE.
 
  @param pParams [out]: 
    A pointer to a TX_PANNABLEPARAMS which will be set to the parameters.
	Must not be NULL.
 
  @return 
    TX_RESULT_OK: The parameters was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_INVALIDBEHAVIORTYPE: The behavior was not of type TX_INTERACTIONBEHAVIORTYPE_PANNABLE.
 */ 
TX_API_FUNCTION(GetPannableBehaviorParams, (
    TX_CONSTHANDLE hBehavior,
    TX_OUT_PARAM(TX_PANNABLEPARAMS) pParams
    ));

/*********************************************************************************************************************/

/**
  txGetPannableEventType

  Gets the TX_PANNABLEEVENTTYPE for a pannable behavior event.
 
  @param hBehavior [in]: 
    A TX_CONSTHANDLE to the behavior from which the event type will be retrieved.
    Must not be TX_EMPTY_HANDLE.
 
  @param pEventType [out]: 
    A pointer to a TX_PANNABLEEVENTTYPE which will be set to the event type.
	Must not be NULL.
 
  @return 
    TX_RESULT_OK: The event type was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_INVALIDBEHAVIORTYPE: The behavior was not of type TX_INTERACTIONBEHAVIORTYPE_PANNABLE.
 */ 
TX_API_FUNCTION(GetPannableEventType, (
    TX_CONSTHANDLE hBehavior,
    TX_OUT_PARAM(TX_PANNABLEEVENTTYPE) pEventType
    ));


/*********************************************************************************************************************/

/**
  txGetPannablePanEventParams

  Gets the TX_PANNABLEPANEVENTPARAMS for a pannable behavior pan event.
 
  @param hBehavior [in]: 
    A TX_CONSTHANDLE to the behavior from which the parameters will be retrieved.
    Must not be TX_EMPTY_HANDLE.
 
  @param pEventParams [out]: 
    A pointer to a TX_PANNABLEPANEVENTPARAMS which will be set to the parameters.
	Must not be NULL.
 
  @return 
    TX_RESULT_OK: The event parameters was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_INVALIDBEHAVIORTYPE: The behavior was not of type TX_INTERACTIONBEHAVIORTYPE_PANNABLE.
 */ 
TX_API_FUNCTION(GetPannablePanEventParams, (
    TX_CONSTHANDLE hBehavior,
    TX_OUT_PARAM(TX_PANNABLEPANEVENTPARAMS) pEventParams
    ));

/*********************************************************************************************************************/

/**
  txGetPannableStepEventParams

  Gets the TX_PANNABLESTEPEVENTPARAMS for a pannable behavior step event.
 
  @param hBehavior [in]: 
    A TX_CONSTHANDLE to the behavior from which the parameters will be retrieved.
    Must not be TX_EMPTY_HANDLE.
 
  @param pEventParams [out]: 
    A pointer to a TX_PANNABLESTEPEVENTPARAMS which will be set to the parameters.
	Must not be NULL.
 
  @return 
    TX_RESULT_OK: The event parameters was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_INVALIDBEHAVIORTYPE: The behavior was not of type TX_INTERACTIONBEHAVIORTYPE_PANNABLE.
 */ 
TX_API_FUNCTION(GetPannableStepEventParams, (
    TX_CONSTHANDLE hBehavior,
    TX_OUT_PARAM(TX_PANNABLESTEPEVENTPARAMS) pEventParams
    ));

/*********************************************************************************************************************/

/**
  txGetPannableHandsFreeEventParams

  Gets the TX_PANNABLEHANDSFREEEVENTPARAMS for a pannable behavior hands free event.
 
  @param hBehavior [in]: 
    A TX_CONSTHANDLE to the behavior from which the parameters will be retrieved.
    Must not be TX_EMPTY_HANDLE.
 
  @param pEventParams [out]: 
    A pointer to a TX_PANNABLEHANDSFREEEVENTPARAMS which will be set to the parameters.
	Must not be NULL.
 
  @return 
    TX_RESULT_OK: The event parameters was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_INVALIDBEHAVIORTYPE: The behavior was not of type TX_INTERACTIONBEHAVIORTYPE_PANNABLE.
 */ 
TX_API_FUNCTION(GetPannableHandsFreeEventParams, (
    TX_CONSTHANDLE hBehavior,
    TX_OUT_PARAM(TX_PANNABLEHANDSFREEEVENTPARAMS) pEventParams
    ));

/*********************************************************************************************************************/

/**
  txSetGazePointDataBehaviorParams

  Sets TX_GAZEPOINTDATAPARAMS for a gaze point data behavior.
 
  @param hBehavior [in]: 
    A TX_HANDLE to the behavior on which to set the parameters.
    Must not be TX_EMPTY_HANDLE.
 
  @param pParams [in]: 
    A pointer to a TX_GAZEPOINTDATAPARAMS which specifies the behavior parameters.
	Must not be NULL.
 
  @return 
    TX_RESULT_OK: The parameters was successfully set.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_INVALIDBEHAVIORTYPE: The behavior was not of type TX_INTERACTIONBEHAVIORTYPE_GAZEPOINTDATA.
 */ 
TX_API_FUNCTION(SetGazePointDataBehaviorParams, (
    TX_HANDLE hBehavior,
    TX_IN_PARAM(TX_GAZEPOINTDATAPARAMS) pParams
    ));

/*********************************************************************************************************************/

/**
  txGetGazePointDataBehaviorParams

  Gets the TX_GAZEPOINTDATAPARAMS for gaze point data behavior.
 
  @param hBehavior [in]: 
    A TX_CONSTHANDLE to the behavior from which the parameter will be retrieved.
    Must not be TX_EMPTY_HANDLE.
 
  @param pParams [out]: 
    A pointer to a TX_GAZEPOINTDATAPARAMS which will be set to the behavior parameters.
	Must not be NULL.
 
  @return 
    TX_RESULT_OK: The parameters was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_INVALIDBEHAVIORTYPE: The behavior was not of type TX_INTERACTIONBEHAVIORTYPE_GAZEPOINTDATA.
 */ 
TX_API_FUNCTION(GetGazePointDataBehaviorParams, (
    TX_CONSTHANDLE hBehavior,
    TX_OUT_PARAM(TX_GAZEPOINTDATAPARAMS) pParams
    ));

/*********************************************************************************************************************/

/**
  txGetGazePointDataEventParams

  Gets the TX_GAZEPOINTDATAEVENTPARAMS for a gaze point behavior.
 
  @param hBehavior [in]: 
    A TX_CONSTHANDLE to the behavior from which the event parameters will be retrieved.
    Must not be TX_EMPTY_HANDLE.
 
  @param pEventParams [out]: 
    A pointer to a TX_GAZEPOINTDATAEVENTPARAMS which will be set to the behavior event parameters.
	Must not be NULL.
 
  @return 
    TX_RESULT_OK: The event parameters was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_INVALIDBEHAVIORTYPE: The behavior is not of type TX_INTERACTIONBEHAVIORTYPE_GAZEPOINTDATA.
 */ 
TX_API_FUNCTION(GetGazePointDataEventParams, (
    TX_CONSTHANDLE hBehavior,
    TX_OUT_PARAM(TX_GAZEPOINTDATAEVENTPARAMS) pEventParams
    ));

/*********************************************************************************************************************/

/**
  txSetGazeAwareBehaviorParams

  Sets TX_GAZEAWAREPARAMS for a gaze aware behavior.
 
  @param hBehavior [in]: 
    A TX_HANDLE to the behavior on which to set the parameters.
    Must not be TX_EMPTY_HANDLE.
 
  @param pParams [in]: 
    A pointer to a TX_GAZEAWAREPARAMS which specifies the behavior parameters.
	Must not be NULL.
 
  @return 
    TX_RESULT_OK: The parameters was successfully set.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_INVALIDBEHAVIORTYPE: The behavior was not of type TX_INTERACTIONBEHAVIORTYPE_GAZEAWARE.
 */ 
TX_API_FUNCTION(SetGazeAwareBehaviorParams, (
    TX_HANDLE hBehavior,
    TX_IN_PARAM(TX_GAZEAWAREPARAMS) pParams
    ));

/*********************************************************************************************************************/

/**
  txGetGazeAwareBehaviorParams

  Gets the TX_GAZEAWAREPARAMS for gaze point data behavior.
 
  @param hBehavior [in]: 
    A TX_CONSTHANDLE to the behavior from which the parameter will be retrieved.
    Must not be TX_EMPTY_HANDLE.
 
  @param pParams [out]: 
    A pointer to a TX_GAZEAWAREPARAMS which will be set to the behavior parameters.
	Must not be NULL.
 
  @return 
    TX_RESULT_OK: The parameters was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_INVALIDBEHAVIORTYPE: The behavior was not of type TX_INTERACTIONBEHAVIORTYPE_GAZEAWARE.
 */ 
TX_API_FUNCTION(GetGazeAwareBehaviorParams, (
    TX_CONSTHANDLE hBehavior,
    TX_OUT_PARAM(TX_GAZEAWAREPARAMS) pParams
    ));

/*********************************************************************************************************************/

/**
  txGetGazeAwareBehaviorEventParams

  Gets the TX_GAZEAWAREEVENTPARAMS for a gaze-aware behavior.
 
  @param hBehavior [in]: 
    A TX_CONSTHANDLE to the behavior from which the event parameters will be retrieved.
    Must not be TX_EMPTY_HANDLE.
 
  @param pEventParams [out]: 
    A pointer to a TX_GAZEAWAREEVENTPARAMS which will be set to the behavior event parameters.
	Must not be NULL.
 
  @return 
    TX_RESULT_OK: The parameters was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_INVALIDBEHAVIORTYPE: The behavior was not of type TX_INTERACTIONBEHAVIORTYPE_GAZEAWARE.
 */
TX_API_FUNCTION(GetGazeAwareBehaviorEventParams, (
    TX_CONSTHANDLE hBehavior,
    TX_OUT_PARAM(TX_GAZEAWAREEVENTPARAMS) pEventParams
    ));

/*********************************************************************************************************************/

/**
  txSetFixationDataBehaviorParams

  Gets the TX_FIXATIONDATAPARAMS for a fixation behavior.
 
  @param hBehavior [in]: 
    A TX_HANDLE to the behavior on which the parameters will be set.
    Must not be TX_EMPTY_HANDLE.
 
  @param pParams [in]: 
    A pointer to a TX_FIXATIONDATAPARAMS which will be set to the behavior parameters.
	Must not be NULL.
 
  @return 
    TX_RESULT_OK: The parameters was successfully set.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_INVALIDBEHAVIORTYPE: The behavior is not of type TX_INTERACTIONBEHAVIOR_FIXATIONDATA.
 */ 
TX_API_FUNCTION(SetFixationDataBehaviorParams, (
    TX_HANDLE hBehavior,
    TX_IN_PARAM(TX_FIXATIONDATAPARAMS) pParams
    ));

/*********************************************************************************************************************/

/**
  txGetFixationDataBehaviorParams

  Gets the TX_FIXATIONDATAPARAMS for a fixation behavior.
 
  @param hBehavior [in]: 
    A TX_CONSTHANDLE to the behavior from which the parameters will be retrieved.
    Must not be TX_EMPTY_HANDLE.
 
  @param pParams [out]: 
    A pointer to a TX_FIXATIONDATAPARAMS which will be set to the behavior parameters.
	Must not be NULL.
 
  @return 
    TX_RESULT_OK: The parameters was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_INVALIDBEHAVIORTYPE: The behavior is not of type TX_INTERACTIONBEHAVIOR_FIXATIONDATA.
 */ 
TX_API_FUNCTION(GetFixationDataBehaviorParams, (
    TX_CONSTHANDLE hBehavior,
    TX_OUT_PARAM(TX_FIXATIONDATAPARAMS) pParams
    ));

/*********************************************************************************************************************/

/**
  txGetFixationDataEventParams

  Gets the TX_FIXATIONDATAEVENTPARAMS for a fixation behavior.
 
  @param hBehavior [in]: 
    A TX_CONSTHANDLE to the behavior from which the event parameters will be retrieved.
    Must not be TX_EMPTY_HANDLE.
 
  @param pEventParams [out]: 
    A pointer to a TX_FIXATIONDATAEVENTPARAMS which will be set to the behavior event parameters.
	Must not be NULL.
 
  @return 
    TX_RESULT_OK: The event parameters was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_INVALIDBEHAVIORTYPE: The behavior is not of type TX_INTERACTIONBEHAVIORTYPE_FIXATIONDATA.
 */ 
TX_API_FUNCTION(GetFixationDataEventParams, (
    TX_CONSTHANDLE hBehavior,
    TX_OUT_PARAM(TX_FIXATIONDATAEVENTPARAMS) pEventParams
    ));

/*********************************************************************************************************************/

/**
  txGetEyePositionDataEventParams

  Gets the TX_EYEPOSITIONDATAEVENTPARAMS for an eye position behavior.
 
  @param hBehavior [in]: 
    A TX_CONSTHANDLE to the behavior from which the event parameters will be retrieved.
    Must not be TX_EMPTY_HANDLE.
 
  @param pEventParams [out]: 
    A pointer to a TX_EYEPOSITIONDATAEVENTPARAMS which will be set to the behavior event parameters.
	Must not be NULL.
 
  @return 
    TX_RESULT_OK: The event parameters was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_INVALIDBEHAVIORTYPE: The behavior is not of type TX_INTERACTIONBEHAVIORTYPE_EYEPOSITIONDATA.
 */ 
TX_API_FUNCTION(GetEyePositionDataEventParams, (
    TX_CONSTHANDLE hBehavior,
    TX_OUT_PARAM(TX_EYEPOSITIONDATAEVENTPARAMS) pEventParams
    ));

/*********************************************************************************************************************/

#endif /* !defined(__TOBII_TX_BEHAVIOR_API__H__) */

/*********************************************************************************************************************/
