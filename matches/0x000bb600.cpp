// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000bb600 @ 0x000bb600
// cl-flags: /GS
struct Parameters_bb600 {
    unsigned int first;
    char rest[0x2b4];
    void FUN_001d1630();
};
struct Manager_bb600 {
    void FUN_001d3b00(const char* name, Parameters_bb600 parameters);
};
extern Manager_bb600* __cdecl FUN_001d4c90();
void __cdecl FUN_000bb600() {
    Manager_bb600* manager = FUN_001d4c90();
    if (manager) {
        Parameters_bb600 parameters;
        parameters.FUN_001d1630();
        parameters.first = 0;
        manager->FUN_001d3b00("UpdateMoveList", parameters);
    }
}
