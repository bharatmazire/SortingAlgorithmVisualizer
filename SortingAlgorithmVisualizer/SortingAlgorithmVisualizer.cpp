#include<Windows.h>
#include"SortingAlgorithmVisualizer.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK MyDlgProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	// variable declaration
	WNDCLASSEX wndclass;
	TCHAR szAppName[] = TEXT("SortAlgoVisualizer");
	HWND hwnd;
	MSG msg;


	wndclass.cbClsExtra = 0;
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.cbWndExtra = 0;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = WndProc;
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wndclass))
		MSGBOX("Register Class Fails ");

	hwnd = CreateWindow(szAppName, TEXT("Sorting Algorithm Visualizer"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	// declaration of variables
	// HDC hdc;
	// PAINTSTRUCT ps;
	// static RECT rc;
	// GetClientRect(hwnd, &rc);
	// HBRUSH hBrush, hBrush1;


	switch (iMsg)
	{
	case WM_CREATE:
		
		break;
	case WM_PAINT:
		
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_SPACE:
			MSGBOX("PRESS SPACE TO START");
			if (DialogBox((HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), MAKEINTRESOURCE(SORTDLG), hwnd, (DLGPROC)MyDlgProc) == IDOK)
			{
				MSGBOX("SUCCESS");
			}
			else
			{
				MSGBOX("FAILURE");
			}
			break;
		case VK_ESCAPE:
			MSGBOX("Distroying Window !!");
			DestroyWindow(hwnd);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

BOOL CALLBACK MyDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_COMMAND:
		case IDOK:
			MSGBOX("OK");
			return TRUE;
		case IDCANCEL:
			EndDialog(hDlg, wParam);
			return TRUE;
	break;
	}
	return FALSE;
}