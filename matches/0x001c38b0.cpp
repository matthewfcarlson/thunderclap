struct Obj_1c38b0 {
    char pad[0x5c];
    float x;
    float y;
    char pad2[8];
    unsigned char dirty;
    void Set(float a, float b);
};
void Obj_1c38b0::Set(float a, float b) {
    if (x != a || y != b) {
        x = a;
        y = b;
        dirty = 0;
    }
}