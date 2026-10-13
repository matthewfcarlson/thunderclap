class Obj {
  public:
    char pad[0x18];
    int mValue;
    int Get();
};

int Obj::Get() {
    return mValue;
}