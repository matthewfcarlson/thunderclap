extern "C" char DAT_0043a0b0[];
extern void __stdcall Init(int*);
class T_3497ab {
  public:
    int vptr;
    T_3497ab(int);
};
T_3497ab::T_3497ab(int a) {
    Init(&a);
    vptr = ((int)DAT_0043a0b0);
}