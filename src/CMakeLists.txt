add_library(calculator_lib STATIC calculator.cpp)

target_include_directories(calculator_lib PUBLIC 
    ${CMAKE_SOURCE_DIR}/include
)


if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    if(MSVC)
        target_compile_options(calculator_lib PRIVATE /Zi)
    else()
        target_compile_options(calculator_lib PRIVATE -g)
    endif()
endif()

add_executable(calculator_app main.cpp)

target_link_libraries(calculator_app PRIVATE calculator_lib)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    if(MSVC)
        target_compile_options(calculator_app PRIVATE /Zi)
        set_target_properties(calculator_app PROPERTIES
            LINK_FLAGS "/DEBUG"
        )
    else()
        target_compile_options(calculator_app PRIVATE -g)
    endif()
endif()

set_target_properties(calculator_app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)