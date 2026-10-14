extern void __stdcall Notify(int);
inline void Copy(char* d, const char* s) {
    char c;
    do {
        c = *s;
        ++s;
        *d = c;
        ++d;
    } while (c);
}
class Obj_e3890 {
  public:
    virtual void Fn();
    char pad4[0x14c];
    int m150;
    int m154;
    char pad158[0x1d58 - 0x158];
    int count;
    char pad1d5c[0x38];
    int callback;
    char pad1d98[0x11];
    char entries[0x2000];
    void Target(const char*, char);
};
void Obj_e3890::Target(const char* s, char flag) {
    if (count < 0x80) {
        Copy(entries + count * 0x40, s);
        if (flag) {
            int n = count;
            m154 = n;
            m150 = n;
            if (callback)
                Notify(n);
            Fn();
        }
        ++count;
    }
}
