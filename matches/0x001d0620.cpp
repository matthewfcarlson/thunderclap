struct L;
float __cdecl GetNum(L* l, int idx, int def);
float* __cdecl NewUData(L* l, int size);
void __cdecl SetMeta(L* l, const char* name);
void __cdecl Pop(L* l, int n);
int Vec3(L* l) {
    float x = GetNum(l, 1, 0);
    float y = GetNum(l, 2, 0);
    float z = GetNum(l, 3, 0);
    float* v = NewUData(l, 12);
    SetMeta(l, "Vector");
    Pop(l, -2);
    v[0] = x;
    v[1] = y;
    v[2] = z;
    return 1;
}
