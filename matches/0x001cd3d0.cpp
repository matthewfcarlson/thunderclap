class Obj_1cd3d0 {
  public:
    char pad0[8];
    int field8;
    int padc;
    int data[0x40];
    char pad110[0x1194 - 0x110];
    int last;
    void Init(int);
    void Tail(int);
};
void Obj_1cd3d0::Init(int value) {
    field8 = value;
    for (int i = 0; i < 0x40; ++i)
        data[i] = 0;
    last = 0;
    Tail(1);
}