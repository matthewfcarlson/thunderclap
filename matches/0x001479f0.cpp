extern char RTTI_CFightParams_1479f0;
extern char RTTI_FightParams;
extern int __cdecl check(void*, int, char*, char*, int);

class Helper_1479f0 {
  public:
    void* getA();
    void* getB();
};

class GrappleAttachedCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool v6(void*, void* p2, void*);
    char pad[8];
    unsigned char flag;
};

bool GrappleAttachedCondition::v6(void*, void* p2, void*) {
    if (!check(p2, 0, &RTTI_FightParams, &RTTI_CFightParams_1479f0, 0))
        return false;
    void* a = ((Helper_1479f0*)p2)->getA();
    void* b = ((Helper_1479f0*)a)->getB();
    int x = *(int*)((char*)b + 0x334);
    bool t = (x != 0);
    return flag == t;
}
