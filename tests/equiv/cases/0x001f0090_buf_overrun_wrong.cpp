extern "C" char* __cdecl strchr(const char*, int);
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
struct Name {
    unsigned int lo, hi;
    void FUN_0027af00();
    void FUN_0027b040(const char* s);
};
struct NamePath {
    Name names[8];
    int count;
    NamePath(const char* path);
};
NamePath::NamePath(const char* path) {
    struct {
        char buf[0x40];
        unsigned int cookie;
    } fr;
    fr.cookie = DAT_004d9968;
    for (int i = 0; i < 8; i++)
        names[i].FUN_0027af00();
    count = 0;
    const char* segment = path;
    const char* dot = strchr(segment, '.');
    while (dot) {
        int len = dot - segment;
        strncpy(fr.buf, segment, len);
        fr.buf[len] = 0;
        if (count < 7) {
            names[count].FUN_0027b040(fr.buf);
            count++;
        }
        segment = dot + 1;
        dot = strchr(segment, '.');
    }
    if (count < 7) {
        names[count].FUN_0027b040(segment);
        count++;
    }
    __security_check_cookie(fr.cookie);
}
