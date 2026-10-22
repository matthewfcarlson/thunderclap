// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// CInvulnerableTrack::vfunc_12 @ 0x0006aa10
void* __cdecl FUN_0008d690(unsigned int size);
struct CInvulnerableAction_6aa10 {
    CInvulnerableAction_6aa10* FUN_000200a0(void* argument, void* source);
};
struct CInvulnerableTrack {
    char pad[0x14];
    void* source;
    CInvulnerableAction_6aa10* vfunc_12(void* argument);
};
CInvulnerableAction_6aa10* CInvulnerableTrack::vfunc_12(void* argument)
{
    CInvulnerableAction_6aa10* object = (CInvulnerableAction_6aa10*)FUN_0008d690(0x24);
    if (object != 0)
        return object->FUN_000200a0(argument, source);
    return 0;
}