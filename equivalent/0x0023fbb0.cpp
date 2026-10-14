// STATUS: equivalent (tools/equiv.py level 3: 3025 inputs, branch coverage 10/10)
// FUN_0023fbb0 @ 0x0023fbb0
struct StringHeader { unsigned int capacity; unsigned short references; unsigned short reserved; };
extern char* DAT_004cc02c;
extern void __cdecl FUN_00247570(StringHeader*);
void __cdecl FUN_0023fa40(int* out, char* text, int a, int b);

struct String {
    char* data;
    unsigned short kind;
    unsigned short pad6;
    unsigned short length;
    unsigned short pad10;
    char* FUN_0023fbb0();
};

// Makes the text private to this string (copy on write) and returns it.
char* String::FUN_0023fbb0()
{
    int fresh;
    if (kind == 0) {
        FUN_0023fa40(&fresh, data, length, length);
        data = (char*)fresh;
        return data;
    }
    StringHeader* header = reinterpret_cast<StringHeader*>(data) - 1;
    if (header->references > 1) {
        FUN_0023fa40(&fresh, data, length, length);
        if (kind == 2) {
            header = reinterpret_cast<StringHeader*>(data) - 1;
            if (header->references == 1) {
                if (data != DAT_004cc02c)
                    FUN_00247570(header);
            } else {
                --header->references;
            }
        }
        data = (char*)fresh;
    }
    return data;
}
