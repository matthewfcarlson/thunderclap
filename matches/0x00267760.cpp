extern "C" int __cdecl __vsnprintf(char*, unsigned int, const char*, char*);
void FUN_00267760(char* param_1, unsigned int param_2, const char* param_3) {
    __vsnprintf(param_1, param_2, param_3, (char*)&param_3 + 4);
    if (!(param_2 <= 0U))
        param_1[param_2 - 1] = 0;
}