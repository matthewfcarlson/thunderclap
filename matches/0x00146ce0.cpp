class Obj_146ce0 {
  public:
    char pad[0x1c];
    int mVal;
    bool Set(int v);
};

bool Obj_146ce0::Set(int v) {
    mVal = v;
    return true;
}
