extern char VT_2380a0[];
struct Track {
    virtual void V();
};
extern "C" Track* __cdecl FUN_00236ac0(int, Track*);
struct Receiver_2380a0 {
    void Finish(Track*);
};
void FUN_002380a0(Receiver_2380a0* c, int b) {
    Track t;
    *(void**)&t = VT_2380a0;
    Track* p = FUN_00236ac0(b, &t);
    c->Finish(p);
}
