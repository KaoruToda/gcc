/* { dg-do compile { target { powerpc*-*-linux* } } } */
/* { dg-require-effective-target powerpc_p9vector_ok } */
/* { dg-options "-O2 -mpower9-vector -mno-float128" } */

/* Test that we can use #pragma GCC target to enable -mfloat128 and generate
   code on ISA 3.0 for the float128 built-in functions.  */

#ifdef __FLOAT128__
#error "-mno-float128 should disable initially defining __FLOAT128__"
#endif

#pragma GCC target("float128")

#ifndef __FLOAT128__
#error "#pragma GCC target(\"float128\") should enable -mfloat128"
#endif

__float128
qabs (__float128 a)
{
  return __builtin_fabsq (a);
}

/* { dg-final { scan-assembler "xsabsqp"  } } */
