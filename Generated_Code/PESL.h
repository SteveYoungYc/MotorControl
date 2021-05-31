/* ================================================================================================================================= **
** ================================================================================================================================= **
** CONFIGURATION FILE FOR PESL LIBRARY                                                                                               **
** ================================================================================================================================= **
** ================================================================================================================================= */

#ifndef __PESL_H
#define __PESL_H


#define _56852             1
#define _56853             2
#define _56854             3
#define _56855             4
#define _56857             5
#define _56858             6
#define _56F801            7
#define _56F802            8
#define _56F803            9
#define _56F805           10
#define _56F807           11
#define _56F826           12
#define _56F827           13
#define _56F8322          14
#define _56F8323          15
#define _56F8333          16
#define _56F8334          17
#define _56F8345          18
#define _56F8346          19
#define _56F8355          20
#define _56F8356          21
#define _56F8357          22
#define _56F8347          23
#define _56F8365          24
#define _56F8366          25
#define _56F8367          26
#define _56F8122          27
#define _56F8123          28
#define _56F8133          29
#define _56F8134          30
#define _56F8145          31
#define _56F8146          32
#define _56F8155          33
#define _56F8156          34
#define _56F8157          35
#define _56F8147          36
#define _56F8165          37
#define _56F8166          38
#define _56F8167          39
#define _56859            40
#define _56F8011          41
#define _56F8012          42
#define _56F8013VPE       43
#define _56F8014VPE       44
#define _56F8013VFAE      45
#define _56F8014VFAE      46
#define _56F8335          47
#define _56F8135          48
#define _56F8023          49
#define _56F8025          50
#define _56F8036          51
#define _56F8037          52
#define _56F8006_48_LQFP  53
#define _56F8006_32_LQFP  54
#define _56F8006_32_SDIP  55
#define _56F8006_28_SOIC  56
#define _56F8002_48_LQFP  57
#define _56F8002_32_LQFP  58
#define _56F8002_32_SDIP  59
#define _56F8002_28_SOIC  60
#define _56F8257          61
#define _56F8256          62
#define _56F8255          63
#define _56F8247          64
#define _56F8246          65
#define _56F8245          66
#define _56F8027          67
#define _56F8033          68
#define _56F8035          69
#define _MC56F84441VLF    70
#define _MC56F84442VLH    71
#define _MC56F84451VLF    72
#define _MC56F84452VLH    73
#define _MC56F84540VLF    74
#define _MC56F84543VLH    75
#define _MC56F84462VLH    76
#define _MC56F84550VLF    77
#define _MC56F84553VLH    78
#define _MC56F84565VLK    79
#define _MC56F84567VLL    80
#define _MC56F84585VLK    81
#define _MC56F84587VLL    82
#define _MC56F84763VLH    83
#define _MC56F84766VLK    84
#define _MC56F84769VLL    85
#define _MC56F84786VLK    86
#define _MC56F84789VLL    87

/* Selected target MCU */

#define CPUtype _56F8257

/* Include appropriate I/O map file */
#if   (CPUtype == _56852)
  #include "56852.h"
#elif (CPUtype == _56853)
  #include "56853.h"
#elif (CPUtype == _56854)
  #include "56854.h"
#elif (CPUtype == _56855)
  #include "56855.h"
#elif (CPUtype == _56857)
  #include "56857.h"
#elif (CPUtype == _56858)
  #include "56858.h"
#elif (CPUtype == _56859)
  #include "56859.h"
#elif (CPUtype == _56F801)
  #include "56F801.h"
#elif (CPUtype == _56F802)
  #include "56F802.h"
#elif (CPUtype == _56F803)
  #include "56F803.h"
#elif (CPUtype == _56F805)
  #include "56F805.h"
#elif (CPUtype == _56F807)
  #include "56F807.h"
#elif (CPUtype == _56F826)
  #include "56F826.h"
#elif (CPUtype == _56F827)
  #include "56F827.h"
#elif (CPUtype == _56F8322)
  #include "56F8322.h"
#elif (CPUtype == _56F8323)
  #include "56F8323.h"
#elif (CPUtype == _56F8333)
  #include "56F8333.h"
#elif (CPUtype == _56F8334)
  #include "56F8334.h"
#elif (CPUtype == _56F8345)
  #include "56F8345.h"
#elif (CPUtype == _56F8346)
  #include "56F8346.h"
#elif (CPUtype == _56F8355)
  #include "56F8355.h"
#elif (CPUtype == _56F8356)
  #include "56F8356.h"
#elif (CPUtype == _56F8357)
  #include "56F8357.h"
#elif (CPUtype == _56F8347)
  #include "56F8347.h"
#elif (CPUtype == _56F8365)
  #include "56F8365.h"
#elif (CPUtype == _56F8366)
  #include "56F8366.h"
#elif (CPUtype == _56F8367)
  #include "56F8367.h"
#elif (CPUtype == _56F8122)
  #include "56F8122.h"
#elif (CPUtype == _56F8123)
  #include "56F8123.h"
#elif (CPUtype == _56F8133)
  #include "56F8133.h"
#elif (CPUtype == _56F8134)
  #include "56F8134.h"
#elif (CPUtype == _56F8145)
  #include "56F8145.h"
#elif (CPUtype == _56F8146)
  #include "56F8146.h"
#elif (CPUtype == _56F8155)
  #include "56F8155.h"
#elif (CPUtype == _56F8156)
  #include "56F8156.h"
#elif (CPUtype == _56F8157)
  #include "56F8157.h"
#elif (CPUtype == _56F8147)
  #include "56F8147.h"
#elif (CPUtype == _56F8165)
  #include "56F8165.h"
#elif (CPUtype == _56F8166)
  #include "56F8166.h"
#elif (CPUtype == _56F8167)
  #include "56F8167.h"
#elif (CPUtype == _56F8011)
  #include "56F8011.h"
#elif (CPUtype == _56F8012)
  #include "56F8012.h"
#elif (CPUtype == _56F8013VPE)
  #include "56F8013VPE.h"
#elif (CPUtype == _56F8014VPE)
  #include "56F8014VPE.h"
#elif (CPUtype == _56F8013VFAE)
  #include "56F8013VFAE.h"
#elif (CPUtype == _56F8014VFAE)
  #include "56F8014VFAE.h"
#elif (CPUtype == _56F8335)
  #include "56F8335.h"
#elif (CPUtype == _56F8135)
  #include "56F8135.h"
#elif (CPUtype == _56F8023)
  #include "56F8023.h"
#elif (CPUtype == _56F8025)
  #include "56F8025.h"
#elif (CPUtype == _56F8036)
  #include "56F8036.h"
#elif (CPUtype == _56F8037)
  #include "56F8037.h"
#elif (CPUtype == _56F8006_48_LQFP)
  #include "56F8006_48_LQFP.h"
#elif (CPUtype == _56F8006_32_LQFP)
  #include "56F8006_32_LQFP.h"
#elif (CPUtype == _56F8006_32_SDIP)
  #include "56F8006_32_SDIP.h"
#elif (CPUtype == _56F8006_28_SOIC)
  #include "56F8006_28_SOIC.h"
#elif (CPUtype == _56F8002_48_LQFP)
  #include "56F8002_48_LQFP.h"
#elif (CPUtype == _56F8002_32_LQFP)
  #include "56F8002_32_LQFP.h"
#elif (CPUtype == _56F8002_32_SDIP)
  #include "56F8002_32_SDIP.h"
#elif (CPUtype == _56F8002_28_SOIC)
  #include "56F8002_28_SOIC.h"
#elif (CPUtype == _56F8257)
  #include "56F8257.h"
#elif (CPUtype == _56F8256)
  #include "56F8256.h"
#elif (CPUtype == _56F8255)
  #include "56F8255.h"
#elif (CPUtype == _56F8247)
  #include "56F8247.h"
#elif (CPUtype == _56F8246)
  #include "56F8246.h"
#elif (CPUtype == _56F8245)
  #include "56F8245.h"
#elif (CPUtype == _56F8027)
  #include "56F8027.h"
#elif (CPUtype == _56F8033)
  #include "56F8033.h"
#elif (CPUtype == _56F8035)
  #include "56F8035.h"
#elif (CPUtype == _MC56F84441VLF)
  #include "MC56F84441VLF.h"
#elif (CPUtype == _MC56F84442VLH)
  #include "MC56F84442VLH.h"
#elif (CPUtype == _MC56F84451VLF)
  #include "MC56F84451VLF.h"
#elif (CPUtype == _MC56F84452VLH)
  #include "MC56F84452VLH.h"
#elif (CPUtype == _MC56F84462VLH)
  #include "MC56F84462VLH.h"
#elif (CPUtype == _MC56F84540VLF)
  #include "MC56F84540VLF.h"
#elif (CPUtype == _MC56F84543VLH)
  #include "MC56F84543VLH.h"
#elif (CPUtype == _MC56F84550VLF)
  #include "MC56F84550VLF.h"
#elif (CPUtype == _MC56F84553VLH)
  #include "MC56F84553VLH.h"
#elif (CPUtype == _MC56F84565VLK)
  #include "MC56F84565VLK.h"
#elif (CPUtype == _MC56F84567VLL)
  #include "MC56F84567VLL.h"
#elif (CPUtype == _MC56F84585VLK)
  #include "MC56F84585VLK.h"
#elif (CPUtype == _MC56F84587VLL)
  #include "MC56F84587VLL.h"
#elif (CPUtype == _MC56F84763VLH)
  #include "MC56F84763VLH.h"
#elif (CPUtype == _MC56F84766VLK)
  #include "MC56F84766VLK.h"
#elif (CPUtype == _MC56F84769VLL)
  #include "MC56F84769VLL.h"
#elif (CPUtype == _MC56F84786VLK)
  #include "MC56F84786VLK.h"
#elif (CPUtype == _MC56F84789VLL)
  #include "MC56F84789VLL.h"
#else
  #error PESL doesn't support selected CPU.
#endif

/* PESL library */

#include "PESLlib.h"

#endif /* ifndef __PESL_H */
