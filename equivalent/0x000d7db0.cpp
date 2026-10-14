// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000d7db0 @ 0x000d7db0
// equiv-map: ??1FEControl@@UAE@XZ = 0x000e92b0
// equiv-map: ??1StringPair@@QAE@XZ = 0x000f7960
class RefCounted_d7db0 {
public:
    virtual void v0() throw();
    virtual void Release() throw();
};

struct StringPair {
    char data[0x14];
    ~StringPair() throw();
};

// Five 0x3c-byte cells, each starting with a StringPair, destroyed last-to-first.
struct CellRow {
    char cell[5][0x3c];
    ~CellRow() throw() {
        for (int i = 4; i >= 0; i--)
            ((StringPair *)cell[i])->~StringPair();
    }
};

class FEControl {
public:
    virtual ~FEControl() throw();
    char pad04[0x1cc - 4];
};

class FEMemCardControl : public FEControl {
public:
    virtual ~FEMemCardControl() throw();
    RefCounted_d7db0 *handle;
    char pad1d0[0x220 - 0x1d0];
    CellRow cells;
    char pad34c[0x35c - 0x34c];
    StringPair title;
    char pad370[0x384 - 0x35c - sizeof(StringPair)];
    StringPair subtitle;
    char pad398[0x3f4 - 0x384 - sizeof(StringPair)];
    StringPair footer;
};

FEMemCardControl::~FEMemCardControl() throw()
{
    if (handle != 0) {
        handle->Release();
        handle = 0;
    }
}
