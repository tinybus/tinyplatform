// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0
/**
 * @file
 * @brief
 *   This file defines the platform-specific functions needed by TinyPlatform's example applications.
 */

#ifndef TINYPLATFORM_PLATFORM_H_
#define TINYPLATFORM_PLATFORM_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Performs all platform-specific initialization of TinyPlatform's drivers.
 *
 * @note This function is not called by the TinyPlatform library. Instead, the system/RTOS should call this function
 *       when initialization of TinyPlatform's drivers is most appropriate.
 *
 */
void tbPlatformInit(void);

/**
 * Performs all platform-specific deinitialization for TinyPlatform's drivers.
 *
 * @note This function is not called by the TinyPlatform library. Instead, the system/RTOS should call this function
 *       when deinitialization of TinyPlatform's drivers is most appropriate.
 */
void tbPlatformDeinit(void);

#ifdef __cplusplus
} // end of extern "C"
#endif

#endif // TINYPLATFORM_PLATFORM_H_
