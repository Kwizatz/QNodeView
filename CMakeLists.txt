# Copyright (C) 2017 Rodrigo Jose Hernandez Cordoba
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 2.8.12)
if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 NEW)
    if(POLICY CMP0020)
        cmake_policy(SET CMP0020 NEW)
    endif(POLICY CMP0020)
    if(POLICY CMP0053)
        cmake_policy(SET CMP0053 NEW)
    endif(POLICY CMP0053)
endif(COMMAND cmake_policy)

project(QNodeView)
enable_language(CXX)
enable_language(C)
find_package(Qt5 COMPONENTS Core Gui Widgets)
include_directories(${Qt5Core_INCLUDE_DIRS}
                    ${Qt5Gui_INCLUDE_DIRS}
                    ${Qt5Widgets_INCLUDE_DIRS})

QT5_WRAP_CPP(QNODEITEMVIEW_MOCS QNodeItemView.hpp)
add_library(QNodeItemView STATIC ${QNODEITEMVIEW_MOCS} QNodeItemView.cpp QNodeItemView.hpp)
# -DQT_BUILD_GUI_LIB
set_target_properties(QNodeItemView PROPERTIES COMPILE_FLAGS "-D_CRT_SECURE_NO_WARNINGS")
target_link_libraries(QNodeItemView ${Qt5Core_LIBRARIES} ${Qt5Gui_LIBRARIES} ${Qt5Widgets_LIBRARIES} ${Qt5WinExtras_LIBRARIES})
add_executable(Example main.cpp)
target_link_libraries(Example ${Qt5Core_LIBRARIES} ${Qt5Gui_LIBRARIES} ${Qt5Widgets_LIBRARIES} ${Qt5WinExtras_LIBRARIES} QNodeItemView)
