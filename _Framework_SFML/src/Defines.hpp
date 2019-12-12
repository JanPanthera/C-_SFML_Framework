#pragma once

#define _SUCCESS true
#define _FAILED false

#define _IS_NULLPTR(_VAL) if (_VAL == nullptr) { \
                             return _FAILED; \
                          } \

#define DEFAULT_FONT "src/fonts/default.otf"

#define LOG_INFO LogToFile::LogAttention::INFO
#define LOG_ERROR LogToFile::LogAttention::ERROR
#define LOG_DEBUG LogToFile::LogAttention::DEBUG
#define LOG_WARNING LogToFile::LogAttention::WARNING
#define LOG_CRITICAL LogToFile::LogAttention::CRITICAL

// Keyboard
#define KEY_ESCAPE 27

// Mouse
#define KEY_LEFT_MOUSE_BTN 0x01
#define KEY_RIGHT_MOUSE_BTN 0x02
#define KEY_CANCEL_MOUSE_BTN 0x03
#define KEY_MIDDLE_MOUSE_BTN 0x04