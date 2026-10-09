class Obj { public: char pad[0x64]; unsigned int flags; char p68[0xA0]; char p108[12]; unsigned char flag114; };
extern "C" unsigned int __cdecl helper(unsigned int, unsigned int, unsigned int);
void __cdecl target(Obj* self, unsigned int a, unsigned int b) {
 if (self->flag114 & 32) { if ((self->flags & 0x300) != 0x300) goto work; return; }
 if (self->flags & 0x800) return;
 work: *(unsigned int*)((char*)self+0x108)=helper(*(unsigned int*)((char*)self+0x108),a,b);
}