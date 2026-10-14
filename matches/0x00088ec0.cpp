class Obj_88ec0 {
  public:
    char pad[0xc];
    char mValue;
    void Set(char x);
    void Callback();
};

void Obj_88ec0::Set(char x) {
    if (mValue != x) {
        Callback();
    }
    mValue = x;
}
