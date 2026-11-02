typedef unsigned int U32_90050;
typedef unsigned long long U64_90050;
extern "C" U64_90050 __cdecl FUN_0027b020(char*);
class Table_90050 {
  public:
    int Find(char* s);
    unsigned int mLow;
    unsigned int mHigh;
};
int Table_90050::Find(char* s) {
    if (s == 0 || *s == 0)
        return -1;
    U64_90050 key = FUN_0027b020(s);
    int i = 0;
    Table_90050* p = this;
    while (i < 50) {
        if (key == *(U64_90050*)p)
            return i;
        ++i;
        p = (Table_90050*)((char*)p + 0x40);
    }
    return -1;
}