extern "C" void* malloc(unsigned int);
extern "C" void FUN_002e69a0(unsigned int, const char*);
void* FUN_002e6af0(unsigned int context, unsigned int size) {
    void* p = malloc(size);
    if (!p)
        FUN_002e69a0(context, "Out of Memory");
    return p;
}