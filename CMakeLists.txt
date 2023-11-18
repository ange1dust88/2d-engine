cmake_minimum_required(VERSION 3.12)
project(code)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES 
    main.cpp
    Engine.cpp
    PrimitiveRenderer.cpp
    Point2D.cpp
    Player.cpp
    Animation.cpp
    Collider.cpp

    #Platform.cpp# Добавьте ваш файл реализации
)

set(HEADERS
    Engine.h
    PrimitiveRenderer.h
    Point2D.h
    Player.h
    Animation.h
    Collider.h
    
    
    # Добавьте ваш заголовочный файл
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "D:/downloads/SFML-2.6.0-windows-vc17-32-bit/SFML-2.6.0/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(code ${SOURCES} ${HEADERS})

target_link_libraries(code sfml-graphics sfml-window sfml-system)