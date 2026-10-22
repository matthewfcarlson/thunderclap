extern int gameVftable;
extern int creatorVftable;
class Ref_1faa60 {
  public:
    virtual void Release(int);
};
class CGameDataHandler_1faa60 {
  public:
    int* vptr;
    Ref_1faa60* mRef;
    void f();
};
void CGameDataHandler_1faa60::f() {
    vptr = &gameVftable;
    if (mRef)
        mRef->Release(1);
    vptr = &creatorVftable;
}