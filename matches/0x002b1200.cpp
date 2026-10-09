typedef unsigned char byte;
void __cdecl FUN_00267090(void*);
void __cdecl FUN_00267094(void*);
class Thing { public: void* mValue; Thing* Destroy(byte flags); };
Thing* Thing::Destroy(byte flags) {
    if (mValue != 0) FUN_00267090(mValue);
    if ((flags & 1) != 0) FUN_00267094(this);
    return this;
}
