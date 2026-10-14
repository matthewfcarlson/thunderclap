class Obj_11be10 {
  public:
    char pad[0x14];
    int mValue;
    char Fn(int x);
};

char Obj_11be10::Fn(int x) {
    mValue = x;
    return 1;
}
