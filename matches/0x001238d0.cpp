class Obj_1238d0 {
  public:
    char pad[12];
    unsigned int value;
    bool Set(unsigned int v);
};

bool Obj_1238d0::Set(unsigned int v) {
    value = v;
    return true;
}
