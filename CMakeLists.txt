cmake_minimum_required(VERSION 3.10)
project(cowmangler)

# 1. Konfiguracja raylib (bez zmian)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
add_subdirectory(external/raylib)

# 2. Znajdowanie wszystkich plików źródłowych w /src
# Zamiast wpisywać każdy plik ręcznie, możesz użyć:
file(GLOB_RECURSE SOURCES "src/*.cpp")

# 3. Tworzymy plik wykonywalny
add_executable(${PROJECT_NAME} ${SOURCES})

# 4. Linkujemy raylib
target_link_libraries(${PROJECT_NAME} raylib)

# 5. KLUCZOWA ZMIANA: Dodajemy ścieżki do nagłówków
# Dodajemy nasz folder /inc ORAZ folder raylib/src
target_include_directories(${PROJECT_NAME} PRIVATE 
    src
    src/core 
    src/entity 
    src/components 
    src/world 
    src/renderer 
    src/physics
    external/raylib/src
)