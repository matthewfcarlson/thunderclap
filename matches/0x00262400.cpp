class Obj {
  public:
    unsigned int A();
    char* B();
};
class P2 {
  public:
    void SetExt(char*);
};

void* FUN_00262400(Obj* obj, P2* p2) {
    if (obj->A() > 0) {
        char* start = obj->B();
        char* p = (char*)obj->A();
        p += (unsigned)obj->B();
        while (p >= start) {
            if (*p == '.') {
                p2->SetExt(p + 1);
                return (void*)p2;
            }
            --p;
        }
    }
    return (void*)p2;
}
