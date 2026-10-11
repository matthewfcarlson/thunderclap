// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// FUN_00204880 @ 0x00204880
struct Stream {
    void FUN_002647e0(void *dest, int a, int b, int c);
};

struct Entry {
    char data[0x56];
    void FUN_00208ac0(unsigned int a, unsigned int b);
    void FUN_00208b40(unsigned int v);
    void FUN_00208b60(unsigned int v);
};

struct Table {
    char pad0[0x58c];
    Entry *entries;
    char pad590[4];
    int count;
    Entry *FUN_00204060(unsigned int a, unsigned int b);
};

struct Reader {
    char pad0[0x284];
    Stream *stream;
    char FUN_002669f0();
    void FUN_00266a30();
    int FUN_00266c30();
    void FUN_00266be0();
};

union Slot {
    Reader *reader;
    unsigned int value;
};

class Loader {
public:
    char pad0[0x14];
    Table *table;
    void FUN_00204880(Slot arg, int unused);
};

void Loader::FUN_00204880(Slot arg, int unused)
{
    Reader *rd = arg.reader;
    struct Frame {
        unsigned int second;
        unsigned int junk;
    } fr;

    rd->stream->FUN_002647e0(&arg.value, 1, 4, 1);
    rd->stream->FUN_002647e0(&fr.second, 1, 4, 1);
    rd->stream->FUN_002647e0(&fr.junk, 1, 4, 1);
    rd->stream->FUN_002647e0(&fr.junk, 1, 4, 1);

    unsigned int second = fr.second;
    Table *t = table;
    Entry *e = t->FUN_00204060(arg.value, second);
    if (e == 0) {
        t->entries[t->count].FUN_00208ac0(arg.value, second);
        e = t->entries + t->count;
        t->count++;
    }
    while (rd->FUN_002669f0()) {
        rd->FUN_00266a30();
        if (rd->FUN_00266c30() == 0x60000724) {
            rd->stream->FUN_002647e0(&arg.value, 1, 4, 1);
            e->FUN_00208b40(arg.value);
        } else if (rd->FUN_00266c30() == 0x60000725) {
            rd->stream->FUN_002647e0(&fr.second, 1, 4, 1);
            e->FUN_00208b60(fr.second);
        }
        rd->FUN_00266be0();
    }
}
