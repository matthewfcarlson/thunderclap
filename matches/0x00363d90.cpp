extern "C" char DAT_004ddb10[];
extern void __stdcall FUN_00013420(void*, int, int, void*);
void FUN_00363d90() {
    char* p = (char*)((int)DAT_004ddb10);
    int i = 2;
    do {
        p -= 0x30;
        FUN_00013420(p, 8, 6, (void*)0xb0ff0);
        --i;
    } while (i);
}