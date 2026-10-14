extern "C" char DAT_004dc950[];
extern "C" char DAT_004dc96c[];
extern "C" char DAT_004dc988[];
class C_363bf0 {
  public:
    void init(void*, void*);
};
extern "C" void __cdecl FUN_00363bf0(void) {
    ((C_363bf0*)((int)DAT_004dc988))->init((void*)0x66930, (void*)((int)DAT_004dc988));
    ((C_363bf0*)((int)DAT_004dc96c))->init((void*)0x66a00, (void*)((int)DAT_004dc96c));
    ((C_363bf0*)((int)DAT_004dc950))->init((void*)0x66930, (void*)((int)DAT_004dc950));
}