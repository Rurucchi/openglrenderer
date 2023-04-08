@echo off
cl /nologo /Zi /EHsc main.cpp /link glfw3_mt.lib glfw3dll.lib kernel32.lib user32.lib shell32.lib winmm.lib gdi32.lib opengl32.lib 