#include "Matrix.h"
#include "math.h"

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
	// 항등 행렬로 초기화
	mat4_t scale_mat = mat4_identity();

	// 대각선 자리를 크기로 넣어줌으로써 Scale Matrix 구성
	scale_mat.m[0][0] = sx;
	scale_mat.m[1][1] = sy;
	scale_mat.m[2][2] = sz;

	return scale_mat;
}

mat4_t mat4_make_translation(float tx, float ty, float tz)
{
	mat4_t translation_mat = mat4_identity();

	// 동차 좌표에 더해지기 위해 마지막 행에 이동값을 적용
	translation_mat.m[0][3] = tx;
	translation_mat.m[1][3] = ty;
	translation_mat.m[2][3] = tz;

	return translation_mat;
}

// x를 제외한 y,z가 변경
mat4_t mat4_make_rotation_x(float angle)
{
	float c = cos(angle);
	float s = sin(angle);

	mat4_t rotation_x_mat = mat4_identity();
	rotation_x_mat.m[1][1] = c;
	rotation_x_mat.m[1][2] = -s;
	rotation_x_mat.m[2][1] = s;
	rotation_x_mat.m[2][2] = c;

	return rotation_x_mat;
}

// y를 제외한 x,z가 변경
mat4_t mat4_make_rotation_y(float angle)
{
	float c = cos(angle);
	float s = sin(angle);

	mat4_t rotation_y_mat = mat4_identity();
	rotation_y_mat.m[0][0] = c;
	rotation_y_mat.m[0][2] = s;
	rotation_y_mat.m[2][0] = -s;
	rotation_y_mat.m[2][2] = c;

	return rotation_y_mat;
}

// z를 제외한 x,y가 변경
mat4_t mat4_make_rotation_z(float angle)
{
	float c = cos(angle);
	float s = sin(angle);

	mat4_t rotation_z_mat = mat4_identity();
	rotation_z_mat.m[0][0] = c;
	rotation_z_mat.m[0][1] = -s;
	rotation_z_mat.m[1][0] = s;
	rotation_z_mat.m[1][1] = c;

	return rotation_z_mat;
}

vec4_t mat4_mul_vec4(mat4_t m, vec4_t v)
{
	vec4_t result;
	result.x = m.m[0][0] * v.x + m.m[0][1] * v.y + m.m[0][2] * v.z + m.m[0][3] * v.w;
	result.y = m.m[1][0] * v.x + m.m[1][1] * v.y + m.m[1][2] * v.z + m.m[1][3] * v.w;
	result.z = m.m[2][0] * v.x + m.m[2][1] * v.y + m.m[2][2] * v.z + m.m[2][3] * v.w;
	result.w = m.m[3][0] * v.x + m.m[3][1] * v.y + m.m[3][2] * v.z + m.m[3][3] * v.w;

	return result;
}

mat4_t mat4_mul_mat4(mat4_t a, mat4_t b)
{
	mat4_t result;

	return result;
}
