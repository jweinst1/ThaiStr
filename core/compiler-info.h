#ifndef THAISTR_CORE_COMPILER_INFO_H
#define THAISTR_CORE_COMPILER_INFO_H

/**
 * The following tells us what kind of C
 * features are available to us. Also informs
 * of specific requirements to the OS
 */

#if defined(__STDC__)
#  if defined(__STDC_VERSION__)
#    if (__STDC_VERSION__ >= 199409L)
#        if (__STDC_VERSION__ >= 199901L)
#           if (__STDC_VERSION__ >= 201112L)
#              define THAISTR_CVERS_11
#           else // !(__STDC_VERSION__ >= 201112L)
#              define THAISTR_CVERS_99
#           endif // (__STDC_VERSION__ >= 201112L)
#        else // !(__STDC_VERSION__ >= 199901L)
#           define THAISTR_CVERS_94
#        endif // (__STDC_VERSION__ >= 199901L)
#    else // (__STDC_VERSION__ >= 199409L)
#       define THAISTR_CVERS_90
#    endif // !(__STDC_VERSION__ >= 199409L)
#  else // defined(__STDC_VERSION__)
#    define THAISTR_CVERS_89
#  endif // !defined(__STDC_VERSION__)
#else // defined(__STDC__)
#  warning "__STDC__ is not defined, this is a non-standard C version." 
#endif

#if defined(__unix__) || defined(__APPLE__) && defined(__MACH__)
#  define THAISTR_OS_UNIX
#endif

#ifdef _WIN32
#  define THAISTR_OS_WIN
#endif

#ifdef SAPPHIRE_STD_C_1999
#  define THAISTR_HAS_VARIADIC_ARGS
#  define THAISTR_HAS_STDINT
#endif

/*
#ifdef WIN32_UTF16_PATHNAMES
#  ifndef THAISTR_CVERS_94
#     include <stddef.h>
#  else
#     include <wchar.h>
#  endif // SAPPHIRE_STD_C_1994
   typedef wchar_t ospath_ch_t;
#  define OSPATH_CON(expr) L##expr
#else
   typedef char ospath_ch_t;
#  define OSPATH_CON(expr) expr
#endif // WIN32_UTF16_PATHNAMES
*/

#endif // THAISTR_CORE_COMPILER_INFO_H
