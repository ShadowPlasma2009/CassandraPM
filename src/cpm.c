// src/cpm.c

#include <stdio.h>
#include <string.h>
#include "help.h"

int main(int argc, char *argv[]) {
  const char version[] = "0.01-Dev";

  if (argc == 1) {
    usage();
  } else if (argc == 2 && strcmp(argv[1], "help") == 0) {
    help(version);
    return 0;
  }
  return 0;
}

void usage(void) {
  printf("Usage: cpm <command> [arguments]\n");
}
