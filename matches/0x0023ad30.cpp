struct Owner_23ad30 {
    char pad0[0x12c];
    int count;
    char pad1[8];
    bool Run(int, char*, int);
};
extern void __cdecl FUN_00267880(char*, int, int);
bool Owner_23ad30::Run(int index, char* out, int arg) {
    if (index < 0 || index >= count)
        return false;
    int* status = (int*)((char*)this + (index * 3 + 0x27) * 8);
    if (*status != 4)
        return false;
    if (out) {
        *out = 0;
        int p = *(int*)((char*)this + 0x13c + index * 24);
        while (p) {
            FUN_00267880(out, p, arg);
            p = *(int*)(p + 0x100);
        }
    }
    return true;
}