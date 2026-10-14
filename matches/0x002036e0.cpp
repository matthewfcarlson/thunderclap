class Obj {
  public:
    char pad[0xaf8];
    int mAf8;
    void Set(int x);
};
void Obj::Set(int x) {
    mAf8 = x;
}
