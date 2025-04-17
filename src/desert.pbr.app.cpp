/**
 * Copyright (C) by chevp
 */

#pragma comment(lib, "Ws2_32.lib")

#include <iostream>

// Protobuf and gRPC includes
#include <ipcde3.pb.h>
#include <ipcde3.grpc.pb.h>
#include <contextEngine.pb.h>
#include <contextEngine.grpc.pb.h>

// Desert PBR and Vulkan includes
#include <pbr.hpp>
#include <desert.pbr.api.hpp>
#include <rsc.hpp>
#include <grpcpp/support/channel_arguments.h>

using namespace desertpbrapp;
using namespace desertpbrapi;

std::unique_ptr<DesertPbrApp> g_scene;

/**
 * Window Callback Function
 */
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (g_scene)
	{
		g_scene->handleMessages(hWnd, uMsg, wParam, lParam);
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

/**
 * Entry point for the Windows application.
 */
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
	desert::info("Starting DESERT_PBR_APP...");

	// Initialize the DesertPbrApp
	g_scene = std::make_unique<DesertPbrApp>(__argc, __argv);

	// Create the core API model with the scene
	std::unique_ptr<DesertPbrApiModel> core = std::make_unique<DesertPbrApiModel>(g_scene.get());

	// Build and apply default settings
	auto settings = DesertPbrApp::buildDefaultSettings();
	g_scene->init(&settings);
	g_scene->setupWindow(hInstance, WndProc);
	g_scene->prepare();

	// Build default desert scene and insert it into the core
	auto defaultScene = core->buildDefaultDesert();
	core->insertDesert(&defaultScene);

	// Start the main loop
	core->run();

	// Resources are automatically cleaned up with smart pointers
	return 0;
}
