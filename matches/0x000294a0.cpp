#include "decls/address.h"
typedef __int64 I64;
class End {
  public:
    void Work(int, int, int, int);
};
class Mid {
  public:
    End* Get();
};
class Holder {
    char pad[0x1ca0];

  public:
    Mid* value;
};
class Owner {
  public:
    Holder* Find(I64);
    void Run(const char* name, int a, int b, int c, int d);
};
void Owner::Run(const char* name, int a, int b, int c, int d) {
    Holder* h = Find(FUN_002672f0(name, 0, 0));
    if (h && h->value) {
        End* e = h->value->Get();
        if (e)
            e->Work(a, b, c, d);
    }
}