# CMakeList.txt: проект CMake для lab1-1; включите исходный код и определения,
# укажите здесь логxику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (lab1-1   "funcs.cpp" "funcs.h" "lab-1-1.cpp"  )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET lab1-1 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
