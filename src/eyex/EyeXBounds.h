/*********************************************************************************************************************
 * Copyright 2013-2014 Tobii Technology AB. All rights reserved.
 * EyeXBounds.h
 *********************************************************************************************************************/

#if !defined(__TOBII_TX_BOUNDS_API__H__)
#define __TOBII_TX_BOUNDS_API__H__

/*********************************************************************************************************************/

/**
  txGetInteractionBoundsType

  Gets the TX_INTERACTIONBOUNDSTYPE of an interaction bounds object.

  @param hBounds [in]: 
    A TX_CONSTHANDLE to the bounds.
    Must not be TX_EMPTY_HANDLE.
 
  @param pBoundsType [out]: 
    A pointer to a TX_INTERACTIONBOUNDSTYPE which will be set to the type of the bounds.
    Must not be NULL.
 
  @return 
    TX_RESULT_OK: The type of the bounds was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.
 */
TX_API_FUNCTION(GetInteractionBoundsType,(
    TX_CONSTHANDLE hBounds,
    TX_OUT_PARAM(TX_INTERACTIONBOUNDSTYPE) pBoundsType
    ));

/*********************************************************************************************************************/

/**
  txSetRectangularBoundsData

  Sets rectangular bounds data for a bounds object.
 
  @param hBounds [in]: 
    A TX_HANDLE to the bounds on which to set the rectangle.
    Must not be TX_EMPTY_HANDLE.
 
  @param x [in]: 
    Position of left edge of the rectangle.
 
  @param y [in]: 
    Position of top edge of the rectangle.
 
  @param width [in]: 
    Width of the rectangle. Must not be negative.
 
  @param height [in]: 
    Height of the rectangle. Must not be negative.
 
  @return 
    TX_RESULT_OK: The rectanglar data was successfully set.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.    
    TX_RESULT_INVALIDBOUNDSTYPE: The bounds type was invalid, must be TX_INTERACTIONBOUNDSTYPE_RECTANGULAR.
 */ 
TX_API_FUNCTION(SetRectangularBoundsData, (
    TX_HANDLE hBounds,
    TX_REAL x,
    TX_REAL y,
    TX_REAL width,
    TX_REAL height
    ));

/*********************************************************************************************************************/

/**
  txSetRectangularBoundsDataRect

  Sets rectangular bounds data for a bounds object.
 
  @param hBounds [in]: 
    A TX_HANDLE to the bounds object on which to set the rectangle.
    Must not be TX_EMPTY_HANDLE.
 
  @param pRect [in]: 
    A pointer to a TX_RECT which holds the rectangular data.
    Must not be NULL.
 
  @return 
    TX_RESULT_OK: The rectanglar data was successfully set.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.    
    TX_RESULT_INVALIDBOUNDSTYPE: The bounds type was invalid, must be TX_INTERACTIONBOUNDSTYPE_RECTANGULAR.
 */ 
TX_API_FUNCTION(SetRectangularBoundsDataRect, (
    TX_HANDLE hBounds,
    TX_IN_PARAM(TX_RECT) pRect
    ));

/*********************************************************************************************************************/

/**
  txGetRectangularBoundsData

  Gets rectangular bounds data from a bounds object.
 
  @param hBounds [in]: 
    A TX_CONSTHANDLE to the bounds object from which to get the rectangular data.
    Must not be TX_EMPTY_HANDLE.
 
  @param pX [out]: 
    A pointer to a TX_REAL which will be set to the position of the left edge of the rectangle.
	Must not be NULL.
 
  @param pY [out]: 
    A pointer to a TX_REAL which will be set to the position of the top edge of the rectangle.
	Must not be NULL.
 
  @param pWidth [out]: 
    A pointer to a TX_REAL which will be set to the width of the rectangle.
	Must not be NULL.
 
  @param height [out]: 
    A pointer to a TX_REAL which will be set to the height of the rectangle.
	Must not be NULL.
 
  @return 
    TX_RESULT_OK: The rectangular data was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.    
    TX_RESULT_INVALIDBOUNDSTYPE: The bounds type is invalid, must be TX_INTERACTIONBOUNDSTYPE_RECTANGULAR.
 */ 
TX_API_FUNCTION(GetRectangularBoundsData, (
    TX_CONSTHANDLE hBounds,
    TX_OUT_PARAM(TX_REAL) pX,
    TX_OUT_PARAM(TX_REAL) pY,
    TX_OUT_PARAM(TX_REAL) pWidth,
    TX_OUT_PARAM(TX_REAL) pHeight
    ));

/*********************************************************************************************************************/

/**
  txGetRectangularBoundsDataRect

  Gets rectangular bounds data from a bounds object.
 
  @param hBounds [in]: 
    A TX_CONSTHANDLE to the Bounds on which to get the rectangle data.
    Must not be TX_EMPTY_HANDLE.
 
  @param pRect [out]: 
    A pointer to a TX_RECT which will hold the rectangle data.
	Must not be NULL.
   
  @return 
    TX_RESULT_OK: The rectangular data was successfully retrieved.
    TX_RESULT_SYSTEMNOTINITIALIZED: The system is not initialized.
    TX_RESULT_INVALIDARGUMENT: An invalid argument was passed to the function.    
    TX_RESULT_INVALIDBOUNDSTYPE: The bounds type is invalid, must be TX_INTERACTIONBOUNDSTYPE_RECTANGULAR.
 */ 
TX_API_FUNCTION(GetRectangularBoundsDataRect, (
    TX_CONSTHANDLE hBounds,
    TX_OUT_PARAM(TX_RECT) pRect
    ));

/*********************************************************************************************************************/

/**
  txRectanglesIntersects

  Checks if two rectangles intersects.
  
  @param x1 [in]: 
    The upper left x coordinate of the first rectangle

  @param y1 [in]: 
    The upper left y coordinate of the first rectangle

  @param width1 [in]: 
    The width of the first rectangle

  @param height1 [in]: 
    The height of the first rectangle

  @param x2 [in]: 
    The upper left x coordinate of the second rectangle

  @param y2 [in]: 
    The upper left y coordinate of the second rectangle

  @param width2 [in]: 
    The width of the second rectangle

  @param height2 [in]: 
    The height of the second rectangle

  @param pIntersects [out]
    The intersection test result. Will be non-zero if rectangles intersects.
	Must not be NULL.
*/
TX_API_FUNCTION(RectanglesIntersects, (
    TX_REAL x1,
    TX_REAL y1,
    TX_REAL width1,
    TX_REAL height1,
    TX_REAL x2,
    TX_REAL y2,
    TX_REAL width2,
    TX_REAL height2,
    TX_OUT_PARAM(TX_BOOL) pIntersects
    ));

/*********************************************************************************************************************/

/**
  txRectanglesIntersectsRect

  Checks if two rectangles intersects.

  @param x1 [in]: 
    The upper left x coordinate of the first rectangle

  @param pRect1 [in, out]: 
    The first rectangle

  @param pRect2 [in, out]: 
    The second rectangle

  @param pIntersects [out]
    The intersection test result. Will be non-zero if rectangles intersects.
*/
TX_API_FUNCTION(RectanglesIntersectsRect, (
    TX_IN_PARAM(TX_RECT) pRect1,
    TX_IN_PARAM(TX_RECT) pRect2,
    TX_OUT_PARAM(TX_BOOL) pIntersects
    ));

/*********************************************************************************************************************/

#endif /* !defined(__TOBII_TX_BOUNDS_API__H__) */

/*********************************************************************************************************************/
