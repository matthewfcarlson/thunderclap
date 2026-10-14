class Obj_12b280 {
  public:
    char pad[0xc];
    int mVal;
    bool Set(int x);
};
bool Obj_12b280::Set(int x) {
    mVal = x;
    return true;
}
