class Thing {
  public:
    char Set(float f);
    char pad[12];
};

char Thing::Set(float f) {
    char r = 1;
    *(float*)((char*)this + 0xc) = f * 0.0174532925f;
    return r;
}
