class Obj_192890 {
    char pad[0x2c];
    int value;

  public:
    bool Set(int v);
};

bool Obj_192890::Set(int v) {
    value = v;
    return true;
}
