class Mgr {
  public:
    char Check(int);
};
class Obj {
    char pad[0x4c];

  public:
    Mgr* mgr;
    void Run();
};
struct Button {
    char pad[0x141];
    char flag;
};
extern "C" void* __cdecl Find(const char*);
extern "C" Button* __cdecl Convert(void*, int, void*, void*, int);
extern const char key[];
extern int type1, type2;
void Obj::Run() {
    Button* b = Convert(Find(key), 0, &type1, &type2, 0);
    if (b) {
        int count = 0;
        for (int i = 0x266; i <= 0x2c9; ++i)
            if (!mgr->Check(i))
                ++count;
        b->flag = count > 0;
    }
}