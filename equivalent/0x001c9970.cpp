// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001c9970 @ 0x001c9970
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;

struct Node {
    bool FUN_001d2e80();
    void FUN_001d1d50(const char *key, const char *value);
    void FUN_001d1e10(const char *key, int value);
    void FUN_001d1d10();
};

Node *__cdecl FUN_001d4c90();
void __cdecl FUN_00096d50(char *buf, int size, int lo, int hi);

class Entity {
public:
    char pad0[0xb0];
    int idLo;                 // 0xb0
    int idHi;                 // 0xb4
    unsigned char kind;       // 0xb8
    bool FUN_001c9840();
    bool FUN_001c9970();
};

struct Frame {
    char text[0x20];
    unsigned int cookie;
};

bool Entity::FUN_001c9970()
{
    Frame f;
    f.cookie = DAT_004d9968;
    if (!FUN_001c9840()) {
        __security_check_cookie(f.cookie);
        return false;
    }
    Node *node = FUN_001d4c90();
    if (node == 0 || !node->FUN_001d2e80()) {
        __security_check_cookie(f.cookie);
        return false;
    }
    FUN_00096d50(f.text, 0x20, idLo, idHi);
    node->FUN_001d1d50("origin", f.text);
    node->FUN_001d1e10("devastator", kind);
    node->FUN_001d1d10();
    __security_check_cookie(f.cookie);
    return true;
}
