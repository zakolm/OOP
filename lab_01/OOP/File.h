#ifndef _FILE_H_
#define _FILE_H_

#include <stdio.h>
#include <stdlib.h>
#include "Init.h"
#include "Constant.h"
#include "Delete.h"

CodeError_e Load_Model1(model_my_s *model, const char *filename);
//CodeError_e load_model(model_my_s *model, const char* filename);

#endif //_FILE_H_