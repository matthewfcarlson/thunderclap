class Ref {
  public:
    virtual void A();
    virtual void B();
};
extern void* vt1;
extern void* vt2;
class T {
  public:
    virtual void V();
    int a4;
    Ref* obj8;
    Ref* objc;
    int count;
    int a14;
    Ref*** arr;
    Ref*** rows;
};
void __cdecl drop(void*);
void T::V() {
    int i = count - 1;
    *(void**)this = &vt1;
    if (i >= 0) {
        do {
            int j = ((int*)arr)[i] - 1;
            while (j >= 0) {
                Ref* r = rows[i][j];
                r->B();
                --j;
            }
            drop(rows[i]);
            --i;
        } while (i >= 0);
    }
    drop(rows);
    drop(arr);
    obj8->B();
    objc->B();
    *(void**)this = &vt2;
}