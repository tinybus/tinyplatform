// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 * @brief
 *  This file defines the errors
 */

#ifndef TINYPLATFORM_ERROR_H_
#define TINYPLATFORM_ERROR_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Represents error codes
 */
typedef enum tinyError
{
    /**
     * No error.
     */
    TINY_ERROR_NONE = 0,

    /**
     * Operational failed.
     */
    TINY_ERROR_SUBSCRIBER_COUNT_EXCEEDED = 1,

    /**
     * Not found.
     */
    TINY_ERROR_NOT_FOUND = 2,

    /**
     * No Buffers.
     */
    TINY_ERROR_NO_BUFS = 3,

    /**
     * The number of defined errors.
     */
    TINY_NUM_ERRORS,

    /**
     * Generic error (should not use).
     */
    TINY_ERROR_GENERIC = 255,
} tinyError;

#ifdef __cplusplus
} // extern "C"
#endif

#endif // TINYPLATFORM_ERROR_H_
