// STATUS: equivalent (tools/equiv.py level 3: 20043 inputs, branch coverage 45/48, incomplete)
// hulkfight::GameStateCondition::vfunc_6 @ 0x0012f400
// cl-flags: /GS
#include "gen/hulkfight.h"

extern int __cdecl FUN_00267760(char* buf, int size, const char* fmt, ...);

struct Script_12f400 {
    char FUN_001d2ba0(const char* name, int a, int b);
    char FUN_001d2da0(const char* name, int* out);
    void FUN_001d2cd0(int value, char* buf, int size);
    void FUN_001d19d0(int n);
};

Script_12f400* __cdecl FUN_001d4c90();

namespace hulkfight {

}
bool hulkfight::GameStateCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; int b = (int)__p1; int c = (int)__p2;

    bool result = false;

    if ((*(const char * *)&this->f_14) != 0) {
        Script_12f400* script = FUN_001d4c90();
        char buf[0x80];
        for (int i = 0; i < 0x80; i++)
            buf[i] = 0;
        int value;
        if (script->FUN_001d2ba0("game_state_current", 1, 0)) {
            char got = script->FUN_001d2da0((*(const char * *)&this->f_0c), &value);
            script->FUN_001d19d0(1);
            if (got && script->FUN_001d2ba0("game_state_list", 1, 0)) {
                char found = script->FUN_001d2ba0((*(const char * *)&this->f_0c), 0, 0);
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
                            if (script->FUN_001d2ba0((*(const char * *)&this->f_0c), 0, 0)) {
                                script->FUN_001d2cd0(value, buf, 0x80);
                                script->FUN_001d19d0(1);
                            }
                            script->FUN_001d19d0(1);
                        }
                    }
                    if (this->f_10 == 0 || this->f_10 == 1) {
                        const char* p = buf;
                        const char* q = (*(const char * *)&this->f_14);
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
                        if (this->f_10 == 0)
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
