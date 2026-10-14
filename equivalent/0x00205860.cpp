// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00205860 @ 0x00205860
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" int __cdecl _sprintf(char *buf, const char *fmt, ...);
extern char DAT_004c91d9;

struct Marker {
    void FUN_00204f00();
};

class District {
public:
    char pad0[0x24];
    char name[0x570 - 0x24];    // 0x24
    int ids[2];                 // 0x570
    bool FUN_002046b0(int id);
    void FUN_00204760(int id);
    Marker *FUN_00204540(const char *label);
    void FUN_00205860(int id);
};

void District::FUN_00205860(int id)
{
    struct Frame {
        char label[0x100];
        unsigned int cookie;
    } fr;
    fr.cookie = DAT_004d9968;
    for (int i = 0; i < 2; i++) {
        if (ids[i] != id)
            continue;
        if (!FUN_002046b0(id)) {
            _sprintf(fr.label, "%s_district_%d", name, id);
            FUN_00204760(id);
            if (DAT_004c91d9 != 0)
                FUN_00204540(fr.label)->FUN_00204f00();
        }
        break;
    }
    __security_check_cookie(fr.cookie);
}
