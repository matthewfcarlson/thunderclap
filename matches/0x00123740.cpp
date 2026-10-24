class Obj_123740 {
  public:
    char Pad[0xc];
    char Fn(float x);
};

char Obj_123740::Fn(float x) {
    *(float*)((char*)this + 0xc) = x * 0.017453292f;
    return 1;
}
