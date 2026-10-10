extern "C" int strcmp(const char*, const char*);
struct Item {
    virtual void a();
    virtual void b(void* p);
};
struct List {
    virtual void a();
    virtual void b();
    virtual int Count();
    virtual const char* Get(int i);
};
struct Req {
    int pad;
    char* d;
};
class CGameDataHandler {
  public:
    virtual void vfunc_0();
    virtual bool vfunc_1(Req* r);
    int pad;
    int n;
    List* lists[1];
};
bool CGameDataHandler::vfunc_1(Req* r) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < lists[i]->Count(); j++) {
            char* d = r->d;
            if (strcmp(d + 4, lists[i]->Get(j)) == 0) {
                ((Item*)lists[i])->b(r);
                return true;
            }
        }
    }
    return true;
}