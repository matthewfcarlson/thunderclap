class Obj {
  public:
    char pad[0xc4];
    void* m180;
    void Set(int value);
};

void Obj::Set(int value) {
    *(int*)((char*)m180 + 0x180) = value;
}
