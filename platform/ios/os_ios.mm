/**************************************************************************/
/*  os_ios.mm                                                             */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#import "os_ios.h"

#import "display_server_ios.h"

#include <iostream>

#ifdef IOS_ENABLED

OS_IOS *OS_IOS::get_singleton() {
	return (OS_IOS *)OS_AppleEmbedded::get_singleton();
}

OS_IOS::OS_IOS() :
		OS_AppleEmbedded() {
	DisplayServerIOS::register_ios_driver();
}

OS_IOS::~OS_IOS() {}

String OS_IOS::get_name() const {
	return "iOS";
}

void OS_IOS::start() {
	OS_AppleEmbedded::start();

	if (virtual_controller) {
		virtual_controller->update_state();
		std::cout << "SHOW VIRTUAL CONTROLLER\n";
	}
}

void OS_IOS::deinitialize_modules() {
	if (virtual_controller) {
		memdelete(virtual_controller);
	}
	OS_AppleEmbedded::deinitialize_modules();
}

void OS_IOS::initialize_joypads() {
	OS_AppleEmbedded::initialize_joypads();

	std::cout << "CREATE VIRTUAL CONTROLLER\n";

	virtual_controller = memnew(IOSVirtualController);
}

VirtualController *OS_IOS::get_virtual_controller() const {
	return virtual_controller;
}

void OS_IOS::controller_connected() const {
	if (virtual_controller) {
		virtual_controller->controller_connected();
	}
}

void OS_IOS::controller_disconnected() const {
	if (virtual_controller) {
		virtual_controller->controller_disconnected();
	}
}

#endif // IOS_ENABLED
