/**
 * Copyright (C) by chevp
 */

#pragma comment(lib, "Ws2_32.lib")

#include <iostream>
#include <ipcde3.pb.h>
#include <ipcde3.grpc.pb.h>
#include <contextEngine.grpc.pb.h>
#include <contextEngine.pb.h>
#include <pbr.hpp>
#include <desert.pbr.api.hpp>
#include <grpcpp/support/channel_arguments.h>
#include <rsc.hpp>

using namespace desertpbrapp;
using namespace desertpbrapi;

DesertPbrApp *_scene;

/**
 * Window Callback Function
 */
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (_scene != NULL)
	{
		_scene->handleMessages(hWnd, uMsg, wParam, lParam);
	}

	return (DefWindowProc(hWnd, uMsg, wParam, lParam));
}

/**
 * Main-Window for Windows.
 */
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
	desert::info("Starting DESERT_PBR_APP...");

	// DesertPbrApp is the main pbr-app
	_scene = new DesertPbrApp(__argc, __argv);

	// DesertPbrApiModel uses a pbr-scene for api inteactions
	auto _core = new DesertPbrApiModel(_scene);

	auto settings = DesertPbrApp::buildDefaultSettings();

	// initialize vulkan scene rendering
	_scene->init(&settings);

	// initialize the window
	_scene->setupWindow(hInstance, WndProc);

	// prepare vulkan environment
	_scene->prepare();

	auto defaultScene = _core->buildDefaultDesert();

	// insert scene entities to the core-model via pbr-api
	_core->insertDesert(&defaultScene);

	// start game loop
	_core->run();

	delete (_core);
	
	delete (_scene);

	return 0;
}
