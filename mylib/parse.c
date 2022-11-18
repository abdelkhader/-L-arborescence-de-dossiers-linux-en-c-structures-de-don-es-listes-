#include<string.h>
#include <stdio.h>
#include <string.h>

int parse(const char *src, char *v1, char *v2)
{
  return sscanf(src,"%s = %s",v1,v2)==2 ;
}