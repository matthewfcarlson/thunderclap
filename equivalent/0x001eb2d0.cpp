// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 11/12, incomplete)
// FUN_001eb2d0 @ 0x001eb2d0
// cl-flags: /GS
extern "C" char* strncat(char* dst, const char* src, unsigned int n);
extern "C" char* strcat(char* dst, const char* src);
extern "C" long atol(const char* s);

struct ScriptLoader {
    void FUN_001eef90(const char* path);
};

// Builds "sound\scripts\<xxx><yyy>.lua" from two 3-character fields of name.
void FUN_001eb2d0(const char* name, ScriptLoader* loader)
{
    struct {
        char field1[4];
        char path[0x20];
    } f;
    char field2[4];
    f.field1[0] = 0;
    f.field1[1] = 0;
    f.field1[2] = 0;
    f.field1[3] = 0;
    strncat(f.field1, name, 3);
    atol(f.field1 + 1);
    field2[0] = 0;
    field2[1] = 0;
    field2[2] = 0;
    field2[3] = 0;
    strncat(field2, name + 3, 3);
    atol(field2 + 1);
    for (int i = 0; i < 0x20; i++)
        f.path[i] = 0;
    strcat(f.path, "sound\\scripts\\");
    strcat(f.path, f.field1);
    strcat(f.path, field2);
    strcat(f.path, ".lua");
    loader->FUN_001eef90(f.path);
}
