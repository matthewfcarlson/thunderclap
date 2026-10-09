extern void* Alloc(unsigned int);
class Sub {
  public:
    void Init();
};
class AIHistorySetTrack {
  public:
    int pad0;
    int x1;
    int x2;
    int x3;
    float val;
    unsigned char flag;
    char pad[3];
    Sub sub;
    int tail;
    void BaseInit();
};
AIHistorySetTrack* Factory() {
    AIHistorySetTrack* p = (AIHistorySetTrack*)Alloc(0x20);
    if (p) {
        p->BaseInit();
        *(int*)p = 0x40dca4;
        p->x3 = 0;
        p->val = -1.0f;
        p->flag = 0;
        p->sub.Init();
        p->x2 = 1;
        return p;
    }
    return 0;
}
