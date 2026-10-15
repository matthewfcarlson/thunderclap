typedef unsigned int uint;
extern "C" void* __cdecl FUN_0008d690(uint);
struct T {
    T(void*);
    T* fn(void* p);
};
T* __cdecl FUN_003280a0(void* p) {
    T* r = (T*)FUN_0008d690(0x90);
    if (r)
        return r->fn(p);
    return 0;
}