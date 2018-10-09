//
// Created by iskandar on 10/7/18.
//

#ifndef LAB2_CONST_H
#define LAB2_CONST_H
#include <stdio.h>

#define MAX_BUFF 128
#define PATH_MAX_LEN 1024


#define PRINT_ERR(M, ...) fprintf(stderr, "[ERROR] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#define PRINT_INFO(M, ...) fprintf(stdout, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#define PRINT_WARN(M, ...) fprintf(stderr, "[WARN] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#endif //LAB2_CONST_H
