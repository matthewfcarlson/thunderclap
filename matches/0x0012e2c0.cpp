typedef unsigned int size_t;
extern "C" void free(void*);
extern "C" void* malloc(size_t);
extern "C" size_t strlen(const char*);
extern "C" char* strcpy(char*, const char*);
class X {
    char pad[12];
    char* str;

  public:
    bool Set(const char* s);
};
bool X::Set(const char* s) {
    free(str);
    if (!s) {
        str = 0;
        return true;
    }
    str = (char*)malloc(strlen(s) + 1);
    strcpy(str, s);
    return true;
}