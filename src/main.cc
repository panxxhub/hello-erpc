#include "c_erpc_matrix_multiply_client.h"
#include "erpc_mbf_setup.h"
#include "erpc_transport_setup.h"
#include <erpc_client_setup.h>

int main(void) {
  Matrix matrix1, matrix2, result_matrix = {{0}};

  auto transport = erpc_transport_serial_init("/dev/ttyUSB0", 115200);
  erpc_mbf_t message_buffer_factory = erpc_mbf_dynamic_init();

  erpc_client_init(transport, message_buffer_factory);

  erpcMatrixMultiply(matrix1, matrix2, result_matrix);

  return 0;
}
