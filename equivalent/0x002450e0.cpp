// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 21/22, incomplete)
// FUN_002450e0 @ 0x002450e0
struct Reader;

// C-style interface: the first word of the stream's first word points at a table of functions.
struct IoTable {
    void *slot0;
    void *slot1;
    void *slot2;
    void *slot3;
    char (*read)(IoTable *self, unsigned *out);       // 0x10
    char (*seek)(IoTable *self, unsigned pos);         // 0x14
};
struct IoHandle {
    IoTable *table;
};
struct Stream {
    IoHandle *handle;
};

struct Pair {
    unsigned a;
    unsigned b;
};
struct Header {
    unsigned key;
    unsigned unused;
    unsigned size;
};

class Resource {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual char Load(Stream *s);
    char FUN_00245040(Pair *p);
};
class Entry {
public:
    virtual void v0();
    virtual void v1();
    virtual Resource *Get();
    char pad4[0x2c];
    char data30[1];                                    // 0x30
};
struct Registry;

extern Registry *DAT_004cc088;
char __cdecl FUN_002433b0(Stream *s, Header *h);
char __cdecl FUN_00244d10(Stream *s, Pair *p);
Entry *__cdecl FUN_00244870(Registry *r, unsigned *key);
Resource *__cdecl FUN_00244fa0(Pair *p, char *src);

struct Source {
    Stream *stream;          // 0x00
    unsigned remaining;      // 0x04

    char FUN_002450e0(Resource **out);
};

// The original keeps all its locals in one 0x18-byte frame and reuses the dead argument slot.
struct Frame {
    unsigned base;           // E+0x0c
    Pair pair;               // E+0x10
    Header hdr;              // E+0x18
};

char Source::FUN_002450e0(Resource **out)
{
    Frame f;
    *out = 0;
    if (remaining == 0)
        return 1;

    f.base = 0;
    if (!stream->handle->table->read(stream->handle->table, &f.base))
        return 0;

    if (!FUN_002433b0(stream, &f.hdr))
        return 0;

    f.pair.a = 0;
    f.pair.b = 0;
    if (!FUN_00244d10(stream, &f.pair))
        return 0;

    f.hdr.unused = f.hdr.key;
    Entry *entry = FUN_00244870(DAT_004cc088, &f.hdr.unused);
    if (entry == 0)
        return 0;

    *out = entry->Get();
    (*out)->AddRef();

    char ok = (*out)->Load(stream);
    if (ok) {
        if (!(*out)->FUN_00245040(&f.pair)) {
            (*out)->Release();
            *out = FUN_00244fa0(&f.pair, entry->data30);
            (*out)->AddRef();
        }
        f.hdr.unused = 0;
        ok = stream->handle->table->read(stream->handle->table, &f.hdr.unused);
        if (ok) {
            unsigned room = f.hdr.unused - f.base;
            unsigned size = f.hdr.size;
            ok = size >= room;
            if (ok) {
                unsigned pos = size + f.base;
                ok = stream->handle->table->seek(stream->handle->table, pos);
                if (ok) {
                    remaining -= f.hdr.size;
                    return ok;
                }
            }
        }
    }
    if (*out) {
        (*out)->Release();
        *out = 0;
    }
    return ok;
}
