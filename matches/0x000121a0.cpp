class Obj {
  public:
    char pad[0x88];
    int mValue;
    int Get();
};

int Obj::Get() {
    return mValue;
}
