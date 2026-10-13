class Obj {
  public:
    char pad[12];
    unsigned int value;
    bool Set(unsigned int x);
};

bool Obj::Set(unsigned int x) {
    value = x;
    return true;
}