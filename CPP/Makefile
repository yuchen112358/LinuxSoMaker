#*****************************************************************************
# Copyright        :  
#
# Author           :   huochangjun
# Modificator  :    yuchen
# Date             :   2016-11-08
# Version           :   
# Description             :   使用C++书写动态链接库
#
#****************************************************************************/

SHELL = /bin/sh
APP_DIR = /home/xxx/C++/LinuxSoMaker/CPP
LIB_DIR = ${APP_DIR}/lib/
BIN_DIR = ${APP_DIR}/bin/
OBJECT_DIR = ${APP_DIR}/obj/
SRC_DIR = ${APP_DIR}/src/

$(shell mkdir -p ${LIB_DIR})

$(shell mkdir -p ${BIN_DIR})

$(shell mkdir -p ${OBJECT_DIR})

RM = rm -fr

#****************************************************************************

CXX = g++

SHARED = -shared

FPIC = -fPIC -c

SRC_OBJECT = $(SRC_DIR)JNIDemo.cpp $(SRC_DIR)JNIStringDemo.cpp $(SRC_DIR)JNIDemoInterface.cpp

H_OBJECT = $(SRC_DIR)JNIDemo.h $(SRC_DIR)JNIStringDemo.h $(SRC_DIR)JNIDemoInterface.h

OBJECT = JNIDemo.o JNIStringDemo.o JNIDemoInterface.o

DY_SRC_OBJECT = $(SRC_DIR)JNIMain.cpp

DY_OBJECT=JNIMain.o

LIB_OBJECT = libjni.so

BIN_OBJECT = JNIMain

#****************************************************************************

.PHONY:all dlib clean

all:$(LIB_OBJECT) $(BIN_OBJECT)

dlib:$(LIB_OBJECT)

$(LIB_OBJECT):$(OBJECT)
	$(CXX) $(OBJECT) $(SHARED) -fPIC -o $(LIB_OBJECT)
	mv $(OBJECT) $(OBJECT_DIR)
	mv $(LIB_OBJECT) $(LIB_DIR)

$(OBJECT):$(SRC_OBJECT) $(H_OBJECT)
	$(CXX) $(FPIC) $(SRC_OBJECT)

$(BIN_OBJECT):$(DY_OBJECT)
	$(CXX) $(OBJECT_DIR)$(DY_OBJECT) -L$(LIB_DIR) -ljni -o $(BIN_OBJECT)
	mv $(BIN_OBJECT) $(BIN_DIR)

$(DY_OBJECT):$(DY_SRC_OBJECT)
	$(CXX) -c $(DY_SRC_OBJECT)
	mv $(DY_OBJECT) $(OBJECT_DIR)

clean:
	$(RM) $(LIB_DIR) $(BIN_DIR) $(OBJECT_DIR)