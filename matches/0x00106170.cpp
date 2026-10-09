class C {
  public:
    char pad0[0x10];
    void* items;
    int count;
    bool set(int index, int a, int b, int c);
};
bool C::set(int index, int a, int b, int c) {
    if (index < count) {
        int* p = (int*)((char*)items + index * 0x24);
        p[0] = a;
        p[1] = b;
        p[2] = c;
        return true;
    }
    return false;
}