#include "pch.h"
#include "IniFile.hpp"
#define ReplacePak(a, b) helperFunctions.ReplaceFile("gd_PC\\" a ".PAK", "gd_PC\\" b ".PAK");
// or #include "stdafx.h" for previous Visual Studio versions

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		// Executed at startup, contains helperFunctions and the path to your mod (useful for getting the config file.)
		// This is where we override functions, replace static data, etc.

		// Read config.ini
		const IniFile* config = new IniFile(std::string(path) + "\\config.ini");

		std::string controller = config->getString("", "Controller", "Vanilla/Custom");
		std::string button = config->getString("", "ButtonIconPrompt", "B/Circle");
		std::string color = config->getString("", "Color", "Black");
		delete config;

		//replace textures
		if (controller == "Xbox (one, series x/s) controllers") {
			if (color == "Black") {
				if (button == "B/Circle") {
					ReplacePak("console", "console_xbox-one-xs_B_Black");
				}
				else if (button == "A/Cross") {
					ReplacePak("console", "console_xbox-one-xs_A_Black");
				}
				else if (button == "X/Square") {
					ReplacePak("console", "console_xbox-one-xs_X_Black");
				}
				else if (button == "Y/Triangle") {
					ReplacePak("console", "console_xbox-one-xs_Y_Black");
				}
			}
		}
		else if (controller == "Nintendo Controllers") {
			if (color == "Black") {
				if (button == "B/Circle") {
					ReplacePak("console", "console_nintendo_B_Black");
				}
				else if (button == "A/Cross") {
					ReplacePak("console", "console_nintendo_A_Black");
				}
				else if (button == "X/Square") {
					ReplacePak("console", "console_nintendo_X_Black");
				}
				else if (button == "Y/Triangle") {
					ReplacePak("console", "console_nintendo_Y_Black");
				}
			}
		}
		else if (controller == "DualShock (Playstation contollers)") {
			if (color == "Black") {
				if (button == "B/Circle") {
					ReplacePak("console", "console_DualShock_Circle_Black");
				}
				else if (button == "A/Cross") {
					ReplacePak("console", "console_DualShock_Cross_Black");
				}
				else if (button == "X/Square") {
					ReplacePak("console", "console_DualShock_Square_Black");
				}
				else if (button == "Y/Triangle") {
					ReplacePak("console", "console_DualShock_Triangle_Black");
				}
			}
		}
	}

	__declspec(dllexport) void __cdecl OnFrame()
	{
		// Executed every running frame of SA2
	}

	__declspec(dllexport) void __cdecl OnInput()
	{
		// Executed before the game processes input
	}

	__declspec(dllexport) void __cdecl OnControl()
	{
		// Executed when the game processes input
	}

	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer }; // This is needed for the Mod Loader to recognize the DLL.
}