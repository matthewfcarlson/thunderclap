struct Obj {
    int pad, a, b, c;
    void F();
};
extern int* gPtr;
extern int gBase;
void Obj::F() {
    int* p = gPtr - 3;
    b = *p + gBase;
    ++p;
    c = *p + gBase;
    ++p;
    a = *p + gBase;
}