class C { public: int Find(int); bool Set(int key, int a, int b); };
bool C::Set(int key, int a, int b) {
    int n = Find(key);
    if (n < 0) return false;
    ((char*)this)[(n + 0x226) * 16] = (char)a;
    ((char*)this)[n * 16 + 0x2261] = (char)b;
    return true;
}