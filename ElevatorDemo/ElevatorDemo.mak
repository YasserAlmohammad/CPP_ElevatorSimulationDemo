# Microsoft Developer Studio Generated NMAKE File, Based on ElevatorDemo.dsp
!IF "$(CFG)" == ""
CFG=ElevatorDemo - Win32 Debug
!MESSAGE No configuration specified. Defaulting to ElevatorDemo - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "ElevatorDemo - Win32 Release" && "$(CFG)" != "ElevatorDemo - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ElevatorDemo.mak" CFG="ElevatorDemo - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ElevatorDemo - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "ElevatorDemo - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "ElevatorDemo - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\ElevatorDemo.exe"


CLEAN :
	-@erase "$(INTDIR)\DrawPaneDlg.obj"
	-@erase "$(INTDIR)\Elevator.obj"
	-@erase "$(INTDIR)\ElevatorDemo.obj"
	-@erase "$(INTDIR)\ElevatorDemo.pch"
	-@erase "$(INTDIR)\ElevatorDemo.res"
	-@erase "$(INTDIR)\ElevatorDemoDlg.obj"
	-@erase "$(INTDIR)\ElevatorUI.obj"
	-@erase "$(INTDIR)\Floor.obj"
	-@erase "$(INTDIR)\FloorUI.obj"
	-@erase "$(INTDIR)\Person.obj"
	-@erase "$(INTDIR)\PersonUI.obj"
	-@erase "$(INTDIR)\Reporter.obj"
	-@erase "$(INTDIR)\Schedule.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\ElevatorDemo.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\ElevatorDemo.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ElevatorDemo.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ElevatorDemo.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\ElevatorDemo.pdb" /machine:I386 /out:"$(OUTDIR)\ElevatorDemo.exe" 
LINK32_OBJS= \
	"$(INTDIR)\DrawPaneDlg.obj" \
	"$(INTDIR)\Elevator.obj" \
	"$(INTDIR)\ElevatorDemo.obj" \
	"$(INTDIR)\ElevatorDemoDlg.obj" \
	"$(INTDIR)\ElevatorUI.obj" \
	"$(INTDIR)\Floor.obj" \
	"$(INTDIR)\FloorUI.obj" \
	"$(INTDIR)\Person.obj" \
	"$(INTDIR)\PersonUI.obj" \
	"$(INTDIR)\Reporter.obj" \
	"$(INTDIR)\Schedule.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ElevatorDemo.res"

"$(OUTDIR)\ElevatorDemo.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ElevatorDemo - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\ElevatorDemo.exe"


CLEAN :
	-@erase "$(INTDIR)\DrawPaneDlg.obj"
	-@erase "$(INTDIR)\Elevator.obj"
	-@erase "$(INTDIR)\ElevatorDemo.obj"
	-@erase "$(INTDIR)\ElevatorDemo.pch"
	-@erase "$(INTDIR)\ElevatorDemo.res"
	-@erase "$(INTDIR)\ElevatorDemoDlg.obj"
	-@erase "$(INTDIR)\ElevatorUI.obj"
	-@erase "$(INTDIR)\Floor.obj"
	-@erase "$(INTDIR)\FloorUI.obj"
	-@erase "$(INTDIR)\Person.obj"
	-@erase "$(INTDIR)\PersonUI.obj"
	-@erase "$(INTDIR)\Reporter.obj"
	-@erase "$(INTDIR)\Schedule.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\ElevatorDemo.exe"
	-@erase "$(OUTDIR)\ElevatorDemo.ilk"
	-@erase "$(OUTDIR)\ElevatorDemo.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\ElevatorDemo.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ElevatorDemo.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ElevatorDemo.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\ElevatorDemo.pdb" /debug /machine:I386 /out:"$(OUTDIR)\ElevatorDemo.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\DrawPaneDlg.obj" \
	"$(INTDIR)\Elevator.obj" \
	"$(INTDIR)\ElevatorDemo.obj" \
	"$(INTDIR)\ElevatorDemoDlg.obj" \
	"$(INTDIR)\ElevatorUI.obj" \
	"$(INTDIR)\Floor.obj" \
	"$(INTDIR)\FloorUI.obj" \
	"$(INTDIR)\Person.obj" \
	"$(INTDIR)\PersonUI.obj" \
	"$(INTDIR)\Reporter.obj" \
	"$(INTDIR)\Schedule.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ElevatorDemo.res"

"$(OUTDIR)\ElevatorDemo.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("ElevatorDemo.dep")
!INCLUDE "ElevatorDemo.dep"
!ELSE 
!MESSAGE Warning: cannot find "ElevatorDemo.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "ElevatorDemo - Win32 Release" || "$(CFG)" == "ElevatorDemo - Win32 Debug"
SOURCE=.\DrawPaneDlg.cpp

"$(INTDIR)\DrawPaneDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ElevatorDemo.pch"


SOURCE=.\Elevator.cpp

"$(INTDIR)\Elevator.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ElevatorDemo.pch"


SOURCE=.\ElevatorDemo.cpp

"$(INTDIR)\ElevatorDemo.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ElevatorDemo.pch"


SOURCE=.\ElevatorDemo.rc

"$(INTDIR)\ElevatorDemo.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\ElevatorDemoDlg.cpp

"$(INTDIR)\ElevatorDemoDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ElevatorDemo.pch"


SOURCE=.\ElevatorUI.cpp

"$(INTDIR)\ElevatorUI.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ElevatorDemo.pch"


SOURCE=.\Floor.cpp

"$(INTDIR)\Floor.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ElevatorDemo.pch"


SOURCE=.\FloorUI.cpp

"$(INTDIR)\FloorUI.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ElevatorDemo.pch"


SOURCE=.\Person.cpp

"$(INTDIR)\Person.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ElevatorDemo.pch"


SOURCE=.\PersonUI.cpp

"$(INTDIR)\PersonUI.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ElevatorDemo.pch"


SOURCE=.\Reporter.cpp

"$(INTDIR)\Reporter.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ElevatorDemo.pch"


SOURCE=.\Schedule.cpp

"$(INTDIR)\Schedule.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ElevatorDemo.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "ElevatorDemo - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\ElevatorDemo.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ElevatorDemo.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ElevatorDemo - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\ElevatorDemo.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ElevatorDemo.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

