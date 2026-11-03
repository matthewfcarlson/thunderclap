extern "C" void* __cdecl malloc(unsigned int);
extern "C" void* __cdecl FUN_00270540(unsigned int size) {
    if (size == 0)
        size = 1;
    return malloc(size);
}