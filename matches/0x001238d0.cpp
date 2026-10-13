class Obj {
  public:
    char pad[12];
    unsigned int value;
    bool Set(unsigned int v);
};

bool Obj::Set(unsigned int v) {
    value = v;
    return true;
}
