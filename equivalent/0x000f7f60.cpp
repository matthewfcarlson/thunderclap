// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000f7f60 @ 0x000f7f60
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;
extern "C" void __cdecl FUN_00294c70(int src, char* dst, int size);

class Printer_f7f60 {
public:
    void FUN_000f7d60(const char* text, int a2, int a3, int a4, int a5, int a6);
    void FUN_000f7f60(int src, int a2, int a3, int a4, int a5, int a6);
};

void Printer_f7f60::FUN_000f7f60(int src, int a2, int a3, int a4, int a5, int a6) {
    struct Frame {
        char text[0x400];
        unsigned int cookie;
    } fr;
    fr.cookie = DAT_004d9968;
    FUN_00294c70(src, fr.text, 0x200);
    FUN_000f7d60(fr.text, a2, a3, a4, a5, a6);
    __security_check_cookie(fr.cookie);
}
