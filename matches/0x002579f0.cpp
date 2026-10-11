namespace om {
class Entity {
  public:
    virtual ~Entity() throw();
    char pad[0x24];
};
} // namespace om
extern char g_pool[];
void Release2(void*, void*) throw();
void F1(void*) throw();
void F2(void*) throw();
namespace audio {
class Sequence : public om::Entity {
  public:
    struct SB {
        char* p;
        char b[0x10];
        void Reset() { p = b; }
    } sb;
    char m3c[8];
    char m44[8];
    virtual ~Sequence() throw();
    static void operator delete(void* p) { Release2(g_pool, p); }
};
Sequence::~Sequence() throw() {
    sb.Reset();
    F1(m3c);
    F2(m44);
}
} // namespace audio
