extern "C" char DAT_003f3f38[];
extern int __cdecl Query(int, int);
extern int __cdecl Format(int, int, const char*, int);
extern void __cdecl Finish(int, int);
class Obj_1d19f0 {
    char pad[8];

  public:
    int field;
    bool Run(int a, int b, char flag);
};
bool Obj_1d19f0::Run(int a, int b, char flag) {
    int x = Query(field, -1);
    bool r = true;
    if (x == 0) {
        r = false;
    } else {
        Format(a, b, (const char*)((int)DAT_003f3f38), x);
    }
    if (flag)
        Finish(field, -2);
    return r;
}