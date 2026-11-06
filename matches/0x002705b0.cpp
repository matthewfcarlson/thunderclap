// aligned free (0x00270570's blocks): frees the block kept below the aligned address
extern "C" void FUN_003479bc(void*);
void FUN_002705b0(void* ptr) {
    if (ptr) {
        FUN_003479bc(*(void**)((char*)ptr - sizeof(void*)));
    }
}
