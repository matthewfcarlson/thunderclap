class Obj_261ef0;
extern "C" bool __cdecl FUN_0025abd0(const char*, unsigned int*);
extern "C" bool __cdecl FUN_0025ac10(const char*, unsigned int*);
extern "C" void* __cdecl FUN_00247530(void*);
extern int gBss_261ef0;
class Obj_261ef0 {
  public:
    int* mHead;
    int* mTail;
    bool Fn(const char*);
};
bool Obj_261ef0::Fn(const char* name) {
    unsigned int count;
    if (!FUN_0025abd0(name, &count))
        return false;
    for (unsigned int i = 0; i < count; ++i) {
        unsigned int value;
        if (!FUN_0025ac10(name, &value))
            return false;
        int* p = (int*)FUN_00247530(&gBss_261ef0);
        if (p)
            *p = value;
        else
            p = 0;
        ++p;
        *p = 0;
        if (!mTail)
            mHead = p;
        else
            *mTail = (int)p;
        mTail = p;
    }
    return true;
}