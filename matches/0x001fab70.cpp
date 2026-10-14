extern "C" int strcmp(const char*, const char*);
struct Item_1fab70 {
    virtual void a();
    virtual void b(void* p);
};
struct List_1fab70 {
    virtual void a();
    virtual void b();
    virtual int Count();
    virtual const char* Get(int i);
};
struct Req_1fab70 {
    int pad;
    char* d;
};
class CGameDataHandler {
  public:
    virtual void vfunc_0();
    virtual bool vfunc_1(Req_1fab70* r);
    int pad;
    int n;
    List_1fab70* lists[1];
};
bool CGameDataHandler::vfunc_1(Req_1fab70* r) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < lists[i]->Count(); j++) {
            char* d = r->d;
            if (strcmp(d + 4, lists[i]->Get(j)) == 0) {
                ((Item_1fab70*)lists[i])->b(r);
                return true;
            }
        }
    }
    return true;
}