// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_000bb600 @ 0x000bb600
struct Parameters_bb600 {
    unsigned int first;
    char rest[0x2b4];
    void FUN_001d1630();
};
struct Manager_bb600 {
    void FUN_001d3b00(const char* name, Parameters_bb600 parameters);
};
extern Manager_bb600* __cdecl FUN_001d4c90();
extern unsigned int DAT_004d9968;
extern void __fastcall __security_check_cookie(unsigned int cookie);
void __cdecl FUN_000bb600() {
    unsigned int cookie = DAT_004d9968;
    Manager_bb600* manager = FUN_001d4c90();
    if (manager) {
        Parameters_bb600 parameters;
        parameters.FUN_001d1630();
        parameters.first = 0;
        manager->FUN_001d3b00("UpdateMoveList", parameters);
    }
    __security_check_cookie(cookie);
}
