# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appmaze_gui_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appmaze_gui_autogen.dir\\ParseCache.txt"
  "appmaze_gui_autogen"
  )
endif()
