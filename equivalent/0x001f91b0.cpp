// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001f91b0 @ 0x001f91b0
// equiv-map: ??4Name@@QAEAAU0@ABU0@@Z = 0x0027af70
struct Name {
    char d[8];
    Name &operator=(const Name &o);
};

struct NameEx {
    Name n;
    unsigned char b8;
    unsigned char b9;
};

int __cdecl FUN_00267760(char *buf, int size, const char *fmt, ...);

class Record_1f91b0 {
public:
    char pad0[8];
    int f8;
    char label[0x20];
    char pad2c[4];
    NameEx name;
    char pad3a[6];
    int f40, f44, f48, f4c;
    unsigned char b50, b51;
    unsigned short w52;
    Record_1f91b0 *FUN_001f91b0(const Record_1f91b0 *src);
};

Record_1f91b0 *Record_1f91b0::FUN_001f91b0(const Record_1f91b0 *src)
{
    f8 = src->f8;
    FUN_00267760(label, 0x20, "%s", src->label);
    f40 = src->f40;
    f44 = src->f44;
    f48 = src->f48;
    f4c = src->f4c;
    name.n = src->name.n;
    name.b8 = src->name.b8;
    name.b9 = src->name.b9;
    b50 = src->b50;
    b51 = src->b51;
    w52 = src->w52;
    return this;
}
