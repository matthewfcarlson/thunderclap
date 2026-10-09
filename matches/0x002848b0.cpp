class Obj {
  public:
    char pad[0x1c];
    int* base;
    int unk20;
    int count;
    char pad28[4];
    void H1(int);
    void H2(int);
    void H3(int);
    void H4(int);
    void Run(int, int, int*);
};
void Obj::Run(int index, int value, int* out) {
    H1(value);
    H2(value);
    H3(value);
    H4(value);
    ++count;
    int* q = (int*)((char*)base + (index << 6) + 0x30);
    out[0] = q[0];
    out[1] = q[1];
    out[2] = q[2];
}