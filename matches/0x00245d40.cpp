struct P {
    char pad[0x90]; int line; unsigned pos; unsigned end;
    char Get(unsigned p);
};
void F(P* p) {
    while (p->pos < p->end) {
        char c = p->Get(p->pos);
        if (c != 9 && c != 32 && c != 10 && c != 13) return;
        if (p->pos < p->end) {
            if (p->Get(p->pos) == 10) p->line++;
            p->pos++;
        }
    }
}
