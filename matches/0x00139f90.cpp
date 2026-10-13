struct T {
    char pad[0x40];
    void* p;
};

void* __fastcall FUN_00139f90(T* self) {
    return (void*)((char*)self + 0x40);
}
