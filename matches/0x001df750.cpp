#include "decls/address.h"
class Base_1df750 {
  public:
    virtual void f();
    char pad[12];
    Base_1df750(const char*, int);
};
extern const char s1[], s2[], s3[];
class Method3 : public Base_1df750 {
  public:
    char a;
    char b;
    char c;
    char pad2[5];
    char d;
    char pad3[3];
    int value;
    Method3(const char*, int);
    virtual void f();
};
Method3::Method3(const char* name, int v) : Base_1df750(name, 3) {
    value = v;
    d = FUN_001d04d0(s1);
    a = FUN_001d04d0(s2);
    b = FUN_001d04d0(s3);
    c = FUN_001d04d0(s3);
}