// STATUS: equivalent (tools/equiv.py level 3: 100 inputs, branch coverage 25/28, incomplete)
// FUN_00337700 @ 0x00337700
extern "C" long atol(const char *s);
void *__cdecl FUN_0008d690(unsigned int size);

class AttrDef_337700 {
public:
    bool FUN_00337210(void *loader);
};

class XmlReader {
public:
    virtual ~XmlReader();
    XmlReader *FUN_003388d0(void *src, int bufSize);
    bool FUN_003385f0(void *arg);
    void FUN_00338630();
};

class XmlLoader {
public:
    char pad0[0x5108];
    int status;
    XmlReader *reader;
    const char *FUN_00337460();
    void FUN_003374a0();
    AttrDef_337700 *FUN_00337680(const char *name);
    bool Load(void *src, void *arg);
};

static bool Match(const char *a, const char *b, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

bool XmlLoader::Load(void *src, void *arg) {
    if (reader != 0) delete reader;
    void *mem = FUN_0008d690(0x874);
    XmlReader *r = 0;
    if (mem != 0) r = ((XmlReader *)mem)->FUN_003388d0(src, 0x2000);
    reader = r;
    status = 0;
    if (!r->FUN_003385f0(arg)) {
        status = 9;
    } else {
        AttrDef_337700 *def = 0;
        const char *tok = FUN_00337460();
        if (tok == 0) {
            reader->FUN_00338630();
        } else {
            for (;;) {
                if (Match(tok, "version", 8)) {
                    FUN_003374a0();
                    const char *s = FUN_00337460();
                    if (s == 0) break;
                    atol(s);
                    FUN_003374a0();
                } else if (tok[0] == '[' && tok[1] == 0) {
                    FUN_003374a0();
                    const char *s = FUN_00337460();
                    if (s == 0) break;
                    def = FUN_00337680(s);
                    if (def == 0) break;
                    FUN_003374a0();
                    FUN_003374a0();
                } else if (Match(tok, "attrDef", 8)) {
                    if (!def->FUN_00337210(this)) break;
                } else {
                    status = 4;
                    break;
                }
                tok = FUN_00337460();
                if (tok == 0) {
                    reader->FUN_00338630();
                    goto done;
                }
            }
            reader->FUN_00338630();
        }
    }
done:
    return status == 0 || status == 1;
}
