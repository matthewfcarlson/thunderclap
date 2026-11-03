typedef void(__cdecl* Callback_2e6ab0)(void*, int);
void __cdecl FUN_003479bc(int);
void __cdecl FUN_002e6ab0(int ptr, Callback_2e6ab0 callback) {
    char local[0x21c];
    if (ptr != 0) {
        if (callback != 0)
            callback(local, ptr);
        else
            FUN_003479bc(ptr);
    }
}