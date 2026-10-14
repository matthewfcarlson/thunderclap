struct Called {
    void F(void*);
};
struct Obj_92340 {
    char pad[0xa8];
    unsigned int Target(Called* param);
};
unsigned int Obj_92340::Target(Called* param) {
    param->F((char*)this + 0xa8);
    return (unsigned int)param;
}