// STATUS: equivalent (tools/equiv.py level 3: 160 inputs, branch coverage 27/33, incomplete)
// FUN_001cb170 @ 0x001cb170
class Dispatcher_1cb170;
class Context {
public:
    bool FUN_001d1cb0();
    void FUN_001d1980(const char *name, int flag);
    void FUN_001d1d30();
};
Context *FUN_001d4c90();

class Dispatcher_1cb170 {
public:
    int pad0;
    int type;               // 0x4
    void FUN_001c9840();
    void FUN_001c9970();
    void FUN_001c9aa0();
    void FUN_001c9b80();
    void FUN_001c9c50();
    void FUN_001c9d20();
    void FUN_001c9df0();
    void FUN_001c9ec0();
    void FUN_001c9fb0();
    void FUN_001ca090();
    void FUN_001ca170();
    void FUN_001ca250();
    void FUN_001ca330();
    void FUN_001ca430();
    void FUN_001ca5b0();
    void FUN_001ca730();
    void FUN_001ca890();
    void FUN_001caa10();
    void FUN_001cab60();
    void FUN_001cacc0();
    void FUN_001cad40();
    void FUN_001cadb0();
    void FUN_001cae90();
    void FUN_001caf40();
    void FUN_001cafd0();
    void FUN_001cb0a0();
    bool FUN_001cb170();
};

bool Dispatcher_1cb170::FUN_001cb170()
{
    Context *ctx = FUN_001d4c90();
    if (ctx == 0) return false;
    if (!ctx->FUN_001d1cb0()) return false;
    ctx->FUN_001d1980("event", 0);
    ctx->FUN_001d1d30();
    switch (type) {
    case 0: return true;
    case 1: FUN_001c9970(); return true;
    case 2: FUN_001c9840(); return true;
    case 3: FUN_001c9840(); return true;
    case 4: FUN_001c9aa0(); return true;
    case 5: FUN_001c9b80(); return true;
    case 6: FUN_001c9c50(); return true;
    case 7: FUN_001c9d20(); return true;
    case 8: FUN_001c9df0(); return true;
    case 9: FUN_001c9ec0(); return true;
    case 10: FUN_001c9fb0(); return true;
    case 11: FUN_001c9fb0(); return true;
    case 12: FUN_001c9fb0(); return true;
    case 13: FUN_001ca090(); return true;
    case 14: return true;
    case 15: FUN_001ca250(); return true;
    case 16: FUN_001ca170(); return true;
    case 17: FUN_001ca330(); return true;
    case 18: FUN_001ca430(); return true;
    case 19: FUN_001ca5b0(); return true;
    case 20: FUN_001ca730(); return true;
    case 21: FUN_001ca890(); return true;
    case 22: FUN_001caa10(); return true;
    case 23: FUN_001cab60(); return true;
    case 24: FUN_001cacc0(); return true;
    case 25: FUN_001cad40(); return true;
    case 26: FUN_001cadb0(); return true;
    case 27: FUN_001cae90(); return true;
    case 28: FUN_001caf40(); return true;
    case 29: FUN_001cafd0(); return true;
    case 30: FUN_001cb0a0(); return true;
    default: return false;
    }
}
