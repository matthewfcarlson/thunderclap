// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0021acc0 @ 0x0021acc0
// Lua 5.1 bytecode header dump through a writer callback (DumpState arrives in esi).
// equiv-conv: FUN_0021acc0 esi
struct DumpState {
    void *L;
    int (__cdecl *write)(void *L, const void *data, int size, void *ud);
    void *ud;
};

extern "C" char __cdecl FUN_00220300();

void FUN_0021acc0(DumpState *D)
{
    struct Frame {
        char pad[3];
        char byte;
        float number;
    } fr;
    D->write(D->L, "\x1b" "Lua", 4, D->ud);
    fr.byte = 0x51;                 // format version
    D->write(D->L, &fr.byte, 1, D->ud);
    fr.byte = FUN_00220300();       // endianness
    D->write(D->L, &fr.byte, 1, D->ud);
    fr.byte = 4;                    // sizeof(int)
    D->write(D->L, &fr.byte, 1, D->ud);
    fr.byte = 4;                    // sizeof(size_t)
    D->write(D->L, &fr.byte, 1, D->ud);
    fr.byte = 4;                    // sizeof(Instruction)
    D->write(D->L, &fr.byte, 1, D->ud);
    fr.byte = 4;                    // sizeof(lua_Number)
    D->write(D->L, &fr.byte, 1, D->ud);
    fr.number = 31415926.0f;        // test number
    D->write(D->L, &fr.number, 8, D->ud);
}
