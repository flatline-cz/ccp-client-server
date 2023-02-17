cmake_minimum_required(VERSION 3.21)

list(APPEND CCP_LIB_INCLUDES
        ${CMAKE_CURRENT_LIST_DIR}/include
        )

list(APPEND CCP_LIB_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/client/ccp-client.c
        )