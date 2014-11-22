set(CMAKE_LEGACY_CYGWIN_WIN32 0)
project(ipo)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)

SET(COMMON_SOURCES
    ../common/noamplio.c
    ../common/cputime.c
    ../common/hash.c
    ../common/hook.c
    ../common/iolp.c
    ../common/linalg.c
    ../common/main.c
    ../common/solve.c
    ../common/strdup.c
    ../common/tree.c
    ../common/drand48.c
    ../common/noamplio.c
)

set (LU_LIBRARY
    ldlt.c
    )

set (HSDLS_SOURCE
    hsdls.c
    )

set (HSD_SOURCE
    hsd.c
    )

set (INTPT_SOURCE
    intpt.c
    )


INCLUDE_DIRECTORIES(
    SYSTEM
    ../amplsolver/
    ../Quad/
    ../Common
    )


if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    SET(CMAKE_FIND_LIBRARY_PREFIXES "" "lib")
    SET(CMAKE_FIND_LIBRARY_SUFFIXES ".dll" ".lib" ".a" )
ENDIF (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")

ADD_EXECUTABLE(hsdls ${LU_LIBRARY} ${COMMON_SOURCES} ${HSDLS_SOURCE})
ADD_EXECUTABLE(hsd ${LU_LIBRARY} ${COMMON_SOURCES} ${HSD_SOURCE})
ADD_EXECUTABLE(intpt ${LU_LIBRARY} ${COMMON_SOURCES} ${INTPT_SOURCE})

IF (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")

    target_link_libraries(
        hsdls
        )

    target_link_libraries(
        hsd
        )

    target_link_libraries(
        intpt
        )
    
ENDIF()
