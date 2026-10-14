class Obj_133060 {
  public:
    char pad[0x18];
    int value;
    bool Set(int v);
};

bool Obj_133060::Set(int v) {
    value = v;
    return true;
}
