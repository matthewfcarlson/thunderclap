// STATUS: equivalent (tools/equiv.py level 3: 20043 inputs, branch coverage 45/48, incomplete)
// hulkfight::GameStateCondition::vfunc_6 @ 0x0012f400
// cl-flags: /GS
extern int __cdecl FUN_00267760(char* buf, int size, const char* fmt, ...);

struct Script_12f400 {
    char FUN_001d2ba0(const char* name, int a, int b);
    char FUN_001d2da0(const char* name, int* out);
    void FUN_001d2cd0(int value, char* buf, int size);
    void FUN_001d19d0(int n);
};

Script_12f400* __cdecl FUN_001d4c90();

namespace hulkfight {

class GameStateCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a, int b, int c);
    char pad04[8];
    const char* stateName;      // 0xc
    int mode;                   // 0x10
    const char* expected;       // 0x14
};

bool GameStateCondition::vfunc_6(int a, int b, int c)
{
    bool result = false;

    if (expected != 0) {
        Script_12f400* script = FUN_001d4c90();
        char buf[0x80];
        for (int i = 0; i < 0x80; i++)
            buf[i] = 0;
        int value;
        if (script->FUN_001d2ba0("game_state_current", 1, 0)) {
            char got = script->FUN_001d2da0(stateName, &value);
            script->FUN_001d19d0(1);
            if (got && script->FUN_001d2ba0("game_state_list", 1, 0)) {
                char found = script->FUN_001d2ba0(stateName, 0, 0);
                if (found)
                    script->FUN_001d19d0(1);
                script->FUN_001d19d0(1);
                if (found) {
                    if (value == 0) {
                        FUN_00267760(buf, 0x80, "unassigned");
                    } else if (value == -1) {
                        FUN_00267760(buf, 0x80, "complete");
                    } else if (value == -999) {
                        FUN_00267760(buf, 0x80, "failed");
                    } else {
                        if (script->FUN_001d2ba0("game_state_list", 1, 0)) {
                            if (script->FUN_001d2ba0(stateName, 0, 0)) {
                                script->FUN_001d2cd0(value, buf, 0x80);
                                script->FUN_001d19d0(1);
                            }
                            script->FUN_001d19d0(1);
                        }
                    }
                    if (mode == 0 || mode == 1) {
                        const char* p = buf;
                        const char* q = expected;
                        int cmp;
                        for (;;) {
                            unsigned char pc = *p;
                            unsigned char qc = *q;
                            if (pc != qc) {
                                cmp = 1;
                                break;
                            }
                            if (pc == 0) {
                                cmp = 0;
                                break;
                            }
                            p++;
                            q++;
                        }
                        if (mode == 0)
                            result = (cmp == 0);
                        else
                            result = (cmp != 0);
                    }
                }
            }
        }
    }
    return result;
}

}
