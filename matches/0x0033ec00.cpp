typedef unsigned char u8;
extern void __cdecl FUN_003479bc(void*);
typedef void(__stdcall* Thunk)(void*);
void __stdcall FUN_0033ec00(void* p) {
    if (p) {
        unsigned int n = *((u8*)p - 1);
        if (*((u8*)p - 2) == 3) {
            Thunk f = (Thunk)(*((Thunk*)p - 2));
            return f((char*)p - n);
        }
        FUN_003479bc((char*)p - n);
    }
}