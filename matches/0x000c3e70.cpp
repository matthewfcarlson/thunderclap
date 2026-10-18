typedef unsigned int uint_000c3e70;
class Helper {
  public:
    int Fn(int x);
};
class C_000c3e70 {
  public:
    int pad;
    Helper* mPtr;
    int Fn(uint_000c3e70 a, int* b);
};
int C_000c3e70::Fn(uint_000c3e70 a, int* b) {
    Helper* p = mPtr;
    if (!p)
        return -1;
    if (a != 1)
        return -1;
    int x = *b;
    mPtr->Fn(x);
    return 0;
}
