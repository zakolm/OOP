#include "stdafx.h"
#include "ConvertPoint.h"
#define _USE_MATH_DEFINES
#include <math.h>

double MyConvertAngle(int angle)
{
	return (angle * M_PI / 180);
}

void ProcessRotate_x(point_3d_my_s *obj, mod_diff_data_s *modif, int count)
{
	int tmp_x, tmp_y, tmp_z;
	double angle = MyConvertAngle(modif->data_rotate.angle_x);
	for (int i = 0; i < count; ++i)
	{
		tmp_x = obj[i].x;
		tmp_y = obj[i].y * cos(angle) + obj[i].z * sin(angle);
		tmp_z = -obj[i].y * sin(angle) + obj[i].z * cos(angle);

		obj[i].x = tmp_x;
		obj[i].y = tmp_y;
		obj[i].z = tmp_z;
	}
}

void ProcessRotate_y(point_3d_my_s *obj, mod_diff_data_s *modif, int count)
{
	int tmp_x, tmp_y, tmp_z;
	double angle = MyConvertAngle(modif->data_rotate.angle_y);
	for (int i = 0; i < count; ++i)
	{
		tmp_x = obj[i].x * cos(angle) + obj[i].z * sin(angle);
		tmp_y = obj[i].y;
		tmp_z = -obj[i].x * sin(angle) + obj[i].z * cos(angle);

		obj[i].x = tmp_x;
		obj[i].y = tmp_y;
		obj[i].z = tmp_z;
	}
}

void ProcessRotate_z(point_3d_my_s *obj, mod_diff_data_s *modif, int count)
{
	int tmp_x, tmp_y, tmp_z;
	double angle = MyConvertAngle(modif->data_rotate.angle_z);
	for (int i = 0; i < count; ++i)
	{
		tmp_x = obj[i].x * cos(angle) - obj[i].y * sin(angle);
		tmp_y = obj[i].x * sin(angle) + obj[i].y * cos(angle);
		tmp_z = obj[i].z;

		obj[i].x = tmp_x;
		obj[i].y = tmp_y;
		obj[i].z = tmp_z;
	}
}

void ProcessRotate(point_3d_my_s *obj, mod_diff_data_s *modif, int count)
{
	ProcessRotate_x(obj, modif, count);
	ProcessRotate_y(obj, modif, count);
	ProcessRotate_z(obj, modif, count);
}

void ProcessScale(point_3d_my_s *obj, mod_diff_data_s *modif, int count)
{
	for (int i = 0; i < count; ++i)
	{
		obj[i].x *= modif->data_scale;
		obj[i].y *= modif->data_scale;
		obj[i].z *= modif->data_scale;
	}
}

void ProcessShift(point_3d_my_s *obj, mod_diff_data_s *modif, int count)
{
	for (int i = 0; i < count; ++i)
	{
		obj[i].x += modif->data_shift.dx;
		obj[i].y += modif->data_shift.dy;
		obj[i].z += modif->data_shift.dz;
	}
}

void ProcessMode(point_3d_my_s *res, mod_diff_data_s *modif, int count)
{
	ProcessShift(res, modif, count);
	ProcessScale(res, modif, count);
	ProcessRotate(res, modif, count);
}

point_3d_my_s *CreateModPoints(model_my_s *model, mod_diff_data_s *modif)
{
	point_3d_my_s *res = new point_3d_my_s[model->count_points];
	for (int i = 0; i < model->count_points; ++i)
	{
		res[i].x = model->arr[i].x;
		res[i].y = model->arr[i].y;
		res[i].z = model->arr[i].z;
	}
	ProcessMode(res, modif, model->count_points);
	return res;
}

point_my_s *ConvertPoints(model_my_s *model, mod_diff_data_s *modif, easel_data_s *easel)
{
	point_3d_my_s *obj = CreateModPoints(model, modif);
	point_my_s *res = new point_my_s[model->count_points];
	for (int i = 0; i < model->count_points; ++i)
	{
		res[i].x = obj[i].x + easel->centre.x;
		res[i].y = obj[i].y + easel->centre.y;
	}
	return res;
}