extern "C" char DAT_00414838[];
extern "C" void* FUN_0008d690(unsigned int);
extern "C" void FUN_002347b0(void*, void**, int);
extern int g_count;
extern void* g_data;
class Param {
  public:
    int a[4];
    int val;
};
class Hit : public Param {
  public:
    void Init(const char*);
};
void FUN_00155500() {
    void* temp;
    if (!g_count) {
        Hit* p = (Hit*)FUN_0008d690(0x18);
        if (p) {
            p->Init("hasHitPushback");
            *(int*)p = ((int)DAT_00414838);
            *(int*)((char*)p + 0x10) = 0x14c550;
            temp = p;
        } else
            temp = 0;
        FUN_002347b0(&g_data, &temp, 1);
    }
    ++g_count;
}