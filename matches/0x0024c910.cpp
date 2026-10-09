struct Obj {
    char pad[0x3c];
    float value;
    int other;
};
void __cdecl FUN_0024c910(Obj* a, float b, int c) {
    a->value = b;
    a->other = c;
}