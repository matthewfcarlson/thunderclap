extern "C" void __cdecl FUN_00066980();
typedef unsigned int u32_670a0;
struct Inner_670a0 {
    int Find(const void*, void*);
};
struct S_670a0 {
    char pad[0x2f4];
};
void __fastcall Target(S_670a0* self, void*, u32_670a0* param, int value) {
    Inner_670a0* p = (Inner_670a0*)((char*)self + 0x2f4);
    int* result = (int*)p->Find((void*)((int)(void (__cdecl*)())&FUN_00066980), param);
    if (result) {
        *(u32_670a0*)((char*)self + 0x380) = param[0];
        *(u32_670a0*)((char*)self + 0x384) = param[1];
        *(float*)((char*)result + 0x18) += (float)value;
    }
}