struct Obj_35a740 {
    virtual void f0();
    virtual void f1();
};
extern Obj_35a740* gList_35a740[];
extern int gCount_35a740;
void RemoveObj(Obj_35a740* o) {
    int i = 0;
    if (gCount_35a740 > 0) {
        do {
            if (gList_35a740[i] == o) {
                gList_35a740[i]->f1();
                int last = gCount_35a740 - 1;
                gList_35a740[i] = 0;
                gCount_35a740 = last;
                if (i != last) {
                    gList_35a740[i] = gList_35a740[last];
                    gList_35a740[last] = 0;
                }
                return;
            }
            i++;
        } while (i < gCount_35a740);
    }
}
