#pragma once

/*
今回やるDirectXを使用したプログラミングは「プログラマブル・シェーダ」を使う。
*/

/*
DirectX9におけるリソースプロパティ（すべてのリソースには以下のものが定義されている）
使用方法					：「テクスチャで使う」や「レンダリングターゲット」などの定義。「D3DUSAGE」で定義してある。
サーフェス・フォーマット	：「赤緑青各8ビット」などの指定。「D3DFORMAT列挙型」で定義してある。
メモリ・クラス				：リソースを置くメモリの管理方法。「D3DPOOL列挙型」で定義してある。
リソース型					：リソースを作った時に決定。「D3DRESOURCETYPE列挙型」で定義してある。

※リソースは「動的リソース」と「静的リソース」がある。
　ほとんどの「静的リソース」に対しては「D3DPOOL_MANAGED」を使うのがベスト。
　これによりデバイス処理をする必要がなくなる。
　「動的リソース」には「D3DPOOL_MANAGED」を指定すると大きくパフォーマンスに
　大きく影響するか、「D3DPOOL_MANAGED」指定自体が不可能になる。
*/

/*
メモリ・クラスでは以下の4種類が定義されている。
D3DPOOL------------>D3DPOOL_DEFAULT
			|		<∴>使用方法に最も適したメモリに置かれる。	
			|			使用した場合、デバイス消失時に必ず、「IDirect3DDevice9::Reset」メソッドを
			|			呼び出す前に解放して、デバイスが復元してから再度作り直す必要がある。
			|			これでテクスチャを作ると、動的テクスチャとFOURCCフォーマットの場合以外はロックされない。
			|
			|------>D3DPOOL_MANAGED
			|		<∴>リソースをDirect3Dで管理する。リソースはシステムメモリにバックアップされていて、
			|			リソースを使う必要が生じると、デバイスから使えるメモリへ自動的にコピーされる。
			|			この時直接変更されるのはシステムメモリ上のコピーで必要に応じて変更内容が
			|			デバイスメモリに転送される。また、デバイスが消失してもリソースを直す必要がない。
			|
			|------>D3DPOOL_SYSTEMMEM
			|		<∴>デバイスからアクセスできないシステムメモリに置かれる。このリソースはロックして内容を
			|			変更できる。また、「D3DPOOL_DEFAULT」タイプのリソース転送先として使うことができる。
			|			デバイスが消失してもリソースを直す必要がない。
			|
			|------>D3DPOOL_SCRATCH
					<∴>システムメモリに置かれる。デバイスによる制限を受けないが、デバイスからアクセスすることも
						転送・描画先として使うこともできない。常にロック可能で、デバイスが消失してもリソースを直す必要がない。
*/

/*
＜画面更新の仕組みについて＞
Direct3D9では、2D/3Dグラフィックスをバックバッファに描画して表示する。
パソコンに表示される内容はフロントバッファの内容。
そのためバックバッファを書き換えたら、フロントバッファにバックバッファの
内容を書き換える必要がある。
この更新処理には「フリップ」と「コピー」がある。
一般的にはフルスクリーンモードでフリップ処理が行われ、
ウィンドウモードでコピー処理が行われる。
*/

/*
＜directX9.0エラー処理関数＞

// エラーコードを示す文字列を返す
TCHAR *DXGetErrorDescription(HRESULT hr);

＜対応しているエラーコード＞
>>XACT,Direct3D10,D3DX10,Direct3D9,D3D9,Direct3D8,D3DX8
>>DirectDraw,DirectMusic,Directsound,DirectInput,DirectShow
>>Win32 Winerror.h	のエラーコードに対応している。


// エラーコードに関連付けられる名前を返す
TCHAR *DXGeterrorString(HRESULT hr);

＜対応しているエラーコード＞
>>対応するエラーコードは「DXGeterrorDescription」と同じ


// 渡されたエラーコードをそのまま返す
HRESULT DXTrace
(
	CHAR *strFile,	// ファイル名文字列ポインタ。「_FILE_」が使える。
	DWORD dwline,	// 行番号。「_LINE_」が使える。
	HRESULT hr,		// エラーコード。「DXGetString関数」が処理される。
	CHAR *strMsg	// オプションとして表示する文字列ポインタ。
	BOOL bPopMsgBox	// メッセージボックスを表示するかを指定する。TRUEで表示、FALSEで非表示。
);
*/

/*
＜DirectX9.0エラー処理マクロ＞

// エラー情報をデバッガに流す
HRESULT DXTRACE_ERR(char *str, HRESULT hr);
>>戻り値はマクロに渡したhrを返す

// メッセージボックスにエラー情報を表示
HRESULT DXTRACE_ERR_MSGBOX(char *str, HRESULT hr);
>>戻り値はマクロに渡したhrを返す

// 文字列をデバッガに流す
HRESULT DXTRACE_MSG(CHAR *str);
>>成功した場合は0以外、失敗した場合0を返す
*/

/*
＜戻り値の判定＞
多くのDirectXメソッドは処理が成功したかを「HRESULT型」で返す。
そのため「hr == S_OK」や「hr == E_FAL」で正しい判定はできない。
「HRESULT型」で判定を行う場合は、FAILEDマクロやSUCCEEDEDマクロを使う。
*/

/*
＜初期化処理＞
1.IDirect3D9インターフェースの取得
2.IDirect3DDevice9インターフェースの取得
3.ビューポートの設定

＜1.IDirect3D9インターフェースの取得＞
IDirect3D9インターフェースを取得するには、「Direct3Create9関数」を使う。
「Direct3DCreate9関数」の引数には常にD3D_SDK_VERSIONを指定する。
この関数はDirect3D9のポインタ型の「LPDIRECT3D9型」を返す。
取得に失敗した場合はNULLを返す。

＜2.IDirect3DDevice9インターフェースの取得＞
デバイスを作成するにはウィンドウハンドルが必要。
なので、デバイスの作成はCreateWindowを行った直後に行う。
*/

/*
＞＞デバイス作成簡易テンプレート＜＜
D3DPRESENT_PARAMETERS g_D3DPP;// デバイスの動作を設定する構造体
LPDIRECT3DDEVICE9 g_pD3DDevice;// デバイスのIDirect3DDevice9のインターフェース(IDirect3DDevice9* と LPDIRECT3DDEVICE9は同じ)

// D3DPRESENT_PARAMETERS構造体の設定
ZeroMemory(&g_D3DPP, sizeof(g_D3DPP));		// メモリ初期化
g_D3DPP.Windowed = TRUE;					// ウィンドウモードを指定
g_D3DPP.SwapEffect = D3DSWAPEFFECT_DISCARD;	// スワップエフェクト
g_D3DPP.BackBufferFormat = D3DFMT_UNKOWN;	// バックバッファのフォーマット

// IDirect3D9::CreateDeviceメソッドの実行
HRESULT hr = g_D3DPP->CreateDevice
			(
				D3DADAPTER_DEFAULT,					// デフォルトディスプレイアダプタを指定
				D3DDEVTYPE_HAL,						// HALデバイスで指定
				hwnd,								// フォーカスするウィンドウを指定
				D3DCREATE_SOFTWERE_VERTEXPROCESSING,// ソフトウェア頂点処理を指定
				&g_D3DPP,							// LPDIRECT3DDEVICE9型にキャストされる(デバイスの設定を取得)
				&g_pD3DDevice						// IDirect3DDevice9インターフェースを受け取る変数ポインタ
			);

if(FAILED(hr))
{
	return false;// IDirect3DDevice9インターフェースの取得に失敗
}
＞＞ーーーーーーーーーーーーーー＜＜
*/

/*
// デバイスの作成
HRESULT IDirect3D9::CreateDevice
		(
			UINT Adapter,				// ディスプレイアダプタの指定。 D3DADAPTER_DEFAULTを指定すると常にプライマリ・ディスプレイ・アダプタを指定できる
			D3DEVTYPE DeviceType,		// デバイスタイプをD3DDEVTYPE列挙型で指定。
			HWND fFocusWindow,			// このデバイスでフォーカスするウィンドウを指定。
			DWORD BehaviorFlags,		// デバイス作成を制御するD3DCREATEフラグの組み合わせ。
			pPresentationParameters,	// デバイスを設定するD3DPRESENT_PARAMETERS構造体のポインタ。
			ppReturnedDeviceInterface,	// IDirect3DDevice9インターフェースを受け取る変数のポインタ。
		);


<<<D3DDEVTYPE列挙型>>>
D3DDEVTYPE------------->D3DDEVTYPE_HAL
			|			<∴>HAL1デバイス。ハードウェアによる処理を行う。
			|
			|
			|---------->D3DDEVTYPE_REF
			|			<∴>リファレンスラスタライザ。すべての機能がソフトウェアで正確に
			|				実装されたデバイスだが、速度が遅い。基本的にデバッグ専用。
			|
			|
			|---------->D3DDEVTYPE_SW
						<∴>プラグ可能なソフトウェアデバイス。使用するソフトウェアデバイスは、
							ユーザ側で用意して登録しなければならない。一般的なアプリケーションでは使われない。

>>開発時には「D3DDEVTYPE_REFs」は有効だが、最終的には「D3DDEVTYPE_HAL」しか使わない。


<<<D3DCREATEフラグ>>>
D3DCREATE--------------->D3DCREATE_FPU_PRESERVE
			|			<∴>アプリケーションで倍精度浮動小数点を使うことを指示。
			|				パフォーマンスが低下する。
			|
			|----------->D3DCREATE_MULTITHREADED
			|			<∴>マルチスレッドでの安全性を要求。
			|				パフォーマンスが低下する。
			|
			|----------->D3DCREATE_PUREDEVICE
			|			<∴>Direct3Dはドライバへの最適なパスを利用できる。
			|				パフォーマンスが向上する。
			|				一部を除いて「IDirect3DDevice9::Get系メソッド」の呼び出しが出来なくなり、
			|				ハードウェアによる頂点処理だけになる。
			|
			|----------->D3DCREATE_HARDWERE_VERTEXPROCESSING
			|			<∴>ハードウェアによる頂点処理を指定。
			|
			|
			|----------->D3DCREATE_SOFTWERE_VERTEXPROCESSING
			|			<∴>ソフトウェアによる頂点処理を指定。
			|				制限なしのライト数や頂点シェーダ機能がソフトウェアで提供される。
			|
			|----------->D3DCREATE_MIXED_VERTEXPROCESSING
						<∴>ミックス(ハードウェアとソフトウェアの両方)頂点処理を指定。

>>>CreateDeviceメソッドでは少なくとも「」「」「」の
>>>どれかを指定します。また、この３つのフラグは排他的にしか使えません。
>>>なお、「ピュアデバイス」(D3DCREATE_PUREDEVICE)を使う場合は、
>>>「D3DCREATE_HARDWERE_VERTEXPROCESSING」を指定しなければならない。


<<<D3DPRESENT_PARAMETERS構造体>>>
D3DPRESENT_PARAMETERS----------->UINT BackBufferWidth
						|		<∴>
						|
						|------->UINT BackBufferHeight
						|		<∴>
						|
						|------->D3DFORMAT BackBufferFormat
						|		<∴>
						|
						|------->UINT BackBufferCount
						|		<∴>
						|
						|------->D3DMULTISAMPLE_TYPE MultiSampleType
						|		<∴>
						|
						|------->DWORD MultiSampleQuality
						|		<∴>
						|
						|------->D3DSWAPEFFECT SwapEffect
						|		<∴>
						|
						|------->HWND hDeviceWindow
						|		<∴>
						|
						|------->BOOL Windowed
						|		<∴>
						|
						|------->BOOL EnableAutoDepthStencil
								<∴>
*/