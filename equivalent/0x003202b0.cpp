// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_003202b0 @ 0x003202b0
extern "C" unsigned int __stdcall FUN_003a8753(int, const char *, int, int, int, int *, int, int, int, int, int);
extern "C" void * __stdcall FUN_003a04fc(int);
extern "C" unsigned int __stdcall FUN_003a41dc(int);
namespace D3D8 { unsigned int __stdcall D3DDevice_CreatePixelShader(void *, unsigned int); }

bool __stdcall FUN_003202b0(const char *source, unsigned int shader)
{
    int buffer = 0;
    const char *end = source;
    while (*end) ++end;
    unsigned int result = FUN_003a8753(0, source, (int)(end - source), 0, 0, &buffer, 0, 0, 0, 0, 0);
    bool success = (result == 0);
    if (buffer) {
        void *code = FUN_003a04fc(buffer);
        D3D8::D3DDevice_CreatePixelShader(code, shader);
        FUN_003a41dc(buffer);
    }
    return success;
}
