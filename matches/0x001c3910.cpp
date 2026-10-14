class Obj_1c3910 {
  public:
    char pad[0x64];
    float a;
    float b;
    unsigned char dirty;
    void Set(float x, float y);
};
void Obj_1c3910::Set(float x, float y) {
    if (a != x || b != y) {
        a = x;
        b = y;
        dirty = 0;
    }
}