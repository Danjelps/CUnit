@echo off

call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat" x86
echo "PATH="
echo %PATH%
set COVFILE=.\test.cov
echo "COVFILE="
echo %COVFILE%
cmd.exe /C msbuild "CUnitTestAppl2.sln" /p:Configuration=Debug /p:Platform="x86" /m
cmd.exe /C "Debug\CUnitTestAppl2.exe xml out"
pause