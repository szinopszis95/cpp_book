cmake_minimum_required(VERSION 3.16.3)

project(
    CPP_BOOK
    VERSION 0.1
    DESCRIPTION "Cpp book project"
    LANGUAGES CXX
    )

set(LIBRARIES_DIR
    3.5
    3.9
    chapter_3_tasks
    chapter_4
)

foreach(LIBRARY ${LIBRARIES_DIR})
    add_subdirectory(${LIBRARY})
endforeach(LIBRARY)