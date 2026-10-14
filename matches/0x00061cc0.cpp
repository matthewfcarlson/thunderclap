class Obj_61cc0 {
  public:
    char pad[0x10];
    int value;
    bool Set(int v);
};

bool Obj_61cc0::Set(int v) {
    value = v;
    return true;
}
