# Unit test build file generation rules
# @author Alec Matthews <alec500oo@gmail.com>

# create testing executable
add_executable(motionctl_tests test_main.c)

# include cmocka headers for intellisense
target_include_directories(motionctl_tests PRIVATE ${CMAKE_SOURCE_DIR}/lib/cmocka/include)

# include libmotionctl headers for intellisense
target_include_directories(motionctl_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

# link cmocka to the testing executable
# this link will be static due to the options set eariler
target_link_libraries(motionctl_tests cmocka)

# link libmotionctl
target_link_libraries(motionctl_tests libmotionctl)
