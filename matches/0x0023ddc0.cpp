extern char VT_23ddc0[];
struct Track {
    virtual void V();
};
extern "C" Track* __cdecl FUN_00236ac0(int, Track*);
struct Receiver_23ddc0 {
    void Finish(Track*);
};
void FUN_0023ddc0(Receiver_23ddc0* c, int b) {
    Track t;
    *(void**)&t = VT_23ddc0;
    Track* p = FUN_00236ac0(b, &t);
    c->Finish(p);
}
