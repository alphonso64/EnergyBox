#############################################################################
# Makefile for building: test_a
# Generated by qmake (2.01a) (Qt 4.8.6) on: Fri Mar 18 10:41:15 2016
# Project:  test_a.pro
# Template: app
# Command: /usr/lib/arm-linux-gnueabihf/qt4/bin/qmake -o Makefile test_a.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I/home/pi/qt/qwt-6.1/src -I/usr/local/include/xlslib/ -I. -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/arm-linux-gnueabihf -L./lib -L/usr/local/lib -lxls -lqwt -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/arm-linux-gnueabihf/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = digitalinputpanel.cpp \
		digitalinputpanelcontext.cpp \
		main.cpp \
		mainwindow.cpp \
		sysparam.cpp \
		util.cpp \
		dataworkerthread.cpp moc_digitalinputpanel.cpp \
		moc_digitalinputpanelcontext.cpp \
		moc_mainwindow.cpp \
		moc_dataworkerthread.cpp
OBJECTS       = digitalinputpanel.o \
		digitalinputpanelcontext.o \
		main.o \
		mainwindow.o \
		sysparam.o \
		util.o \
		dataworkerthread.o \
		moc_digitalinputpanel.o \
		moc_digitalinputpanelcontext.o \
		moc_mainwindow.o \
		moc_dataworkerthread.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		test_a.pro
QMAKE_TARGET  = test_a
DESTDIR       = 
TARGET        = test_a

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_digitalinputpanel.h ui_mainwindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: test_a.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/arm-linux-gnueabihf/libQtGui.prl \
		/usr/lib/arm-linux-gnueabihf/libQtCore.prl
	$(QMAKE) -o Makefile test_a.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/arm-linux-gnueabihf/libQtGui.prl:
/usr/lib/arm-linux-gnueabihf/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile test_a.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/test_a1.0.0 || $(MKDIR) .tmp/test_a1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/test_a1.0.0/ && $(COPY_FILE) --parents digitalinputpanel.h digitalinputpanelcontext.h mainwindow.h sysparam.h util.h dataworkerthread.h .tmp/test_a1.0.0/ && $(COPY_FILE) --parents digitalinputpanel.cpp digitalinputpanelcontext.cpp main.cpp mainwindow.cpp sysparam.cpp util.cpp dataworkerthread.cpp .tmp/test_a1.0.0/ && $(COPY_FILE) --parents digitalinputpanel.ui mainwindow.ui .tmp/test_a1.0.0/ && (cd `dirname .tmp/test_a1.0.0` && $(TAR) test_a1.0.0.tar test_a1.0.0 && $(COMPRESS) test_a1.0.0.tar) && $(MOVE) `dirname .tmp/test_a1.0.0`/test_a1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/test_a1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_digitalinputpanel.cpp moc_digitalinputpanelcontext.cpp moc_mainwindow.cpp moc_dataworkerthread.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_digitalinputpanel.cpp moc_digitalinputpanelcontext.cpp moc_mainwindow.cpp moc_dataworkerthread.cpp
moc_digitalinputpanel.cpp: ui_digitalinputpanel.h \
		digitalinputpanel.h
	/usr/lib/arm-linux-gnueabihf/qt4/bin/moc $(DEFINES) $(INCPATH) digitalinputpanel.h -o moc_digitalinputpanel.cpp

moc_digitalinputpanelcontext.cpp: digitalinputpanel.h \
		ui_digitalinputpanel.h \
		digitalinputpanelcontext.h
	/usr/lib/arm-linux-gnueabihf/qt4/bin/moc $(DEFINES) $(INCPATH) digitalinputpanelcontext.h -o moc_digitalinputpanelcontext.cpp

moc_mainwindow.cpp: sysparam.h \
		dataworkerthread.h \
		mainwindow.h
	/usr/lib/arm-linux-gnueabihf/qt4/bin/moc $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_dataworkerthread.cpp: dataworkerthread.h
	/usr/lib/arm-linux-gnueabihf/qt4/bin/moc $(DEFINES) $(INCPATH) dataworkerthread.h -o moc_dataworkerthread.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_digitalinputpanel.h ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_digitalinputpanel.h ui_mainwindow.h
ui_digitalinputpanel.h: digitalinputpanel.ui
	/usr/lib/arm-linux-gnueabihf/qt4/bin/uic digitalinputpanel.ui -o ui_digitalinputpanel.h

ui_mainwindow.h: mainwindow.ui
	/usr/lib/arm-linux-gnueabihf/qt4/bin/uic mainwindow.ui -o ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

digitalinputpanel.o: digitalinputpanel.cpp digitalinputpanel.h \
		ui_digitalinputpanel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o digitalinputpanel.o digitalinputpanel.cpp

digitalinputpanelcontext.o: digitalinputpanelcontext.cpp digitalinputpanelcontext.h \
		digitalinputpanel.h \
		ui_digitalinputpanel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o digitalinputpanelcontext.o digitalinputpanelcontext.cpp

main.o: main.cpp mainwindow.h \
		sysparam.h \
		dataworkerthread.h \
		digitalinputpanelcontext.h \
		digitalinputpanel.h \
		ui_digitalinputpanel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		sysparam.h \
		dataworkerthread.h \
		ui_mainwindow.h \
		digitalinputpanelcontext.h \
		digitalinputpanel.h \
		ui_digitalinputpanel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

sysparam.o: sysparam.cpp sysparam.h \
		util.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sysparam.o sysparam.cpp

util.o: util.cpp util.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o util.o util.cpp

dataworkerthread.o: dataworkerthread.cpp dataworkerthread.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dataworkerthread.o dataworkerthread.cpp

moc_digitalinputpanel.o: moc_digitalinputpanel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_digitalinputpanel.o moc_digitalinputpanel.cpp

moc_digitalinputpanelcontext.o: moc_digitalinputpanelcontext.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_digitalinputpanelcontext.o moc_digitalinputpanelcontext.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_dataworkerthread.o: moc_dataworkerthread.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_dataworkerthread.o moc_dataworkerthread.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

