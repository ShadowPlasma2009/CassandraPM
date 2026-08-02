// src/help.c
#include <stdio.h>
#include "include.h"

int help(const char version[]) {
  printf(CYAN BOLD "Cassandra Package Manager %s\n" RESET, version);
  
  printf(DIM "\nThe code to this project is licensed under\n");
  printf("the GNU General Public License v3.\n" RESET);
  printf(DIM "Source: " CYAN "https://github.com/ShadowPlasma2009/CassandraPM\n" RESET);
  printf(DIM "GPLv3: " CYAN "https://www.gnu.org/licenses/gpl-3.0.html\n" RESET);

  printf(GREEN "\nUsage: " BOLD YELLOW "cpm <command> [arguments]\n" RESET);
  printf(CYAN BOLD "\nCommands:\n" RESET);
  printf(GREEN "  install <package> -R " RESET BLUE"- Install a package from an online repository\n" RESET);
  printf(GREEN "  install <pkg_path> -T " RESET BLUE"- Install a local .tar.gz package\n" RESET);
  printf(GREEN "  remove <package> " RESET BLUE"- Remove specified package\n" RESET);
  printf(GREEN "  update " RESET BLUE"- Update local package database\n" RESET);
  printf(GREEN "  upgrade " RESET BLUE"- Upgrade all installed packages\n" RESET);
  printf(GREEN "  list " RESET BLUE"- List all available to install packages\n" RESET);
  printf(GREEN "  help " RESET BLUE"- Display this help message\n" RESET);

  printf(MAGENTA "\nThis package manager is running in Moisturizer (6 in 1) mode!\n" RESET);

  return 0;
}
