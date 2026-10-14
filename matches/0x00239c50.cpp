extern char VT_239c50[];
struct Track {
    virtual void V();
};
extern "C" Track* __cdecl FUN_00236ac0(int, Track*);
struct Receiver_239c50 {
    void Finish(Track*);
};
void FUN_00239c50(Receiver_239c50* c, int b) {
    Track t;
    *(void**)&t = VT_239c50;
    Track* p = FUN_00236ac0(b, &t);
    c->Finish(p);
}
