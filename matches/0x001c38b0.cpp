struct Obj {
    char pad[0x5c];
    float x;
    float y;
    char pad2[8];
    unsigned char dirty;
    void Set(float a, float b);
};
void Obj::Set(float a, float b) {
    if (x != a || y != b) {
        x = a;
        y = b;
        dirty = 0;
    }
}