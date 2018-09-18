/**
  * Touhou type library
  * Restores the state of unnecessary warnings on certain compilers
  *
  * Should be #included at the end of every public header file, after
  * pragma_pop.h.
  *
  * Needs to be separate from pragma_pop.h, because we still get C4103 on
  * Visual Studio if we disable that warning anywhere in a file where the
  * pack #pragma is changed.
  */

#ifdef _MSC_VER
# pragma warning(pop)
#endif
