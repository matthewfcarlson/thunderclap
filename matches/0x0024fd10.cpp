extern const char name1[], name2[];
extern __int64 __cdecl MakeKey(const char*, int, int) throw();
class Temp {
    char pad[12];

  public:
    Temp* Init(const char*, int) throw();
    ~Temp() throw();
};
namespace audio {
class Base {
  public:
    virtual void V();
    Base(Temp*, const __int64*, int, int) throw();
};
class SeqEventConditionType : public Base {
  public:
    virtual void V();
    SeqEventConditionType() throw();
};
} // namespace audio
audio::SeqEventConditionType::SeqEventConditionType() throw()
    : Base(Temp().Init(name2, 0), &(__int64 const&)MakeKey(name1, 0, 0), 32, 4) {}