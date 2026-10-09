struct Helper { void Run(); };
struct Thing { char pad[8]; Helper sub; Thing* F(unsigned char); };
void __cdecl thunk_FUN_00267090(Thing*);
Thing* Thing::F(unsigned char flags) { sub.Run(); ((Helper*)this)->Run(); if (flags & 1) thunk_FUN_00267090(this); return this; }