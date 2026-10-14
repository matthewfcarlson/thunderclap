// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 16/16)
// FUN_002401f0 @ 0x002401f0
struct StringHeader_2401f0 { unsigned int capacity; unsigned short references; unsigned short reserved; };
extern char* DAT_004cc02c;
extern void __cdecl FUN_00247570(StringHeader_2401f0*);
struct String {
    char* data; unsigned short kind; unsigned short pad6; unsigned short length; unsigned short pad10;
    void FUN_00240090(const String* src);
    char* FUN_0023fbb0();
    String* ToLower(String* out);
};
String* String::ToLower(String* out) {
    String tmp;
    tmp.FUN_00240090(this);
    char* p = tmp.FUN_0023fbb0();
    if (p) {
        while (*p) {
            if (*p >= 'A' && *p <= 'Z') *p += 0x20;
            ++p;
        }
    }
    out->FUN_00240090(&tmp);
    if (tmp.kind == 2) {
        StringHeader_2401f0* header = reinterpret_cast<StringHeader_2401f0*>(tmp.data) - 1;
        if (header->references == 1) {
            if (tmp.data != DAT_004cc02c) FUN_00247570(header);
        } else {
            --header->references;
        }
    }
    return out;
}
