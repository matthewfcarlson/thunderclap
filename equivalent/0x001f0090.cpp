// STATUS: equivalent (tools/equiv.py level 3: 2893 inputs, branch coverage 10/10)
// FUN_001f0090 @ 0x001f0090
// cl-flags: /GS
extern "C" char* __cdecl strchr(const char*, int);
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
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
    } fr;
    for (int i = 0; i < 8; i++)
        names[i].FUN_0027af00();
    count = 0;
    const char* segment = path;
    const char* dot = strchr(segment, '.');
    while (dot) {
        int len = dot - segment;
        strncpy(fr.buf, segment, len);
        fr.buf[len] = 0;
        if (count < 8) {
            names[count].FUN_0027b040(fr.buf);
            count++;
        }
        segment = dot + 1;
        dot = strchr(segment, '.');
    }
    if (count < 8) {
        names[count].FUN_0027b040(segment);
        count++;
    }
}
