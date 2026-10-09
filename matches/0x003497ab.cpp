extern void __stdcall Init(int*);
class T {
  public:
    int vptr;
    T(int);
};
T::T(int a) {
    Init(&a);
    vptr = 0x43a0b0;
}