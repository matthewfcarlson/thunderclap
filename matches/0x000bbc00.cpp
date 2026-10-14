class Sub {
  public:
    int Fn();
};
struct Obj {
    int pad;
    void* mPtr;
    char pad2[0x34 - 8];
    Sub* mSub;
    int Fn2(int a, int b);
};
int Obj::Fn2(int a, int b) {
    void* p = mPtr;
    if (!p)
        return -1;
    Sub* s = *(Sub* volatile*)((char*)p + 0x34);
    if (s)
        s->Fn();
    return 0;
}
