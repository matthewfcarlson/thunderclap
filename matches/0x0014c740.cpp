class Obj_14c740 {
  public:
    char pad[12];
    unsigned int value;
    bool Set(unsigned int x);
};

bool Obj_14c740::Set(unsigned int x) {
    value = x;
    return true;
}