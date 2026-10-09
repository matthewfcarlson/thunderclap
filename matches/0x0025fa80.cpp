extern void* gPtr;
extern int gCount;
void InitMeta(void*, void*);
struct MetaType { void* vftable; void run(); };
void MetaType::run() {
    void* p = gPtr;
    vftable = (void*)0x42aa40;
    InitMeta(p, this);
    --gCount;
}