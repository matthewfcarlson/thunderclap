// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001c9df0 @ 0x001c9df0
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int cookie);
struct Properties {
    bool FUN_001d2e80();
    void FUN_001d1d50(const char* name, const char* value);
    void FUN_001d1d10();
};
extern "C" void __cdecl FUN_00096d50(char* buffer, int size, unsigned int low, unsigned int high);
struct Frame {
    char buffer[32];
    unsigned int cookie;
};
struct Object {
    char padding[0x18];
    unsigned int idLow, idHigh;
    Properties* FUN_001d4c90();
    bool target();
};
bool Object::target() {
    Frame fr;
    fr.cookie = DAT_004d9968;
    Properties* properties = FUN_001d4c90();
    if (!properties || !properties->FUN_001d2e80()) {
        __security_check_cookie(fr.cookie);
        return false;
    }
    FUN_00096d50(fr.buffer, 32, idLow, idHigh);
    properties->FUN_001d1d50("civilian", fr.buffer);
    properties->FUN_001d1d10();
    __security_check_cookie(fr.cookie);
    return true;
}
