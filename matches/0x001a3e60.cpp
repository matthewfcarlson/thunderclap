extern "C" void thunk_FUN_00267090(void*);
extern "C" void* malloc(unsigned int);
extern "C" unsigned int strlen(const char*);
extern "C" char* strcpy(char*, const char*);
class Obj_1a3e60 {
    char pad[0xdc];
    char* str;

  public:
    char Set(char* s);
};
char Obj_1a3e60::Set(char* s) {
    thunk_FUN_00267090(str);
    if (!s) {
        str = s;
        return 1;
    }
    str = (char*)malloc(strlen(s) + 1);
    strcpy(str, s);
    return 1;
}