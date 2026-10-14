class Thing_146950 {
  public:
    char Set(float f);
    char pad[12];
};

char Thing_146950::Set(float f) {
    char r = 1;
    *(float*)((char*)this + 0xc) = f * 0.0174532925f;
    return r;
}
