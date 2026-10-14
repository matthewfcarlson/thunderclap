class Obj_1a2440 {
  public:
    char pad[0x74];
    int mValue;
    bool Set(int x);
};

bool Obj_1a2440::Set(int x) {
    mValue = x;
    return true;
}
