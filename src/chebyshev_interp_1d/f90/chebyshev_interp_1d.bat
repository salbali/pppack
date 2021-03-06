@echo off

REM for /F %%i in ("%cd%") do set "libname=%%~ni"
set libname=%~n0

set fsplit=..\..\..\..\bin\f90split.exe

mkdir temp
cd temp

if not exist %fsplit% (
    echo missing %fsplit% from %cd%
    exit /b 1
)
%fsplit% ..\%libname%.f90

for /F %%i in ('dir /b *.f90') do gfortran -c %%i
	
del *.f90

REM REM include dependencies
set libr8=..\..\r8lib\f90\libr8lib.a
if not exist ..\%libr8% (
    echo missing ..\%libr8%
    exit /b 1
)
ar -x ..\%libr8%

set libqr=..\..\qr_solve\f90\libqr_solve.a
if not exist ..\%libqr% (
    echo missing ..\%libqr%
    exit /b 1
)
ar -x ..\%libqr%

ar qc lib%libname%.a *.o
del *.o

move lib%libname%.a ..\.
cd ..
rmdir temp
echo "Library installed as lib%libname%.a"

REM test the library
echo "gfortran -o %libname%_prb.exe %libname%_prb.f90 lib%libname%.a %libr8% %libqr%"
gfortran -o %libname%_prb.exe %libname%_prb.f90 lib%libname%.a %libr8% %libqr%

%libname%_prb.exe > %libname%_prb_output.txt
echo " --- TEST LIB ---"
echo "diff between ref. and current %libname%_prb_output.txt"
fc %libname%_prb_output_ref.txt %libname%_prb_output.txt
REM echo " *** without datetime at the beginning and at the end ***"
REM FC <(tail -n +1 ${libname}_prb_output.txt | head -n -1) <(tail -n +1 ${libname}_prb_output_tst.txt | head -n -1)
echo " --- NORMAL END ---"
