extern void __stdcall FUN_00013420(void*, int, int, void*);
void target() {
    char* p = (char*)0x4ddbc8;
    int i = 2;
    do {
        FUN_00013420(p, ((p -= 0x30), 8), 6, (void*)0xb0ff0);
    } while (--i);
}