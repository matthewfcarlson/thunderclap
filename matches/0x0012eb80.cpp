extern "C" char DAT_00411344[];
typedef unsigned int U;
class DialogueTrack;
extern void __fastcall final_fn(DialogueTrack*);
extern void __cdecl release(U);
class DialogueTrack {
  public:
    void* vf;
    char pad[12];
    U a;
    U b;
    char pad2[4];
    U c;
    U d;
    void destroy();
};
void DialogueTrack::destroy() {
    vf = (void*)((int)DAT_00411344);
    release(a);
    release(b);
    release(c);
    release(d);
    final_fn(this);
}
