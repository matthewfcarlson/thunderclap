// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 6/6)
// FUN_0033bf50 @ 0x0033bf50
struct OutputBuffer {
    char* cursor;
    char storage[520];
};
extern "C" unsigned DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned cookie);
extern "C" unsigned char* __cdecl FUN_00339df0(void* input, int mode, unsigned* length);
extern "C" void __cdecl FUN_00339630(void* input, OutputBuffer* output);
extern "C" void __cdecl FUN_00339470(OutputBuffer* output);
extern "C" unsigned char __cdecl FUN_00345b90(unsigned character);
extern "C" void __cdecl FUN_00339540(OutputBuffer* output);
int __cdecl FUN_0033bf50(void* input) {
    unsigned cookie = DAT_004d9968;
    struct { unsigned length; OutputBuffer output; } local;
    unsigned char* source = FUN_00339df0(input, 1, &local.length);
    FUN_00339630(input, &local.output);
    for (unsigned i = 0; i < local.length; ++i) {
        if (local.output.cursor >= local.output.storage + sizeof(local.output.storage))
            FUN_00339470(&local.output);
        unsigned char ch = FUN_00345b90(source[i]);
        *local.output.cursor = ch;
        ++local.output.cursor;
    }
    FUN_00339540(&local.output);
    __security_check_cookie(cookie);
    return 1;
}