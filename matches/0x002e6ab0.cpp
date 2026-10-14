typedef void(__cdecl* Callback_2e6ab0)(void*, int);
void __cdecl FUN_003479bc(int);
void __cdecl FUN_002e6ab0(int param_1, Callback_2e6ab0 param_2) {
    char local[0x21c];
    if (param_1 != 0) {
        if (param_2 != 0)
            param_2(local, param_1);
        else
            FUN_003479bc(param_1);
    }
}