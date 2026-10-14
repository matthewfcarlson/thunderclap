class Obj_68b00 {
  public:
    char pad[0x5c];
    int m5c;
    bool Set(int v);
};

bool Obj_68b00::Set(int v) {
    m5c = v;
    return true;
}
