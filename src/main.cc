#include "erpc_matrix_multiply_client.hpp"
#include "erpc_matrix_multiply_common.hpp"
#include "erpc_mbf_setup.h"
#include "erpc_transport_setup.h"
#include <cstdio>
#include <erpc_client_setup.h>
#include <memory>

int main(void) {
  // 5x5 matrix
  Matrix matrix1, matrix2, result_matrix = {{0}};

  /**
   * Initialize matrices(5x5)
   * matrix1 unit matrix
   * matrix2 random matrix
   */

  for (int i = 0; i < matrix_size; i++) {
    for (int j = 0; j < matrix_size; j++) {
      matrix1[i][j] = (i == j) ? 9 : 0;
    }
  }

  for (int i = 0; i < matrix_size; i++) {
    for (int j = 0; j < matrix_size; j++) {
      matrix2[i][j] = (i + j) * 3;
    }
  }
  for (int i = 0; i < matrix_size; i++) {
    for (int j = 0; j < matrix_size; j++) {
      result_matrix[i][j] = 0;
    }
  }

  auto transport = erpc_transport_serial_init("/dev/ttyUSB0", 115200);
  erpc_mbf_t message_buffer_factory = erpc_mbf_dynamic_init();

  auto *client = erpc_client_init(transport, message_buffer_factory);

  std::unique_ptr<erpcShim::MatrixMultiplyService_client>
      matrix_multiply_service_client(new erpcShim::MatrixMultiplyService_client(
          reinterpret_cast<erpc::ClientManager *>(client)));

  // erpcMatrixMultiply(matrix1, matrix2, result_matrix);
  matrix_multiply_service_client->erpcMatrixMultiply(matrix1, matrix2,
                                                     result_matrix);

  printf("Result matrix:\n");
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      printf("%d ", result_matrix[i][j]);
    }
    printf("\n");
  }

  erpc_client_deinit(client);

  erpc_mbf_dynamic_deinit(message_buffer_factory);

  return 0;
}
