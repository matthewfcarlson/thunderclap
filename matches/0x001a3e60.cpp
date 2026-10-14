extern "C" void free(void*);
extern "C" void* malloc(unsigned int);
extern "C" unsigned int strlen(const char*);
extern "C" char* strcpy(char*, const char*);
class Obj {
    char pad[0xdc];
    char* str;

  public:
    char Set(char* s);
};
char Obj::Set(char* s) {
    free(str);
    if (!s) {
        str = s;
        return 1;
    }
    str = (char*)malloc(strlen(s) + 1);
    strcpy(str, s);
    return 1;
}