extern char RTTI_CFightParams;
extern char RTTI_FightParams;
extern int __cdecl check(void*, int, char*, char*, int);

class Helper { public: void* getA(); void* getB(); };

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
  if (!check(p2, 0, &RTTI_FightParams, &RTTI_CFightParams, 0)) return false;
  void* a = ((Helper*)p2)->getA();
  void* b = ((Helper*)a)->getB();
  int x = *(int*)((char*)b + 0x334);
  bool t = (x != 0);
  return flag == t;
}
