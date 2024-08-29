#include "erpc_mbf_setup.h"
#include "erpc_servo_configure_client.hpp"
#include "erpc_servo_configure_common.hpp"
#include "erpc_transport_setup.h"
#include <cstdio>
#include <erpc_client_setup.h>
#include <memory>

int main(void) {
  // 5x5 matrix

  /**
   * Initialize matrices(5x5)
   * matrix1 unit matrix
   * matrix2 random matrix
   */

  auto transport = erpc_transport_serial_init("/dev/ttyUSB0", 115200);
  erpc_mbf_t message_buffer_factory = erpc_mbf_dynamic_init();

  auto *client = erpc_client_init(transport, message_buffer_factory);

  std::unique_ptr<erpcShim::ServoConfigureService_client> my_client(
      new erpcShim::ServoConfigureService_client(
          reinterpret_cast<erpc::ClientManager *>(client)));

  SdoSubEntry subEntry = {0};
  for (int i = 0; i < 100; i++) {
    int ret = my_client->getSdoSubEntry(0x3100, 0, &subEntry);

    sleep(1);
    if (ret != 0) {
      printf("Error: %d\n", ret);
      // return 1;
      continue;
    }

    int32_t value = 0;
    memcpy(&value, subEntry.data, sizeof(int32_t));
    printf("Value: %d\n", value);
  }
  erpc_client_deinit(client);

  erpc_mbf_dynamic_deinit(message_buffer_factory);

  return 0;
}
