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

#include "platform-esp.h"
#include "tinyplatform/logging.h"

static const char *TAG = "tinyplatform";

/* Convert OT log level to zephyr log level. */
static inline int log_translate(tbLogLevel aLogLevel)
{
    switch (aLogLevel)
    {
    case TB_LOG_LEVEL_NONE:
    case TB_LOG_LEVEL_ERROR:
        return ESP_LOG_ERROR;
    case TB_LOG_LEVEL_WARN:
        return ESP_LOG_WARN;
    case TB_LOG_LEVEL_INFO:
        return ESP_LOG_INFO;
    case TB_LOG_LEVEL_DEBG:
        return ESP_LOG_DEBUG;
    default:
        break;
    }

    return -1;
}

void tbPlatLog(tbLogLevel aLogLevel, const char *aFormat, ...)
{
#if defined(CONFIG_TINYPLATFORM_LOG)
    int     level = log_translate(aLogLevel);
    va_list param_list;
    if (level < 0)
    {
        return;
    }

    va_start(param_list, aFormat);
    esp_log_writev(level, TAG, aFormat, param_list);
    va_end(param_list);

#else
    ARG_UNUSED(aLogLevel);
    ARG_UNUSED(aFormat);
#endif
}
