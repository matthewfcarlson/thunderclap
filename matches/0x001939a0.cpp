class Obj_1939a0 {
  public:
    char pad[0x5c];
    int mVal;
    bool mFlag;
    bool Set(int x);
};

bool Obj_1939a0::Set(int x) {
    mVal = x;
    return true;
}
