#include "stdafx.h"
#include "Draw.h"
#include "ConvertPoint.h"

void DrawLine(easel_data_s *easel, point_my_s from, point_my_s to)
{
	easel->canvas->DrawLine(Pens::Black, from.x, from.y,  to.x, to.y);
}

void DrawEdges(model_my_s *model, easel_data_s *easel, point_my_s *obj)
{
	for (int i = 0; i < model->count_points; ++i)
	{
		for (int j = i + 1; j < model->count_points; ++j)
		{
			if (model->matrix_contiguities[i][j])
			{
				DrawLine(easel, obj[i], obj[j]);
			}
		}
	}
}

void PrepareCanvas(easel_data_s *easel)
{
	easel->canvas->Clear(easel->backcolor);
}

CodeError_e DrawModel(model_my_s *model, easel_data_s *easel, mod_diff_data_s *modif)
{
	CodeError_e rc = ERROR_DRAW;
	if (model->count_points > 0)
	{
		//переводим точки модели в точки холста, с учётом "параметров экрана"
		point_my_s *obj = ConvertPoints(model, modif, easel);

		PrepareCanvas(easel);

		//отрисовываем рёбра модели//obj
		DrawEdges(model, easel, obj);//modif);//conv, easel, &(mdl->edges));
		rc = OK;
	}
	return rc;
}