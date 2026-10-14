struct Item_270a50 {
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
};
extern "C" void FUN_0026d850(void*);
extern "C" void FUN_0026d840(void*);
extern int count;
extern Item_270a50* items[];
extern char lockdata[];
void FUN_00270a50() {
    FUN_0026d850(lockdata);
    unsigned int i = 0;
    if ((unsigned int)count > 0) {
        Item_270a50** p = items;
        do {
            Item_270a50* q = *p;
            if (q != 0) {
                q->A();
                FUN_0026d840(lockdata);
                q->D();
                q->B();
                FUN_0026d850(lockdata);
            }
            ++i;
            p += 0x47;
        } while (i < (unsigned int)count);
    }
    FUN_0026d840(lockdata);
}