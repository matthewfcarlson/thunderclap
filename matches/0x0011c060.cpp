class Obj_11c060 {
  public:
    char pad[0x28];
    void* mVal;
    bool Set(void* v);
};
bool Obj_11c060::Set(void* v) {
    mVal = v;
    return 1;
}
