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
    // MSVC evaluates the operands right to left: f1, then f2, then f3
    float x1 = f1(a, b);
    float x2 = f2(a, b) * x1;
    b->value = f3(a, b) * x2;
    b->slot60 = f4(a, b);
    f5(a, b, &b->slot58, &b->slot5c);
}