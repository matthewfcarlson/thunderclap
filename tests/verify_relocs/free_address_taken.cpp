// verify_relocs regression (integ3, D132 item 6): a free stored as data, not called. The test pairs this object
// with a synthetic image whose operands are the game's operator delete[] (0x0008d340), so no game bytes are needed.
// SetBad stores it under its address name (must be reported), SetGood under its own name ??_V@YAXPAX@Z (must not),
// UseTable binds a deleter table this TU defines (its entry under the address name must be reported).
extern "C" void FUN_0008d340(void*);
void __cdecl operator delete[](void*);
typedef void (*Deleter)(void*);
struct Rec {
    int pad;
    Deleter deleter;
};
void SetBad(Rec* r) { r->deleter = FUN_0008d340; }
void SetGood(Rec* r) { r->deleter = &operator delete[]; }
extern "C" Deleter g_deleters[2] = {FUN_0008d340, &operator delete[]};
Deleter* UseTable() { return g_deleters; }
