class X_26e200 {
  public:
    char pad[0x1d4];
    int mHead;
    bool f(void*);
};
bool X_26e200::f(void* p) {
    int i = mHead;
    while (i != 0) {
        if (i == (int)p)
            return true;
        i = *(int*)(i + 0x10);
    }
    return false;
}