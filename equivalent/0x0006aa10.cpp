// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// CInvulnerableTrack::vfunc_12 @ 0x0006aa10
void* __cdecl FUN_0008d690(unsigned int size);
struct InvulnerableObject {
    InvulnerableObject* FUN_000200a0(void* argument, void* source);
};
struct CInvulnerableTrack {
    char pad[0x14];
    void* source;
    InvulnerableObject* vfunc_12(void* argument);
};
InvulnerableObject* CInvulnerableTrack::vfunc_12(void* argument)
{
    InvulnerableObject* object = (InvulnerableObject*)FUN_0008d690(0x24);
    if (object != 0)
        return object->FUN_000200a0(argument, source);
    return 0;
}