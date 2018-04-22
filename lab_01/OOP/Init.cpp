#include "stdafx.h"
#include "Init.h"

model_my_s init_model(void)
{
	model_my_s model;
	model.count_points = 0;
	model.arr = nullptr;
	model.matrix_contiguities = nullptr;
	return model;
}

/*
 * Инициализация мольберта
 * * easel - мальберт
 * * canva - холст
*/
easel_data_s init_easel(const wrapper_canvas *canva)//easel_data_s *easel, const wrapper_canvas *canva)
{
	easel_data_s easel;
	easel.canvas = canva->pb->CreateGraphics(); // передаем управление холстом мольберту
	easel.backcolor = canva->pb->BackColor;	 // оставляем при отрисовки цвет элемента
	easel.centre.x = canva->pb->Width/2;		 // получение данных о центре 
	easel.centre.y = canva->pb->Height/2;		 // получение данных о центре 
	return easel;
}

shift_mod_data_s init_data_shift(void)
{
	shift_mod_data_s data_shift;
	data_shift.dx = 0;
	data_shift.dy = 0;
	data_shift.dz = 0;
	return data_shift;
}

rotate_mod_data_s init_data_rotate(void)
{
	rotate_mod_data_s data_rotate;
	data_rotate.angle_x = 0;
	data_rotate.angle_y = 0;
	data_rotate.angle_z = 0;
	return data_rotate;
}

mod_diff_data_s init_modif(void)
{
	mod_diff_data_s modif;
	modif.data_shift = init_data_shift();
	modif.data_scale = 1;//0.0;
	modif.data_rotate = init_data_rotate();
	return modif;
}

input_mod_data_u init_mod_data(void)
{
	input_mod_data_u tmp;
	return tmp;
}