// Game side of tests/native_host/rtti_test.sh: compiled like the tree (MS C++ ABI, aarch64-pc-windows-msvc, the IR
// retargeted to Mach-O by tools/native_mac.py), so its dynamic_cast / typeid go through clang's MS lowering
// (__RTDynamicCast, __RTCastToVoid, __RTtypeid) to src/platform/sdl/host/rtti_msabi.cpp.
class type_info {
  public:
    virtual ~type_info();
    int operator==(const type_info&) const;
    int operator!=(const type_info&) const;
    const char* name() const;
    const char* raw_name() const;
};
namespace std { using ::type_info; }

struct A { virtual ~A() {} int a; };
struct B : A { int b; };
struct C { virtual void c() {} int c1; };
struct D : B, C { int d; };
struct V { virtual void v() {} int v1; };
struct W : virtual V { int w; };
struct X : W { int x; };
struct P { virtual void p() {} };
struct Q : private P { P* self() { return this; } };     // P is a private base of Q
struct S { virtual void s() {} };
struct R : A, Q, private S {};
namespace ns { struct Inner { virtual ~Inner() {} }; template <class T, int N> struct Tpl : Inner {}; }
enum Colour { red };

extern "C" int hulk_rtti_strcmp(const char*, const char*);

#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)

extern "C" int rtti_game_run(void) {
    B b; D d; X x; Q q; A a;
    ns::Tpl<int, 3> t;
    A* pa = &b;
    CHECK(dynamic_cast<B*>(pa) == &b);                        // single inheritance, down
    CHECK(dynamic_cast<B*>(&a) == 0);                         // not a B
    CHECK(dynamic_cast<B*>((A*)0) == 0);
    C* pc = &d;                                               // the second base of D
    CHECK((void*)pc != (void*)&d);
    CHECK(dynamic_cast<D*>(pc) == &d);                        // down from a non-primary base: adjusted
    CHECK(dynamic_cast<B*>(pc) == static_cast<B*>(&d));       // cross cast
    CHECK(dynamic_cast<A*>(pc) == static_cast<A*>(&d));
    CHECK(dynamic_cast<void*>(pc) == (void*)&d);              // the complete object
    A* pda = &d;
    CHECK(dynamic_cast<C*>(pda) == static_cast<C*>(&d));
    V* pv = &x;                                               // a virtual base
    CHECK(dynamic_cast<X*>(pv) == &x);
    CHECK(dynamic_cast<W*>(pv) == static_cast<W*>(&x));
    CHECK(dynamic_cast<void*>(pv) == (void*)&x);
    CHECK(dynamic_cast<Q*>(q.self()) == 0);                   // from a private base: not allowed
    R r;
    CHECK(dynamic_cast<Q*>(r.self()) == 0);                   // the same, Q not the complete object
    CHECK(dynamic_cast<S*>(static_cast<A*>(&r)) == 0);        // a cross cast to a private base
    CHECK(typeid(*pa) == typeid(B));
    CHECK(typeid(*pc) == typeid(D));                          // the complete object's type
    CHECK(typeid(*pv) == typeid(X));
    CHECK(typeid(*pa) != typeid(A));
    CHECK(hulk_rtti_strcmp(typeid(*pa).name(), "struct B") == 0);
    CHECK(hulk_rtti_strcmp(typeid(*pa).raw_name(), ".?AUB@@") == 0);
    CHECK(hulk_rtti_strcmp(typeid(int).name(), "int") == 0);
    CHECK(hulk_rtti_strcmp(typeid(bool).name(), "bool") == 0);
    CHECK(hulk_rtti_strcmp(typeid(const char*).name(), "char const * __ptr64") == 0);
    CHECK(hulk_rtti_strcmp(typeid(Colour).name(), "enum Colour") == 0);
    ns::Inner* pi = &t;
    CHECK(hulk_rtti_strcmp(typeid(*pi).name(), "struct ns::Tpl<int,3>") == 0);
    CHECK(hulk_rtti_strcmp(typeid(ns::Tpl<B, 1>).name(), "struct ns::Tpl<struct B,1>") == 0);
    return 0;
}

extern "C" const void* rtti_game_type_b(void) { return &typeid(B); }
extern "C" void* rtti_game_object_d(void) { static D d; return static_cast<A*>(&d); }
extern "C" void* rtti_game_ref_cast(void) { static A a; A& r = a; return &dynamic_cast<B&>(r); }   // bad_cast
extern "C" const void* rtti_game_typeid_null(void) { A* p = 0; return &typeid(*p); }      // bad_typeid
