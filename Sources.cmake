# Libraries:

link_libraries (gcc)

set (hwlib ${build_environment}/libraries/hwlib)
include_directories (${hwlib}/library)

set (catch ${build_environment}/libraries/Catch2)
include_directories (${catch}/single_include)

# Source Files:

set (sources
    src/moving_platform.cpp
    src/UART_Lib/uart_connection.cpp
    src/UART_Lib/mock_uart.cpp
    src/qik_2s12v10.cpp
)
