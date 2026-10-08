typedef unsigned char byte;
void __cdecl ReleaseThing(void*);
class Thing { public: void* mValue; Thing* Destroy(byte flags); };
Thing* Thing::Destroy(byte flags) {
    if (mValue != 0) ReleaseThing(mValue);
    if ((flags & 1) != 0) ReleaseThing(this);
    return this;
}