struct Entry_89f00 {
    __int64 id;
    char name[16];
};
extern "C" __int64 F27b020(int s);
extern "C" int F267760(char* buf, int n, const char* fmt, int a);
class T_89f00 {
  public:
    char pad[0x158];
    Entry_89f00 mE[100];
    int Find(int k);
    void Set(int k, int s);
};
void T_89f00::Set(int k, int s) {
    int i = Find(k);
    if (i == -1) {
        i = 0;
        Entry_89f00* e = mE;
        do {
            if (e->id == 0)
                goto found;
            i++;
            e++;
        } while (i < 100);
        return;
    found:
        if (i == -1)
            return;
    }
    char* b = (char*)this + i * 0x18;
    *(__int64*)(b + 0x158) = F27b020(k);
    F267760(b + 0x160, 0x10, "%s", s);
}
