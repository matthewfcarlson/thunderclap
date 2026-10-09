extern "C" void* malloc(unsigned int);
extern "C" void FUN_002e69a0(unsigned int, const char*);
void* FUN_002e6af0(unsigned int param_1, unsigned int param_2) {
    void* p = malloc(param_2);
    if (!p)
        FUN_002e69a0(param_1, "Out of Memory");
    return p;
}