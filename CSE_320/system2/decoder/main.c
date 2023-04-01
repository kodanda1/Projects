/**
 * Main program for testing the decoder
 */
#include <stdio.h>
#include "decoder.h"

/*
 * Main
 */
int main()
{
  const char *encoded="\
                       ff%^Gwcg^ZgfZ^w%cp%BwB^ZZ^gwffcgcpwwgGw^%ZfcZ^wZfBBGg^ZBwfGw\
                       ZZfpMBf^BfGfwgZZGZZMZppwZB%ffcfwp!w!ZZBZ^fcgZpfZZG%B!ZBZww!p\
                       %wZ%M!ZpggfcgGwp%w%ZMBcc^fcw^cw%wZ%g^ZfwGcGwwf%%%gf%ffZgwwcc\
                       gZp!^Gwcg^Z!Z%gpffcMBcffpfZ!ZZfwwppgwfww!pfwfGwGcp^ZZZw%fZw%\
                       ^wfGgZcfgfgZw%^pfZp!wpgfB%ffwGwpM^cZcwgGpBwfZ%fwgfBfZcwgGM!c\
                       pwZp!cg^wfZZZgZ^Bw!B^!fZZZpZfBBZBB%fZ%%fwwZ!Ggp!gfgcpcZwZZB!\
                       %g%ffgB^GcZwMZfZ%!%Gp!wpZppZffpwcgZgfGcZw%ZgwMfwG^w!ccgZ!%^g\
                       !ZpGZgZwGw%^wZ!g%gfcZwp!%G%BGwfGcfwZ!p^wg!%gZwcgZg^%%g!%pGwp\
                       gf^fG^ZZZgfZ^Gww!%ZMfgBf^Bfw^cG^%ZZ^c%ffZgf%B%ffpg^GwGw%Zg%!\
                       fZ%BZgZgZ^fwZgB^f^ZZZgBZfwwffwccGww!%^ccB!!pgGp!w!%w";
  
  char decoded[1000];

  decoder(encoded, decoded, sizeof(decoded));
  printf("%s\n", decoded);

  return 0;
}
