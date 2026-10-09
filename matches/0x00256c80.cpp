struct Sub {
    void Init();
};
class SeqTrack {
  public:
    char pad[0x1c];
    SeqTrack* Build(unsigned char);
};
int __cdecl GetTrack(SeqTrack*);
void __cdecl Cleanup(int);
SeqTrack* SeqTrack::Build(unsigned char flags) {
    *(int*)this = 0x42a600;
    ((Sub*)((char*)this + 0x1c))->Init();
    if (flags & 1)
        Cleanup(GetTrack(this));
    return this;
}