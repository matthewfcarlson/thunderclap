struct Obj {
    char pad[0xcd];
    unsigned char flag;
};
struct ThisWrap_001fcc60 {
    Obj* findObj(int);
    void FUN_001fcc60(int id);
};
void ThisWrap_001fcc60::FUN_001fcc60(int id) {
    Obj* p = this->findObj(id);
    if (p)
        p->flag = 1;
}