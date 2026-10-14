// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 16/18, incomplete)
// FUN_002c2370 @ 0x002c2370
struct Stream {
    char FUN_002647e0(void* dest, int a, int b, int c);
};

struct Reader {
    char pad0[0x284];
    Stream* stream;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

struct Name_2c2370 {
    void FUN_0027b040(const char* s);
};

struct Created_2c2370 {
    char pad0[8];
    Name_2c2370 name;
};

struct Target_2c2370 {
    char pad0[0x8c];
    int f8c;
    char pad90[4];
    void FUN_002ae950(int a, int b, int c, int d);
};

class Loader_2c2370 {
  public:
    char pad0[0x14];
    Target_2c2370* target;
    Created_2c2370* FUN_002c1f80(Reader* rd, Target_2c2370* t, Created_2c2370* prev, int index, int count);
    Created_2c2370* FUN_002c1d70(Reader* rd, Target_2c2370* t, Created_2c2370* prev, int index);
    Created_2c2370* FUN_002c2370(Reader* rd);
};

Created_2c2370* Loader_2c2370::FUN_002c2370(Reader* rd)
{
    struct Frame {
        char pad10[2];
        unsigned char len;
        unsigned char flagB;
        int count;
        int va;
        int ve;
        int vb;
        int vd;
        int vf;
        char name[0x80];
    } fr;
    unsigned char flagA;

    rd->stream->FUN_002647e0(&fr.len, 1, 1, 1);
    int len = fr.len;
    rd->stream->FUN_002647e0(fr.name, len, 1, 1);
    fr.name[len] = 0;
    rd->stream->FUN_002647e0(&fr.va, 1, 4, 1);
    rd->stream->FUN_002647e0(&fr.va, 1, 4, 1);
    rd->stream->FUN_002647e0(&fr.va, 1, 4, 1);
    rd->stream->FUN_002647e0(&fr.vb, 1, 4, 1);
    rd->stream->FUN_002647e0(&fr.va, 1, 4, 1);
    rd->stream->FUN_002647e0(&fr.count, 1, 4, 1);
    if (fr.count != 0)
        fr.count--;
    rd->stream->FUN_002647e0(&fr.vd, 1, 4, 1);
    rd->stream->FUN_002647e0(&fr.ve, 1, 4, 1);
    rd->stream->FUN_002647e0(&fr.vf, 1, 4, 1);

    target->f8c = fr.vb;
    target->FUN_002ae950(fr.va, fr.count, fr.vd, fr.ve);

    Created_2c2370* made = 0;
    int index = 0;
    fr.flagB = 0;
    flagA = 0;
    // flagA lives in the len byte of the frame in the original
    while (rd->FUN_002669f0()) {
        if (index > fr.count)
            break;
        int id = rd->FUN_00266a30();
        if (id == 0x19001) {
            if (!fr.flagB) {
                made = FUN_002c1d70(rd, target, made, index);
                fr.flagB = 0;
                flagA = 1;
                index++;
            }
        } else if (id == 0x19004) {
            if (!flagA) {
                made = FUN_002c1f80(rd, target, made, index, fr.count);
                fr.flagB = 1;
                flagA = 0;
                index++;
            }
        }
        rd->FUN_00266be0();
    }
    if (made)
        made->name.FUN_0027b040(fr.name);
    return made;
}
