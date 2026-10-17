// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001d3f00 @ 0x001d3f00
extern void __cdecl FUN_00212d80(void *, int);
struct Handler {
    char pad[4];
    int status;
    void *resource;
    int FUN_001d2810(void *, const char *, int, int);
    void FUN_001d3f00(const char *text, int value);
};
void Handler::FUN_001d3f00(const char *text, int value) {
    FUN_00212d80(resource, 0);
    const char *end = text;
    while (*end) ++end;
    if (FUN_001d2810(resource, text, (int)(end - text), value))
        status = 0;
    else
        status = 3;
}