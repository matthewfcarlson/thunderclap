class Obj_68980 {
  public:
    char pad[0x14];
    int value;
    bool Set(int arg);
};

bool Obj_68980::Set(int arg) {
    value = arg;
    return true;
}