extern "C" int __cdecl Format(char *, const char *, ...);
namespace XAPILIB { void __stdcall OutputDebugStringA(const char *); }
extern const char fmt[];
extern const char nl[];
void __cdecl FUN_0031c230(int code)
{
    char buffer[512];
    if (code != 0) {
        Format(buffer, fmt, code & 0xffff, (code >> 16) & 0x1fff, (code >> 31) & 1);
        XAPILIB::OutputDebugStringA(buffer);
        XAPILIB::OutputDebugStringA(nl);
    }
}