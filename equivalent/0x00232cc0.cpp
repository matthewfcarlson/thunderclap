// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 4/4)
// FUN_00232cc0 @ 0x00232cc0
// cl-flags: /GS
struct Reader {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
 virtual const char* filename();
 virtual int line();
};
extern "C" int __cdecl FUN_00267730(char*, unsigned, const char*, char*);
extern "C" int __cdecl FUN_00267760(char*, unsigned, const char*, ...);
extern void (__cdecl *DAT_004e5bb0)(const char*, Reader*, void*);
extern void* DAT_004e5bb4;
void __cdecl FUN_00232cc0(Reader* reader, const char* format, ...) {
 char message[1024];
 char fullMessage[1024];
 FUN_00267730(message, 1024, format, (char*)(&format + 1));
 const char* name = reader->filename();
 if (!name) name = "";
 FUN_00267760(fullMessage, 1024, "fight::Reader ERROR\n%s(%d):  %s\n", name, reader->line(), message);
 if (DAT_004e5bb0) DAT_004e5bb0(fullMessage, reader, DAT_004e5bb4);
}
