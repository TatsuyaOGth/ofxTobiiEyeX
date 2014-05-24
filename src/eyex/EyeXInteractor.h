/*********************************************************************************************************************
 * Copyright 2013-2014 Tobii Technology AB. All rights reserved.
 * EyeXInteractor.h
 *********************************************************************************************************************/

#if !defined(__TOBII_TX_INTERACTOR_API__H__)
#define __TOBII_TX_INTERACTOR_API__H__

/*********************************************************************************************************************/

/**
  txGetInteractorId

  Gets the id of an interactor.
 
  @param hInteractor [in]: 
    A TX_CONSTHANDLE to the interactor for which the id should be retrieved.
    Must not be TX_EMPTY_HANDLE.
 
  @param pInteractorId [out]: 
    A TX_STRING to which the interactor id will be copied.
    Must be at least the size of the interactor id.
    Can be NULL to only get the size of the interactor id.
 
  @param pInteractorIdSize [in,out]: 
    A pointer to a TX_SIZE which will be set the size of the interactor id.
    Must not be NULL. 
    The value must be 0 if pInteractorId is NULL.
 
  @return 
    TX_RESULT_OK: The interactor id or the required size of the string was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_INVALIDBUFFERSIZE: The size of pInteractorId is invalid (*pInteractorIdSize will be set to the required size).
 */
TX_API_FUNCTION(GetInteractorId,(
    TX_CONSTHANDLE hInteractor, 
    TX_STRING pInteractorId,
    TX_REF_PARAM(TX_SIZE) pInteractorIdSize
    ));

/*********************************************************************************************************************/

/**
  txGetInteractorParentId

  Gets the id of an interactors parent.
 
  @param hInteractor [in]: 
    A TX_CONSTHANDLE to the interactor for which the parent id should be retrieved.
    Must not be TX_EMPTY_HANDLE.
 
  @param pParentInteractorId [out]: 
    A TX_STRING to which the parent interactor id will be copied.
    Must be at least the size of the parent interactor id.
    Can be NULL to only get the size of the parent interactor id.
 
  @param pInteractorParentIdSize [in,out]: 
    A pointer to a TX_SIZE which will be set the size of the parent interactor id.
    Must not be NULL. 
    The value must be 0 if pParentInteractorId is NULL.
 
  @return 
    TX_RESULT_OK: The parent interactor id or the required size of the string was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_INVALIDBUFFERSIZE: The size of pParentInteractorId is invalid (*pInteractorParentIdSize will be set to the required size).
 */
TX_API_FUNCTION(GetInteractorParentId,(
    TX_CONSTHANDLE hInteractor, 
    TX_STRING pParentInteractorId,
    TX_REF_PARAM(TX_SIZE) pInteractorParentIdSize
    ));

/*********************************************************************************************************************/

/**
  txGetInteractorWindowId

  Gets the window id of the interactor.
 
  @param hInteractor [in]: 
    A TX_CONSTHANDLE to the interactor for which the window id should be retrieved.
    Must not be TX_EMPTY_HANDLE.
 
  @param pWindowId [out]: 
    A TX_STRING to which the window id will be copied.
    Must be at least the size of the window id.
    Can be NULL to only get the size of the window id.
 
  @param pWindowIdSize [in,out]: 
    A pointer to a TX_SIZE which will be set the size of the window id.
    Must not be NULL. 
    The value must be 0 if pWindowId is NULL.
 
  @return 
    TX_RESULT_OK: The window id or the required size of the string was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_INVALIDBUFFERSIZE: The size of pWindowId is invalid (*pWindowIdSize will be set to the required size).
 */
TX_API_FUNCTION(GetInteractorWindowId,(
    TX_CONSTHANDLE hInteractor, 
    TX_STRING pWindowId,
    TX_REF_PARAM(TX_SIZE) pWindowIdSize
    ));

/*********************************************************************************************************************/

/**
  txSetInteractorZ

  Sets the z value of an interactor.
  The z value of an interactor is used to specify which interactor lies on top of which among siblings.
  Note that the z value is local on each level of interactors and therefore only concerns interactors with the same parent.
  The z value must be a non negative TX_REAL.
  This call will overwrite any previously set z value.
 
  @param hInteractor [in]: 
    A TX_HANDLE to the interactor for which to set the z value.
    Must not be TX_EMPTY_HANDLE.
 
  @param z [in]: 
    The z value as a TX_REAL.
    Must be a non negative TX_REAL.
 
  @return 
    TX_RESULT_OK: The z value was successfully set.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
 */
TX_API_FUNCTION(SetInteractorZ,(
    TX_HANDLE hInteractor, 
    TX_REAL z
    ));

/*********************************************************************************************************************/

/**
  txGetInteractorZ

  Gets the z value of an interactor.
 
  @param hInteractor [in]: 
    A TX_CONSTHANDLE to the interactor for which to get the z value.
    Must not be TX_EMPTY_HANDLE.
 
  @param pZ [out]: 
    The pointer to a TX_REAL which will be set to the z value.
    Must not be NULL.
 
  @return 
    TX_RESULT_OK: The z value was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
 */
TX_API_FUNCTION(GetInteractorZ,(
    TX_CONSTHANDLE hInteractor, 
    TX_OUT_PARAM(TX_REAL) pZ
    ));

/*********************************************************************************************************************/

/**
  txSetInteractorEnabled

  Sets a TX_BOOL flag which specifies if an interactor is enabled or not.
  This call will overwrite any previously set enabled flag.
  The default value is false.
 
  @param hInteractor [in]: 
    A TX_HANDLE to the interactor to enable/disable.
    Must not be TX_EMPTY_HANDLE.
 
  @param enabled [in]: 
    The flag as a TX_BOOL.
 
  @return 
    TX_RESULT_OK: The interactor was successfully set to enabled/disabled.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
 */
TX_API_FUNCTION(SetInteractorEnabled,(
    TX_HANDLE hInteractor, 
    TX_BOOL enabled
    ));

/*********************************************************************************************************************/

/**
  txGetInteractorEnabled

  Gets the enabled flag from the interactor.
 
  @param hInteractor [in]: 
    A TX_CONSTHANDLE to the interactor for which to get the enabled flag.
    Must not be TX_EMPTY_HANDLE.
 
  @param pEnabled [out]: 
    The pointer to a TX_BOOL which will be set to the enabled flag value.
    Must not be NULL.
 
  @return 
    TX_RESULT_OK: The enabled flag was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
 */
TX_API_FUNCTION(GetInteractorEnabled,(
    TX_CONSTHANDLE hInteractor, 
    TX_OUT_PARAM(TX_BOOL) pEnabled
    ));

/*********************************************************************************************************************/

/**
  txSetInteractorDeleted

  Sets a TX_BOOL flag which specifies if an interactor is deleted or not.
  This call will overwrite any previously set deleted flag.
  The default value is false.
 
  @param hInteractor [in]: 
    A TX_HANDLE to the interactor to set as deleted.
    Must not be TX_EMPTY_HANDLE.
 
  @param deleted [in]: 
    The flag as a TX_BOOL.
 
  @return 
    TX_RESULT_OK: The deleted flag on the interactor was successfully set.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
 */
TX_API_FUNCTION(SetInteractorDeleted,(
    TX_HANDLE hInteractor, 
    TX_BOOL deleted
    ));

/*********************************************************************************************************************/

/**
  txGetInteractorDeleted

  Gets the deleted flag from the interactor.
 
  @param hInteractor [in]: 
    A TX_CONSTHANDLE to the interactor for which to get the deleted flag.
    Must not be TX_EMPTY_HANDLE.
 
  @param pDeleted [out]: 
    The pointer to a TX_BOOL which will be set to the deleted flag value.
    Must not be NULL.
 
  @return 
    TX_RESULT_OK: The deleted flag was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
 */
TX_API_FUNCTION(GetInteractorDeleted,(
    TX_CONSTHANDLE hInteractor, 
    TX_OUT_PARAM(TX_BOOL) pDeleted
    ));

/*********************************************************************************************************************/

/**
  txCreateInteractorBounds

  Creates bounds on an interactor.
  If the interactor already has bounds this call will fail.
  The bounds will be owned by the interactor and does not need to be deleted explicitly.
 
  @param hInteractor [in]: 
    A TX_HANDLE to the interactor on which the bounds should be created.
    Must not be TX_EMPTY_HANDLE.
 
  @param phBounds [out]: 
    A pointer to a TX_HANDLE which will be set to the newly created bounds.
    This handle must be released using txReleaseObject to avoid leaks.
    Must not be NULL.
    The value of the pointer must be set to TX_EMPTY_HANDLE.
 
  @param boundsType [in]: 
    The TX_INTERACTIONBOUNDSTYPE which specifies what kind of bounds to create.
 
  @return 
    TX_RESULT_OK: The bounds was successfully created.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_DUPLICATEBOUNDS: This interactor already has bounds.
 */
TX_API_FUNCTION(CreateInteractorBounds,(
    TX_HANDLE hInteractor,
    TX_OUT_PARAM(TX_HANDLE) phBounds,
    TX_INTERACTIONBOUNDSTYPE boundsType
    ));

/*********************************************************************************************************************/

/**
  txDeleteInteractorBounds

  Deletes the bounds on an interactor.
  If the interactor does not have any bounds this call will fail.
  The bounds object is owned by the interactor and does not need to be deleted explicitly.
 
  @param hInteractor [in]: 
    A TX_HANDLE to the interactor on which to delete the bounds.
    Must not be TX_EMPTY_HANDLE.
 
  @return 
    TX_RESULT_OK: The bounds was successfully deleted.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_NOTFOUND: This interactor does not have any bounds.
 */
TX_API_FUNCTION(DeleteInteractorBounds,(
    TX_HANDLE hInteractor
    ));

/*********************************************************************************************************************/

/**
  txGetInteractorBounds

  Gets the bounds of an interactor.
  If the interactor does not have any bounds this call will fail.
 
  @param hInteractor [in]: 
    A TX_CONSTHANDLE to the interactor from which the bounds should be retrieved.
    Must not be TX_EMPTY_HANDLE.
 
  @param phBounds [out]: 
    A pointer to a TX_HANDLE which will be set to the bounds on the interactor.    
    This handle must be released using txReleaseObject to avoid leaks.
    Must not be NULL.
    The value of the pointer must be set to TX_EMPTY_HANDLE.
 
  @return 
    TX_RESULT_OK: The bounds was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_NOTFOUND: This interactor does not have any bounds.
 */
TX_API_FUNCTION(GetInteractorBounds,(
    TX_CONSTHANDLE hInteractor,
    TX_OUT_PARAM(TX_HANDLE) phBounds
    ));

/*********************************************************************************************************************/

/**
  txCreateInteractorBehavior

  Creates a behavior of a specified TX_INTERACTIONBEHAVIORTYPE on an interactor.
  If the interactor already has a behavior of the specified type this call will fail.
  The behavior will be owned by the interactor and does not need to be removed explicitly.
 
  @param hInteractor [in]: 
    A TX_HANDLE to the interactor on which the behavior should be created.
    Must not be TX_EMPTY_HANDLE.
 
  @param phBehavior [out]: 
    A pointer to a TX_HANDLE which will be set to the newly created behavior.
    This handle must be released using txReleaseObject to avoid leaks.
    Must not be NULL.
    The value of the pointer must be set to TX_EMPTY_HANDLE.
 
  @param behaviorType [in]: 
    The TX_INTERACTIONBEHAVIORTYPE which specifies what type of behavior to create.
 
  @return 
    TX_RESULT_OK: The behavior was successfully created.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_DUPLICATEBEHAVIOR: This interactor already has a behavior of the specified type.
 */
TX_API_FUNCTION(CreateInteractorBehavior,(
    TX_HANDLE hInteractor,
    TX_OUT_PARAM(TX_HANDLE) phBehavior,
    TX_INTERACTIONBEHAVIORTYPE behaviorType
    ));

/*********************************************************************************************************************/

/**
  txRemoveInteractorBehavior

  Removes a TX_INTERACTIONBEHAVIORTYPE from an interactor.
  If the interactor does not have a behavior of the specified type this call will fail.
 
  @param hInteractor [in]: 
    A TX_HANDLE to the interactor from which the behavior should be removed.
    Must not be TX_EMPTY_HANDLE.
 
  @param behaviorType [in]: 
    The TX_INTERACTIONBEHAVIORTYPE which specifies what type of behavior to remove.
 
  @return 
    TX_RESULT_OK: The behavior was successfully removed.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_NOTFOUND: This interactor does not have a behavior of the specified type.
 */
TX_API_FUNCTION(RemoveInteractorBehavior,(
    TX_HANDLE hInteractor,    
    TX_INTERACTIONBEHAVIORTYPE behaviorType
    ));

/*********************************************************************************************************************/

/**
  txGetInteractorBehavior

  Gets a TX_INTERACTIONBEHAVIORTYPE from an interactor.
  If the interactor does not have a behavior of the specified type this call will fail.
 
  @param hInteractor [in]: 
    A TX_CONSTHANDLE to the interactor from which the behavior should be retrieved.
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
    TX_RESULT_NOTFOUND: This interactor does not have a behavior of the specified type.
 */
TX_API_FUNCTION(GetInteractorBehavior,(
    TX_CONSTHANDLE hInteractor,
    TX_OUT_PARAM(TX_HANDLE) phBehavior,
    TX_INTERACTIONBEHAVIORTYPE behaviorType
    ));

/*********************************************************************************************************************/

/**
  txGetInteractorBehaviors

  Gets the TX_HANDLEs to all behaviors on an interactor.
 
  @param hInteractor [in]: 
    A TX_CONSTHANDLE to the interactor from which to get the behaviors.
    Must not be TX_EMPTY_HANDLE.
 
  @param phBehaviors [out]: 
    A pointer to an array of TX_HANDLEs to which the behavior handles will be copied.
    These handles must be released using txReleaseObject to avoid leaks.
    Can be NULL to only get the size.
 
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
TX_API_FUNCTION(GetInteractorBehaviors,(
    TX_CONSTHANDLE hInteractor,
    TX_PTR_PARAM(TX_HANDLE) phBehaviors,
    TX_REF_PARAM(TX_SIZE) pBehaviorsSize
    ));

/*********************************************************************************************************************/

/**
  txSetGazeAwareBehavior

  Makes sure that the interactor has an gaze point data behavior and sets the specified parameters.
  The behavior will be created if it does not exist.
 
  @param hInteractor [in]: 
    A TX_HANDLE to the interactor that should have the behavior.
    Must not be TX_EMPTY_HANDLE.

  @param pParams [in]: 
    A pointer to a TX_GAZEAWAREARAMS which specifies the behaviors parameters.
	Must not be NULL.
 
  @return 
    TX_RESULT_OK: The behavior was successfully set.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
 */
TX_API_FUNCTION(SetGazeAwareBehavior, (
    TX_HANDLE hInteractor,
    TX_IN_PARAM(TX_GAZEAWAREPARAMS) pParams
    ));

/*********************************************************************************************************************/

/**
  txSetActivatableBehavior

  Makes sure that the interactor has an activatable behavior and sets the specified parameters.
  The behavior will be created if it does not exist.
 
  @param hInteractor [in]: 
    A TX_HANDLE to the interactor that should have the behavior.
    Must not be TX_EMPTY_HANDLE.

  @param pParams [in]: 
    A pointer to a TX_ACTIVATABLEPARAMS which specifies the behaviors parameters.
	Must not be NULL.
 
  @return 
    TX_RESULT_OK: The behavior was successfully set.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
 */
TX_API_FUNCTION(SetActivatableBehavior, (
    TX_HANDLE hInteractor,
    TX_IN_PARAM(TX_ACTIVATABLEPARAMS) pParams
    ));

/*********************************************************************************************************************/

/**
  txSetPannableBehavior

  Makes sure that the interactor has a pannable behavior and sets the specified parameters.
  The behavior will be created if it does not exist.
 
  @param hInteractor [in]: 
    A TX_HANDLE to the interactor that should have the behavior.
    Must not be TX_EMPTY_HANDLE.

  @param pParams [in]: 
    A pointer to a TX_PANNABLEPARAMS which specifies the behaviors parameters.
	Must not be NULL.
 
  @return 
    TX_RESULT_OK: The behavior was successfully set.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
 */
TX_API_FUNCTION(SetPannableBehavior, (
    TX_HANDLE hInteractor,
    TX_IN_PARAM(TX_PANNABLEPARAMS) pParams
    ));

/*********************************************************************************************************************/

/**
  txSetGazePointDataBehavior

  Makes sure that the interactor has a gaze point data behavior and sets the specified parameters.
  The behavior will be created if it does not exist.
 
  @param hInteractor [in]: 
    A TX_HANDLE to the interactor that should have the behavior.
    Must not be TX_EMPTY_HANDLE.

  @param pParams [in]: 
    A pointer to a TX_GAZEPOINTDATAPARAMS which specifies the behaviors parameters.
	Must not be NULL.
 
  @return 
    TX_RESULT_OK: The behavior was successfully set.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
 */
TX_API_FUNCTION(SetGazePointDataBehavior, (
    TX_HANDLE hInteractor,
    TX_IN_PARAM(TX_GAZEPOINTDATAPARAMS) pParams
    ));

/*********************************************************************************************************************/

/**
  txSetFixationDataBehavior

  Makes sure that the interactor has a fixation data behavior and sets the specified parameters.
  The behavior will be created if it does not exist.
 
  @param hInteractor [in]: 
    A TX_HANDLE to the interactor that should have the behavior.
    Must not be TX_EMPTY_HANDLE.

  @param options [in]: 
    A pointer to a TX_FIXATIONDATAPARAMS which specifies the behaviors parameters.
	Must not be NULL.
 
  @return 
    TX_RESULT_OK: The behavior was successfully set.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
 */
TX_API_FUNCTION(SetFixationDataBehavior, (
    TX_HANDLE hInteractor,
    TX_IN_PARAM(TX_FIXATIONDATAPARAMS) pParams
    ));

/*********************************************************************************************************************/

/**
  txCreateInteractorMask

  Creates an interation mask on an interactor.
  The mask is defined by a matrix of size columnCount * rowCount. The usage of each element in the matrix varies 
  between diffrent TX_MASKTYPEs.
   
  @param hInteractor [in]: 
    A TX_HANDLE to interactor on which to create the mask.
    Must not be TX_EMPTY_HANDLE.
        
  @param phMask [out]: 
    A pointer to a TX_HANDLE which will be set to the newly created interaction mask.
    Must not be NULL.
    The value of the pointer must be set to TX_EMPTY_HANDLE.
 
  @param maskType [in]: 
    The type of mask to create. See TX_MASKTYPE.

  @param columnCount [in]: 
    The width of the mask.
	Must be a positive TX_INTEGER.
 
  @param rowCount [in]: 
    The height of the mask.
	Must be a positive TX_INTEGER.
 
  @param pData [in]: 
    A pointer to buffer of TX_BYTEs which contains the mask elements.
    See TX_MASKTYPE for details about mask data for different types.
	Must not be NULL.
  
  @return 
    TX_RESULT_OK: The interaction mask was successfully set.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
 */ 
TX_API_FUNCTION(CreateInteractorMask, (
    TX_HANDLE hInteractor,
    TX_OUT_PARAM(TX_HANDLE) phMask,
	TX_MASKTYPE maskType,
    TX_INTEGER columnCount,
    TX_INTEGER rowCount,
    TX_CONSTPTR_PARAM(TX_BYTE) pData
    ));

/*********************************************************************************************************************/

/**
  txRemoveInteractorMask

  Removes an interation mask from an interactor.
  
  @param hInteractor [in]: 
    A TX_HANDLE to interactor on which to create the mask.
    Must not be TX_EMPTY_HANDLE.
  
  @return 
    TX_RESULT_OK: The interaction mask was successfully removed.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
 */
TX_API_FUNCTION(RemoveInteractorMask, (
    TX_HANDLE hInteractor
    ));

/*********************************************************************************************************************/

/**
  txGetInteractorMask

  Retrieves the mask from an interactor.
  
  @param hInteractor [in]: 
    A TX_CONSTHANDLE to interactor from which to get the mask.
    Must not be TX_EMPTY_HANDLE.

   @param phMask [out]: 
    A pointer to a TX_HANDLE which will be set to the interaction mask.
    Must not be NULL.
    The value of the pointer must be set to TX_EMPTY_HANDLE.
   
  @return 
    TX_RESULT_OK: The interaction mask was successfully removed.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_NOTFOUND: The interactor does not have an interaction mask.
 */
TX_API_FUNCTION(GetInteractorMask, (
    TX_CONSTHANDLE hInteractor,
    TX_OUT_PARAM(TX_HANDLE) phMask
    ));

/*********************************************************************************************************************/

/**
  txGetInteractionMaskData

  Gets the data of an interaction mask.
   
  @param hMask [in]: 
    A TX_CONSTHANDLE to interaction mask for which to get the data.
    Must not be TX_EMPTY_HANDLE.
 
  @param pColumnCount [out]: 
    A TX_INTEGER which will be set to the width of the mask.
    Must not be NULL.
 
  @param pRowCount [out]: 
    A TX_INTEGER which will be set to the height of the mask.
    Must not be NULL.
 
  @param pData [out]: 
    A pointer to buffer of TX_BYTEs which contains the mask elements.
    Can be NULL to only get the size of the mask.

  @param pDataSize [in,out]:
    A pointer to a TX_SIZE which will be set to the size of the data buffer.
    Can be NULL to only get the size of the mask.
    The value must be 0 if phObjects is NULL.
  
  @return 
    TX_RESULT_OK: The data of the interaction mask or the required buffer size was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDBUFFERSIZE: The size of the buffer was to small. (*pDataSize will be set to the required size if not NULL.)
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
 */ 
TX_API_FUNCTION(GetInteractionMaskData, (
    TX_CONSTHANDLE hMask,
    TX_OUT_PARAM(TX_INTEGER) pColumnCount,
    TX_OUT_PARAM(TX_INTEGER) pRowCount,
    TX_PTR_PARAM(TX_BYTE) pData,
    TX_REF_PARAM(TX_SIZE) pDataSize
    ));

/*********************************************************************************************************************/

/**
  txSetInteractorMaskBounds

  Sets the bounds of the mask.
  By default a mask covers the entire interactor.
   
  @param hInteractor [in]: 
    A TX_HANDLE to interactor for which to set the mask bounds.
    Must not be TX_EMPTY_HANDLE.
 
  @param pBounds [in]: 
    A pointer to a TX_RECT which holds the rectangle data.
    Must not be NULL.
   
  @return 
    TX_RESULT_OK: The bounds of the interaction mask was successfully set.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
 */ 
TX_API_FUNCTION(SetInteractorMaskBounds, (
    TX_HANDLE hInteractor,
    TX_IN_PARAM(TX_RECT) pBounds
    ));

/*********************************************************************************************************************/

/**
  txClearInteractorMaskBounds

  Clears the mask bounds of an interactor.
   
  @param hInteractor [in]: 
    A TX_HANDLE to interactor for which to set the mask bounds.
    Must not be TX_EMPTY_HANDLE.
    
  @return 
    TX_RESULT_OK: The bounds of the interaction mask was successfully cleared.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
 */ 
TX_API_FUNCTION(ClearInteractorMaskBounds, (
    TX_HANDLE hInteractor
    ));

/*********************************************************************************************************************/

/**
  txGetInteractorMaskBounds

  Gets the bounds of the mask.
   
  @param hInteractor [in]: 
    A TX_CONSTHANDLE to interactor from which to set the mask bounds.
    Must not be TX_EMPTY_HANDLE.
 
  @param pBounds [out]:    
    A pointer to a TX_RECT which will hold the rectangle data.
    Must not be NULL.
   
  @return 
    TX_RESULT_OK: The bounds of the interaction mask was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
    TX_RESULT_NOTFOUND: The interactor does not have any mask bounds specified.
 */ 
TX_API_FUNCTION(GetInteractorMaskBounds, (
    TX_CONSTHANDLE hInteractor,
    TX_OUT_PARAM(TX_RECT) pBounds
    ));

/*********************************************************************************************************************/

#endif /* !defined(__TOBII_TX_INTERACTOR_API__H__) */

/*********************************************************************************************************************/
