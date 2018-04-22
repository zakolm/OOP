#ifndef _BASEMATRIX_H_
#define _BASEMATRIX_H_

class BaseMatrix
{
public:
    BaseMatrix(void): rows(0), columns(0){};
    ~BaseMatrix(void){};
	size_t GetRows(void) const {return this->rows;}
	size_t GetColumns(void) const {return this->columns;}
	void SetRows(size_t rows) {this->rows = rows;}
	void SetColumns(size_t columns) {this->columns = columns;}
private:
	size_t columns;
	size_t rows;
};

#endif //_BASEMATRIX_H_