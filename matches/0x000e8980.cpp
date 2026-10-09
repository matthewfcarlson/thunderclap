struct Ref {
    virtual void a();
    virtual void release();
};
extern int billboardVtable;
extern int animationVtable;
void thunk(unsigned int);
struct Obj {
    int* vptr;
    unsigned int resource;
    char pad[4];
    Ref* child;
    void cleanup();
};
void Obj::cleanup() {
    vptr = &billboardVtable;
    Ref* volatile* pc = &child;
    Ref* c = *pc;
    if (c) {
        c->release();
        child = 0;
    }
    vptr = &animationVtable;
    c = *pc;
    if (c) {
        c->release();
        child = 0;
    }
    if (resource) {
        thunk(resource);
        resource = 0;
    }
}
