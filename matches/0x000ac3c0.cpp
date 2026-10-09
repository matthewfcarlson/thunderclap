typedef unsigned int u32;
extern void* gNisCam;
class Base {
  public:
    void BaseInit();
};
class Sub {
  public:
    void Init(void* p);
};
class CNISCamera {
  public:
    char pad[0x174];
};
CNISCamera* __fastcall target(CNISCamera* self) {
    ((Base*)self)->BaseInit();
    void* p = gNisCam;
    *(u32*)self = 0x405b2c;
    *(u32*)((char*)self + 0xd0) = 3;
    ((Sub*)((char*)self + 8))->Init(p);
    *(u32*)((char*)self + 0x170) = 0;
    return self;
}
