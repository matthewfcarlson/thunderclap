// FUN_0025cda0 @ 0x0025cda0
struct Stream;
struct Pair_25cda0 {
    int a, b;
};

class Header_25cda0;
bool __cdecl FUN_0025ccf0(Stream *s, Header_25cda0 *h);
bool __cdecl FUN_0025aa80(Stream *s, char *out);
bool __cdecl FUN_0025abd0(Stream *s, unsigned int *out);
bool __cdecl FUN_0025c490(Stream *s, Pair_25cda0 *out);

class Header_25cda0 {
public:
    char pad0[8];
    unsigned char enabled : 1;      // 0x8, bit 0
    char pad9[3];
    unsigned int id : 31;           // 0xc, low 31 bits
    unsigned int reserved : 1;
    Pair_25cda0 range;                     // 0x10

    bool FUN_0025cda0(Stream *s);
};

bool Header_25cda0::FUN_0025cda0(Stream *s)
{
    struct Frame {
        union {
            char bit;
            unsigned int slot;
        } enabled;
        unsigned int idBits;
    } f;
    f.enabled.bit = 0;
    f.idBits = 0;
    bool ok = FUN_0025ccf0(s, this)
        && FUN_0025aa80(s, &f.enabled.bit)
        && FUN_0025abd0(s, &f.idBits)
        && FUN_0025c490(s, &range);
    id = f.idBits;
    enabled = f.enabled.bit;
    return ok;
}
