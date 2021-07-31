set(CHAPTER_3_LIBS
    task_1
    task_2
)

foreach(LIBRARY ${CHAPTER_3_LIBS})
    add_subdirectory(${LIBRARY})
endforeach(LIBRARY)