typedef unsigned char u8;
void FUN_00213ba0(int, int, int);
struct Obj_1d15d0 {
    char pad[8];
    int value;
    void Run(char flag);
};
void Obj_1d15d0::Run(char flag) {
    if (flag)
        FUN_00213ba0(value, 2, 0);
    else
        FUN_00213ba0(value, 4, 2);
}