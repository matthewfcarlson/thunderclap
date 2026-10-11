extern "C" char DAT_00422674[];
extern "C" char DAT_00422830[];
class ScriptHandler {};
extern "C" void __stdcall FUN_001d0480(void*, int);
extern "C" int FUN_001d04d0(const char*);
extern int gName1;
extern int gName2;
class Closure {
  public:
    Closure(void*, void*, void*);
};
Closure::Closure(void* a, void* b, void* c) {
    FUN_001d0480(a, 1);
    *(int*)this = ((int)DAT_00422674);
    *(int*)((char*)this + 0x1c) = (int)c;
    *(char*)((char*)this + 0x18) = (char)FUN_001d04d0((const char*)&gName1);
    *(char*)((char*)this + 0x10) = (char)FUN_001d04d0((const char*)&gName2);
    *(int*)this = ((int)DAT_00422830);
    *(int*)((char*)this + 0x20) = (int)b;
}