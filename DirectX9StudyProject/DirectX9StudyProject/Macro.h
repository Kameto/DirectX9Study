#pragma once
#define STRICT				// 型チェックを厳密に行う
#define WIN32_LEAN_AND_MEAN	// ヘッダーから余計な関数を省く

// define定数
#define WIDTH 960			// 横幅
#define HEIGHT 680			// 縦幅

// define関数
#define RELEASE(x) { if((x) != nullptr){ delete (x); (x) = nullptr; } }
#define SAFE_RELEASE(x) { if((x)){ (x)->Release(); (x) = NULL; } }

using namespace std;
namespace Error
{
	// エラーチェック
	template <class T>
	inline bool Check(T handle)
	{
		if (RegisterClass(handle))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	template <>
	inline bool Check(HWND handle)
	{
		if (handle != NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};