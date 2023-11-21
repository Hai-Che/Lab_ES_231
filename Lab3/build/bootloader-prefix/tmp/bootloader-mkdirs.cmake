# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/Admin/esp/esp-idf/components/bootloader/subproject"
  "D:/Study/ES/Lab/Lab_ES_231/Lab3/build/bootloader"
  "D:/Study/ES/Lab/Lab_ES_231/Lab3/build/bootloader-prefix"
  "D:/Study/ES/Lab/Lab_ES_231/Lab3/build/bootloader-prefix/tmp"
  "D:/Study/ES/Lab/Lab_ES_231/Lab3/build/bootloader-prefix/src/bootloader-stamp"
  "D:/Study/ES/Lab/Lab_ES_231/Lab3/build/bootloader-prefix/src"
  "D:/Study/ES/Lab/Lab_ES_231/Lab3/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/Study/ES/Lab/Lab_ES_231/Lab3/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/Study/ES/Lab/Lab_ES_231/Lab3/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
