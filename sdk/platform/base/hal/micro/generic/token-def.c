/***************************************************************************//**
 * @file
 * @brief This file is for the code definitions (arrays) needed for the tokens.
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/
#include PLATFORM_HEADER
#include "stack/include/ember.h"

#ifdef EFR32MG21
#define CONST_CONTROL const
#else
#define CONST_CONTROL
#endif


//-- Build structure defines (these define all the data types of the tokens).
#define DEFINETYPES
// Multiple inclusion of unguarded token-related header files is by design; suppress violation.
//cstat !MISRAC2012-Dir-4.10
  #include "stack/config/token-stack.h"
#undef DEFINETYPES

//-- Build parameter links
#define DEFINETOKENS
#define TOKEN_MFG(name, creator, iscnt, isidx, type, arraysize, ...)

#define TOKEN_DEF(name, creator, iscnt, isidx, type, arraysize, ...) \
  NVM3KEY_##name,
CONST_CONTROL uint32_t tokenNvm3Keys[] = {
#if defined (USE_NVM3)
  // Multiple inclusion of unguarded token-related header files is by design; suppress violation.
  //cstat !MISRAC2012-Dir-4.10
  #include "stack/config/token-stack.h"
#else
  0xFFFFFFFFUL // Dummy
#endif
};

#undef TOKEN_DEF

#define TOKEN_DEF(name, creator, iscnt, isidx, type, arraysize, ...) \
  creator,
CONST_CONTROL uint16_t tokenCreators[] = {
#if !defined (USE_NVM3) || defined (SIMEE2_TO_NVM3_UPGRADE)
  // Multiple inclusion of unguarded token-related header files is by design; suppress violation.
  //cstat !MISRAC2012-Dir-4.10
  #include "stack/config/token-stack.h"
#else
  0xFFFFUL   // Dummy
#endif
};
#undef TOKEN_DEF

#define TOKEN_DEF(name, creator, iscnt, isidx, type, arraysize, ...) \
  iscnt,
CONST_CONTROL bool tokenIsCnt[] = {
  // Multiple inclusion of unguarded token-related header files is by design; suppress violation.
  //cstat !MISRAC2012-Dir-4.10
    #include "stack/config/token-stack.h"
};
#undef TOKEN_DEF

#define TOKEN_DEF(name, creator, iscnt, isidx, type, arraysize, ...) \
  isidx,
CONST_CONTROL bool tokenIsIdx[] = {
#if defined (USE_NVM3)
  // Multiple inclusion of unguarded token-related header files is by design; suppress violation.
  //cstat !MISRAC2012-Dir-4.10
    #include "stack/config/token-stack.h"
#else
  false // Dummy
#endif
};
#undef TOKEN_DEF

#define TOKEN_DEF(name, creator, iscnt, isidx, type, arraysize, ...) \
  sizeof(type),
CONST_CONTROL uint8_t tokenSize[] = {
  // Multiple inclusion of unguarded token-related header files is by design; suppress violation.
  //cstat !MISRAC2012-Dir-4.10
    #include "stack/config/token-stack.h"
};
#undef TOKEN_DEF

#define TOKEN_DEF(name, creator, iscnt, isidx, type, arraysize, ...) \
  arraysize,
CONST_CONTROL uint8_t tokenArraySize[] = {
  // Multiple inclusion of unguarded token-related header files is by design; suppress violation.
  //cstat !MISRAC2012-Dir-4.10
    #include "stack/config/token-stack.h"
};
#undef TOKEN_DEF

//These set of DEFAULT token values are only used in the tokenDefaults array
//below.

// -------------------------------------------------------------------------
// MISRAC2012-Rule-20.7 doesn't allow for this use of concatenation within
// a macro expansion. Moreover, since TOKEN_DEF is only being used here as a
// static declaration of token default values, there's no risk that it will
// interfere with any other logic.
// -------------------------------------------------------------------------
#define TOKEN_DEF(name, creator, iscnt, isidx, type, arraysize, ...) \
  CONST_CONTROL type TOKEN_##name##_DEFAULTS = __VA_ARGS__;
// Multiple inclusion of unguarded token-related header files is by design; suppress violation.
//cstat !MISRAC2012-Dir-4.10
  #include "stack/config/token-stack.h"
#undef TOKEN_DEF
// -------------------------------------------------------------------------
// -------------------------------------------------------------------------

#define TOKEN_DEF(name, creator, iscnt, isidx, type, arraysize, ...) \
  ((void *)&TOKEN_##name##_DEFAULTS),
CONST_CONTROL void * const tokenDefaults[] = {
  // Multiple inclusion of unguarded token-related header files is by design; suppress violation.
  //cstat !MISRAC2012-Dir-4.10
    #include "stack/config/token-stack.h"
};
#undef TOKEN_DEF

#undef DEFINETOKENS

#undef TOKEN_MFG
