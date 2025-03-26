// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
// SPDX-License-Identifier: Apache-2.0

/**
 * @file
 * @brief
 *   This file includes the platform abstraction for the debug log service.
 */
#include <esp_log.h>
#include <stdarg.h>
#include <stdio.h>
#include "tiny/toolchain.h"

#include "platform-esp.h"
#include "tiny/logging.h"

/* Convert OT log level to zephyr log level. */
static inline int log_translate(tinyLogLevel aLogLevel)
{
    switch (aLogLevel)
    {
    case TINY_LOG_LEVEL_NONE:
    case TINY_LOG_LEVEL_ERROR:
        return ESP_LOG_ERROR;
    case TINY_LOG_LEVEL_WARN:
        return ESP_LOG_WARN;
    case TINY_LOG_LEVEL_INFO:
        return ESP_LOG_INFO;
    case TINY_LOG_LEVEL_DEBG:
        return ESP_LOG_DEBUG;
    default:
        break;
    }

    return -1;
}

void tinyPlatLog(tinyLogLevel aLogLevel, const char *aTag, const char *aFormat, ...)
{
#if defined(CONFIG_TINYPLATFORM_LOG)
    int     level = log_translate(aLogLevel);
    va_list param_list;
    if (level < 0)
    {
        return;
    }

    if (level == ESP_LOG_ERROR)
    {
        esp_log_write(level, aTag,
                      LOG_COLOR_E "E"
                                  "(%s) %s: ",
                      esp_log_system_timestamp(), aTag);
    }
    else if (level == ESP_LOG_WARN)
    {
        esp_log_write(level, aTag,
                      LOG_COLOR_W "W"
                                  "(%s) %s: ",
                      esp_log_system_timestamp(), aTag);
    }
    else if (level == ESP_LOG_DEBUG)
    {
        esp_log_write(level, aTag,
                      LOG_COLOR_D "D"
                                  "(%s) %s: ",
                      esp_log_system_timestamp(), aTag);
    }
    else if (level == ESP_LOG_VERBOSE)
    {
        esp_log_write(level, aTag,
                      LOG_COLOR_V "V"
                                  "(%s) %s: ",
                      esp_log_system_timestamp(), aTag);
    }
    else
    {
        esp_log_write(level, aTag,
                      LOG_COLOR_I "I"
                                  "(%s) %s: ",
                      esp_log_system_timestamp(), aTag);
    }
    va_start(param_list, aFormat);
    esp_log_writev(level, aTag, aFormat, param_list);
    va_end(param_list);
    esp_log_write(level, aTag, LOG_RESET_COLOR "\n");

#else
    TINY_UNUSED_VARIABLE(aLogLevel);
    TINY_UNUSED_VARIABLE(aTag);
    TINY_UNUSED_VARIABLE(aFormat);
#endif
}
