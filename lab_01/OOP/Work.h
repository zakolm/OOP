#ifndef _Work_H_
#define _Work_H_

#include "Constant.h"
#include "Init.h"

enum ActionEvent_e 
{
	canvasInit, // инициализация мольберта
	LoadModel,  // загрузка модели из файла
	ShiftModel, // сдвиг модели
	ScaleModel, // масштабирование модели
	RotateModel,// поворот модели
	DeleteModel,// удаление элементов
	ModelDraw   // отрисовка модели
};

// обработчик
CodeError_e Task_Manager(const ActionEvent_e &action, const input_mod_data_u *inputdata);

#endif //_Work_H_
