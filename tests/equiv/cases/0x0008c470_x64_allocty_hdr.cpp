// FUN_0008c470 @ 0x0008c470
// (integ3, allocty, rev5 R2') a header and its payload, `(Hdr*)Alloc(sizeof(Hdr) + len)` with a fuzzed len (multiples of
// sizeof(Hdr) included): only the header is typed, the payload stays raw and the same byte for byte, so a payload byte
// read before it is written is equal on both sides and no 64-bit allocation stop fires
struct Hdr { Hdr* next; void* data; unsigned len; };
extern "C" void* __cdecl FUN_0008d6d0(unsigned);
extern void __cdecl InitHdr(Hdr*);
extern void __cdecl Use(Hdr*, unsigned char);
struct Owner { const void* vftable; unsigned len; void FUN_0008c470(unsigned); };
void Owner::FUN_0008c470(unsigned n) {
    len = (n & 7) * 12;     // (multiples of the 32-bit sizeof(Hdr) included)
    Hdr* h = (Hdr*)FUN_0008d6d0((unsigned)sizeof(Hdr) + len);
    InitHdr(h);
    unsigned char first = len ? ((unsigned char*)(h + 1))[0] : 0;
    if (h->next)
        h->next->len = len;
    Use(h, first);
}
