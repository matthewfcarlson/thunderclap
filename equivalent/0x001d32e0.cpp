// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method4<ScriptHandler,void,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_2 @ 0x001d32e0
#include "gen/global.h"

struct ScriptHandler_1d32e0 { void invoke(const char *, const char *, const char *, const char *); }; typedef void (ScriptHandler_1d32e0::*HandlerMethod)(const char *, const char *, const char *, const char *);  
template <> void Method4<ScriptHandler, void, const char *, const char *, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { ScriptHandler_1d32e0 * handler = (ScriptHandler_1d32e0 *)__p0; const char ** args = (const char **)__p1; void * unused = (void *)__p2;
 (handler->*(*(HandlerMethod *)&this->f_1c))(args[0], args[1], args[2], args[3]); }
