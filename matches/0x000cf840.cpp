#include "decls/address.h"
class Base {
  public:
    virtual void invoke();
    Base(const char*, int);
};
extern const char a[], b[];
class Closure1_cf840 : public Base {
  public:
    virtual void invoke();
    char pad[12];
    unsigned char v1;
    char pad2[7];
    unsigned char v2;
    char pad3[3];
    void* object;
    Closure1_cf840(const char*, void*, void*);
};
class Closure1 : public Closure1_cf840 {
  public:
    virtual void invoke();
    void* other;
    Closure1(const char*, void*, void*);
};
Closure1::Closure1(const char* s, void* obj, void* p) : Closure1_cf840(s, obj, p) {
    other = obj;
}
Closure1_cf840::Closure1_cf840(const char* s, void* obj, void* p) : Base(s, 1) {
    object = p;
    v2 = FUN_001d04d0(a);
    v1 = FUN_001d04d0(b);
}
