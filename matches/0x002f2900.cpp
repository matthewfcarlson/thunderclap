struct S_2f2900 {
    char pad[16];
    float x;
};
float __cdecl FUN_002f2900(S_2f2900* a, S_2f2900* b) {
    float t = b->x;
    float q = a->x;
    if (!(q < t))
        q = t;
    return q;
}
