#pragma once

/*
������DirectX���g�p�����v���O���~���O�́u�v���O���}�u���E�V�F�[�_�v���g���B
*/

/*
DirectX9�ɂ����郊�\�[�X�v���p�e�B�i���ׂẴ��\�[�X�ɂ͈ȉ��̂��̂���`����Ă���j
�g�p���@					�F�u�e�N�X�`���Ŏg���v��u�����_�����O�^�[�Q�b�g�v�Ȃǂ̒�`�B�uD3DUSAGE�v�Œ�`���Ă���B
�T�[�t�F�X�E�t�H�[�}�b�g	�F�u�ԗΐe8�r�b�g�v�Ȃǂ̎w��B�uD3DFORMAT�񋓌^�v�Œ�`���Ă���B
�������E�N���X				�F���\�[�X��u���������̊Ǘ����@�B�uD3DPOOL�񋓌^�v�Œ�`���Ă���B
���\�[�X�^					�F���\�[�X����������Ɍ���B�uD3DRESOURCETYPE�񋓌^�v�Œ�`���Ă���B

�����\�[�X�́u���I���\�[�X�v�Ɓu�ÓI���\�[�X�v������B
�@�قƂ�ǂ́u�ÓI���\�[�X�v�ɑ΂��ẮuD3DPOOL_MANAGED�v���g���̂��x�X�g�B
�@����ɂ��f�o�C�X����������K�v���Ȃ��Ȃ�B
�@�u���I���\�[�X�v�ɂ́uD3DPOOL_MANAGED�v���w�肷��Ƒ傫���p�t�H�[�}���X��
�@�傫���e�����邩�A�uD3DPOOL_MANAGED�v�w�莩�̂��s�\�ɂȂ�B
*/

/*
�������E�N���X�ł͈ȉ���4��ނ���`����Ă���B
D3DPOOL------------>D3DPOOL_DEFAULT
			|		<��>�g�p���@�ɍł��K�����������ɒu�����B	
			|			�g�p�����ꍇ�A�f�o�C�X�������ɕK���A�uIDirect3DDevice9::Reset�v���\�b�h��
			|			�Ăяo���O�ɉ�����āA�f�o�C�X���������Ă���ēx��蒼���K�v������B
			|			����Ńe�N�X�`�������ƁA���I�e�N�X�`����FOURCC�t�H�[�}�b�g�̏ꍇ�ȊO�̓��b�N����Ȃ��B
			|
			|------>D3DPOOL_MANAGED
			|		<��>���\�[�X��Direct3D�ŊǗ�����B���\�[�X�̓V�X�e���������Ƀo�b�N�A�b�v����Ă��āA
			|			���\�[�X���g���K�v��������ƁA�f�o�C�X����g���郁�����֎����I�ɃR�s�[�����B
			|			���̎����ڕύX�����̂̓V�X�e����������̃R�s�[�ŕK�v�ɉ����ĕύX���e��
			|			�f�o�C�X�������ɓ]�������B�܂��A�f�o�C�X���������Ă����\�[�X�𒼂��K�v���Ȃ��B
			|
			|------>D3DPOOL_SYSTEMMEM
			|		<��>�f�o�C�X����A�N�Z�X�ł��Ȃ��V�X�e���������ɒu�����B���̃��\�[�X�̓��b�N���ē��e��
			|			�ύX�ł���B�܂��A�uD3DPOOL_DEFAULT�v�^�C�v�̃��\�[�X�]����Ƃ��Ďg�����Ƃ��ł���B
			|			�f�o�C�X���������Ă����\�[�X�𒼂��K�v���Ȃ��B
			|
			|------>D3DPOOL_SCRATCH
					<��>�V�X�e���������ɒu�����B�f�o�C�X�ɂ�鐧�����󂯂Ȃ����A�f�o�C�X����A�N�Z�X���邱�Ƃ�
						�]���E�`���Ƃ��Ďg�����Ƃ��ł��Ȃ��B��Ƀ��b�N�\�ŁA�f�o�C�X���������Ă����\�[�X�𒼂��K�v���Ȃ��B
*/

/*
����ʍX�V�̎d�g�݂ɂ��ā�
Direct3D9�ł́A2D/3D�O���t�B�b�N�X���o�b�N�o�b�t�@�ɕ`�悵�ĕ\������B
�p�\�R���ɕ\���������e�̓t�����g�o�b�t�@�̓��e�B
���̂��߃o�b�N�o�b�t�@��������������A�t�����g�o�b�t�@�Ƀo�b�N�o�b�t�@��
���e������������K�v������B
���̍X�V�����ɂ́u�t���b�v�v�Ɓu�R�s�[�v������B
��ʓI�ɂ̓t���X�N���[�����[�h�Ńt���b�v�������s���A
�E�B���h�E���[�h�ŃR�s�[�������s����B
*/

/*
��directX9.0�G���[�����֐���

// �G���[�R�[�h�������������Ԃ�
TCHAR *DXGetErrorDescription(HRESULT hr);

���Ή����Ă���G���[�R�[�h��
>>XACT,Direct3D10,D3DX10,Direct3D9,D3D9,Direct3D8,D3DX8
>>DirectDraw,DirectMusic,Directsound,DirectInput,DirectShow
>>Win32 Winerror.h	�̃G���[�R�[�h�ɑΉ����Ă���B


// �G���[�R�[�h�Ɋ֘A�t�����閼�O��Ԃ�
TCHAR *DXGeterrorString(HRESULT hr);

���Ή����Ă���G���[�R�[�h��
>>�Ή�����G���[�R�[�h�́uDXGeterrorDescription�v�Ɠ���


// �n���ꂽ�G���[�R�[�h�����̂܂ܕԂ�
HRESULT DXTrace
(
	CHAR *strFile,	// �t�@�C����������|�C���^�B�u_FILE_�v���g����B
	DWORD dwline,	// �s�ԍ��B�u_LINE_�v���g����B
	HRESULT hr,		// �G���[�R�[�h�B�uDXGetString�֐��v�����������B
	CHAR *strMsg	// �I�v�V�����Ƃ��ĕ\�����镶����|�C���^�B
	BOOL bPopMsgBox	// ���b�Z�[�W�{�b�N�X��\�����邩���w�肷��BTRUE�ŕ\���AFALSE�Ŕ�\���B
);
*/

/*
��DirectX9.0�G���[�����}�N����

// �G���[�����f�o�b�K�ɗ���
HRESULT DXTRACE_ERR(char *str, HRESULT hr);
>>�߂�l�̓}�N���ɓn����hr��Ԃ�

// ���b�Z�[�W�{�b�N�X�ɃG���[����\��
HRESULT DXTRACE_ERR_MSGBOX(char *str, HRESULT hr);
>>�߂�l�̓}�N���ɓn����hr��Ԃ�

// ��������f�o�b�K�ɗ���
HRESULT DXTRACE_MSG(CHAR *str);
>>���������ꍇ��0�ȊO�A���s�����ꍇ0��Ԃ�
*/

/*
���߂�l�̔��聄
������DirectX���\�b�h�͏������������������uHRESULT�^�v�ŕԂ��B
���̂��߁uhr == S_OK�v��uhr == E_FAL�v�Ő���������͂ł��Ȃ��B
�uHRESULT�^�v�Ŕ�����s���ꍇ�́AFAILED�}�N����SUCCEEDED�}�N�����g���B
*/

/*
��������������
1.IDirect3D9�C���^�[�t�F�[�X�̎擾
2.IDirect3DDevice9�C���^�[�t�F�[�X�̎擾
3.�r���[�|�[�g�̐ݒ�

��1.IDirect3D9�C���^�[�t�F�[�X�̎擾��
IDirect3D9�C���^�[�t�F�[�X���擾����ɂ́A�uDirect3Create9�֐��v���g���B
�uDirect3DCreate9�֐��v�̈����ɂ͏��D3D_SDK_VERSION���w�肷��B
���̊֐���Direct3D9�̃|�C���^�^�́uLPDIRECT3D9�^�v��Ԃ��B
�擾�Ɏ��s�����ꍇ��NULL��Ԃ��B

��2.IDirect3DDevice9�C���^�[�t�F�[�X�̎擾��
�f�o�C�X���쐬����ɂ̓E�B���h�E�n���h�����K�v�B
�Ȃ̂ŁA�f�o�C�X�̍쐬��CreateWindow���s��������ɍs���B
*/

/*
�����f�o�C�X�쐬�ȈՃe���v���[�g����
D3DPRESENT_PARAMETERS g_D3DPP;// �f�o�C�X�̓����ݒ肷��\����
LPDIRECT3DDEVICE9 g_pD3DDevice;// �f�o�C�X��IDirect3DDevice9�̃C���^�[�t�F�[�X(IDirect3DDevice9* �� LPDIRECT3DDEVICE9�͓���)

// D3DPRESENT_PARAMETERS�\���̂̐ݒ�
ZeroMemory(&g_D3DPP, sizeof(g_D3DPP));		// ������������
g_D3DPP.Windowed = TRUE;					// �E�B���h�E���[�h���w��
g_D3DPP.SwapEffect = D3DSWAPEFFECT_DISCARD;	// �X���b�v�G�t�F�N�g
g_D3DPP.BackBufferFormat = D3DFMT_UNKOWN;	// �o�b�N�o�b�t�@�̃t�H�[�}�b�g

// IDirect3D9::CreateDevice���\�b�h�̎��s
HRESULT hr = g_D3DPP->CreateDevice
			(
				D3DADAPTER_DEFAULT,					// �f�t�H���g�f�B�X�v���C�A�_�v�^���w��
				D3DDEVTYPE_HAL,						// HAL�f�o�C�X�Ŏw��
				hwnd,								// �t�H�[�J�X����E�B���h�E���w��
				D3DCREATE_SOFTWERE_VERTEXPROCESSING,// �\�t�g�E�F�A���_�������w��
				&g_D3DPP,							// LPDIRECT3DDEVICE9�^�ɃL���X�g�����(�f�o�C�X�̐ݒ���擾)
				&g_pD3DDevice						// IDirect3DDevice9�C���^�[�t�F�[�X���󂯎��ϐ��|�C���^
			);

if(FAILED(hr))
{
	return false;// IDirect3DDevice9�C���^�[�t�F�[�X�̎擾�Ɏ��s
}
�����[�[�[�[�[�[�[�[�[�[�[�[�[�[����
*/

/*
// �f�o�C�X�̍쐬
HRESULT IDirect3D9::CreateDevice
		(
			UINT Adapter,				// �f�B�X�v���C�A�_�v�^�̎w��B D3DADAPTER_DEFAULT���w�肷��Ə�Ƀv���C�}���E�f�B�X�v���C�E�A�_�v�^���w��ł���
			D3DEVTYPE DeviceType,		// �f�o�C�X�^�C�v��D3DDEVTYPE�񋓌^�Ŏw��B
			HWND fFocusWindow,			// ���̃f�o�C�X�Ńt�H�[�J�X����E�B���h�E���w��B
			DWORD BehaviorFlags,		// �f�o�C�X�쐬�𐧌䂷��D3DCREATE�t���O�̑g�ݍ��킹�B
			pPresentationParameters,	// �f�o�C�X��ݒ肷��D3DPRESENT_PARAMETERS�\���̂̃|�C���^�B
			ppReturnedDeviceInterface,	// IDirect3DDevice9�C���^�[�t�F�[�X���󂯎��ϐ��̃|�C���^�B
		);


<<<D3DDEVTYPE�񋓌^>>>
D3DDEVTYPE------------->D3DDEVTYPE_HAL
			|			<��>HAL1�f�o�C�X�B�n�[�h�E�F�A�ɂ�鏈�����s���B
			|
			|
			|---------->D3DDEVTYPE_REF
			|			<��>���t�@�����X���X�^���C�U�B���ׂĂ̋@�\���\�t�g�E�F�A�Ő��m��
			|				�������ꂽ�f�o�C�X�����A���x���x���B��{�I�Ƀf�o�b�O��p�B
			|
			|
			|---------->D3DDEVTYPE_SW
						<��>�v���O�\�ȃ\�t�g�E�F�A�f�o�C�X�B�g�p����\�t�g�E�F�A�f�o�C�X�́A
							���[�U���ŗp�ӂ��ēo�^���Ȃ���΂Ȃ�Ȃ��B��ʓI�ȃA�v���P�[�V�����ł͎g���Ȃ��B

>>�J�����ɂ́uD3DDEVTYPE_REFs�v�͗L�������A�ŏI�I�ɂ́uD3DDEVTYPE_HAL�v�����g��Ȃ��B


<<<D3DCREATE�t���O>>>
D3DCREATE--------------->D3DCREATE_FPU_PRESERVE
			|			<��>�A�v���P�[�V�����Ŕ{���x���������_���g�����Ƃ��w���B
			|				�p�t�H�[�}���X���ቺ����B
			|
			|----------->D3DCREATE_MULTITHREADED
			|			<��>�}���`�X���b�h�ł̈��S����v���B
			|				�p�t�H�[�}���X���ቺ����B
			|
			|----------->D3DCREATE_PUREDEVICE
			|			<��>Direct3D�̓h���C�o�ւ̍œK�ȃp�X�𗘗p�ł���B
			|				�p�t�H�[�}���X�����シ��B
			|				�ꕔ�������āuIDirect3DDevice9::Get�n���\�b�h�v�̌Ăяo�����o���Ȃ��Ȃ�A
			|				�n�[�h�E�F�A�ɂ�钸�_���������ɂȂ�B
			|
			|----------->D3DCREATE_HARDWERE_VERTEXPROCESSING
			|			<��>�n�[�h�E�F�A�ɂ�钸�_�������w��B
			|
			|
			|----------->D3DCREATE_SOFTWERE_VERTEXPROCESSING
			|			<��>�\�t�g�E�F�A�ɂ�钸�_�������w��B
			|				�����Ȃ��̃��C�g���Ⓒ�_�V�F�[�_�@�\���\�t�g�E�F�A�Œ񋟂����B
			|
			|----------->D3DCREATE_MIXED_VERTEXPROCESSING
						<��>�~�b�N�X(�n�[�h�E�F�A�ƃ\�t�g�E�F�A�̗���)���_�������w��B

>>>CreateDevice���\�b�h�ł͏��Ȃ��Ƃ��u�v�u�v�u�v��
>>>�ǂꂩ���w�肵�܂��B�܂��A���̂R�̃t���O�͔r���I�ɂ����g���܂���B
>>>�Ȃ��A�u�s���A�f�o�C�X�v(D3DCREATE_PUREDEVICE)���g���ꍇ�́A
>>>�uD3DCREATE_HARDWERE_VERTEXPROCESSING�v���w�肵�Ȃ���΂Ȃ�Ȃ��B


<<<D3DPRESENT_PARAMETERS�\����>>>
D3DPRESENT_PARAMETERS----------->UINT BackBufferWidth
						|		<��>
						|
						|------->UINT BackBufferHeight
						|		<��>
						|
						|------->D3DFORMAT BackBufferFormat
						|		<��>
						|
						|------->UINT BackBufferCount
						|		<��>
						|
						|------->D3DMULTISAMPLE_TYPE MultiSampleType
						|		<��>
						|
						|------->DWORD MultiSampleQuality
						|		<��>
						|
						|------->D3DSWAPEFFECT SwapEffect
						|		<��>
						|
						|------->HWND hDeviceWindow
						|		<��>
						|
						|------->BOOL Windowed
						|		<��>
						|
						|------->BOOL EnableAutoDepthStencil
								<��>
*/