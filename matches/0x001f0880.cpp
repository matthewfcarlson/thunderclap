struct Bits {
    int lo, hi;
};
union Value {
    __int64 whole;
    Bits parts;
};
class CSoundCommand_1f0880 {
  public:
    int a, b, c;
    CSoundCommand_1f0880(int z) : a(0), b(0), c(z) {}
};
class Pair {
  public:
    int d, e;
    Pair() : d(0), e(0) {}
};
class CSoundCommand_PlayAmbienceEvent : public CSoundCommand_1f0880 {
  public:
    virtual void Fn();
    Pair pair;
    int f;
    CSoundCommand_PlayAmbienceEvent(int x, int y, int z);
};
extern "C" __int64 __cdecl FUN_002672f0(int, int, int);
extern "C" int __cdecl FUN_002673a0(int, int);
CSoundCommand_PlayAmbienceEvent::CSoundCommand_PlayAmbienceEvent(int x, int y, int z) : CSoundCommand_1f0880(z) {
    Value v;
    v.whole = FUN_002672f0(x, 0, 0);
    pair.e = v.parts.hi;
    pair.d = v.parts.lo;
    f = FUN_002673a0(y, 0);
}