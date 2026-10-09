class Obj {
  public:
    char pad0[0x10];
    char enabled;
    char pad11[0x4f];
    int items[16][8];
    bool GetData(int, int*);
    void ClearData(int);
};
void __fastcall FUN_000c75b0(Obj* p) {
    int local[3];
    if (p->enabled) {
        int i = 0;
        int* q = &p->items[0][3];
        do {
            if (q[-3] != -1) {
                if (!p->GetData(i, local))
                    p->ClearData(i);
                else {
                    q[-2] = local[0];
                    q[-1] = local[1];
                    q[0] = local[2];
                }
            }
            ++i;
            q += 8;
        } while (i < 16);
    }
}
