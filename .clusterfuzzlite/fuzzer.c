// Heuristic: FuzzerGenHeuristic6 :: Target: http_parser_parse_url
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "http_parser.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  const char *buf = (const char *)data;
  
  // Ensure buf is null-terminated
  char *buf_cpy = (char *)malloc(size + 1);
  memcpy(buf_cpy, buf, size);
  buf_cpy[size] = '\0';

  int is_connect = 0; // Set to 0 for now
  struct http_parser_url u;
  
  http_parser_parse_url(buf_cpy, size, is_connect, &u);

  free(buf_cpy);

  return 0;
}
  