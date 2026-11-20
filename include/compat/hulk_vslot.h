// A virtual slot called through a vftable pointer loaded earlier (fix126, D146; integ3's design).
//
// Some of the game's code loads an object's vftable pointer, makes another call (an argument's), then re-reads the
// object pointer and calls the OLD vftable's slot with the NEW object: `mov ebx,[ecx] ... call X ... mov ecx,[esi+8];
// call [ebx+0xc]`. Where that other call can change the object (slot 16 of ContentStreamFile writes it), a plain
// `obj->f(arg())` is not the same code. hulk_slot<F>(vt, k) turns slot k of the preloaded table into a member
// function pointer of type F = R (T::*)(Args...), called as `(obj->*hulk_slot<F>(vt, k))(args)`.
//
// Every target uses the Microsoft C++ ABI (MSVC 7.1 on i386; the native builds' *-windows-msvc front ends), where a
// pointer to a member function of a complete class with single inheritance and no virtual bases is exactly one code
// pointer: the union below then reads the slot as that pointer. The class must be complete where F is formed (else
// MSVC picks the general, larger representation; a forward declaration would need `class __single_inheritance T;`).
// The size check refuses any other representation.
// Natively the slot index k is the same Microsoft vftable index (8-byte slots), so no 32-bit offset is baked in.
// Include it only in the TUs that use it (D74/D77: it declares a template, which MSVC 7.1 counts).
#ifndef HULK_COMPAT_VSLOT_H
#define HULK_COMPAT_VSLOT_H

template <class F>
inline F hulk_slot(void* const* vt, int k) {
    typedef char hulk_slot_is_one_pointer[sizeof(F) == sizeof(void*) ? 1 : -1];
    union {
        void* p;
        F m;
    } u;
    u.p = vt[k];
    return u.m;
}

// hulk_vcallN<F>(&objptr, vt, k, args...): call slot k of the preloaded table with the object read from *objptr only
// after every argument is evaluated (both compilers evaluate a call's arguments before entering it), as the original
// re-reads the object after an argument's call; a void slot. `(obj->*hulk_slot<F>(vt, k))(f())` would let clang read
// the object and the slot before f() runs.
template <class F, class T, class A1, class A2, class A3>
inline void hulk_vcall3(T* const* obj, void* const* vt, int k, A1 a1, A2 a2, A3 a3) {
    ((*obj)->*hulk_slot<F>(vt, k))(a1, a2, a3);
}
template <class F, class T, class A1, class A2, class A3, class A4>
inline void hulk_vcall4(T* const* obj, void* const* vt, int k, A1 a1, A2 a2, A3 a3, A4 a4) {
    ((*obj)->*hulk_slot<F>(vt, k))(a1, a2, a3, a4);
}

#endif
