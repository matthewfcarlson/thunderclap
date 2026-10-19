// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 4/4)
// FUN_001c9ec0 @ 0x001c9ec0
// cl-flags: /GS
struct Properties_1c9ec0 {
    bool FUN_001d2e80();
    void FUN_001d1d50(const char* name, const char* value);
    void FUN_001d1d10();
};
extern "C" void __cdecl FUN_00096d50(char* buffer, int size, unsigned int low, unsigned int high);
struct Frame_1c9ec0 {
    char buffer[32];
};
struct Object {
    char padding[0x18];
    unsigned int idLow, idHigh;
    Properties_1c9ec0* FUN_001d4c90();
    bool target();
};
bool Object::target() {
    Frame_1c9ec0 fr;
    Properties_1c9ec0* properties = FUN_001d4c90();
    if (!properties || !properties->FUN_001d2e80()) {
        return false;
    }
    FUN_00096d50(fr.buffer, 32, idLow, idHigh);
    properties->FUN_001d1d50("civilian", fr.buffer);
    properties->FUN_001d1d10();
    return true;
}
