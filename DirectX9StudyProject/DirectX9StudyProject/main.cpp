#include <atlstr.h>
#include <string>
#include <Windows.h>

#include "Macro.h"

HWND hwnd;
HINSTANCE hinst;
LPCSTR clsname = "test";

inline LRESULT CALLBACK WinProc( HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
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

inline WNDCLASS SetWndClass(WNDPROC _WinProc, HINSTANCE hInstance, LPCSTR wndName)
{
	WNDCLASS wc = { NULL };
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hCursor = NULL;
	wc.hIcon = NULL;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszClassName = clsname;
	wc.lpszMenuName = NULL;
	return wc;
}

inline HWND NewCreateWindow(LPCTSTR _classname, LPCTSTR wind_name, int _x, int _y, int _height, int _width, HINSTANCE _hinst)
{
	return CreateWindowA(
		_classname,
		wind_name,
		WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX,
		_x,
		_y,
		_width,
		_height,
		NULL,
		NULL,
		_hinst,
		NULL
	);
}

int WINAPI WinMain( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,_In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	
	WNDCLASS wc		 = { NULL };
	MSG msg			 = { NULL };

	// �E�B���h�E�N���X����
	wc = SetWndClass(WinProc, hInstance, clsname);
	if (!Error::Check(&wc))
	{
		MessageBox(NULL, "�E�B���h�E�N���X�o�^���s", NULL, MB_OK);
		return -1;
	}

	// �E�B���h�E����
	hwnd = NewCreateWindow("test","Direct3D", 100, 100, HEIGHT, WIDTH, hInstance);
	if (!Error::Check(hwnd))
	{
		MessageBox(NULL, "�E�B���h�E�쐬���s", NULL, MB_OK);
		return -1;
	}
	
	hinst = hInstance;
	int loopCheck = 0;
	// ���C�����[�v
	while (loopCheck = GetMessage(&msg, NULL, 0, 0))
	{
		if (loopCheck == -1)
		{
			break;
		}

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// �E�B���h�E�N���X���
	UnregisterClass(clsname, hinst);

	return 0;
}