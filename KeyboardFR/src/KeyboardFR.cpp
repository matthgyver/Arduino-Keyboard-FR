/*
  Keyboard.cpp

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

#include "KeyboardFR.h"

#if defined(_USING_HID)

//================================================================================
//================================================================================
//	Keyboard

static const uint8_t _hidReportDescriptor[] PROGMEM = {

  //  Keyboard
    0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)  // 47
    0x09, 0x06,                    // USAGE (Keyboard)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x85, 0x02,                    //   REPORT_ID (2)
    0x05, 0x07,                    //   USAGE_PAGE (Keyboard)
   
  	0x19, 0xe0,                    //   USAGE_MINIMUM (Keyboard LeftControl)
    0x29, 0xe7,                    //   USAGE_MAXIMUM (Keyboard Right GUI)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0x01,                    //   LOGICAL_MAXIMUM (1)
    0x75, 0x01,                    //   REPORT_SIZE (1)
    
  	0x95, 0x08,                    //   REPORT_COUNT (8)
    0x81, 0x02,                    //   INPUT (Data,Var,Abs)
    0x95, 0x01,                    //   REPORT_COUNT (1)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x81, 0x03,                    //   INPUT (Cnst,Var,Abs)
    
  	0x95, 0x06,                    //   REPORT_COUNT (6)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0x73,                    //   LOGICAL_MAXIMUM (115)
    0x05, 0x07,                    //   USAGE_PAGE (Keyboard)
    
  	0x19, 0x00,                    //   USAGE_MINIMUM (Reserved (no event indicated))
    0x29, 0x73,                    //   USAGE_MAXIMUM (Keyboard Application)
    0x81, 0x00,                    //   INPUT (Data,Ary,Abs)
    0xc0,                          // END_COLLECTION
};

Keyboard_::Keyboard_(void) 
{
	static HIDSubDescriptor node(_hidReportDescriptor, sizeof(_hidReportDescriptor));
	HID().AppendDescriptor(&node);
}

void Keyboard_::begin(void)
{
}

void Keyboard_::end(void)
{
}

void Keyboard_::sendReport(KeyReport* keys)
{
	HID().SendReport(2,keys,sizeof(KeyReport));
}

extern
const uint8_t _asciimap[256] PROGMEM;

// Build help :
//	- https://raw.githubusercontent.com/qlyoung/armory-keyboard/master/layouts/keyboard-layout.png
//	- https://www.ascii-code.com/

#define SHIFT 0x80
#define ALTGR 0x40
const uint8_t _asciimap[256] =
{
  0x00,             // NUL
  0x00,             // SOH
  0x00,             // STX
  0x00,             // ETX
  0x00,             // EOT
  0x00,             // ENQ
  0x00,             // ACK  
  0x00,             // BEL
  0x2a,							// BS	Backspace
  0x2b,							// TAB	Tab
  0x28,							// LF	Enter
  0x00,             // VT 
  0x00,             // FF 
  0x00,             // CR 
  0x00,             // SO 
  0x00,             // SI 
  0x00,             // DEL
  0x00,             // DC1
  0x00,             // DC2
  0x00,             // DC3
  0x00,             // DC4
  0x00,             // NAK
  0x00,             // SYN
  0x00,             // ETB
  0x00,             // CAN
  0x00,             // EM 
  0x00,             // SUB
  0x00,             // ESC
  0x00,             // FS 
  0x00,             // GS 
  0x00,             // RS 
  0x00,             // US 
  0x2c,		   				// ' '
  0x38,	   					// ! 
  0x20,    					// "
  0x20|ALTGR,    	    	// #
  0x30,    					// $
  0x34|SHIFT,    		// %
  0x1E,    					// & 
  0x21,          		// '
  0x22,    					// (
  0x2d,    					// )
  0x32,    					// *
  0x2e|SHIFT,       // +
  0x10,             // , 
  0x23,             // -
  0x36|SHIFT,       // .
  0x37|SHIFT,       // /
  0x27|SHIFT,       // 0
  0x1e|SHIFT,       // 1
  0x1f|SHIFT,       // 2
  0x20|SHIFT,       // 3
  0x21|SHIFT,       // 4
  0x22|SHIFT,       // 5
  0x23|SHIFT,       // 6
  0x24|SHIFT,       // 7
  0x25|SHIFT,       // 8
  0x26|SHIFT,       // 9
  0x37,             // :
  0x36,             // ;
  0x03,      				// < Done
  0x2e,          		// =
  0x03|SHIFT,       // > Done
  0x10|SHIFT,       // ? 0x38 -> 0x10 OK
  0x27|ALTGR,       // @
  0x14|SHIFT,       // A
  0x05|SHIFT,       // B
  0x06|SHIFT,       // C
  0x07|SHIFT,       // D
  0x08|SHIFT,       // E
  0x09|SHIFT,       // F
  0x0a|SHIFT,       // G
  0x0b|SHIFT,       // H
  0x0c|SHIFT,       // I
  0x0d|SHIFT,       // J
  0x0e|SHIFT,       // K
  0x0f|SHIFT,       // L
  0x33|SHIFT,       // M
  0x11|SHIFT,       // N
  0x12|SHIFT,       // O
  0x13|SHIFT,       // P
  0x04|SHIFT,       // Q
  0x15|SHIFT,       // R
  0x16|SHIFT,       // S
  0x17|SHIFT,       // T
  0x18|SHIFT,       // U
  0x19|SHIFT,       // V
  0x1d|SHIFT,       // W
  0x1b|SHIFT,       // X
  0x1c|SHIFT,       // Y
  0x1a|SHIFT,       // Z
  0x22|ALTGR,  		// [
  0x25|ALTGR,          		// backslash
  0x2d|ALTGR,          		// ]
  0x26|ALTGR,    		// ^
  0x25,    					// _
  0x24|ALTGR,       // `
  0x14,          		// a
  0x05,          		// b
  0x06,          		// c
  0x07,          		// d
  0x08,          		// e
  0x09,          		// f
  0x0a,          		// g
  0x0b,          		// h
  0x0c,          		// i
  0x0d,          		// j
  0x0e,          		// k
  0x0f,          		// l
  0x33,          		// m
  0x11,          		// n
  0x12,          		// o
  0x13,          		// p
  0x04,          		// q
  0x15,          		// r
  0x16,          		// s
  0x17,          		// t
  0x18,          		// u
  0x19,          		// v
  0x1d,          		// w
  0x1b,          		// x
  0x1c,          		// y
  0x1a,          		// z
  0x21|ALTGR,    			 		// {
  0x23|ALTGR,    			 		// |
  0x2e|ALTGR,    			 		// }
  0x1f|ALTGR,    			 		// ~
  0,						  	// DEL
  0x08|ALTGR,      	// €
  0x00,             // NUL
  0x00,             // SOH
  0x00,             // STX
  0x00,             // ETX
  0x00,             // EOT
  0x00,             // ENQ
  0x00,             // ACK  
  0x00,             // BEL
  0x2a,							// BS	Backspace
  0x2b,							// TAB	Tab
  0x28,							// LF	Enter
  0x00,             // VT 
  0x00,             // FF 
  0x00,             // CR 
  0x00,             // SO 
  0x00,             // SI 
  0x00,             // DEL
  0x00,             // DC1
  0x00,             // DC2
  0x00,             // DC3
  0x00,             // DC4
  0x00,             // NAK
  0x00,             // SYN
  0x00,             // ETB
  0x00,             // CAN
  0x00,             // EM 
  0x00,             // SUB
  0x00,             // ESC
  0x00,             // FS 
  0x00,             // GS 
  0x00,             // RS 
  0x00,             // US 
  0,                // nobr
  0,                //
  0x30|SHIFT,       // £
  0x30|ALTGR,				// ø
  0,
  0,   
  0x38|SHIFT,       // §
  0x20,             // "
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0x2d|SHIFT,       // °
  0,
  0x35,             // ²
  0x35|SHIFT,       // ³
  0,
  0x31|SHIFT,       // µ
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0x27,             // à
  0,
  0,                // â
  0,
  0,                // ä
  0,
  0,                // æ
  0x26,             // ç
  0x24,             // è
  0x1f,             // é
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0x34,             // ù
  0,
  0,
  0,
  0,
  0,
  0
};


uint8_t USBPutChar(uint8_t c);

// press() adds the specified key (iso-8859-1 encoded)
// to the persistent key report and sends the report.  Because of the way 
// USB HID works, the host acts like the key remains pressed until we 
// call release(), releaseAll(), or otherwise clear the report and resend.
size_t Keyboard_::press(uint8_t k) 
{
	uint8_t i;
	if (k == 131) {	// if key is windows key
		_keyReport.modifiers |= (1<<(k-128));
		k = 0;
	} else {	
		k = pgm_read_byte(_asciimap + k);
		if (!k) {
			setWriteError();
			return 0;
		}
		
		if (k & 0x80) {						// it's a capital letter or other character reached with shift
			_keyReport.modifiers |= 0x02;	// the left shift modifier
			k &= 0x7F;
		}
		if (k & 0x40) {
			_keyReport.modifiers |= 0x40;
			k &= 0x3F;
		}
		if (k == 0x03) { // special case 0x64
			k = 0x64;
		}
	}
	// Add k to the key report only if it's not already present
	// and if there is an empty slot.
	if (_keyReport.keys[0] != k && _keyReport.keys[1] != k && 
		_keyReport.keys[2] != k && _keyReport.keys[3] != k &&
		_keyReport.keys[4] != k && _keyReport.keys[5] != k) {
		
		for (i=0; i<6; i++) {
			if (_keyReport.keys[i] == 0x00) {
				_keyReport.keys[i] = k;
				break;
			}
		}
		if (i == 6) {
			setWriteError();
			return 0;
		}	
	}
	sendReport(&_keyReport);
	return 1;
}

// release() takes the specified key out of the persistent key report and
// sends the report.  This tells the OS the key is no longer pressed and that
// it shouldn't be repeated any more.
size_t Keyboard_::release(uint8_t k) 
{
	uint8_t i;
	k = pgm_read_byte(_asciimap + k);
	if (!k) {
		return 0;
	}
	if (k & 0x80) {							// it's a capital letter or other character reached with shift
		_keyReport.modifiers &= ~(0x02);	// the left shift modifier
		k &= 0x7F;
	}
	if (k & 0x40) {
		_keyReport.modifiers &= ~(0x40);
		k &= 0x3F;
	}
	if (k == 0x03) { // special case 0x64
		k = 0x64;
	}
	
	// Test the key report to see if k is present.  Clear it if it exists.
	// Check all positions in case the key is present more than once (which it shouldn't be)
	for (i=0; i<6; i++) {
		if (0 != k && _keyReport.keys[i] == k) {
			_keyReport.keys[i] = 0x00;
		}
	}

	sendReport(&_keyReport);
	return 1;
}


void Keyboard_::releaseAll(void)
{
	_keyReport.keys[0] = 0;
	_keyReport.keys[1] = 0;	
	_keyReport.keys[2] = 0;
	_keyReport.keys[3] = 0;	
	_keyReport.keys[4] = 0;
	_keyReport.keys[5] = 0;	
	_keyReport.modifiers = 0;
	sendReport(&_keyReport);
}

size_t Keyboard_::write(uint8_t c)
{
	uint8_t p = press(c);  // Keydown
	release(c);            // Keyup
	return p;              // just return the result of press() since release() almost always returns 1
}

size_t Keyboard_::write(const uint8_t *buffer, size_t size) {
	size_t n = 0;
	while (size--) {
		if (*buffer != '\r') {
			if (write(*buffer)) {
			  n++;
			} else {
			  break;
			}
		}
		buffer++;
	}
	return n;
}

Keyboard_ Keyboard;

#endif

