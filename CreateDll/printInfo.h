#pragma once

extern "C" {
	_declspec(dllexport) void printERROR(const char* str);
	_declspec(dllexport) void printWARNING(const char* str);
	_declspec(dllexport) void printLOG(const char* str);
}



