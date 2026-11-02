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

extern "C" void FUN_0021acc0(void *D)
{
    struct Frame {
        char pad[3];
        char byte;
        float number;
    } fr;
    ((DumpState *)D)->write(((DumpState *)D)->L, "\x1b" "Lua", 4, ((DumpState *)D)->ud);
    fr.byte = 0x51;                 // format version
    ((DumpState *)D)->write(((DumpState *)D)->L, &fr.byte, 1, ((DumpState *)D)->ud);
    fr.byte = FUN_00220300();       // endianness
    ((DumpState *)D)->write(((DumpState *)D)->L, &fr.byte, 1, ((DumpState *)D)->ud);
    fr.byte = 4;                    // sizeof(int)
    ((DumpState *)D)->write(((DumpState *)D)->L, &fr.byte, 1, ((DumpState *)D)->ud);
    fr.byte = 4;                    // sizeof(size_t)
    ((DumpState *)D)->write(((DumpState *)D)->L, &fr.byte, 1, ((DumpState *)D)->ud);
    fr.byte = 4;                    // sizeof(Instruction)
    ((DumpState *)D)->write(((DumpState *)D)->L, &fr.byte, 1, ((DumpState *)D)->ud);
    fr.byte = 4;                    // sizeof(lua_Number)
    ((DumpState *)D)->write(((DumpState *)D)->L, &fr.byte, 1, ((DumpState *)D)->ud);
    fr.number = 31415926.0f;        // test number
    ((DumpState *)D)->write(((DumpState *)D)->L, &fr.number, 4, ((DumpState *)D)->ud);
}
