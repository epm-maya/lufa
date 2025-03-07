/*
             LUFA Library
     Copyright (C) Dean Camera, 2021.

  dean [at] fourwalledcubicle [dot] com
           www.lufa-lib.org
*/

/*
  Copyright 2021  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaims all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

/** \file
 *  \brief Application Configuration Header File
 *
 *  This is a header file which is be used to configure some of
 *  the application's compile time options, as an alternative to
 *  specifying the compile time constants supplied through a
 *  makefile or build system.
 *
 *  For information on what each token does, refer to the
 *  \ref Sec_Options section of the application documentation.
 */

#ifndef _APP_CONFIG_H_
#define _APP_CONFIG_H_

	#define AUX_LINE_PORT              PORTB
	#define AUX_LINE_PIN               PINB
	#define AUX_LINE_DDR               DDRB
	#if (BOARD == BOARD_U2S)
		#define AUX_LINE_MASK          (1 << 0)
	#else
		#define AUX_LINE_MASK          (1 << 4)
	#endif

	#define ENABLE_ISP_PROTOCOL
	#define ENABLE_XPROG_PROTOCOL

	#define VTARGET_ADC_CHANNEL        2
	#define VTARGET_REF_VOLTS          5
	#define VTARGET_SCALE_FACTOR       1
//	#define VTARGET_USE_INTERNAL_REF
	#define NO_VTARGET_DETECT
//	#define XCK_RESCUE_CLOCK_ENABLE
//	#define INVERTED_ISP_MISO

//	#define FIRMWARE_VERSION_MINOR     0x11

#include "HostTypes.h"

#ifdef HOST_TYPE

#if HOST_TYPE == ITSY32U4
		#undef  AUX_LINE_PORT
		#undef  AUX_LINE_PIN
		#undef  AUX_LINE_DDR
		#undef  AUX_LINE_MASK
		// A5 : PF0
		#define AUX_LINE_PORT          PORTF
		#define AUX_LINE_PIN           PINF
		#define AUX_LINE_DDR           DDRF
		#define AUX_LINE_MASK          (1 << 0)
#endif

#if HOST_TYPE == PROMICRO
		#undef  AUX_LINE_MASK
		// D10 : PB6
		#define AUX_LINE_MASK          (1 << 6)
#endif

#endif

#endif
