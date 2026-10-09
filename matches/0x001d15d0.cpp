typedef unsigned char u8;
void FUN_00213ba0(int, int, int);
struct Obj { char pad[8]; int value; void Run(char flag); };
void Obj::Run(char flag) {
    if (flag) FUN_00213ba0(value, 2, 0);
    else FUN_00213ba0(value, 4, 2);
}