class Obj_68280 {
  public:
    char pad[0xc];
    int value;
    bool Set(int arg);
};

bool Obj_68280::Set(int arg) {
    value = arg;
    return true;
}
