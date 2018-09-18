/**
  * Touhou type library
  * Disables unnecessary warnings on certain compilers
  *
  * Should be #included at the beginning of every public header file, before
  * pragma_push.h.
  */

#ifdef _MSC_VER
# pragma warning(push)
/* Disables:
 * • C4103: alignment changed after including header
 * • C4200: nonstandard extension used : zero-sized array in struct/union
 */
# pragma warning(disable: 4103 4200)
#endif
