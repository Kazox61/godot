/**************************************************************************/
/*  default_virtual_controller.cpp                                        */
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

#include "default_virtual_controller.h"

#include "scene/gui/virtual_controller_overlay.h"
#include "scene/main/canvas_layer.h"
#include "scene/main/scene_tree.h"
#include "scene/main/window.h"

void DefaultVirtualController::enable() {
	if (canvas_layer) {
		canvas_layer->show();
	}
}

void DefaultVirtualController::disable() {
	if (canvas_layer) {
		canvas_layer->hide();
	}
}

bool DefaultVirtualController::is_enabled() {
	return canvas_layer != nullptr && canvas_layer->is_visible();
}

DefaultVirtualController::DefaultVirtualController() {
	if (canvas_layer == nullptr) {
		canvas_layer = memnew(CanvasLayer);
		SceneTree::get_singleton()->get_root()->add_child(canvas_layer);
	}

	if (overlay == nullptr) {
		overlay = memnew(VirtualControllerOverlay);
		canvas_layer->add_child(overlay);
	}
}

DefaultVirtualController::~DefaultVirtualController() {
}

void DefaultVirtualController::set_enabled_left_thumbstick(bool p_enabled) {
	enabled_left_thumbstick = p_enabled;
}

bool DefaultVirtualController::is_enabled_left_thumbstick() {
	return enabled_left_thumbstick;
}

void DefaultVirtualController::set_enabled_right_thumbstick(bool p_enabled) {
	enabled_right_thumbstick = p_enabled;
}

bool DefaultVirtualController::is_enabled_right_thumbstick() {
	return enabled_right_thumbstick;
}

void DefaultVirtualController::set_enabled_button_a(bool p_enabled) {
	enabled_button_a = p_enabled;
}

bool DefaultVirtualController::is_enabled_button_a() {
	return enabled_button_a;
}

void DefaultVirtualController::set_enabled_button_b(bool p_enabled) {
	enabled_button_b = p_enabled;
}

bool DefaultVirtualController::is_enabled_button_b() {
	return enabled_button_b;
}

void DefaultVirtualController::set_enabled_button_x(bool p_enabled) {
	enabled_button_x = p_enabled;
}

bool DefaultVirtualController::is_enabled_button_x() {
	return enabled_button_x;
}

void DefaultVirtualController::set_enabled_button_y(bool p_enabled) {
	enabled_button_y = p_enabled;
}

bool DefaultVirtualController::is_enabled_button_y() {
	return enabled_button_y;
}
