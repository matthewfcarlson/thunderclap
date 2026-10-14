class Ref_30fc90 {
  public:
    virtual void A();
    virtual void B();
};
extern void* vt1_30fc90;
extern void* vt2_30fc90;
class T_30fc90 {
  public:
    virtual void V();
    int a4;
    Ref_30fc90* obj8;
    Ref_30fc90* objc;
    int count;
    int a14;
    Ref_30fc90*** arr;
    Ref_30fc90*** rows;
};
void __cdecl drop(void*);
void T_30fc90::V() {
    int i = count - 1;
    *(void**)this = &vt1_30fc90;
    if (i >= 0) {
        do {
            int j = ((int*)arr)[i] - 1;
            while (j >= 0) {
                Ref_30fc90* r = rows[i][j];
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
    *(void**)this = &vt2_30fc90;
}