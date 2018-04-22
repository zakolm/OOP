#ifndef _MOD_H_
#define _MOD_H_

#include "Init.h"
#include "Constant.h"

CodeError_e Shift_Model_f(mod_diff_data_s *modif, const shift_mod_data_s *data_shift);
CodeError_e Scale_Model_f(mod_diff_data_s *modif, const double data_scale);
CodeError_e Rotate_Model_f(mod_diff_data_s *modif, const rotate_mod_data_s *data_rotate);

#endif //_MOD_H_