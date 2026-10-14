typedef unsigned char u8_1d1980;
typedef unsigned int u32_1d1980;
struct Obj_1d1980 {
    char pad[8];
    int member;
    bool run(u32_1d1980 arg, u8_1d1980 flag);
};
void f1(int, u32_1d1980);
void f2(int, int, int);
void f3(int, int);
bool Obj_1d1980::run(u32_1d1980 arg, u8_1d1980 flag) {
    int v = -3;
    if (flag)
        v = -10001;
    f1(member, arg);
    f2(member, 0, 0);
    f3(member, v);
    return true;
}
