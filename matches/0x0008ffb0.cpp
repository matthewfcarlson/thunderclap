class Obj {
  public:
    char pad[0xc88];
    int mField;
    int Get();
};

int Obj::Get() {
    return mField;
}
