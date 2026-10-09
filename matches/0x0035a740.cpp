struct Obj {
    virtual void f0();
    virtual void f1();
};
extern Obj* gList[];
extern int gCount;
void RemoveObj(Obj* o) {
    int i = 0;
    if (gCount > 0) {
        do {
            if (gList[i] == o) {
                gList[i]->f1();
                int last = gCount - 1;
                gList[i] = 0;
                gCount = last;
                if (i != last) {
                    gList[i] = gList[last];
                    gList[last] = 0;
                }
                return;
            }
            i++;
        } while (i < gCount);
    }
}
