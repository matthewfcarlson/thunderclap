typedef unsigned int u32;
struct Inner { int Find(const void*, void*); };
struct S { char pad[0x2f4]; };
void __fastcall Target(S* self, void*, u32* param, int value) {
    Inner* p = (Inner*)((char*)self + 0x2f4);
    int* result = (int*)p->Find((void*)0x66980, param);
    if (result) {
        *(u32*)((char*)self + 0x380) = param[0];
        *(u32*)((char*)self + 0x384) = param[1];
        *(float*)((char*)result + 0x18) += (float)value;
    }
}