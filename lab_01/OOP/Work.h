#ifndef _Work_H_
#define _Work_H_

#include "Constant.h"
#include "Init.h"

enum ActionEvent_e 
{
	canvasInit, // ������������� ���������
	LoadModel,  // �������� ������ �� �����
	ShiftModel, // ����� ������
	ScaleModel, // ��������������� ������
	RotateModel,// ������� ������
	DeleteModel,// �������� ���������
	ModelDraw   // ��������� ������
};

// ����������
CodeError_e Task_Manager(const ActionEvent_e &action, const input_mod_data_u *inputdata);

#endif //_Work_H_
