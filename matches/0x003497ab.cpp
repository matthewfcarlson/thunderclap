extern "C" char DAT_0043a0b0[];
extern void __stdcall Init(int*);
class T {
  public:
    int vptr;
    T(int);
};
T::T(int a) {
    Init(&a);
    vptr = ((int)DAT_0043a0b0);
}