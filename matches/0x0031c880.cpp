typedef unsigned int U32;
struct Obj { char pad[8]; U32 index; U32 base; void Copy(U32); };
struct Temp { void Run(U32, void*); };
extern "C" void* memcpy(void*, const void*, unsigned int);
void Obj::Copy(U32 param) {
    char local[64];
    void* dst = (void*)(index * 64 + base);
    ((Temp*)local)->Run(param, dst);
    dst = (void*)(index * 64 + base);
    memcpy(dst, local, 64);
}