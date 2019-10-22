#pragma once
#define STRICT				// �^�`�F�b�N�������ɍs��
#define WIN32_LEAN_AND_MEAN	// �w�b�_�[����]�v�Ȋ֐����Ȃ�

// define�萔
#define WIDTH 960			// ����
#define HEIGHT 680			// �c��

// define�֐�
#define RELEASE(x) { if((x) != nullptr){ delete (x); (x) = nullptr; } }
#define SAFE_RELEASE(x) { if((x)){ (x)->Release(); (x) = NULL; } }

using namespace std;
namespace Error
{
	// �G���[�`�F�b�N
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