class Obj_18cb80 {
  public:
    char pad[0xc];
    int mValue;
    bool Set(int x);
};
bool Obj_18cb80::Set(int x) {
    mValue = x;
    return 1;
}