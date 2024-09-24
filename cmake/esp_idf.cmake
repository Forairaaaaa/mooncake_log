# Src files
file(GLOB_RECURSE AAA_SRCS
    ${AAA_ROOT_DIR}/src/*.c
    ${AAA_ROOT_DIR}/src/*.cpp
)
# Include
set(AAA_INCS
    ${AAA_ROOT_DIR}/src/
    ${AAA_ROOT_DIR}/src/spdlog/include/
)

# Public component requirement
set(AAA_REQUIRES
)

# Private component requirement
set(AAA_PRIV_REQUIRES
)

# Register component
idf_component_register(
    SRCS ${AAA_SRCS}
    INCLUDE_DIRS ${AAA_INCS}
    REQUIRES ${AAA_REQUIRES}
    PRIV_REQUIRES ${AAA_PRIV_REQUIRES}
)