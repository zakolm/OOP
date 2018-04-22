#include "stdafx.h"
#include "Mod.h"

CodeError_e Rotate_Model_f(mod_diff_data_s *modif, const rotate_mod_data_s *data_rotate)
{
	modif->data_rotate.angle_x += data_rotate->angle_x;
	modif->data_rotate.angle_y += data_rotate->angle_y;
	modif->data_rotate.angle_z += data_rotate->angle_z;
	return OK;
}

CodeError_e Scale_Model_f(mod_diff_data_s *modif, const double data_scale)
{
	CodeError_e rc = OK;
	if (data_scale != 0)
		modif->data_scale = data_scale;
	else
		rc = THERE_IS_NO_MODEL;
	return rc;
}

CodeError_e Shift_Model_f(mod_diff_data_s *modif, const shift_mod_data_s *data_shift)
{
	modif->data_shift.dx += data_shift->dx;
	modif->data_shift.dy += data_shift->dy;
	modif->data_shift.dz += data_shift->dz;
	return OK;
}