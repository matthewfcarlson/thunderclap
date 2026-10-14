// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 2/2)
// FUN_00261120 @ 0x00261120
// equiv-map: ??0Type@om@@QAE@PAX0HH@Z = 0x002584d0
// equiv-map: ??0String@om@@QAE@XZ = 0x0023fac0
inline void* operator new(unsigned int, void* p) { return p; }
inline void operator delete(void*, void*) {}
extern int DAT_004e58c8;
extern int DAT_004e58d0;
void* __cdecl FUN_00247530(void* pool);
struct Registry;
void __cdecl FUN_00260f10(Registry* reg, void* attr, int* key);
namespace om {
class String {
public:
    char data[8];
    String() throw();
    void FUN_00240190(const String* s);
};
class Type {
public:
    virtual void v0();
    char data[0x3c];
    Type(void* a, void* b, int c, int d) throw();
    void FUN_002580e0();
};
template <class T> class TypeT : public Type {
public:
    virtual void v0();
    TypeT(void* a, void* b, int c, int d) throw() : Type(a, b, c, d) {}
};
class DynAttr {
public:
    virtual void v0();
    char pad[0x10];
    int key;
    DynAttr(const int* k) throw() : key(*k) {}
};
template <class T> class DynAttrT : public DynAttr {
public:
    virtual void v0();
    T value;
    DynAttrT(const int* k) : DynAttr(k) {}
};
}
om::String* RegisterString(Registry* reg, int* key, const om::String* text) {
    om::TypeT<om::DynAttrT<om::String> > pool(&DAT_004e58d0, &DAT_004e58c8, 0x24, 4);
    void* mem = FUN_00247530(&pool);
    pool.FUN_002580e0();
    om::DynAttrT<om::String>* attr = 0;
    if (mem)
        attr = new (mem) om::DynAttrT<om::String>(key);
    om::String* s = &attr->value;
    s->FUN_00240190(text);
    FUN_00260f10(reg, attr, key);
    return s;
}
