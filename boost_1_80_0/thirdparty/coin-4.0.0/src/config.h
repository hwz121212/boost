/* src/config.h.  Generated from config.h.cmake.in by CMake. */


#ifndef COIN_INTERNAL
#error this is a private header file
#endif

#include <unconfig.h>
#include <setup.h>


/* define this to the libCoin beta version letter */
#define COIN_BETA_VERSION 

/* define this to a type of the indicated bitwidth */
#define COIN_INT16_T int16_t

/* define this to a type of the indicated bitwidth */
#define COIN_INT32_T int32_t

/* define this to a type of the indicated bitwidth */
#define COIN_INT64_T int64_t

/* define this to a type of the indicated bitwidth */
#define COIN_INT8_T int8_t

/* define this to a type of the indicated bitwidth */
#define COIN_INTPTR_T intptr_t

/* Define when building Mac OS X framework */
/* #undef COIN_MACOSX_FRAMEWORK */

/* Define for Mac OS X builds */
/* #undef COIN_MACOS_10 */

/* Define for Mac OS 10.1 builds */
/* #undef COIN_MACOS_10_1 */

/* Define for Mac OS 10.2 builds */
/* #undef COIN_MACOS_10_2 */

/* Define for Mac OS 10.3 and later builds */
/* #undef COIN_MACOS_10_3 */

/* define this to the libCoin major version number */
#define COIN_MAJOR_VERSION 4

/* define this to the libCoin release version number */
#define COIN_MICRO_VERSION 0

/* define this to the libCoin minor version number */
#define COIN_MINOR_VERSION 0

/* define this to the dynamic library name of Coin */
#ifdef _DEBUG
#define COIN_SYSTEM_LIBRARY_NAME "Coin.dll"
#else
#define COIN_SYSTEM_LIBRARY_NAME "Coin.dll"
#endif

/* System dependent thread ID type */
#define COIN_THREADID_TYPE DWORD

/* define this to a type of the indicated bitwidth */
#define COIN_UINT16_T uint16_t

/* define this to a type of the indicated bitwidth */
#define COIN_UINT32_T uint32_t

/* define this to a type of the indicated bitwidth */
#define COIN_UINT64_T uint64_t

/* define this to a type of the indicated bitwidth */
#define COIN_UINT8_T uint8_t

/* define this to a type of the indicated bitwidth */
#define COIN_UINTPTR_T uintptr_t

/* define to "remove" conflicting IN_PATH define from <sys/unistd.h> */
/* #undef COIN_UNDEF_IN_PATH_HACK */

/* define this to the full libCoin major.minor.micro version number */
#define COIN_VERSION "4.0.0"

/* define this to the dynamic library extension suffix on this system */
#define DYNAMIC_LIBRARY_EXTENSION ".dll"

/* define for runtime linking with fontconfig */
#define FONTCONFIG_RUNTIME_LINKING 1

/* define for runtime linking with freetype */
#define FREETYPE_RUNTIME_LINKING 1

/* define if GLU is part of the GL library */
/* #undef GLU_IS_PART_OF_GL */

/* define for runtime linking with GLU */
#define GLU_RUNTIME_LINKING 1

/* define if you have AGL OpenGL bindings */
/* #undef HAVE_AGL */

/* define if AGL pBuffers are available on the system */
/* #undef HAVE_AGL_PBUFFER */

/* define if the AL header should be included as AL/al.h */
/* #undef HAVE_AL_AL_H */

/* define if preprocessor can quote arguments with apostophes */
/* #undef HAVE_APOSTROPHES_QUOTING */

/* Define if assert() uses __builtin_expect() */
/* #undef HAVE_ASSERT_WITH_BUILTIN_EXPECT */

/* define if bcopy() is available */
/* #undef HAVE_BCOPY */

/* Define to use bzip2 */
/* #undef HAVE_BZIP2 */

/* define if you have CGL OpenGL bindings */
/* #undef HAVE_CGL */

/* define if you have the CoreText framework */
/* #undef HAVE_CORETEXT */

/* The CPP compiler has a variable containing the current function name */
#define HAVE_CPP_COMPILER_FUNCTION_NAME_VAR __func__

/* The C compiler has a variable containing the current function name */
#define HAVE_C_COMPILER_FUNCTION_NAME_VAR __func__

/* Define to 1 if you have the <direct.h> header file. */
#define HAVE_DIRECT_H 1

/* define if the DLD shared library loader is available */
/* #undef HAVE_DLD_LIB */

/* Define to 1 if you have the <dlfcn.h> header file. */
/* #undef HAVE_DLFCN_H */

/* define if you have the dl library */
/* #undef HAVE_DL_LIB */

/* define if the Mac OS X dyld can be used for runtime binding */
/* #undef HAVE_DYLD_RUNTIME_BINDING */

/* should be defined if there is some way of doing dynamic linking */
#define HAVE_DYNAMIC_LINKING 1

/* whether or not finite() is available */
/* #undef HAVE_FINITE */

/* define if you have the fontconfig library */
/* #undef HAVE_FONTCONFIG */

/* define that the Fontconfig header is available */
/* #undef HAVE_FONTCONFIG_H */

/* whether or not fpclass() is available */
/* #undef HAVE_FPCLASS */

/* define if you have the freetype library */
/* #undef HAVE_FREETYPE */

/* define that the FreeType header is available */
/* #undef HAVE_FREETYPE_H */

/* define if fstat() is available */
#define HAVE_FSTAT 1

/* Define to use ftime() */
#define HAVE_FTIME

/* Define to use getcwd() */
/* #undef HAVE_GETCWD */

/* Define to use GetEnvironmentVariable() instead of getenv() */
#define HAVE_GETENVIRONMENTVARIABLE

/* Define to use SVr4 / BSD4.3 gettimeofday() */
/* #undef HAVE_GETTIMEOFDAY */

/* define if you have GLU */
/* #undef HAVE_GLU */

/* define if you have GLX X11 OpenGL bindings */
/* #undef HAVE_GLX */

/* Define to use gzdopen() */
#define HAVE_GZDOPEN 1

/* define if preprocessor can quote arguments with the hash symbol */
#define HAVE_HASH_QUOTING 1

/* Define to 1 if you have the <ieeefp.h> header file. */
/* #undef HAVE_IEEEFP_H */

/* Define to use ilogb() */
#define HAVE_ILOGB

/* define this if the type is available on the system */
#define HAVE_INT16_T 1

/* define this if the type is available on the system */
#define HAVE_INT32_T 1

/* define this if the type is available on the system */
#define HAVE_INT64_T 1

/* define this if the type is available on the system */
#define HAVE_INT8_T 1

/* define this if the type is available on the system */
#define HAVE_INTPTR_T 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the <io.h> header file. */
#define HAVE_IO_H 1

/* define if isinf() is available */
#define HAVE_ISINF

/* whether or not isnan() is available */
#define HAVE_ISNAN

/* Define this if you build the Java wrapper */
/* #undef HAVE_JAVA_WRAPPER */

/* Define to 1 if you have the <libgen.h> header file. */
/* #undef HAVE_LIBGEN_H */

/* define if you have the simage library */
/* #undef HAVE_LIBSIMAGE */

/* Define to 1 if you have the <mach-o/dyld.h> header file. */
/* #undef HAVE_MACH_O_DYLD_H */

/* define if memmove() is available */
#define HAVE_MEMMOVE 1

/* Define to 1 if you have the <memory.h> header file. */
/* #undef HAVE_MEMORY_H */

/* Define if you have the <netinet/in.h> header file. */
/* #undef HAVE_NETINET_IN_H */

/* openal extensions available */
/* #undef HAVE_OPENAL */

/* define if the AL header should be included as OpenAL/al.h */
/* #undef HAVE_OPENAL_AL_H */

/* define if you have OpenGL */
#define HAVE_OPENGL 1

/* Define to 1 if you have the <OpenGL/CGLCurrent.h> header file. */
/* #undef HAVE_OPENGL_CGLCURRENT_H */

/* define if the GLEXT header should be included as OpenGL/glext.h */
/* #undef HAVE_OPENGL_GLEXT_H */

/* define if the GLU header should be included as OpenGL/glu.h */
/* #undef HAVE_OPENGL_GLU_H */

/* define if the GL header should be included as OpenGL/gl.h */
/* #undef HAVE_OPENGL_GL_H */

/* define if pthread's struct timespec uses nsecs and not usecs */
/* #undef HAVE_PTHREAD_TIMESPEC_NSEC */

/* Define to use Win32 QueryPerformanceCounter() */
#define HAVE_QUERYPERFORMANCECOUNTER

/* define if snprintf() is available */
/* #undef HAVE_SNPRINTF */

/* define that the Spidermonkey header is available */
/* #undef HAVE_SPIDERMONKEY_H */

/* define if you have the SpiderMonkey library */
/* #undef HAVE_SPIDERMONKEY_VIA_LINKTIME_LINKING */

/* Define to 1 if you have the <stddef.h> header file. */
#define HAVE_STDDEF_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
/* #undef HAVE_STDLIB_H */

/* Define to 1 if you have the <strings.h> header file. */
/* #undef HAVE_STRINGS_H */

/* Define to 1 if you have the <string.h> header file. */
/* #undef HAVE_STRING_H */

/* Define to use BSD4.3 strncasecmp() */
/* #undef HAVE_STRNCASECMP */

/* *EXPERIMENTAL* to use the GLU we've "appropriated" from SGI */
/* #undef HAVE_SUPERGLU */

/* Define this if you want to use a system installation of expat */
/* #undef HAVE_SYSTEM_EXPAT */

/* Define to 1 if you have the <sys/param.h> header file. */
/* #undef HAVE_SYS_PARAM_H */

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/timeb.h> header file. */
#define HAVE_SYS_TIMEB_H 1

/* Define to 1 if you have the <sys/time.h> header file. */
/* #undef HAVE_SYS_TIME_H */

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <sys/unistd.h> header file. */
/* #undef HAVE_SYS_UNISTD_H */

/* to use the platform-independent thread-handling abstractions */
#define HAVE_THREADS

/* Define to use timeGetTime() */
/* #undef HAVE_TIMEGETTIME */

/* Define to 1 if you have the <time.h> header file. */
#define HAVE_TIME_H 1

/* Define to 1 if you have the <tlhelp32.h> header file. */
#define HAVE_TLHELP32_H 1

/* define this if the type is available on the system */
#define HAVE_UINT16_T 1

/* define this if the type is available on the system */
#define HAVE_UINT32_T 1

/* define this if the type is available on the system */
#define HAVE_UINT64_T 1

/* define this if the type is available on the system */
#define HAVE_UINT8_T 1

/* define this if the type is available on the system */
#define HAVE_UINTPTR_T 1

/* Define to 1 if you have the <unistd.h> header file. */
/* #undef HAVE_UNISTD_H */

/* Define to use va_copy() when available */
#define HAVE_VA_COPY_MACRO

/* define if vsnprintf() is available */
#define HAVE_VSNPRINTF 1

/* define if you have WGL Win32 OpenGL bindings */
#define HAVE_WGL

/* Define if the Win32 API is available */
#define HAVE_WIN32_API

/* define if the Win32 LoadLibrary method is available */
#define HAVE_WINDLL_RUNTIME_BINDING

/* Define to 1 if you have the <windows.h> header file. */
#define HAVE_WINDOWS_H 1

/* define if it is possible to build against X11 */
/* #undef HAVE_X11_AVAILABLE */

/* Define to use zlib */
/* #undef HAVE_ZLIB */

/* whether or not _finite() is available */
#define HAVE__FINITE

/* whether or not _fpclass() is available */
#define HAVE__FPCLASS

/* Define to use Win32 _ftime() */
/* #undef HAVE__FTIME */

/* Define to use Win32 _getcwd() */
#define HAVE__GETCWD

/* whether or not _isnan() is available */
/* #undef HAVE__ISNAN */

/* Define to use Win32 _logb() */
/* #undef HAVE__LOGB */

/* define if _snprintf() is available */
/* #undef HAVE__SNPRINTF */

/* define if the system has _splitpath() */
#define HAVE__SPLITPATH

/* define if _vsnprintf() is available */
/* #undef HAVE__VSNPRINTF */

/* Define if compiler has __builtin_expect() macro */
/* #undef HAVE___BUILTIN_EXPECT */

/* define for runtime linking with zlib */
#define LIBBZIP2_RUNTIME_LINKING 1

/* define for runtime linking with OpenAL */
#define OPENAL_RUNTIME_LINKING 1

/* define this to the dynamic library name of OpenGL */
#define OPENGL_SYSTEM_LIBRARY_NAME "opengl32.dll"

/* Name of package */
#define PACKAGE "Coin"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "coin-support@coin3d.org"

/* Define to the full name of this package. */
#define PACKAGE_NAME "Coin"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "Coin 4.0.0"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "coin"

/* Define to the version of this package. */
#define PACKAGE_VERSION "4.0.0"

/* define for runtime linking with simage */
#define SIMAGE_RUNTIME_LINKING 1

/* define for choosing correct variable size */
#define SIM_TIMEVAL_TV_SEC_T long

/* define for choosing correct variable size */
#define SIM_TIMEVAL_TV_USEC_T long

/* define for runtime linking with SpiderMonkey */
#define SPIDERMONKEY_RUNTIME_LINKING 1

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define to make Coin use/catch exceptions at some particular places. */
#define USE_EXCEPTIONS 1

/* define to use the POSIX threads API */
/* #undef USE_PTHREAD */

/* define to use the Win32 threads API */
#define USE_W32THREAD

/* Version number of package */
#define VERSION "4.0.0"

/* Define to 1 if the X Window System is missing or not being used. */
/* #undef X_DISPLAY_MISSING */

/* Define to extract entropy from /dev/urandom. */
/* #undef XML_DEV_URANDOM */

/* define for runtime linking with zlib */
#define ZLIB_RUNTIME_LINKING 1
