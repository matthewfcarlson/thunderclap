typedef unsigned int size_t;
extern "C" void* __cdecl FUN_000678d0();
void* __stdcall FUN_00024b90(void* x) {
    char* p = (char*)FUN_000678d0();
    *(void**)(p + 0x2b8) = x;
    return (void*)p;
}
