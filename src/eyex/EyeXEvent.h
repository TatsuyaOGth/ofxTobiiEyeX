/*********************************************************************************************************************
 * Copyright 2013-2014 Tobii Technology AB. All rights reserved.
 * EyeXEvent.h
 *********************************************************************************************************************/

#if !defined(__TOBII_TX_EVENT_API__H__)
#define __TOBII_TX_EVENT_API__H__

/*********************************************************************************************************************/

/**
  txGetEventInteractorId

  Gets the id of the interactor for which the event should apply.
 
  @param hEvent [in]: 
    A TX_CONSTHANDLE to the event from which the interactor id should be retrieved.
    Must not be TX_EMPTY_HANDLE.
 
  @param pInteractorId [out]: 
    A TX_STRING to which the interactor id will be copied.
    Must be at least the size of the interactor id.
    Can be NULL to only get the size of the interactor.
 
  @param pInteractorIdSize [in,out]: 
    A pointer to a TX_SIZE which will be set to the size of the interactor id.
    Must not be NULL.
    The value must be 0 if pInteractorId is NULL.
 
  @return 
    TX_RESULT_OK: The interactor id or the required size of the string was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_INVALIDBUFFERSIZE: The size of pInteractorId is invalid (*pInteractorIdSize will be set to the required size).
 */
TX_API_FUNCTION(GetEventInteractorId,(
    TX_CONSTHANDLE hEvent, 
    TX_STRING pInteractorId,
    TX_REF_PARAM(TX_SIZE) pInteractorIdSize
    ));

/*********************************************************************************************************************/

/**
  txGetEventBehavior

  Gets a behavior with a specified TX_INTERACTIONBEHAVIORTYPE from an event.
  If the event does not have a behavior of the specified type this call will fail.
 
  @param hEvent [in]: 
    A TX_CONSTHANDLE to the event from which the behavior should be retrieved.
    Must not be TX_EMPTY_HANDLE.
 
  @param phBehavior [out]: 
    A pointer to a TX_HANDLE which will be set to the behavior.
    This handle must be released using txReleaseObject to avoid leaks.
    Must not be NULL.
    The value of the pointer must be set to TX_EMPTY_HANDLE.
 
  @param behaviorType [in]: 
    The TX_INTERACTIONBEHAVIORTYPE which specifies what type of behavior to get.
 
  @return 
    TX_RESULT_OK: The behavior was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_NOTFOUND: This event does not have a behavior of the specified type.
 */
TX_API_FUNCTION(GetEventBehavior,(
    TX_CONSTHANDLE hEvent,
    TX_OUT_PARAM(TX_HANDLE) phBehavior,
    TX_INTERACTIONBEHAVIORTYPE behaviorType
    ));
  
/*********************************************************************************************************************/

/**
  txGetEventBehaviors

  Gets the TX_HANDLEs to all the behaviors on an event.
 
  @param hEvent [in]: 
    A TX_CONSTHANDLE to the event from which to get the behaviors.
    Must not be TX_EMPTY_HANDLE.
 
  @param phBehaviors [out]: 
    A pointer to an array of TX_HANDLEs to which the behavior handles will be copied.
    These handles must be released using txReleaseObject to avoid leaks.
    Can be NULL to only get the required size.
 
  @param pBehaviorsSize [in,out]: 
    A pointer to a TX_SIZE which will be set to the number of behaviors.
    Must not be NULL.
    The value must be 0 if phBehaviors is NULL.
 
  @return 
    TX_RESULT_OK: The handles or the required size of the buffer was retrieved successfully.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_INVALIDBUFFERSIZE: The size of the array is invalid. (*pBehaviorsSize will be set to the number of behaviors).
 */
TX_API_FUNCTION(GetEventBehaviors,(
    TX_CONSTHANDLE hEvent,
    TX_PTR_PARAM(TX_HANDLE) phBehaviors,
    TX_REF_PARAM(TX_SIZE) pBehaviorsSize
    ));

/*********************************************************************************************************************/

#endif /* !defined(__TOBII_TX_EVENT_API__H__) */

/*********************************************************************************************************************/
