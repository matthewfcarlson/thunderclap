#include "compat/ptr.h"
#include "gen/owners.h"
class Ret_89830 {
  public:
    void Last(bool);
};
class Sub_89830 {
  public:
    int a;
    int b;
};
class Mid_89830 {
  public:
    char pad[0x54];
    Ret_89830* Get();
};
class Root_89830 {
  public:
    char pad[0x54];
    Mid_89830* m;
};
class Manager_89830 {
  public:
    char pad[0xd0];
    Sub_89830 sub;
    void Target(hulk_intptr p);
};
extern Root_89830* g_89830;
void Manager_89830::Target(hulk_intptr p) {
    Sub_89830* s = &sub;
    ((owners::Obj_88fe0 *)s)->FUN_00088fe0((unsigned int)p);
    Ret_89830* r = g_89830->m->Get();
    bool f = s->a != -1 && s->b != -1;
    r->Last(f);
}
