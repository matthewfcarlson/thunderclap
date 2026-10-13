class Obj {
  public:
    char pad[0x14];
    int mVal;
    int Target();
};
int Obj::Target() {
    return mVal;
}