if(BUILD_TESTING)
    find_package(GTest QUIET)
    
    if(NOT GTest_FOUND)
        include(FetchContent)
        FetchContent_Declare(
            googletest
            URL https://github.com/google/googletest/archive/03597a01ee50f33f9191585d6b9e5177a7f7a00b.zip
        )
        # For Windows: Prevent overriding the parent project's compiler/linker settings
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
        FetchContent_MakeAvailable(googletest)
    endif()
    
    add_executable(calculator_tests test_calculator.cpp)
    
    if(GTest_FOUND)
        target_link_libraries(calculator_tests PRIVATE calculator_lib GTest::gtest_main)
    else()
        target_link_libraries(calculator_tests PRIVATE calculator_lib gtest_main)
    endif()

    include(GoogleTest)
    
    gtest_discover_tests(calculator_tests)
    
    add_test(NAME CalculatorTests COMMAND calculator_tests)
endif()