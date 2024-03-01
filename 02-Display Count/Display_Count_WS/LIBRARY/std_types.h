/*
 ============================================================================
 Module      : Common - Platform Types Abstraction
 File Name   : std_types.h
 Description : Types for AVR
 Author      : AHMED Abdel-Monem El-Askary
 Date        : 16/10/2023
 ============================================================================
 */
#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char boolean;

#ifndef FALSE
#define FALSE       (0u)
#endif
#ifndef TRUE
#define TRUE        (1u)
#endif

#define LOGIC_HIGH        (1u)
#define LOGIC_LOW         (0u)

#define NULL_PTR    ((void*)0)

typedef unsigned char         u8;
typedef signed char           s8;

typedef unsigned short        u16;
typedef signed short          s16;

typedef unsigned long         u32;
typedef signed long           s32;

typedef unsigned long long    u64;
typedef signed long long      s64;

typedef float                 f32;
typedef double                f64;

#endif /* STD_TYPE_H_ */
