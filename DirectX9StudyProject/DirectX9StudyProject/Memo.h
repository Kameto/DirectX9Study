#pragma once

/*
DirectX9�ɂ����郊�\�[�X�v���p�e�B�i���ׂẴ��\�[�X�ɂ͈ȉ��̂��̂���`����Ă���j
�g�p���@					�F�u�e�N�X�`���Ŏg���v��u�����_�����O�^�[�Q�b�g�v�Ȃǂ̒�`�B�uD3DUSAGE�v�Œ�`���Ă���B
�T�[�t�F�X�E�t�H�[�}�b�g	�F�u�ԗΐe8�r�b�g�v�Ȃǂ̎w��B�uD3DFORMAT�񋓌^�v�Œ�`���Ă���B
�������E�N���X				�F���\�[�X��u���������̊Ǘ����@�B�uD3DPOOL�񋓌^�v�Œ�`���Ă���B
���\�[�X�^					�F���\�[�X����������Ɍ���B�uD3DRESOURCETYPE�񋓌^�v�Œ�`���Ă���B

�������E�N���X�ł͈ȉ���4��ނ���`����Ă���B
D3DPOOL------------>D3DPOOL_DEFAULT
			|		<��>�g�p���@�ɍł��K�����������ɒu�����B	
			|			�g�p�����ꍇ�A�f�o�C�X�������ɕK���A�uIDirect3DDevice9::Reset�v���\�b�h��
			|			�Ăяo���O�ɉ�����āA�f�o�C�X���������Ă���ēx��蒼���K�v������B
			|			����Ńe�N�X�`�������ƁA���I�e�N�X�`����FOURCC�t�H�[�}�b�g�̏ꍇ�ȊO�̓��b�N����Ȃ��B
			|
			|------>D3DPOOL_MANAGED
			|		<��>
			|
			|------>D3DPOOL_SYSTEMMEM
			|		<��>
			|
			|------>D3DPOOL_SCRATCH
					<��>
*/