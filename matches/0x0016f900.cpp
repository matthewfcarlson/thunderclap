// cl-flags: /O1
class Obj_16f900 {
  public:
    char pad[0x18];
    int mVal;
    bool Set(int v);
};

bool Obj_16f900::Set(int v) {
    mVal = v;
    return true;
}