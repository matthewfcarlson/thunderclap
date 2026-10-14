extern char VT_23f500[];
struct Track {
    virtual void V();
};
extern "C" Track* __cdecl FUN_00236ac0(int, Track*);
struct Receiver_23f500 {
    void Finish(Track*);
};
void FUN_0023f500(Receiver_23f500* c, int b) {
    Track t;
    *(void**)&t = VT_23f500;
    Track* p = FUN_00236ac0(b, &t);
    c->Finish(p);
}
