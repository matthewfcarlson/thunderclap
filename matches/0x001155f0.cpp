class Obj_1155f0 {
  public:
    char pad[0x20];
    int value;
    bool Set(int v);
};

bool Obj_1155f0::Set(int v) {
    value = v;
    return true;
}
