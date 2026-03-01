//
//  Ethan Bobowski, 2026
// ----------------------
//
//  This is free and unencumbered software released into the public domain.
//
//  Anyone is free to copy, modify, publish, use, compile, sell, or
//  distribute this software, either in source code form or as a compiled
//  binary, for any purpose, commercial or non-commercial, and by any
//  means.
//
//  In jurisdictions that recognize copyright laws, the author or authors
//  of this software dedicate any and all copyright interest in the
//  software to the public domain. We make this dedication for the benefit
//  of the public at large and to the detriment of our heirs and
//  successors. We intend this dedication to be an overt act of
//  relinquishment in perpetuity of all present and future rights to this
//  software under copyright law.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
//  IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.
//
//  For more information, please refer to <https://unlicense.org/> 
//  
//  File Description
// ==================
//  
//  THIS IS A PART OF THE KAHC (KRISK'S ABSTRACT HEADER COLLECTION).
// ------------------------------------------------------------------
//  This file kahc_c_types.h is a header-only implementation of simplification
//  of C variable types. It redefines signed and unsigned integers, floating
//  point decimal variables such as doubles and floats, simple min/max macros
//  and return check macros.
//  Define #define KAHC_C_TYPES_IMPLEMENTATION in *ONE* file to use this
//  header. Only define *ONE* of the bit types.
//
//  Usage
// =======
//    
//  Variable Name       Definition
// ---------------     ------------
//
//  u8_                 unsigned 8-bit   integer
//  u16_                unsigned 16-bit  integer
//  u32_                unsigned 32-bit  integer
//  u64_                unsigned 64-bit  integer
//  u128_               unsigned 128-bit integer
//
//  s8_                 signed 8-bit   integer
//  s16_                signed 16-bit  integer
//  s32_                signed 32-bit  integer
//  s64_                signed 64-bit  integer
//  s128_               signed 128-bit integer
//
//  au8_                atomic unsigned 8-bit   integer
//  au16_               atomic unsigned 16-bit  integer
//  au32_               atomic unsigned 32-bit  integer
//  au64_               atomic unsigned 64-bit  integer
//  au128_              atomic unsigned 128-bit integer
//
//  as8_                atomic signed 8-bit   integer
//  as16_               atomic signed 16-bit  integer
//  as32_               atomic signed 32-bit  integer
//  as64_               atomic signed 64-bit  integer
//  as128_              atomic signed 128-bit integer
//
//  f32_                signed 32-bit  float / double
//  f64_                signed 64-bit  double
//  f128_               signed 96-bit to 128-bit double
//
//  Fu8_                format specifier for unsigned 8-bit integers for printf like functions
//  Fu16_               format specifier for unsigned 16-bit integers for printf like functions
//  Fu32_               format specifier for unsigned 32-bit integers for printf like functions
//  Fu64_               format specifier for unsigned 64-bit integers for printf like functions
//
//  Fs8_                format specifier for signed 8-bit integers for printf like functions
//  Fs16_               format specifier for signed 16-bit integers for printf like functions
//  Fs32_               format specifier for signed 32-bit integers for printf like functions
//  Fs64_               format specifier for signed 64-bit integers for printf like functions
//
//  Ff32_               format specifier for 32-bit floats for printf like functions
//  Ff64_               format specifier for 64-bit floats for printf like functions
//  Ff128_              format specifier for 128-bit floats for printf like functions
//
//  uz_                 unsigned architecture size
//  sz_                 signed   architecture size
//  sptrdif_            signed   pointer difference
//  bool_               unsigned 8-bit boolean (true_ / false_)
//
//  <type>MAX_          maximum value of <type> (not defined for atomics)
//  <type>MIN_          minimum value of <type> (not defined for atomics)
//  array_size_(x)      gets the amount of elements; does not work with pointers
//
//  null_               null void
//  nullptr_            null void
//  nonnull_            pointer must not be null
//
//  unused_(x)          suppresses "unused variable" warnings
//  nodiscard_          prevents ignoring a function's return value
//
//  uptr_               unsigned integer pointer
//  sptr_               signed   integer pointer   
//  
//  alignas_(x)         forces a variable to start at a specific memory boundary (in bytes)
//  alignof_(x)         returns the alignment requirement (in bytes) of a specific type
//  is_aligned_(ptr, align)  returns true if a pointer matches a specific byte alignment
//
//  Implementation                         Definition
// ----------------                       ------------
//  
//  #define KAHC_C_TYPES_IMPLEMENTATION    Allows this header to be used.
//  #define KAHC_C_TYPES_32_BIT            Provides all definitions up to
//                                         32-bits.
//  #define KAHC_C_TYPES_64_BIT            Provides all definitions up to
//                                         64-bits.
//  #define KAHC_C_TYPES_128_BIT           Provides all definitions up to
//                                         128-bits.
//  #define KAHC_C_TYPES_ATOMIC            Provides atomic signed and unsigned integers.
//                                         Provide a bit size before defining this.
//                                         NOTE: -latomic may be needed during linking.
//
//  Control History
// =================
//
//  Version    Data (UTC)    Time (NY)     Author                  Action
// ---------  ------------  ------------  --------                --------
//  1.0        2026/03/01    12:49         Ethan Bobowski          Finished kahc_c_types.h
//
//  TODO
// ======
//
//  Maybe fix comments and make code more readable.
//  Add any unfinished or more efficient types.
//  rm -rf microsoft for weird macros. No one needs this macro hell.
//






#pragma once

#ifndef _KAHC_C_TYPES_H_
#define _KAHC_C_TYPES_H_

#ifdef __cplusplus
  extern "C" {
#endif // __cplusplus

#include <stdint.h>
#include <stddef.h>
#include <inttypes.h>






//  32-Bit Types
// ==============

#if defined(KAHC_C_TYPES_32_BIT) || defined(KAHC_C_TYPES_64_BIT) || defined(KAHC_C_TYPES_128_BIT)
// Unsigned integers
typedef uint8_t   u8_;
typedef uint16_t  u16_;
typedef uint32_t  u32_;

// Unsigned pointers
typedef uintptr_t uptr_;
  
// Signed integers
typedef int8_t    s8_;
typedef int16_t   s16_;
typedef int32_t   s32_;
  
// Signed pointers
typedef intptr_t sptr_;

// Booleans
typedef uint8_t bool_;
#define true_   ((bool_) 1)
#define false_  ((bool_) 0)

// Size types 
typedef size_t    uz_;
typedef ptrdiff_t sptrdif_;
#if defined(_MSC_VER) || defined(_WIN32)
#include <BaseTsd.h>
  typedef SSIZE_T sz_;
#elif defined(__unix__) || defined(__APPLE__) || defined(__linux__) // _MSC_VER || _WIN32
#include <sys/types.h>
  typedef ssize_t sz_;
#else // else
  typedef ptrdiff_t sz_; // Fallback case
#endif // _MSC_VER || _WIN32 

// Decimal point variables
typedef float     f32_;
  
// Extras 
#define null_    ((void *) 0)
#define nullptr_ ((void *) 0)
#define unused_(x) ((void) (x))
#define array_size_(x) (sizeof(x) / sizeof((x)[0]))
#define is_aligned(ptr, align) (((uptr_)(ptr) & ((align) - 1)) == 0)
#if defined(__GNUC__) || defined(__clang__)
#define nodiscard_ __attribute__((warn_unused_result))
#define nonnull_ __attribute__((nonnull))
#elif defined(_MSC_VER) // _GNUC__ || __clang
#include <sal.h>
#define nodiscard_ _Check_return_
#define nonnull_   _In_
#else  // else
#define nodiscard_
#define nonnull_
#endif // __GNUC__ || __clang__

// Unsigned print type specifiers
#define Fu8_   PRIu8
#define Fu16_  PRIu16
#define Fu32_  PRIu32

// Signed print type specifiers
#define Fs8_   PRId8
#define Fs16_  PRId16
#define Fs32_  PRId32

// Decimal point print type specifiers
#define Ff32_  "f"

// Extra print type specifiers
#define Fuz_   "zu"
#define Fsz_   "zd"

// Fallback for static_assert 
#if !defined(__cplusplus) && !defined(static_assert)
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
#define static_assert _Static_assert
#else // else
#define static_assert(expr, msg) enum { static_assert_fail = 1/(!!(expr)) } // Fallback case
#endif // __STDC_VERSION__ && __STDC_VERSION__ >= 201112L 
#endif // __cplusplus && static_assert 

// Unsigned limits
#define U8_MAX_   ((u8_) 255)
#define U16_MAX_  ((u16_) 65535)
#define U32_MAX_  ((u32_) 4294967295U)

// Signed limits
#define S8_MIN_   ((s8_) -128)
#define S8_MAX_   ((s8_) 127)
#define S16_MIN_  ((s16_) -32768)
#define S16_MAX_  ((s16_) 32767)
#define S32_MIN_  ((s32_) -2147483647 - 1)
#define S32_MAX_  ((s32_) 2147483647)

// Memory alignment 
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
#include <stdalign.h>
#define alignas_(x) alignas(x)
#define alignof_(x) alignof(x)
#else // else
#define alignas_(x)
#define alignof_(x) sizeof(void *)
#endif  // __STDC_VERSION__ && __STDC_VERSION >= 201112L
#endif // KAHC_C_TYPES_32_BIT || KAHC_C_TYPES_64_BIT || KAHC_C_TYPES_128_BIT






//  64-Bit Types
// ==============

#if defined(KAHC_C_TYPES_64_BIT) || defined(KAHC_C_TYPES_128_BIT)
// Unsigned integers
typedef uint64_t  u64_;
  
// Signed integers
typedef int64_t   s64_;

// Decimal point variables
typedef double    f64_;
  
// Unsigned limits
#define U64_MAX_  ((u64_) 18446744073709551615ULL)

// Signed limits
#define S64_MIN_  ((s64_)-9223372036854775807LL - 1)
#define S64_MAX_  ((s64_)9223372036854775807LL)

// Unsigned print type specifiers
#define Fu64_   PRIu64

// Signed print type specifiers
#define Fs64_   PRId64

// Decimal point print type specifiers
#define Ff64_   "f"
#endif // KAHC_C_TYPES_64_BIT || KAHC_C_TYPES_128_BIT






//  128-Bit Types
// =============== 

#if defined(KAHC_C_TYPES_128_BIT)
  // Compiler extension for 128-bit integers
  #if defined(__SIZEOF_INT128__)
  // Unsigned integers
  typedef unsigned __int128 u128_;

  // Signed integers
  typedef __int128          s128_;

  // Unsigned limits
  #define U128_MAX_ ((u128_)-1)

  // Signed limits 
#define S128_MAX_ ((s128_)(U128_MAX_ >> 1))
#define S128_MIN_ ((s128_)-S128_MAX_ - 1)
#endif // __SIZEOF_INT128__

// Decimal point print type specifiers
#define Ff128_ "Lf"

// Decimal point variables
typedef long double f128_;
#endif // KAHC_C_TYPES_128_BIT






//  Atomic Types
// ==============

#ifdef KAHC_C_TYPES_ATOMIC
#if defined(__STDC_NO_ATOMICS__)
#error "KAHC_C_TYPES_ATOMIC defined, but the compiler does not support <stdatomic.h>. "
#else // else
#include <stdatomic.h>
  // Unsigned atomic integers
  typedef _Atomic u8_   au8_;
  typedef _Atomic u16_  au16_;
  typedef _Atomic u32_ au32_;

  // Signed atomic integers
  typedef _Atomic s8_   as8_;
  typedef _Atomic s16_  as16_;
  typedef _Atomic s32_  as32_;

// 64-bit unsigned and signed atomic integers
#if defined(KAHC_C_TYPES_64_BIT) || defined(KAHC_C_TYPES_128_BIT)
  // Unsigned atomic integers
  typedef _Atomic u64_  au64_;

  // Signed atomic integers
  typedef _Atomic s64_  as64_;
#endif // KAHC_C_TYPES_64_BIT || KAHC_C_TYPES_128_BIT

// 128-bit unsigned and signed atomic integers
#if defined(KAHC_C_TYPES_128_BIT) && defined(__SIZEOF_INT128__)
  // Unsigned atomic integers
  typedef _Atomic u128_ au128_;

  // Signed atomic integers
  typedef _Atomic s128_ as128_;
#endif // KAHC_C_TYPES_128_BIT && __SIZEOF_INT128__

// Atomic booleans
typedef _Atomic bool_ abool_;

#endif // __STDC_NO_ATOMICS__
#endif // KAHC_C_TYPES_ATOMIC






//  Header Guard Implementation
// =============================

#ifdef KAHC_C_TYPES_IMPLEMENTATION

// Check if a bit size was defined
#if !defined(KAHC_C_TYPES_32_BIT) && !defined(KAHC_C_TYPES_64_BIT) && !defined(KAHC_C_TYPES_128_BIT)
#error "KAHC_C_TYPES_IMPLEMENTATION defined, but a bit size was not defined. " \
       "Define KAHC_C_TYPES_32_BIT, KAHC_C_TYPES_64_BIT, or KAHC_C_TYPES_128_BIT. "
#endif // !KAHC_C_TYPES_32_BIT && !KAHC_C_TYPES_64_BIT && !KAHC_C_TYPES_128_BIT






//  32-Bit Implementation Checks
// ============================== 

#if defined(KAHC_C_TYPES_32_BIT) || defined(KAHC_C_TYPES_64_BIT) || defined(KAHC_C_TYPES_128_BIT)
  // Compile-time checks for correct size
  static_assert(sizeof(uz_) == sizeof(void*), "uz_ must match pointer size");
  static_assert(sizeof(bool_) == 1, "bool_ must be 8 bits");
  static_assert(sizeof(f32_) == 4, "f32_ must be exactly 4 bytes (32 bits)");
#endif // KAHC_C_TYPES_32_BIT || KAHC_C_TYPES_64_BIT || KAHC_C_TYPES_128_BIT






//  64-Bit Implementation Checks
// ==============================

#if defined(KAHC_C_TYPES_64_BIT) || defined(KAHC_C_TYPES_128_BIT)
  // Compile-time checks for correct size
  static_assert(sizeof(f64_) == 8, "f64_ must be exactly 8 bytes (64 bits)");
#endif // KAHC_C_TYPES_64_BIT || KAHC_C_TYPES_128_BIT






//  128-Bit Implementation Checks
// ===============================

#if defined(KAHC_C_TYPES_128_BIT)
  // Compile-time checks for correct size
  static_assert(sizeof(f128_) >= 12, "f128_ must be at least 12 bytes (96 bits)");
#endif // KAHC_C_TYPES_128_BIT






#endif // KAHC_C_TYPES_IMPLEMENTATION 
#ifdef __cplusplus
  }
#endif // __cplusplus
#endif // _KAHC_C_TYPES_H_
// EOF
