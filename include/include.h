// include/include.h
#ifndef INCLUDE_H
#define INCLUDE_H

#define CPM_VERSION "0.02-dev"
#define CPM_REPO_URL "https://github.com"
#define CPM_CONFIG_PATH "$HOME/Projects/cpm/res"
#define CPM_PREFIX "$HOME/cpmUsr"

void help(const char *version);
int update(const char *repo_url, const char *config_path);
int search(const char *config_path);
void usage(void);

#endif
