// include/include.h
#ifndef INCLUDE_H
#define INCLUDE_H

int help(const char *version);
int update(const char *repo, const char *config);
int list(const char *config);
int rinstall(char *package, const char *repo, const char *config, const char *prefix, const char *temp);
int tinstall(char *pkg_path, const char *prefix, const char *temp);
int pkginstalled(char *package, const char *config);
int usage(void);

#endif
