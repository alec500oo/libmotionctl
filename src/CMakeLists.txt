# libmotionctl build file generation rules

# add the source files for the library
set(libmotionctl_srcs
    motion_ctl.c
)

# Create motion control library. For now, I would like to only make static
# builds.
add_library(libmotionctl STATIC ${libmotionctl_srcs})

# add */include folders
target_include_directories(libmotionctl PUBLIC ${CMAKE_SOURCE_DIR}/include)
