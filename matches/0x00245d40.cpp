struct P_245d40 {
    char pad[0x90];
    int line;
    unsigned pos;
    unsigned end;
    char Get(unsigned p);
};
extern "C" void FUN_00245d40(void * p) {
    while (((P_245d40 *)p)->pos < ((P_245d40 *)p)->end) {
        char c = ((P_245d40 *)p)->Get(((P_245d40 *)p)->pos);
        if (c != 9 && c != 32 && c != 10 && c != 13)
            return;
        if (((P_245d40 *)p)->pos < ((P_245d40 *)p)->end) {
            if (((P_245d40 *)p)->Get(((P_245d40 *)p)->pos) == 10)
                ((P_245d40 *)p)->line++;
            ((P_245d40 *)p)->pos++;
        }
    }
}
