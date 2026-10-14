extern "C" int strcmp(const char*, const char*);
struct Ent_90720 {
    char pad[0x38];
    int val;
    char pad2[4];
};
class C_90720 {
  public:
    void Fn(const char* s, int n);
    int Find(const char* s);
    void Other(int n);
    char pad[0];
};
void C_90720::Fn(const char* s, int n) {
    if (s && *s) {
        if (!strcmp(s, "xp")) {
            Other(n);
            return;
        }
        int i = Find(s);
        if (i != -1) {
            int* p = (int*)((char*)this + i * 0x40 + 0x38);
            n = *p + n;
            *p = n;
            if (n > 999999999)
                *p = 999999999;
        }
    }
}
