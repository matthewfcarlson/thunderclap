// STATUS: equivalent (tools/equiv.py level 3: 3013 inputs, branch coverage 6/6)
// FUN_002405c0 @ 0x002405c0
struct StringHeader { unsigned int capacity; unsigned short references; unsigned short reserved; };
extern char* DAT_004cc02c;
extern void __cdecl FUN_00247570(StringHeader*);
struct String {
    char* data; unsigned short kind; unsigned short pad6; unsigned short length; unsigned short pad10;
    void FUN_00240090(const String* src);
    void FUN_00240430(float value);
    String* Concat(String* out, float value);
};
String* String::Concat(String* out, float value) {
    String tmp;
    tmp.FUN_00240090(this);
    tmp.FUN_00240430(value);
    out->FUN_00240090(&tmp);
    if (tmp.kind == 2) {
        StringHeader* header = reinterpret_cast<StringHeader*>(tmp.data) - 1;
        if (header->references == 1) {
            if (tmp.data != DAT_004cc02c) FUN_00247570(header);
        } else {
            --header->references;
        }
    }
    return out;
}
