 
#ifndef ASC_QUEST_TOOL_H
#define ASC_QUEST_TOOL_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "dirent.h"

const char *nowTimeString(char *buffer, size_t len) {
  if (buffer == NULL || len <= 0)
    return NULL;

  time_t rtime;
  time(&rtime);
  struct tm *timeinfo = localtime(&rtime);
  strftime(buffer, len, "%m%d-%H%M%S", timeinfo);

  return buffer;
}

const char *filenameWithTime(char *buffer, size_t len, const char *outputDir,
                             const char *prefix, const char *suffix) {
  char buf[128];
  if (nowTimeString(buf, sizeof(buf)) == NULL) {
    return NULL;
  }

  // outputDir is empty
  if (outputDir == NULL || strncmp(outputDir, "", 1) == 0) {
    snprintf(buffer, len, "%s%s%s", prefix, buf, suffix);
  } else {
    snprintf(buffer, len, "%s/%s%s%s", outputDir, prefix, buf, suffix);
  }

  return buffer;
}

// Assume output dir is argv[1]
const char *getOutputDir(int argc, char **argv) {
  if (argc <= 1)
    return NULL;
  size_t len = strlen(argv[1]);
  if (len <= 0)
    return NULL;
  if (len >= 255) {
    fprintf(stderr, "error: output dir is too long: %s\n", argv[1]);
    exit(-1);
  }

  // check wether dir exist
  DIR *dir = NULL;
  dir = opendir(argv[1]);
  if (dir == NULL) {
    fprintf(stderr, "error: output dir: %s not exist\n", argv[1]);
    exit(-1);
  }

  closedir(dir);
  return argv[1];
}

#endif // ASC_QUEST_TOOL_H