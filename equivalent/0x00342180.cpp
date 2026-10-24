// STATUS: equivalent (tools/equiv.py level 3: 3200 inputs, branch coverage 0/0)
// FUN_00342180 @ 0x00342180
// FUN_00342180: in-place 32-point butterfly network (two stages of rotations by the twiddles in c) over
// the float array d (eax), twiddle table in c (ecx).  Reconstructed from the original x87 code by following
// the FPU stack: values the original keeps unrounded on the FPU stack are recomputed inline from reads,
// values it stores to the stack are hulk_fslot locals (rounded to float, numbered t5..t80 in the order the
// original computes them), and the twiddle fields k1/k4/k5 and the inputs x* it preloads are copies taken
// before the first store into d (d and c may overlap).
#if defined(_MSC_VER) && !defined(__clang__)
typedef volatile float hulk_fslot; // forces the store-and-reload MSVC 7.1 would otherwise skip
#else
typedef float hulk_fslot;
#endif

// equiv-conv: FUN_00342180 eax ecx
void FUN_00342180(float *d, float *c)
{
    hulk_fslot k1 = c[1];
    hulk_fslot k4 = c[4];
    hulk_fslot k5 = c[5];
    hulk_fslot x23 = d[23];
    hulk_fslot x6 = d[6];
    hulk_fslot x7 = d[7];
    hulk_fslot x22 = d[22];
    hulk_fslot x31 = d[31];
    hulk_fslot x14 = d[14];
    hulk_fslot x15 = d[15];
    hulk_fslot x30 = d[30];
    // c[6] and c[7] are copied as raw words, like the original.
    hulk_fslot c6;
    hulk_fslot c7;
    *(unsigned int *)&c6 = ((unsigned *)c)[6];
    *(unsigned int *)&c7 = ((unsigned *)c)[7];
    hulk_fslot t5 = (d[8] - d[25]);
    hulk_fslot t6 = (d[9] + d[24]);
    hulk_fslot t7 = ((t5 - t6) * k1);
    hulk_fslot t8 = ((t6 + t5) * k1);
    hulk_fslot t9 = (t7 + (d[0] - d[17]));
    hulk_fslot t10 = (t8 + (d[16] + d[1]));
    hulk_fslot t11 = ((d[0] - d[17]) - t7);
    hulk_fslot t12 = ((d[16] + d[1]) - t8);
    hulk_fslot t13 = (d[25] + d[8]);
    hulk_fslot t14 = (d[9] - d[24]);
    hulk_fslot t15 = ((t13 - t14) * k1);
    hulk_fslot t16 = ((t14 + t13) * k1);
    hulk_fslot t17 = ((d[17] + d[0]) - t16);
    hulk_fslot t18 = (t15 + (d[1] - d[16]));
    hulk_fslot t19 = (t16 + (d[17] + d[0]));
    hulk_fslot t20 = ((d[1] - d[16]) - t15);
    hulk_fslot t21 = (d[3] + d[18]);
    hulk_fslot t22 = (((d[2] - d[19]) * k4) - (t21 * k5));
    hulk_fslot t23 = (((d[2] - d[19]) * k5) + (t21 * k4));
    hulk_fslot t24 = (d[11] + d[26]);
    hulk_fslot t25 = ((c7 * (d[10] - d[27])) - (t24 * c6));
    hulk_fslot t26 = ((t24 * c7) + ((d[10] - d[27]) * c6));
    hulk_fslot t27 = (t25 + t22);
    hulk_fslot t28 = (t26 + t23);
    hulk_fslot t29 = (t22 - t25);
    hulk_fslot t30 = (t23 - t26);
    hulk_fslot t31 = (d[3] - d[18]);
    hulk_fslot t32 = ((c6 * (d[19] + d[2])) - (t31 * c7));
    hulk_fslot t33 = (((d[19] + d[2]) * c7) + (t31 * c6));
    hulk_fslot t34 = (d[11] - d[26]);
    hulk_fslot t35 = (((d[11] - d[26]) * k5) + ((d[27] + d[10]) * k4));
    hulk_fslot t36 = ((t34 * k4) - ((d[27] + d[10]) * k5));
    hulk_fslot t37 = (t32 - t35);
    hulk_fslot t38 = (t33 - t36);
    hulk_fslot t39 = (t35 + t32);
    hulk_fslot t40 = (t36 + t33);
    hulk_fslot t41 = (d[5] + d[20]);
    hulk_fslot t42 = (((d[4] - d[21]) * c[8]) - (t41 * c[9]));
    hulk_fslot t43 = (((d[4] - d[21]) * c[9]) + (t41 * c[8]));
    hulk_fslot t44 = (d[13] + d[28]);
    hulk_fslot t45 = (((d[12] - d[29]) * c[9]) - (t44 * c[8]));
    hulk_fslot t46 = ((t44 * c[9]) + ((d[12] - d[29]) * c[8]));
    hulk_fslot t47 = (t45 + t42);
    hulk_fslot t48 = (t46 + t43);
    hulk_fslot t49 = (t42 - t45);
    hulk_fslot t50 = (t43 - t46);
    hulk_fslot t51 = (d[5] - d[20]);
    hulk_fslot t52 = (((d[21] + d[4]) * c[9]) - (t51 * c[8]));
    hulk_fslot t53 = ((t51 * c[9]) + ((d[21] + d[4]) * c[8]));
    hulk_fslot t54 = (d[13] - d[28]);
    hulk_fslot t55 = (((d[29] + d[12]) * c[8]) - (t54 * c[9]));
    hulk_fslot t56 = (((d[29] + d[12]) * c[9]) + (t54 * c[8]));
    hulk_fslot t57 = (t52 - t55);
    hulk_fslot t58 = (t53 - t56);
    hulk_fslot t59 = (t55 + t52);
    hulk_fslot t60 = (t56 + t53);
    hulk_fslot t61 = (((d[6] - d[23]) * c6) - ((d[7] + d[22]) * c7));
    hulk_fslot t62 = (((d[14] - d[31]) * k5) - ((d[30] + d[15]) * k4));
    hulk_fslot t63 = (((d[30] + d[15]) * k5) + ((d[14] - d[31]) * k4));
    hulk_fslot t64 = (t62 + t61);
    hulk_fslot t65 = (t63 + (((d[6] - d[23]) * c7) + ((d[7] + d[22]) * c6)));
    hulk_fslot t66 = (t61 - t62);
    hulk_fslot t67 = ((((d[6] - d[23]) * c7) + ((d[7] + d[22]) * c6)) - t63);
    hulk_fslot t68 = (((x23 + x6) * k5) + ((x7 - x22) * k4));
    hulk_fslot t69 = (((x31 + x14) * c7) - ((x15 - x30) * c6));
    hulk_fslot t70 = (t69 + t68);
    hulk_fslot t71 = ((((x15 - x30) * c7) + ((x31 + x14) * c6)) + (((x7 - x22) * k5) - ((x23 + x6) * k4)));
    hulk_fslot t72 = (t68 - t69);
    hulk_fslot t73 = (t65 + t28);
    d[0] = ((t64 + t27) + (t47 + t9));
    d[1] = (t73 + (t48 + t10));
    d[2] = ((t47 + t9) - (t64 + t27));
    d[3] = ((t48 + t10) - t73);
    d[4] = ((t9 - t47) - (t28 - t65));
    d[5] = ((t27 - t64) + (t10 - t48));
    d[6] = ((t28 - t65) + (t9 - t47));
    d[7] = ((t10 - t48) - (t27 - t64));
    hulk_fslot t74 = (((t29 - t67) - (t66 + t30)) * k1);
    d[8] = (t74 + (t11 - t50));
    d[9] = ((((t29 - t67) + (t66 + t30)) * k1) + (t49 + t12));
    d[10] = ((t11 - t50) - t74);
    d[11] = ((t49 + t12) - (((t29 - t67) + (t66 + t30)) * k1));
    hulk_fslot t75 = (((t67 + t29) - (t30 - t66)) * k1);
    d[12] = ((t50 + t11) - (((t67 + t29) + (t30 - t66)) * k1));
    d[13] = (t75 + (t12 - t49));
    d[14] = ((((t67 + t29) + (t30 - t66)) * k1) + (t50 + t11));
    d[15] = ((t12 - t49) - t75);
    hulk_fslot t76 = (t38 - t71);
    d[16] = ((t37 - t70) + (t57 + t17));
    d[17] = (t76 + (t58 + t18));
    d[18] = ((t57 + t17) - (t37 - t70));
    d[19] = ((t58 + t18) - t76);
    d[20] = ((t17 - t57) - (t71 + t38));
    d[21] = ((t70 + t37) + (t18 - t58));
    d[22] = ((t71 + t38) + (t17 - t57));
    d[23] = ((t18 - t58) - (t70 + t37));
    hulk_fslot t77 = (((((((x7 - x22) * k5) - ((x23 + x6) * k4)) - (((x15 - x30) * c7) + ((x31 + x14) * c6))) + t39) - (t40 - t72)) * k1);
    d[24] = (t77 + (t19 - t60));
    d[25] = ((((((((x7 - x22) * k5) - ((x23 + x6) * k4)) - (((x15 - x30) * c7) + ((x31 + x14) * c6))) + t39) + (t40 - t72)) * k1) + (t59 + t20));
    d[26] = ((t19 - t60) - t77);
    d[27] = ((t59 + t20) - (((((((x7 - x22) * k5) - ((x23 + x6) * k4)) - (((x15 - x30) * c7) + ((x31 + x14) * c6))) + t39) + (t40 - t72)) * k1));
    hulk_fslot t78 = (t60 + t19);
    hulk_fslot t79 = (t20 - t59);
    hulk_fslot t80 = (((t39 - ((((x7 - x22) * k5) - ((x23 + x6) * k4)) - (((x15 - x30) * c7) + ((x31 + x14) * c6)))) - (t72 + t40)) * k1);
    d[28] = (t78 - (k1 * ((t72 + t40) + (t39 - ((((x7 - x22) * k5) - ((x23 + x6) * k4)) - (((x15 - x30) * c7) + ((x31 + x14) * c6)))))));
    d[29] = (t80 + t79);
    d[30] = ((k1 * ((t72 + t40) + (t39 - ((((x7 - x22) * k5) - ((x23 + x6) * k4)) - (((x15 - x30) * c7) + ((x31 + x14) * c6)))))) + t78);
    d[31] = (t79 - t80);
}
