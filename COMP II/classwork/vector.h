#include "status.h"
typedef void* VECTOR;

VECTOR vector_init_default(void);

Boolean vector_is_empty(VECTOR hVector);

void vector_destroy(VECTOR hVector);