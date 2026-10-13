class Obj {
  public:
    char pad[0x90];
    int mVal;
    int Get();
};
int Obj::Get() {
    return mVal;
}
