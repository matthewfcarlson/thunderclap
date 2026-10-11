// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 9/10, incomplete)
// FUN_0023fe50 @ 0x0023fe50
struct StringHeader { unsigned int capacity; unsigned short references; unsigned short reserved; };
extern char* DAT_004cc02c;
extern void __cdecl FUN_00247570(StringHeader*);
extern void __cdecl FUN_0023fa40(const char**, const char*, unsigned int, unsigned int);
struct String { char* data; unsigned short kind; unsigned short reserved; unsigned short length; String* assign(const char* source); };
String* String::assign(const char* source) {
    if (kind == 2) {
        StringHeader* header = reinterpret_cast<StringHeader*>(data) - 1;
        if (header->references == 1) {
            if (data != DAT_004cc02c) FUN_00247570(header);
        } else {
            --header->references;
        }
    }
    if (source) {
        unsigned int count = 0;
        while (source[count]) ++count;
        length = (unsigned short)count;
        kind = 2;
        FUN_0023fa40(&source, source, count, count);
        data = const_cast<char*>(source);
    } else {
        data = DAT_004cc02c;
        ++(reinterpret_cast<StringHeader*>(DAT_004cc02c) - 1)->references;
        length = 0;
        kind = 2;
    }
    return this;
}
