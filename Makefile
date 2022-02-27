# This Makefile will build a DLL and an application which makes use of the DLL.

# Object files to create for the executable
DLL_OBJS = _obj/Engine.o 
EXE_OBJS = _obj/Sandbox.o

# Warnings to be raised by the C compiler
WARNS = -Wall

# Names of tools to use when building
CC = gcc
RC = windres
EXE = Sandbox.exe
DLL = Engine.dll

# Compiler flags
EXE_CFLAGS = -O3 -std=c++2a ${WARNS} -Iinclude
DLL_CFLAGS = ${EXE_CFLAGS} -D ADD_EXPORTS

# Linker flags
DLL_LDFLAGS = -shared -Wl,--out-implib,_lib/Engine.a _obj/Engine.o 
EXE_LDFLAGS = -Llib -laddlib -s -Wl,

.PHONY: all clean

# Build DLL and executable by default
all: _bin/${DLL} _bin/${EXE}

# Delete all build output
clean:
	if exist _bin\* del /q _bin\*
	if exist _lib\* del /q _lib\*
	if exist _obj\* del /q _obj\*


# Compile object files for DLL
#	# ${CC} ${DLL_CFLAGS} -c "$<" -o "$@"
_obj/Engine.o: CryingEngine/src/Engine.* | _obj
	gcc -c -DBUILD_MY_DLL CryingEngine/src/Engine.cpp  -o _obj/Engine.o -fPIC

# Compile object files for executable
_obj/Sandbox.o: Sandbox/src/Sandbox.* | _obj
	${CC} ${EXE_CFLAGS} -c "$<" -o "$@"


# Build the DLL
_bin/${DLL}: ${DLL_OBJS} | _bin _lib
	gcc -shared -o _bin/Engine.dll _obj/Engine.o -Wl,--out-implib,_lib/Engine.a

# Buld the executable
_bin/${EXE}: ${EXE_OBJS} | _bin
	${CC} -o "$@" ${EXE_OBJS} 