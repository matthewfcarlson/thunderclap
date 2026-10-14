// STATUS: equivalent (tools/equiv.py level 3: 3013 inputs, branch coverage 6/6)
// FUN_002406a0 @ 0x002406a0
extern const char* DAT_004cc02c;
void __cdecl FUN_00247570(void* p);
struct Str {
    char* p;
    unsigned short kind;
    char pad6[6];
    void FUN_00240090(const Str* other);
    void FUN_0023ff50(const void* rhs);
    Str* FUN_002406a0(Str* ret, const void* rhs);
};
Str* Str::FUN_002406a0(Str* ret, const void* rhs) {
    Str tmp;
    tmp.FUN_00240090(this);
    tmp.FUN_0023ff50(rhs);
    ret->FUN_00240090(&tmp);
    if (tmp.kind == 2) {
        char* data = tmp.p;
        if (*(unsigned short*)(data - 4) == 1) {
            if (data != DAT_004cc02c)
                FUN_00247570(data - 8);
        } else {
            (*(unsigned short*)(data - 4))--;
        }
    }
    return ret;
}
