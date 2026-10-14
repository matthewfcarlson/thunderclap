// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_001efa40 @ 0x001efa40
extern "C" int sprintf(char *buf, const char *fmt, ...);
extern "C" unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
void *__cdecl FUN_0008d710(unsigned int size, int tag);

struct StrTable {
    void FUN_0027af00();
    void FUN_0027b040(const char *name);
};

struct Pool_1efa40 {
    int a, b, c, d;
    StrTable table;
};

struct Slot_1efa40 {
    char pad0[8];
    int f8;
    int fc;
    int f10;
    char f14;
    char pad15[3];
    StrTable name;
    char padName[7];
    float f20;
    int f24;
};

struct Loader_1efa40 {
    void FUN_001d3600(const char *path, int flag);
};
Loader_1efa40 *FUN_001d4c90();

struct Registry_1efa40 {
    void FUN_001f4c50();
};

class SoundObjects {
public:
    Registry_1efa40 *registry;
    char pad4[4];
    Pool_1efa40 *pool;
    Slot_1efa40 *slots;
    void FUN_001efa40(char load, int id1, int id2);
};

void SoundObjects::FUN_001efa40(char load, int id1, int id2)
{
    unsigned int cookie = DAT_004d9968;
    if (load) {
        Pool_1efa40 *p = (Pool_1efa40 *)FUN_0008d710(0x18, 6);
        if (p) {
            p->a = 0;
            p->b = 0;
            p->c = 0;
            p->d = 0;
            p->table.FUN_0027af00();
        }
        pool = p;
        p->table.FUN_0027b040("Objects");

        char path1[64] = {0};
        sprintf(path1, "sound\\scripts\\%s.obj", id2);
        FUN_001d4c90()->FUN_001d3600(path1, 0);

        char path2[64] = {0};
        sprintf(path2, "sound\\scripts\\%s.obj", id1);
        FUN_001d4c90()->FUN_001d3600(path2, 0);
    }
    registry->FUN_001f4c50();
    for (int off = 0; off < 0xfa0; off += 0x28) {
        Slot_1efa40 *s = (Slot_1efa40 *)((char *)slots + off);
        s->f8 = 0;
        s->fc = 0;
        s->f10 = 0;
        s->f14 = 0;
        s->f20 = 100.0f;
        s->f24 = 0;
        s->name.FUN_0027b040(0);
    }
    __security_check_cookie(cookie);
}
