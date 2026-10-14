struct Obj {
    char pad[0x14];
    float field14;
    char pad2[4];
    float field1c;
};

void FUN_002d1310(float value, int unused, Obj* p) {
    p->field14 = value * p->field1c + p->field14;
}
