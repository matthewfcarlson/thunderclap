class Result {
  public:
    char pad[0x1ca0];
    class Mid* mid;
};
class End {
  public:
    char pad[0xc8];
    unsigned char flag;
};
class Mid {
  public:
    End* Get();
};
extern "C" __int64 __cdecl Decode(int, int, int);
class Owner {
  public:
    Result* Find(__int64);
    void Set(int, unsigned char);
};
void Owner::Set(int key, unsigned char flag) {
    __int64 id = Decode(key, 0, 0);
    Result* r = Find(id);
    if (r) {
        End* e = r->mid->Get();
        if (e)
            e->flag = flag;
    }
}