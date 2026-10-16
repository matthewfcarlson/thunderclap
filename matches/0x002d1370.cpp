struct Obj {
    char pad[0x14];
    float value;
    char pad2[4];
    float scale;
};
void __cdecl FUN_002d1370(float delta, int unused, Obj* obj) {
    obj->value += delta * obj->scale;
}