class Obj_17f670 {
  public:
    char pad[0x10];
    char value;
    bool Set(char c);
};

bool Obj_17f670::Set(char c) {
    value = c;
    return true;
}
