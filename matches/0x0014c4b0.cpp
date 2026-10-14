// cl-flags: /O1
class Obj_14c4b0 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int v);
};

bool Obj_14c4b0::Set(int v) {
    mValue = v;
    return true;
}
