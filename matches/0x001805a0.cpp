class Obj_1805a0 {
  public:
    char pad[0x10];
    int m10;
    bool Set(int v);
};

bool Obj_1805a0::Set(int v) {
    m10 = v;
    return true;
}