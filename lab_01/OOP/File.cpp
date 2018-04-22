#include "stdafx.h"
#include "File.h"

CodeError_e scan_count(int *res, FILE *fsrc)
{
	if (fscanf(fsrc, "%d", res) != 1 || *res <= 0)
		return ERROR_FILE;
	else
		return OK;
}

CodeError_e read_from_file_points(point_3d_my_s *arr, FILE *fsrc, int count)
{
	CodeError_e rc = OK;
	point_3d_my_s point;
	for (int i = 0; i < count && rc == OK; ++i)
	{
	if (fscanf(fsrc, "%lf %lf %lf", &point.x, &point.y, &point.z) != 3)
		{
			rc = ERROR_FILE;
		}
		if (rc == OK)
		{
			arr[i].x = point.x;
			arr[i].y = point.y;
			arr[i].z = point.z;
		}
	}

	return rc;
}

CodeError_e scan_point(point_3d_my_s **res, FILE *fsrc, int count)
{
	CodeError_e rc = OK;
	point_3d_my_s *tmp_arr = new point_3d_my_s[count];
	if (!tmp_arr)
		return ERROR_MEMORY;
	
	rc = read_from_file_points(tmp_arr, fsrc, count);

	if (rc == OK)
		*res = tmp_arr;
	return OK;
}

CodeError_e scan_matrix(int ***res, FILE *fsrc, int count)
{
	CodeError_e rc = OK;
	int **tmp_matrix = new int*[count];
	if (!tmp_matrix)
		return ERROR_MEMORY;
	for (int i = 0; i < count; ++i)
	{
		tmp_matrix[i] = new int[count];
		if (!tmp_matrix[i])
		{
			delete [] tmp_matrix;
			return ERROR_MEMORY;
		}
	}

	int item;
	for (int i = 0; i < count && rc == OK; ++i)
	{
		for (int j = 0; j < count && rc == OK; ++j)
		{
			if (fscanf(fsrc, "%d", &item) != 1)
			{
				rc = ERROR_FILE;
			}
			else
				tmp_matrix[i][j] = item;
		}
	}
	if (rc == OK)
		*res = tmp_matrix;

	return rc;
}

void Assignment(model_my_s *model, int count, point_3d_my_s *arr, int **matrix)
{
	model->count_points = count;
	model->arr = arr;
	model->matrix_contiguities = matrix;
}

CodeError_e read_data(model_my_s *model, FILE *fsrc)
{
	CodeError_e rc = OK;
	int count = 0;
	rc = scan_count(&count, fsrc);
	if (rc != OK)
		return rc;

	point_3d_my_s *arr = nullptr;
	rc = scan_point(&arr, fsrc, count);
	if (rc != OK)
		return rc;

	int **matrix = nullptr;
	rc = scan_matrix(&matrix, fsrc, count);
	
	if (rc == OK)
		Assignment(model, count, arr, matrix);

	return rc;
}

CodeError_e load_model(model_my_s *model, const char *filename)
{
	FILE *fsrc = fopen(filename, "r");
	if (!fsrc)
	{
		return ERROR_FILE;
	}
	
	CodeError_e rc = read_data(model, fsrc);

	fclose(fsrc);
	return rc;
}

CodeError_e Load_Model1(model_my_s *model, const char *filename)
{
	model_my_s tmp = init_model();
    CodeError_e rc = load_model(&tmp, filename);
	if (rc == OK)//&& model.count_points > 0)
	{
		Delete_Model(model);
		*model = tmp;
	}
	return rc;
}