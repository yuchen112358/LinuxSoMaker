#*****************************************************************************
# Copyright        :  
#
# Author           :   huochangjun
# Modificator  :    yuchen
# Date             :   2016-11-08
# Version           :   
# Description             :   使用C书写动态链接库
#
#****************************************************************************/

SHELL = /bin/sh
APP_DIR = /home/xxx/C++/LinuxSoMaker/C
LIB_DIR = ${APP_DIR}/lib/
BIN_DIR = ${APP_DIR}/bin/
OBJECT_DIR = ${APP_DIR}/obj/
SRC_DIR = ${APP_DIR}/src/

$(shell mkdir -p ${LIB_DIR})

$(shell mkdir -p ${BIN_DIR})

$(shell mkdir -p ${OBJECT_DIR})

RM = rm -fr

#****************************************************************************

CC = gcc

SHARED = -shared

FPIC = -fPIC -c

SRC_OBJECT = $(SRC_DIR)test_a.c $(SRC_DIR)test_b.c $(SRC_DIR)test_c.c

H_OBJECT = $(SRC_DIR)so_test.h

OBJECT = test_a.o test_b.o test_c.o

DY_SRC_OBJECT = $(SRC_DIR)test.c

DY_OBJECT=test.o

LIB_OBJECT = libtest.so

BIN_OBJECT = test

#****************************************************************************

.PHONY:all dlib clean

all:$(LIB_OBJECT) $(BIN_OBJECT)

dlib:$(LIB_OBJECT)

$(LIB_OBJECT):$(OBJECT)
	$(CC) $(OBJECT) $(SHARED) -fPIC -o $(LIB_OBJECT)
	mv $(OBJECT) $(OBJECT_DIR)
	mv $(LIB_OBJECT) $(LIB_DIR)

$(OBJECT):$(SRC_OBJECT) $(H_OBJECT)
	$(CC) $(FPIC) $(SRC_OBJECT)

$(BIN_OBJECT):$(DY_OBJECT)
	$(CC) $(OBJECT_DIR)$(DY_OBJECT) -L$(LIB_DIR) -ltest -o $(BIN_OBJECT)
	mv $(BIN_OBJECT) $(BIN_DIR)

$(DY_OBJECT):$(DY_SRC_OBJECT)
	$(CC) -c $(DY_SRC_OBJECT)
	mv $(DY_OBJECT) $(OBJECT_DIR)

clean:
	$(RM) $(LIB_DIR) $(BIN_DIR) $(OBJECT_DIR)