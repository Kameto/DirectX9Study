#pragma once
#define STRICT				// 型チェックを厳密に行う
#define WIN32_LEAN_AND_MEAN	// ヘッダーから余計な関数を省く

// define定数

// define関数
#define RELEASE(x) { if((x) != nullptr){ delete (x); (x) = nullptr; } }
#define SAFE_RELEASE(x) { if((x)){ (x)->Release(); (x) = NULL; } }