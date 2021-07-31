set(CHAPTER_3_LIBS
    alphabet_loop
    square
)

foreach(LIBRARY ${CHAPTER_3_LIBS})
    add_subdirectory(${LIBRARY})
endforeach(LIBRARY)