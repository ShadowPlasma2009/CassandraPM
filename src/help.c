// src/help.c

#include <stdio.h>
#include "help.h"

void help(const char version[]) {
  printf("Cassandra Package Manager %s\n", version);
  printf("Usage: cpm <command> [arguments]\n");
  printf("\nCommands:\n");
  printf(" install <package>\n");
  printf(" remove <package>\n");
  printf(" search <package>\n");
  printf(" update\n");
  printf(" upgrade\n");
  printf(" help\n");
}
