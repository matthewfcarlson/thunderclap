struct Child { void cleanup(); };
struct Obj { char pad[5]; bool flag; char pad2[2]; Child* ptr; void run(); };
void tail();
void Obj::run() { if (ptr) ptr->cleanup(); if (flag) tail(); }
