#include "gen/owners.h"
struct P_245d40 {
    char pad[0x90];
    int line;
    unsigned pos;
    unsigned end;
};
extern "C" void FUN_00245d40(void * p) {
    while (((P_245d40 *)p)->pos < ((P_245d40 *)p)->end) {
        char c = ((char)((owners::RingReader_245b70 *)(((P_245d40 *)p)))->FUN_00245b70((unsigned int)(((P_245d40 *)p)->pos)));
        if (c != 9 && c != 32 && c != 10 && c != 13)
            return;
        if (((P_245d40 *)p)->pos < ((P_245d40 *)p)->end) {
            if (((char)((owners::RingReader_245b70 *)(((P_245d40 *)p)))->FUN_00245b70((unsigned int)(((P_245d40 *)p)->pos))) == 10)
                ((P_245d40 *)p)->line++;
            ((P_245d40 *)p)->pos++;
        }
    }
}
