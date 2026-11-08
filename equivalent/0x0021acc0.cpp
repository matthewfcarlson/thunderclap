// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// DumpHeader: the chunk header (signature, version, byte order, the 32-bit sizes, the test number).
#include "decls/data/lua.h"

extern "C" char __cdecl FUN_00220300();

// equiv-conv: FUN_0021acc0 esi
extern "C" void __cdecl FUN_0021acc0(LuaVMDumpState* D) {
    struct {
        char pad[3];
        char byte;
        float number;
    } fr;
    D->writer(D->L, "\x1b"
                    "Lua",
              4, D->data);
    fr.byte = 0x51;  // format version
    D->writer(D->L, &fr.byte, 1, D->data);
    fr.byte = FUN_00220300();  // endianness
    D->writer(D->L, &fr.byte, 1, D->data);
    fr.byte = 4;  // sizeof(int) in the chunk
    D->writer(D->L, &fr.byte, 1, D->data);
    fr.byte = 4;  // sizeof(size_t)
    D->writer(D->L, &fr.byte, 1, D->data);
    fr.byte = 4;  // sizeof(Instruction)
    D->writer(D->L, &fr.byte, 1, D->data);
    fr.byte = 4;  // sizeof(lua_Number)
    D->writer(D->L, &fr.byte, 1, D->data);
    fr.number = 31415926.0f;  // test number
    D->writer(D->L, &fr.number, 4, D->data);
}
