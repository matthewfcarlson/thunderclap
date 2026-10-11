// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00333f10 @ 0x00333f10
extern unsigned int DAT_004cdbb0;
void __cdecl FUN_002705f0();
namespace core {
struct Object {
 virtual void slot0();
 unsigned int id;
 Object() : id(DAT_004cdbb0) { FUN_002705f0(); }
};
struct RefCount : Object {
 unsigned int references;
 RefCount() : references(0) { FUN_002705f0(); }
};
}
namespace movie {
struct Player2 { virtual void slot0(); };
struct PlayerBink : Player2, core::RefCount {
 unsigned int a,b,c,d;
 float scale;
 bool flag1,flag2;
 PlayerBink();
 virtual void slot0();
};
}
extern movie::PlayerBink* DAT_00555ba4;
movie::PlayerBink::PlayerBink() : a(0),b(0),c(0),d(0),scale(1.0f),flag1(false),flag2(false) { DAT_00555ba4=this; }
