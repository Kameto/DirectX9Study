#include <atlstr.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <string>
#include <Windows.h>

#include "Macro.h"

HWND hwnd;
HINSTANCE hinst;
LPCSTR clsname = "WindName";

LRESULT CALLBACK WinProc( HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_COMMAND:
		break;
	default:
		break;
	}
	return DefWindowProc(hwnd, msg, wp, lp);
}

WNDCLASS SetWndClass(WNDCLASS _wc, WNDPROC _WinProc, HINSTANCE hInstance)
{
	WNDCLASS wc = _wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = _WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszClassName = clsname;
	wc.lpszMenuName = NULL;
	return wc;
}

HWND NewWind(LPCTSTR classname, LPCTSTR windname, int x, int y, int hei, int wid, HINSTANCE hinst)
{
	return CreateWindowA
	(
		classname,
		windname,
		WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX,
		x,
		y,
		wid,
		hei,
		NULL,
		NULL,
		hinst,
		NULL
	);
}

int WINAPI WinMain( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,_In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	WNDCLASS wc = { NULL };
	MSG msg = { NULL };
	int loopCheck = 0;

	// ウィンドウクラス生成
	wc = SetWndClass(wc,WinProc, hInstance);
	if (!RegisterClass(&wc))
	{
		MessageBox(NULL, "ウィンドウクラス登録失敗", NULL, MB_OK);
		return -1;
	}

	// ウィンドウ生成
	hwnd = NewWind("Direct3D", "Direct3D", 100, 100, 540, 960, hinst);
	if (hwnd == NULL)
	{
		MessageBox(NULL, "ウィンドウ作成失敗", NULL, MB_OK);
		return -1;
	}
	
	hinst = hInstance;
	
	// メインループ
	while (loopCheck = GetMessage(&msg, NULL, 0, 0))
	{
		if (loopCheck == -1)
		{
			break;
		}

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// ウィンドウクラス解放
	UnregisterClass(clsname, hinst);

	return 0;
}