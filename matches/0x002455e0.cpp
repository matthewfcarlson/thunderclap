struct Pair {
    unsigned a;
    unsigned b;
};
Pair __cdecl FUN_002672f0(const char*, int, int);
namespace audio {
class Base {
  public:
    virtual void FUN_002455d0();
    Base(const Pair*, const Pair*, int, int, int);
};
class ClipType : public Base {
  public:
    virtual void FUN_002455d0();
    ClipType();
};
} // namespace audio
audio::ClipType::ClipType()
    : Base(&FUN_002672f0("Data_Clip", 0, 0), &FUN_002672f0("Clip", 0, 0), 0x1000000, 0x30, 8) {}
