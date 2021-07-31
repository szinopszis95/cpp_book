set(CHAPTER_3_LIBS
    drill
    excercises
    try_these
)

foreach(LIBRARY ${CHAPTER_3_LIBS})
    add_subdirectory(${LIBRARY})
endforeach(LIBRARY)