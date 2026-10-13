class Obj {
  public:
    char pad[0x28];
    void* mVal;
    bool Set(void* v);
};
bool Obj::Set(void* v) {
    mVal = v;
    return 1;
}
