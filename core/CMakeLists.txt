cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 20)
project(Core)

add_library(
   Core

   error_code.h
   error_domain.h
   exception.h
   initialization.h
   initialization.cpp
   instance_id.h
   instance_specifier.cpp
   instance_specifier.h
   optional.h
   result.h
   Span.h
   string.h
   StringView.h
   utility.h
   vector.h
)