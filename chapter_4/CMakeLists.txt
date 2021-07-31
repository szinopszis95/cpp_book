set(CHAPTER_3_LIBS
    Drill
    Excercises
    try_these
)

foreach(LIBRARY ${CHAPTER_3_LIBS})
    add_subdirectory(${LIBRARY})
endforeach(LIBRARY)