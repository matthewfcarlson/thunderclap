class Obj_16ecb0 {
  public:
    char pad[0x18];
    int mValue;
    bool Set(int v);
};

bool Obj_16ecb0::Set(int v) {
    mValue = v;
    return true;
}
