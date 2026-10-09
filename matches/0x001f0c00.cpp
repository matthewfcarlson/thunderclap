class Base {
  public:
    Base(char*, int);
};
unsigned char FUN_001d04d0(void*);
class CSoundSystem : public Base {
  public:
    char pad0[0x10];
    unsigned char b10, b11, b12, b13, b14, b15;
    char pad16[2];
    unsigned char b18;
    char pad19[3];
    void* p1c;
    CSoundSystem(char*, void*);
};
CSoundSystem::CSoundSystem(char* a, void* c) : Base(a, 6) {
    *(unsigned int*)this = 0x4246ec;
    p1c = c;
    b18 = FUN_001d04d0((void*)0x48e100);
    b10 = FUN_001d04d0((void*)0x49cad8);
    b11 = FUN_001d04d0((void*)0x49cad8);
    b12 = FUN_001d04d0((void*)0x48e128);
    b13 = FUN_001d04d0((void*)0x48e128);
    b14 = FUN_001d04d0((void*)0x48e128);
    b15 = FUN_001d04d0((void*)0x48e128);
}