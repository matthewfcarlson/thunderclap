struct Callee { void Yes(int); void No(int); };
struct Obj { char pad0[4]; Callee* p; char flag; void Run(int); };
void Obj::Run(int unused) {
    if (flag) p->Yes(unused);
    else p->No(1);
}