#ifndef _Init_H_
#define _Init_H_

#include <gcroot.h>

using namespace System::Drawing;

// точки модели
struct point_3d_my_s
{
	double x;
	double y;
	double z;
};
// модель
struct model_my_s
{
	int count_points;
	point_3d_my_s *arr;
	int **matrix_contiguities;
};

// отрисовка
struct point_my_s
{
	int x;
	int y;
};
// мольберт
struct easel_data_s
{
	gcroot<Graphics^> canvas;
	gcroot<Color> backcolor;
	point_my_s centre;
};
// обертка над холстом
struct wrapper_canvas
{
	gcroot<System::Windows::Forms::PictureBox^> pb;
};

// смещение
struct shift_mod_data_s
{
	int dx;
	int dy;
	int dz;
};
// изменение угла
struct rotate_mod_data_s
{
	int angle_x;
	int angle_y;
	int angle_z;
};
// изменения
struct mod_diff_data_s
{
	shift_mod_data_s data_shift;
	double data_scale;
	rotate_mod_data_s data_rotate;
};

model_my_s init_model(void);
easel_data_s init_easel(const wrapper_canvas *canva); // Инициализация мольберта
mod_diff_data_s init_modif(void);

// объединение для ввода изменений
union input_mod_data_u
{
	shift_mod_data_s data_shift;
	double data_scale;
	rotate_mod_data_s data_rotate;
	wrapper_canvas* canva;
	char *filename;
};
input_mod_data_u init_mod_data(void);

#endif //_Init_H_