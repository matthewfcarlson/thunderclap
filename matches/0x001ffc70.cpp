#include "decls/address.h"
#include "decls/data/game/global.h"
class CTriggerVolumeManager;
class Function_1ffc70 {
  public:
    virtual void invoke();
    Function_1ffc70(const char*, int);
    char pad[0x0c];
    unsigned char x;
    char pad2[7];
    unsigned char y;
    char pad3[3];
    void* owner;
};
class Method1 : public Function_1ffc70 {
  public:
    virtual void invoke();
    Method1(const char* s, void* o) : Function_1ffc70(s, 1) {
        owner = o;
        y = FUN_001d04d0(((const char*)&DAT_0048e0e4));
        x = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void invoke();
    void* fn;
    Closure1(const char* s, void* f, void* o);
};
Closure1::Closure1(const char* s, void* f, void* o) : Method1(s, o) {
    fn = f;
}