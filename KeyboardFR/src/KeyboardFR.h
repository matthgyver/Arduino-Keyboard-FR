/*
  Keyboard.h

  Copyright (c) 2015, Arduino LLC
  Original code (pre-library): Copyright (c) 2011, Peter Barrett

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef KEYBOARD_h
#define KEYBOARD_h

#include "HID.h"

#if !defined(_USING_HID)

#warning "Using legacy HID core (non pluggable)"

#else

//================================================================================
//================================================================================
//  Keyboard

#define KEY_LEFT_CTRL		0x01
#define KEY_LEFT_SHIFT		0x02
#define KEY_LEFT_ALT		0x04
//#define KEY_LEFT_GUI		0x83
#define KEY_LEFT_GUI		0x08
#define KEY_RIGHT_CTRL		0x10
#define KEY_RIGHT_SHIFT		0x20
#define KEY_RIGHT_ALT		0x40
#define KEY_RIGHT_GUI		0x80

#define KEY_UP_ARROW		0x52
#define KEY_DOWN_ARROW		0x51
#define KEY_LEFT_ARROW		0x50
#define KEY_RIGHT_ARROW		0x49
#define KEY_BACKSPACE		0x2A
#define KEY_TAB				0x2B
#define KEY_RETURN			0x28
#define KEY_ESC				0x29
#define KEY_INSERT			0x49
#define KEY_DELETE			0x4C
#define KEY_PAGE_UP			0x4B
#define KEY_PAGE_DOWN		0x4E
#define KEY_HOME			0x4A
#define KEY_END				0x4D
#define KEY_CAPS_LOCK		0x39
#define KEY_F1				0x3A
#define KEY_F2				0x3B
#define KEY_F3				0x3C
#define KEY_F4				0x3D
#define KEY_F5				0x3E
#define KEY_F6				0x3F
#define KEY_F7				0x40
#define KEY_F8				0x41
#define KEY_F9				0x42
#define KEY_F10				0x43
#define KEY_F11				0x44
#define KEY_F12				0x45


//  Low level key report: up to 6 keys and shift, ctrl etc at once
typedef struct
{
  uint8_t modifiers;
  uint8_t reserved;
  uint8_t keys[6];
} KeyReport;

class Keyboard_ : public Print
{
private:
  KeyReport _keyReport;
  void sendReport(KeyReport* keys);
public:
  Keyboard_(void);
  void begin(void);
  void end(void);
  size_t write(uint8_t k);
  size_t write(const uint8_t *buffer, size_t size);
  size_t press(uint8_t k);
  size_t release(uint8_t k);
  void releaseAll(void);
};
extern Keyboard_ Keyboard;

#endif
#endif

