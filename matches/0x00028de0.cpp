struct End {
    void Act(int, int, int);
};
struct Mid {
    End* Get();
};
struct Obj {
    char pad[0x1ca0];
    Mid* mid;
};
extern "C" __int64 __cdecl Decode(int, int, int);
class Handler {
  public:
    int field;
    Obj* Find(__int64);
    void Run(int a, int b);
};
void Handler::Run(int a, int b) {
    Obj* obj = Find(Decode(a, 0, 0));
    if (obj) {
        Mid* m = obj->mid;
        if (m) {
            End* e = m->Get();
            if (e)
                e->Act(field, b, 0);
        }
    }
}