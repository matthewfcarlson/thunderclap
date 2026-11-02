extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" unsigned int FUN_00267f00();
struct Buffer {
    char pad[0x2004];
    char* cursor;
};
extern "C" char* __cdecl FUN_00260a90(Buffer* b) {
    unsigned int n = FUN_00267f00();
    char* s = b->cursor;
    sprintf(s, "%u", n);
    b->cursor += strlen(s) + 1;
    return s;
}