class Caster {
  public:
    virtual void cast();
};
struct CDamageTrack;
extern void __cdecl Find(CDamageTrack*, Caster*);
void __cdecl Target(CDamageTrack* track) {
    Caster c;
    Find(track, &c);
}