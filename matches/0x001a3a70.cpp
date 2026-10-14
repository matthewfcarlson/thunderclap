extern "C" void __cdecl release(void*);
extern "C" char* __cdecl allocate(unsigned int);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
class Obj_1a3a70 {
    char pad[0x90];
    char* text;

  public:
    char Set(const char* s);
};
char Obj_1a3a70::Set(const char* s) {
    release(text);
    if (!s) {
        text = 0;
        return 1;
    }
    text = allocate(strlen(s) + 1);
    strcpy(text, s);
    return 1;
}