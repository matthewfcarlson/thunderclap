typedef unsigned int u32_2eaf30;
struct Obj_2eaf30 {
    char pad[0x24];
    void(__cdecl* fn)(u32_2eaf30, u32_2eaf30);
    u32_2eaf30 value;
};
void __cdecl FUN_002ea2a0(Obj_2eaf30*, Obj_2eaf30*, int);
int __cdecl FUN_002eaf30(Obj_2eaf30* a, Obj_2eaf30* b) {
    FUN_002ea2a0(a, b, 0);
    b->fn(b->value, a->value);
    b->fn(b->value, *((u32_2eaf30*)((char*)a + 0x24)));
    b->fn(b->value, (u32_2eaf30)a);
    return 0;
}