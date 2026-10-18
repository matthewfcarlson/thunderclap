class C_28b100 {
  public:
    void Decode(int, int*);
};
extern "C" int __cdecl FUN_0028b100(C_28b100* a, C_28b100* b, float scale, int input) {
    int x;
    int y;
    a->Decode(input, &x);
    b->Decode(input, &y);
    int d = y - x;
    return (int)((float)d * scale) + x;
}
