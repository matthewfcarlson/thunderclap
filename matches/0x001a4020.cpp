extern "C" void __cdecl release(void*);
extern "C" void* __cdecl alloc(unsigned int);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
class Obj_1a4020 {
    char pad[0xfc];
    char* text;

  public:
    bool set(const char* s);
};
bool Obj_1a4020::set(const char* s) {
    release(text);
    if (!s) {
        text = 0;
        return true;
    }
    text = (char*)alloc(strlen(s) + 1);
    strcpy(text, s);
    return true;
}