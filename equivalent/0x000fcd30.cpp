// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000fcd30 @ 0x000fcd30
extern unsigned char DAT_004e0a90;
struct FUN_000fc760 {
 virtual void slot0();
 char pad04[0x58];
 int field5c, field60;
 float field64;
 FUN_000fc760(int arg);
};
struct CControllerAgent : FUN_000fc760 {
 virtual void slot0();
 float field68;
 unsigned char field6c, field6d;
 char pad6e[2];
 int field70, field74;
 float field78;
 int field7c;
 float field80;
 int field84;
 float values[6];
 unsigned char fielda0, fielda1;
 char pada2[0x32];
 int fieldd4;
 CControllerAgent(int arg);
};
CControllerAgent::CControllerAgent(int arg) : FUN_000fc760(arg) {
 for(int i=0;i<6;++i) values[i]=-1.0f;
 unsigned char initialized=DAT_004e0a90;
 field6c=0; field74=0; field84=0; fielda0=0; fielda1=0; fieldd4=0;
 field68=0.2f; field6d=1; field70=-1; field78=0.01f; field7c=1; field80=0.1f;
 field5c=0; field60=0; field64=1.0f;
 if(!initialized) DAT_004e0a90=1;
}