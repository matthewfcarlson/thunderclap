// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001eb440 @ 0x001eb440
extern "C" char* strncat(char* dst, const char* src, unsigned int n);
extern "C" long atol(const char* s);

struct StringList_1eb440 {
    char data[0x48];
    void FUN_001ef370(const char *s);
};

struct NameSource_1eb440 {
    const char *FUN_0008a2d0();
};

void FUN_001eb440(NameSource_1eb440 *source, StringList_1eb440 *list)
{
    const char *name = source->FUN_0008a2d0();
    char field1[4];
    char field2[4];
    field1[0] = 0;
    field1[1] = 0;
    field1[2] = 0;
    field1[3] = 0;
    strncat(field1, name, 3);
    atol(field1 + 1);
    field2[0] = 0;
    field2[1] = 0;
    field2[2] = 0;
    field2[3] = 0;
    strncat(field2, name + 3, 3);
    atol(field2 + 1);
    list->FUN_001ef370(field1);
    list->FUN_001ef370(field2);
}
