#include "Matrix.h"

mat4_t mat4_identity(void)
{
	mat4_t identity = { 
		{
			{1, 0, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 1},
		}
	};
	return identity;
}

mat4_t mat4_make_scale(float sx, float sy, float sz)
{
	// �׵� ��ķ� �ʱ�ȭ
	mat4_t scale_mat = mat4_identity();

	// �밢�� �ڸ��� ũ��� �־������ν� Scale Matrix ����
	scale_mat.m[0][0] = sx;
	scale_mat.m[1][1] = sy;
	scale_mat.m[2][2] = sz;

	return scale_mat;
}
