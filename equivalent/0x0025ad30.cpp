// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 8/8)
// FUN_0025ad30 @ 0x0025ad30
// 0x0025ad30: compare the text of a (copied) string with the string stored in b, strcmp style
extern "C" int __cdecl strcmp(const char*, const char*);

struct Str_25ad30 {
    char data[12];
    const char* FUN_0023fb00();
    Str_25ad30* FUN_0023fc40(const char* text, int flag);
    void FUN_00240060();
};

struct Record_25ad30 {
    char pad00[0x10];
    Str_25ad30 name;
};

int FUN_0025ad30(Str_25ad30* a, Record_25ad30* b)
{
    Str_25ad30 copy;
    Str_25ad30* t = copy.FUN_0023fc40(a->FUN_0023fb00(), 0);
    const char* other = b->name.FUN_0023fb00();
    int result = strcmp(t->FUN_0023fb00(), other);
    copy.FUN_00240060();
    return result;
}
