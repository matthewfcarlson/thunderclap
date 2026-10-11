extern char VT[];
struct Track {
    virtual void V();
};
extern "C" Track* __cdecl FUN_00236ac0(int, Track*);
struct Receiver {
    void Finish(Track*);
};
void FUN_002380a0(Receiver* c, int b) {
    Track t;
    *(void**)&t = VT;
    Track* p = FUN_00236ac0(b, &t);
    c->Finish(p);
}
