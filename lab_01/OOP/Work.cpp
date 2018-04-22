#include "stdafx.h"
#include "Work.h"
#include "Mod.h"
#include "Draw.h"
#include "File.h"
#include "Delete.h"

/* 
 * ����� ����� ~ ���������� �������
 */
CodeError_e Task_Manager(const ActionEvent_e &action, const input_mod_data_u *inputdata)
{
    CodeError_e rc = OK;                                     // ��� ������
    static model_my_s model = init_model();                  // ������
    static easel_data_s easel = init_easel(inputdata->canva);// ��������
    static mod_diff_data_s modif = init_modif();             // ���������

    switch(action)
    {
        case canvasInit:                                    // ������������� ���������
        {
            // ������ ��������� ��� �������������, ������ ������� ������ ���� ���� ��������
        }
        break;
        case LoadModel:                                     // �������� �� �����
        {
			rc = Load_Model1(&model, inputdata->filename);
        }
        break;
        case ShiftModel:                                    // ����� ������
        {
            rc = Shift_Model_f(&modif, &inputdata->data_shift);
        }
        break;
        case ScaleModel:                                    // ��������� ��������
         {
            rc = Scale_Model_f(&modif, inputdata->data_scale);
         }
         break;
        case RotateModel:                                   // ��������� ����
         {
            rc = Rotate_Model_f(&modif, &inputdata->data_rotate);
         }
         break;
        case DeleteModel:                                   // �������� ������ �������
        {
            Delete_Model(&model);
        }
        break;
        case ModelDraw:                                     // ��������� ������
        {
			rc = DrawModel(&model, &easel, &modif);
        }
        break;
        default:                                            // ��������� �����
            rc = ERROR_ACTION;
    }
    
    return rc;
}