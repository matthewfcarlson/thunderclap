void __cdecl Free(void*);
void* __cdecl Alloc(unsigned int);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
class Obj_1a3fb0 {
    char pad[0xf0];
    char* text;

  public:
    char Set(char* s);
};
char Obj_1a3fb0::Set(char* s) {
    Free(text);
    if (!s) {
        text = 0;
        return 1;
    }
    text = (char*)Alloc(strlen(s) + 1);
    strcpy(text, s);
    return 1;
}