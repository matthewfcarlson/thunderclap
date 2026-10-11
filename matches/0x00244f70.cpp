extern void* vEntity[];
extern void* vIRef[];
extern void* DAT_004cc08c;
extern int DAT_004e5f0c;
extern void FUN_00244b20(void*, void*);
struct Target {
    void* vf;
    void Dtor() throw();
};
void Target::Dtor() throw() {
    void* g = DAT_004cc08c;
    vf = vEntity;
    FUN_00244b20(g, this);
    DAT_004e5f0c = DAT_004e5f0c - 1;
    vf = vIRef;
}
