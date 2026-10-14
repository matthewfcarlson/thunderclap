class Obj {
  public:
    char Pad[0xc];
    char Fn(float x);
};

char Obj::Fn(float x) {
    *(float*)((char*)this + 0xc) = x * (3.14159265358979f / 180.0f);
    return 1;
}
