extern void Free(void*) throw();
class Item {
  public:
    void Fini() throw();
};
namespace core {
struct ILanguageChangeCallback {
    virtual void a() = 0;
    virtual void b() = 0;
    virtual void c() = 0;
    virtual ~ILanguageChangeCallback() throw() {}
    virtual void e() = 0;
};
} // namespace core
template <class T> struct Vec {
    T* b;
    T* e;
    T* c;
    unsigned size() const { return (unsigned)(e - b); }
    T& operator[](unsigned i) { return b[i]; }
    void clear() { e = b; }
    ~Vec() throw() {
        e = b;
        if (b)
            Free(b);
    }
};
namespace pure3d {
class Entity {
  public:
    virtual ~Entity() throw();
    char pad[0xc];
};
class TextBible : public Entity, public core::ILanguageChangeCallback {
  public:
    Vec<Item*> items;
    virtual ~TextBible() throw();
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void e();
};
TextBible::~TextBible() throw() {
    for (unsigned i = 0; i < items.size(); i++)
        items[i]->Fini();
    items.clear();
}
} // namespace pure3d
