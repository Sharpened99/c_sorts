add_executable(c_sorts
        main.cpp
        utils.cpp utils.h
        test.cpp test.h
)

target_link_libraries(c_sorts comp_sorts)