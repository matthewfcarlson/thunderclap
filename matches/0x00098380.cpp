struct Obj_98380 {
    unsigned int x[16];
    void Run(unsigned int);
};
struct Helper_98380 {
    void Init(Obj_98380*, unsigned int);
};
void Obj_98380::Run(unsigned int arg) {
    Obj_98380 local;
    ((Helper_98380*)&local)->Init(this, arg);
    *this = local;
}