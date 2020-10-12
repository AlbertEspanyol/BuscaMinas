##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Practica2
ConfigurationName      :=Debug
WorkspacePath          :=D:/UNI/1r/Programació/projecte_S2/P2_albertEspanol_carlosFernandez
ProjectPath            :=D:/UNI/1r/Programació/projecte_S2/P2_albertEspanol_carlosFernandez
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Usuari
Date                   :=11/01/2019
CodeLitePath           :="C:/Program Files (x86)/CodeLite"
LinkerName             :=C:/MinGW-4.8.1/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW-4.8.1/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Practica2.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW-4.8.1/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)allegro-5.0.10-monolith-mt-debug 
ArLibs                 :=  "liballegro-5.0.10-monolith-mt-debug.a" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW-4.8.1/bin/ar.exe rcu
CXX      := C:/MinGW-4.8.1/bin/g++.exe
CC       := C:/MinGW-4.8.1/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW-4.8.1/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/LS_allegro.c$(ObjectSuffix) $(IntermediateDirectory)/grafica.c$(ObjectSuffix) $(IntermediateDirectory)/tauler.c$(ObjectSuffix) $(IntermediateDirectory)/ranquing.c$(ObjectSuffix) $(IntermediateDirectory)/llistab.c$(ObjectSuffix) $(IntermediateDirectory)/logica.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/UNI/1r/Programació/projecte_S2/P2_albertEspanol_carlosFernandez/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c

$(IntermediateDirectory)/LS_allegro.c$(ObjectSuffix): LS_allegro.c $(IntermediateDirectory)/LS_allegro.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/UNI/1r/Programació/projecte_S2/P2_albertEspanol_carlosFernandez/LS_allegro.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/LS_allegro.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/LS_allegro.c$(DependSuffix): LS_allegro.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/LS_allegro.c$(ObjectSuffix) -MF$(IntermediateDirectory)/LS_allegro.c$(DependSuffix) -MM LS_allegro.c

$(IntermediateDirectory)/LS_allegro.c$(PreprocessSuffix): LS_allegro.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/LS_allegro.c$(PreprocessSuffix) LS_allegro.c

$(IntermediateDirectory)/grafica.c$(ObjectSuffix): grafica.c $(IntermediateDirectory)/grafica.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/UNI/1r/Programació/projecte_S2/P2_albertEspanol_carlosFernandez/grafica.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/grafica.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/grafica.c$(DependSuffix): grafica.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/grafica.c$(ObjectSuffix) -MF$(IntermediateDirectory)/grafica.c$(DependSuffix) -MM grafica.c

$(IntermediateDirectory)/grafica.c$(PreprocessSuffix): grafica.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/grafica.c$(PreprocessSuffix) grafica.c

$(IntermediateDirectory)/tauler.c$(ObjectSuffix): tauler.c $(IntermediateDirectory)/tauler.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/UNI/1r/Programació/projecte_S2/P2_albertEspanol_carlosFernandez/tauler.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tauler.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tauler.c$(DependSuffix): tauler.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tauler.c$(ObjectSuffix) -MF$(IntermediateDirectory)/tauler.c$(DependSuffix) -MM tauler.c

$(IntermediateDirectory)/tauler.c$(PreprocessSuffix): tauler.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tauler.c$(PreprocessSuffix) tauler.c

$(IntermediateDirectory)/ranquing.c$(ObjectSuffix): ranquing.c $(IntermediateDirectory)/ranquing.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/UNI/1r/Programació/projecte_S2/P2_albertEspanol_carlosFernandez/ranquing.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ranquing.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ranquing.c$(DependSuffix): ranquing.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ranquing.c$(ObjectSuffix) -MF$(IntermediateDirectory)/ranquing.c$(DependSuffix) -MM ranquing.c

$(IntermediateDirectory)/ranquing.c$(PreprocessSuffix): ranquing.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ranquing.c$(PreprocessSuffix) ranquing.c

$(IntermediateDirectory)/llistab.c$(ObjectSuffix): llistab.c $(IntermediateDirectory)/llistab.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/UNI/1r/Programació/projecte_S2/P2_albertEspanol_carlosFernandez/llistab.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/llistab.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/llistab.c$(DependSuffix): llistab.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/llistab.c$(ObjectSuffix) -MF$(IntermediateDirectory)/llistab.c$(DependSuffix) -MM llistab.c

$(IntermediateDirectory)/llistab.c$(PreprocessSuffix): llistab.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/llistab.c$(PreprocessSuffix) llistab.c

$(IntermediateDirectory)/logica.c$(ObjectSuffix): logica.c $(IntermediateDirectory)/logica.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/UNI/1r/Programació/projecte_S2/P2_albertEspanol_carlosFernandez/logica.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/logica.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/logica.c$(DependSuffix): logica.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/logica.c$(ObjectSuffix) -MF$(IntermediateDirectory)/logica.c$(DependSuffix) -MM logica.c

$(IntermediateDirectory)/logica.c$(PreprocessSuffix): logica.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/logica.c$(PreprocessSuffix) logica.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


