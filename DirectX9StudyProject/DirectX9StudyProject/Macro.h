#pragma once
#define STRICT				// �^�`�F�b�N�������ɍs��
#define WIN32_LEAN_AND_MEAN	// �w�b�_�[����]�v�Ȋ֐����Ȃ�

// define�萔

// define�֐�
#define RELEASE(x) { if((x) != nullptr){ delete (x); (x) = nullptr; } }
#define SAFE_RELEASE(x) { if((x)){ (x)->Release(); (x) = NULL; } }