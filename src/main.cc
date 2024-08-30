#include "c_erpc_servo_configure_client.h"
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

  int ret = my_client->getSdoSubEntry(0x3110, 0, &subEntry);
  size_t copy_size = subEntry.bitsize / 8;
  if (copy_size == 0) {
    copy_size = 1;
  }

  int32_t value = 0;
  memcpy(&value, subEntry.data, copy_size);
  value = value & ((1 << subEntry.bitsize) - 1);

  printf("Value: %d\n", value);

  int32_t c0 = 0;
  int width = my_client->getAdcRaw(ERPC_ADC_CURRENT0, &c0);
  if (width < 0) {
    printf("Error: %d\n", width);
    ret = 1;
    goto fail_or_default;
  }
  printf("Current0: %d, Width: %d\n", c0, width);

  width = my_client->getAdcRaw(ERPC_ADC_CURRENT1, &c0);
  if (width < 0) {
    printf("Error: %d\n", width);
    ret = 1;
    goto fail_or_default;
  }
  printf("Current1: %d, Width: %d\n", c0, width);

  width = my_client->getAdcRaw(ERPC_ADC_CURRENT2, &c0);
  if (width < 0) {
    printf("Error: %d\n", width);
    ret = 1;
    goto fail_or_default;
  }
  printf("Current2: %d, Width: %d\n", c0, width);

  width = my_client->getAdcRaw(ERPC_ADC_MAIN_ENCODER_SIN, &c0);
  if (width < 0) {
    printf("Error: %d\n", width);
    ret = 1;
    goto fail_or_default;
  }
  printf("Main Encoder Sin: %d, Width: %d\n", c0, width);

  width = my_client->getAdcRaw(ERPC_ADC_MAIN_ENCODER_COS, &c0);
  if (width < 0) {
    printf("Error: %d\n", width);
    ret = 1;
    goto fail_or_default;
  }
  printf("Main Encoder Cos: %d, Width: %d\n", c0, width);

fail_or_default:
  erpc_client_deinit(client);

  erpc_mbf_dynamic_deinit(message_buffer_factory);

  return ret;
}
