/*********************************************************************************************************************
 * Copyright 2013-2014 Tobii Technology AB. All rights reserved.
 * EyeXInternalTypes.h
 *********************************************************************************************************************/

#if !defined(__TOBII_TX_INTERNAL_TYPES__H__)
#define __TOBII_TX_INTERNAL_TYPES__H__

/*********************************************************************************************************************/

/**
  Callback for an Invalid argument.
 
  @param functionName [in]: 
    A TX_CONSTSTRING
 
  @param parameterName [in]: 
    A TX_CONSTSTRING 
 
  @param userParam [in]: 
    Supplied when registering the callback, normally used to respond to the event outside of the callback.
  
  @return 
    void
 */
TX_DEFINE_CALLABLE(TX_INVALIDARGUMENTCALLBACK, InvalidArgumentCallback, void, (
    TX_CONSTSTRING functionName,
    TX_CONSTSTRING parameterName,
    TX_USERPARAM userParam
    ));

/*********************************************************************************************************************/

TX_BEGIN_FLAGS(PropertyFlags)
    TX_ENUM_VALUE(TX_PROPERTYFLAG_NONE,           None) = TX_FLAGS_NONE_VALUE,
    TX_ENUM_VALUE(TX_PROPERTYFLAG_NONREMOVABLE,   NonRemoveable) = 1 << 0,
    TX_ENUM_VALUE(TX_PROPERTYFLAG_MANUALCLONING,  ManualCloning) = 1 << 1
TX_END_FLAGS(TX_PROPERTYFLAGS, PropertyFlags)

/*********************************************************************************************************************/

#endif /* !defined(__TOBII_TX_INTERNAL_TYPES__H__) */

/*********************************************************************************************************************/
