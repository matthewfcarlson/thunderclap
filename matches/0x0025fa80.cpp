extern "C" char DAT_0042aa40[];
extern void* gPtr;
extern int gCount;
void InitMeta(void*, void*);
struct MetaType {
    void* vftable;
    void run();
};
void MetaType::run() {
    void* p = gPtr;
    vftable = (void*)((int)DAT_0042aa40);
    InitMeta(p, this);
    --gCount;
}