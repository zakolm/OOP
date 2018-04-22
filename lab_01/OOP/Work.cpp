#include "stdafx.h"
#include "Work.h"
#include "Mod.h"
#include "Draw.h"
#include "File.h"
#include "Delete.h"

/* 
 * Точка Входа ~ Обработчик событий
 */
CodeError_e Task_Manager(const ActionEvent_e &action, const input_mod_data_u *inputdata)
{
    CodeError_e rc = OK;                                     // код ошибки
    static model_my_s model = init_model();                  // модель
    static easel_data_s easel = init_easel(inputdata->canva);// мольберт
    static mod_diff_data_s modif = init_modif();             // изменения

    switch(action)
    {
        case canvasInit:                                    // Инициализация мольберта
        {
            // Сверху произошла вся инициализация, просто функция должна была быть вызавана
        }
        break;
        case LoadModel:                                     // Загрузка из файла
        {
			rc = Load_Model1(&model, inputdata->filename);
        }
        break;
        case ShiftModel:                                    // Сдвиг модели
        {
            rc = Shift_Model_f(&modif, &inputdata->data_shift);
        }
        break;
        case ScaleModel:                                    // Изменение масштаба
         {
            rc = Scale_Model_f(&modif, inputdata->data_scale);
         }
         break;
        case RotateModel:                                   // Изменение угла
         {
            rc = Rotate_Model_f(&modif, &inputdata->data_rotate);
         }
         break;
        case DeleteModel:                                   // Удаление данных объекта
        {
            Delete_Model(&model);
        }
        break;
        case ModelDraw:                                     // Отрисовка фигуры
        {
			rc = DrawModel(&model, &easel, &modif);
        }
        break;
        default:                                            // Ошибочный вызов
            rc = ERROR_ACTION;
    }
    
    return rc;
}