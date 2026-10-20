// STATUS: equivalent (tools/equiv.py level 3: 3116 inputs, branch coverage 199/256, incomplete)
// CRangedAgent::vfunc_4 @ 0x00107c90
// mechanical lift of 0x00107c90 (work/big3/lift.py): frame array S[], register variables, gotos
#include "compat/ptr.h"
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"

#define PF8(x) (!((0x6996 >> ((((x) >> 4) ^ (x)) & 15)) & 1))
#define FSW(a, b) ((((a) != (a)) || ((b) != (b))) ? 0x4500 : (((a) > (b)) ? 0 : (((a) < (b)) ? 0x100 : 0x4000)))
extern "C" double sqrt(double);
struct R64 { unsigned lo; unsigned hi; };
struct Agent { void FUN_00107c90(void* a1, float a2, int a3); };
extern unsigned DAT_004dd700;
struct O {
    void FUN_000111b0(unsigned, unsigned);
    double FUN_000111f0();
    double FUN_00018990();
    unsigned FUN_00024190(unsigned);
    unsigned FUN_00024300(unsigned);
    unsigned FUN_00025d30(unsigned);
    void FUN_00029250(unsigned, unsigned, unsigned, unsigned);
    void FUN_000344b0(unsigned);
    unsigned FUN_00035ef0(unsigned);
    void FUN_00036ac0(unsigned);
    void FUN_0003ffa0(unsigned, unsigned);
    unsigned __int64 FUN_000443c0();
    unsigned FUN_000446c0(unsigned);
    void FUN_00059a50(unsigned);
    void FUN_00060170();
    unsigned FUN_00078750(unsigned, unsigned);
    double FUN_00078780();
    double FUN_000964e0();
    unsigned FUN_00099730();
    unsigned FUN_00099750();
    unsigned FUN_00099760();
    unsigned FUN_00099790();
    unsigned FUN_000fc800();
    double FUN_000fc830();
    unsigned FUN_000fc850();
    void FUN_000fde40(unsigned);
    void FUN_000fde60(unsigned);
    unsigned FUN_000fefc0();
    void FUN_001048d0(unsigned);
    void FUN_00104c60(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
    unsigned FUN_00107410(unsigned, unsigned);
    unsigned FUN_00107760(unsigned, unsigned, unsigned, unsigned);
    unsigned FUN_001d6b40();
    void FUN_00202460(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
    void FUN_0022b170(unsigned, unsigned);
    void FUN_0022b650(unsigned);
    void FUN_0022b980();
    void FUN_0022c3b0(unsigned, unsigned);
    double FUN_0022d110();
    unsigned FUN_0022d2b0(unsigned, unsigned);
    unsigned FUN_00231ee0();
    unsigned FUN_0023f7b0(unsigned, unsigned, unsigned, unsigned);
    void FUN_0023f820(unsigned, unsigned, unsigned, unsigned);
    unsigned FUN_0027af50();
    unsigned FUN_0027af90(unsigned);
    void FUN_0027b040(unsigned);
    unsigned FUN_0027b0e0(unsigned);
    unsigned FUN_002ee140(unsigned, unsigned, unsigned, unsigned);
};
double __cdecl FUN_000186f0(unsigned, unsigned);
double __cdecl FUN_00018710(unsigned, unsigned);
unsigned __cdecl FUN_00036b10(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
unsigned __cdecl FUN_00065870(unsigned, unsigned);
unsigned __cdecl FUN_00083dd0(unsigned, unsigned, unsigned);
unsigned __cdecl FUN_00083e00(unsigned, unsigned, unsigned);
unsigned __cdecl FUN_000964d0();
void __cdecl FUN_00096a40(unsigned, unsigned);
double __cdecl FUN_0010ae50(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
double __cdecl FUN_0010b1c0(unsigned, unsigned, unsigned, unsigned);
unsigned __cdecl FUN_00202f00();
unsigned __int64 __cdecl FUN_0027b020(unsigned);
struct VC0 { virtual void vf0(); virtual void vf1(); virtual void vf2(); virtual void vf3(); virtual void vf4(); virtual void vf5(); virtual unsigned vcall(); };
struct VC1 { virtual void vf0(); virtual void vf1(); virtual void vf2(); virtual void vf3(); virtual void vf4(); virtual void vf5(); virtual void vf6(); virtual void vf7(); virtual void vf8(); virtual unsigned vcall(); };
struct VC2 { virtual void vf0(); virtual void vf1(); virtual void vf2(); virtual void vf3(); virtual void vf4(); virtual void vf5(); virtual unsigned vcall(); };
struct VC3 { virtual void vf0(); virtual void vf1(); virtual void vf2(); virtual void vf3(); virtual unsigned vcall(unsigned, unsigned, unsigned); };
struct VC4 { virtual void vf0(); virtual void vf1(); virtual void vf2(); virtual void vcall(unsigned, unsigned, unsigned, unsigned, unsigned); };
struct VC5 { virtual void vf0(); virtual void vf1(); virtual void vf2(); virtual void vf3(); virtual void vcall(unsigned, unsigned, unsigned); };
struct VC6 { virtual void vf0(); virtual void vf1(); virtual void vf2(); virtual void vf3(); virtual void vf4(); virtual void vf5(); virtual void vf6(); virtual void vcall(unsigned); };
struct VC7 { virtual void vf0(); virtual void vf1(); virtual void vf2(); virtual unsigned vcall(unsigned, unsigned, unsigned, unsigned, unsigned); };
struct VC8 { virtual void vf0(); virtual void vf1(); virtual void vf2(); virtual void vcall(unsigned, unsigned, unsigned, unsigned, unsigned); };
struct VC9 { virtual void vf0(); virtual void vf1(); virtual void vf2(); virtual void vcall(unsigned, unsigned, unsigned, unsigned, unsigned); };
void Agent::FUN_00107c90(void* a1, float a2, int a3)
{
    unsigned S[107];
    hulk_uintptr eax = 0, ebx = 0, ecx = (hulk_uintptr)this, edx = 0, esi = 0, edi = 0, ebp = 0;
    double fpk0;
    double fpk1;
    double fretv;
    float fl100;
    float fl101;
    float fl102;
    float fl103;
    float fl104;
    float fl105;
    float fl106;
    float fl107;
    float fl108;
    float fl109;
    float fl10;
    float fl110;
    float fl111;
    float fl112;
    float fl113;
    float fl114;
    float fl115;
    float fl116;
    float fl117;
    float fl118;
    float fl119;
    float fl11;
    float fl120;
    float fl121;
    float fl122;
    float fl123;
    float fl124;
    float fl125;
    float fl126;
    float fl127;
    float fl128;
    float fl129;
    float fl12;
    float fl130;
    float fl131;
    float fl132;
    float fl133;
    float fl134;
    float fl135;
    float fl136;
    float fl137;
    float fl138;
    float fl139;
    float fl13;
    float fl140;
    float fl141;
    float fl142;
    float fl143;
    float fl144;
    float fl145;
    float fl146;
    float fl147;
    float fl148;
    float fl149;
    float fl14;
    float fl150;
    float fl151;
    float fl152;
    float fl153;
    float fl154;
    float fl155;
    float fl156;
    float fl157;
    float fl158;
    float fl159;
    float fl15;
    float fl160;
    float fl161;
    float fl162;
    float fl163;
    float fl164;
    float fl165;
    float fl166;
    float fl167;
    float fl168;
    float fl169;
    float fl16;
    float fl170;
    float fl171;
    float fl172;
    float fl173;
    float fl174;
    float fl175;
    float fl176;
    float fl177;
    float fl178;
    float fl179;
    float fl17;
    float fl180;
    float fl181;
    float fl182;
    float fl183;
    float fl184;
    float fl185;
    float fl186;
    float fl187;
    float fl188;
    float fl189;
    float fl18;
    float fl190;
    float fl191;
    float fl192;
    float fl193;
    float fl194;
    float fl195;
    float fl196;
    float fl197;
    float fl198;
    float fl199;
    float fl19;
    float fl1;
    float fl200;
    float fl201;
    float fl202;
    float fl203;
    float fl204;
    float fl205;
    float fl206;
    float fl207;
    float fl208;
    float fl209;
    float fl20;
    float fl210;
    float fl211;
    float fl212;
    float fl213;
    float fl214;
    float fl215;
    float fl216;
    float fl21;
    float fl22;
    float fl23;
    float fl24;
    float fl25;
    float fl26;
    float fl27;
    float fl28;
    float fl29;
    float fl2;
    float fl30;
    float fl31;
    float fl32;
    float fl33;
    float fl34;
    float fl35;
    float fl36;
    float fl37;
    float fl38;
    float fl39;
    float fl3;
    float fl40;
    float fl41;
    float fl42;
    float fl43;
    float fl44;
    float fl45;
    float fl46;
    float fl47;
    float fl48;
    float fl49;
    float fl4;
    float fl50;
    float fl51;
    float fl52;
    float fl53;
    float fl54;
    float fl55;
    float fl56;
    float fl57;
    float fl58;
    float fl59;
    float fl5;
    float fl60;
    float fl61;
    float fl62;
    float fl63;
    float fl64;
    float fl65;
    float fl66;
    float fl67;
    float fl68;
    float fl69;
    float fl6;
    float fl70;
    float fl71;
    float fl72;
    float fl73;
    float fl74;
    float fl75;
    float fl76;
    float fl77;
    float fl78;
    float fl79;
    float fl7;
    float fl80;
    float fl81;
    float fl82;
    float fl83;
    float fl84;
    float fl85;
    float fl86;
    float fl87;
    float fl88;
    float fl89;
    float fl8;
    float fl90;
    float fl91;
    float fl92;
    float fl93;
    float fl94;
    float fl95;
    float fl96;
    float fl97;
    float fl98;
    float fl99;
    float fl9;
    hulk_uintptr vo_eax;
    hulk_uintptr vo_ecx;
    hulk_uintptr vo_edx;
    S[99] = 0;
    S[100] = (hulk_uintptr)a1;
    *(float*)&S[101] = a2;
    S[102] = (unsigned)a3;
  /*0000 sub esp, 0x14c*/
  /*0006 push ebx*/
    *(unsigned*)((char*)S + 60) = ebx;
  /*0007 push esi*/
    *(unsigned*)((char*)S + 56) = esi;
  /*0008 mov esi, ecx*/
    esi = ecx;
  /*000a call FUN_000964d0*/
    eax = (unsigned)FUN_000964d0();
  /*000f mov ecx, dword ptr [esi + 0x58]*/
    ecx = (*(unsigned*)((char*)(esi + 88)));
  /*0012 mov dword ptr [esp + 0xe8], eax*/
    *(unsigned*)((char*)S + 288) = eax;
  /*0019 mov eax, dword ptr [ecx]*/
    vo_eax = ecx;
    eax = (*(unsigned*)((char*)(ecx)));
  /*001b call dword ptr [eax + 0x18]*/
    eax = (unsigned)((VC0*)vo_eax)->vcall();
  /*001e mov ebx, eax*/
    ebx = eax;
  /*0020 test ebx, ebx*/
  /*0022 mov dword ptr [esp + 0x54], ebx*/
    *(unsigned*)((char*)S + 140) = ebx;
  /*0026 je 1d42*/
    if ((unsigned)((ebx & ebx)) == 0) goto L_1d42;
  /*002c mov eax, dword ptr [ebx + 0x11c]*/
    eax = (*(unsigned*)((char*)(ebx + 284)));
  /*0032 test eax, eax*/
  /*0034 mov dword ptr [esp + 0x44], eax*/
    *(unsigned*)((char*)S + 124) = eax;
  /*0038 je 1d42*/
    if ((unsigned)((eax & eax)) == 0) goto L_1d42;
  /*003e mov eax, dword ptr [esi + 0x58]*/
    eax = (*(unsigned*)((char*)(esi + 88)));
  /*0041 add eax, 0x58*/
    eax = (unsigned)(eax + 88u);
  /*0044 mov dword ptr [esp + 0xc8], eax*/
    *(unsigned*)((char*)S + 256) = eax;
  /*004b je 1d42*/
    if ((unsigned)(eax) == 0) goto L_1d42;
  /*0051 mov eax, dword ptr [eax + 8]*/
    eax = (*(unsigned*)((char*)(eax + 8)));
  /*0054 test eax, eax*/
  /*0056 mov dword ptr [esp + 0x8c], eax*/
    *(unsigned*)((char*)S + 196) = eax;
  /*005d je 1d42*/
    if ((unsigned)((eax & eax)) == 0) goto L_1d42;
  /*0063 mov al, byte ptr [esp + 0x160]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 408))) & 0xff) << 0);
  /*006a test al, al*/
  /*006c je 007c*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) == 0) goto L_007c;
  /*006e mov byte ptr [esi + 0x6c], 0*/
    *(unsigned char*)((char*)(esi + 108)) = 0u;
  /*0072 mov dword ptr [esi + 0xac], 0*/
    *(unsigned*)((char*)(esi + 172)) = 0u;
L_007c:
  /*007c mov ecx, dword ptr [ebx + 0x1ca0]*/
    ecx = (*(unsigned*)((char*)(ebx + 7328)));
  /*0082 mov edx, dword ptr [ecx]*/
    vo_edx = ecx;
    edx = (*(unsigned*)((char*)(ecx)));
  /*0084 call dword ptr [edx + 0x24]*/
    eax = (unsigned)((VC1*)vo_edx)->vcall();
  /*0087 cmp eax, 4*/
  /*008a je 1d42*/
    if ((unsigned)(eax) == (unsigned)(4u)) goto L_1d42;
  /*0090 push ebp*/
    *(unsigned*)((char*)S + 52) = ebp;
  /*0091 push edi*/
    *(unsigned*)((char*)S + 48) = edi;
  /*0092 lea edi, [ebx + 0x1f58]*/
    edi = (hulk_uintptr)((char*)(ebx + 8024));
  /*0098 mov ecx, edi*/
    ecx = edi;
  /*009a call FUN_00060170*/
    ((O*)ecx)->FUN_00060170();
  /*009f mov ebp, dword ptr [esp + 0xd0]*/
    ebp = (*(unsigned*)((char*)S + 256));
  /*00a6 mov ecx, ebp*/
    ecx = ebp;
  /*00a8 mov byte ptr [esp + 0x11], 0*/
    *(unsigned char*)((char*)S + 65) = 0u;
  /*00ad call FUN_000fc800*/
    eax = (unsigned)((O*)ecx)->FUN_000fc800();
  /*00b2 mov ecx, ebp*/
    ecx = ebp;
  /*00b4 mov byte ptr [esp + 0x3f], al*/
    *(unsigned char*)((char*)S + 111) = (eax & 0xff);
  /*00b8 call FUN_000fc850*/
    eax = (unsigned)((O*)ecx)->FUN_000fc850();
  /*00bd mov ecx, dword ptr [0x4dd700]*/
    ecx = DAT_004dd700;
  /*00c3 mov byte ptr [esp + 0x12], al*/
    *(unsigned char*)((char*)S + 66) = (eax & 0xff);
  /*00c7 mov al, byte ptr [ebp + 0x70]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)(ebp + 112)))) & 0xff) << 0);
  /*00ca mov ebp, dword ptr [ecx + 8]*/
    ebp = (*(unsigned*)((char*)(ecx + 8)));
  /*00cd test ebp, ebp*/
  /*00cf mov byte ptr [esp + 0x62], al*/
    *(unsigned char*)((char*)S + 146) = (eax & 0xff);
  /*00d3 je 0106*/
    if ((unsigned)((ebp & ebp)) == 0) goto L_0106;
  /*00d5 mov ecx, ebp*/
    ecx = ebp;
  /*00d7 call FUN_00099730*/
    eax = (unsigned)((O*)ecx)->FUN_00099730();
  /*00dc test al, al*/
  /*00de jne 0101*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) != 0) goto L_0101;
  /*00e0 mov ecx, ebp*/
    ecx = ebp;
  /*00e2 call FUN_00099750*/
    eax = (unsigned)((O*)ecx)->FUN_00099750();
  /*00e7 test al, al*/
  /*00e9 jne 0101*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) != 0) goto L_0101;
  /*00eb mov ecx, ebp*/
    ecx = ebp;
  /*00ed call FUN_00099760*/
    eax = (unsigned)((O*)ecx)->FUN_00099760();
  /*00f2 test al, al*/
  /*00f4 jne 0101*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) != 0) goto L_0101;
  /*00f6 mov ecx, ebp*/
    ecx = ebp;
  /*00f8 call FUN_00099790*/
    eax = (unsigned)((O*)ecx)->FUN_00099790();
  /*00fd test al, al*/
  /*00ff je 0106*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) == 0) goto L_0106;
L_0101:
  /*0101 mov byte ptr [esp + 0x12], 0*/
    *(unsigned char*)((char*)S + 66) = 0u;
L_0106:
  /*0106 lea edx, [esp + 0xa8]*/
    edx = (hulk_uintptr)((char*)S + 216);
  /*010d push edx*/
    *(unsigned*)((char*)S + 44) = edx;
  /*010e mov ecx, ebx*/
    ecx = ebx;
  /*0110 mov dword ptr [esp + 0xac], 0*/
    *(unsigned*)((char*)S + 216) = 0u;
  /*011b mov dword ptr [esp + 0xb0], 0*/
    *(unsigned*)((char*)S + 220) = 0u;
  /*0126 mov dword ptr [esp + 0xb4], 0*/
    *(unsigned*)((char*)S + 224) = 0u;
  /*0131 call FUN_00036ac0*/
    ((O*)ecx)->FUN_00036ac0(*(unsigned*)((char*)S + 44));
  /*0136 mov ebp, dword ptr [esp + 0xd0]*/
    ebp = (*(unsigned*)((char*)S + 256));
  /*013d mov ecx, ebp*/
    ecx = ebp;
  /*013f mov dword ptr [esp + 0x64], 0*/
    *(unsigned*)((char*)S + 148) = 0u;
  /*0147 mov dword ptr [esp + 0x68], 0*/
    *(unsigned*)((char*)S + 152) = 0u;
  /*014f mov dword ptr [esp + 0x6c], 0*/
    *(unsigned*)((char*)S + 156) = 0u;
  /*0157 call FUN_000fc830*/
    fretv = ((O*)ecx)->FUN_000fc830();
  /*015c fcomp dword ptr [0x40d6fc]*/
  /*0162 fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fretv, 3.0f)) & 0xffff);
  /*0164 test ah, 5*/
  /*0167 jp 0213*/
    if (PF8((((eax >> 8) & 0xff) & 5u))) goto L_0213;
  /*016d mov ebp, dword ptr [esp + 0x94]*/
    ebp = (*(unsigned*)((char*)S + 196));
  /*0174 mov eax, dword ptr [ebp + 0x40]*/
    eax = (*(unsigned*)((char*)(ebp + 64)));
  /*0177 mov ecx, dword ptr [ebp + 0x44]*/
    ecx = (*(unsigned*)((char*)(ebp + 68)));
  /*017a mov edx, dword ptr [ebp + 0x48]*/
    edx = (*(unsigned*)((char*)(ebp + 72)));
  /*017d mov dword ptr [esp + 0x7c], eax*/
    *(unsigned*)((char*)S + 172) = eax;
  /*0181 lea eax, [esp + 0x24]*/
    eax = (hulk_uintptr)((char*)S + 84);
  /*0185 mov dword ptr [esp + 0x80], ecx*/
    *(unsigned*)((char*)S + 176) = ecx;
  /*018c mov ecx, dword ptr [esp + 0xd0]*/
    ecx = (*(unsigned*)((char*)S + 256));
  /*0193 push eax*/
    *(unsigned*)((char*)S + 44) = eax;
  /*0194 mov dword ptr [esp + 0x88], edx*/
    *(unsigned*)((char*)S + 180) = edx;
  /*019b call FUN_000fde40*/
    ((O*)ecx)->FUN_000fde40(*(unsigned*)((char*)S + 44));
  /*01a0 fld dword ptr [esp + 0x24]*/
    fl1 = *(float*)((char*)S + 84);
  /*01a4 fsub dword ptr [esp + 0x7c]*/
    fl2 = *(float*)((char*)S + 172);
  /*01a8 lea ecx, [esp + 0x64]*/
    ecx = (hulk_uintptr)((char*)S + 148);
  /*01ac push ecx*/
    *(unsigned*)((char*)S + 44) = ecx;
  /*01ad push ebp*/
    *(unsigned*)((char*)S + 40) = ebp;
  /*01ae fstp dword ptr [esp + 0x48]*/
    *(float*)((char*)S + 112) = (float)(((fl1) - (fl2)));
  /*01b2 fld dword ptr [esp + 0x30]*/
    fl3 = *(float*)((char*)S + 88);
  /*01b6 fsub dword ptr [esp + 0x88]*/
    fl4 = *(float*)((char*)S + 176);
  /*01bd fstp dword ptr [esp + 0x4c]*/
    *(float*)((char*)S + 116) = (float)(((fl3) - (fl4)));
  /*01c1 fld dword ptr [esp + 0x34]*/
    fl5 = *(float*)((char*)S + 92);
  /*01c5 fsub dword ptr [esp + 0x8c]*/
    fl6 = *(float*)((char*)S + 180);
  /*01cc fstp dword ptr [esp + 0x50]*/
    *(float*)((char*)S + 120) = (float)(((fl5) - (fl6)));
  /*01d0 call FUN_00096a40*/
    FUN_00096a40(*(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*01d5 mov eax, dword ptr [ebp + 0xc]*/
    eax = (*(unsigned*)((char*)(ebp + 12)));
  /*01d8 fld dword ptr [esp + 0x70]*/
    fl7 = *(float*)((char*)S + 152);
  /*01dc add esp, 8*/
  /*01df cmp eax, 1*/
  /*01e2 jne 01ea*/
    fpk0 = fl7;
    // WARNING fp stack live (1) at 01e2
    if ((unsigned)(eax) != (unsigned)(1u)) goto L_01ea;
  /*01e4 fsub dword ptr [0x3f32dc]*/
    fpk0 = ((fpk0) - (1.0f));
    // WARNING fp stack live (1) at 01ea
L_01ea:
  /*01ea fld dword ptr [esp + 0x40]*/
    fl8 = *(float*)((char*)S + 112);
  /*01ee fadd dword ptr [esp + 0x64]*/
    fl9 = *(float*)((char*)S + 148);
  /*01f2 fstp dword ptr [esp + 0x64]*/
    *(float*)((char*)S + 148) = (float)(((fl8) + (fl9)));
  /*01f6 fld dword ptr [esp + 0x44]*/
    fl10 = *(float*)((char*)S + 116);
  /*01fa fadd st(1)*/
  /*01fc fstp dword ptr [esp + 0x68]*/
    *(float*)((char*)S + 152) = (float)(((fl10) + (fpk0)));
  /*0200 fstp st(0)*/
  /*0202 fld dword ptr [esp + 0x6c]*/
    fl11 = *(float*)((char*)S + 156);
  /*0206 fadd dword ptr [esp + 0x48]*/
    fl12 = *(float*)((char*)S + 120);
  /*020a fstp dword ptr [esp + 0x6c]*/
    *(float*)((char*)S + 156) = (float)(((fl11) + (fl12)));
  /*020e jmp 02ec*/
    goto L_02ec;
L_0213:
  /*0213 lea edx, [esp + 0x64]*/
    edx = (hulk_uintptr)((char*)S + 148);
  /*0217 push edx*/
    *(unsigned*)((char*)S + 44) = edx;
  /*0218 mov ecx, ebp*/
    ecx = ebp;
  /*021a call FUN_000fde40*/
    ((O*)ecx)->FUN_000fde40(*(unsigned*)((char*)S + 44));
  /*021f lea eax, [esp + 0x24]*/
    eax = (hulk_uintptr)((char*)S + 84);
  /*0223 push eax*/
    *(unsigned*)((char*)S + 44) = eax;
  /*0224 lea ecx, [esp + 0x68]*/
    ecx = (hulk_uintptr)((char*)S + 148);
  /*0228 push ecx*/
    *(unsigned*)((char*)S + 40) = ecx;
  /*0229 mov dword ptr [esp + 0x2c], 0*/
    *(unsigned*)((char*)S + 84) = 0u;
  /*0231 mov dword ptr [esp + 0x30], 0*/
    *(unsigned*)((char*)S + 88) = 0u;
  /*0239 mov dword ptr [esp + 0x34], 0*/
    *(unsigned*)((char*)S + 92) = 0u;
  /*0241 call FUN_00065870*/
    eax = (unsigned)FUN_00065870(*(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*0246 add esp, 8*/
  /*0249 test al, al*/
  /*024b je 0266*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) == 0) goto L_0266;
  /*024d mov ecx, ebp*/
    ecx = ebp;
  /*024f call FUN_000fc830*/
    fretv = ((O*)ecx)->FUN_000fc830();
  /*0254 fcomp dword ptr [0x40d6f8]*/
  /*025a fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fretv, 7.0f)) & 0xffff);
  /*025c test ah, 5*/
  /*025f jp 0266*/
    if (PF8((((eax >> 8) & 0xff) & 5u))) goto L_0266;
  /*0261 mov byte ptr [esp + 0x11], 1*/
    *(unsigned char*)((char*)S + 65) = 1u;
L_0266:
  /*0266 push 0x3727c5ac*/
    *(unsigned*)((char*)S + 44) = 925353388u;
  /*026b lea edx, [esp + 0x28]*/
    edx = (hulk_uintptr)((char*)S + 84);
  /*026f push edx*/
    *(unsigned*)((char*)S + 40) = edx;
  /*0270 lea ecx, [esp + 0x6c]*/
    ecx = (hulk_uintptr)((char*)S + 148);
  /*0274 mov dword ptr [esp + 0x2c], 0*/
    *(unsigned*)((char*)S + 84) = 0u;
  /*027c mov dword ptr [esp + 0x30], 0*/
    *(unsigned*)((char*)S + 88) = 0u;
  /*0284 mov dword ptr [esp + 0x34], 0*/
    *(unsigned*)((char*)S + 92) = 0u;
  /*028c call FUN_0022d2b0*/
    eax = (unsigned)((O*)ecx)->FUN_0022d2b0(*(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*0291 test al, al*/
  /*0293 je 02a1*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) == 0) goto L_02a1;
  /*0295 lea eax, [esp + 0x64]*/
    eax = (hulk_uintptr)((char*)S + 148);
  /*0299 push eax*/
    *(unsigned*)((char*)S + 44) = eax;
  /*029a mov ecx, ebp*/
    ecx = ebp;
  /*029c call FUN_000fde60*/
    ((O*)ecx)->FUN_000fde60(*(unsigned*)((char*)S + 44));
L_02a1:
  /*02a1 push 0x3727c5ac*/
    *(unsigned*)((char*)S + 44) = 925353388u;
  /*02a6 lea ecx, [esp + 0x28]*/
    ecx = (hulk_uintptr)((char*)S + 84);
  /*02aa push ecx*/
    *(unsigned*)((char*)S + 40) = ecx;
  /*02ab lea ecx, [esp + 0x6c]*/
    ecx = (hulk_uintptr)((char*)S + 148);
  /*02af mov dword ptr [esp + 0x2c], 0*/
    *(unsigned*)((char*)S + 84) = 0u;
  /*02b7 mov dword ptr [esp + 0x30], 0*/
    *(unsigned*)((char*)S + 88) = 0u;
  /*02bf mov dword ptr [esp + 0x34], 0*/
    *(unsigned*)((char*)S + 92) = 0u;
  /*02c7 call FUN_0022d2b0*/
    eax = (unsigned)((O*)ecx)->FUN_0022d2b0(*(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*02cc test al, al*/
  /*02ce je 02ec*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) == 0) goto L_02ec;
  /*02d0 mov eax, dword ptr [esp + 0x94]*/
    eax = (*(unsigned*)((char*)S + 196));
  /*02d7 mov edx, dword ptr [eax + 0x40]*/
    edx = (*(unsigned*)((char*)(eax + 64)));
  /*02da mov dword ptr [esp + 0x64], edx*/
    *(unsigned*)((char*)S + 148) = edx;
  /*02de mov ecx, dword ptr [eax + 0x44]*/
    ecx = (*(unsigned*)((char*)(eax + 68)));
  /*02e1 mov dword ptr [esp + 0x68], ecx*/
    *(unsigned*)((char*)S + 152) = ecx;
  /*02e5 mov edx, dword ptr [eax + 0x48]*/
    edx = (*(unsigned*)((char*)(eax + 72)));
  /*02e8 mov dword ptr [esp + 0x6c], edx*/
    *(unsigned*)((char*)S + 156) = edx;
L_02ec:
  /*02ec fld dword ptr [esp + 0x64]*/
    fl13 = *(float*)((char*)S + 148);
  /*02f0 lea ecx, [esp + 0xc4]*/
    ecx = (hulk_uintptr)((char*)S + 244);
  /*02f7 fsub dword ptr [esp + 0xa8]*/
    fl14 = *(float*)((char*)S + 216);
  /*02fe fstp dword ptr [esp + 0xc4]*/
    *(float*)((char*)S + 244) = (float)(((fl13) - (fl14)));
  /*0305 fld dword ptr [esp + 0x68]*/
    fl15 = *(float*)((char*)S + 152);
  /*0309 fsub dword ptr [esp + 0xac]*/
    fl16 = *(float*)((char*)S + 220);
  /*0310 fstp dword ptr [esp + 0xc8]*/
    *(float*)((char*)S + 248) = (float)(((fl15) - (fl16)));
  /*0317 fld dword ptr [esp + 0x6c]*/
    fl17 = *(float*)((char*)S + 156);
  /*031b fsub dword ptr [esp + 0xb0]*/
    fl18 = *(float*)((char*)S + 224);
  /*0322 fstp dword ptr [esp + 0xcc]*/
    *(float*)((char*)S + 252) = (float)(((fl17) - (fl18)));
  /*0329 call FUN_00018990*/
    fretv = ((O*)ecx)->FUN_00018990();
  /*032e mov ecx, dword ptr [esp + 0xcc]*/
    ecx = (*(unsigned*)((char*)S + 252));
  /*0335 fstp dword ptr [esp + 0x30]*/
    *(float*)((char*)S + 96) = (float)(fretv);
  /*0339 mov eax, dword ptr [esp + 0xc4]*/
    eax = (*(unsigned*)((char*)S + 244));
  /*0340 mov dword ptr [esp + 0x58], ecx*/
    *(unsigned*)((char*)S + 136) = ecx;
  /*0344 lea ecx, [esp + 0x50]*/
    ecx = (hulk_uintptr)((char*)S + 128);
  /*0348 mov dword ptr [esp + 0x50], eax*/
    *(unsigned*)((char*)S + 128) = eax;
  /*034c mov dword ptr [esp + 0x54], 0*/
    *(unsigned*)((char*)S + 132) = 0u;
  /*0354 call FUN_00018990*/
    fretv = ((O*)ecx)->FUN_00018990();
  /*0359 fstp dword ptr [esp + 0xec]*/
    *(float*)((char*)S + 284) = (float)(fretv);
  /*0360 lea ecx, [esp + 0xc4]*/
    ecx = (hulk_uintptr)((char*)S + 244);
  /*0367 call FUN_0022d110*/
    fretv = ((O*)ecx)->FUN_0022d110();
  /*036c fstp st(0)*/
  /*036e lea ecx, [esp + 0x50]*/
    ecx = (hulk_uintptr)((char*)S + 128);
  /*0372 call FUN_0022d110*/
    fretv = ((O*)ecx)->FUN_0022d110();
  /*0377 fstp st(0)*/
  /*0379 mov ebp, dword ptr [esp + 0x4c]*/
    ebp = (*(unsigned*)((char*)S + 124));
  /*037d push 0*/
    *(unsigned*)((char*)S + 44) = 0u;
  /*037f mov ecx, ebp*/
    ecx = ebp;
  /*0381 call FUN_000446c0*/
    eax = (unsigned)((O*)ecx)->FUN_000446c0(*(unsigned*)((char*)S + 44));
  /*0386 test eax, eax*/
  /*0388 je 03cd*/
    if ((unsigned)((eax & eax)) == 0) goto L_03cd;
  /*038a push 0*/
    *(unsigned*)((char*)S + 44) = 0u;
  /*038c mov ecx, ebp*/
    ecx = ebp;
  /*038e call FUN_000446c0*/
    eax = (unsigned)((O*)ecx)->FUN_000446c0(*(unsigned*)((char*)S + 44));
  /*0393 mov edx, dword ptr [eax + 8]*/
    edx = (*(unsigned*)((char*)(eax + 8)));
  /*0396 mov eax, dword ptr [eax + 0xc]*/
    eax = (*(unsigned*)((char*)(eax + 12)));
  /*0399 push 0x40d6e0*/
    *(unsigned*)((char*)S + 44) = 4249312u;
  /*039e mov dword ptr [esp + 0x9c], edx*/
    *(unsigned*)((char*)S + 200) = edx;
  /*03a5 mov dword ptr [esp + 0xa0], eax*/
    *(unsigned*)((char*)S + 204) = eax;
  /*03ac call FUN_0027b020*/
    { unsigned __int64 r64 = FUN_0027b020(*(unsigned*)((char*)S + 44)); eax = (unsigned)r64; edx = (unsigned)(r64 >> 32); }
  /*03b1 mov ecx, dword ptr [esp + 0x9c]*/
    ecx = (*(unsigned*)((char*)S + 200));
  /*03b8 add esp, 4*/
  /*03bb cmp ecx, eax*/
  /*03bd jne 03cd*/
    if ((unsigned)(ecx) != (unsigned)(eax)) goto L_03cd;
  /*03bf cmp dword ptr [esp + 0x9c], edx*/
  /*03c6 mov byte ptr [esp + 0x10], 1*/
    *(unsigned char*)((char*)S + 64) = 1u;
  /*03cb je 03d2*/
    if ((unsigned)((*(unsigned*)((char*)S + 204))) == (unsigned)(edx)) goto L_03d2;
L_03cd:
  /*03cd mov byte ptr [esp + 0x10], 0*/
    *(unsigned char*)((char*)S + 64) = 0u;
L_03d2:
  /*03d2 mov ecx, dword ptr [esp + 0x160]*/
    ecx = (*(unsigned*)((char*)S + 400));
  /*03d9 mov ecx, dword ptr [ecx + 0x20]*/
    ecx = (*(unsigned*)((char*)(ecx + 32)));
  /*03dc push ebx*/
    *(unsigned*)((char*)S + 44) = ebx;
  /*03dd call FUN_00024300*/
    eax = (unsigned)((O*)ecx)->FUN_00024300(*(unsigned*)((char*)S + 44));
  /*03e2 cmp dword ptr [ebp + 0x14], 5*/
  /*03e6 mov byte ptr [esp + 0x37], al*/
    *(unsigned char*)((char*)S + 103) = (eax & 0xff);
  /*03ea mov al, byte ptr [0x4e0ac0]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)&(*(unsigned*)&DAT_004e0ac0)))) & 0xff) << 0);
  /*03ef sete byte ptr [esp + 0x23]*/
    *(unsigned char*)((char*)S + 83) = ((unsigned)((*(unsigned*)((char*)(ebp + 20)))) == (unsigned)(5u)) ? 1 : 0;
  /*03f4 test al, 1*/
  /*03f6 jne 041d*/
    if ((unsigned char)(((eax & 0xff) & 1u)) != 0) goto L_041d;
  /*03f8 mov eax, dword ptr [0x4e0ac0]*/
    eax = (*(unsigned*)&DAT_004e0ac0);
  /*03fd or eax, 1*/
    eax = (unsigned)(eax | 1u);
  /*0400 push 0x3f3fa0*/
    *(unsigned*)((char*)S + 44) = 4145056u;
  /*0405 mov dword ptr [0x4e0ac0], eax*/
    (*(hulk_uintptr*)&DAT_004e0ac0) = eax;
  /*040a call FUN_0027b020*/
    { unsigned __int64 r64 = FUN_0027b020(*(unsigned*)((char*)S + 44)); eax = (unsigned)r64; edx = (unsigned)(r64 >> 32); }
  /*040f add esp, 4*/
  /*0412 mov dword ptr [0x4e0ab8], eax*/
    DAT_004e0ab8 = eax;
  /*0417 mov dword ptr [0x4e0abc], edx*/
    DAT_004e0abc = edx;
L_041d:
  /*041d mov ecx, ebp*/
    ecx = ebp;
  /*041f call FUN_000443c0*/
    { unsigned __int64 r64 = ((O*)ecx)->FUN_000443c0(); eax = (unsigned)r64; edx = (unsigned)(r64 >> 32); }
  /*0424 cmp eax, dword ptr [0x4e0ab8]*/
  /*042a jne 0439*/
    if ((unsigned)(eax) != (unsigned)(DAT_004e0ab8)) goto L_0439;
  /*042c cmp edx, dword ptr [0x4e0abc]*/
  /*0432 mov byte ptr [esp + 0x13], 1*/
    *(unsigned char*)((char*)S + 67) = 1u;
  /*0437 je 043e*/
    if ((unsigned)(edx) == (unsigned)(DAT_004e0abc)) goto L_043e;
L_0439:
  /*0439 mov byte ptr [esp + 0x13], 0*/
    *(unsigned char*)((char*)S + 67) = 0u;
L_043e:
  /*043e lea ecx, [ebx + 0xdc]*/
    ecx = (hulk_uintptr)((char*)(ebx + 220));
  /*0444 call FUN_00231ee0*/
    eax = (unsigned)((O*)ecx)->FUN_00231ee0();
  /*0449 fld dword ptr [esi + 0x70]*/
    fl19 = *(float*)((char*)(esi + 112));
  /*044c fsub dword ptr [esp + 0x164]*/
    fl20 = *(float*)((char*)S + 404);
  /*0453 mov edx, dword ptr [esp + 0xd0]*/
    edx = (*(unsigned*)((char*)S + 256));
  /*045a mov al, byte ptr [edx + 0x46]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)(edx + 70)))) & 0xff) << 0);
  /*045d mov ecx, dword ptr [esp + 0x164]*/
    ecx = (*(unsigned*)((char*)S + 404));
  /*0464 fstp dword ptr [esi + 0x70]*/
    *(float*)((char*)(esi + 112)) = (float)(((fl19) - (fl20)));
  /*0467 push ecx*/
    *(unsigned*)((char*)S + 44) = ecx;
  /*0468 fld dword ptr [esi + 0x74]*/
    fl21 = *(float*)((char*)(esi + 116));
  /*046b push edi*/
    *(unsigned*)((char*)S + 40) = edi;
  /*046c fsub dword ptr [esp + 0x16c]*/
    fl22 = *(float*)((char*)S + 404);
  /*0473 mov ecx, esi*/
    ecx = esi;
  /*0475 mov byte ptr [esp + 0x6b], al*/
    *(unsigned char*)((char*)S + 147) = (eax & 0xff);
  /*0479 fstp dword ptr [esi + 0x74]*/
    *(float*)((char*)(esi + 116)) = (float)(((fl21) - (fl22)));
  /*047c fld dword ptr [esi + 0x78]*/
    fl23 = *(float*)((char*)(esi + 120));
  /*047f fsub dword ptr [esp + 0x16c]*/
    fl24 = *(float*)((char*)S + 404);
  /*0486 fstp dword ptr [esi + 0x78]*/
    *(float*)((char*)(esi + 120)) = (float)(((fl23) - (fl24)));
  /*0489 call FUN_00107410*/
    eax = (unsigned)((O*)ecx)->FUN_00107410(*(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*048e fld dword ptr [esi + 0xa0]*/
    fl25 = *(float*)((char*)(esi + 160));
  /*0494 fcomp dword ptr [0x3f32e0]*/
  /*049a fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fl25, 0.0f)) & 0xffff);
  /*049c test ah, 0x41*/
  /*049f jne 04d2*/
    if ((unsigned char)((((eax >> 8) & 0xff) & 65u)) != 0) goto L_04d2;
  /*04a1 fld dword ptr [esi + 0xa0]*/
    fl26 = *(float*)((char*)(esi + 160));
  /*04a7 fsub dword ptr [esp + 0x164]*/
    fl27 = *(float*)((char*)S + 404);
  /*04ae fcomp dword ptr [0x3f32e0]*/
  /*04b4 fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(((fl26) - (fl27)), 0.0f)) & 0xffff);
  /*04b6 test ah, 0x41*/
  /*04b9 jp 04d2*/
    if (PF8((((eax >> 8) & 0xff) & 65u))) goto L_04d2;
  /*04bb push 0x40d278*/
    *(unsigned*)((char*)S + 44) = 4248184u;
  /*04c0 lea ecx, [edi + 0x140]*/
    ecx = (hulk_uintptr)((char*)(edi + 320));
  /*04c6 call FUN_0027b040*/
    ((O*)ecx)->FUN_0027b040(*(unsigned*)((char*)S + 44));
  /*04cb mov byte ptr [edi + 0x148], 1*/
    *(unsigned char*)((char*)(edi + 328)) = 1u;
L_04d2:
  /*04d2 fld dword ptr [esi + 0xa0]*/
    fl28 = *(float*)((char*)(esi + 160));
  /*04d8 mov edx, dword ptr [esp + 0x50]*/
    edx = (*(unsigned*)((char*)S + 128));
  /*04dc fsub dword ptr [esp + 0x164]*/
    fl29 = *(float*)((char*)S + 404);
  /*04e3 push 0*/
    *(unsigned*)((char*)S + 44) = 0u;
  /*04e5 fstp dword ptr [esi + 0xa0]*/
    *(float*)((char*)(esi + 160)) = (float)(((fl28) - (fl29)));
  /*04eb mov dword ptr [edi + 0x11c], edx*/
    *(hulk_uintptr*)((char*)(edi + 284)) = edx;
  /*04f1 mov eax, dword ptr [esp + 0x58]*/
    eax = (*(unsigned*)((char*)S + 132));
  /*04f5 mov dword ptr [edi + 0x120], eax*/
    *(hulk_uintptr*)((char*)(edi + 288)) = eax;
  /*04fb mov ecx, dword ptr [esp + 0x5c]*/
    ecx = (*(unsigned*)((char*)S + 136));
  /*04ff mov dword ptr [edi + 0x124], ecx*/
    *(hulk_uintptr*)((char*)(edi + 292)) = ecx;
  /*0505 mov ecx, ebx*/
    ecx = ebx;
  /*0507 call FUN_00035ef0*/
    eax = (unsigned)((O*)ecx)->FUN_00035ef0(*(unsigned*)((char*)S + 44));
  /*050c test eax, eax*/
  /*050e je 06d1*/
    if ((unsigned)((eax & eax)) == 0) goto L_06d1;
  /*0514 push 0*/
    *(unsigned*)((char*)S + 44) = 0u;
  /*0516 mov ecx, ebx*/
    ecx = ebx;
  /*0518 call FUN_00035ef0*/
    eax = (unsigned)((O*)ecx)->FUN_00035ef0(*(unsigned*)((char*)S + 44));
  /*051d mov ecx, eax*/
    ecx = eax;
  /*051f call FUN_001d6b40*/
    eax = (unsigned)((O*)ecx)->FUN_001d6b40();
  /*0524 fld dword ptr [esp + 0x64]*/
    fl30 = *(float*)((char*)S + 148);
  /*0528 mov edx, dword ptr [eax]*/
    vo_edx = eax;
    edx = (*(unsigned*)((char*)(eax)));
  /*052a mov dword ptr [esp + 0x98], edx*/
    *(unsigned*)((char*)S + 200) = edx;
  /*0531 fsub dword ptr [esp + 0x98]*/
    fl31 = *(float*)((char*)S + 200);
  /*0538 mov ecx, dword ptr [eax + 4]*/
    ecx = (*(unsigned*)((char*)(eax + 4)));
  /*053b mov dword ptr [esp + 0x9c], ecx*/
    *(unsigned*)((char*)S + 204) = ecx;
  /*0542 mov edx, dword ptr [eax + 8]*/
    edx = (*(unsigned*)((char*)(eax + 8)));
  /*0545 fstp dword ptr [esp + 0x40]*/
    *(float*)((char*)S + 112) = (float)(((fl30) - (fl31)));
  /*0549 fld dword ptr [esp + 0x68]*/
    fl32 = *(float*)((char*)S + 152);
  /*054d mov dword ptr [esp + 0xa0], edx*/
    *(unsigned*)((char*)S + 208) = edx;
  /*0554 fsub dword ptr [esp + 0x9c]*/
    fl33 = *(float*)((char*)S + 204);
  /*055b lea ecx, [esp + 0x40]*/
    ecx = (hulk_uintptr)((char*)S + 112);
  /*055f fstp dword ptr [esp + 0x44]*/
    *(float*)((char*)S + 116) = (float)(((fl32) - (fl33)));
  /*0563 fld dword ptr [esp + 0x6c]*/
    fl34 = *(float*)((char*)S + 156);
  /*0567 fsub dword ptr [esp + 0xa0]*/
    fl35 = *(float*)((char*)S + 208);
  /*056e fstp dword ptr [esp + 0x48]*/
    *(float*)((char*)S + 120) = (float)(((fl34) - (fl35)));
  /*0572 call FUN_0022d110*/
    fretv = ((O*)ecx)->FUN_0022d110();
  /*0577 mov ecx, dword ptr [0x4e0ab0]*/
    ecx = (*(unsigned*)&DAT_004e0ab0);
  /*057d fstp st(0)*/
  /*057f test ecx, ecx*/
  /*0581 je 05c5*/
    if ((unsigned)((ecx & ecx)) == 0) goto L_05c5;
  /*0583 push ecx*/
    *(unsigned*)((char*)S + 44) = ecx;
  /*0584 mov eax, 0xffff0000*/
    eax = 4294901760u;
  /*0589 push eax*/
    *(unsigned*)((char*)S + 40) = eax;
  /*058a mov eax, dword ptr [0x4a1e54]*/
    eax = (*(unsigned*)&DAT_004a1e54);
  /*058f push eax*/
    *(unsigned*)((char*)S + 36) = eax;
  /*0590 lea ecx, [esp + 0x70]*/
    ecx = (hulk_uintptr)((char*)S + 148);
  /*0594 push ecx*/
    *(unsigned*)((char*)S + 32) = ecx;
  /*0595 mov ecx, dword ptr [0x4dd6e8]*/
    ecx = (*(unsigned*)&DAT_004dd6e8);
  /*059b call FUN_0023f820*/
    ((O*)ecx)->FUN_0023f820(*(unsigned*)((char*)S + 32), *(unsigned*)((char*)S + 36), *(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*05a0 mov edx, dword ptr [0x4e0ab0]*/
    edx = (*(unsigned*)&DAT_004e0ab0);
  /*05a6 push edx*/
    *(unsigned*)((char*)S + 44) = edx;
  /*05a7 mov eax, 0xffff0000*/
    eax = 4294901760u;
  /*05ac push eax*/
    *(unsigned*)((char*)S + 40) = eax;
  /*05ad lea eax, [esp + 0x6c]*/
    eax = (hulk_uintptr)((char*)S + 148);
  /*05b1 push eax*/
    *(unsigned*)((char*)S + 36) = eax;
  /*05b2 lea ecx, [esp + 0xa4]*/
    ecx = (hulk_uintptr)((char*)S + 200);
  /*05b9 push ecx*/
    *(unsigned*)((char*)S + 32) = ecx;
  /*05ba mov ecx, dword ptr [0x4dd6e8]*/
    ecx = (*(unsigned*)&DAT_004dd6e8);
  /*05c0 call FUN_0023f7b0*/
    eax = (unsigned)((O*)ecx)->FUN_0023f7b0(*(unsigned*)((char*)S + 32), *(unsigned*)((char*)S + 36), *(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
L_05c5:
  /*05c5 mov al, byte ptr [esp + 0x10]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 64))) & 0xff) << 0);
  /*05c9 test al, al*/
  /*05cb je 06c0*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) == 0) goto L_06c0;
  /*05d1 fld dword ptr [esp + 0x68]*/
    fl36 = *(float*)((char*)S + 152);
  /*05d5 fcomp dword ptr [esp + 0x9c]*/
    fl37 = *(float*)((char*)S + 204);
  /*05dc fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fl36, fl37)) & 0xffff);
  /*05de test ah, 0x41*/
  /*05e1 jne 06c0*/
    if ((unsigned char)((((eax >> 8) & 0xff) & 65u)) != 0) goto L_06c0;
  /*05e7 fld dword ptr [esp + 0x44]*/
    fl38 = *(float*)((char*)S + 116);
  /*05eb fcomp dword ptr [0x3ffa00]*/
  /*05f1 fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fl38, 0.699999988f)) & 0xffff);
  /*05f3 test ah, 5*/
  /*05f6 jp 06c0*/
    if (PF8((((eax >> 8) & 0xff) & 5u))) goto L_06c0;
  /*05fc fld dword ptr [esp + 0x30]*/
    fl39 = *(float*)((char*)S + 96);
  /*0600 mov dword ptr [esp + 0x38], 0*/
    *(unsigned*)((char*)S + 104) = 0u;
  /*0608 fcomp dword ptr [0x4a1e50]*/
    fl40 = *(float*)&(*(unsigned*)&DAT_004a1e50);
  /*060e fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fl39, fl40)) & 0xffff);
  /*0610 test ah, 0x41*/
  /*0613 jne 062e*/
    if ((unsigned char)((((eax >> 8) & 0xff) & 65u)) != 0) goto L_062e;
  /*0615 fld dword ptr [esp + 0x30]*/
    fl41 = *(float*)((char*)S + 96);
  /*0619 fcomp dword ptr [0x4a1e4c]*/
    fl42 = *(float*)&(*(unsigned*)&DAT_004a1e4c);
  /*061f fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fl41, fl42)) & 0xffff);
  /*0621 test ah, 1*/
  /*0624 jne 062e*/
    if ((unsigned char)((((eax >> 8) & 0xff) & 1u)) != 0) goto L_062e;
  /*0626 mov dword ptr [esp + 0x38], 0x3f1c61aa*/
    *(unsigned*)((char*)S + 104) = 1058824618u;
L_062e:
  /*062e lea edx, [esp + 0x24]*/
    edx = (hulk_uintptr)((char*)S + 84);
  /*0632 push edx*/
    *(unsigned*)((char*)S + 44) = edx;
  /*0633 lea eax, [esp + 0x44]*/
    eax = (hulk_uintptr)((char*)S + 112);
  /*0637 push eax*/
    *(unsigned*)((char*)S + 40) = eax;
  /*0638 lea ecx, [esp + 0x84]*/
    ecx = (hulk_uintptr)((char*)S + 172);
  /*063f mov dword ptr [esp + 0x2c], 0*/
    *(unsigned*)((char*)S + 84) = 0u;
  /*0647 mov dword ptr [esp + 0x30], 0x3f800000*/
    *(unsigned*)((char*)S + 88) = 1065353216u;
  /*064f mov dword ptr [esp + 0x34], 0*/
    *(unsigned*)((char*)S + 92) = 0u;
  /*0657 call FUN_000111b0*/
    ((O*)ecx)->FUN_000111b0(*(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*065c mov edx, dword ptr [esp + 0x38]*/
    edx = (*(unsigned*)((char*)S + 104));
  /*0660 lea ecx, [esp + 0x7c]*/
    ecx = (hulk_uintptr)((char*)S + 172);
  /*0664 push ecx*/
    *(unsigned*)((char*)S + 44) = ecx;
  /*0665 push edx*/
    *(unsigned*)((char*)S + 40) = edx;
  /*0666 lea ecx, [esp + 0x108]*/
    ecx = (hulk_uintptr)((char*)S + 304);
  /*066d call FUN_0022b170*/
    ((O*)ecx)->FUN_0022b170(*(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*0672 lea ecx, [esp + 0x11c]*/
    ecx = (hulk_uintptr)((char*)S + 332);
  /*0679 call FUN_0022b980*/
    ((O*)ecx)->FUN_0022b980();
  /*067e lea eax, [esp + 0x11c]*/
    eax = (hulk_uintptr)((char*)S + 332);
  /*0685 push eax*/
    *(unsigned*)((char*)S + 44) = eax;
  /*0686 lea ecx, [esp + 0x104]*/
    ecx = (hulk_uintptr)((char*)S + 304);
  /*068d call FUN_0022b650*/
    ((O*)ecx)->FUN_0022b650(*(unsigned*)((char*)S + 44));
  /*0692 mov ecx, dword ptr [esp + 0x40]*/
    ecx = (*(unsigned*)((char*)S + 112));
  /*0696 mov edx, dword ptr [esp + 0x44]*/
    edx = (*(unsigned*)((char*)S + 116));
  /*069a mov eax, dword ptr [esp + 0x48]*/
    eax = (*(unsigned*)((char*)S + 120));
  /*069e mov dword ptr [esp + 0x24], ecx*/
    *(unsigned*)((char*)S + 84) = ecx;
  /*06a2 lea ecx, [esp + 0x40]*/
    ecx = (hulk_uintptr)((char*)S + 112);
  /*06a6 mov dword ptr [esp + 0x28], edx*/
    *(unsigned*)((char*)S + 88) = edx;
  /*06aa push ecx*/
    *(unsigned*)((char*)S + 44) = ecx;
  /*06ab lea edx, [esp + 0x28]*/
    edx = (hulk_uintptr)((char*)S + 84);
  /*06af push edx*/
    *(unsigned*)((char*)S + 40) = edx;
  /*06b0 lea ecx, [esp + 0x124]*/
    ecx = (hulk_uintptr)((char*)S + 332);
  /*06b7 mov dword ptr [esp + 0x34], eax*/
    *(unsigned*)((char*)S + 92) = eax;
  /*06bb call FUN_0022c3b0*/
    ((O*)ecx)->FUN_0022c3b0(*(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
L_06c0:
  /*06c0 mov eax, dword ptr [esp + 0x30]*/
    eax = (*(unsigned*)((char*)S + 96));
  /*06c4 push eax*/
    *(unsigned*)((char*)S + 44) = eax;
  /*06c5 lea ecx, [esp + 0x44]*/
    ecx = (hulk_uintptr)((char*)S + 112);
  /*06c9 push ecx*/
    *(unsigned*)((char*)S + 40) = ecx;
  /*06ca lea edx, [esp + 0x2c]*/
    edx = (hulk_uintptr)((char*)S + 84);
  /*06ce push edx*/
    *(unsigned*)((char*)S + 36) = edx;
  /*06cf jmp 06e3*/
    goto L_06e3;
L_06d1:
  /*06d1 mov ecx, dword ptr [esp + 0x30]*/
    ecx = (*(unsigned*)((char*)S + 96));
  /*06d5 push ecx*/
    *(unsigned*)((char*)S + 44) = ecx;
  /*06d6 lea edx, [esp + 0xc8]*/
    edx = (hulk_uintptr)((char*)S + 244);
  /*06dd push edx*/
    *(unsigned*)((char*)S + 40) = edx;
  /*06de lea eax, [esp + 0x2c]*/
    eax = (hulk_uintptr)((char*)S + 84);
  /*06e2 push eax*/
    *(unsigned*)((char*)S + 36) = eax;
L_06e3:
  /*06e3 call FUN_00083e00*/
    eax = (unsigned)FUN_00083e00(*(unsigned*)((char*)S + 36), *(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*06e8 mov edx, dword ptr [eax + 4]*/
    edx = (*(unsigned*)((char*)(eax + 4)));
  /*06eb mov ecx, dword ptr [eax]*/
    vo_ecx = eax;
    ecx = (*(unsigned*)((char*)(eax)));
  /*06ed mov eax, dword ptr [eax + 8]*/
    eax = (*(unsigned*)((char*)(eax + 8)));
  /*06f0 mov dword ptr [esp + 0xcc], eax*/
    *(unsigned*)((char*)S + 240) = eax;
  /*06f7 mov al, byte ptr [esp + 0x2f]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 83))) & 0xff) << 0);
  /*06fb add esp, 0xc*/
  /*06fe test al, al*/
  /*0700 mov dword ptr [esp + 0xb8], ecx*/
    *(unsigned*)((char*)S + 232) = ecx;
  /*0707 mov dword ptr [esp + 0xbc], edx*/
    *(unsigned*)((char*)S + 236) = edx;
  /*070e je 075c*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) == 0) goto L_075c;
  /*0710 mov ecx, dword ptr [esi + 0x58]*/
    ecx = (*(unsigned*)((char*)(esi + 88)));
  /*0713 mov edx, dword ptr [ecx]*/
    vo_edx = ecx;
    edx = (*(unsigned*)((char*)(ecx)));
  /*0715 call dword ptr [edx + 0x18]*/
    eax = (unsigned)((VC2*)vo_edx)->vcall();
  /*0718 push 0x40d6d8*/
    *(unsigned*)((char*)S + 44) = 4249304u;
  /*071d lea ecx, [esp + 0x9c]*/
    ecx = (hulk_uintptr)((char*)S + 200);
  /*0724 mov ebp, eax*/
    ebp = eax;
  /*0726 call FUN_0027b0e0*/
    eax = (unsigned)((O*)ecx)->FUN_0027b0e0(*(unsigned*)((char*)S + 44));
  /*072b push eax*/
    *(unsigned*)((char*)S + 44) = eax;
  /*072c lea ecx, [ebp + 0x1b50]*/
    ecx = (hulk_uintptr)((char*)(ebp + 6992));
  /*0732 call FUN_0027af90*/
    eax = (unsigned)((O*)ecx)->FUN_0027af90(*(unsigned*)((char*)S + 44));
  /*0737 lea ecx, [esp + 0x98]*/
    ecx = (hulk_uintptr)((char*)S + 200);
  /*073e mov byte ptr [esp + 0xa7], al*/
    *(unsigned char*)((char*)S + 215) = (eax & 0xff);
  /*0745 call FUN_0027af50*/
    eax = (unsigned)((O*)ecx)->FUN_0027af50();
  /*074a mov al, byte ptr [esp + 0xa7]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 215))) & 0xff) << 0);
  /*0751 test al, al*/
  /*0753 je 075c*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) == 0) goto L_075c;
  /*0755 mov dword ptr [esi + 0x70], 0*/
    *(unsigned*)((char*)(esi + 112)) = 0u;
L_075c:
  /*075c mov al, byte ptr [esp + 0x3f]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 111))) & 0xff) << 0);
  /*0760 test al, al*/
  /*0762 jne 0786*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) != 0) goto L_0786;
  /*0764 mov al, byte ptr [esp + 0x11]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 65))) & 0xff) << 0);
  /*0768 test al, al*/
  /*076a je 0d09*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) == 0) goto L_0d09;
  /*0770 fld dword ptr [esi + 0x98]*/
    fl43 = *(float*)((char*)(esi + 152));
  /*0776 fchs */
  /*0778 fcomp dword ptr [esi + 0x70]*/
    fl44 = *(float*)((char*)(esi + 112));
  /*077b fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW((-(fl43)), fl44)) & 0xffff);
  /*077d test ah, 0x41*/
  /*0780 jne 0d09*/
    if ((unsigned char)((((eax >> 8) & 0xff) & 65u)) != 0) goto L_0d09;
L_0786:
  /*0786 fld dword ptr [esp + 0x30]*/
    fl45 = *(float*)((char*)S + 96);
  /*078a fcomp dword ptr [esi + 0x84]*/
    fl46 = *(float*)((char*)(esi + 132));
  /*0790 fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fl45, fl46)) & 0xffff);
  /*0792 test ah, 1*/
  /*0795 je 07ae*/
    if ((unsigned char)((((eax >> 8) & 0xff) & 1u)) == 0) goto L_07ae;
  /*0797 fld dword ptr [esi + 0xac]*/
    fl47 = *(float*)((char*)(esi + 172));
  /*079d fcomp dword ptr [0x3f5cf8]*/
  /*07a3 fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fl47, 2.0f)) & 0xffff);
  /*07a5 test ah, 0x41*/
  /*07a8 jne 0d09*/
    if ((unsigned char)((((eax >> 8) & 0xff) & 65u)) != 0) goto L_0d09;
L_07ae:
  /*07ae fld dword ptr [esp + 0x30]*/
    fl48 = *(float*)((char*)S + 96);
  /*07b2 fcomp dword ptr [esi + 0x88]*/
    fl49 = *(float*)((char*)(esi + 136));
  /*07b8 fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fl48, fl49)) & 0xffff);
  /*07ba test ah, 0x41*/
  /*07bd jp 0d09*/
    if (PF8((((eax >> 8) & 0xff) & 65u))) goto L_0d09;
  /*07c3 mov al, byte ptr [esp + 0x12]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 66))) & 0xff) << 0);
  /*07c7 test al, al*/
  /*07c9 je 0d09*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) == 0) goto L_0d09;
  /*07cf mov al, byte ptr [esp + 0x10]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 64))) & 0xff) << 0);
  /*07d3 test al, al*/
  /*07d5 mov byte ptr [esp + 0x11], 0*/
    *(unsigned char*)((char*)S + 65) = 0u;
  /*07da je 0b12*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) == 0) goto L_0b12;
  /*07e0 mov eax, dword ptr [esp + 0x160]*/
    eax = (*(unsigned*)((char*)S + 400));
  /*07e7 mov ecx, dword ptr [eax + 0x20]*/
    ecx = (*(unsigned*)((char*)(eax + 32)));
  /*07ea mov eax, dword ptr [ecx + 0xc]*/
    eax = (*(unsigned*)((char*)(ecx + 12)));
  /*07ed xor ebx, ebx*/
    ebx = 0;
  /*07ef test eax, eax*/
  /*07f1 mov dword ptr [esp + 0xb4], eax*/
    *(unsigned*)((char*)S + 228) = eax;
  /*07f8 jle 08b1*/
    if (((int)((eax & eax)) <= 0)) goto L_08b1;
  /*07fe mov edi, edi*/
    edi = edi;
L_0800:
  /*0800 mov edx, dword ptr [esp + 0x160]*/
    edx = (*(unsigned*)((char*)S + 400));
  /*0807 mov ecx, dword ptr [edx + 0x20]*/
    ecx = (*(unsigned*)((char*)(edx + 32)));
  /*080a push ebx*/
    *(unsigned*)((char*)S + 44) = ebx;
  /*080b call FUN_00024190*/
    eax = (unsigned)((O*)ecx)->FUN_00024190(*(unsigned*)((char*)S + 44));
  /*0810 mov ebp, eax*/
    ebp = eax;
  /*0812 test ebp, ebp*/
  /*0814 je 08a1*/
    if ((unsigned)((ebp & ebp)) == 0) goto L_08a1;
  /*081a mov eax, dword ptr [esp + 0x160]*/
    eax = (*(unsigned*)((char*)S + 400));
  /*0821 mov ecx, dword ptr [eax + 0x20]*/
    ecx = (*(unsigned*)((char*)(eax + 32)));
  /*0824 push ebp*/
    *(unsigned*)((char*)S + 44) = ebp;
  /*0825 call FUN_00025d30*/
    eax = (unsigned)((O*)ecx)->FUN_00025d30(*(unsigned*)((char*)S + 44));
  /*082a test al, al*/
  /*082c jne 08a1*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) != 0) goto L_08a1;
  /*082e mov eax, dword ptr [esp + 0x5c]*/
    eax = (*(unsigned*)((char*)S + 140));
  /*0832 cmp ebp, eax*/
  /*0834 je 08a1*/
    if ((unsigned)(ebp) == (unsigned)(eax)) goto L_08a1;
  /*0836 mov ecx, dword ptr [ebp + 0x11c]*/
    ecx = (*(unsigned*)((char*)(ebp + 284)));
  /*083c mov edx, dword ptr [eax + 0x11c]*/
    edx = (*(unsigned*)((char*)(eax + 284)));
  /*0842 mov eax, dword ptr [ecx + 0x1b0]*/
    eax = (*(unsigned*)((char*)(ecx + 432)));
  /*0848 cmp eax, dword ptr [edx + 0x1b0]*/
  /*084e jne 08a1*/
    if ((unsigned)(eax) != (unsigned)((*(unsigned*)((char*)(edx + 432))))) goto L_08a1;
  /*0850 lea ecx, [esp + 0x24]*/
    ecx = (hulk_uintptr)((char*)S + 84);
  /*0854 push ecx*/
    *(unsigned*)((char*)S + 44) = ecx;
  /*0855 mov ecx, dword ptr [ebp + 0x10]*/
    ecx = (*(unsigned*)((char*)(ebp + 16)));
  /*0858 call FUN_00059a50*/
    ((O*)ecx)->FUN_00059a50(*(unsigned*)((char*)S + 44));
  /*085d fld dword ptr [esp + 0x24]*/
    fl50 = *(float*)((char*)S + 84);
  /*0861 fsub dword ptr [esp + 0x64]*/
    fl51 = *(float*)((char*)S + 148);
  /*0865 lea ecx, [esp + 0x7c]*/
    ecx = (hulk_uintptr)((char*)S + 172);
  /*0869 fstp dword ptr [esp + 0x7c]*/
    *(float*)((char*)S + 172) = (float)(((fl50) - (fl51)));
  /*086d fld dword ptr [esp + 0x28]*/
    fl52 = *(float*)((char*)S + 88);
  /*0871 fsub dword ptr [esp + 0x68]*/
    fl53 = *(float*)((char*)S + 152);
  /*0875 fstp dword ptr [esp + 0x80]*/
    *(float*)((char*)S + 176) = (float)(((fl52) - (fl53)));
  /*087c fld dword ptr [esp + 0x2c]*/
    fl54 = *(float*)((char*)S + 92);
  /*0880 fsub dword ptr [esp + 0x6c]*/
    fl55 = *(float*)((char*)S + 156);
  /*0884 fstp dword ptr [esp + 0x84]*/
    *(float*)((char*)S + 180) = (float)(((fl54) - (fl55)));
  /*088b call FUN_00018990*/
    fretv = ((O*)ecx)->FUN_00018990();
  /*0890 fcomp dword ptr [0x40d6fc]*/
  /*0896 fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fretv, 3.0f)) & 0xffff);
  /*0898 test ah, 5*/
  /*089b jnp 0b0d*/
    if (!PF8((((eax >> 8) & 0xff) & 5u))) goto L_0b0d;
L_08a1:
  /*08a1 mov eax, dword ptr [esp + 0xb4]*/
    eax = (*(unsigned*)((char*)S + 228));
  /*08a8 inc ebx*/
    ebx = ebx + 1;
  /*08a9 cmp ebx, eax*/
  /*08ab jl 0800*/
    if ((int)(ebx) < (int)(eax)) goto L_0800;
L_08b1:
  /*08b1 mov edx, dword ptr [esp + 0x94]*/
    edx = (*(unsigned*)((char*)S + 196));
  /*08b8 cmp dword ptr [edx + 0xc], 1*/
  /*08bc jne 0b12*/
    if ((unsigned)((*(unsigned*)((char*)(edx + 12)))) != (unsigned)(1u)) goto L_0b12;
  /*08c2 mov eax, dword ptr [esp + 0x160]*/
    eax = (*(unsigned*)((char*)S + 400));
  /*08c9 mov ecx, dword ptr [eax + 0x20]*/
    ecx = (*(unsigned*)((char*)(eax + 32)));
  /*08cc mov ebx, edx*/
    ebx = edx;
  /*08ce mov edx, dword ptr [ebx + 8]*/
    edx = (*(unsigned*)((char*)(ebx + 8)));
  /*08d1 push edx*/
    *(unsigned*)((char*)S + 44) = edx;
  /*08d2 call FUN_00025d30*/
    eax = (unsigned)((O*)ecx)->FUN_00025d30(*(unsigned*)((char*)S + 44));
  /*08d7 test al, al*/
  /*08d9 je 0b12*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) == 0) goto L_0b12;
  /*08df mov ebp, dword ptr [esp + 0x5c]*/
    ebp = (*(unsigned*)((char*)S + 140));
  /*08e3 push 0*/
    *(unsigned*)((char*)S + 44) = 0u;
  /*08e5 mov ecx, ebp*/
    ecx = ebp;
  /*08e7 call FUN_00035ef0*/
    eax = (unsigned)((O*)ecx)->FUN_00035ef0(*(unsigned*)((char*)S + 44));
  /*08ec test eax, eax*/
  /*08ee je 0b12*/
    if ((unsigned)((eax & eax)) == 0) goto L_0b12;
  /*08f4 fld dword ptr [esp + 0x64]*/
    fl56 = *(float*)((char*)S + 148);
  /*08f8 mov eax, dword ptr [esp + 0xa8]*/
    eax = (*(unsigned*)((char*)S + 216));
  /*08ff fsub dword ptr [esp + 0xa8]*/
    fl57 = *(float*)((char*)S + 216);
  /*0906 mov ecx, dword ptr [esp + 0xac]*/
    ecx = (*(unsigned*)((char*)S + 220));
  /*090d fld dword ptr [esp + 0x68]*/
    fl58 = *(float*)((char*)S + 152);
  /*0911 mov edx, dword ptr [esp + 0xb0]*/
    edx = (*(unsigned*)((char*)S + 224));
  /*0918 fsub dword ptr [esp + 0xac]*/
    fl59 = *(float*)((char*)S + 220);
  /*091f mov dword ptr [esp + 0x7c], eax*/
    *(unsigned*)((char*)S + 172) = eax;
  /*0923 fld dword ptr [esp + 0x6c]*/
    fl60 = *(float*)((char*)S + 156);
  /*0927 mov dword ptr [esp + 0x80], ecx*/
    *(unsigned*)((char*)S + 176) = ecx;
  /*092e fsub dword ptr [esp + 0xb0]*/
    fl61 = *(float*)((char*)S + 224);
  /*0935 lea ecx, [esp + 0x40]*/
    ecx = (hulk_uintptr)((char*)S + 112);
  /*0939 mov dword ptr [esp + 0x84], edx*/
    *(unsigned*)((char*)S + 180) = edx;
  /*0940 fstp dword ptr [esp + 0x2c]*/
    *(float*)((char*)S + 92) = (float)(((fl60) - (fl61)));
  /*0944 mov eax, dword ptr [esp + 0x2c]*/
    eax = (*(unsigned*)((char*)S + 92));
  /*0948 fxch st(1)*/
  /*094a mov dword ptr [esp + 0x48], eax*/
    *(unsigned*)((char*)S + 120) = eax;
  /*094e fstp dword ptr [esp + 0x40]*/
    *(float*)((char*)S + 112) = (float)(((fl56) - (fl57)));
  /*0952 fstp dword ptr [esp + 0x44]*/
    *(float*)((char*)S + 116) = (float)(((fl58) - (fl59)));
  /*0956 call FUN_00018990*/
    fretv = ((O*)ecx)->FUN_00018990();
  /*095b mov ecx, dword ptr [esp + 0x40]*/
    ecx = (*(unsigned*)((char*)S + 112));
  /*095f fstp dword ptr [esp + 0x38]*/
    *(float*)((char*)S + 104) = (float)(fretv);
  /*0963 mov edx, dword ptr [esp + 0x44]*/
    edx = (*(unsigned*)((char*)S + 116));
  /*0967 mov eax, dword ptr [esp + 0x48]*/
    eax = (*(unsigned*)((char*)S + 120));
  /*096b mov dword ptr [esp + 0x24], ecx*/
    *(unsigned*)((char*)S + 84) = ecx;
  /*096f lea ecx, [esp + 0x24]*/
    ecx = (hulk_uintptr)((char*)S + 84);
  /*0973 mov dword ptr [esp + 0x28], edx*/
    *(unsigned*)((char*)S + 88) = edx;
  /*0977 mov dword ptr [esp + 0x2c], eax*/
    *(unsigned*)((char*)S + 92) = eax;
  /*097b call FUN_0022d110*/
    fretv = ((O*)ecx)->FUN_0022d110();
  /*0980 fstp st(0)*/
  /*0982 fld dword ptr [esp + 0x38]*/
    fl62 = *(float*)((char*)S + 104);
  /*0986 lea ecx, [esp + 0xb4]*/
    ecx = (hulk_uintptr)((char*)S + 228);
  /*098d fsub dword ptr [0x3f5cf8]*/
  /*0993 push ecx*/
    *(unsigned*)((char*)S + 44) = ecx;
  /*0994 lea edx, [esp + 0x9c]*/
    edx = (hulk_uintptr)((char*)S + 200);
  /*099b push edx*/
    *(unsigned*)((char*)S + 40) = edx;
  /*099c fstp dword ptr [esp + 0xbc]*/
    *(float*)((char*)S + 228) = (float)(((fl62) - (2.0f)));
  /*09a3 mov dword ptr [esp + 0xa0], 0x3f800000*/
    *(unsigned*)((char*)S + 200) = 1065353216u;
  /*09ae call FUN_00018710*/
    fretv = FUN_00018710(*(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*09b3 fstp dword ptr [esp + 4]*/
    *(float*)((char*)S + 44) = (float)(fretv);
  /*09b7 add esp, 4*/
  /*09ba lea eax, [esp + 0x28]*/
    eax = (hulk_uintptr)((char*)S + 84);
  /*09be push eax*/
    *(unsigned*)((char*)S + 40) = eax;
  /*09bf lea ecx, [esp + 0xa0]*/
    ecx = (hulk_uintptr)((char*)S + 200);
  /*09c6 push ecx*/
    *(unsigned*)((char*)S + 36) = ecx;
  /*09c7 call FUN_00083e00*/
    eax = (unsigned)FUN_00083e00(*(unsigned*)((char*)S + 36), *(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*09cc mov edx, dword ptr [eax]*/
    vo_edx = eax;
    edx = (*(unsigned*)((char*)(eax)));
  /*09ce mov dword ptr [esp + 0x4c], edx*/
    *(unsigned*)((char*)S + 112) = edx;
  /*09d2 mov ecx, dword ptr [eax + 4]*/
    ecx = (*(unsigned*)((char*)(eax + 4)));
  /*09d5 mov dword ptr [esp + 0x50], ecx*/
    *(unsigned*)((char*)S + 116) = ecx;
  /*09d9 mov edx, dword ptr [eax + 8]*/
    edx = (*(unsigned*)((char*)(eax + 8)));
  /*09dc mov eax, dword ptr [ebx + 0x74]*/
    eax = (*(unsigned*)((char*)(ebx + 116)));
  /*09df add esp, 0xc*/
  /*09e2 test eax, eax*/
  /*09e4 mov dword ptr [esp + 0x48], edx*/
    *(unsigned*)((char*)S + 120) = edx;
  /*09e8 je 09ee*/
    if ((unsigned)((eax & eax)) == 0) goto L_09ee;
  /*09ea mov byte ptr [eax + 0x72], 0*/
    *(unsigned char*)((char*)(eax + 114)) = 0u;
L_09ee:
  /*09ee mov eax, dword ptr [ebp + 0x12c]*/
    eax = (*(unsigned*)((char*)(ebp + 300)));
  /*09f4 test eax, eax*/
  /*09f6 je 0a03*/
    if ((unsigned)((eax & eax)) == 0) goto L_0a03;
  /*09f8 mov eax, dword ptr [eax + 0x74]*/
    eax = (*(unsigned*)((char*)(eax + 116)));
  /*09fb test eax, eax*/
  /*09fd je 0a03*/
    if ((unsigned)((eax & eax)) == 0) goto L_0a03;
  /*09ff mov byte ptr [eax + 0x72], 0*/
    *(unsigned char*)((char*)(eax + 114)) = 0u;
L_0a03:
  /*0a03 call FUN_00202f00*/
    eax = (unsigned)FUN_00202f00();
  /*0a08 fld dword ptr [esp + 0x40]*/
    fl63 = *(float*)((char*)S + 112);
  /*0a0c fadd dword ptr [esp + 0x7c]*/
    fl64 = *(float*)((char*)S + 172);
  /*0a10 mov ecx, dword ptr [0x4e0aac]*/
    ecx = DAT_004e0aac;
  /*0a16 push 0*/
    *(unsigned*)((char*)S + 44) = 0u;
  /*0a18 mov dword ptr [0x554c18], ecx*/
    (*(hulk_uintptr*)&DAT_00554c18) = ecx;
  /*0a1e fstp dword ptr [esp + 0x9c]*/
    *(float*)((char*)S + 200) = (float)(((fl63) + (fl64)));
  /*0a25 lea edx, [esp + 0x9c]*/
    edx = (hulk_uintptr)((char*)S + 200);
  /*0a2c fld dword ptr [esp + 0x48]*/
    fl65 = *(float*)((char*)S + 116);
  /*0a30 push edx*/
    *(unsigned*)((char*)S + 40) = edx;
  /*0a31 fadd dword ptr [esp + 0x88]*/
    fl66 = *(float*)((char*)S + 176);
  /*0a38 lea ecx, [esp + 0x84]*/
    ecx = (hulk_uintptr)((char*)S + 172);
  /*0a3f push ecx*/
    *(unsigned*)((char*)S + 36) = ecx;
  /*0a40 mov ecx, dword ptr [0x554c14]*/
    ecx = (*(unsigned*)&DAT_00554c14);
  /*0a46 fstp dword ptr [esp + 0xa8]*/
    *(float*)((char*)S + 204) = (float)(((fl65) + (fl66)));
  /*0a4d push eax*/
    *(unsigned*)((char*)S + 32) = eax;
  /*0a4e fld dword ptr [esp + 0x94]*/
    fl67 = *(float*)((char*)S + 180);
  /*0a55 mov dword ptr [0x4d2a3c], 2*/
    (*(unsigned*)&DAT_004d2a3c) = 2u;
  /*0a5f fadd dword ptr [esp + 0x58]*/
    fl68 = *(float*)((char*)S + 120);
  /*0a63 mov byte ptr [0x554c1c], 0*/
    *(unsigned char*)&(*(unsigned*)&DAT_00554c1c) = 0u;
  /*0a6a fstp dword ptr [esp + 0xb0]*/
    *(float*)((char*)S + 208) = (float)(((fl67) + (fl68)));
  /*0a71 call FUN_002ee140*/
    eax = (unsigned)((O*)ecx)->FUN_002ee140(*(unsigned*)((char*)S + 32), *(unsigned*)((char*)S + 36), *(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*0a76 test al, al*/
  /*0a78 je 0a7f*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) == 0) goto L_0a7f;
  /*0a7a mov byte ptr [esp + 0x11], 1*/
    *(unsigned char*)((char*)S + 65) = 1u;
L_0a7f:
  /*0a7f mov eax, dword ptr [ebx + 0x74]*/
    eax = (*(unsigned*)((char*)(ebx + 116)));
  /*0a82 test eax, eax*/
  /*0a84 je 0a8a*/
    if ((unsigned)((eax & eax)) == 0) goto L_0a8a;
  /*0a86 mov byte ptr [eax + 0x72], 1*/
    *(unsigned char*)((char*)(eax + 114)) = 1u;
L_0a8a:
  /*0a8a mov eax, dword ptr [ebp + 0x12c]*/
    eax = (*(unsigned*)((char*)(ebp + 300)));
  /*0a90 test eax, eax*/
  /*0a92 je 0a9f*/
    if ((unsigned)((eax & eax)) == 0) goto L_0a9f;
  /*0a94 mov eax, dword ptr [eax + 0x74]*/
    eax = (*(unsigned*)((char*)(eax + 116)));
  /*0a97 test eax, eax*/
  /*0a99 je 0a9f*/
    if ((unsigned)((eax & eax)) == 0) goto L_0a9f;
  /*0a9b mov byte ptr [eax + 0x72], 1*/
    *(unsigned char*)((char*)(eax + 114)) = 1u;
L_0a9f:
  /*0a9f mov al, byte ptr [esp + 0x11]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 65))) & 0xff) << 0);
  /*0aa3 test al, al*/
  /*0aa5 jne 0b12*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) != 0) goto L_0b12;
  /*0aa7 fld dword ptr [0x3f32e0]*/
  /*0aad fld dword ptr [esp + 0x44]*/
    fl69 = *(float*)((char*)S + 116);
  /*0ab1 fucompp */
  /*0ab3 fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fl69, 0.0f)) & 0xffff);
  /*0ab5 test ah, 0x44*/
  /*0ab8 jnp 0b12*/
    if (!PF8((((eax >> 8) & 0xff) & 68u))) goto L_0b12;
  /*0aba push 0*/
    *(unsigned*)((char*)S + 44) = 0u;
  /*0abc lea edx, [esp + 0xb8]*/
    edx = (hulk_uintptr)((char*)S + 228);
  /*0ac3 push edx*/
    *(unsigned*)((char*)S + 40) = edx;
  /*0ac4 mov edx, dword ptr [esp + 0x40]*/
    edx = (*(unsigned*)((char*)S + 104));
  /*0ac8 lea eax, [esp + 0xa0]*/
    eax = (hulk_uintptr)((char*)S + 200);
  /*0acf push eax*/
    *(unsigned*)((char*)S + 36) = eax;
  /*0ad0 lea ecx, [esp + 0x100]*/
    ecx = (hulk_uintptr)((char*)S + 292);
  /*0ad7 push ecx*/
    *(unsigned*)((char*)S + 32) = ecx;
  /*0ad8 push 1*/
    *(unsigned*)((char*)S + 28) = 1u;
  /*0ada push edx*/
    *(unsigned*)((char*)S + 24) = edx;
  /*0adb mov edx, dword ptr [esp + 0x178]*/
    edx = (*(unsigned*)((char*)S + 400));
  /*0ae2 lea eax, [esp + 0x58]*/
    eax = (hulk_uintptr)((char*)S + 112);
  /*0ae6 push eax*/
    *(unsigned*)((char*)S + 20) = eax;
  /*0ae7 lea ecx, [esp + 0x98]*/
    ecx = (hulk_uintptr)((char*)S + 172);
  /*0aee push ecx*/
    *(unsigned*)((char*)S + 16) = ecx;
  /*0aef mov ecx, dword ptr [edx + 0x24]*/
    ecx = (*(unsigned*)((char*)(edx + 36)));
  /*0af2 mov dword ptr [esp + 0xd4], 0*/
    *(unsigned*)((char*)S + 228) = 0u;
  /*0afd call FUN_00202460*/
    ((O*)ecx)->FUN_00202460(*(unsigned*)((char*)S + 16), *(unsigned*)((char*)S + 20), *(unsigned*)((char*)S + 24), *(unsigned*)((char*)S + 28), *(unsigned*)((char*)S + 32), *(unsigned*)((char*)S + 36), *(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*0b02 mov eax, dword ptr [esp + 0xb4]*/
    eax = (*(unsigned*)((char*)S + 228));
  /*0b09 test eax, eax*/
  /*0b0b je 0b12*/
    if ((unsigned)((eax & eax)) == 0) goto L_0b12;
L_0b0d:
  /*0b0d mov byte ptr [esp + 0x11], 1*/
    *(unsigned char*)((char*)S + 65) = 1u;
L_0b12:
  /*0b12 fld dword ptr [esi + 0x70]*/
    fl70 = *(float*)((char*)(esi + 112));
  /*0b15 fcomp dword ptr [0x3f32e0]*/
  /*0b1b fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fl70, 0.0f)) & 0xffff);
  /*0b1d test ah, 0x41*/
  /*0b20 jne 0b39*/
    if ((unsigned char)((((eax >> 8) & 0xff) & 65u)) != 0) goto L_0b39;
  /*0b22 mov al, byte ptr [esp + 0x11]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 65))) & 0xff) << 0);
  /*0b26 test al, al*/
  /*0b28 je 0b39*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) == 0) goto L_0b39;
  /*0b2a mov al, byte ptr [esp + 0x10]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 64))) & 0xff) << 0);
  /*0b2e test al, al*/
  /*0b30 je 0b39*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) == 0) goto L_0b39;
  /*0b32 mov dword ptr [esi + 0x70], 0*/
    *(unsigned*)((char*)(esi + 112)) = 0u;
L_0b39:
  /*0b39 fld dword ptr [esi + 0x70]*/
    fl71 = *(float*)((char*)(esi + 112));
  /*0b3c xor ebp, ebp*/
    ebp = 0;
  /*0b3e fcomp dword ptr [0x3f32e0]*/
  /*0b44 fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fl71, 0.0f)) & 0xffff);
  /*0b46 test ah, 0x41*/
  /*0b49 jne 0c10*/
    if ((unsigned char)((((eax >> 8) & 0xff) & 65u)) != 0) goto L_0c10;
  /*0b4f mov dword ptr [edi + 0x118], ebp*/
    *(hulk_uintptr*)((char*)(edi + 280)) = ebp;
  /*0b55 mov eax, dword ptr [esp + 0x50]*/
    eax = (*(unsigned*)((char*)S + 128));
  /*0b59 mov dword ptr [edi + 0x11c], eax*/
    *(hulk_uintptr*)((char*)(edi + 284)) = eax;
  /*0b5f mov ecx, dword ptr [esp + 0x54]*/
    ecx = (*(unsigned*)((char*)S + 132));
  /*0b63 mov eax, dword ptr [esp + 0xb8]*/
    eax = (*(unsigned*)((char*)S + 232));
  /*0b6a mov dword ptr [edi + 0x120], ecx*/
    *(hulk_uintptr*)((char*)(edi + 288)) = ecx;
  /*0b70 mov edx, dword ptr [esp + 0x58]*/
    edx = (*(unsigned*)((char*)S + 136));
  /*0b74 mov ecx, dword ptr [esp + 0xbc]*/
    ecx = (*(unsigned*)((char*)S + 236));
  /*0b7b mov dword ptr [edi + 0x124], edx*/
    *(hulk_uintptr*)((char*)(edi + 292)) = edx;
  /*0b81 mov edx, dword ptr [esp + 0xc0]*/
    edx = (*(unsigned*)((char*)S + 240));
  /*0b88 mov dword ptr [edi + 0x114], ebp*/
    *(hulk_uintptr*)((char*)(edi + 276)) = ebp;
  /*0b8e mov dword ptr [edi + 0x110], ebp*/
    *(hulk_uintptr*)((char*)(edi + 272)) = ebp;
  /*0b94 mov dword ptr [edi + 0x10c], ebp*/
    *(hulk_uintptr*)((char*)(edi + 268)) = ebp;
  /*0b9a mov dword ptr [edi + 0x128], eax*/
    *(hulk_uintptr*)((char*)(edi + 296)) = eax;
  /*0ba0 mov al, byte ptr [esp + 0x13]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 67))) & 0xff) << 0);
  /*0ba4 test al, al*/
  /*0ba6 mov dword ptr [edi + 0x12c], ecx*/
    *(hulk_uintptr*)((char*)(edi + 300)) = ecx;
  /*0bac mov dword ptr [edi + 0x130], edx*/
    *(hulk_uintptr*)((char*)(edi + 304)) = edx;
  /*0bb2 je 0bcf*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) == 0) goto L_0bcf;
  /*0bb4 call FUN_000964e0*/
    fretv = ((O*)ecx)->FUN_000964e0();
  /*0bb9 fcomp dword ptr [0x40d66c]*/
  /*0bbf fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fretv, 0.5f)) & 0xffff);
  /*0bc1 test ah, 0x41*/
  /*0bc4 jne 0bcf*/
    if ((unsigned char)((((eax >> 8) & 0xff) & 65u)) != 0) goto L_0bcf;
  /*0bc6 mov dword ptr [edi + 0x18], 1*/
    *(unsigned*)((char*)(edi + 24)) = 1u;
  /*0bcd jmp 0bd5*/
    goto L_0bd5;
L_0bcf:
  /*0bcf mov dword ptr [edi], 1*/
    *(unsigned*)((char*)(edi)) = 1u;
L_0bd5:
  /*0bd5 mov al, byte ptr [esp + 0x23]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 83))) & 0xff) << 0);
  /*0bd9 test al, al*/
  /*0bdb jne 0bed*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) != 0) goto L_0bed;
  /*0bdd mov al, byte ptr [esp + 0x37]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 103))) & 0xff) << 0);
  /*0be1 test al, al*/
  /*0be3 jne 0bed*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) != 0) goto L_0bed;
  /*0be5 mov al, byte ptr [esp + 0x10]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 64))) & 0xff) << 0);
  /*0be9 test al, al*/
  /*0beb je 0bf0*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) == 0) goto L_0bf0;
L_0bed:
  /*0bed mov dword ptr [esi + 0x70], ebp*/
    *(hulk_uintptr*)((char*)(esi + 112)) = ebp;
L_0bf0:
  /*0bf0 mov eax, dword ptr [esp + 0x94]*/
    eax = (*(unsigned*)((char*)S + 196));
  /*0bf7 mov ebx, dword ptr [esp + 0x5c]*/
    ebx = (*(unsigned*)((char*)S + 140));
  /*0bfb push ebp*/
    *(unsigned*)((char*)S + 44) = ebp;
  /*0bfc push eax*/
    *(unsigned*)((char*)S + 40) = eax;
  /*0bfd mov ecx, ebx*/
    ecx = ebx;
  /*0bff mov dword ptr [edi + 0x48], 2*/
    *(unsigned*)((char*)(edi + 72)) = 2u;
  /*0c06 call FUN_0003ffa0*/
    ((O*)ecx)->FUN_0003ffa0(*(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*0c0b jmp 0d11*/
    goto L_0d11;
L_0c10:
  /*0c10 mov ecx, dword ptr [esp + 0x50]*/
    ecx = (*(unsigned*)((char*)S + 128));
  /*0c14 mov dword ptr [edi + 0x11c], ecx*/
    *(hulk_uintptr*)((char*)(edi + 284)) = ecx;
  /*0c1a mov edx, dword ptr [esp + 0x54]*/
    edx = (*(unsigned*)((char*)S + 132));
  /*0c1e mov ecx, dword ptr [esp + 0xb8]*/
    ecx = (*(unsigned*)((char*)S + 232));
  /*0c25 mov dword ptr [edi + 0x120], edx*/
    *(hulk_uintptr*)((char*)(edi + 288)) = edx;
  /*0c2b mov eax, dword ptr [esp + 0x58]*/
    eax = (*(unsigned*)((char*)S + 136));
  /*0c2f mov edx, dword ptr [esp + 0xbc]*/
    edx = (*(unsigned*)((char*)S + 236));
  /*0c36 mov dword ptr [edi + 0x124], eax*/
    *(hulk_uintptr*)((char*)(edi + 292)) = eax;
  /*0c3c mov eax, dword ptr [esp + 0xc0]*/
    eax = (*(unsigned*)((char*)S + 240));
  /*0c43 mov dword ptr [edi + 0x130], eax*/
    *(hulk_uintptr*)((char*)(edi + 304)) = eax;
  /*0c49 mov al, byte ptr [esp + 0x3f]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 111))) & 0xff) << 0);
  /*0c4d test al, al*/
  /*0c4f mov dword ptr [edi + 0x128], ecx*/
    *(hulk_uintptr*)((char*)(edi + 296)) = ecx;
  /*0c55 mov dword ptr [edi + 0x12c], edx*/
    *(hulk_uintptr*)((char*)(edi + 300)) = edx;
  /*0c5b je 0d0d*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) == 0) goto L_0d0d;
  /*0c61 fld dword ptr [esi + 0x98]*/
    fl72 = *(float*)((char*)(esi + 152));
  /*0c67 fchs */
  /*0c69 fcomp dword ptr [esi + 0x70]*/
    fl73 = *(float*)((char*)(esi + 112));
  /*0c6c fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW((-(fl72)), fl73)) & 0xffff);
  /*0c6e test ah, 0x41*/
  /*0c71 jne 0d0d*/
    if ((unsigned char)((((eax >> 8) & 0xff) & 65u)) != 0) goto L_0d0d;
  /*0c77 mov ebx, dword ptr [esp + 0x4c]*/
    ebx = (*(unsigned*)((char*)S + 124));
  /*0c7b mov ecx, dword ptr [ebx + 0x3a8]*/
    ecx = (*(unsigned*)((char*)(ebx + 936)));
  /*0c81 mov dword ptr [esi + 0x98], ecx*/
    *(hulk_uintptr*)((char*)(esi + 152)) = ecx;
  /*0c87 mov ecx, dword ptr [esp + 0xf0]*/
    ecx = (*(unsigned*)((char*)S + 288));
  /*0c8e call FUN_00078780*/
    fretv = ((O*)ecx)->FUN_00078780();
  /*0c93 fmul dword ptr [0x40d66c]*/
  /*0c99 fadd dword ptr [0x3f32dc]*/
  /*0c9f fmul dword ptr [esi + 0x98]*/
    fl74 = *(float*)((char*)(esi + 152));
  /*0ca5 fstp dword ptr [esi + 0x98]*/
    *(float*)((char*)(esi + 152)) = (float)(((((((fretv) * (0.5f))) + (1.0f))) * (fl74)));
  /*0cab fld dword ptr [ebx + 0x3a4]*/
    fl75 = *(float*)((char*)(ebx + 932));
  /*0cb1 fst dword ptr [esi + 0x94]*/
    *(float*)((char*)(esi + 148)) = (float)(fl75);
  /*0cb7 fld dword ptr [ebx + 0x3ac]*/
    fl76 = *(float*)((char*)(ebx + 940));
  /*0cbd fcom dword ptr [0x3f32e0]*/
  /*0cc3 fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fl76, 0.0f)) & 0xffff);
  /*0cc5 test ah, 0x41*/
  /*0cc8 jp 0cd2*/
    fpk0 = fl75;
    fpk1 = fl76;
    // WARNING fp stack live (2) at 0cc8
    if (PF8((((eax >> 8) & 0xff) & 65u))) goto L_0cd2;
  /*0cca fstp st(0)*/
  /*0ccc fld dword ptr [0x3f32dc]*/
    fpk0 = fpk0;
    fpk1 = 1.0f;
    // WARNING fp stack live (2) at 0cd2
L_0cd2:
  /*0cd2 fxch st(1)*/
  /*0cd4 mov ebx, dword ptr [esp + 0x5c]*/
    ebx = (*(unsigned*)((char*)S + 140));
  /*0cd8 fdiv st(1)*/
  /*0cda mov ecx, dword ptr [esp + 0x94]*/
    ecx = (*(unsigned*)((char*)S + 196));
  /*0ce1 push 1*/
    *(unsigned*)((char*)S + 44) = 1u;
  /*0ce3 lea eax, [esp + 0xac]*/
    eax = (hulk_uintptr)((char*)S + 216);
  /*0cea fstp dword ptr [esi + 0x70]*/
    *(float*)((char*)(esi + 112)) = (float)(((fpk0) / (fpk1)));
  /*0ced mov edx, dword ptr [ebx + 0x1cbc]*/
    edx = (*(unsigned*)((char*)(ebx + 7356)));
  /*0cf3 push edx*/
    *(unsigned*)((char*)S + 40) = edx;
  /*0cf4 mov edx, dword ptr [esp + 0x168]*/
    edx = (*(unsigned*)((char*)S + 400));
  /*0cfb fstp st(0)*/
  /*0cfd push eax*/
    *(unsigned*)((char*)S + 36) = eax;
  /*0cfe push ecx*/
    *(unsigned*)((char*)S + 32) = ecx;
  /*0cff mov ecx, dword ptr [edx + 0x20]*/
    ecx = (*(unsigned*)((char*)(edx + 32)));
  /*0d02 call FUN_00029250*/
    ((O*)ecx)->FUN_00029250(*(unsigned*)((char*)S + 32), *(unsigned*)((char*)S + 36), *(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*0d07 jmp 0d11*/
    goto L_0d11;
L_0d09:
  /*0d09 xor ebp, ebp*/
    ebp = 0;
  /*0d0b jmp 0d11*/
    goto L_0d11;
L_0d0d:
  /*0d0d mov ebx, dword ptr [esp + 0x5c]*/
    ebx = (*(unsigned*)((char*)S + 140));
L_0d11:
  /*0d11 mov al, byte ptr [esp + 0x3f]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 111))) & 0xff) << 0);
  /*0d15 test al, al*/
  /*0d17 mov dword ptr [esp + 0x70], 0*/
    *(unsigned*)((char*)S + 160) = 0u;
  /*0d1f mov dword ptr [esp + 0x74], 0*/
    *(unsigned*)((char*)S + 164) = 0u;
  /*0d27 mov dword ptr [esp + 0x78], 0*/
    *(unsigned*)((char*)S + 168) = 0u;
  /*0d2f mov dword ptr [esp + 0x88], 0*/
    *(unsigned*)((char*)S + 184) = 0u;
  /*0d3a mov dword ptr [esp + 0x8c], 0*/
    *(unsigned*)((char*)S + 188) = 0u;
  /*0d45 mov dword ptr [esp + 0x90], 0*/
    *(unsigned*)((char*)S + 192) = 0u;
  /*0d50 mov dword ptr [esp + 0xe0], 0*/
    *(unsigned*)((char*)S + 272) = 0u;
  /*0d5b mov dword ptr [esp + 0xe4], 0*/
    *(unsigned*)((char*)S + 276) = 0u;
  /*0d66 mov dword ptr [esp + 0xe8], 0*/
    *(unsigned*)((char*)S + 280) = 0u;
  /*0d71 mov dword ptr [esp + 0xd4], 0*/
    *(unsigned*)((char*)S + 260) = 0u;
  /*0d7c mov dword ptr [esp + 0xd8], 0*/
    *(unsigned*)((char*)S + 264) = 0u;
  /*0d87 mov dword ptr [esp + 0xdc], 0*/
    *(unsigned*)((char*)S + 268) = 0u;
  /*0d92 mov dword ptr [esp + 0x14], 0*/
    *(unsigned*)((char*)S + 68) = 0u;
  /*0d9a mov dword ptr [esp + 0x18], 0*/
    *(unsigned*)((char*)S + 72) = 0u;
  /*0da2 mov dword ptr [esp + 0x1c], 0*/
    *(unsigned*)((char*)S + 76) = 0u;
  /*0daa je 0ddb*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) == 0) goto L_0ddb;
  /*0dac mov al, byte ptr [esp + 0x12]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 66))) & 0xff) << 0);
  /*0db0 test al, al*/
  /*0db2 je 0ddb*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) == 0) goto L_0ddb;
  /*0db4 fld dword ptr [esp + 0x30]*/
    fl77 = *(float*)((char*)S + 96);
  /*0db8 fcomp dword ptr [esi + 0x84]*/
    fl78 = *(float*)((char*)(esi + 132));
  /*0dbe fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fl77, fl78)) & 0xffff);
  /*0dc0 test ah, 1*/
  /*0dc3 jne 0ddb*/
    if ((unsigned char)((((eax >> 8) & 0xff) & 1u)) != 0) goto L_0ddb;
  /*0dc5 fld dword ptr [esp + 0x30]*/
    fl79 = *(float*)((char*)S + 96);
  /*0dc9 mov byte ptr [esp + 0x13], 1*/
    *(unsigned char*)((char*)S + 67) = 1u;
  /*0dce fcomp dword ptr [esi + 0x88]*/
    fl80 = *(float*)((char*)(esi + 136));
  /*0dd4 fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fl79, fl80)) & 0xffff);
  /*0dd6 test ah, 0x41*/
  /*0dd9 jnp 0de0*/
    if (!PF8((((eax >> 8) & 0xff) & 65u))) goto L_0de0;
L_0ddb:
  /*0ddb mov byte ptr [esp + 0x13], 0*/
    *(unsigned char*)((char*)S + 67) = 0u;
L_0de0:
  /*0de0 mov eax, dword ptr [esi + 0x58]*/
    eax = (*(unsigned*)((char*)(esi + 88)));
  /*0de3 mov cl, byte ptr [eax + 0x129]*/
    ecx = (ecx & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)(eax + 297)))) & 0xff) << 0);
  /*0de9 test cl, cl*/
  /*0deb mov dword ptr [esp + 0x5c], 0x3fc00000*/
    *(unsigned*)((char*)S + 140) = 1069547520u;
  /*0df3 jne 0dfd*/
    if ((unsigned char)(((ecx & 0xff) & (ecx & 0xff))) != 0) goto L_0dfd;
  /*0df5 mov dword ptr [esp + 0x5c], 0x3f400000*/
    *(unsigned*)((char*)S + 140) = 1061158912u;
L_0dfd:
  /*0dfd mov edx, dword ptr [esp + 0x5c]*/
    edx = (*(unsigned*)((char*)S + 140));
  /*0e01 mov eax, dword ptr [esp + 0x160]*/
    eax = (*(unsigned*)((char*)S + 400));
  /*0e08 lea ecx, [esp + 0x70]*/
    ecx = (hulk_uintptr)((char*)S + 160);
  /*0e0c push ecx*/
    *(unsigned*)((char*)S + 44) = ecx;
  /*0e0d push edx*/
    *(unsigned*)((char*)S + 40) = edx;
  /*0e0e push ebx*/
    *(unsigned*)((char*)S + 36) = ebx;
  /*0e0f push eax*/
    *(unsigned*)((char*)S + 32) = eax;
  /*0e10 call FUN_0010b1c0*/
    fretv = FUN_0010b1c0(*(unsigned*)((char*)S + 32), *(unsigned*)((char*)S + 36), *(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*0e15 fst dword ptr [esp + 0x48]*/
    *(float*)((char*)S + 104) = (float)(fretv);
  /*0e19 fcomp dword ptr [0x3f32e0]*/
  /*0e1f add esp, 0x10*/
  /*0e22 fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fretv, 0.0f)) & 0xffff);
  /*0e24 test ah, 5*/
  /*0e27 jnp 0f00*/
    if (!PF8((((eax >> 8) & 0xff) & 5u))) goto L_0f00;
  /*0e2d fld dword ptr [esp + 0x38]*/
    fl81 = *(float*)((char*)S + 104);
  /*0e31 fcomp dword ptr [esp + 0x5c]*/
    fl82 = *(float*)((char*)S + 140);
  /*0e35 fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fl81, fl82)) & 0xffff);
  /*0e37 test ah, 0x41*/
  /*0e3a je 0f00*/
    if ((unsigned char)((((eax >> 8) & 0xff) & 65u)) == 0) goto L_0f00;
  /*0e40 mov ecx, dword ptr [esi + 0x58]*/
    ecx = (*(unsigned*)((char*)(esi + 88)));
  /*0e43 mov byte ptr [ecx + 0x129], 1*/
    *(unsigned char*)((char*)(ecx + 297)) = 1u;
  /*0e4a lea ecx, [esp + 0x70]*/
    ecx = (hulk_uintptr)((char*)S + 160);
  /*0e4e call FUN_0022d110*/
    fretv = ((O*)ecx)->FUN_0022d110();
  /*0e53 fstp st(0)*/
  /*0e55 mov al, byte ptr [esp + 0x10]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 64))) & 0xff) << 0);
  /*0e59 test al, al*/
  /*0e5b jne 0ebd*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) != 0) goto L_0ebd;
  /*0e5d fld dword ptr [esp + 0x38]*/
    fl83 = *(float*)((char*)S + 104);
  /*0e61 fcomp dword ptr [0x3f3f10]*/
  /*0e67 fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fl83, 0.75f)) & 0xffff);
  /*0e69 test ah, 0x41*/
  /*0e6c jne 0ebd*/
    if ((unsigned char)((((eax >> 8) & 0xff) & 65u)) != 0) goto L_0ebd;
  /*0e6e mov al, byte ptr [esp + 0x13]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 67))) & 0xff) << 0);
  /*0e72 test al, al*/
  /*0e74 je 0ebd*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) == 0) goto L_0ebd;
  /*0e76 fld dword ptr [esp + 0x70]*/
    fl84 = *(float*)((char*)S + 160);
  /*0e7a fmul dword ptr [esp + 0x50]*/
    fl85 = *(float*)((char*)S + 128);
  /*0e7e fld dword ptr [esp + 0x78]*/
    fl86 = *(float*)((char*)S + 168);
  /*0e82 fmul dword ptr [esp + 0x58]*/
    fl87 = *(float*)((char*)S + 136);
  /*0e86 faddp st(1)*/
  /*0e88 fld dword ptr [esp + 0x74]*/
    fl88 = *(float*)((char*)S + 164);
  /*0e8c fmul dword ptr [esp + 0x54]*/
    fl89 = *(float*)((char*)S + 132);
  /*0e90 faddp st(1)*/
  /*0e92 fcomp dword ptr [0x3ff9fc]*/
  /*0e98 fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(((((((fl84) * (fl85))) + (((fl86) * (fl87))))) + (((fl88) * (fl89)))), 0.899999976f)) & 0xffff);
  /*0e9a test ah, 0x41*/
  /*0e9d jne 0ebd*/
    if ((unsigned char)((((eax >> 8) & 0xff) & 65u)) != 0) goto L_0ebd;
  /*0e9f mov edx, dword ptr [esi + 0x58]*/
    edx = (*(unsigned*)((char*)(esi + 88)));
  /*0ea2 mov byte ptr [esi + 0x6c], 1*/
    *(unsigned char*)((char*)(esi + 108)) = 1u;
  /*0ea6 mov byte ptr [edx + 0x129], 0*/
    *(unsigned char*)((char*)(edx + 297)) = 0u;
  /*0ead mov byte ptr [esi + 0x80], 0*/
    *(unsigned char*)((char*)(esi + 128)) = 0u;
  /*0eb4 mov byte ptr [esi + 0x81], 0*/
    *(unsigned char*)((char*)(esi + 129)) = 0u;
  /*0ebb jmp 0f0a*/
    goto L_0f0a;
L_0ebd:
  /*0ebd fld dword ptr [esp + 0x5c]*/
    fl90 = *(float*)((char*)S + 140);
  /*0ec1 lea eax, [esp + 0x98]*/
    eax = (hulk_uintptr)((char*)S + 200);
  /*0ec8 fsub dword ptr [esp + 0x38]*/
    fl91 = *(float*)((char*)S + 104);
  /*0ecc push eax*/
    *(unsigned*)((char*)S + 44) = eax;
  /*0ecd lea ecx, [esp + 0x50]*/
    ecx = (hulk_uintptr)((char*)S + 124);
  /*0ed1 push ecx*/
    *(unsigned*)((char*)S + 40) = ecx;
  /*0ed2 fdiv dword ptr [esp + 0x64]*/
    fl92 = *(float*)((char*)S + 140);
  /*0ed6 mov dword ptr [esp + 0x54], 0x3f800000*/
    *(unsigned*)((char*)S + 124) = 1065353216u;
  /*0ede fstp dword ptr [esp + 0xa0]*/
    *(float*)((char*)S + 200) = (float)(((((fl90) - (fl91))) / (fl92)));
  /*0ee5 call FUN_000186f0*/
    fretv = FUN_000186f0(*(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*0eea fstp dword ptr [esp + 4]*/
    *(float*)((char*)S + 44) = (float)(fretv);
  /*0eee add esp, 4*/
  /*0ef1 lea ecx, [esp + 0x74]*/
    ecx = (hulk_uintptr)((char*)S + 160);
  /*0ef5 call FUN_000344b0*/
    ((O*)ecx)->FUN_000344b0(*(unsigned*)((char*)S + 44));
  /*0efa mov byte ptr [esi + 0x6c], 0*/
    *(unsigned char*)((char*)(esi + 108)) = 0u;
  /*0efe jmp 0f22*/
    goto L_0f22;
L_0f00:
  /*0f00 mov edx, dword ptr [esi + 0x58]*/
    edx = (*(unsigned*)((char*)(esi + 88)));
  /*0f03 mov byte ptr [edx + 0x129], 0*/
    *(unsigned char*)((char*)(edx + 297)) = 0u;
L_0f0a:
  /*0f0a mov dword ptr [esp + 0x78], 0*/
    *(unsigned*)((char*)S + 168) = 0u;
  /*0f12 mov dword ptr [esp + 0x74], 0*/
    *(unsigned*)((char*)S + 164) = 0u;
  /*0f1a mov dword ptr [esp + 0x70], 0*/
    *(unsigned*)((char*)S + 160) = 0u;
L_0f22:
  /*0f22 fld dword ptr [esi + 0x78]*/
    fl93 = *(float*)((char*)(esi + 120));
  /*0f25 fcomp dword ptr [0x3f32e0]*/
  /*0f2b fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fl93, 0.0f)) & 0xffff);
  /*0f2d test ah, 0x41*/
  /*0f30 jp 0f59*/
    if (PF8((((eax >> 8) & 0xff) & 65u))) goto L_0f59;
  /*0f32 fld dword ptr [esi + 0x7c]*/
    fl94 = *(float*)((char*)(esi + 124));
  /*0f35 mov ecx, dword ptr [esp + 0xf0]*/
    ecx = (*(unsigned*)((char*)S + 288));
  /*0f3c fmul dword ptr [0x3f3388]*/
  /*0f42 fstp dword ptr [esi + 0x7c]*/
    *(float*)((char*)(esi + 124)) = (float)(((fl94) * (-1.0f)));
  /*0f45 call FUN_00078780*/
    fretv = ((O*)ecx)->FUN_00078780();
  /*0f4a fmul dword ptr [0x40d6fc]*/
  /*0f50 fadd dword ptr [0x3f3318]*/
  /*0f56 fstp dword ptr [esi + 0x78]*/
    *(float*)((char*)(esi + 120)) = (float)(((((fretv) * (3.0f))) + (4.0f)));
L_0f59:
  /*0f59 lea eax, [esp + 0x24]*/
    eax = (hulk_uintptr)((char*)S + 84);
  /*0f5d push eax*/
    *(unsigned*)((char*)S + 44) = eax;
  /*0f5e lea ecx, [esp + 0x54]*/
    ecx = (hulk_uintptr)((char*)S + 128);
  /*0f62 push ecx*/
    *(unsigned*)((char*)S + 40) = ecx;
  /*0f63 lea ecx, [esp + 0xdc]*/
    ecx = (hulk_uintptr)((char*)S + 260);
  /*0f6a mov dword ptr [esp + 0x2c], 0*/
    *(unsigned*)((char*)S + 84) = 0u;
  /*0f72 mov dword ptr [esp + 0x30], 0x3f800000*/
    *(unsigned*)((char*)S + 88) = 1065353216u;
  /*0f7a mov dword ptr [esp + 0x34], 0*/
    *(unsigned*)((char*)S + 92) = 0u;
  /*0f82 call FUN_000111b0*/
    ((O*)ecx)->FUN_000111b0(*(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*0f87 fld dword ptr [esi + 0x7c]*/
    fl95 = *(float*)((char*)(esi + 124));
  /*0f8a fld dword ptr [esp + 0xd4]*/
    fl96 = *(float*)((char*)S + 260);
  /*0f91 lea ecx, [esp + 0xd4]*/
    ecx = (hulk_uintptr)((char*)S + 260);
  /*0f98 fmul st(1)*/
  /*0f9a fstp dword ptr [esp + 0xd4]*/
    *(float*)((char*)S + 260) = (float)(((fl96) * (fl95)));
  /*0fa1 fld dword ptr [esp + 0xd8]*/
    fl97 = *(float*)((char*)S + 264);
  /*0fa8 fmul st(1)*/
  /*0faa fstp dword ptr [esp + 0xd8]*/
    *(float*)((char*)S + 264) = (float)(((fl97) * (fl95)));
  /*0fb1 fmul dword ptr [esp + 0xdc]*/
    fl98 = *(float*)((char*)S + 268);
  /*0fb8 fstp dword ptr [esp + 0xdc]*/
    *(float*)((char*)S + 268) = (float)(((fl95) * (fl98)));
  /*0fbf call FUN_0022d110*/
    fretv = ((O*)ecx)->FUN_0022d110();
  /*0fc4 mov al, byte ptr [esp + 0x63]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 147))) & 0xff) << 0);
  /*0fc8 fstp st(0)*/
  /*0fca test al, al*/
  /*0fcc fld dword ptr [esi + 0x90]*/
    fl99 = *(float*)((char*)(esi + 144));
  /*0fd2 fsub dword ptr [esi + 0x8c]*/
    fl100 = *(float*)((char*)(esi + 140));
  /*0fd8 mov dword ptr [esp + 0x40], 0*/
    *(unsigned*)((char*)S + 112) = 0u;
  /*0fe0 mov dword ptr [esp + 0x44], 0*/
    *(unsigned*)((char*)S + 116) = 0u;
  /*0fe8 mov dword ptr [esp + 0x48], 0*/
    *(unsigned*)((char*)S + 120) = 0u;
  /*0ff0 fmul dword ptr [0x409004]*/
  /*0ff6 fstp dword ptr [esp + 0x4c]*/
    *(float*)((char*)S + 124) = (float)(((((fl99) - (fl100))) * (0.25f)));
  /*0ffa je 13a7*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) == 0) goto L_13a7;
  /*1000 mov ecx, dword ptr [esp + 0x160]*/
    ecx = (*(unsigned*)((char*)S + 400));
  /*1007 lea edx, [esp + 0x40]*/
    edx = (hulk_uintptr)((char*)S + 112);
  /*100b push edx*/
    *(unsigned*)((char*)S + 44) = edx;
  /*100c lea eax, [esp + 0xe4]*/
    eax = (hulk_uintptr)((char*)S + 272);
  /*1013 push eax*/
    *(unsigned*)((char*)S + 40) = eax;
  /*1014 push ebx*/
    *(unsigned*)((char*)S + 36) = ebx;
  /*1015 push ecx*/
    *(unsigned*)((char*)S + 32) = ecx;
  /*1016 mov ecx, esi*/
    ecx = esi;
  /*1018 call FUN_00107760*/
    eax = (unsigned)((O*)ecx)->FUN_00107760(*(unsigned*)((char*)S + 32), *(unsigned*)((char*)S + 36), *(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*101d test al, al*/
  /*101f je 13a7*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) == 0) goto L_13a7;
  /*1025 mov al, byte ptr [esp + 0x23]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 83))) & 0xff) << 0);
  /*1029 test al, al*/
  /*102b jne 13a7*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) != 0) goto L_13a7;
  /*1031 fld dword ptr [esp + 0xa8]*/
    fl101 = *(float*)((char*)S + 216);
  /*1038 mov ecx, dword ptr [esp + 0xb0]*/
    ecx = (*(unsigned*)((char*)S + 224));
  /*103f fsub dword ptr [esp + 0x40]*/
    fl102 = *(float*)((char*)S + 112);
  /*1043 mov edx, dword ptr [esp + 0xa8]*/
    edx = (*(unsigned*)((char*)S + 216));
  /*104a mov eax, dword ptr [esp + 0xac]*/
    eax = (*(unsigned*)((char*)S + 220));
  /*1051 mov dword ptr [esp + 0x84], ecx*/
    *(unsigned*)((char*)S + 180) = ecx;
  /*1058 fstp dword ptr [esp + 0x24]*/
    *(float*)((char*)S + 84) = (float)(((fl101) - (fl102)));
  /*105c lea ecx, [esp + 0x24]*/
    ecx = (hulk_uintptr)((char*)S + 84);
  /*1060 fld dword ptr [esp + 0xac]*/
    fl103 = *(float*)((char*)S + 220);
  /*1067 mov dword ptr [esi + 0xac], ebp*/
    *(hulk_uintptr*)((char*)(esi + 172)) = ebp;
  /*106d fsub dword ptr [esp + 0x44]*/
    fl104 = *(float*)((char*)S + 116);
  /*1071 mov dword ptr [esp + 0x7c], edx*/
    *(unsigned*)((char*)S + 172) = edx;
  /*1075 mov dword ptr [esp + 0x80], eax*/
    *(unsigned*)((char*)S + 176) = eax;
  /*107c fstp dword ptr [esp + 0x28]*/
    *(float*)((char*)S + 88) = (float)(((fl103) - (fl104)));
  /*1080 fld dword ptr [esp + 0xb0]*/
    fl105 = *(float*)((char*)S + 224);
  /*1087 fsub dword ptr [esp + 0x48]*/
    fl106 = *(float*)((char*)S + 120);
  /*108b fstp dword ptr [esp + 0x2c]*/
    *(float*)((char*)S + 92) = (float)(((fl105) - (fl106)));
  /*108f call FUN_00018990*/
    fretv = ((O*)ecx)->FUN_00018990();
  /*1094 push ecx*/
    *(unsigned*)((char*)S + 44) = ecx;
  /*1095 lea edx, [esp + 0xe4]*/
    edx = (hulk_uintptr)((char*)S + 272);
  /*109c fstp dword ptr [esp]*/
    *(float*)((char*)S + 44) = (float)(fretv);
  /*109f push edx*/
    *(unsigned*)((char*)S + 40) = edx;
  /*10a0 lea eax, [esp + 0xfc]*/
    eax = (hulk_uintptr)((char*)S + 292);
  /*10a7 push eax*/
    *(unsigned*)((char*)S + 36) = eax;
  /*10a8 call FUN_00083e00*/
    eax = (unsigned)FUN_00083e00(*(unsigned*)((char*)S + 36), *(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*10ad fld dword ptr [esp + 0x90]*/
    fl107 = *(float*)((char*)S + 180);
  /*10b4 fadd dword ptr [eax + 8]*/
    fl108 = *(float*)((char*)(eax + 8));
  /*10b7 lea ecx, [esp + 0x6e]*/
    ecx = (hulk_uintptr)((char*)S + 146);
  /*10bb fld dword ptr [esp + 0x88]*/
    fl109 = *(float*)((char*)S + 172);
  /*10c2 push ecx*/
    *(unsigned*)((char*)S + 32) = ecx;
  /*10c3 fadd dword ptr [eax]*/
    fl110 = *(float*)((char*)(eax));
  /*10c5 lea edx, [esp + 0x73]*/
    edx = (hulk_uintptr)((char*)S + 147);
  /*10c9 push edx*/
    *(unsigned*)((char*)S + 28) = edx;
  /*10ca lea eax, [esp + 0x108]*/
    eax = (hulk_uintptr)((char*)S + 292);
  /*10d1 fstp dword ptr [esp + 0x38]*/
    *(float*)((char*)S + 84) = (float)(((fl109) + (fl110)));
  /*10d5 push eax*/
    *(unsigned*)((char*)S + 24) = eax;
  /*10d6 lea ecx, [esp + 0xd0]*/
    ecx = (hulk_uintptr)((char*)S + 232);
  /*10dd fstp dword ptr [esp + 0x44]*/
    *(float*)((char*)S + 92) = (float)(((fl107) + (fl108)));
  /*10e1 push ecx*/
    *(unsigned*)((char*)S + 20) = ecx;
  /*10e2 fld dword ptr [esp + 0x9c]*/
    fl111 = *(float*)((char*)S + 176);
  /*10e9 mov ecx, dword ptr [0x4dd700]*/
    ecx = DAT_004dd700;
  /*10ef fadd dword ptr [0x3f75a8]*/
  /*10f5 lea edx, [esp + 0x40]*/
    edx = (hulk_uintptr)((char*)S + 84);
  /*10f9 push edx*/
    *(unsigned*)((char*)S + 16) = edx;
  /*10fa lea eax, [esp + 0x9c]*/
    eax = (hulk_uintptr)((char*)S + 172);
  /*1101 push eax*/
    *(unsigned*)((char*)S + 12) = eax;
  /*1102 fst dword ptr [esp + 0xa4]*/
    *(float*)((char*)S + 176) = (float)(((fl111) + (1.25f)));
  /*1109 push ecx*/
    *(unsigned*)((char*)S + 8) = ecx;
  /*110a fstp dword ptr [esp + 0x50]*/
    *(float*)((char*)S + 88) = (float)(((fl111) + (1.25f)));
  /*110e call FUN_00036b10*/
    eax = (unsigned)FUN_00036b10(*(unsigned*)((char*)S + 8), *(unsigned*)((char*)S + 12), *(unsigned*)((char*)S + 16), *(unsigned*)((char*)S + 20), *(unsigned*)((char*)S + 24), *(unsigned*)((char*)S + 28), *(unsigned*)((char*)S + 32));
  /*1113 add esp, 0x28*/
  /*1116 test al, al*/
  /*1118 jne 118a*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) != 0) goto L_118a;
  /*111a mov ecx, dword ptr [esi + 0x58]*/
    ecx = (*(unsigned*)((char*)(esi + 88)));
  /*111d call FUN_000fefc0*/
    eax = (unsigned)((O*)ecx)->FUN_000fefc0();
  /*1122 mov ebp, eax*/
    ebp = eax;
  /*1124 push esi*/
    *(unsigned*)((char*)S + 44) = esi;
  /*1125 mov ecx, ebp*/
    ecx = ebp;
  /*1127 call FUN_001048d0*/
    ((O*)ecx)->FUN_001048d0(*(unsigned*)((char*)S + 44));
  /*112c mov ecx, dword ptr [0x4dd700]*/
    ecx = DAT_004dd700;
  /*1132 push 0x3f800000*/
    *(unsigned*)((char*)S + 44) = 1065353216u;
  /*1137 push 0x3f000000*/
    *(unsigned*)((char*)S + 40) = 1056964608u;
  /*113c push 0*/
    *(unsigned*)((char*)S + 36) = 0u;
  /*113e push 0x3f800000*/
    *(unsigned*)((char*)S + 32) = 1065353216u;
  /*1143 lea edx, [esp + 0x34]*/
    edx = (hulk_uintptr)((char*)S + 84);
  /*1147 push edx*/
    *(unsigned*)((char*)S + 28) = edx;
  /*1148 lea eax, [esp + 0xbc]*/
    eax = (hulk_uintptr)((char*)S + 216);
  /*114f push eax*/
    *(unsigned*)((char*)S + 24) = eax;
  /*1150 push ecx*/
    *(unsigned*)((char*)S + 20) = ecx;
  /*1151 mov ecx, ebp*/
    ecx = ebp;
  /*1153 call FUN_00104c60*/
    ((O*)ecx)->FUN_00104c60(*(unsigned*)((char*)S + 20), *(unsigned*)((char*)S + 24), *(unsigned*)((char*)S + 28), *(unsigned*)((char*)S + 32), *(unsigned*)((char*)S + 36), *(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*1158 mov eax, dword ptr [esp + 0x164]*/
    eax = (*(unsigned*)((char*)S + 404));
  /*115f mov ecx, dword ptr [0x4dd700]*/
    ecx = DAT_004dd700;
  /*1165 mov edx, dword ptr [ebp]*/
    vo_edx = ebp;
    edx = (*(unsigned*)((char*)(ebp)));
  /*1168 push 0*/
    *(unsigned*)((char*)S + 44) = 0u;
  /*116a push eax*/
    *(unsigned*)((char*)S + 40) = eax;
  /*116b push ecx*/
    *(unsigned*)((char*)S + 36) = ecx;
  /*116c mov ecx, ebp*/
    ecx = ebp;
  /*116e call dword ptr [edx + 0x10]*/
    eax = (unsigned)((VC3*)vo_edx)->vcall(*(unsigned*)((char*)S + 36), *(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
L_1171:
  /*1171 xor ebp, ebp*/
    ebp = 0;
L_1173:
  /*1173 mov al, byte ptr [esp + 0x37]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 103))) & 0xff) << 0);
  /*1177 test al, al*/
  /*1179 jne 1c2a*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) != 0) goto L_1c2a;
L_117f:
  /*117f mov dword ptr [edi + 0x110], ebp*/
    *(hulk_uintptr*)((char*)(edi + 272)) = ebp;
  /*1185 jmp 1d32*/
    goto L_1d32;
L_118a:
  /*118a mov edx, dword ptr [esi + 0x58]*/
    edx = (*(unsigned*)((char*)(esi + 88)));
  /*118d mov dword ptr [esp + 0x78], 0*/
    *(unsigned*)((char*)S + 168) = 0u;
  /*1195 mov dword ptr [esp + 0x74], 0*/
    *(unsigned*)((char*)S + 164) = 0u;
  /*119d mov dword ptr [esp + 0x70], 0*/
    *(unsigned*)((char*)S + 160) = 0u;
  /*11a5 mov al, byte ptr [edx + 0x129]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)(edx + 297)))) & 0xff) << 0);
  /*11ab test al, al*/
  /*11ad mov dword ptr [esp + 0x4c], 0x3fc00000*/
    *(unsigned*)((char*)S + 124) = 1069547520u;
  /*11b5 jne 11bf*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) != 0) goto L_11bf;
  /*11b7 mov dword ptr [esp + 0x4c], 0x3f7d70a4*/
    *(unsigned*)((char*)S + 124) = 1065185444u;
L_11bf:
  /*11bf mov edx, dword ptr [0x4dd700]*/
    edx = DAT_004dd700;
  /*11c5 push ebp*/
    *(unsigned*)((char*)S + 44) = ebp;
  /*11c6 push 1*/
    *(unsigned*)((char*)S + 40) = 1u;
  /*11c8 lea eax, [esp + 0x78]*/
    eax = (hulk_uintptr)((char*)S + 160);
  /*11cc push eax*/
    *(unsigned*)((char*)S + 36) = eax;
  /*11cd lea ecx, [esp + 0xa4]*/
    ecx = (hulk_uintptr)((char*)S + 200);
  /*11d4 push ecx*/
    *(unsigned*)((char*)S + 32) = ecx;
  /*11d5 push 0x3fc00000*/
    *(unsigned*)((char*)S + 28) = 1069547520u;
  /*11da push ebx*/
    *(unsigned*)((char*)S + 24) = ebx;
  /*11db push edx*/
    *(unsigned*)((char*)S + 20) = edx;
  /*11dc call FUN_0010ae50*/
    fretv = FUN_0010ae50(*(unsigned*)((char*)S + 20), *(unsigned*)((char*)S + 24), *(unsigned*)((char*)S + 28), *(unsigned*)((char*)S + 32), *(unsigned*)((char*)S + 36), *(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*11e1 fcom dword ptr [0x3f32e0]*/
  /*11e7 add esp, 0x1c*/
  /*11ea fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fretv, 0.0f)) & 0xffff);
  /*11ec test ah, 5*/
  /*11ef jnp 1208*/
    fpk0 = fretv;
    // WARNING fp stack live (1) at 11ef
    if (!PF8((((eax >> 8) & 0xff) & 5u))) goto L_1208;
  /*11f1 fcomp dword ptr [esp + 0x4c]*/
    fl112 = *(float*)((char*)S + 124);
  /*11f5 fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fpk0, fl112)) & 0xffff);
  /*11f7 test ah, 0x41*/
  /*11fa je 120a*/
    if ((unsigned char)((((eax >> 8) & 0xff) & 65u)) == 0) goto L_120a;
  /*11fc mov eax, dword ptr [esi + 0x58]*/
    eax = (*(unsigned*)((char*)(esi + 88)));
  /*11ff mov byte ptr [eax + 0x129], 1*/
    *(unsigned char*)((char*)(eax + 297)) = 1u;
  /*1206 jmp 122c*/
    goto L_122c;
L_1208:
  /*1208 fstp st(0)*/
L_120a:
  /*120a mov ecx, dword ptr [esi + 0x58]*/
    ecx = (*(unsigned*)((char*)(esi + 88)));
  /*120d mov byte ptr [ecx + 0x129], 0*/
    *(unsigned char*)((char*)(ecx + 297)) = 0u;
  /*1214 mov dword ptr [esp + 0x78], 0*/
    *(unsigned*)((char*)S + 168) = 0u;
  /*121c mov dword ptr [esp + 0x74], 0*/
    *(unsigned*)((char*)S + 164) = 0u;
  /*1224 mov dword ptr [esp + 0x70], 0*/
    *(unsigned*)((char*)S + 160) = 0u;
L_122c:
  /*122c mov eax, dword ptr [esi + 0x5c]*/
    eax = (*(unsigned*)((char*)(esi + 92)));
  /*122f mov edx, dword ptr [esp + 0xe0]*/
    edx = (*(unsigned*)((char*)S + 272));
  /*1236 mov dword ptr [eax + 0x10], edx*/
    *(hulk_uintptr*)((char*)(eax + 16)) = edx;
  /*1239 mov ecx, dword ptr [esp + 0xe4]*/
    ecx = (*(unsigned*)((char*)S + 276));
  /*1240 add eax, 0x10*/
    eax = (unsigned)(eax + 16u);
  /*1243 mov dword ptr [eax + 4], ecx*/
    *(hulk_uintptr*)((char*)(eax + 4)) = ecx;
  /*1246 mov edx, dword ptr [esp + 0xe8]*/
    edx = (*(unsigned*)((char*)S + 280));
  /*124d mov dword ptr [eax + 8], edx*/
    *(hulk_uintptr*)((char*)(eax + 8)) = edx;
  /*1250 mov edx, dword ptr [esp + 0x164]*/
    edx = (*(unsigned*)((char*)S + 404));
  /*1257 mov ecx, dword ptr [esi + 0x5c]*/
    ecx = (*(unsigned*)((char*)(esi + 92)));
  /*125a mov eax, dword ptr [ecx]*/
    vo_eax = ecx;
    eax = (*(unsigned*)((char*)(ecx)));
  /*125c push 0*/
    *(unsigned*)((char*)S + 44) = 0u;
  /*125e push edx*/
    *(unsigned*)((char*)S + 40) = edx;
  /*125f lea edx, [esp + 0x90]*/
    edx = (hulk_uintptr)((char*)S + 184);
  /*1266 push edx*/
    *(unsigned*)((char*)S + 36) = edx;
  /*1267 mov edx, dword ptr [0x4dd700]*/
    edx = DAT_004dd700;
  /*126d push ebx*/
    *(unsigned*)((char*)S + 32) = ebx;
  /*126e push edx*/
    *(unsigned*)((char*)S + 28) = edx;
  /*126f call dword ptr [eax + 0xc]*/
    ((VC4*)vo_eax)->vcall(*(unsigned*)((char*)S + 28), *(unsigned*)((char*)S + 32), *(unsigned*)((char*)S + 36), *(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*1272 fld dword ptr [esp + 0x88]*/
    fl113 = *(float*)((char*)S + 184);
  /*1279 mov ecx, dword ptr [0x4a1e38]*/
    ecx = (*(unsigned*)&DAT_004a1e38);
  /*127f fadd st(0), st(0)*/
  /*1281 lea eax, [esp + 0x70]*/
    eax = (hulk_uintptr)((char*)S + 160);
  /*1285 push eax*/
    *(unsigned*)((char*)S + 44) = eax;
  /*1286 fstp dword ptr [esp + 0x8c]*/
    *(float*)((char*)S + 184) = (float)(((fl113) + (fl113)));
  /*128d push ecx*/
    *(unsigned*)((char*)S + 40) = ecx;
  /*128e fld dword ptr [esp + 0x94]*/
    fl114 = *(float*)((char*)S + 188);
  /*1295 lea edx, [esp + 0x48]*/
    edx = (hulk_uintptr)((char*)S + 112);
  /*1299 fadd st(0), st(0)*/
  /*129b push edx*/
    *(unsigned*)((char*)S + 36) = edx;
  /*129c lea ebp, [esi + 0x60]*/
    ebp = (hulk_uintptr)((char*)(esi + 96));
  /*129f fstp dword ptr [esp + 0x98]*/
    *(float*)((char*)S + 188) = (float)(((fl114) + (fl114)));
  /*12a6 fld dword ptr [esp + 0x9c]*/
    fl115 = *(float*)((char*)S + 192);
  /*12ad fadd st(0), st(0)*/
  /*12af fstp dword ptr [esp + 0x9c]*/
    *(float*)((char*)S + 192) = (float)(((fl115) + (fl115)));
  /*12b6 call FUN_00083dd0*/
    eax = (unsigned)FUN_00083dd0(*(unsigned*)((char*)S + 36), *(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*12bb fld dword ptr [0x3f32dc]*/
  /*12c1 add esp, 0xc*/
  /*12c4 fsub dword ptr [0x4a1e38]*/
    fl116 = *(float*)&(*(unsigned*)&DAT_004a1e38);
  /*12ca push eax*/
    *(unsigned*)((char*)S + 44) = eax;
  /*12cb lea eax, [esp + 0x114]*/
    eax = (hulk_uintptr)((char*)S + 320);
  /*12d2 push eax*/
    *(unsigned*)((char*)S + 40) = eax;
  /*12d3 push ebp*/
    *(unsigned*)((char*)S + 36) = ebp;
  /*12d4 push ecx*/
    *(unsigned*)((char*)S + 32) = ecx;
  /*12d5 lea ecx, [esp + 0x110]*/
    ecx = (hulk_uintptr)((char*)S + 304);
  /*12dc fstp dword ptr [esp]*/
    *(float*)((char*)S + 32) = (float)(((1.0f) - (fl116)));
  /*12df push ecx*/
    *(unsigned*)((char*)S + 28) = ecx;
  /*12e0 call FUN_00083dd0*/
    eax = (unsigned)FUN_00083dd0(*(unsigned*)((char*)S + 28), *(unsigned*)((char*)S + 32), *(unsigned*)((char*)S + 36));
  /*12e5 add esp, 0xc*/
  /*12e8 mov ecx, eax*/
    ecx = eax;
  /*12ea call FUN_00078750*/
    eax = (unsigned)((O*)ecx)->FUN_00078750(*(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*12ef fld dword ptr [esp + 0xe0]*/
    fl117 = *(float*)((char*)S + 272);
  /*12f6 mov edx, dword ptr [eax]*/
    vo_edx = eax;
    edx = (*(unsigned*)((char*)(eax)));
  /*12f8 mov dword ptr [ebp], edx*/
    *(hulk_uintptr*)((char*)(ebp)) = edx;
  /*12fb mov ecx, dword ptr [eax + 4]*/
    ecx = (*(unsigned*)((char*)(eax + 4)));
  /*12fe mov dword ptr [ebp + 4], ecx*/
    *(hulk_uintptr*)((char*)(ebp + 4)) = ecx;
  /*1301 mov edx, dword ptr [eax + 8]*/
    edx = (*(unsigned*)((char*)(eax + 8)));
  /*1304 mov dword ptr [ebp + 8], edx*/
    *(hulk_uintptr*)((char*)(ebp + 8)) = edx;
  /*1307 fadd dword ptr [ebp]*/
    fl118 = *(float*)((char*)(ebp));
  /*130a fld dword ptr [esp + 0xe8]*/
    fl119 = *(float*)((char*)S + 280);
  /*1311 lea ecx, [esp + 0x14]*/
    ecx = (hulk_uintptr)((char*)S + 68);
  /*1315 fadd dword ptr [ebp + 8]*/
    fl120 = *(float*)((char*)(ebp + 8));
  /*1318 mov dword ptr [esp + 0x18], 0*/
    *(unsigned*)((char*)S + 72) = 0u;
  /*1320 fstp dword ptr [esp + 0x48]*/
    *(float*)((char*)S + 120) = (float)(((fl119) + (fl120)));
  /*1324 fadd dword ptr [esp + 0x88]*/
    fl121 = *(float*)((char*)S + 184);
  /*132b fld dword ptr [esp + 0x48]*/
    fl122 = *(float*)((char*)S + 120);
  /*132f fadd dword ptr [esp + 0x90]*/
    fl123 = *(float*)((char*)S + 192);
  /*1336 fxch st(1)*/
  /*1338 fstp dword ptr [esp + 0x14]*/
    *(float*)((char*)S + 68) = (float)(((((fl117) + (fl118))) + (fl121)));
  /*133c fstp dword ptr [esp + 0x1c]*/
    *(float*)((char*)S + 76) = (float)(((fl122) + (fl123)));
  /*1340 call FUN_0022d110*/
    fretv = ((O*)ecx)->FUN_0022d110();
  /*1345 fcom dword ptr [0x3f32dc]*/
  /*134b fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fretv, 1.0f)) & 0xffff);
  /*134d test ah, 0x41*/
  /*1350 jne 1360*/
    fpk0 = fretv;
    // WARNING fp stack live (1) at 1350
    if ((unsigned char)((((eax >> 8) & 0xff) & 65u)) != 0) goto L_1360;
  /*1352 fstp st(0)*/
  /*1354 mov dword ptr [edi + 0x118], 0x3f800000*/
    *(unsigned*)((char*)(edi + 280)) = 1065353216u;
  /*135e jmp 1366*/
    goto L_1366;
L_1360:
  /*1360 fstp dword ptr [edi + 0x118]*/
    *(float*)((char*)(edi + 280)) = (float)(fpk0);
L_1366:
  /*1366 mov eax, dword ptr [esp + 0x50]*/
    eax = (*(unsigned*)((char*)S + 128));
  /*136a mov dword ptr [edi + 0x11c], eax*/
    *(hulk_uintptr*)((char*)(edi + 284)) = eax;
  /*1370 mov ecx, dword ptr [esp + 0x54]*/
    ecx = (*(unsigned*)((char*)S + 132));
  /*1374 mov dword ptr [edi + 0x120], ecx*/
    *(hulk_uintptr*)((char*)(edi + 288)) = ecx;
  /*137a mov edx, dword ptr [esp + 0x58]*/
    edx = (*(unsigned*)((char*)S + 136));
  /*137e mov dword ptr [edi + 0x124], edx*/
    *(hulk_uintptr*)((char*)(edi + 292)) = edx;
L_1384:
  /*1384 mov eax, dword ptr [esp + 0x14]*/
    eax = (*(unsigned*)((char*)S + 68));
  /*1388 mov dword ptr [edi + 0x10c], eax*/
    *(hulk_uintptr*)((char*)(edi + 268)) = eax;
  /*138e mov ecx, dword ptr [esp + 0x18]*/
    ecx = (*(unsigned*)((char*)S + 72));
  /*1392 mov dword ptr [edi + 0x110], ecx*/
    *(hulk_uintptr*)((char*)(edi + 272)) = ecx;
  /*1398 mov edx, dword ptr [esp + 0x1c]*/
    edx = (*(unsigned*)((char*)S + 76));
  /*139c mov dword ptr [edi + 0x114], edx*/
    *(hulk_uintptr*)((char*)(edi + 276)) = edx;
  /*13a2 jmp 1171*/
    goto L_1171;
L_13a7:
  /*13a7 mov ecx, dword ptr [esp + 0xd0]*/
    ecx = (*(unsigned*)((char*)S + 256));
  /*13ae call FUN_000fc830*/
    fretv = ((O*)ecx)->FUN_000fc830();
  /*13b3 fcomp qword ptr [0x40d6d0]*/
  /*13b9 fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fretv, 2.5)) & 0xffff);
  /*13bb test ah, 1*/
  /*13be jne 1479*/
    if ((unsigned char)((((eax >> 8) & 0xff) & 1u)) != 0) goto L_1479;
  /*13c4 mov al, byte ptr [esp + 0x62]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 146))) & 0xff) << 0);
  /*13c8 test al, al*/
  /*13ca je 1479*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) == 0) goto L_1479;
  /*13d0 mov cl, byte ptr [esp + 0x23]*/
    ecx = (ecx & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 83))) & 0xff) << 0);
  /*13d4 test cl, cl*/
  /*13d6 jne 147d*/
    if ((unsigned char)(((ecx & 0xff) & (ecx & 0xff))) != 0) goto L_147d;
  /*13dc lea eax, [esp + 0x7c]*/
    eax = (hulk_uintptr)((char*)S + 172);
  /*13e0 mov byte ptr [esi + 0x6c], cl*/
    *(unsigned char*)((char*)(esi + 108)) = (ecx & 0xff);
  /*13e3 mov dword ptr [esi + 0xac], 0*/
    *(unsigned*)((char*)(esi + 172)) = 0u;
  /*13ed mov ecx, dword ptr [ebx + 0x10]*/
    ecx = (*(unsigned*)((char*)(ebx + 16)));
  /*13f0 push eax*/
    *(unsigned*)((char*)S + 44) = eax;
  /*13f1 call FUN_00059a50*/
    ((O*)ecx)->FUN_00059a50(*(unsigned*)((char*)S + 44));
  /*13f6 mov eax, dword ptr [esp + 0x94]*/
    eax = (*(unsigned*)((char*)S + 196));
  /*13fd mov ecx, dword ptr [eax + 0x40]*/
    ecx = (*(unsigned*)((char*)(eax + 64)));
  /*1400 mov edx, dword ptr [eax + 0x44]*/
    edx = (*(unsigned*)((char*)(eax + 68)));
  /*1403 mov eax, dword ptr [eax + 0x48]*/
    eax = (*(unsigned*)((char*)(eax + 72)));
  /*1406 mov dword ptr [esp + 0x24], ecx*/
    *(unsigned*)((char*)S + 84) = ecx;
  /*140a mov ecx, dword ptr [esi + 0x58]*/
    ecx = (*(unsigned*)((char*)(esi + 88)));
  /*140d mov dword ptr [esp + 0x28], edx*/
    *(unsigned*)((char*)S + 88) = edx;
  /*1411 mov dword ptr [esp + 0x2c], eax*/
    *(unsigned*)((char*)S + 92) = eax;
  /*1415 call FUN_000fefc0*/
    eax = (unsigned)((O*)ecx)->FUN_000fefc0();
  /*141a mov ebp, eax*/
    ebp = eax;
  /*141c push esi*/
    *(unsigned*)((char*)S + 44) = esi;
  /*141d mov ecx, ebp*/
    ecx = ebp;
  /*141f call FUN_001048d0*/
    ((O*)ecx)->FUN_001048d0(*(unsigned*)((char*)S + 44));
  /*1424 mov ebx, dword ptr [esp + 0x160]*/
    ebx = (*(unsigned*)((char*)S + 400));
  /*142b push 0x3f800000*/
    *(unsigned*)((char*)S + 44) = 1065353216u;
  /*1430 push 0x40000000*/
    *(unsigned*)((char*)S + 40) = 1073741824u;
  /*1435 push 1*/
    *(unsigned*)((char*)S + 36) = 1u;
  /*1437 push 0x3f800000*/
    *(unsigned*)((char*)S + 32) = 1065353216u;
  /*143c lea ecx, [esp + 0x34]*/
    ecx = (hulk_uintptr)((char*)S + 84);
  /*1440 push ecx*/
    *(unsigned*)((char*)S + 28) = ecx;
  /*1441 lea edx, [esp + 0x90]*/
    edx = (hulk_uintptr)((char*)S + 172);
  /*1448 push edx*/
    *(unsigned*)((char*)S + 24) = edx;
  /*1449 push ebx*/
    *(unsigned*)((char*)S + 20) = ebx;
  /*144a mov ecx, ebp*/
    ecx = ebp;
  /*144c call FUN_00104c60*/
    ((O*)ecx)->FUN_00104c60(*(unsigned*)((char*)S + 20), *(unsigned*)((char*)S + 24), *(unsigned*)((char*)S + 28), *(unsigned*)((char*)S + 32), *(unsigned*)((char*)S + 36), *(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*1451 mov ecx, dword ptr [esp + 0x168]*/
    ecx = (*(unsigned*)((char*)S + 408));
  /*1458 mov edx, dword ptr [esp + 0x164]*/
    edx = (*(unsigned*)((char*)S + 404));
  /*145f mov eax, dword ptr [ebp]*/
    vo_eax = ebp;
    eax = (*(unsigned*)((char*)(ebp)));
  /*1462 push ecx*/
    *(unsigned*)((char*)S + 44) = ecx;
  /*1463 push edx*/
    *(unsigned*)((char*)S + 40) = edx;
  /*1464 push ebx*/
    *(unsigned*)((char*)S + 36) = ebx;
  /*1465 mov ecx, ebp*/
    ecx = ebp;
  /*1467 call dword ptr [eax + 0x10]*/
    ((VC5*)vo_eax)->vcall(*(unsigned*)((char*)S + 36), *(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*146a mov eax, dword ptr [ebp]*/
    vo_eax = ebp;
    eax = (*(unsigned*)((char*)(ebp)));
  /*146d push 1*/
    *(unsigned*)((char*)S + 44) = 1u;
  /*146f mov ecx, ebp*/
    ecx = ebp;
  /*1471 call dword ptr [eax + 0x1c]*/
    ((VC6*)vo_eax)->vcall(*(unsigned*)((char*)S + 44));
  /*1474 jmp 1171*/
    goto L_1171;
L_1479:
  /*1479 mov cl, byte ptr [esp + 0x23]*/
    ecx = (ecx & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 83))) & 0xff) << 0);
L_147d:
  /*147d fld dword ptr [esp + 0x30]*/
    fl124 = *(float*)((char*)S + 96);
  /*1481 fcomp dword ptr [esi + 0x8c]*/
    fl125 = *(float*)((char*)(esi + 140));
  /*1487 fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fl124, fl125)) & 0xffff);
  /*1489 test ah, 5*/
  /*148c jnp 149c*/
    if (!PF8((((eax >> 8) & 0xff) & 5u))) goto L_149c;
  /*148e mov al, byte ptr [esi + 0x80]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)(esi + 128)))) & 0xff) << 0);
  /*1494 test al, al*/
  /*1496 je 17b6*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) == 0) goto L_17b6;
L_149c:
  /*149c test cl, cl*/
  /*149e jne 17b6*/
    if ((unsigned char)(((ecx & 0xff) & (ecx & 0xff))) != 0) goto L_17b6;
  /*14a4 fld dword ptr [esp + 0x4c]*/
    fl126 = *(float*)((char*)S + 124);
  /*14a8 fadd dword ptr [esi + 0x8c]*/
    fl127 = *(float*)((char*)(esi + 140));
  /*14ae fcomp dword ptr [esp + 0x30]*/
    fl128 = *(float*)((char*)S + 96);
  /*14b2 fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(((fl126) + (fl127)), fl128)) & 0xffff);
  /*14b4 test ah, 5*/
  /*14b7 jp 14c1*/
    if (PF8((((eax >> 8) & 0xff) & 5u))) goto L_14c1;
  /*14b9 mov byte ptr [esi + 0x80], cl*/
    *(unsigned char*)((char*)(esi + 128)) = (ecx & 0xff);
  /*14bf jmp 14d9*/
    goto L_14d9;
L_14c1:
  /*14c1 fld dword ptr [esp + 0x30]*/
    fl129 = *(float*)((char*)S + 96);
  /*14c5 fcomp dword ptr [esi + 0x8c]*/
    fl130 = *(float*)((char*)(esi + 140));
  /*14cb fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fl129, fl130)) & 0xffff);
  /*14cd test ah, 5*/
  /*14d0 jp 14d9*/
    if (PF8((((eax >> 8) & 0xff) & 5u))) goto L_14d9;
  /*14d2 mov byte ptr [esi + 0x80], 1*/
    *(unsigned char*)((char*)(esi + 128)) = 1u;
L_14d9:
  /*14d9 mov al, byte ptr [esp + 0x10]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 64))) & 0xff) << 0);
  /*14dd test al, al*/
  /*14df mov byte ptr [esi + 0x6c], 0*/
    *(unsigned char*)((char*)(esi + 108)) = 0u;
  /*14e3 jne 15d3*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) != 0) goto L_15d3;
  /*14e9 fld dword ptr [esp + 0x30]*/
    fl131 = *(float*)((char*)S + 96);
  /*14ed fcomp dword ptr [0x3f5cf8]*/
  /*14f3 fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fl131, 2.0f)) & 0xffff);
  /*14f5 test ah, 5*/
  /*14f8 jp 15d3*/
    if (PF8((((eax >> 8) & 0xff) & 5u))) goto L_15d3;
  /*14fe fld dword ptr [esp + 0xec]*/
    fl132 = *(float*)((char*)S + 284);
  /*1505 fcomp dword ptr [0x3f5cf8]*/
  /*150b fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fl132, 2.0f)) & 0xffff);
  /*150d test ah, 5*/
  /*1510 jp 15d3*/
    if (PF8((((eax >> 8) & 0xff) & 5u))) goto L_15d3;
  /*1516 fld dword ptr [esi + 0x74]*/
    fl133 = *(float*)((char*)(esi + 116));
  /*1519 fcomp dword ptr [0x3f32e0]*/
  /*151f fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fl133, 0.0f)) & 0xffff);
  /*1521 test ah, 0x41*/
  /*1524 jp 15d3*/
    if (PF8((((eax >> 8) & 0xff) & 65u))) goto L_15d3;
  /*152a mov ecx, dword ptr [ebx + 0x1cd0]*/
    ecx = (*(unsigned*)((char*)(ebx + 7376)));
  /*1530 mov dword ptr [esi + 0x9c], ecx*/
    *(hulk_uintptr*)((char*)(esi + 156)) = ecx;
  /*1536 mov ecx, dword ptr [esp + 0xf0]*/
    ecx = (*(unsigned*)((char*)S + 288));
  /*153d call FUN_00078780*/
    fretv = ((O*)ecx)->FUN_00078780();
  /*1542 fmul dword ptr [0x40d66c]*/
  /*1548 mov dword ptr [esi + 0x70], ebp*/
    *(hulk_uintptr*)((char*)(esi + 112)) = ebp;
  /*154b push 1*/
    *(unsigned*)((char*)S + 44) = 1u;
  /*154d fadd dword ptr [0x3f32dc]*/
  /*1553 fmul dword ptr [esi + 0x9c]*/
    fl134 = *(float*)((char*)(esi + 156));
  /*1559 fst dword ptr [esi + 0x9c]*/
    *(float*)((char*)(esi + 156)) = (float)(((((((fretv) * (0.5f))) + (1.0f))) * (fl134)));
  /*155f fstp dword ptr [esi + 0x74]*/
    *(float*)((char*)(esi + 116)) = (float)(((((((fretv) * (0.5f))) + (1.0f))) * (fl134)));
  /*1562 mov dword ptr [edi + 0x118], ebp*/
    *(hulk_uintptr*)((char*)(edi + 280)) = ebp;
  /*1568 mov edx, dword ptr [esp + 0xc8]*/
    edx = (*(unsigned*)((char*)S + 244));
  /*156f mov dword ptr [edi + 0x11c], edx*/
    *(hulk_uintptr*)((char*)(edi + 284)) = edx;
  /*1575 mov eax, dword ptr [esp + 0xcc]*/
    eax = (*(unsigned*)((char*)S + 248));
  /*157c mov dword ptr [edi + 0x120], eax*/
    *(hulk_uintptr*)((char*)(edi + 288)) = eax;
  /*1582 mov ecx, dword ptr [esp + 0xd0]*/
    ecx = (*(unsigned*)((char*)S + 252));
  /*1589 mov dword ptr [edi + 0x124], ecx*/
    *(hulk_uintptr*)((char*)(edi + 292)) = ecx;
  /*158f mov ecx, dword ptr [esp + 0x98]*/
    ecx = (*(unsigned*)((char*)S + 196));
  /*1596 mov dword ptr [edi + 0x114], ebp*/
    *(hulk_uintptr*)((char*)(edi + 276)) = ebp;
  /*159c mov dword ptr [edi + 0x110], ebp*/
    *(hulk_uintptr*)((char*)(edi + 272)) = ebp;
  /*15a2 mov dword ptr [edi + 0x10c], ebp*/
    *(hulk_uintptr*)((char*)(edi + 268)) = ebp;
  /*15a8 mov dword ptr [edi + 0xc], 1*/
    *(unsigned*)((char*)(edi + 12)) = 1u;
  /*15af mov edx, dword ptr [ebx + 0x1cbc]*/
    edx = (*(unsigned*)((char*)(ebx + 7356)));
  /*15b5 push edx*/
    *(unsigned*)((char*)S + 40) = edx;
  /*15b6 mov edx, dword ptr [esp + 0x168]*/
    edx = (*(unsigned*)((char*)S + 400));
  /*15bd lea eax, [esp + 0xb0]*/
    eax = (hulk_uintptr)((char*)S + 216);
  /*15c4 push eax*/
    *(unsigned*)((char*)S + 36) = eax;
  /*15c5 push ecx*/
    *(unsigned*)((char*)S + 32) = ecx;
  /*15c6 mov ecx, dword ptr [edx + 0x20]*/
    ecx = (*(unsigned*)((char*)(edx + 32)));
  /*15c9 call FUN_00029250*/
    ((O*)ecx)->FUN_00029250(*(unsigned*)((char*)S + 32), *(unsigned*)((char*)S + 36), *(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*15ce jmp 1173*/
    goto L_1173;
L_15d3:
  /*15d3 fld dword ptr [esp + 0x50]*/
    fl135 = *(float*)((char*)S + 128);
  /*15d7 fchs */
  /*15d9 fld dword ptr [esp + 0x54]*/
    fl136 = *(float*)((char*)S + 132);
  /*15dd fchs */
  /*15df fst dword ptr [esp + 0x28]*/
    *(float*)((char*)S + 88) = (float)((-(fl136)));
  /*15e3 fld dword ptr [esp + 0x58]*/
    fl137 = *(float*)((char*)S + 136);
  /*15e7 fchs */
  /*15e9 fstp dword ptr [esp + 0x2c]*/
    *(float*)((char*)S + 92) = (float)((-(fl137)));
  /*15ed mov eax, dword ptr [esp + 0x2c]*/
    eax = (*(unsigned*)((char*)S + 92));
  /*15f1 fld st(1)*/
  /*15f3 mov dword ptr [esp + 0x1c], eax*/
    *(unsigned*)((char*)S + 76) = eax;
  /*15f7 mov al, byte ptr [esp + 0x12]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 66))) & 0xff) << 0);
  /*15fb fstp dword ptr [esp + 0x14]*/
    *(float*)((char*)S + 68) = (float)((-(fl135)));
  /*15ff test al, al*/
  /*1601 fstp dword ptr [esp + 0x18]*/
    *(float*)((char*)S + 72) = (float)((-(fl136)));
  /*1605 jne 1632*/
    fpk0 = (-(fl135));
    // WARNING fp stack live (1) at 1605
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) != 0) goto L_1632;
  /*1607 fadd dword ptr [esp + 0xd4]*/
    fl138 = *(float*)((char*)S + 260);
  /*160e fstp dword ptr [esp + 0x14]*/
    *(float*)((char*)S + 68) = (float)(((fpk0) + (fl138)));
  /*1612 fld dword ptr [esp + 0x28]*/
    fl139 = *(float*)((char*)S + 88);
  /*1616 fadd dword ptr [esp + 0xd8]*/
    fl140 = *(float*)((char*)S + 264);
  /*161d fstp dword ptr [esp + 0x18]*/
    *(float*)((char*)S + 72) = (float)(((fl139) + (fl140)));
  /*1621 fld dword ptr [esp + 0x2c]*/
    fl141 = *(float*)((char*)S + 92);
  /*1625 fadd dword ptr [esp + 0xdc]*/
    fl142 = *(float*)((char*)S + 268);
  /*162c fstp dword ptr [esp + 0x1c]*/
    *(float*)((char*)S + 76) = (float)(((fl141) + (fl142)));
  /*1630 jmp 1634*/
    goto L_1634;
L_1632:
  /*1632 fstp st(0)*/
L_1634:
  /*1634 mov eax, dword ptr [esi + 0x5c]*/
    eax = (*(unsigned*)((char*)(esi + 92)));
  /*1637 mov ecx, dword ptr [esp + 0x14]*/
    ecx = (*(unsigned*)((char*)S + 68));
  /*163b add eax, 0x10*/
    eax = (unsigned)(eax + 16u);
  /*163e mov dword ptr [eax], ecx*/
    *(hulk_uintptr*)((char*)(eax)) = ecx;
  /*1640 mov edx, dword ptr [esp + 0x18]*/
    edx = (*(unsigned*)((char*)S + 72));
  /*1644 mov dword ptr [eax + 4], edx*/
    *(hulk_uintptr*)((char*)(eax + 4)) = edx;
  /*1647 mov ecx, dword ptr [esp + 0x1c]*/
    ecx = (*(unsigned*)((char*)S + 76));
  /*164b mov dword ptr [eax + 8], ecx*/
    *(hulk_uintptr*)((char*)(eax + 8)) = ecx;
  /*164e mov eax, dword ptr [esp + 0x164]*/
    eax = (*(unsigned*)((char*)S + 404));
  /*1655 mov ecx, dword ptr [esi + 0x5c]*/
    ecx = (*(unsigned*)((char*)(esi + 92)));
  /*1658 mov edx, dword ptr [ecx]*/
    vo_edx = ecx;
    edx = (*(unsigned*)((char*)(ecx)));
  /*165a push ebp*/
    *(unsigned*)((char*)S + 44) = ebp;
  /*165b push eax*/
    *(unsigned*)((char*)S + 40) = eax;
  /*165c lea eax, [esp + 0x90]*/
    eax = (hulk_uintptr)((char*)S + 184);
  /*1663 push eax*/
    *(unsigned*)((char*)S + 36) = eax;
  /*1664 mov eax, dword ptr [esp + 0x16c]*/
    eax = (*(unsigned*)((char*)S + 400));
  /*166b push ebx*/
    *(unsigned*)((char*)S + 32) = ebx;
  /*166c push eax*/
    *(unsigned*)((char*)S + 28) = eax;
  /*166d call dword ptr [edx + 0xc]*/
    eax = (unsigned)((VC7*)vo_edx)->vcall(*(unsigned*)((char*)S + 28), *(unsigned*)((char*)S + 32), *(unsigned*)((char*)S + 36), *(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*1670 test al, al*/
  /*1672 jne 1691*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) != 0) goto L_1691;
  /*1674 mov al, byte ptr [esp + 0x10]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 64))) & 0xff) << 0);
  /*1678 test al, al*/
  /*167a je 1691*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) == 0) goto L_1691;
  /*167c fld dword ptr [esp + 0x164]*/
    fl143 = *(float*)((char*)S + 404);
  /*1683 fadd dword ptr [esi + 0xac]*/
    fl144 = *(float*)((char*)(esi + 172));
  /*1689 fstp dword ptr [esi + 0xac]*/
    *(float*)((char*)(esi + 172)) = (float)(((fl143) + (fl144)));
  /*168f jmp 1697*/
    goto L_1697;
L_1691:
  /*1691 mov dword ptr [esi + 0xac], ebp*/
    *(hulk_uintptr*)((char*)(esi + 172)) = ebp;
L_1697:
  /*1697 mov edx, dword ptr [0x4a1e38]*/
    edx = (*(unsigned*)&DAT_004a1e38);
  /*169d lea ecx, [esp + 0x70]*/
    ecx = (hulk_uintptr)((char*)S + 160);
  /*16a1 push ecx*/
    *(unsigned*)((char*)S + 44) = ecx;
  /*16a2 push edx*/
    *(unsigned*)((char*)S + 40) = edx;
  /*16a3 lea eax, [esp + 0x108]*/
    eax = (hulk_uintptr)((char*)S + 304);
  /*16aa push eax*/
    *(unsigned*)((char*)S + 36) = eax;
  /*16ab lea ebp, [esi + 0x60]*/
    ebp = (hulk_uintptr)((char*)(esi + 96));
  /*16ae call FUN_00083dd0*/
    eax = (unsigned)FUN_00083dd0(*(unsigned*)((char*)S + 36), *(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*16b3 fld dword ptr [0x3f32dc]*/
  /*16b9 fsub dword ptr [0x4a1e38]*/
    fl145 = *(float*)&(*(unsigned*)&DAT_004a1e38);
  /*16bf add esp, 0xc*/
  /*16c2 push eax*/
    *(unsigned*)((char*)S + 44) = eax;
  /*16c3 lea ecx, [esp + 0x114]*/
    ecx = (hulk_uintptr)((char*)S + 320);
  /*16ca push ecx*/
    *(unsigned*)((char*)S + 40) = ecx;
  /*16cb push ebp*/
    *(unsigned*)((char*)S + 36) = ebp;
  /*16cc push ecx*/
    *(unsigned*)((char*)S + 32) = ecx;
  /*16cd lea edx, [esp + 0x104]*/
    edx = (hulk_uintptr)((char*)S + 292);
  /*16d4 fstp dword ptr [esp]*/
    *(float*)((char*)S + 32) = (float)(((1.0f) - (fl145)));
  /*16d7 push edx*/
    *(unsigned*)((char*)S + 28) = edx;
  /*16d8 call FUN_00083dd0*/
    eax = (unsigned)FUN_00083dd0(*(unsigned*)((char*)S + 28), *(unsigned*)((char*)S + 32), *(unsigned*)((char*)S + 36));
  /*16dd add esp, 0xc*/
  /*16e0 mov ecx, eax*/
    ecx = eax;
  /*16e2 call FUN_00078750*/
    eax = (unsigned)((O*)ecx)->FUN_00078750(*(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*16e7 fld dword ptr [esp + 0x14]*/
    fl146 = *(float*)((char*)S + 68);
  /*16eb mov ecx, dword ptr [eax]*/
    vo_ecx = eax;
    ecx = (*(unsigned*)((char*)(eax)));
  /*16ed mov dword ptr [ebp], ecx*/
    *(hulk_uintptr*)((char*)(ebp)) = ecx;
  /*16f0 mov edx, dword ptr [eax + 4]*/
    edx = (*(unsigned*)((char*)(eax + 4)));
  /*16f3 mov dword ptr [ebp + 4], edx*/
    *(hulk_uintptr*)((char*)(ebp + 4)) = edx;
  /*16f6 mov eax, dword ptr [eax + 8]*/
    eax = (*(unsigned*)((char*)(eax + 8)));
  /*16f9 mov dword ptr [ebp + 8], eax*/
    *(hulk_uintptr*)((char*)(ebp + 8)) = eax;
  /*16fc fadd dword ptr [ebp]*/
    fl147 = *(float*)((char*)(ebp));
  /*16ff fld dword ptr [esp + 0x18]*/
    fl148 = *(float*)((char*)S + 72);
  /*1703 lea ecx, [esp + 0x14]*/
    ecx = (hulk_uintptr)((char*)S + 68);
  /*1707 fadd dword ptr [ebp + 4]*/
    fl149 = *(float*)((char*)(ebp + 4));
  /*170a fld dword ptr [esp + 0x1c]*/
    fl150 = *(float*)((char*)S + 76);
  /*170e fadd dword ptr [ebp + 8]*/
    fl151 = *(float*)((char*)(ebp + 8));
  /*1711 fstp dword ptr [esp + 0x1c]*/
    *(float*)((char*)S + 76) = (float)(((fl150) + (fl151)));
  /*1715 fxch st(1)*/
  /*1717 fadd dword ptr [esp + 0xe0]*/
    fl152 = *(float*)((char*)S + 272);
  /*171e fstp dword ptr [esp + 0x14]*/
    *(float*)((char*)S + 68) = (float)(((((fl146) + (fl147))) + (fl152)));
  /*1722 fadd dword ptr [esp + 0xe4]*/
    fl153 = *(float*)((char*)S + 276);
  /*1729 fld dword ptr [esp + 0x1c]*/
    fl154 = *(float*)((char*)S + 76);
  /*172d fadd dword ptr [esp + 0xe8]*/
    fl155 = *(float*)((char*)S + 280);
  /*1734 fld dword ptr [esp + 0x14]*/
    fl156 = *(float*)((char*)S + 68);
  /*1738 fadd dword ptr [esp + 0x88]*/
    fl157 = *(float*)((char*)S + 184);
  /*173f fstp dword ptr [esp + 0x14]*/
    *(float*)((char*)S + 68) = (float)(((fl156) + (fl157)));
  /*1743 fxch st(1)*/
  /*1745 fadd dword ptr [esp + 0x8c]*/
    fl158 = *(float*)((char*)S + 188);
  /*174c fstp dword ptr [esp + 0x18]*/
    *(float*)((char*)S + 72) = (float)(((((((fl148) + (fl149))) + (fl153))) + (fl158)));
  /*1750 fadd dword ptr [esp + 0x90]*/
    fl159 = *(float*)((char*)S + 192);
  /*1757 fstp dword ptr [esp + 0x1c]*/
    *(float*)((char*)S + 76) = (float)(((((fl154) + (fl155))) + (fl159)));
  /*175b call FUN_0022d110*/
    fretv = ((O*)ecx)->FUN_0022d110();
  /*1760 mov ecx, dword ptr [esp + 0xc4]*/
    ecx = (*(unsigned*)((char*)S + 244));
  /*1767 fstp st(0)*/
  /*1769 mov dword ptr [edi + 0x11c], ecx*/
    *(hulk_uintptr*)((char*)(edi + 284)) = ecx;
  /*176f mov edx, dword ptr [esp + 0xc8]*/
    edx = (*(unsigned*)((char*)S + 248));
  /*1776 mov dword ptr [edi + 0x120], edx*/
    *(hulk_uintptr*)((char*)(edi + 288)) = edx;
  /*177c mov eax, dword ptr [esp + 0xcc]*/
    eax = (*(unsigned*)((char*)S + 252));
  /*1783 mov dword ptr [edi + 0x124], eax*/
    *(hulk_uintptr*)((char*)(edi + 292)) = eax;
  /*1789 mov ecx, dword ptr [esp + 0x14]*/
    ecx = (*(unsigned*)((char*)S + 68));
  /*178d mov dword ptr [edi + 0x10c], ecx*/
    *(hulk_uintptr*)((char*)(edi + 268)) = ecx;
  /*1793 mov edx, dword ptr [esp + 0x18]*/
    edx = (*(unsigned*)((char*)S + 72));
  /*1797 mov dword ptr [edi + 0x110], edx*/
    *(hulk_uintptr*)((char*)(edi + 272)) = edx;
  /*179d mov eax, dword ptr [esp + 0x1c]*/
    eax = (*(unsigned*)((char*)S + 76));
  /*17a1 mov dword ptr [edi + 0x114], eax*/
    *(hulk_uintptr*)((char*)(edi + 276)) = eax;
  /*17a7 mov dword ptr [edi + 0x118], 0x3f800000*/
    *(unsigned*)((char*)(edi + 280)) = 1065353216u;
  /*17b1 jmp 1171*/
    goto L_1171;
L_17b6:
  /*17b6 fld dword ptr [esp + 0x30]*/
    fl160 = *(float*)((char*)S + 96);
  /*17ba fcomp dword ptr [esi + 0x90]*/
    fl161 = *(float*)((char*)(esi + 144));
  /*17c0 fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fl160, fl161)) & 0xffff);
  /*17c2 test ah, 0x41*/
  /*17c5 je 17d5*/
    if ((unsigned char)((((eax >> 8) & 0xff) & 65u)) == 0) goto L_17d5;
  /*17c7 mov al, byte ptr [esi + 0x81]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)(esi + 129)))) & 0xff) << 0);
  /*17cd test al, al*/
  /*17cf je 18c7*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) == 0) goto L_18c7;
L_17d5:
  /*17d5 test cl, cl*/
  /*17d7 jne 18c7*/
    if ((unsigned char)(((ecx & 0xff) & (ecx & 0xff))) != 0) goto L_18c7;
  /*17dd fld dword ptr [esi + 0x90]*/
    fl162 = *(float*)((char*)(esi + 144));
  /*17e3 fsub dword ptr [esp + 0x4c]*/
    fl163 = *(float*)((char*)S + 124);
  /*17e7 fcomp dword ptr [esp + 0x30]*/
    fl164 = *(float*)((char*)S + 96);
  /*17eb fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(((fl162) - (fl163)), fl164)) & 0xffff);
  /*17ed test ah, 0x41*/
  /*17f0 jne 17fa*/
    if ((unsigned char)((((eax >> 8) & 0xff) & 65u)) != 0) goto L_17fa;
  /*17f2 mov byte ptr [esi + 0x81], cl*/
    *(unsigned char*)((char*)(esi + 129)) = (ecx & 0xff);
  /*17f8 jmp 1812*/
    goto L_1812;
L_17fa:
  /*17fa fld dword ptr [esp + 0x30]*/
    fl165 = *(float*)((char*)S + 96);
  /*17fe fcomp dword ptr [esi + 0x90]*/
    fl166 = *(float*)((char*)(esi + 144));
  /*1804 fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fl165, fl166)) & 0xffff);
  /*1806 test ah, 0x41*/
  /*1809 jne 1812*/
    if ((unsigned char)((((eax >> 8) & 0xff) & 65u)) != 0) goto L_1812;
  /*180b mov byte ptr [esi + 0x81], 1*/
    *(unsigned char*)((char*)(esi + 129)) = 1u;
L_1812:
  /*1812 fld dword ptr [esp + 0xe0]*/
    fl167 = *(float*)((char*)S + 272);
  /*1819 lea ecx, [esp + 0x14]*/
    ecx = (hulk_uintptr)((char*)S + 68);
  /*181d fadd dword ptr [esp + 0x50]*/
    fl168 = *(float*)((char*)S + 128);
  /*1821 mov byte ptr [esi + 0x6c], 0*/
    *(unsigned char*)((char*)(esi + 108)) = 0u;
  /*1825 fld dword ptr [esp + 0xe4]*/
    fl169 = *(float*)((char*)S + 276);
  /*182c mov dword ptr [esi + 0xac], ebp*/
    *(hulk_uintptr*)((char*)(esi + 172)) = ebp;
  /*1832 fadd dword ptr [esp + 0x54]*/
    fl170 = *(float*)((char*)S + 132);
  /*1836 fld dword ptr [esp + 0xe8]*/
    fl171 = *(float*)((char*)S + 280);
  /*183d fadd dword ptr [esp + 0x58]*/
    fl172 = *(float*)((char*)S + 136);
  /*1841 fstp dword ptr [esp + 0x1c]*/
    *(float*)((char*)S + 76) = (float)(((fl171) + (fl172)));
  /*1845 fxch st(1)*/
  /*1847 fadd dword ptr [esp + 0x88]*/
    fl173 = *(float*)((char*)S + 184);
  /*184e fstp dword ptr [esp + 0x14]*/
    *(float*)((char*)S + 68) = (float)(((((fl167) + (fl168))) + (fl173)));
  /*1852 fadd dword ptr [esp + 0x8c]*/
    fl174 = *(float*)((char*)S + 188);
  /*1859 fstp dword ptr [esp + 0x18]*/
    *(float*)((char*)S + 72) = (float)(((((fl169) + (fl170))) + (fl174)));
  /*185d fld dword ptr [esp + 0x1c]*/
    fl175 = *(float*)((char*)S + 76);
  /*1861 fadd dword ptr [esp + 0x90]*/
    fl176 = *(float*)((char*)S + 192);
  /*1868 fstp dword ptr [esp + 0x1c]*/
    *(float*)((char*)S + 76) = (float)(((fl175) + (fl176)));
  /*186c call FUN_0022d110*/
    fretv = ((O*)ecx)->FUN_0022d110();
  /*1871 mov ecx, dword ptr [esp + 0xc4]*/
    ecx = (*(unsigned*)((char*)S + 244));
  /*1878 fstp st(0)*/
  /*187a mov dword ptr [edi + 0x11c], ecx*/
    *(hulk_uintptr*)((char*)(edi + 284)) = ecx;
  /*1880 mov edx, dword ptr [esp + 0xc8]*/
    edx = (*(unsigned*)((char*)S + 248));
  /*1887 mov dword ptr [edi + 0x120], edx*/
    *(hulk_uintptr*)((char*)(edi + 288)) = edx;
  /*188d mov eax, dword ptr [esp + 0xcc]*/
    eax = (*(unsigned*)((char*)S + 252));
  /*1894 mov dword ptr [edi + 0x124], eax*/
    *(hulk_uintptr*)((char*)(edi + 292)) = eax;
  /*189a mov ecx, dword ptr [esp + 0x14]*/
    ecx = (*(unsigned*)((char*)S + 68));
  /*189e mov dword ptr [edi + 0x10c], ecx*/
    *(hulk_uintptr*)((char*)(edi + 268)) = ecx;
  /*18a4 mov edx, dword ptr [esp + 0x18]*/
    edx = (*(unsigned*)((char*)S + 72));
  /*18a8 mov dword ptr [edi + 0x110], edx*/
    *(hulk_uintptr*)((char*)(edi + 272)) = edx;
  /*18ae mov eax, dword ptr [esp + 0x1c]*/
    eax = (*(unsigned*)((char*)S + 76));
  /*18b2 mov dword ptr [edi + 0x114], eax*/
    *(hulk_uintptr*)((char*)(edi + 276)) = eax;
  /*18b8 mov dword ptr [edi + 0x118], 0x3f800000*/
    *(unsigned*)((char*)(edi + 280)) = 1065353216u;
  /*18c2 jmp 1173*/
    goto L_1173;
L_18c7:
  /*18c7 mov al, byte ptr [esp + 0x12]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 66))) & 0xff) << 0);
  /*18cb test al, al*/
  /*18cd jne 1a51*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) != 0) goto L_1a51;
  /*18d3 test cl, cl*/
  /*18d5 jne 1a51*/
    if ((unsigned char)(((ecx & 0xff) & (ecx & 0xff))) != 0) goto L_1a51;
  /*18db fld dword ptr [esp + 0xd4]*/
    fl177 = *(float*)((char*)S + 260);
  /*18e2 mov eax, dword ptr [esi + 0x5c]*/
    eax = (*(unsigned*)((char*)(esi + 92)));
  /*18e5 fadd dword ptr [esp + 0x50]*/
    fl178 = *(float*)((char*)S + 128);
  /*18e9 mov byte ptr [esi + 0x6c], cl*/
    *(unsigned char*)((char*)(esi + 108)) = (ecx & 0xff);
  /*18ec fld dword ptr [esp + 0xd8]*/
    fl179 = *(float*)((char*)S + 264);
  /*18f3 mov dword ptr [esi + 0xac], 0*/
    *(unsigned*)((char*)(esi + 172)) = 0u;
  /*18fd fadd dword ptr [esp + 0x54]*/
    fl180 = *(float*)((char*)S + 132);
  /*1901 add eax, 0x10*/
    eax = (unsigned)(eax + 16u);
  /*1904 fld dword ptr [esp + 0xdc]*/
    fl181 = *(float*)((char*)S + 268);
  /*190b push 0*/
    *(unsigned*)((char*)S + 44) = 0u;
  /*190d fadd dword ptr [esp + 0x5c]*/
    fl182 = *(float*)((char*)S + 136);
  /*1911 fld st(2)*/
  /*1913 fstp dword ptr [esp + 0x18]*/
    *(float*)((char*)S + 68) = (float)(((fl177) + (fl178)));
  /*1917 fxch st(1)*/
  /*1919 fstp dword ptr [esp + 0x1c]*/
    *(float*)((char*)S + 72) = (float)(((fl179) + (fl180)));
  /*191d fstp dword ptr [esp + 0x20]*/
    *(float*)((char*)S + 76) = (float)(((fl181) + (fl182)));
  /*1921 fstp dword ptr [eax]*/
    *(float*)((char*)(eax)) = (float)(((fl177) + (fl178)));
  /*1923 mov ecx, dword ptr [esp + 0x1c]*/
    ecx = (*(unsigned*)((char*)S + 72));
  /*1927 mov dword ptr [eax + 4], ecx*/
    *(hulk_uintptr*)((char*)(eax + 4)) = ecx;
  /*192a mov edx, dword ptr [esp + 0x20]*/
    edx = (*(unsigned*)((char*)S + 76));
  /*192e mov dword ptr [eax + 8], edx*/
    *(hulk_uintptr*)((char*)(eax + 8)) = edx;
  /*1931 mov edx, dword ptr [esp + 0x168]*/
    edx = (*(unsigned*)((char*)S + 404));
  /*1938 mov ecx, dword ptr [esi + 0x5c]*/
    ecx = (*(unsigned*)((char*)(esi + 92)));
  /*193b mov eax, dword ptr [ecx]*/
    vo_eax = ecx;
    eax = (*(unsigned*)((char*)(ecx)));
  /*193d push edx*/
    *(unsigned*)((char*)S + 40) = edx;
  /*193e lea edx, [esp + 0x90]*/
    edx = (hulk_uintptr)((char*)S + 184);
  /*1945 push edx*/
    *(unsigned*)((char*)S + 36) = edx;
  /*1946 mov edx, dword ptr [0x4dd700]*/
    edx = DAT_004dd700;
  /*194c push ebx*/
    *(unsigned*)((char*)S + 32) = ebx;
  /*194d push edx*/
    *(unsigned*)((char*)S + 28) = edx;
  /*194e call dword ptr [eax + 0xc]*/
    ((VC8*)vo_eax)->vcall(*(unsigned*)((char*)S + 28), *(unsigned*)((char*)S + 32), *(unsigned*)((char*)S + 36), *(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*1951 mov ecx, dword ptr [0x4a1e38]*/
    ecx = (*(unsigned*)&DAT_004a1e38);
  /*1957 lea eax, [esp + 0x70]*/
    eax = (hulk_uintptr)((char*)S + 160);
  /*195b push eax*/
    *(unsigned*)((char*)S + 44) = eax;
  /*195c push ecx*/
    *(unsigned*)((char*)S + 40) = ecx;
  /*195d lea edx, [esp + 0x108]*/
    edx = (hulk_uintptr)((char*)S + 304);
  /*1964 push edx*/
    *(unsigned*)((char*)S + 36) = edx;
  /*1965 lea ebp, [esi + 0x60]*/
    ebp = (hulk_uintptr)((char*)(esi + 96));
  /*1968 call FUN_00083dd0*/
    eax = (unsigned)FUN_00083dd0(*(unsigned*)((char*)S + 36), *(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*196d fld dword ptr [0x3f32dc]*/
  /*1973 fsub dword ptr [0x4a1e38]*/
    fl183 = *(float*)&(*(unsigned*)&DAT_004a1e38);
  /*1979 add esp, 0xc*/
  /*197c push eax*/
    *(unsigned*)((char*)S + 44) = eax;
  /*197d lea eax, [esp + 0x114]*/
    eax = (hulk_uintptr)((char*)S + 320);
  /*1984 push eax*/
    *(unsigned*)((char*)S + 40) = eax;
  /*1985 push ebp*/
    *(unsigned*)((char*)S + 36) = ebp;
  /*1986 push ecx*/
    *(unsigned*)((char*)S + 32) = ecx;
  /*1987 lea ecx, [esp + 0x104]*/
    ecx = (hulk_uintptr)((char*)S + 292);
  /*198e fstp dword ptr [esp]*/
    *(float*)((char*)S + 32) = (float)(((1.0f) - (fl183)));
  /*1991 push ecx*/
    *(unsigned*)((char*)S + 28) = ecx;
  /*1992 call FUN_00083dd0*/
    eax = (unsigned)FUN_00083dd0(*(unsigned*)((char*)S + 28), *(unsigned*)((char*)S + 32), *(unsigned*)((char*)S + 36));
  /*1997 add esp, 0xc*/
  /*199a mov ecx, eax*/
    ecx = eax;
  /*199c call FUN_00078750*/
    eax = (unsigned)((O*)ecx)->FUN_00078750(*(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*19a1 fld dword ptr [esp + 0x14]*/
    fl184 = *(float*)((char*)S + 68);
  /*19a5 mov edx, dword ptr [eax]*/
    vo_edx = eax;
    edx = (*(unsigned*)((char*)(eax)));
  /*19a7 mov dword ptr [ebp], edx*/
    *(hulk_uintptr*)((char*)(ebp)) = edx;
  /*19aa mov ecx, dword ptr [eax + 4]*/
    ecx = (*(unsigned*)((char*)(eax + 4)));
  /*19ad mov dword ptr [ebp + 4], ecx*/
    *(hulk_uintptr*)((char*)(ebp + 4)) = ecx;
  /*19b0 mov edx, dword ptr [eax + 8]*/
    edx = (*(unsigned*)((char*)(eax + 8)));
  /*19b3 mov dword ptr [ebp + 8], edx*/
    *(hulk_uintptr*)((char*)(ebp + 8)) = edx;
  /*19b6 fadd dword ptr [ebp]*/
    fl185 = *(float*)((char*)(ebp));
  /*19b9 fld dword ptr [esp + 0x18]*/
    fl186 = *(float*)((char*)S + 72);
  /*19bd lea ecx, [esp + 0x14]*/
    ecx = (hulk_uintptr)((char*)S + 68);
  /*19c1 fadd dword ptr [ebp + 4]*/
    fl187 = *(float*)((char*)(ebp + 4));
  /*19c4 fld dword ptr [esp + 0x1c]*/
    fl188 = *(float*)((char*)S + 76);
  /*19c8 fadd dword ptr [ebp + 8]*/
    fl189 = *(float*)((char*)(ebp + 8));
  /*19cb fstp dword ptr [esp + 0x1c]*/
    *(float*)((char*)S + 76) = (float)(((fl188) + (fl189)));
  /*19cf fxch st(1)*/
  /*19d1 fadd dword ptr [esp + 0x88]*/
    fl190 = *(float*)((char*)S + 184);
  /*19d8 fstp dword ptr [esp + 0x14]*/
    *(float*)((char*)S + 68) = (float)(((((fl184) + (fl185))) + (fl190)));
  /*19dc fadd dword ptr [esp + 0x8c]*/
    fl191 = *(float*)((char*)S + 188);
  /*19e3 fstp dword ptr [esp + 0x18]*/
    *(float*)((char*)S + 72) = (float)(((((fl186) + (fl187))) + (fl191)));
  /*19e7 fld dword ptr [esp + 0x1c]*/
    fl192 = *(float*)((char*)S + 76);
  /*19eb fadd dword ptr [esp + 0x90]*/
    fl193 = *(float*)((char*)S + 192);
  /*19f2 fstp dword ptr [esp + 0x1c]*/
    *(float*)((char*)S + 76) = (float)(((fl192) + (fl193)));
  /*19f6 call FUN_0022d110*/
    fretv = ((O*)ecx)->FUN_0022d110();
  /*19fb mov eax, dword ptr [esp + 0x50]*/
    eax = (*(unsigned*)((char*)S + 128));
  /*19ff fstp st(0)*/
  /*1a01 mov dword ptr [edi + 0x11c], eax*/
    *(hulk_uintptr*)((char*)(edi + 284)) = eax;
  /*1a07 mov ecx, dword ptr [esp + 0x54]*/
    ecx = (*(unsigned*)((char*)S + 132));
  /*1a0b mov eax, dword ptr [esp + 0xb8]*/
    eax = (*(unsigned*)((char*)S + 232));
  /*1a12 mov dword ptr [edi + 0x120], ecx*/
    *(hulk_uintptr*)((char*)(edi + 288)) = ecx;
  /*1a18 mov edx, dword ptr [esp + 0x58]*/
    edx = (*(unsigned*)((char*)S + 136));
  /*1a1c mov ecx, dword ptr [esp + 0xbc]*/
    ecx = (*(unsigned*)((char*)S + 236));
  /*1a23 mov dword ptr [edi + 0x124], edx*/
    *(hulk_uintptr*)((char*)(edi + 292)) = edx;
  /*1a29 mov edx, dword ptr [esp + 0xc0]*/
    edx = (*(unsigned*)((char*)S + 240));
  /*1a30 mov dword ptr [edi + 0x128], eax*/
    *(hulk_uintptr*)((char*)(edi + 296)) = eax;
  /*1a36 mov dword ptr [edi + 0x12c], ecx*/
    *(hulk_uintptr*)((char*)(edi + 300)) = ecx;
  /*1a3c mov dword ptr [edi + 0x130], edx*/
    *(hulk_uintptr*)((char*)(edi + 304)) = edx;
  /*1a42 mov dword ptr [edi + 0x118], 0x3f800000*/
    *(unsigned*)((char*)(edi + 280)) = 1065353216u;
  /*1a4c jmp 1384*/
    goto L_1384;
L_1a51:
  /*1a51 mov eax, dword ptr [esp + 0x50]*/
    eax = (*(unsigned*)((char*)S + 128));
  /*1a55 mov dword ptr [edi + 0x11c], eax*/
    *(hulk_uintptr*)((char*)(edi + 284)) = eax;
  /*1a5b mov ecx, dword ptr [esp + 0x54]*/
    ecx = (*(unsigned*)((char*)S + 132));
  /*1a5f mov eax, dword ptr [esp + 0xb8]*/
    eax = (*(unsigned*)((char*)S + 232));
  /*1a66 mov dword ptr [edi + 0x120], ecx*/
    *(hulk_uintptr*)((char*)(edi + 288)) = ecx;
  /*1a6c mov edx, dword ptr [esp + 0x58]*/
    edx = (*(unsigned*)((char*)S + 136));
  /*1a70 mov ecx, dword ptr [esp + 0xbc]*/
    ecx = (*(unsigned*)((char*)S + 236));
  /*1a77 mov dword ptr [edi + 0x124], edx*/
    *(hulk_uintptr*)((char*)(edi + 292)) = edx;
  /*1a7d mov edx, dword ptr [esp + 0xc0]*/
    edx = (*(unsigned*)((char*)S + 240));
  /*1a84 mov dword ptr [edi + 0x128], eax*/
    *(hulk_uintptr*)((char*)(edi + 296)) = eax;
  /*1a8a mov dword ptr [edi + 0x12c], ecx*/
    *(hulk_uintptr*)((char*)(edi + 300)) = ecx;
  /*1a90 mov dword ptr [edi + 0x130], edx*/
    *(hulk_uintptr*)((char*)(edi + 304)) = edx;
  /*1a96 mov dword ptr [edi + 0x118], ebp*/
    *(hulk_uintptr*)((char*)(edi + 280)) = ebp;
  /*1a9c mov dword ptr [edi + 0x114], ebp*/
    *(hulk_uintptr*)((char*)(edi + 276)) = ebp;
  /*1aa2 mov dword ptr [edi + 0x110], ebp*/
    *(hulk_uintptr*)((char*)(edi + 272)) = ebp;
  /*1aa8 mov dword ptr [edi + 0x10c], ebp*/
    *(hulk_uintptr*)((char*)(edi + 268)) = ebp;
  /*1aae mov al, byte ptr [esi + 0x6c]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)(esi + 108)))) & 0xff) << 0);
  /*1ab1 test al, al*/
  /*1ab3 mov dword ptr [esi + 0xac], ebp*/
    *(hulk_uintptr*)((char*)(esi + 172)) = ebp;
  /*1ab9 jne 1173*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) != 0) goto L_1173;
  /*1abf mov al, byte ptr [esp + 0x37]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)S + 103))) & 0xff) << 0);
  /*1ac3 test al, al*/
  /*1ac5 jne 1c2a*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) != 0) goto L_1c2a;
  /*1acb lea ecx, [esp + 0x70]*/
    ecx = (hulk_uintptr)((char*)S + 160);
  /*1acf call FUN_000111f0*/
    fretv = ((O*)ecx)->FUN_000111f0();
  /*1ad4 fcomp dword ptr [0x3f3358]*/
  /*1ada fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fretv, 0.00999999978f)) & 0xffff);
  /*1adc test ah, 0x41*/
  /*1adf jne 117f*/
    if ((unsigned char)((((eax >> 8) & 0xff) & 65u)) != 0) goto L_117f;
  /*1ae5 mov eax, dword ptr [esi + 0x5c]*/
    eax = (*(unsigned*)((char*)(esi + 92)));
  /*1ae8 mov ecx, dword ptr [esp + 0x70]*/
    ecx = (*(unsigned*)((char*)S + 160));
  /*1aec add eax, 0x10*/
    eax = (unsigned)(eax + 16u);
  /*1aef mov dword ptr [eax], ecx*/
    *(hulk_uintptr*)((char*)(eax)) = ecx;
  /*1af1 mov edx, dword ptr [esp + 0x74]*/
    edx = (*(unsigned*)((char*)S + 164));
  /*1af5 mov dword ptr [eax + 4], edx*/
    *(hulk_uintptr*)((char*)(eax + 4)) = edx;
  /*1af8 mov ecx, dword ptr [esp + 0x78]*/
    ecx = (*(unsigned*)((char*)S + 168));
  /*1afc mov dword ptr [eax + 8], ecx*/
    *(hulk_uintptr*)((char*)(eax + 8)) = ecx;
  /*1aff mov eax, dword ptr [esp + 0x164]*/
    eax = (*(unsigned*)((char*)S + 404));
  /*1b06 mov ecx, dword ptr [esi + 0x5c]*/
    ecx = (*(unsigned*)((char*)(esi + 92)));
  /*1b09 mov edx, dword ptr [ecx]*/
    vo_edx = ecx;
    edx = (*(unsigned*)((char*)(ecx)));
  /*1b0b push 0*/
    *(unsigned*)((char*)S + 44) = 0u;
  /*1b0d push eax*/
    *(unsigned*)((char*)S + 40) = eax;
  /*1b0e lea eax, [esp + 0x90]*/
    eax = (hulk_uintptr)((char*)S + 184);
  /*1b15 push eax*/
    *(unsigned*)((char*)S + 36) = eax;
  /*1b16 mov eax, dword ptr [0x4dd700]*/
    eax = DAT_004dd700;
  /*1b1b push ebx*/
    *(unsigned*)((char*)S + 32) = ebx;
  /*1b1c push eax*/
    *(unsigned*)((char*)S + 28) = eax;
  /*1b1d call dword ptr [edx + 0xc]*/
    ((VC9*)vo_edx)->vcall(*(unsigned*)((char*)S + 28), *(unsigned*)((char*)S + 32), *(unsigned*)((char*)S + 36), *(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*1b20 mov edx, dword ptr [0x4a1e38]*/
    edx = (*(unsigned*)&DAT_004a1e38);
  /*1b26 lea ecx, [esp + 0x70]*/
    ecx = (hulk_uintptr)((char*)S + 160);
  /*1b2a push ecx*/
    *(unsigned*)((char*)S + 44) = ecx;
  /*1b2b push edx*/
    *(unsigned*)((char*)S + 40) = edx;
  /*1b2c lea eax, [esp + 0x108]*/
    eax = (hulk_uintptr)((char*)S + 304);
  /*1b33 push eax*/
    *(unsigned*)((char*)S + 36) = eax;
  /*1b34 lea ebp, [esi + 0x60]*/
    ebp = (hulk_uintptr)((char*)(esi + 96));
  /*1b37 call FUN_00083dd0*/
    eax = (unsigned)FUN_00083dd0(*(unsigned*)((char*)S + 36), *(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*1b3c fld dword ptr [0x3f32dc]*/
  /*1b42 fsub dword ptr [0x4a1e38]*/
    fl194 = *(float*)&(*(unsigned*)&DAT_004a1e38);
  /*1b48 add esp, 0xc*/
  /*1b4b push eax*/
    *(unsigned*)((char*)S + 44) = eax;
  /*1b4c lea ecx, [esp + 0x114]*/
    ecx = (hulk_uintptr)((char*)S + 320);
  /*1b53 push ecx*/
    *(unsigned*)((char*)S + 40) = ecx;
  /*1b54 push ebp*/
    *(unsigned*)((char*)S + 36) = ebp;
  /*1b55 push ecx*/
    *(unsigned*)((char*)S + 32) = ecx;
  /*1b56 lea edx, [esp + 0x104]*/
    edx = (hulk_uintptr)((char*)S + 292);
  /*1b5d fstp dword ptr [esp]*/
    *(float*)((char*)S + 32) = (float)(((1.0f) - (fl194)));
  /*1b60 push edx*/
    *(unsigned*)((char*)S + 28) = edx;
  /*1b61 call FUN_00083dd0*/
    eax = (unsigned)FUN_00083dd0(*(unsigned*)((char*)S + 28), *(unsigned*)((char*)S + 32), *(unsigned*)((char*)S + 36));
  /*1b66 add esp, 0xc*/
  /*1b69 mov ecx, eax*/
    ecx = eax;
  /*1b6b call FUN_00078750*/
    eax = (unsigned)((O*)ecx)->FUN_00078750(*(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*1b70 fld dword ptr [esp + 0x14]*/
    fl195 = *(float*)((char*)S + 68);
  /*1b74 mov ecx, dword ptr [eax]*/
    vo_ecx = eax;
    ecx = (*(unsigned*)((char*)(eax)));
  /*1b76 mov dword ptr [ebp], ecx*/
    *(hulk_uintptr*)((char*)(ebp)) = ecx;
  /*1b79 mov edx, dword ptr [eax + 4]*/
    edx = (*(unsigned*)((char*)(eax + 4)));
  /*1b7c mov dword ptr [ebp + 4], edx*/
    *(hulk_uintptr*)((char*)(ebp + 4)) = edx;
  /*1b7f mov eax, dword ptr [eax + 8]*/
    eax = (*(unsigned*)((char*)(eax + 8)));
  /*1b82 mov dword ptr [ebp + 8], eax*/
    *(hulk_uintptr*)((char*)(ebp + 8)) = eax;
  /*1b85 fadd dword ptr [ebp]*/
    fl196 = *(float*)((char*)(ebp));
  /*1b88 fld dword ptr [esp + 0x18]*/
    fl197 = *(float*)((char*)S + 72);
  /*1b8c lea ecx, [esp + 0x14]*/
    ecx = (hulk_uintptr)((char*)S + 68);
  /*1b90 fadd dword ptr [ebp + 4]*/
    fl198 = *(float*)((char*)(ebp + 4));
  /*1b93 mov dword ptr [esp + 0x98], 0x3f800000*/
    *(unsigned*)((char*)S + 200) = 1065353216u;
  /*1b9e fld dword ptr [esp + 0x1c]*/
    fl199 = *(float*)((char*)S + 76);
  /*1ba2 fadd dword ptr [ebp + 8]*/
    fl200 = *(float*)((char*)(ebp + 8));
  /*1ba5 fstp dword ptr [esp + 0x1c]*/
    *(float*)((char*)S + 76) = (float)(((fl199) + (fl200)));
  /*1ba9 fxch st(1)*/
  /*1bab fadd dword ptr [esp + 0x88]*/
    fl201 = *(float*)((char*)S + 184);
  /*1bb2 fstp dword ptr [esp + 0x14]*/
    *(float*)((char*)S + 68) = (float)(((((fl195) + (fl196))) + (fl201)));
  /*1bb6 fadd dword ptr [esp + 0x8c]*/
    fl202 = *(float*)((char*)S + 188);
  /*1bbd fstp dword ptr [esp + 0x18]*/
    *(float*)((char*)S + 72) = (float)(((((fl197) + (fl198))) + (fl202)));
  /*1bc1 fld dword ptr [esp + 0x1c]*/
    fl203 = *(float*)((char*)S + 76);
  /*1bc5 fadd dword ptr [esp + 0x90]*/
    fl204 = *(float*)((char*)S + 192);
  /*1bcc fstp dword ptr [esp + 0x1c]*/
    *(float*)((char*)S + 76) = (float)(((fl203) + (fl204)));
  /*1bd0 call FUN_00018990*/
    fretv = ((O*)ecx)->FUN_00018990();
  /*1bd5 lea ecx, [esp + 0x98]*/
    ecx = (hulk_uintptr)((char*)S + 200);
  /*1bdc fstp dword ptr [esp + 0x4c]*/
    *(float*)((char*)S + 124) = (float)(fretv);
  /*1be0 push ecx*/
    *(unsigned*)((char*)S + 44) = ecx;
  /*1be1 lea edx, [esp + 0x50]*/
    edx = (hulk_uintptr)((char*)S + 124);
  /*1be5 push edx*/
    *(unsigned*)((char*)S + 40) = edx;
  /*1be6 call FUN_000186f0*/
    fretv = FUN_000186f0(*(unsigned*)((char*)S + 40), *(unsigned*)((char*)S + 44));
  /*1beb fstp dword ptr [edi + 0x118]*/
    *(float*)((char*)(edi + 280)) = (float)(fretv);
  /*1bf1 add esp, 8*/
  /*1bf4 lea ecx, [esp + 0x14]*/
    ecx = (hulk_uintptr)((char*)S + 68);
  /*1bf8 call FUN_0022d110*/
    fretv = ((O*)ecx)->FUN_0022d110();
  /*1bfd fstp st(0)*/
  /*1bff mov eax, dword ptr [esp + 0x14]*/
    eax = (*(unsigned*)((char*)S + 68));
  /*1c03 mov dword ptr [edi + 0x10c], eax*/
    *(hulk_uintptr*)((char*)(edi + 268)) = eax;
  /*1c09 mov ecx, dword ptr [esp + 0x18]*/
    ecx = (*(unsigned*)((char*)S + 72));
  /*1c0d mov dword ptr [edi + 0x110], ecx*/
    *(hulk_uintptr*)((char*)(edi + 272)) = ecx;
  /*1c13 mov edx, dword ptr [esp + 0x1c]*/
    edx = (*(unsigned*)((char*)S + 76));
  /*1c17 xor ebp, ebp*/
    ebp = 0;
  /*1c19 mov dword ptr [edi + 0x114], edx*/
    *(hulk_uintptr*)((char*)(edi + 276)) = edx;
  /*1c1f mov dword ptr [edi + 0x110], ebp*/
    *(hulk_uintptr*)((char*)(edi + 272)) = ebp;
  /*1c25 jmp 1d32*/
    goto L_1d32;
L_1c2a:
  /*1c2a fld dword ptr [esp + 0xec]*/
    fl205 = *(float*)((char*)S + 284);
  /*1c31 fcomp dword ptr [0x40d6cc]*/
  /*1c37 fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fl205, 80.0f)) & 0xffff);
  /*1c39 test ah, 5*/
  /*1c3c jp 1d32*/
    if (PF8((((eax >> 8) & 0xff) & 5u))) goto L_1d32;
  /*1c42 fld dword ptr [esp + 0xc8]*/
    fl206 = *(float*)((char*)S + 248);
  /*1c49 fmul dword ptr [esp + 0x30]*/
    fl207 = *(float*)((char*)S + 96);
  /*1c4d fchs */
  /*1c4f fst dword ptr [esp + 0x38]*/
    *(float*)((char*)S + 104) = (float)((-(((fl206) * (fl207)))));
  /*1c53 fcomp dword ptr [0x40d6fc]*/
  /*1c59 fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW((-(((fl206) * (fl207)))), 3.0f)) & 0xffff);
  /*1c5b test ah, 5*/
  /*1c5e jp 1cb5*/
    if (PF8((((eax >> 8) & 0xff) & 5u))) goto L_1cb5;
  /*1c60 fld dword ptr [0x40d6cc]*/
  /*1c66 lea ecx, [edi + 0x10c]*/
    ecx = (hulk_uintptr)((char*)(edi + 268));
  /*1c6c fsub dword ptr [esp + 0xec]*/
    fl208 = *(float*)((char*)S + 284);
  /*1c73 fmul dword ptr [0x40d6c8]*/
  /*1c79 fadd dword ptr [edi + 0x110]*/
    fl209 = *(float*)((char*)(edi + 272));
  /*1c7f fstp dword ptr [edi + 0x110]*/
    *(float*)((char*)(edi + 272)) = (float)(((((((80.0f) - (fl208))) * (0.0125000002f))) + (fl209)));
  /*1c85 call FUN_0022d110*/
    fretv = ((O*)ecx)->FUN_0022d110();
  /*1c8a fstp st(0)*/
  /*1c8c fld dword ptr [edi + 0x118]*/
    fl210 = *(float*)((char*)(edi + 280));
  /*1c92 fcomp dword ptr [0x3f32e0]*/
  /*1c98 fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fl210, 0.0f)) & 0xffff);
  /*1c9a test ah, 0x41*/
  /*1c9d jp 1d32*/
    if (PF8((((eax >> 8) & 0xff) & 65u))) goto L_1d32;
  /*1ca3 fld dword ptr [0x40d6fc]*/
  /*1ca9 fsub dword ptr [esp + 0x38]*/
    fl211 = *(float*)((char*)S + 104);
  /*1cad fmul dword ptr [0x3f5cd0]*/
  /*1cb3 jmp 1d15*/
    fpk0 = ((((3.0f) - (fl211))) * (0.333333343f));
    // WARNING fp stack live (1) at 1cb3
    goto L_1d15;
L_1cb5:
  /*1cb5 fld dword ptr [esp + 0x38]*/
    fl212 = *(float*)((char*)S + 104);
  /*1cb9 fcomp dword ptr [0x3f342c]*/
  /*1cbf fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fl212, 5.0f)) & 0xffff);
  /*1cc1 test ah, 0x41*/
  /*1cc4 jne 1d32*/
    if ((unsigned char)((((eax >> 8) & 0xff) & 65u)) != 0) goto L_1d32;
  /*1cc6 fld dword ptr [0x40d6cc]*/
  /*1ccc lea ecx, [edi + 0x10c]*/
    ecx = (hulk_uintptr)((char*)(edi + 268));
  /*1cd2 fsub dword ptr [esp + 0xec]*/
    fl213 = *(float*)((char*)S + 284);
  /*1cd9 fmul dword ptr [0x40d6c8]*/
  /*1cdf fsubr dword ptr [edi + 0x110]*/
    fl214 = *(float*)((char*)(edi + 272));
  /*1ce5 fstp dword ptr [edi + 0x110]*/
    *(float*)((char*)(edi + 272)) = (float)(((fl214) - (((((80.0f) - (fl213))) * (0.0125000002f)))));
  /*1ceb call FUN_0022d110*/
    fretv = ((O*)ecx)->FUN_0022d110();
  /*1cf0 fstp st(0)*/
  /*1cf2 fld dword ptr [edi + 0x118]*/
    fl215 = *(float*)((char*)(edi + 280));
  /*1cf8 fcomp dword ptr [0x3f32e0]*/
  /*1cfe fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fl215, 0.0f)) & 0xffff);
  /*1d00 test ah, 0x41*/
  /*1d03 jp 1d32*/
    if (PF8((((eax >> 8) & 0xff) & 65u))) goto L_1d32;
  /*1d05 fld dword ptr [esp + 0x38]*/
    fl216 = *(float*)((char*)S + 104);
  /*1d09 fsub dword ptr [0x3f342c]*/
  /*1d0f fmul dword ptr [0x3ff5ac]*/
    fpk0 = ((((fl216) - (5.0f))) * (0.200000003f));
    // WARNING fp stack live (1) at 1d15
L_1d15:
  /*1d15 fst dword ptr [edi + 0x118]*/
    *(float*)((char*)(edi + 280)) = (float)(fpk0);
  /*1d1b fcomp dword ptr [0x3f32dc]*/
  /*1d21 fnstsw ax*/
    eax = (eax & 0xffff0000u) | ((unsigned)(FSW(fpk0, 1.0f)) & 0xffff);
  /*1d23 test ah, 0x41*/
  /*1d26 jne 1d32*/
    if ((unsigned char)((((eax >> 8) & 0xff) & 65u)) != 0) goto L_1d32;
  /*1d28 mov dword ptr [edi + 0x118], 0x3f800000*/
    *(unsigned*)((char*)(edi + 280)) = 1065353216u;
L_1d32:
  /*1d32 mov al, byte ptr [esi + 0x6c]*/
    eax = (eax & ~(0xffu << 0)) | (((unsigned)((*(unsigned char*)((char*)(esi + 108)))) & 0xff) << 0);
  /*1d35 test al, al*/
  /*1d37 je 1d40*/
    if ((unsigned char)(((eax & 0xff) & (eax & 0xff))) == 0) goto L_1d40;
  /*1d39 mov dword ptr [edi + 0x3c], 2*/
    *(unsigned*)((char*)(edi + 60)) = 2u;
L_1d40:
  /*1d40 pop edi*/
    edi = *(unsigned*)((char*)S + 48);
  /*1d41 pop ebp*/
    ebp = *(unsigned*)((char*)S + 52);
L_1d42:
  /*1d42 pop esi*/
    esi = *(unsigned*)((char*)S + 56);
  /*1d43 pop ebx*/
    ebx = *(unsigned*)((char*)S + 60);
  /*1d44 add esp, 0x14c*/
  /*1d4a ret 0xc*/
    return;
}
