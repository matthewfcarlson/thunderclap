// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0002d440 @ 0x0002d440
struct CallbackObj {};
struct Args { unsigned a,b,c,d,e,f,g; };
typedef void (__fastcall *Callback)(CallbackObj*, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
void __cdecl FUN_0002d440(CallbackObj* object, const Args* args, unsigned unused, Callback callback)
{
    callback(object, 0, args->a, args->b, args->c, args->d, args->e, args->f, args->g);
}
