// STATUS: equivalent (tools/equiv.py level 3: 2758 inputs, branch coverage 2/2)
// FUN_0025ce40 @ 0x0025ce40
struct FileState { char padding[0x24]; int count; };
extern "C" unsigned char __cdecl FUN_00246f50(FileState *, const char *, ...);
unsigned char __stdcall FUN_0025ce40(FileState **state)
{
    if (FUN_00246f50(*state, "\n[\n")) {
        ++(*state)->count;
        FUN_00246f50(*state, "%s ", "mFileName");
    }
    return 0;
}
