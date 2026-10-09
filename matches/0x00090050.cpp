typedef unsigned int U32;
typedef unsigned long long U64;
extern U64 __cdecl MakeKey(char *);
class Table {
public:
    int Find(char *s);
    unsigned int mLow;
    unsigned int mHigh;
};
int Table::Find(char *s)
{
    if (s == 0 || *s == 0)
        return -1;
    U64 key = MakeKey(s);
    int i = 0;
    Table *p = this;
    while (i < 50) {
        if (key == *(U64 *)p)
            return i;
        ++i;
        p = (Table *)((char *)p + 0x40);
    }
    return -1;
}