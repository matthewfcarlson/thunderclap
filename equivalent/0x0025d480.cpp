// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0025d480 @ 0x0025d480
struct Buffer_25d480 { unsigned int header; char data[256]; };
extern void __cdecl FUN_0025be60(unsigned int, Buffer_25d480*);
extern void __cdecl FUN_0025c320(Buffer_25d480*, void*, unsigned int, unsigned int);
extern unsigned int __cdecl FUN_0024c590(Buffer_25d480*, unsigned int);
extern unsigned int __cdecl FUN_0025be80(unsigned int, Buffer_25d480*);
extern unsigned int __cdecl FUN_0026fd50(unsigned int, unsigned int);
struct Context;
struct Handler_25d480 { virtual unsigned int invoke(Context*, Buffer_25d480*, void*, unsigned int); };
struct Context { char pad0[0x8c]; unsigned int value; char pad90[0x1c]; Handler_25d480* handler; char padb0[4]; unsigned char flags; };
struct Owner_25d480 { char pad[0x44]; void* data; };
struct Target_25d480 { char pad0[4]; Owner_25d480* owner; char pad8[0x2c]; unsigned int result; char pad38[4]; Context* context; unsigned int FUN_0025d480(unsigned int arg); };
unsigned int Target_25d480::FUN_0025d480(unsigned int arg) {
 Buffer_25d480 buffer;
 FUN_0025be60(arg, &buffer);
 void* data = owner->data;
 if (!data) {
  unsigned int flags = context->flags;
  data = buffer.data;
  FUN_0025c320(&buffer, data, flags & 1, (flags >> 1) & 1);
 }
 unsigned int a = FUN_0024c590(&buffer, context->value);
 unsigned int b = FUN_0025be80(arg, &buffer);
 unsigned int c = FUN_0026fd50(a, b);
 Context* ctx = context;
 unsigned int r = ctx->handler->invoke(ctx, &buffer, data, c);
 result = r;
 return r;
}