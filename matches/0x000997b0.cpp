class Obj {
  public:
    char pad[0xc4];
    void* m;
    void Set(int a, int b);
};

void Obj::Set(int a, int b) {
    *(int*)((char*)m + 0x1b0) = a;
    *(int*)((char*)m + 0x1b4) = b;
}
