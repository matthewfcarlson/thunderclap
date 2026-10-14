class Obj {
  public:
    char pad[0xd0];
    int mValue;
    void Set(int value);
};

void Obj::Set(int value) {
    mValue = value;
}
