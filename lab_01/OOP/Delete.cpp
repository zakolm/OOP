#include "stdafx.h"
#include "Delete.h"

void Delete_Model(model_my_s *model)
{
	delete [] model->arr;

	for (int i = 0; i < model->count_points; ++i)
	{
		delete [] model->matrix_contiguities[i];
	}
	delete [] model->matrix_contiguities;
}