extern "C" void __cdecl free_(void* p);
extern "C" void* __cdecl alloc_(int n);
extern "C" unsigned int strlen(const char*);
extern "C" char* strcpy(char*, const char*);
class StrHolder {
  public:
    int mPad;
    char* mStr;
    void Set(char* src);
};
void StrHolder::Set(char* src) {
    free_(mStr);
    if (src != 0) {
        mStr = (char*)alloc_(strlen(src) + 1);
        strcpy(mStr, src);
    }
}
