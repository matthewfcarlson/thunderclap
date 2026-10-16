#include "decls/address.h"
class CTriggerVolumeManager;
extern const char a[], b[];
class Base {
  public:
    virtual void invoke();
    Base(const char*, int);
    char pad[0x0c];
    unsigned char x;
    char pad2[7];
    unsigned char y;
    char pad3[3];
    void* owner;
};
class Method1 : public Base {
  public:
    virtual void invoke();
    Method1(const char* s, void* o) : Base(s, 1) {
        owner = o;
        y = FUN_001d04d0(a);
        x = FUN_001d04d0(b);
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