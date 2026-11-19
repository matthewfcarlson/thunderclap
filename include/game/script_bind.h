// The script binding family as records (script1, 2026-11-18): Function (RTTI .?AVFunction@@) and the Method<N> /
// Closure<N> templates that bind a C++ member function to Lua, built the way the game builds them, for the sources
// that construct them (the managers' constructors and registration helpers, the out-of-line template constructors).
//
// Why records: a source-local polymorphic stand-in gets clang's own vftable natively, whose slots name stand-in
// members nothing defines (CLAUDE.md). Here the object is a record (the vftable word, Function's fields from
// include/decls/data/script.h, the member-function pointer, the object) and its constructor stores the game's
// vftables by address, as the game's inlined constructors do: Method<N>'s, then Closure<N>'s. Natively those are the
// game vftables native_mac emits (code_owned64), whose slots are the tree's own definitions (the scalar deleting
// destructor, Function::vfunc_1 0x001d04c0, the instantiation's vfunc_2), so ScriptHandler's call through slot 2
// (0x001d22a0) reaches the tree's invoke function.
//
// What the game does (0x000b0500, the haptic manager, inlines three of them): `new` is the class's operator new, the
// game heap's allocation 0x0008d690 (declared throw(): the new-expression tests the result); Function's constructor
// 0x001d0480 (name, argc; key 0; Function's vftable) is out of line; then the instantiation's vftable, the member-function
// pointer, the type codes of the result and the arguments (0x001d04d0 of each type's type_info), the next vftable, the
// object. sizeof(ScriptClosure<N>) is the allocation size (0x24 on 32-bit, ScriptClosureView's).
//
// The constructors are throw(): in a TU that keeps /GX for its `??_G` blocks (D24) a new-expression would otherwise get
// an unwind frame the game's code has none of.
//
// Only the TUs that build script functions include this header (not common.h: CLAUDE.md on large header additions).
// Its names live in namespace hulk_script, so they never meet a TU's own stubs; the C names it declares are the
// definitions' own (extern "C").
#ifndef TREE_GAME_SCRIPT_BIND_H
#define TREE_GAME_SCRIPT_BIND_H

#include "compat/ptr.h"
#include "decls/data/script.h"

namespace hulk_script {

// The game heap's allocation 0x0008d690 (unk_08ceb0) and the type code of a type_info 0x001d04d0 (Function.cpp), by
// their address names. C++ names in this namespace, not the definitions' extern "C" ones: TUs declare those C names
// with other types (clang refuses a second extern "C" declaration of another type); the links bind the address names.
void* __cdecl FUN_0008d690(unsigned int size);
char __cdecl FUN_001d04d0(const void* typeInfo);

// The type_info records 0x001d04d0 classifies (its code in the comment). A source binding another type adds a
// specialization of ScriptType in its own TU (`template <> struct hulk_script::ScriptType<X> { ... };`).
extern char DAT_0048e100[];   // void          'v'
extern char DAT_0048e0e4[];   // bool          'b'
extern char DAT_0048e0f0[];   // const char*   's'
extern char DAT_0049cad8[];   // char*         's'
extern char DAT_0048e134[];   // int           'i'
extern char DAT_0049b95c[];   // unsigned int  'i'
extern char DAT_0048e128[];   // float         'f'
extern char DAT_0048e10c[];   // math::Vector  'V'

template <class T> struct ScriptType;
template <> struct ScriptType<void> { static const void* tag() { return DAT_0048e100; } };
template <> struct ScriptType<bool> { static const void* tag() { return DAT_0048e0e4; } };
template <> struct ScriptType<const char*> { static const void* tag() { return DAT_0048e0f0; } };
template <> struct ScriptType<char*> { static const void* tag() { return DAT_0049cad8; } };
template <> struct ScriptType<int> { static const void* tag() { return DAT_0048e134; } };
template <> struct ScriptType<unsigned int> { static const void* tag() { return DAT_0049b95c; } };
template <> struct ScriptType<float> { static const void* tag() { return DAT_0048e128; } };

// Function's constructor 0x001d0480 (Function.cpp), named by its address: the class is empty, so it adds nothing to the
// record that derives from it (its `this` is the record's).
struct FUN_001d0480 {
    FUN_001d0480(const char* name, int argc);
};

// Function (0x1c bytes on 32-bit): the vftable word, then Function's fields. Its operator new is the game heap's.
struct ScriptFunction : FUN_001d0480 {
    void* vftable;
    ScriptFunctionFields f;
    static void* operator new(hulk_uintptr size) throw() { return FUN_0008d690((unsigned int)size); }
    static void* operator new(hulk_uintptr, void* p) throw() { return p; }
    ScriptFunction(const char* name, int argc) throw() : FUN_001d0480(name, argc) {}
};

// Method<N> (0x20 bytes on 32-bit): Function, then the bound member-function pointer (C a complete class: single
// inheritance, one code pointer). vft is the instantiation's game vftable (`DAT_<addr>` / `hulk_at_<addr>`).
template <class C, class Fn>
struct ScriptMethodBase : ScriptFunction {
    Fn fn;
    ScriptMethodBase(const char* name, int argc, const void* vft, Fn f) throw() : ScriptFunction(name, argc) {
        vftable = (void*)vft;
        fn = f;
    }
};

template <class C, class R>
struct ScriptMethod0 : ScriptMethodBase<C, R (C::*)()> {
    typedef R (C::*Fn)();
    ScriptMethod0(const char* name, const void* vft, Fn f) throw() : ScriptMethodBase<C, Fn>(name, 0, vft, f) {
        this->f.retType = FUN_001d04d0(ScriptType<R>::tag());
    }
};
template <class C, class R, class A0>
struct ScriptMethod1 : ScriptMethodBase<C, R (C::*)(A0)> {
    typedef R (C::*Fn)(A0);
    ScriptMethod1(const char* name, const void* vft, Fn f) throw() : ScriptMethodBase<C, Fn>(name, 1, vft, f) {
        this->f.retType = FUN_001d04d0(ScriptType<R>::tag());
        this->f.argTypes[0] = FUN_001d04d0(ScriptType<A0>::tag());
    }
};
template <class C, class R, class A0, class A1>
struct ScriptMethod2 : ScriptMethodBase<C, R (C::*)(A0, A1)> {
    typedef R (C::*Fn)(A0, A1);
    ScriptMethod2(const char* name, const void* vft, Fn f) throw() : ScriptMethodBase<C, Fn>(name, 2, vft, f) {
        this->f.retType = FUN_001d04d0(ScriptType<R>::tag());
        this->f.argTypes[0] = FUN_001d04d0(ScriptType<A0>::tag());
        this->f.argTypes[1] = FUN_001d04d0(ScriptType<A1>::tag());
    }
};
template <class C, class R, class A0, class A1, class A2>
struct ScriptMethod3 : ScriptMethodBase<C, R (C::*)(A0, A1, A2)> {
    typedef R (C::*Fn)(A0, A1, A2);
    ScriptMethod3(const char* name, const void* vft, Fn f) throw() : ScriptMethodBase<C, Fn>(name, 3, vft, f) {
        this->f.retType = FUN_001d04d0(ScriptType<R>::tag());
        this->f.argTypes[0] = FUN_001d04d0(ScriptType<A0>::tag());
        this->f.argTypes[1] = FUN_001d04d0(ScriptType<A1>::tag());
        this->f.argTypes[2] = FUN_001d04d0(ScriptType<A2>::tag());
    }
};
template <class C, class R, class A0, class A1, class A2, class A3>
struct ScriptMethod4 : ScriptMethodBase<C, R (C::*)(A0, A1, A2, A3)> {
    typedef R (C::*Fn)(A0, A1, A2, A3);
    ScriptMethod4(const char* name, const void* vft, Fn f) throw() : ScriptMethodBase<C, Fn>(name, 4, vft, f) {
        this->f.retType = FUN_001d04d0(ScriptType<R>::tag());
        this->f.argTypes[0] = FUN_001d04d0(ScriptType<A0>::tag());
        this->f.argTypes[1] = FUN_001d04d0(ScriptType<A1>::tag());
        this->f.argTypes[2] = FUN_001d04d0(ScriptType<A2>::tag());
        this->f.argTypes[3] = FUN_001d04d0(ScriptType<A3>::tag());
    }
};

template <class C, class R, class A0, class A1, class A2, class A3, class A4>
struct ScriptMethod5 : ScriptMethodBase<C, R (C::*)(A0, A1, A2, A3, A4)> {
    typedef R (C::*Fn)(A0, A1, A2, A3, A4);
    ScriptMethod5(const char* name, const void* vft, Fn f) throw() : ScriptMethodBase<C, Fn>(name, 5, vft, f) {
        this->f.retType = FUN_001d04d0(ScriptType<R>::tag());
        this->f.argTypes[0] = FUN_001d04d0(ScriptType<A0>::tag());
        this->f.argTypes[1] = FUN_001d04d0(ScriptType<A1>::tag());
        this->f.argTypes[2] = FUN_001d04d0(ScriptType<A2>::tag());
        this->f.argTypes[3] = FUN_001d04d0(ScriptType<A3>::tag());
        this->f.argTypes[4] = FUN_001d04d0(ScriptType<A4>::tag());
    }
};

// Closure<N> (0x24 bytes on 32-bit): Method<N>, then the object the member function is called on. mvft / cvft are the
// instantiation's Method<N> and Closure<N> game vftables (the game's inlined constructors store both, in that order).
template <class M, class C>
struct ScriptClosure : M {
    C* owner;
    ScriptClosure(const char* name, C* o, typename M::Fn fn, const void* mvft, const void* cvft) throw() : M(name, mvft, fn) {
        this->vftable = (void*)cvft;
        owner = o;
    }
};

// The vftable word alone, for a source whose Function view derives from ScriptFunctionFields (unqualified field names):
// `struct Function : hulk_script::ScriptVftable, ScriptFunctionFields` has the vftable at 0 and the fields after it.
struct ScriptVftable {
    void* vftable;
};

// ScriptHandler's registration (0x001d3b70: name, function) on the singleton 0x001d4c90 returns.
struct ScriptRegistry {
    void FUN_001d3b70(const char* name, void* function);
};

}  // namespace hulk_script

// The 32-bit layout (a compile error on the 32-bit builds when a size differs from the XBE's).
struct ScriptBindLayout32 {
    struct C_ {};
    SCRIPT_CHECK32(method, sizeof(hulk_script::ScriptMethod1<C_, void, int>) == 0x20);
    SCRIPT_CHECK32(closure, sizeof(hulk_script::ScriptClosure<hulk_script::ScriptMethod1<C_, void, int>, C_>) == 0x24);
};

#endif
