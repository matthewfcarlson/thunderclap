// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002f2d10 @ 0x002f2d10
struct Entry_2f2d10 {
    float x, y, z, w;
    float scale, a, b, c;
};
struct Object {
    Entry_2f2d10 entries[64];
    void FUN_002f2cb0();
    Object* FUN_002f2d10();
};
Object* Object::FUN_002f2d10() {
    for (int i = 0; i < 64; ++i) {
        entries[i].x = 0.0f;
        entries[i].y = 0.0f;
        entries[i].b = 0.0f;
        entries[i].c = 1.0f;
        entries[i].scale = 1.5f;
        entries[i].a = 0.0f;
        entries[i].z = 0.0f;
        entries[i].w = 1.0f;
    }
    FUN_002f2cb0();
    return this;
}
