extern "C" bool Check(const char*, const char*, int);
extern "C" bool CheckByte(void*, unsigned char);
extern "C" bool EndCheck(const char*, const char*);

struct Obj { const char* mName; };

extern "C" bool FUN_00250ef0(Obj* p, int arg, unsigned char* ch) {
    int a = arg;
    const char* s = p->mName;
    if (Check(s, (const char*)0x4298a8, a)) {
        if (CheckByte(p, *ch)) {
            p = (Obj*)p->mName;
            return EndCheck((const char*)p, (const char*)0x422518);
        }
    }
    return false;
}
