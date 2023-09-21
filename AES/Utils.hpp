#ifndef UTILS_HPP
#define UTILS_HPP

void PrintArray(unsigned char arr[]);
void RotateOnce(unsigned char arr[]);
void PrintState(unsigned char state[][4]);
void CopyMatrix(unsigned char des[][4],unsigned char src[][4]);
unsigned char SubByte(unsigned char byte);
unsigned char GetRcon(int index);

#endif