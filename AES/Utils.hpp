#ifndef UTILS_HPP
#define UTILS_HPP

void PrintVector(std::vector<unsigned char> vector);
void PrintBlocks(std::vector<matrix> blocks);
void RotateOnce(std::vector<unsigned char> &vector);
void PrintState(matrix state);
void CopyMatrix(matrix &des,const matrix &src);
void PrintVector(std::vector<unsigned char> v);
void PrintVectorWOSpaces(std::vector<unsigned char> v);
unsigned char SubByte(unsigned char byte);
unsigned char InverseSubByte(unsigned char byte);
unsigned char GetRcon(int index);
matrix CreateEmptyMatrix();
std::vector<matrix> DivideToMatrix(std::vector<unsigned char> data);
std::vector<unsigned char> FlatMatrixes(std::vector<matrix>  blocks);
std::string BytesToS(std::vector<unsigned char> bytes);

#endif