typedef __int64 I64;
extern "C" I64 __cdecl lookup(const char*, int, int);
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
    Holder* h = Find(lookup(name, 0, 0));
    if (h && h->value) {
        End* e = h->value->Get();
        if (e)
            e->Work(a, b, c, d);
    }
}