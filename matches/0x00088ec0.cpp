class Obj {
  public:
    char pad[0xc];
    char mValue;
    void Set(char x);
    void Callback();
};

void Obj::Set(char x) {
    if (mValue != x) {
        Callback();
    }
    mValue = x;
}
