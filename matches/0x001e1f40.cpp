#include "decls/address.h"
class CSPManager;
extern const char s1[], s2[];
struct Function_1e1f40 {
    virtual void run();
    char pad[0x0c];
    char a;
    char pad2[7];
    char b;
    char pad3[3];
    const char* name;
    Function_1e1f40(const char*, int);
};
struct Method1 : Function_1e1f40 {
    virtual void run();
    Method1(const char* x, const char* z) : Function_1e1f40(x, 1) {
        name = z;
        b = FUN_001d04d0(s1);
        a = FUN_001d04d0(s2);
    }
};
struct Closure1 : Method1 {
    virtual void run();
    CSPManager* mgr;
    Closure1(const char*, CSPManager*, const char*);
};
Closure1::Closure1(const char* x, CSPManager* m, const char* z) : Method1(x, z) {
    mgr = m;
}
