extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
class ControllerBuffer { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual bool vfunc_7(void*); virtual void v8(); char pad4[0x10]; unsigned int mCapacity; unsigned int mSize; unsigned int mIndex; unsigned int mEnd; unsigned int* mBuffers; };
bool ControllerBuffer::vfunc_7(void* output) {
 if (mIndex == mEnd) return false;
 memcpy(output, (void*)mBuffers[mIndex], mSize);
 mIndex=(mIndex+1)%mCapacity; return true;
}