#include "decls/data/game/global.h"
#include "decls/data/platform/xbox/pure3d.h"

extern "C" int __cdecl FUN_00356734(char*, const char*, ...);
namespace XAPILIB {
void __stdcall OutputDebugStringA(const char*);
}
void __cdecl FUN_0031c230(int code) {
    char buffer[512];
    if (code != 0) {
        FUN_00356734(buffer, DAT_0043259c, code & 0xffff, (code >> 16) & 0x1fff, (code >> 31) & 1);
        XAPILIB::OutputDebugStringA(buffer);
        XAPILIB::OutputDebugStringA(DAT_00422518);
    }
}