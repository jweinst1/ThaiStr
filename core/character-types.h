#ifndef THAISTR_CORE_CHARACTER_TYPES_H
#define THAISTR_CORE_CHARACTER_TYPES_H

/*Character conversions*/

#include <limits.h>
#include "compiler-info.h"

/* Determine type for unsigned, 16-bit integer */
#ifdef THAISTR_CVERS_99 || THAISTR_CVERS_11
#  include <stdint.h>
   typedef uint16_t tis620_t;
#else // ! THAISTR_CVERS_99 || THAISTR_CVERS_11
#   if USHRT_MAX == 65535
      typedef unsigned short tis620_t;
#   else
#      if UINT_MAX >= 65535
          typedef unsigned int tis620_t;
#      else
#         if ULONG_MAX >= 65535
          typedef unsigned long tis620_t;
#         else
#            error "Cannot find an unsigned 16-bit integer type"
#         endif
#      endif
#   endif
#endif // THAISTR_CVERS_99 || THAISTR_CVERS_11

/* Determines type for signed, 8-bit integer (utf8) */
#ifdef THAISTR_CVERS_99 || THAISTR_CVERS_11
   // stdint.h already included above.
   typedef int8_t utf8_t;
#else // ! // THAISTR_CVERS_99 || THAISTR_CVERS_11
   typedef char utf8_t;
#endif // THAISTR_CVERS_99 || THAISTR_CVERS_11

#define THAISTR_UINT16_IS_TIS(num) (num < 0x0080)


#endif // THAISTR_CORE_CHARACTER_TYPES_H
