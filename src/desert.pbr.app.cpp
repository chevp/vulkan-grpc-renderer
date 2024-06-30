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

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (_scene != NULL)
	{
		_scene->handleMessages(hWnd, uMsg, wParam, lParam);
	}

	return (DefWindowProc(hWnd, uMsg, wParam, lParam));
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
	desert::info("Starting DESERT_PBR_APP...");

	_scene = new DesertPbrApp(__argc, __argv);

	grpc::ChannelArguments args;

	args.SetCompressionAlgorithm(GRPC_COMPRESS_GZIP);

	auto _core = new DesertPbrApiModel(_scene);

	auto settings = DesertPbrApp::buildDefaultSettings();

	_scene->init(&settings);

	_scene->setupWindow(hInstance, WndProc);

	_scene->prepare();

	auto defaultScene = _core->buildDefaultDesert();
	
	_core->insertDesert(&defaultScene);

	_core->run();

	delete (_core);
	
	delete (_scene);

	return 0;
}