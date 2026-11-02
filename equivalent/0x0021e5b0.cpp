// STATUS: equivalent (tools/equiv.py level 3: 6659 inputs, branch coverage 6/6)
// FUN_0021e5b0 @ 0x0021e5b0
// FUN_0021e5b0 @ 0x0021e5b0
#include "compat/ptr.h"
struct Scope_21e5b0 { Scope_21e5b0* previous; int saved; unsigned char mode, changed, active; };
struct Context { char p0[12]; int device; char p10[4]; Scope_21e5b0* scope; char p18[12]; int modeValue; char p28[12]; unsigned char mode; };
struct Parser_21e5b0 { int unknown; int position; int savedPosition; int token; int value; int nextToken; int nextValue; Context* context; };
struct Result_21e5b0 { int kind; int a; int b; int c; int d; };
extern "C" int __cdecl FUN_00220530(void *);
extern "C" int __cdecl FUN_0021bbc0(void *, void *);
// equiv-conv: FUN_0021e080 eax
extern "C" void __cdecl FUN_0021e080(void *);
// equiv-conv: FUN_0021c340 eax esi edi stack
void FUN_0021c340(int, Parser_21e5b0*, int, int);
extern "C" int __cdecl FUN_0021ded0(void *, void *, unsigned int);
extern "C" void __cdecl FUN_002214b0(void *, void *);
void __cdecl FUN_00220d70(Context*, int);
extern "C" void __cdecl FUN_00221ae0(void *, int, int);
// equiv-conv: FUN_0021c5b0 eax edx
extern "C" void __cdecl FUN_0021c5b0(void *, int);
extern "C" int __cdecl FUN_00220bd0(void *, unsigned int, int, unsigned int, unsigned int);
// equiv-conv: FUN_0021e5b0 eax stack
extern "C" void FUN_0021e5b0(void * parser_, int argument) {
    Parser_21e5b0 * parser = (Parser_21e5b0 *)parser_;
 Context* context = parser->context;
 int saved = FUN_00220530((Context *)context);
 Scope_21e5b0 scope;
 scope.saved = -1;
 scope.active = 1;
 scope.mode = context->mode;
 scope.changed = 0;
 scope.previous = context->scope;
 context->scope = &scope;
 parser->savedPosition = parser->position;
 if (parser->nextToken != 0x11f) {
 parser->token = parser->nextToken;
 parser->value = parser->nextValue;
 parser->nextToken = 0x11f;
 } else parser->token = FUN_0021bbc0((Parser_21e5b0 *)parser, (int *)(&parser->value));
 FUN_0021e080((Parser_21e5b0 *)parser);
 FUN_0021c340(argument, parser, 0x114, 0x110);
 Result_21e5b0 result;
 FUN_0021ded0((Parser_21e5b0 *)parser, (Result_21e5b0 *)(&result), 0);
 if (result.kind == 1) result.kind = 3;
 FUN_002214b0((Context *)(parser->context), (Result_21e5b0 *)(&result));
 FUN_00220d70(parser->context, result.c);
 FUN_00221ae0((Context *)context, result.d, saved);
 Scope_21e5b0* current = context->scope;
 context->scope = current->previous;
 FUN_0021c5b0((void *)(hulk_uintptr)(int)(context->device), (unsigned int)(current->mode));
 if (current->changed) FUN_00220bd0((Context *)context, 0x22, (unsigned int)(current->mode), 0, 0);
 context->modeValue = context->mode;
 FUN_00220d70(context, current->saved);
}
