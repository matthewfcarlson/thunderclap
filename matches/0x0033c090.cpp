extern "C" unsigned char* __cdecl FUN_00339df0(void* input, int flag, unsigned int* length);
extern "C" int __cdecl FUN_00339fe0(void* input, int mode, int flag);
extern "C" void __cdecl FUN_00213360(void* input, unsigned int value);

int __cdecl FUN_0033c090(void* input) {
    unsigned int length;
    unsigned char* bytes = FUN_00339df0(input, 1, &length);
    unsigned int oldLength = length;
    int result = FUN_00339fe0(input, 2, 1);
    unsigned int index = (unsigned int)result;
    if (result < 0)
        index += oldLength + 1;
    if ((int)index > 0 && index <= length) {
        FUN_00213360(input, bytes[index - 1]);
        return 1;
    }
    return 0;
}