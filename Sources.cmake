# Libraries:

link_libraries (gcc)

set (hwlib ${build_environment}/libraries/hwlib)
include_directories (${hwlib}/library)

set (catch ${build_environment}/libraries/Catch2)
include_directories (${catch}/single_include)

set (uart_lib ${build_environment}/libraries/UART_LIB)
include_directories (${uart_lib}/src)

# Source Files:

set (sources
    src/moving_platform.cpp
    ${uart_lib}/src/mock_uart.cpp
    ${uart_lib}/src/uart_connection.cpp
    src/qik_2s12v10.cpp
)
