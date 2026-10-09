struct Result { int value; };
extern Result* __cdecl FUN_00219e50(int, int);
int* __cdecl FUN_00217580(int ptr, int count, int param3) {
    Result* p = FUN_00219e50(ptr, param3);
    if (p->value == 0) {
        *(unsigned char*)(ptr + 6) |= (unsigned char)(1 << count);
        return 0;
    }
    return (int*)p;
}