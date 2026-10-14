extern char VT_23e930[];
struct Track {
    virtual void V();
};
extern "C" Track* __cdecl FUN_00236ac0(int, Track*);
struct Receiver_23e930 {
    void Finish(Track*);
};
void FUN_0023e930(Receiver_23e930* c, int b) {
    Track t;
    *(void**)&t = VT_23e930;
    Track* p = FUN_00236ac0(b, &t);
    c->Finish(p);
}
