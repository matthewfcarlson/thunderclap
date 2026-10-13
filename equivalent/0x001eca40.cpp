// STATUS: equivalent (tools/equiv.py level 3: 3028 inputs, branch coverage 16/16)
// FUN_001eca40 @ 0x001eca40
extern unsigned int DAT_004d9968;
// equiv-conv: __security_check_cookie ecx
void __security_check_cookie(unsigned int);
struct Detail { char pad[0x14]; int type; };
struct Object { char pad[0x11c]; Detail* detail; };
struct Controller { void FUN_001ec980(Object*, const char*); void FUN_001eca40(Object*,Object*,const char*); };
void Controller::FUN_001eca40(Object* first, Object* second, const char* sound) {
 unsigned int cookie = DAT_004d9968;
 if (first && first->detail && second && second->detail) {
 FUN_001ec980(first,sound);
 char selected[16] = {0};
 int type = first->detail->type;
 const char* source;
 if (type != 1 && type != 2) source = "impact_sml";
 else {
 const char* match="whiff";
 int i;
 for(i=0;i<6;++i) if(sound[i]!=match[i]) break;
 source = i==6 ? sound : "impact_big";
 }
 int i=0;
 do { selected[i]=source[i]; } while(source[i++] != 0);
 FUN_001ec980(second,selected);
 }
 __security_check_cookie(cookie);
}
