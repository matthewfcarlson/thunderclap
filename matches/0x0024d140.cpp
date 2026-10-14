struct Obj_24d140 {
    char pad[0x54];
    float value;
    float slot58;
    float slot5c;
    float slot60;
};
float __cdecl f1(int, Obj_24d140*);
float __cdecl f2(int, Obj_24d140*);
float __cdecl f3(int, Obj_24d140*);
float __cdecl f4(int, Obj_24d140*);
void __cdecl f5(int, Obj_24d140*, float*, float*);
void __cdecl target(int a, Obj_24d140* b) {
    b->value = f3(a, b) * (f2(a, b) * f1(a, b));
    b->slot60 = f4(a, b);
    f5(a, b, &b->slot58, &b->slot5c);
}