// STATUS: equivalent (tools/equiv.py level 3: 3096 inputs, branch coverage 36/48, incomplete)
// hulkfight::ChapterMissionCondition::vfunc_6 @ 0x0012f200
struct MissionState { int FUN_00088fa0(); int FUN_00088fb0(); };
struct Mission { char pad[0x80]; MissionState state; };
struct Manager { Mission* FUN_00086310(); };
struct Root { char pad[0x54]; Manager* manager; };
extern Root* DAT_004dd700;
namespace hulkfight {
struct ChapterMissionCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual int vfunc_6(int,int,int);
 char pad[8]; int chapterOperator; int chapter; int missionOperator; int mission;
};
int ChapterMissionCondition::vfunc_6(int,int,int) {
 bool a=true,b=true;
 Mission* current=DAT_004dd700->manager->FUN_00086310();
 if(chapter>=0) {
 int value=current->state.FUN_00088fa0();
 switch(chapterOperator) {
 case 0:a=value<chapter;break;
 case 1:a=value<=chapter;break;
 case 2:a=value==chapter;break;
 case 3:a=value!=chapter;break;
 case 4:a=value>=chapter;break;
 case 5:a=value>chapter;break;
 default:a=false;break;
 }
 }
 if(mission>=0) {
 int value=current->state.FUN_00088fb0();
 switch(missionOperator) {
 case 0:b=value<mission;break;
 case 1:b=value<=mission;break;
 case 2:b=value==mission;break;
 case 3:b=value!=mission;break;
 case 4:b=value>=mission;break;
 case 5:b=value>mission;break;
 default:b=false;break;
 }
 }
 return a && b ? 1:0;
}
}